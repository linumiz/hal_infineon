/*******************************************************************************
 * File Name: cycfg_qspi_memslot.c
 *
 * Description:
 * Provides definitions of the SMIF-driver memory configuration.
 * This file was automatically generated and should not be modified.
 * QSPI Configurator 4.70.0.2834
 *******************************************************************************
 * Copyright 2026 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.
 * SPDX-License-Identifier: Apache-2.0
 ******************************************************************************/

#include "cycfg_qspi_memslot.h"

/* Commands for S25HL512T interfaced in Dual-Quad mode */
cy_stc_smif_mem_cmd_t S25HL512T_SlaveSlot_0_readCmd =
{
    .command = 0xECU,
    .cmdWidth = CY_SMIF_WIDTH_SINGLE,
    .addrWidth = CY_SMIF_WIDTH_QUAD,
    .mode = 0x01U,
    .modeWidth = CY_SMIF_WIDTH_QUAD,
    .dummyCycles = 8U,
    .dataWidth = CY_SMIF_WIDTH_QUAD,
#if (CY_IP_MXSMIF_VERSION >= 2)
    .dataRate = CY_SMIF_SDR,
    .dummyCyclesPresence = CY_SMIF_PRESENT_1BYTE,
    .modePresence = CY_SMIF_PRESENT_1BYTE,
    .modeH = 0x00,
    .modeRate = CY_SMIF_SDR,
    .addrRate = CY_SMIF_SDR,
    .cmdPresence = CY_SMIF_PRESENT_1BYTE,
    .commandH = 0x00,
    .cmdRate = CY_SMIF_SDR,
#endif
};

cy_stc_smif_mem_cmd_t S25HL512T_SlaveSlot_0_writeEnCmd =
{
    .command = 0x06U,
    .cmdWidth = CY_SMIF_WIDTH_SINGLE,
    .addrWidth = CY_SMIF_WIDTH_SINGLE,
    .mode = 0xFFFFFFFFU,
    .modeWidth = CY_SMIF_WIDTH_SINGLE,
    .dummyCycles = 0U,
    .dataWidth = CY_SMIF_WIDTH_SINGLE,
#if (CY_IP_MXSMIF_VERSION >= 2)
    .dataRate = CY_SMIF_SDR,
    .dummyCyclesPresence = CY_SMIF_NOT_PRESENT,
    .modePresence = CY_SMIF_NOT_PRESENT,
    .modeH = 0x00,
    .modeRate = CY_SMIF_SDR,
    .addrRate = CY_SMIF_SDR,
    .cmdPresence = CY_SMIF_PRESENT_1BYTE,
    .commandH = 0x00,
    .cmdRate = CY_SMIF_SDR,
#endif
};

cy_stc_smif_mem_cmd_t S25HL512T_SlaveSlot_0_writeDisCmd =
{
    .command = 0x04U,
    .cmdWidth = CY_SMIF_WIDTH_SINGLE,
    .addrWidth = CY_SMIF_WIDTH_SINGLE,
    .mode = 0xFFFFFFFFU,
    .modeWidth = CY_SMIF_WIDTH_SINGLE,
    .dummyCycles = 0U,
    .dataWidth = CY_SMIF_WIDTH_SINGLE,
#if (CY_IP_MXSMIF_VERSION >= 2)
    .dataRate = CY_SMIF_SDR,
    .dummyCyclesPresence = CY_SMIF_NOT_PRESENT,
    .modePresence = CY_SMIF_NOT_PRESENT,
    .modeH = 0x00,
    .modeRate = CY_SMIF_SDR,
    .addrRate = CY_SMIF_SDR,
    .cmdPresence = CY_SMIF_PRESENT_1BYTE,
    .commandH = 0x00,
    .cmdRate = CY_SMIF_SDR,
#endif
};

