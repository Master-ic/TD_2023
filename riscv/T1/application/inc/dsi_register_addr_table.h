/*
 * dsi_register_addr_table.h
 *
 *  Created on: 2022年3月4日
 *      Author: guoqiang.xiong
 */

#ifndef APPLICATION_INC_DSI_REGISTER_ADDR_TABLE_H_
#define APPLICATION_INC_DSI_REGISTER_ADDR_TABLE_H_

#include "nuclei.h"

#define DSI_0_BASE_ADDR 0xE0080000
#define DSI_1_BASE_ADDR 0xE0090000

volatile uint32_t *DSI_0_0x000_PWR_UP                   = DSI_0_BASE_ADDR + 0x00000000;
volatile uint32_t *DSI_0_0x004_CLKMGR_CFG               = DSI_0_BASE_ADDR + 0x00000004;
volatile uint32_t *DSI_0_0x008_DPI_VCID                 = DSI_0_BASE_ADDR + 0x00000008;
volatile uint32_t *DSI_0_0x00C_DPI_COLOR_CODING         = DSI_0_BASE_ADDR + 0x0000000C;
volatile uint32_t *DSI_0_0x010_DPI_CFG_POL              = DSI_0_BASE_ADDR + 0x00000010;
volatile uint32_t *DSI_0_0x014_DPI_LP_CMD_TIM           = DSI_0_BASE_ADDR + 0x00000014;
volatile uint32_t *DSI_0_0x018_PCKHDL_CFG               = DSI_0_BASE_ADDR + 0x00000018;
volatile uint32_t *DSI_0_0x01C_GEN_VCID                 = DSI_0_BASE_ADDR + 0x0000001C;
volatile uint32_t *DSI_0_0x020_MODE_CFG                 = DSI_0_BASE_ADDR + 0x00000020;
volatile uint32_t *DSI_0_0x024_VID_MODE_CFG             = DSI_0_BASE_ADDR + 0x00000024;
volatile uint32_t *DSI_0_0x028_VID_PKT_SIZE             = DSI_0_BASE_ADDR + 0x00000028;
volatile uint32_t *DSI_0_0x02C_VID_NUM_CHUNKS           = DSI_0_BASE_ADDR + 0x0000002C;
volatile uint32_t *DSI_0_0x030_VID_NULL_SIZE            = DSI_0_BASE_ADDR + 0x00000030;
volatile uint32_t *DSI_0_0x034_VID_HSA_TIME             = DSI_0_BASE_ADDR + 0x00000034;
volatile uint32_t *DSI_0_0x038_VID_HBP_TIME             = DSI_0_BASE_ADDR + 0x00000038;
volatile uint32_t *DSI_0_0x03C_VID_HLINE_TIME           = DSI_0_BASE_ADDR + 0x0000003C;
volatile uint32_t *DSI_0_0x040_VID_VSA_LINES            = DSI_0_BASE_ADDR + 0x00000040;
volatile uint32_t *DSI_0_0x044_VID_VBP_LINES            = DSI_0_BASE_ADDR + 0x00000044;
volatile uint32_t *DSI_0_0x048_VID_VFP_LINES            = DSI_0_BASE_ADDR + 0x00000048;
volatile uint32_t *DSI_0_0x04C_VID_VACTIVE_LINES        = DSI_0_BASE_ADDR + 0x0000004C;
volatile uint32_t *DSI_0_0x050_ALDPI_CMD_SIZE           = DSI_0_BASE_ADDR + 0x00000050;
volatile uint32_t *DSI_0_0x054_CMD_MODE_CFG             = DSI_0_BASE_ADDR + 0x00000054;
volatile uint32_t *DSI_0_0x058_GEN_HDR                  = DSI_0_BASE_ADDR + 0x00000058;
volatile uint32_t *DSI_0_0x05C_GEN_PLD_DATA             = DSI_0_BASE_ADDR + 0x0000005C;
volatile uint32_t *DSI_0_0x060_GEN_RD_HDR               = DSI_0_BASE_ADDR + 0x00000060;
volatile uint32_t *DSI_0_0x064_GEN_RD_PLD_DATA          = DSI_0_BASE_ADDR + 0x00000064;
volatile uint32_t *DSI_0_0x068_CMD_PKT_STATUS           = DSI_0_BASE_ADDR + 0x00000068;
volatile uint32_t *DSI_0_0x06C_TO_CNT_CFG               = DSI_0_BASE_ADDR + 0x0000006C;
volatile uint32_t *DSI_0_0x070_HS_RD_TO_CNT             = DSI_0_BASE_ADDR + 0x00000070;
volatile uint32_t *DSI_0_0x074_LP_RD_TO_CNT             = DSI_0_BASE_ADDR + 0x00000074;
volatile uint32_t *DSI_0_0x078_HS_WR_TO_CNT             = DSI_0_BASE_ADDR + 0x00000078;
volatile uint32_t *DSI_0_0x07C_LP_WR_TO_CNT             = DSI_0_BASE_ADDR + 0x0000007C;
volatile uint32_t *DSI_0_0x080_BTA_TO_CNT               = DSI_0_BASE_ADDR + 0x00000080;
volatile uint32_t *DSI_0_0x084_DEVICE_LPTXRDY_TO_CNT    = DSI_0_BASE_ADDR + 0x00000084;
volatile uint32_t *DSI_0_0x088_DEVICE_LPTX_TO_CNT       = DSI_0_BASE_ADDR + 0x00000088;
volatile uint32_t *DSI_0_0x08C_DEVICE_HSRX_TO_CNT       = DSI_0_BASE_ADDR + 0x0000008C;
volatile uint32_t *DSI_0_0x090_DEVICE_DDI_VALID_VC_CFG  = DSI_0_BASE_ADDR + 0x00000090;
volatile uint32_t *DSI_0_0x094_DEVICE_CTRL_CFG          = DSI_0_BASE_ADDR + 0x00000094;
volatile uint32_t *DSI_0_0x098_DEVICE_FIFO_STATUS       = DSI_0_BASE_ADDR + 0x00000098;
volatile uint32_t *DSI_0_0x09C_VID_PKT_STATUS           = DSI_0_BASE_ADDR + 0x0000009C;
volatile uint32_t *DSI_0_0x0A0_LPCLK_CTRL               = DSI_0_BASE_ADDR + 0x000000A0;
volatile uint32_t *DSI_0_0x0A4_PHY_TMR_LPCLK_CFG        = DSI_0_BASE_ADDR + 0x000000A4;
volatile uint32_t *DSI_0_0x0A8_PHY_TMR_CFG              = DSI_0_BASE_ADDR + 0x000000A8;
volatile uint32_t *DSI_0_0x0AC_PHY_TMR_RD_CFG           = DSI_0_BASE_ADDR + 0x000000AC;
volatile uint32_t *DSI_0_0x0B0_PHY_RSTZ                 = DSI_0_BASE_ADDR + 0x000000B0;
volatile uint32_t *DSI_0_0x0B4_PHY_IF_CFG               = DSI_0_BASE_ADDR + 0x000000B4;
volatile uint32_t *DSI_0_0x0B8_PHY_ULPS_CTRL            = DSI_0_BASE_ADDR + 0x000000B8;
volatile uint32_t *DSI_0_0x0BC_PHY_TX_TRIGGERS          = DSI_0_BASE_ADDR + 0x000000BC;
volatile uint32_t *DSI_0_0x0C0_PHY_STATUS               = DSI_0_BASE_ADDR + 0x000000C0;
volatile uint32_t *DSI_0_0x0C4_PHY_CAL                  = DSI_0_BASE_ADDR + 0x000000C4;
volatile uint32_t *DSI_0_0x0C8_INT_ST_MAIN              = DSI_0_BASE_ADDR + 0x000000C8;
volatile uint32_t *DSI_0_0x0CC_INT_ST0                  = DSI_0_BASE_ADDR + 0x000000CC;
volatile uint32_t *DSI_0_0x0D0_INT_MSK0                 = DSI_0_BASE_ADDR + 0x000000D0;
volatile uint32_t *DSI_0_0x0D4_INT_FORCE0               = DSI_0_BASE_ADDR + 0x000000D4;
volatile uint32_t *DSI_0_0x0D8_INT_ST1                  = DSI_0_BASE_ADDR + 0x000000D8;
volatile uint32_t *DSI_0_0x0DC_INT_MSK1                 = DSI_0_BASE_ADDR + 0x000000DC;
volatile uint32_t *DSI_0_0x0E0_INT_FORCE1               = DSI_0_BASE_ADDR + 0x000000E0;
volatile uint32_t *DSI_0_0x0E4_INT_ST_PHY_FATAL         = DSI_0_BASE_ADDR + 0x000000E4;
volatile uint32_t *DSI_0_0x0E8_INT_MSK_N_PHY_FATAL      = DSI_0_BASE_ADDR + 0x000000E8;
volatile uint32_t *DSI_0_0x0EC_INT_FORCE_PHY_FATAL      = DSI_0_BASE_ADDR + 0x000000EC;
volatile uint32_t *DSI_0_0x0F0_INT_ST_DSI_FATAL         = DSI_0_BASE_ADDR + 0x000000F0;
volatile uint32_t *DSI_0_0x0F4_INT_MSK_N_DSI_FATAL      = DSI_0_BASE_ADDR + 0x000000F4;
volatile uint32_t *DSI_0_0x0F8_INT_FORCE_DSI_FATAL      = DSI_0_BASE_ADDR + 0x000000F8;
volatile uint32_t *DSI_0_0x0FC_INT_ST_DDI_FATAL         = DSI_0_BASE_ADDR + 0x000000FC;
volatile uint32_t *DSI_0_0x100_INT_MSK_N_DDI_FATAL      = DSI_0_BASE_ADDR + 0x00000100;
volatile uint32_t *DSI_0_0x104_INT_FORCE_DDI_FATAL      = DSI_0_BASE_ADDR + 0x00000104;
volatile uint32_t *DSI_0_0x108_INT_ST_FIFO_FATAL        = DSI_0_BASE_ADDR + 0x00000108;
volatile uint32_t *DSI_0_0x10C_INT_MSK_N_FIFO_FATAL     = DSI_0_BASE_ADDR + 0x0000010C;
volatile uint32_t *DSI_0_0x110_INT_FORCE_FIFO_FATAL     = DSI_0_BASE_ADDR + 0x00000110;
volatile uint32_t *DSI_0_0x114_INT_ST_ERR_RPT           = DSI_0_BASE_ADDR + 0x00000114;
volatile uint32_t *DSI_0_0x118_INT_MSK_N_ERR_RPT        = DSI_0_BASE_ADDR + 0x00000118;
volatile uint32_t *DSI_0_0x11C_INT_FORCE_ERR_RPT        = DSI_0_BASE_ADDR + 0x0000011C;
volatile uint32_t *DSI_0_0x120_INT_ST_RX_TRIGGERS       = DSI_0_BASE_ADDR + 0x00000120;
volatile uint32_t *DSI_0_0x124_INT_MSK_N_RX_TRIGGERS    = DSI_0_BASE_ADDR + 0x00000124;
volatile uint32_t *DSI_0_0x128_INT_FORCE_RX_TRIGGERS    = DSI_0_BASE_ADDR + 0x00000128;
volatile uint32_t *DSI_0_0x12C_TX_PLL                   = DSI_0_BASE_ADDR + 0x0000012C;
volatile uint32_t *DSI_0_0x130_PHY_DIG_CTRL0            = DSI_0_BASE_ADDR + 0x00000130;
volatile uint32_t *DSI_0_0x134_PHY_DIG_CTRL1            = DSI_0_BASE_ADDR + 0x00000134;
volatile uint32_t *DSI_0_0x138_PHY_DIG_CTRL2            = DSI_0_BASE_ADDR + 0x00000138;
volatile uint32_t *DSI_0_0x13C_PHY_DIG_CTRL3            = DSI_0_BASE_ADDR + 0x0000013C;
volatile uint32_t *DSI_0_0x140_PHY_DIG_CTRL4            = DSI_0_BASE_ADDR + 0x00000140;
volatile uint32_t *DSI_0_0x144_PHY_DIG_CTRL5            = DSI_0_BASE_ADDR + 0x00000144;
volatile uint32_t *DSI_0_0x148_PHY_DIG_TO_0             = DSI_0_BASE_ADDR + 0x00000148;
volatile uint32_t *DSI_0_0x14C_PHY_DIG_TO_1             = DSI_0_BASE_ADDR + 0x0000014C;
volatile uint32_t *DSI_0_0x150_PHY_DIG_TO_2             = DSI_0_BASE_ADDR + 0x00000150;
volatile uint32_t *DSI_0_0x154_PHY_DIG_TO_3             = DSI_0_BASE_ADDR + 0x00000154;
volatile uint32_t *DSI_0_0x158_PHY_DIG_RSVD             = DSI_0_BASE_ADDR + 0x00000158;

