/***************************************************************************//**
* \file mtb_hal_syspm_mxs40srss.h
*
* \brief
* Provides an interface for interacting with the Infineon power
* management on MXS40SRSS devices
*
********************************************************************************
* \copyright
* Copyright 2024 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation
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

#pragma once

/**
 * \addtogroup group_hal_impl_syspm System Power Management
 * \ingroup group_hal_impl
 * \{
 * The Power Management has the following characteristics:<br>
 * \ref MTB_HAL_SYSPM_CB_SYSTEM_NORMAL equates to the Low Power mode<br>
 * \ref MTB_HAL_SYSPM_CB_SYSTEM_LOW equates to the Ultra Low Power mode
 * \} group_hal_impl_syspm
 */

#if defined(__cplusplus)
extern "C" {
#endif

#if (MTB_HAL_DRIVER_AVAILABLE_LPTIMER)

//--------------------------------------------------------------------------------------------------
// _mtb_hal_syspm_ensure_cb_registered_dsram_lptimer
//--------------------------------------------------------------------------------------------------
static inline bool _mtb_hal_syspm_ensure_cb_registered_dsram_lptimer(void)
{
    // This IP does not support DeepSleep RAM
    return true;
}


#endif // (MTB_HAL_DRIVER_AVAILABLE_LPTIMER)
#if defined(__cplusplus)
}
#endif