cy_stc_smif_mem_cmd_t S25HL512T_SlaveSlot_0_eraseCmd =
{
    .command = 0xDCU,
    .cmdWidth = CY_SMIF_WIDTH_SINGLE,
    .addrWidth = CY_SMIF_WIDTH_SINGLE,
    .mode = 0xFFFFFFFFU,
    .modeWidth = CY_SMIF_WIDTH_SINGLE,
    .dummyCycles = 0U,
    .dataWidth = CY_SMIF_WIDTH_SINGLE,
#if (CY_IP_MXSMIF_VERSION >= 2)
    .dataRate = CY_SMIF_SDR,
    .dummyCyclesPresence = CY_SMIF_NOT_PRESENT,
    .modePresence = CY_SMIF_NOT_PRESENT,
    .modeH = 0x00,
    .modeRate = CY_SMIF_SDR,
    .addrRate = CY_SMIF_SDR,
    .cmdPresence = CY_SMIF_PRESENT_1BYTE,
    .commandH = 0x00,
    .cmdRate = CY_SMIF_SDR,
#endif
};

cy_stc_smif_mem_cmd_t S25HL512T_SlaveSlot_0_chipEraseCmd =
{
    .command = 0x60U,
    .cmdWidth = CY_SMIF_WIDTH_SINGLE,
    .addrWidth = CY_SMIF_WIDTH_SINGLE,
    .mode = 0xFFFFFFFFU,
    .modeWidth = CY_SMIF_WIDTH_SINGLE,
    .dummyCycles = 0U,
    .dataWidth = CY_SMIF_WIDTH_SINGLE,
#if (CY_IP_MXSMIF_VERSION >= 2)
    .dataRate = CY_SMIF_SDR,
    .dummyCyclesPresence = CY_SMIF_NOT_PRESENT,
    .modePresence = CY_SMIF_NOT_PRESENT,
    .modeH = 0x00,
    .modeRate = CY_SMIF_SDR,
    .addrRate = CY_SMIF_SDR,
    .cmdPresence = CY_SMIF_PRESENT_1BYTE,
    .commandH = 0x00,
    .cmdRate = CY_SMIF_SDR,
#endif
};

cy_stc_smif_mem_cmd_t S25HL512T_SlaveSlot_0_programCmd =
{
    .command = 0x12U,
    .cmdWidth = CY_SMIF_WIDTH_SINGLE,
    .addrWidth = CY_SMIF_WIDTH_SINGLE,
    .mode = 0xFFFFFFFFU,
    .modeWidth = CY_SMIF_WIDTH_SINGLE,
    .dummyCycles = 0U,
    .dataWidth = CY_SMIF_WIDTH_SINGLE,
#if (CY_IP_MXSMIF_VERSION >= 2)
    .dataRate = CY_SMIF_SDR,
    .dummyCyclesPresence = CY_SMIF_NOT_PRESENT,
    .modePresence = CY_SMIF_NOT_PRESENT,
    .modeH = 0x00,
    .modeRate = CY_SMIF_SDR,
    .addrRate = CY_SMIF_SDR,
    .cmdPresence = CY_SMIF_PRESENT_1BYTE,
    .commandH = 0x00,
    .cmdRate = CY_SMIF_SDR,
#endif
};

cy_stc_smif_mem_cmd_t S25HL512T_SlaveSlot_0_readStsRegQeCmd =
{
    .command = 0x35U,
    .cmdWidth = CY_SMIF_WIDTH_SINGLE,
    .addrWidth = CY_SMIF_WIDTH_SINGLE,
    .mode = 0xFFFFFFFFU,
    .modeWidth = CY_SMIF_WIDTH_SINGLE,
    .dummyCycles = 0U,
    .dataWidth = CY_SMIF_WIDTH_SINGLE,
#if (CY_IP_MXSMIF_VERSION >= 2)
    .dataRate = CY_SMIF_SDR,
    .dummyCyclesPresence = CY_SMIF_NOT_PRESENT,
    .modePresence = CY_SMIF_NOT_PRESENT,
    .modeH = 0x00,
    .modeRate = CY_SMIF_SDR,
    .addrRate = CY_SMIF_SDR,
    .cmdPresence = CY_SMIF_PRESENT_1BYTE,
    .commandH = 0x00,
    .cmdRate = CY_SMIF_SDR,
#endif
};