volatile uint32_t *DSI_1_0x000_PWR_UP                   = DSI_1_BASE_ADDR + 0x00000000;
volatile uint32_t *DSI_1_0x004_CLKMGR_CFG               = DSI_1_BASE_ADDR + 0x00000004;
volatile uint32_t *DSI_1_0x008_DPI_VCID                 = DSI_1_BASE_ADDR + 0x00000008;
volatile uint32_t *DSI_1_0x00C_DPI_COLOR_CODING         = DSI_1_BASE_ADDR + 0x0000000C;
volatile uint32_t *DSI_1_0x010_DPI_CFG_POL              = DSI_1_BASE_ADDR + 0x00000010;
volatile uint32_t *DSI_1_0x014_DPI_LP_CMD_TIM           = DSI_1_BASE_ADDR + 0x00000014;
volatile uint32_t *DSI_1_0x018_PCKHDL_CFG               = DSI_1_BASE_ADDR + 0x00000018;
volatile uint32_t *DSI_1_0x01C_GEN_VCID                 = DSI_1_BASE_ADDR + 0x0000001C;
volatile uint32_t *DSI_1_0x020_MODE_CFG                 = DSI_1_BASE_ADDR + 0x00000020;
volatile uint32_t *DSI_1_0x024_VID_MODE_CFG             = DSI_1_BASE_ADDR + 0x00000024;
volatile uint32_t *DSI_1_0x028_VID_PKT_SIZE             = DSI_1_BASE_ADDR + 0x00000028;
volatile uint32_t *DSI_1_0x02C_VID_NUM_CHUNKS           = DSI_1_BASE_ADDR + 0x0000002C;
volatile uint32_t *DSI_1_0x030_VID_NULL_SIZE            = DSI_1_BASE_ADDR + 0x00000030;
volatile uint32_t *DSI_1_0x034_VID_HSA_TIME             = DSI_1_BASE_ADDR + 0x00000034;
volatile uint32_t *DSI_1_0x038_VID_HBP_TIME             = DSI_1_BASE_ADDR + 0x00000038;
volatile uint32_t *DSI_1_0x03C_VID_HLINE_TIME           = DSI_1_BASE_ADDR + 0x0000003C;
volatile uint32_t *DSI_1_0x040_VID_VSA_LINES            = DSI_1_BASE_ADDR + 0x00000040;
volatile uint32_t *DSI_1_0x044_VID_VBP_LINES            = DSI_1_BASE_ADDR + 0x00000044;
volatile uint32_t *DSI_1_0x048_VID_VFP_LINES            = DSI_1_BASE_ADDR + 0x00000048;
volatile uint32_t *DSI_1_0x04C_VID_VACTIVE_LINES        = DSI_1_BASE_ADDR + 0x0000004C;
volatile uint32_t *DSI_1_0x050_ALDPI_CMD_SIZE           = DSI_1_BASE_ADDR + 0x00000050;
volatile uint32_t *DSI_1_0x054_CMD_MODE_CFG             = DSI_1_BASE_ADDR + 0x00000054;
volatile uint32_t *DSI_1_0x058_GEN_HDR                  = DSI_1_BASE_ADDR + 0x00000058;
volatile uint32_t *DSI_1_0x05C_GEN_PLD_DATA             = DSI_1_BASE_ADDR + 0x0000005C;
volatile uint32_t *DSI_1_0x060_GEN_RD_HDR               = DSI_1_BASE_ADDR + 0x00000060;
volatile uint32_t *DSI_1_0x064_GEN_RD_PLD_DATA          = DSI_1_BASE_ADDR + 0x00000064;
volatile uint32_t *DSI_1_0x068_CMD_PKT_STATUS           = DSI_1_BASE_ADDR + 0x00000068;
volatile uint32_t *DSI_1_0x06C_TO_CNT_CFG               = DSI_1_BASE_ADDR + 0x0000006C;
volatile uint32_t *DSI_1_0x070_HS_RD_TO_CNT             = DSI_1_BASE_ADDR + 0x00000070;
volatile uint32_t *DSI_1_0x074_LP_RD_TO_CNT             = DSI_1_BASE_ADDR + 0x00000074;
volatile uint32_t *DSI_1_0x078_HS_WR_TO_CNT             = DSI_1_BASE_ADDR + 0x00000078;
volatile uint32_t *DSI_1_0x07C_LP_WR_TO_CNT             = DSI_1_BASE_ADDR + 0x0000007C;
volatile uint32_t *DSI_1_0x080_BTA_TO_CNT               = DSI_1_BASE_ADDR + 0x00000080;
volatile uint32_t *DSI_1_0x084_DEVICE_LPTXRDY_TO_CNT    = DSI_1_BASE_ADDR + 0x00000084;
volatile uint32_t *DSI_1_0x088_DEVICE_LPTX_TO_CNT       = DSI_1_BASE_ADDR + 0x00000088;
volatile uint32_t *DSI_1_0x08C_DEVICE_HSRX_TO_CNT       = DSI_1_BASE_ADDR + 0x0000008C;
volatile uint32_t *DSI_1_0x090_DEVICE_DDI_VALID_VC_CFG  = DSI_1_BASE_ADDR + 0x00000090;
volatile uint32_t *DSI_1_0x094_DEVICE_CTRL_CFG          = DSI_1_BASE_ADDR + 0x00000094;
volatile uint32_t *DSI_1_0x098_DEVICE_FIFO_STATUS       = DSI_1_BASE_ADDR + 0x00000098;
volatile uint32_t *DSI_1_0x09C_VID_PKT_STATUS           = DSI_1_BASE_ADDR + 0x0000009C;
volatile uint32_t *DSI_1_0x0A0_LPCLK_CTRL               = DSI_1_BASE_ADDR + 0x000000A0;
volatile uint32_t *DSI_1_0x0A4_PHY_TMR_LPCLK_CFG        = DSI_1_BASE_ADDR + 0x000000A4;
volatile uint32_t *DSI_1_0x0A8_PHY_TMR_CFG              = DSI_1_BASE_ADDR + 0x000000A8;
volatile uint32_t *DSI_1_0x0AC_PHY_TMR_RD_CFG           = DSI_1_BASE_ADDR + 0x000000AC;
volatile uint32_t *DSI_1_0x0B0_PHY_RSTZ                 = DSI_1_BASE_ADDR + 0x000000B0;
volatile uint32_t *DSI_1_0x0B4_PHY_IF_CFG               = DSI_1_BASE_ADDR + 0x000000B4;
volatile uint32_t *DSI_1_0x0B8_PHY_ULPS_CTRL            = DSI_1_BASE_ADDR + 0x000000B8;
volatile uint32_t *DSI_1_0x0BC_PHY_TX_TRIGGERS          = DSI_1_BASE_ADDR + 0x000000BC;
volatile uint32_t *DSI_1_0x0C0_PHY_STATUS               = DSI_1_BASE_ADDR + 0x000000C0;
volatile uint32_t *DSI_1_0x0C4_PHY_CAL                  = DSI_1_BASE_ADDR + 0x000000C4;
volatile uint32_t *DSI_1_0x0C8_INT_ST_MAIN              = DSI_1_BASE_ADDR + 0x000000C8;
volatile uint32_t *DSI_1_0x0CC_INT_ST0                  = DSI_1_BASE_ADDR + 0x000000CC;
volatile uint32_t *DSI_1_0x0D0_INT_MSK0                 = DSI_1_BASE_ADDR + 0x000000D0;
volatile uint32_t *DSI_1_0x0D4_INT_FORCE0               = DSI_1_BASE_ADDR + 0x000000D4;
volatile uint32_t *DSI_1_0x0D8_INT_ST1                  = DSI_1_BASE_ADDR + 0x000000D8;
volatile uint32_t *DSI_1_0x0DC_INT_MSK1                 = DSI_1_BASE_ADDR + 0x000000DC;
volatile uint32_t *DSI_1_0x0E0_INT_FORCE1               = DSI_1_BASE_ADDR + 0x000000E0;
volatile uint32_t *DSI_1_0x0E4_INT_ST_PHY_FATAL         = DSI_1_BASE_ADDR + 0x000000E4;
volatile uint32_t *DSI_1_0x0E8_INT_MSK_N_PHY_FATAL      = DSI_1_BASE_ADDR + 0x000000E8;
volatile uint32_t *DSI_1_0x0EC_INT_FORCE_PHY_FATAL      = DSI_1_BASE_ADDR + 0x000000EC;
volatile uint32_t *DSI_1_0x0F0_INT_ST_DSI_FATAL         = DSI_1_BASE_ADDR + 0x000000F0;
volatile uint32_t *DSI_1_0x0F4_INT_MSK_N_DSI_FATAL      = DSI_1_BASE_ADDR + 0x000000F4;
volatile uint32_t *DSI_1_0x0F8_INT_FORCE_DSI_FATAL      = DSI_1_BASE_ADDR + 0x000000F8;
volatile uint32_t *DSI_1_0x0FC_INT_ST_DDI_FATAL         = DSI_1_BASE_ADDR + 0x000000FC;
volatile uint32_t *DSI_1_0x100_INT_MSK_N_DDI_FATAL      = DSI_1_BASE_ADDR + 0x00000100;
volatile uint32_t *DSI_1_0x104_INT_FORCE_DDI_FATAL      = DSI_1_BASE_ADDR + 0x00000104;
volatile uint32_t *DSI_1_0x108_INT_ST_FIFO_FATAL        = DSI_1_BASE_ADDR + 0x00000108;
volatile uint32_t *DSI_1_0x10C_INT_MSK_N_FIFO_FATAL     = DSI_1_BASE_ADDR + 0x0000010C;
volatile uint32_t *DSI_1_0x110_INT_FORCE_FIFO_FATAL     = DSI_1_BASE_ADDR + 0x00000110;
volatile uint32_t *DSI_1_0x114_INT_ST_ERR_RPT           = DSI_1_BASE_ADDR + 0x00000114;
volatile uint32_t *DSI_1_0x118_INT_MSK_N_ERR_RPT        = DSI_1_BASE_ADDR + 0x00000118;
volatile uint32_t *DSI_1_0x11C_INT_FORCE_ERR_RPT        = DSI_1_BASE_ADDR + 0x0000011C;
volatile uint32_t *DSI_1_0x120_INT_ST_RX_TRIGGERS       = DSI_1_BASE_ADDR + 0x00000120;
volatile uint32_t *DSI_1_0x124_INT_MSK_N_RX_TRIGGERS    = DSI_1_BASE_ADDR + 0x00000124;
volatile uint32_t *DSI_1_0x128_INT_FORCE_RX_TRIGGERS    = DSI_1_BASE_ADDR + 0x00000128;
volatile uint32_t *DSI_1_0x12C_TX_PLL                   = DSI_1_BASE_ADDR + 0x0000012C;
volatile uint32_t *DSI_1_0x130_PHY_DIG_CTRL0            = DSI_1_BASE_ADDR + 0x00000130;
volatile uint32_t *DSI_1_0x134_PHY_DIG_CTRL1            = DSI_1_BASE_ADDR + 0x00000134;
volatile uint32_t *DSI_1_0x138_PHY_DIG_CTRL2            = DSI_1_BASE_ADDR + 0x00000138;
volatile uint32_t *DSI_1_0x13C_PHY_DIG_CTRL3            = DSI_1_BASE_ADDR + 0x0000013C;
volatile uint32_t *DSI_1_0x140_PHY_DIG_CTRL4            = DSI_1_BASE_ADDR + 0x00000140;
volatile uint32_t *DSI_1_0x144_PHY_DIG_CTRL5            = DSI_1_BASE_ADDR + 0x00000144;
volatile uint32_t *DSI_1_0x148_PHY_DIG_TO_0             = DSI_1_BASE_ADDR + 0x00000148;
volatile uint32_t *DSI_1_0x14C_PHY_DIG_TO_1             = DSI_1_BASE_ADDR + 0x0000014C;
volatile uint32_t *DSI_1_0x150_PHY_DIG_TO_2             = DSI_1_BASE_ADDR + 0x00000150;
volatile uint32_t *DSI_1_0x154_PHY_DIG_TO_3             = DSI_1_BASE_ADDR + 0x00000154;
volatile uint32_t *DSI_1_0x158_PHY_DIG_RSVD             = DSI_1_BASE_ADDR + 0x00000158;


