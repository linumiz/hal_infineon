/***************************************************************************//**
* \file mtb_hal_lptimer_mcwdt_b.h
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

/**
 * \addtogroup group_hal_impl_lptimer LPTimer (Low-Power Timer)
 * \ingroup group_hal_impl
 * \{
 *
 * The the maximum number of ticks that can be set to an LPTimer is 0xFFFFFFFF since C0
 * and C1 do not cascade.
 *
 * \} group_hal_impl_lptimer
 */

#pragma once

#include "mtb_hal_lptimer.h"
#include <stdlib.h>
#include "cy_pdl.h"
#include "cy_mcwdt.h"


#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || ((SRSS_NUM_MCWDT_B) > 0)

/*******************************************************************************
*                           Defines
*******************************************************************************/

#define _MTB_HAL_LPTIMER_MCWDT
#define _MTB_HAL_LPTIMER_MCWDT_B

#if !defined(SRSS_NUM_MCWDT_B)
#define SRSS_NUM_MCWDT_B (SRSS_NUM_MCWDT)
#endif

// The max sleep time for MCWDT_B devices is ~17.5 hours. This is because the toggle bit that is set
// for Counter2 match value toggles every time the bit changes from 0 to 1 or from 1 to 0.

/* _MTB_HAL_LPTIMER_MAX_DELAY_TICKS is ~36hours, set to 0xffffffff since C0 and C1 do not cascade */
#define _MTB_HAL_LPTIMER_MAX_DELAY_TICKS                (0xffffffffUL)
#define _MTB_HAL_LPTIMER_ISR_CALL_USER_CB_MASK          (0x01)
#define _MTB_HAL_LPTIMER_RESET_TIME_US                  (93)
#define _MTB_HAL_LPTIMER_SETMATCH_TIME_US               (93)

#define _MTB_HAL_LPTIMER_MIN_DELAY                      (3U) /* minimum amount of lfclk cycles that
                                                                LPTIMER can delay for. */
/*******************************************************************************
*                           Typedefs
*******************************************************************************/


/*******************************************************************************
*                        Public Function Prototypes
*******************************************************************************/


/*******************************************************************************
*                        Inlined Functions
*******************************************************************************/

//--------------------------------------------------------------------------------------------------
// _mtb_hal_lptimer_read
//--------------------------------------------------------------------------------------------------
/* This IP needs no further action */
#define _mtb_hal_lptimer_read(obj, count) (count)


//--------------------------------------------------------------------------------------------------
// _mtb_hal_lptimer_counter_to_mask
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE uint32_t _mtb_hal_lptimer_counter_to_mask(cy_en_mcwdtctr_t counter)
{
    /* Get the mask (for e.g. ClearInterrupt) associated with a particular counter */
    return 1UL << counter;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_lptimer_enable_event
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE void _mtb_hal_lptimer_enable_event(mtb_hal_lptimer_t* obj)
{
    uint32_t critical_section = Cy_SysLib_EnterCriticalSection();
    Cy_MCWDT_ClearInterrupt(obj->base, _mtb_hal_lptimer_counter_to_mask(obj->counter));
    Cy_MCWDT_SetInterruptMask(obj->base, _mtb_hal_lptimer_counter_to_mask(obj->counter));
    Cy_SysLib_ExitCriticalSection(critical_section);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_lptimer_disable_event
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE void _mtb_hal_lptimer_disable_event(mtb_hal_lptimer_t* obj)
{
    uint32_t critical_section = Cy_SysLib_EnterCriticalSection();
    Cy_MCWDT_ClearInterrupt(obj->base, _mtb_hal_lptimer_counter_to_mask(obj->counter));
    Cy_MCWDT_SetInterruptMask(obj->base, Cy_MCWDT_GetInterruptMask(
                                  obj->base) & ~_mtb_hal_lptimer_counter_to_mask(obj->counter));
    Cy_SysLib_ExitCriticalSection(critical_section);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_lptimer_setup
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_lptimer_setup(mtb_hal_lptimer_t* obj)
{
    obj->final_time = 0;
    obj->counter = CY_MCWDT_COUNTER1;
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_lptimer_set_delay_rollover
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE void _mtb_hal_lptimer_set_delay_rollover(uint16_t* c0_match, uint16_t* c1_match)
{
    // These IPs need no rollover adjustment
    CY_UNUSED_PARAMETER(c0_match);
    CY_UNUSED_PARAMETER(c1_match);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_lptimer_set_delay_enable
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE void _mtb_hal_lptimer_set_delay_enable(mtb_hal_lptimer_t* obj)
{
    Cy_MCWDT_SetInterruptMask(obj->base, Cy_MCWDT_GetInterruptMask(
                                  obj->base) & ~_mtb_hal_lptimer_counter_to_mask(obj->counter));
}


#endif \
    /* (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || ((SRSS_NUM_MCWDT_B) > 0) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
