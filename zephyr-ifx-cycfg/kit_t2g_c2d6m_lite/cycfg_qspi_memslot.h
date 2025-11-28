/*******************************************************************************
 * File Name: cycfg_qspi_memslot.h
 *
 * Description:
 * Provides declarations of the SMIF-driver memory configuration.
 * This file was automatically generated and should not be modified.
 * QSPI Configurator 4.60.0.2742
 *
 *******************************************************************************
 * Copyright 2025 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.
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
 ******************************************************************************/

#ifndef CYCFG_QSPI_MEMSLOT_H
#define CYCFG_QSPI_MEMSLOT_H
#include "cy_smif_memslot.h"

#define CY_SMIF_CFG_TOOL_VERSION           (460)

/* Supported QSPI Driver version */
#define CY_SMIF_DRV_VERSION_REQUIRED       (100)

#if !defined(CY_SMIF_DRV_VERSION)
    #define CY_SMIF_DRV_VERSION            (100)
#endif

/* Check the used Driver version */
#if (CY_SMIF_DRV_VERSION_REQUIRED > CY_SMIF_DRV_VERSION)
   #error The QSPI Configurator requires a newer version of the PDL. Update the PDL in your project.
#endif

typedef cy_stc_smif_mem_config_t cy_serial_flash_mem_config_t;
typedef cy_stc_smif_block_config_t cy_serial_flash_block_config_t;

#define CY_SMIF_DEVICE_NUM0 1

#define CY_SMIF_DEVICE_NUM1 1

#define SMIF0_DESELECT_DELAY 7

#define SMIF1_DESELECT_DELAY 7

#define smifBlockConfig smif0BlockConfig
#define smifMemConfigs smif0MemConfigs

extern cy_stc_smif_mem_cmd_t S28HS512T_SMIF0_SlaveSlot_0_readCmd;
extern cy_stc_smif_mem_cmd_t S28HS512T_SMIF0_SlaveSlot_0_writeEnCmd;
extern cy_stc_smif_mem_cmd_t S28HS512T_SMIF0_SlaveSlot_0_writeDisCmd;
extern cy_stc_smif_mem_cmd_t S28HS512T_SMIF0_SlaveSlot_0_eraseCmd;
extern cy_stc_smif_mem_cmd_t S28HS512T_SMIF0_SlaveSlot_0_chipEraseCmd;
extern cy_stc_smif_mem_cmd_t S28HS512T_SMIF0_SlaveSlot_0_programCmd;
extern cy_stc_smif_mem_cmd_t S28HS512T_SMIF0_SlaveSlot_0_readStsRegWipCmd;
extern cy_stc_smif_mem_cmd_t S28HS512T_SMIF0_SlaveSlot_0_readStsRegOeCmd;
extern cy_stc_smif_mem_cmd_t S28HS512T_SMIF0_SlaveSlot_0_writeStsRegOeCmd;

/* SMIF0 */
extern cy_stc_smif_mem_device_cfg_t deviceCfg_S28HS512T_SMIF0_SlaveSlot_0;

extern cy_stc_smif_mem_config_t S28HS512T_SMIF0_SlaveSlot_0;

extern cy_stc_smif_mem_config_t* smif0MemConfigs[CY_SMIF_DEVICE_NUM0];

extern cy_stc_smif_block_config_t smif0BlockConfig;

extern cy_stc_smif_config_t SMIF0_config;

/* SMIF1 */
extern cy_stc_smif_hbmem_device_config_t deviceCfg_S27KS0642_SMIF1_SlaveSlot_1;

extern cy_stc_smif_mem_config_t S27KS0642_SMIF1_SlaveSlot_1;

extern cy_stc_smif_mem_config_t* smif1MemConfigs[CY_SMIF_DEVICE_NUM1];

extern cy_stc_smif_block_config_t smif1BlockConfig;

extern cy_stc_smif_config_t SMIF1_config;

#endif /*CYCFG_QSPI_MEMSLOT_H*/