#define   dsi_0_0x000_pwr_up                    *DSI_0_0x000_PWR_UP                  
#define   dsi_0_0x004_clkmgr_cfg                *DSI_0_0x004_CLKMGR_CFG              
#define   dsi_0_0x008_dpi_vcid                  *DSI_0_0x008_DPI_VCID                
#define   dsi_0_0x00C_dpi_color_coding          *DSI_0_0x00C_DPI_COLOR_CODING        
#define   dsi_0_0x010_dpi_cfg_pol               *DSI_0_0x010_DPI_CFG_POL             
#define   dsi_0_0x014_dpi_lp_cmd_tim            *DSI_0_0x014_DPI_LP_CMD_TIM          
#define   dsi_0_0x018_pckhdl_cfg                *DSI_0_0x018_PCKHDL_CFG              
#define   dsi_0_0x01C_gen_vcid                  *DSI_0_0x01C_GEN_VCID                
#define   dsi_0_0x020_mode_cfg                  *DSI_0_0x020_MODE_CFG                
#define   dsi_0_0x024_vid_mode_cfg              *DSI_0_0x024_VID_MODE_CFG            
#define   dsi_0_0x028_vid_pkt_size              *DSI_0_0x028_VID_PKT_SIZE            
#define   dsi_0_0x02C_vid_num_chunks            *DSI_0_0x02C_VID_NUM_CHUNKS          
#define   dsi_0_0x030_vid_null_size             *DSI_0_0x030_VID_NULL_SIZE           
#define   dsi_0_0x034_vid_hsa_time              *DSI_0_0x034_VID_HSA_TIME            
#define   dsi_0_0x038_vid_hbp_time              *DSI_0_0x038_VID_HBP_TIME            
#define   dsi_0_0x03C_vid_hline_time            *DSI_0_0x03C_VID_HLINE_TIME          
#define   dsi_0_0x040_vid_vsa_lines             *DSI_0_0x040_VID_VSA_LINES           
#define   dsi_0_0x044_vid_vbp_lines             *DSI_0_0x044_VID_VBP_LINES           
#define   dsi_0_0x048_vid_vfp_lines             *DSI_0_0x048_VID_VFP_LINES           
#define   dsi_0_0x04C_vid_vactive_lines         *DSI_0_0x04C_VID_VACTIVE_LINES       
#define   dsi_0_0x050_aldpi_cmd_size            *DSI_0_0x050_ALDPI_CMD_SIZE          
#define   dsi_0_0x054_cmd_mode_cfg              *DSI_0_0x054_CMD_MODE_CFG            
#define   dsi_0_0x058_gen_hdr                   *DSI_0_0x058_GEN_HDR                 
#define   dsi_0_0x05C_gen_pld_data              *DSI_0_0x05C_GEN_PLD_DATA            
#define   dsi_0_0x060_gen_rd_hdr                *DSI_0_0x060_GEN_RD_HDR              
#define   dsi_0_0x064_gen_rd_pld_data           *DSI_0_0x064_GEN_RD_PLD_DATA         
#define   dsi_0_0x068_cmd_pkt_status            *DSI_0_0x068_CMD_PKT_STATUS          
#define   dsi_0_0x06C_to_cnt_cfg                *DSI_0_0x06C_TO_CNT_CFG              
#define   dsi_0_0x070_hs_rd_to_cnt              *DSI_0_0x070_HS_RD_TO_CNT            
#define   dsi_0_0x074_lp_rd_to_cnt              *DSI_0_0x074_LP_RD_TO_CNT            
#define   dsi_0_0x078_hs_wr_to_cnt              *DSI_0_0x078_HS_WR_TO_CNT            
#define   dsi_0_0x07C_lp_wr_to_cnt              *DSI_0_0x07C_LP_WR_TO_CNT            
#define   dsi_0_0x080_bta_to_cnt                *DSI_0_0x080_BTA_TO_CNT              
#define   dsi_0_0x084_device_lptxrdy_to_cnt     *DSI_0_0x084_DEVICE_LPTXRDY_TO_CNT   
#define   dsi_0_0x088_device_lptx_to_cnt        *DSI_0_0x088_DEVICE_LPTX_TO_CNT      
#define   dsi_0_0x08C_device_hsrx_to_cnt        *DSI_0_0x08C_DEVICE_HSRX_TO_CNT      
#define   dsi_0_0x090_device_ddi_valid_vc_cfg   *DSI_0_0x090_DEVICE_DDI_VALID_VC_CFG 
#define   dsi_0_0x094_device_ctrl_cfg           *DSI_0_0x094_DEVICE_CTRL_CFG         
#define   dsi_0_0x098_device_fifo_status        *DSI_0_0x098_DEVICE_FIFO_STATUS      
#define   dsi_0_0x09C_vid_pkt_status            *DSI_0_0x09C_VID_PKT_STATUS          
#define   dsi_0_0x0A0_lpclk_ctrl                *DSI_0_0x0A0_LPCLK_CTRL              
#define   dsi_0_0x0A4_phy_tmr_lpclk_cfg         *DSI_0_0x0A4_PHY_TMR_LPCLK_CFG       
#define   dsi_0_0x0A8_phy_tmr_cfg               *DSI_0_0x0A8_PHY_TMR_CFG             
#define   dsi_0_0x0AC_phy_tmr_rd_cfg            *DSI_0_0x0AC_PHY_TMR_RD_CFG          
#define   dsi_0_0x0B0_phy_rstz                  *DSI_0_0x0B0_PHY_RSTZ                
#define   dsi_0_0x0B4_phy_if_cfg                *DSI_0_0x0B4_PHY_IF_CFG              
#define   dsi_0_0x0B8_phy_ulps_ctrl             *DSI_0_0x0B8_PHY_ULPS_CTRL           
#define   dsi_0_0x0BC_phy_tx_triggers           *DSI_0_0x0BC_PHY_TX_TRIGGERS         
#define   dsi_0_0x0C0_phy_status                *DSI_0_0x0C0_PHY_STATUS              
#define   dsi_0_0x0C4_phy_cal                   *DSI_0_0x0C4_PHY_CAL                 
#define   dsi_0_0x0C8_int_st_main               *DSI_0_0x0C8_INT_ST_MAIN             
#define   dsi_0_0x0CC_int_st0                   *DSI_0_0x0CC_INT_ST0                 
#define   dsi_0_0x0D0_int_msk0                  *DSI_0_0x0D0_INT_MSK0                
#define   dsi_0_0x0D4_int_force0                *DSI_0_0x0D4_INT_FORCE0              
#define   dsi_0_0x0D8_int_st1                   *DSI_0_0x0D8_INT_ST1                 
#define   dsi_0_0x0DC_int_msk1                  *DSI_0_0x0DC_INT_MSK1                
#define   dsi_0_0x0E0_int_force1                *DSI_0_0x0E0_INT_FORCE1              
#define   dsi_0_0x0E4_int_st_phy_fatal          *DSI_0_0x0E4_INT_ST_PHY_FATAL        
#define   dsi_0_0x0E8_int_msk_n_phy_fatal       *DSI_0_0x0E8_INT_MSK_N_PHY_FATAL     
#define   dsi_0_0x0EC_int_force_phy_fatal       *DSI_0_0x0EC_INT_FORCE_PHY_FATAL     
#define   dsi_0_0x0F0_int_st_dsi_fatal          *DSI_0_0x0F0_INT_ST_DSI_FATAL        
#define   dsi_0_0x0F4_int_msk_n_dsi_fatal       *DSI_0_0x0F4_INT_MSK_N_DSI_FATAL     
#define   dsi_0_0x0F8_int_force_dsi_fatal       *DSI_0_0x0F8_INT_FORCE_DSI_FATAL     
#define   dsi_0_0x0FC_int_st_ddi_fatal          *DSI_0_0x0FC_INT_ST_DDI_FATAL        
#define   dsi_0_0x100_int_msk_n_ddi_fatal       *DSI_0_0x100_INT_MSK_N_DDI_FATAL     
#define   dsi_0_0x104_int_force_ddi_fatal       *DSI_0_0x104_INT_FORCE_DDI_FATAL     
#define   dsi_0_0x108_int_st_fifo_fatal         *DSI_0_0x108_INT_ST_FIFO_FATAL       
#define   dsi_0_0x10C_int_msk_n_fifo_fatal      *DSI_0_0x10C_INT_MSK_N_FIFO_FATAL    
#define   dsi_0_0x110_int_force_fifo_fatal      *DSI_0_0x110_INT_FORCE_FIFO_FATAL    
#define   dsi_0_0x114_int_st_err_rpt            *DSI_0_0x114_INT_ST_ERR_RPT          
#define   dsi_0_0x118_int_msk_n_err_rpt         *DSI_0_0x118_INT_MSK_N_ERR_RPT       
#define   dsi_0_0x11C_int_force_err_rpt         *DSI_0_0x11C_INT_FORCE_ERR_RPT       
#define   dsi_0_0x120_int_st_rx_triggers        *DSI_0_0x120_INT_ST_RX_TRIGGERS      
#define   dsi_0_0x124_int_msk_n_rx_triggers     *DSI_0_0x124_INT_MSK_N_RX_TRIGGERS   
#define   dsi_0_0x128_int_force_rx_triggers     *DSI_0_0x128_INT_FORCE_RX_TRIGGERS   
#define   dsi_0_0x12C_tx_pll                    *DSI_0_0x12C_TX_PLL                  
#define   dsi_0_0x130_phy_dig_ctrl0             *DSI_0_0x130_PHY_DIG_CTRL0           
#define   dsi_0_0x134_phy_dig_ctrl1             *DSI_0_0x134_PHY_DIG_CTRL1           
#define   dsi_0_0x138_phy_dig_ctrl2             *DSI_0_0x138_PHY_DIG_CTRL2           
#define   dsi_0_0x13C_phy_dig_ctrl3             *DSI_0_0x13C_PHY_DIG_CTRL3           
#define   dsi_0_0x140_phy_dig_ctrl4             *DSI_0_0x140_PHY_DIG_CTRL4           
#define   dsi_0_0x144_phy_dig_ctrl5             *DSI_0_0x144_PHY_DIG_CTRL5           
#define   dsi_0_0x148_phy_dig_to_0              *DSI_0_0x148_PHY_DIG_TO_0            
#define   dsi_0_0x14C_phy_dig_to_1              *DSI_0_0x14C_PHY_DIG_TO_1            
#define   dsi_0_0x150_phy_dig_to_2              *DSI_0_0x150_PHY_DIG_TO_2            
#define   dsi_0_0x154_phy_dig_to_3              *DSI_0_0x154_PHY_DIG_TO_3            
#define   dsi_0_0x158_phy_dig_rsvd              *DSI_0_0x158_PHY_DIG_RSVD            