cy_stc_smif_mem_cmd_t S25HL512T_SlaveSlot_0_readStsRegWipCmd =
{
    .command = 0x05U,
    .cmdWidth = CY_SMIF_WIDTH_SINGLE,
    .addrWidth = CY_SMIF_WIDTH_SINGLE,
    .mode = 0xFFFFFFFFU,
    .modeWidth = CY_SMIF_WIDTH_SINGLE,
    .dummyCycles = 0U,
    .dataWidth = CY_SMIF_WIDTH_SINGLE,
#if (CY_IP_MXSMIF_VERSION >= 2)
    .dataRate = CY_SMIF_SDR,
    .dummyCyclesPresence = CY_SMIF_NOT_PRESENT,
    .modePresence = CY_SMIF_NOT_PRESENT,
    .modeH = 0x00,
    .modeRate = CY_SMIF_SDR,
    .addrRate = CY_SMIF_SDR,
    .cmdPresence = CY_SMIF_PRESENT_1BYTE,
    .commandH = 0x00,
    .cmdRate = CY_SMIF_SDR,
#endif
};

cy_stc_smif_mem_cmd_t S25HL512T_SlaveSlot_0_writeStsRegQeCmd =
{
    .command = 0x01U,
    .cmdWidth = CY_SMIF_WIDTH_SINGLE,
    .addrWidth = CY_SMIF_WIDTH_SINGLE,
    .mode = 0xFFFFFFFFU,
    .modeWidth = CY_SMIF_WIDTH_SINGLE,
    .dummyCycles = 0U,
    .dataWidth = CY_SMIF_WIDTH_SINGLE,
#if (CY_IP_MXSMIF_VERSION >= 2)
    .dataRate = CY_SMIF_SDR,
    .dummyCyclesPresence = CY_SMIF_NOT_PRESENT,
    .modePresence = CY_SMIF_NOT_PRESENT,
    .modeH = 0x00,
    .modeRate = CY_SMIF_SDR,
    .addrRate = CY_SMIF_SDR,
    .cmdPresence = CY_SMIF_PRESENT_1BYTE,
    .commandH = 0x00,
    .cmdRate = CY_SMIF_SDR,
#endif
};

#if (CY_SMIF_DRV_VERSION_MAJOR > 1) || (CY_SMIF_DRV_VERSION_MINOR >= 50)
static cy_stc_smif_hybrid_region_info_t S25HL512T_SlaveSlot_0_region0 =
{
    .regionAddress = 0x0U,
    .sectorsCount = 32U,
    .eraseCmd = 0x21U,
    .eraseSize = 0x1000U,
    .eraseTime = 335U,
};

static cy_stc_smif_hybrid_region_info_t S25HL512T_SlaveSlot_0_region1 =
{
    .regionAddress = 0x20000U,
    .sectorsCount = 1U,
    .eraseCmd = 0xDCU,
    .eraseSize = 0x20000U,
    .eraseTime = 5869U,
};

static cy_stc_smif_hybrid_region_info_t S25HL512T_SlaveSlot_0_region2 =
{
    .regionAddress = 0x40000U,
    .sectorsCount = 255U,
    .eraseCmd = 0xDCU,
    .eraseSize = 0x40000U,
    .eraseTime = 5869U,
};

static cy_stc_smif_hybrid_region_info_t * S25HL512T_SlaveSlot_0_regionInfo[3] = {
   &S25HL512T_SlaveSlot_0_region0,
   &S25HL512T_SlaveSlot_0_region1,
   &S25HL512T_SlaveSlot_0_region2
};
#endif

