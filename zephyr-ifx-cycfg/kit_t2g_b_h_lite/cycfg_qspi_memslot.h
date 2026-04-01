/*******************************************************************************
 * File Name: cycfg_qspi_memslot.h
 *
 * Description:
 * Provides declarations of the SMIF-driver memory configuration.
 * This file was automatically generated and should not be modified.
 * QSPI Configurator 4.70.0.2834
 *******************************************************************************
 * Copyright 2026 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.
 * SPDX-License-Identifier: Apache-2.0
 ******************************************************************************/

#ifndef CYCFG_QSPI_MEMSLOT_H
#define CYCFG_QSPI_MEMSLOT_H
#include "cy_smif_memslot.h"

#define CY_SMIF_CFG_TOOL_VERSION           (470)

#define CY_SMIF_DRV_VERSION_REQUIRED       (100)

#if !defined(CY_SMIF_DRV_VERSION)
    #define CY_SMIF_DRV_VERSION            (100)
#endif

#if (CY_SMIF_DRV_VERSION_REQUIRED > CY_SMIF_DRV_VERSION)
   #error The QSPI Configurator requires a newer version of the PDL.
#endif

typedef cy_stc_smif_mem_config_t cy_serial_flash_mem_config_t;
typedef cy_stc_smif_block_config_t cy_serial_flash_block_config_t;

#define CY_SMIF_DEVICE_NUM 2

#define SMIF0_DESELECT_DELAY 7

extern cy_stc_smif_mem_cmd_t S25HL512T_SlaveSlot_0_readCmd;
extern cy_stc_smif_mem_cmd_t S25HL512T_SlaveSlot_0_writeEnCmd;
extern cy_stc_smif_mem_cmd_t S25HL512T_SlaveSlot_0_writeDisCmd;
extern cy_stc_smif_mem_cmd_t S25HL512T_SlaveSlot_0_eraseCmd;
extern cy_stc_smif_mem_cmd_t S25HL512T_SlaveSlot_0_chipEraseCmd;
extern cy_stc_smif_mem_cmd_t S25HL512T_SlaveSlot_0_programCmd;
extern cy_stc_smif_mem_cmd_t S25HL512T_SlaveSlot_0_readStsRegQeCmd;
extern cy_stc_smif_mem_cmd_t S25HL512T_SlaveSlot_0_readStsRegWipCmd;
extern cy_stc_smif_mem_cmd_t S25HL512T_SlaveSlot_0_writeStsRegQeCmd;

extern cy_stc_smif_mem_device_cfg_t deviceCfg_S25HL512T_SlaveSlot_0;
extern cy_stc_smif_mem_config_t S25HL512T_SlaveSlot_0;

/* Slot 1 shares command structs with Slot 0 */
extern cy_stc_smif_mem_device_cfg_t deviceCfg_S25HL512T_SlaveSlot_1;
extern cy_stc_smif_mem_config_t S25HL512T_SlaveSlot_1;

extern cy_stc_smif_mem_config_t* smifMemConfigs[CY_SMIF_DEVICE_NUM];
extern cy_stc_smif_block_config_t smif0BlockConfig;
extern cy_stc_smif_config_t SMIF0_config;

#endif /* CYCFG_QSPI_MEMSLOT_H */