/***************************************************************************//**
* \file mtb_hal_lptimer_mcwdt_b.c
*
* \brief
* Provides common API declarations of the mcwdt_b driver
*
********************************************************************************
* \copyright
* Copyright 2025 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
*
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/


#include "mtb_hal_lptimer.h"
#include <stdlib.h>
#include "cy_pdl.h"
#include "mtb_hal_lptimer_mcwdt_b.h"
#include "mtb_hal_irq_impl.h"

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(MTB_HAL_DRIVER_AVAILABLE_LPTIMER) && ((defined (CY_IP_MXS40SRSS) && \
    (CY_IP_MXS40SRSS_VERSION >= 2)) || ((SRSS_NUM_MCWDT_B) > 0))

/*******************************************************************************
*                           Defines
*******************************************************************************/


/*******************************************************************************
*                           Typedefs
*******************************************************************************/


/*******************************************************************************
*                        Internal Functions
*******************************************************************************/

//--------------------------------------------------------------------------------------------------
// _mtb_hal_lptimer_get_toggle_bit
//--------------------------------------------------------------------------------------------------
uint32_t _mtb_hal_lptimer_get_toggle_bit(uint32_t c2_current, uint32_t delay)
{
    uint32_t val = c2_current ^ (c2_current + delay);
    int bit = 0;
    while (val > 0)
    {
        bit++;
        val >>= 1;
    }
    return bit - 1;
}


/*******************************************************************************
*                        Public Functions
*******************************************************************************/