cy_stc_smif_mem_device_cfg_t deviceCfg_S25HL512T_SlaveSlot_0 =
{
    .numOfAddrBytes = 0x04U,
    .memSize = 0x04000000U,
    .readCmd = &S25HL512T_SlaveSlot_0_readCmd,
    .writeEnCmd = &S25HL512T_SlaveSlot_0_writeEnCmd,
    .writeDisCmd = &S25HL512T_SlaveSlot_0_writeDisCmd,
    .eraseCmd = &S25HL512T_SlaveSlot_0_eraseCmd,
    .eraseSize = 0x0040000U,
    .chipEraseCmd = &S25HL512T_SlaveSlot_0_chipEraseCmd,
    .programCmd = &S25HL512T_SlaveSlot_0_programCmd,
    .programSize = 0x0000100U,
    .readStsRegQeCmd = &S25HL512T_SlaveSlot_0_readStsRegQeCmd,
    .readStsRegWipCmd = &S25HL512T_SlaveSlot_0_readStsRegWipCmd,
    .writeStsRegQeCmd = &S25HL512T_SlaveSlot_0_writeStsRegQeCmd,
    .stsRegBusyMask = 0x01U,
    .stsRegQuadEnableMask = 0x02U,
    .eraseTime = 5869U,
    .chipEraseTime = 696000U,
    .programTime = 2175U,
#if (CY_SMIF_DRV_VERSION_MAJOR > 1) || (CY_SMIF_DRV_VERSION_MINOR >= 50)
    .hybridRegionCount = 3U,
    .hybridRegionInfo = S25HL512T_SlaveSlot_0_regionInfo,
#endif
    .readLatencyCmd = 0,
    .writeLatencyCmd = 0,
    .latencyCyclesRegAddr = 0x00U,
    .latencyCyclesMask = 0x00U,
#if (CY_IP_MXSMIF_VERSION >= 2)
    .octalDDREnableSeq = 0,
    .readStsRegOeCmd = 0,
    .writeStsRegOeCmd = 0,
    .stsRegOctalEnableMask = 0x00U,
    .octalEnableRegAddr = 0x00U,
    .freq_of_operation = CY_SMIF_100MHZ_OPERATION,
#endif
};

cy_stc_smif_mem_config_t S25HL512T_SlaveSlot_0 =
{
    .slaveSelect = CY_SMIF_SLAVE_SELECT_0,
#if (CY_IP_MXSMIF_VERSION >= 2)
    .flags = CY_SMIF_FLAG_SMIF_REV_3 | CY_SMIF_FLAG_MEMORY_MAPPED | CY_SMIF_FLAG_WR_EN,
#else
    .flags = CY_SMIF_FLAG_MEMORY_MAPPED | CY_SMIF_FLAG_WR_EN,
#endif
    .dataSelect = CY_SMIF_DATA_SEL0,
    .baseAddress = 0x60000000U,
    .memMappedSize = 0x4000000U,
    .dualQuadSlots = CY_SMIF_SLAVE_SELECT_0 | CY_SMIF_SLAVE_SELECT_1,
    .deviceCfg = &deviceCfg_S25HL512T_SlaveSlot_0,
#if (CY_IP_MXSMIF_VERSION >= 2)
    .mergeTimeout = CY_SMIF_MERGE_TIMEOUT_1_CYCLE,
#endif
};

/* Slot 1 shares commands with Slot 0 (same device, dual-quad pair) */

#if (CY_SMIF_DRV_VERSION_MAJOR > 1) || (CY_SMIF_DRV_VERSION_MINOR >= 50)
static cy_stc_smif_hybrid_region_info_t S25HL512T_SlaveSlot_1_region0 =
{
    .regionAddress = 0x0U,
    .sectorsCount = 32U,
    .eraseCmd = 0x21U,
    .eraseSize = 0x1000U,
    .eraseTime = 335U,
};

static cy_stc_smif_hybrid_region_info_t S25HL512T_SlaveSlot_1_region1 =
{
    .regionAddress = 0x20000U,
    .sectorsCount = 1U,
    .eraseCmd = 0xDCU,
    .eraseSize = 0x20000U,
    .eraseTime = 5869U,
};

static cy_stc_smif_hybrid_region_info_t S25HL512T_SlaveSlot_1_region2 =
{
    .regionAddress = 0x40000U,
    .sectorsCount = 255U,
    .eraseCmd = 0xDCU,
    .eraseSize = 0x40000U,
    .eraseTime = 5869U,
};

static cy_stc_smif_hybrid_region_info_t * S25HL512T_SlaveSlot_1_regionInfo[3] = {
    &S25HL512T_SlaveSlot_1_region0,
    &S25HL512T_SlaveSlot_1_region1,
    &S25HL512T_SlaveSlot_1_region2,
};
#endif

