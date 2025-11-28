/***************************************************************************//**
* File Name: mtb_hal_nvm_m7cpuss_v1.c
*
* Description:
* Provides a high level interface for interacting with the Infineon embedded
* non-volatile memory (NVM). This is wrapper around the lower level PDL API.
*
********************************************************************************
* \copyright
* Copyright 2018-2022 Cypress Semiconductor Corporation (an Infineon company) or
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


#include "mtb_hal_nvm_impl.h"


#if (MTB_HAL_DRIVER_AVAILABLE_NVM)

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

#define _MTB_HAL_NVM_MEMORY_BLOCKS_COUNT  (_MTB_HAL_INTERNAL_FLASH_MEMORY_BLOCKS + \
                                         _MTB_HAL_INTERNAL_RRAM_MEMORY_BLOCKS + \
                                         _MTB_HAL_INTERNAL_OTP_MEMORY_BLOCKS)

static const mtb_hal_nvm_region_info_t _mtb_hal_nvm_mem_regions[_MTB_HAL_NVM_MEMORY_BLOCKS_COUNT] =
{
    #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_FLASH)
    /* Each flash area is divided into two regions: A "large" region with 2KB sectors and a
     * "small" region with 128b sectors. The flash can be configured in either single- or
     * double-bank mode. In double-bank mode, the flash is divided into two sub-regions such
     * that it is possible to read from one region while writing to another region. Because
     * dual-bank mode is highly device specific, for simplicity we stick to single-bank mode
     * in the portable HAL driver */
    // Large main flash region, 32KB sectors
    {
        .nvm_type = MTB_HAL_NVM_TYPE_FLASH,
        .start_address = CY_FLASH_LG_SBM_BASE,
        .size = CY_FLASH_LG_SBM_SIZE,
        .sector_size = 32768u,
        .block_size = 8u,
        .is_erase_required = true,
        .erase_value = 0xFFU,
    },
    // Small main flash region, 8KB sectors
    {
        .nvm_type = MTB_HAL_NVM_TYPE_FLASH,
        .start_address = CY_FLASH_SM_SBM_BASE,
        .size = CY_FLASH_SM_SBM_SIZE,
        .sector_size = 8192u,
        .block_size = 8u,
        .is_erase_required = true,
        .erase_value = 0xFFU,
    },
    // Large wflash region, 32KB sectors
    {
        .nvm_type = MTB_HAL_NVM_TYPE_FLASH,
        .start_address = CY_WFLASH_LG_SBM_BASE,
        .size = CY_WFLASH_LG_SBM_SIZE,
        .sector_size = 2048u,     /* Hard-coded in the IP */
        .block_size = 4u,
        .is_erase_required = true,
        .erase_value = 0xFFU,
    },
    // Small wflash region, 128B sectors
    {
        .nvm_type = MTB_HAL_NVM_TYPE_FLASH,
        .start_address = CY_WFLASH_SM_SBM_BASE,
        .size = CY_WFLASH_SM_SBM_SIZE,
        .sector_size = 128u,
        .block_size = 4u,
        .is_erase_required = true,
        .erase_value = 0xFFU,
    },
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_NVM_FLASH) */
};

/*******************************************************************************
*       Functions
*******************************************************************************/

//--------------------------------------------------------------------------------------------------
// _mtb_hal_flash_get_mem_region_count
//--------------------------------------------------------------------------------------------------
uint8_t _mtb_hal_flash_get_mem_region_count(void)
{
    return _MTB_HAL_NVM_MEMORY_BLOCKS_COUNT;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_flash_get_mem_region
//--------------------------------------------------------------------------------------------------
const mtb_hal_nvm_region_info_t* _mtb_hal_flash_get_mem_region(void)
{
    return &_mtb_hal_nvm_mem_regions[0];
}


#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* (MTB_HAL_DRIVER_AVAILABLE_NVM) */