#define   dsi_1_0x000_pwr_up                    *DSI_1_0x000_PWR_UP                  
#define   dsi_1_0x004_clkmgr_cfg                *DSI_1_0x004_CLKMGR_CFG              
#define   dsi_1_0x008_dpi_vcid                  *DSI_1_0x008_DPI_VCID                
#define   dsi_1_0x00C_dpi_color_coding          *DSI_1_0x00C_DPI_COLOR_CODING        
#define   dsi_1_0x010_dpi_cfg_pol               *DSI_1_0x010_DPI_CFG_POL             
#define   dsi_1_0x014_dpi_lp_cmd_tim            *DSI_1_0x014_DPI_LP_CMD_TIM          
#define   dsi_1_0x018_pckhdl_cfg                *DSI_1_0x018_PCKHDL_CFG              
#define   dsi_1_0x01C_gen_vcid                  *DSI_1_0x01C_GEN_VCID                
#define   dsi_1_0x020_mode_cfg                  *DSI_1_0x020_MODE_CFG                
#define   dsi_1_0x024_vid_mode_cfg              *DSI_1_0x024_VID_MODE_CFG            
#define   dsi_1_0x028_vid_pkt_size              *DSI_1_0x028_VID_PKT_SIZE            
#define   dsi_1_0x02C_vid_num_chunks            *DSI_1_0x02C_VID_NUM_CHUNKS          
#define   dsi_1_0x030_vid_null_size             *DSI_1_0x030_VID_NULL_SIZE           
#define   dsi_1_0x034_vid_hsa_time              *DSI_1_0x034_VID_HSA_TIME            
#define   dsi_1_0x038_vid_hbp_time              *DSI_1_0x038_VID_HBP_TIME            
#define   dsi_1_0x03C_vid_hline_time            *DSI_1_0x03C_VID_HLINE_TIME          
#define   dsi_1_0x040_vid_vsa_lines             *DSI_1_0x040_VID_VSA_LINES           
#define   dsi_1_0x044_vid_vbp_lines             *DSI_1_0x044_VID_VBP_LINES           
#define   dsi_1_0x048_vid_vfp_lines             *DSI_1_0x048_VID_VFP_LINES           
#define   dsi_1_0x04C_vid_vactive_lines         *DSI_1_0x04C_VID_VACTIVE_LINES       
#define   dsi_1_0x050_aldpi_cmd_size            *DSI_1_0x050_ALDPI_CMD_SIZE          
#define   dsi_1_0x054_cmd_mode_cfg              *DSI_1_0x054_CMD_MODE_CFG            
#define   dsi_1_0x058_gen_hdr                   *DSI_1_0x058_GEN_HDR                 
#define   dsi_1_0x05C_gen_pld_data              *DSI_1_0x05C_GEN_PLD_DATA            
#define   dsi_1_0x060_gen_rd_hdr                *DSI_1_0x060_GEN_RD_HDR              
#define   dsi_1_0x064_gen_rd_pld_data           *DSI_1_0x064_GEN_RD_PLD_DATA         
#define   dsi_1_0x068_cmd_pkt_status            *DSI_1_0x068_CMD_PKT_STATUS          
#define   dsi_1_0x06C_to_cnt_cfg                *DSI_1_0x06C_TO_CNT_CFG              
#define   dsi_1_0x070_hs_rd_to_cnt              *DSI_1_0x070_HS_RD_TO_CNT            
#define   dsi_1_0x074_lp_rd_to_cnt              *DSI_1_0x074_LP_RD_TO_CNT            
#define   dsi_1_0x078_hs_wr_to_cnt              *DSI_1_0x078_HS_WR_TO_CNT            
#define   dsi_1_0x07C_lp_wr_to_cnt              *DSI_1_0x07C_LP_WR_TO_CNT            
#define   dsi_1_0x080_bta_to_cnt                *DSI_1_0x080_BTA_TO_CNT              
#define   dsi_1_0x084_device_lptxrdy_to_cnt     *DSI_1_0x084_DEVICE_LPTXRDY_TO_CNT   
#define   dsi_1_0x088_device_lptx_to_cnt        *DSI_1_0x088_DEVICE_LPTX_TO_CNT      
#define   dsi_1_0x08C_device_hsrx_to_cnt        *DSI_1_0x08C_DEVICE_HSRX_TO_CNT      
#define   dsi_1_0x090_device_ddi_valid_vc_cfg   *DSI_1_0x090_DEVICE_DDI_VALID_VC_CFG 
#define   dsi_1_0x094_device_ctrl_cfg           *DSI_1_0x094_DEVICE_CTRL_CFG         
#define   dsi_1_0x098_device_fifo_status        *DSI_1_0x098_DEVICE_FIFO_STATUS      
#define   dsi_1_0x09C_vid_pkt_status            *DSI_1_0x09C_VID_PKT_STATUS          
#define   dsi_1_0x0A0_lpclk_ctrl                *DSI_1_0x0A0_LPCLK_CTRL              
#define   dsi_1_0x0A4_phy_tmr_lpclk_cfg         *DSI_1_0x0A4_PHY_TMR_LPCLK_CFG       
#define   dsi_1_0x0A8_phy_tmr_cfg               *DSI_1_0x0A8_PHY_TMR_CFG             
#define   dsi_1_0x0AC_phy_tmr_rd_cfg            *DSI_1_0x0AC_PHY_TMR_RD_CFG          
#define   dsi_1_0x0B0_phy_rstz                  *DSI_1_0x0B0_PHY_RSTZ                
#define   dsi_1_0x0B4_phy_if_cfg                *DSI_1_0x0B4_PHY_IF_CFG              
#define   dsi_1_0x0B8_phy_ulps_ctrl             *DSI_1_0x0B8_PHY_ULPS_CTRL           
#define   dsi_1_0x0BC_phy_tx_triggers           *DSI_1_0x0BC_PHY_TX_TRIGGERS         
#define   dsi_1_0x0C0_phy_status                *DSI_1_0x0C0_PHY_STATUS              
#define   dsi_1_0x0C4_phy_cal                   *DSI_1_0x0C4_PHY_CAL                 
#define   dsi_1_0x0C8_int_st_main               *DSI_1_0x0C8_INT_ST_MAIN             
#define   dsi_1_0x0CC_int_st0                   *DSI_1_0x0CC_INT_ST0                 
#define   dsi_1_0x0D0_int_msk0                  *DSI_1_0x0D0_INT_MSK0                
#define   dsi_1_0x0D4_int_force0                *DSI_1_0x0D4_INT_FORCE0              
#define   dsi_1_0x0D8_int_st1                   *DSI_1_0x0D8_INT_ST1                 
#define   dsi_1_0x0DC_int_msk1                  *DSI_1_0x0DC_INT_MSK1                
#define   dsi_1_0x0E0_int_force1                *DSI_1_0x0E0_INT_FORCE1              
#define   dsi_1_0x0E4_int_st_phy_fatal          *DSI_1_0x0E4_INT_ST_PHY_FATAL        
#define   dsi_1_0x0E8_int_msk_n_phy_fatal       *DSI_1_0x0E8_INT_MSK_N_PHY_FATAL     
#define   dsi_1_0x0EC_int_force_phy_fatal       *DSI_1_0x0EC_INT_FORCE_PHY_FATAL     
#define   dsi_1_0x0F0_int_st_dsi_fatal          *DSI_1_0x0F0_INT_ST_DSI_FATAL        
#define   dsi_1_0x0F4_int_msk_n_dsi_fatal       *DSI_1_0x0F4_INT_MSK_N_DSI_FATAL     
#define   dsi_1_0x0F8_int_force_dsi_fatal       *DSI_1_0x0F8_INT_FORCE_DSI_FATAL     
#define   dsi_1_0x0FC_int_st_ddi_fatal          *DSI_1_0x0FC_INT_ST_DDI_FATAL        
#define   dsi_1_0x100_int_msk_n_ddi_fatal       *DSI_1_0x100_INT_MSK_N_DDI_FATAL     
#define   dsi_1_0x104_int_force_ddi_fatal       *DSI_1_0x104_INT_FORCE_DDI_FATAL     
#define   dsi_1_0x108_int_st_fifo_fatal         *DSI_1_0x108_INT_ST_FIFO_FATAL       
#define   dsi_1_0x10C_int_msk_n_fifo_fatal      *DSI_1_0x10C_INT_MSK_N_FIFO_FATAL    
#define   dsi_1_0x110_int_force_fifo_fatal      *DSI_1_0x110_INT_FORCE_FIFO_FATAL    
#define   dsi_1_0x114_int_st_err_rpt            *DSI_1_0x114_INT_ST_ERR_RPT          
#define   dsi_1_0x118_int_msk_n_err_rpt         *DSI_1_0x118_INT_MSK_N_ERR_RPT       
#define   dsi_1_0x11C_int_force_err_rpt         *DSI_1_0x11C_INT_FORCE_ERR_RPT       
#define   dsi_1_0x120_int_st_rx_triggers        *DSI_1_0x120_INT_ST_RX_TRIGGERS      
#define   dsi_1_0x124_int_msk_n_rx_triggers     *DSI_1_0x124_INT_MSK_N_RX_TRIGGERS   
#define   dsi_1_0x128_int_force_rx_triggers     *DSI_1_0x128_INT_FORCE_RX_TRIGGERS   
#define   dsi_1_0x12C_tx_pll                    *DSI_1_0x12C_TX_PLL                  
#define   dsi_1_0x130_phy_dig_ctrl0             *DSI_1_0x130_PHY_DIG_CTRL0           
#define   dsi_1_0x134_phy_dig_ctrl1             *DSI_1_0x134_PHY_DIG_CTRL1           
#define   dsi_1_0x138_phy_dig_ctrl2             *DSI_1_0x138_PHY_DIG_CTRL2           
#define   dsi_1_0x13C_phy_dig_ctrl3             *DSI_1_0x13C_PHY_DIG_CTRL3           
#define   dsi_1_0x140_phy_dig_ctrl4             *DSI_1_0x140_PHY_DIG_CTRL4           
#define   dsi_1_0x144_phy_dig_ctrl5             *DSI_1_0x144_PHY_DIG_CTRL5           
#define   dsi_1_0x148_phy_dig_to_0              *DSI_1_0x148_PHY_DIG_TO_0            
#define   dsi_1_0x14C_phy_dig_to_1              *DSI_1_0x14C_PHY_DIG_TO_1            
#define   dsi_1_0x150_phy_dig_to_2              *DSI_1_0x150_PHY_DIG_TO_2            
#define   dsi_1_0x154_phy_dig_to_3              *DSI_1_0x154_PHY_DIG_TO_3            
#define   dsi_1_0x158_phy_dig_rsvd              *DSI_1_0x158_PHY_DIG_RSVD            






#endif /* APPLICATION_INC_DSI_REGISTER_ADDR_TABLE_H_ */