cy_stc_smif_mem_device_cfg_t deviceCfg_S25HL512T_SlaveSlot_1 =
{
    .numOfAddrBytes = 0x04U,
    .memSize = 0x04000000U,
    .readCmd = &S25HL512T_SlaveSlot_0_readCmd,
    .writeEnCmd = &S25HL512T_SlaveSlot_0_writeEnCmd,
    .writeDisCmd = &S25HL512T_SlaveSlot_0_writeDisCmd,
    .eraseCmd = &S25HL512T_SlaveSlot_0_eraseCmd,
    .eraseSize = 0x0040000U,
    .chipEraseCmd = &S25HL512T_SlaveSlot_0_chipEraseCmd,
    .programCmd = &S25HL512T_SlaveSlot_0_programCmd,
    .programSize = 0x0000100U,
    .readStsRegQeCmd = &S25HL512T_SlaveSlot_0_readStsRegQeCmd,
    .readStsRegWipCmd = &S25HL512T_SlaveSlot_0_readStsRegWipCmd,
    .writeStsRegQeCmd = &S25HL512T_SlaveSlot_0_writeStsRegQeCmd,
    .stsRegBusyMask = 0x01U,
    .stsRegQuadEnableMask = 0x02U,
    .eraseTime = 5869U,
    .chipEraseTime = 696000U,
    .programTime = 2175U,
#if (CY_SMIF_DRV_VERSION_MAJOR > 1) || (CY_SMIF_DRV_VERSION_MINOR >= 50)
    .hybridRegionCount = 3U,
    .hybridRegionInfo = S25HL512T_SlaveSlot_1_regionInfo,
#endif
    .readLatencyCmd = 0,
    .writeLatencyCmd = 0,
    .latencyCyclesRegAddr = 0x00U,
    .latencyCyclesMask = 0x00U,
#if (CY_IP_MXSMIF_VERSION >= 2)
    .octalDDREnableSeq = 0,
    .readStsRegOeCmd = 0,
    .writeStsRegOeCmd = 0,
    .stsRegOctalEnableMask = 0x00U,
    .octalEnableRegAddr = 0x00U,
    .freq_of_operation = CY_SMIF_100MHZ_OPERATION,
#endif
};

cy_stc_smif_mem_config_t S25HL512T_SlaveSlot_1 =
{
    .slaveSelect = CY_SMIF_SLAVE_SELECT_1,
#if (CY_IP_MXSMIF_VERSION >= 2)
    .flags = CY_SMIF_FLAG_SMIF_REV_3 | CY_SMIF_FLAG_MEMORY_MAPPED | CY_SMIF_FLAG_WR_EN,
#else
    .flags = CY_SMIF_FLAG_MEMORY_MAPPED | CY_SMIF_FLAG_WR_EN,
#endif
    .dataSelect = CY_SMIF_DATA_SEL2,
    .baseAddress = 0x60000000U,          /* Fixed - next 64MB region */
    .memMappedSize = 0x4000000U,
    .dualQuadSlots = CY_SMIF_SLAVE_SELECT_0 | CY_SMIF_SLAVE_SELECT_1,
    .deviceCfg = &deviceCfg_S25HL512T_SlaveSlot_1,
#if (CY_IP_MXSMIF_VERSION >= 2)
    .mergeTimeout = CY_SMIF_MERGE_TIMEOUT_1_CYCLE,
#endif
};

cy_stc_smif_mem_config_t* smifMemConfigs[CY_SMIF_DEVICE_NUM] = {
    &S25HL512T_SlaveSlot_0,
    &S25HL512T_SlaveSlot_1,
};

cy_stc_smif_block_config_t smif0BlockConfig =
{
    .memCount = CY_SMIF_DEVICE_NUM,
    .memConfig = (cy_stc_smif_mem_config_t**)smifMemConfigs,
    .majorVersion = CY_SMIF_DRV_VERSION_MAJOR,
    .minorVersion = CY_SMIF_DRV_VERSION_MINOR,
};

cy_stc_smif_config_t SMIF0_config =
{
    .mode = (uint32_t)CY_SMIF_NORMAL,
    .deselectDelay = SMIF0_DESELECT_DELAY,
    .rxClockSel = CY_SMIF_SEL_INVERTED_FEEDBACK_CLK,
    .blockEvent = (uint32_t)CY_SMIF_BUS_ERROR,
    .delayTapEnable = CY_SMIF_DELAY_TAP_DISABLE,
    .delayLineSelect = CY_SMIF_NO_DELAY_SEL,
};