//--------------------------------------------------------------------------------------------------
// mtb_hal_lptimer_process_interrupt
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_lptimer_process_interrupt(mtb_hal_lptimer_t* obj)
{
    CY_ASSERT(obj != NULL);
    uint32_t c2_count = Cy_MCWDT_GetCount(obj->base, CY_MCWDT_COUNTER2);
    //Since CAT1C does not use Counter0, there is no need to clear the interrupt
    Cy_MCWDT_ClearInterrupt(obj->base, (CY_MCWDT_CTR1 | CY_MCWDT_CTR2));
    // We want to clear the interrupt mask everytime we enter the IRQ handler
    // for CAT1C devices regardless if set_delay or set_match was called.
    // This means if mtb_hal_lptimer_set_match was called, a single interrupt will be triggered.
    Cy_MCWDT_SetInterruptMask(obj->base, Cy_MCWDT_GetInterruptMask(
                                  obj->base) & ~_mtb_hal_lptimer_counter_to_mask(obj->counter));
    /* Clear interrupt mask if set only from mtb_hal_lptimer_set_delay() function */
    if (obj->clear_int_mask)
    {
        Cy_MCWDT_SetInterruptMask(obj->base, 0);
    }
    if ((obj->final_time - c2_count > 0) && (obj->final_time > c2_count))
    {
        mtb_hal_lptimer_set_delay(obj, obj->final_time - c2_count);
    }
    else
    {
        if ((NULL != obj->callback_data.callback) &&
            ((obj->isr_instruction & _MTB_HAL_LPTIMER_ISR_CALL_USER_CB_MASK) != 0))
        {
            mtb_hal_lptimer_event_callback_t callback =
                (mtb_hal_lptimer_event_callback_t)obj->callback_data.callback;
            callback(obj->callback_data.callback_arg, MTB_HAL_LPTIMER_COMPARE_MATCH);
        }
    }
    #if (_MTB_HAL_IRQ_MUXING)
    /* Check if the event flag should have been cleared when inside a critical situation */
    if ((obj->isr_instruction & _MTB_HAL_LPTIMER_ISR_CRITICAL_SECTION_MASK) != 0)
    {
        Cy_MCWDT_ClearInterrupt(obj->base, _mtb_hal_lptimer_counter_to_mask(obj->counter));
        Cy_MCWDT_SetInterruptMask(obj->base, Cy_MCWDT_GetInterruptMask(
                                      obj->base) & ~_mtb_hal_lptimer_counter_to_mask(obj->counter));
        obj->isr_instruction &= ~_MTB_HAL_LPTIMER_ISR_CRITICAL_SECTION_MASK;
    }
    #endif
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_lptimer_set_delay
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_lptimer_set_delay(mtb_hal_lptimer_t* obj, uint32_t delay)
{
    obj->clear_int_mask = true;
    obj->final_time = (Cy_MCWDT_GetCount(obj->base, CY_MCWDT_COUNTER2) + delay);

    // Check to see if Counter1 or Counter2 is enabled.
    // If neither is enabled, return Error Disabled.
    // We do not check to see if Counter0 is enabled as it is not used
    // for this IP implementation.
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(Cy_MCWDT_GetEnabledStatus(obj->base, CY_MCWDT_COUNTER1)
                         || Cy_MCWDT_GetEnabledStatus(obj->base,
                                                      CY_MCWDT_COUNTER2),
                         MTB_HAL_LPTIMER_RSLT_ERR_DISABLED);
    #else
    if ((Cy_MCWDT_GetEnabledStatus(obj->base, CY_MCWDT_COUNTER1) == 0UL)
        || (Cy_MCWDT_GetEnabledStatus(obj->base, CY_MCWDT_COUNTER2) == 0UL))
    {
        return MTB_HAL_LPTIMER_RSLT_ERR_DISABLED;
    }
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)
    if (delay <= _MTB_HAL_LPTIMER_MIN_DELAY)
    {
        delay = _MTB_HAL_LPTIMER_MIN_DELAY;
    }
    // No delay > MAX_TICKS check here as MAX_TICKS is uint32_t max (0xFFFFFFFFUL)

    // If the delay is greater than 2^16 we will use Counter2 for interrupts
    // we must then clear the Counter2 interrupt before setting the new match.
    obj->counter = (delay > ((1UL << 16)-1)) ? CY_MCWDT_COUNTER2 : CY_MCWDT_COUNTER1;
    uint32_t critical_section = Cy_SysLib_EnterCriticalSection();
    uint32_t counter_value = Cy_MCWDT_GetCount(obj->base, obj->counter);
    Cy_MCWDT_Unlock(obj->base);
    if (obj->counter == CY_MCWDT_COUNTER1)
    {
        // counter1 is free-running by default based on C1AutoService value.
        // The count value will be started at 0 based on C1LowerLimit value for each counting.
        // 1. We trigger counter1 to do counting (Cy_MCWDT_ResetCounters). After count value reaches
        // warnlimit, it fires interrupt and counter1 stop to do counting.
        // 2. We set warnlimit (Cy_MCWDT_SetWarnLimit)
        uint32_t match_value = delay;
        // A reset occurs after one lf_clk cycle passes
        Cy_MCWDT_ResetCounters(obj->base, _mtb_hal_lptimer_counter_to_mask(obj->counter), 0);
        // The match affects after two lf_clk cycles pass.
        Cy_MCWDT_SetWarnLimit(obj->base, obj->counter, (uint16_t)match_value,
                              _MTB_HAL_LPTIMER_SETMATCH_TIME_US);
    }
    else
    {
        // We want to get the monitored bit to set for the toggle point
        uint32_t toggle_bit = _mtb_hal_lptimer_get_toggle_bit(counter_value, delay);
        // We want to set an interrupt for Counter2 to the 2^n value closest to the match value
        // without going over.  If there is a delta between our power of value of 2^n and the
        // match value we set the remaining delay time on the object which will trigger a follow
        // up interrupt in the IRQ handler
        Cy_MCWDT_SetToggleBit(obj->base, toggle_bit);
        // Wait 3 LFClk cycles to make sure the toggle bit was updated
        Cy_SysLib_DelayUs(_MTB_HAL_LPTIMER_SETMATCH_TIME_US);
    }
    Cy_MCWDT_Lock(obj->base);
    Cy_SysLib_ExitCriticalSection(critical_section);
    Cy_MCWDT_ClearInterrupt(obj->base, _mtb_hal_lptimer_counter_to_mask(obj->counter));
    Cy_MCWDT_SetInterruptMask(obj->base, _mtb_hal_lptimer_counter_to_mask(obj->counter));

    return CY_RSLT_SUCCESS;
}


#endif \
    /* defined(MTB_HAL_DRIVER_AVAILABLE_LPTIMER) && ((defined (CY_IP_MXS40SRSS) &&
       (CY_IP_MXS40SRSS_VERSION >= 2)) || ((SRSS_NUM_MCWDT_B) > 0)) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
