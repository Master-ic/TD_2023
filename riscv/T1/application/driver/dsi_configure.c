/*
 * dsi_configure.c
 *
 *  Created on: 2022年3月4日
 *      Author: guoqiang.xiong
 */
#include "../inc/dsi_register_addr_table.h"
#include "../inc/dsi_configure.h"



void lcd_screen_config()
{
	dsi_0_0x020_mode_cfg = 0x00000001;  ///切换成command模式才能发送lp数据

	dsi_0_dcs_data_write_1p(0xB0,0x01);
	dsi_0_dcs_data_write_1p(0xC3,0x0F);
	dsi_0_dcs_data_write_1p(0xC4,0x00);
	dsi_0_dcs_data_write_1p(0xC5,0x00);
	dsi_0_dcs_data_write_1p(0xC6,0x00);
	dsi_0_dcs_data_write_1p(0xC7,0x00);
	dsi_0_dcs_data_write_1p(0xC8,0x0D);
	dsi_0_dcs_data_write_1p(0xC9,0x12);
	dsi_0_dcs_data_write_1p(0xCA,0x11);
	dsi_0_dcs_data_write_1p(0xCD,0x1D);
	dsi_0_dcs_data_write_1p(0xCE,0x1B);
	dsi_0_dcs_data_write_1p(0xCF,0x0B);
	dsi_0_dcs_data_write_1p(0xD0,0x09);
	dsi_0_dcs_data_write_1p(0xD1,0x07);
	dsi_0_dcs_data_write_1p(0xD2,0x05);
	dsi_0_dcs_data_write_1p(0xD3,0x01);
	dsi_0_dcs_data_write_1p(0xD7,0x10);
	dsi_0_dcs_data_write_1p(0xD8,0x00);
	dsi_0_dcs_data_write_1p(0xD9,0x00);
	dsi_0_dcs_data_write_1p(0xDA,0x00);
	dsi_0_dcs_data_write_1p(0xDB,0x00);
	dsi_0_dcs_data_write_1p(0xDC,0x0E);
	dsi_0_dcs_data_write_1p(0xDD,0x12);
	dsi_0_dcs_data_write_1p(0xDE,0x11);
	dsi_0_dcs_data_write_1p(0xE1,0x1E);
	dsi_0_dcs_data_write_1p(0xE2,0x1C);
	dsi_0_dcs_data_write_1p(0xE3,0x0C);
	dsi_0_dcs_data_write_1p(0xE4,0x0A);
	dsi_0_dcs_data_write_1p(0xE5,0x08);
	dsi_0_dcs_data_write_1p(0xE6,0x06);
	dsi_0_dcs_data_write_1p(0xE7,0x02);
	dsi_0_dcs_data_write_1p(0xB0,0x03);
	dsi_0_dcs_data_write_1p(0xBE,0x03);
	dsi_0_dcs_data_write_1p(0xCC,0x44);
	dsi_0_dcs_data_write_1p(0xC8,0x07);
	dsi_0_dcs_data_write_1p(0xC9,0x05);
	dsi_0_dcs_data_write_1p(0xCA,0x42);
	dsi_0_dcs_data_write_1p(0xCD,0x3E);
	dsi_0_dcs_data_write_1p(0xCF,0x60);
	dsi_0_dcs_data_write_1p(0xD2,0x04);
	dsi_0_dcs_data_write_1p(0xD3,0x04);
	dsi_0_dcs_data_write_1p(0xD4,0x01);
	dsi_0_dcs_data_write_1p(0xD5,0x00);
	dsi_0_dcs_data_write_1p(0xD6,0x03);
	dsi_0_dcs_data_write_1p(0xD7,0x04);
	dsi_0_dcs_data_write_1p(0xD9,0x01);
	dsi_0_dcs_data_write_1p(0xDB,0x01);
	dsi_0_dcs_data_write_1p(0xE4,0xF0);
	dsi_0_dcs_data_write_1p(0xE5,0x0A);
	dsi_0_dcs_data_write_1p(0xB0,0x00);
	dsi_0_dcs_data_write_1p(0xBD,0x63);
	dsi_0_dcs_data_write_1p(0xC2,0x08);
	dsi_0_dcs_data_write_1p(0xC4,0x10);
	dsi_0_dcs_data_write_1p(0xB0,0x02);
	dsi_0_dcs_data_write_1p(0xC0,0x00);
	dsi_0_dcs_data_write_1p(0xC1,0x0A);
	dsi_0_dcs_data_write_1p(0xC2,0x20);
	dsi_0_dcs_data_write_1p(0xC3,0x24);
	dsi_0_dcs_data_write_1p(0xC4,0x23);
	dsi_0_dcs_data_write_1p(0xC5,0x29);
	dsi_0_dcs_data_write_1p(0xC6,0x23);
	dsi_0_dcs_data_write_1p(0xC7,0x1C);
	dsi_0_dcs_data_write_1p(0xC8,0x19);
	dsi_0_dcs_data_write_1p(0xC9,0x17);
	dsi_0_dcs_data_write_1p(0xCA,0x17);
	dsi_0_dcs_data_write_1p(0xCB,0x18);
	dsi_0_dcs_data_write_1p(0xCC,0x1A);
	dsi_0_dcs_data_write_1p(0xCD,0x1E);
	dsi_0_dcs_data_write_1p(0xCE,0x20);
	dsi_0_dcs_data_write_1p(0xCF,0x23);
	dsi_0_dcs_data_write_1p(0xD0,0x07);
	dsi_0_dcs_data_write_1p(0xD1,0x00);
	dsi_0_dcs_data_write_1p(0xD2,0x00);
	dsi_0_dcs_data_write_1p(0xD3,0x0A);
	dsi_0_dcs_data_write_1p(0xD4,0x13);
	dsi_0_dcs_data_write_1p(0xD5,0x1C);
	dsi_0_dcs_data_write_1p(0xD6,0x1A);
	dsi_0_dcs_data_write_1p(0xD7,0x13);
	dsi_0_dcs_data_write_1p(0xD8,0x17);
	dsi_0_dcs_data_write_1p(0xD9,0x1C);
	dsi_0_dcs_data_write_1p(0xDA,0x19);
	dsi_0_dcs_data_write_1p(0xDB,0x17);
	dsi_0_dcs_data_write_1p(0xDC,0x17);
	dsi_0_dcs_data_write_1p(0xDD,0x18);
	dsi_0_dcs_data_write_1p(0xDE,0x1A);
	dsi_0_dcs_data_write_1p(0xDF,0x1E);
	dsi_0_dcs_data_write_1p(0xE0,0x20);
	dsi_0_dcs_data_write_1p(0xE1,0x23);
	dsi_0_dcs_data_write_1p(0xE2,0x07);

	dsi_0_dcs_data_write_np(0x11);    
	delay_1ms(240);
	dsi_0_dcs_data_write_np(0x29);    
	delay_1ms(40);

	dsi_0_0x020_mode_cfg = 0x00000000;  ///lp数据发送完了之后切回video模式

	printf("screen configure done!!\n");
}


void dsi_0_dcs_data_write_np(uint8_t data)
{
	uint8_t dcs_short_np_dt = 0x05;

	dsi_0_0x058_gen_hdr = (0x00 << 24) + (0x00 << 16) + (data << 8) + dcs_short_np_dt;
	delay_1us(10);
}

void dsi_0_dcs_data_write_1p(uint8_t data0,uint8_t data1)
{
	uint8_t dcs_short_1p_dt = 0x15;

	dsi_0_0x058_gen_hdr = (0x00 << 24) + (data1 << 16) + (data0 << 8) + dcs_short_1p_dt;
	delay_1us(10);
}

void dsi_0_dcs_data_write_3p(uint8_t data0,uint8_t data1,uint8_t data2,uint8_t data3)
{
	uint8_t dcs_short_2p_dt = 0x39;
	uint8_t dcs_wc = 4;

	dsi_0_0x05C_gen_pld_data = (data3 << 24) + (data2 << 16) + (data1 << 8) + data0;
	dsi_0_0x058_gen_hdr      = (0x00 << 24) + (0x00 << 16) + (dcs_wc << 8) + dcs_short_2p_dt;
	delay_1us(10);
}


void dsi_0_configure()
{

	dsi_0_0x004_clkmgr_cfg        = 0x00000c0c;
	dsi_0_0x0B4_phy_if_cfg        = 0x00000003;
	dsi_0_0x018_pckhdl_cfg        = 0x00000001;
	dsi_0_0x00C_dpi_color_coding  = 0x00000005;
	dsi_0_0x010_dpi_cfg_pol       = 0x00000000;
	dsi_0_0x020_mode_cfg          = 0x00000000;
	dsi_0_0x024_vid_mode_cfg      = 0x0000ff02;
	dsi_0_0x02C_vid_num_chunks    = 0x00000000;
	dsi_0_0x030_vid_null_size     = 0;

	dsi_0_0x028_vid_pkt_size      = 1200;
	dsi_0_0x034_vid_hsa_time      = 10;   // 40
	dsi_0_0x038_vid_hbp_time      = 50;   // 40
	dsi_0_0x03C_vid_hline_time    = 1341;  // 920

	dsi_0_0x040_vid_vsa_lines     = 3;
	dsi_0_0x044_vid_vbp_lines     = 23;
	dsi_0_0x048_vid_vfp_lines     = 35;
	dsi_0_0x04C_vid_vactive_lines = 1920;

	dsi_0_0x054_cmd_mode_cfg      = 0x000f0000;
	dsi_0_0x0A0_lpclk_ctrl        = 0x00000001;
	dsi_0_0x0A4_phy_tmr_lpclk_cfg = 0x000a000a;
	dsi_0_0x0A8_phy_tmr_cfg       = 0x00300030;  //配置lp进入hs，以及hs进入lp的时间
	dsi_0_0x12C_tx_pll            = 0x49000a03;  //
	dsi_0_0x130_phy_dig_ctrl0     = 0x00112201;
	dsi_0_0x148_phy_dig_to_0      = 0x1667277e;
	dsi_0_0x14C_phy_dig_to_1      = 0xe0d13880;
	dsi_0_0x150_phy_dig_to_2      = 0x51813757;
	dsi_0_0x154_phy_dig_to_3      = 0x00f082ca;

	while((dsi_0_0x0C0_phy_status & 0x00000001) != 0x00000001);

	dsi_0_0x0B0_phy_rstz          = 0x00000007;
	dsi_0_0x000_pwr_up            = 0x00000011;
	dsi_0_0x0A0_lpclk_ctrl        = 0x00000001;

	printf("dsi0 configure done!!\n");
}


void dsi_1_configure()
{

	dsi_1_0x148_phy_dig_to_0      = 0x16650000;
	dsi_1_0x000_pwr_up            = 0x00000001;
	dsi_1_0x0B0_phy_rstz          = 0x0000000f;
	dsi_1_0x0B4_phy_if_cfg        = 0x00000003;
	dsi_1_0x004_clkmgr_cfg        = 0x00000c0c;
	dsi_1_0x130_phy_dig_ctrl0     = 0x00112201;
	dsi_1_0x14C_phy_dig_to_1      = 0xe0c13880;
	dsi_1_0x150_phy_dig_to_2      = 0x51813757;
	dsi_1_0x154_phy_dig_to_3      = 0x00f082ca;
//	dsi_1_0x140_phy_dig_ctrl4     = 0x08002a08;

}


void dsi_0_configure_read()
{

	printf("dsi_0_0x004_clkmgr_cfg        = 0x%08x\n", dsi_0_0x004_clkmgr_cfg       );
	printf("dsi_0_0x0B4_phy_if_cfg        = 0x%08x\n", dsi_0_0x0B4_phy_if_cfg       );
	printf("dsi_0_0x018_pckhdl_cfg        = 0x%08x\n", dsi_0_0x018_pckhdl_cfg       );
	printf("dsi_0_0x00C_dpi_color_coding  = 0x%08x\n", dsi_0_0x00C_dpi_color_coding );
	printf("dsi_0_0x010_dpi_cfg_pol       = 0x%08x\n", dsi_0_0x010_dpi_cfg_pol      );
	printf("dsi_0_0x020_mode_cfg          = 0x%08x\n", dsi_0_0x020_mode_cfg         );
	printf("dsi_0_0x024_vid_mode_cfg      = 0x%08x\n", dsi_0_0x024_vid_mode_cfg     );
	printf("dsi_0_0x028_vid_pkt_size      = 0x%08x\n", dsi_0_0x028_vid_pkt_size     );
	printf("dsi_0_0x02C_vid_num_chunks    = 0x%08x\n", dsi_0_0x02C_vid_num_chunks   );
	printf("dsi_0_0x030_vid_null_size     = 0x%08x\n", dsi_0_0x030_vid_null_size    );
	printf("dsi_0_0x034_vid_hsa_time      = 0x%08x\n", dsi_0_0x034_vid_hsa_time     );
	printf("dsi_0_0x038_vid_hbp_time      = 0x%08x\n", dsi_0_0x038_vid_hbp_time     );
	printf("dsi_0_0x03C_vid_hline_time    = 0x%08x\n", dsi_0_0x03C_vid_hline_time   );
	printf("dsi_0_0x040_vid_vsa_lines     = 0x%08x\n", dsi_0_0x040_vid_vsa_lines    );
	printf("dsi_0_0x044_vid_vbp_lines     = 0x%08x\n", dsi_0_0x044_vid_vbp_lines    );
	printf("dsi_0_0x048_vid_vfp_lines     = 0x%08x\n", dsi_0_0x048_vid_vfp_lines    );
	printf("dsi_0_0x04C_vid_vactive_lines = 0x%08x\n", dsi_0_0x04C_vid_vactive_lines);
	printf("dsi_0_0x054_cmd_mode_cfg      = 0x%08x\n", dsi_0_0x054_cmd_mode_cfg     );
	printf("dsi_0_0x0A0_lpclk_ctrl        = 0x%08x\n", dsi_0_0x0A0_lpclk_ctrl       );
	printf("dsi_0_0x0A4_phy_tmr_lpclk_cfg = 0x%08x\n", dsi_0_0x0A4_phy_tmr_lpclk_cfg);
	printf("dsi_0_0x0A8_phy_tmr_cfg       = 0x%08x\n", dsi_0_0x0A8_phy_tmr_cfg      );
	printf("dsi_0_0x12C_tx_pll            = 0x%08x\n", dsi_0_0x12C_tx_pll           );
	printf("dsi_0_0x130_phy_dig_ctrl0     = 0x%08x\n", dsi_0_0x130_phy_dig_ctrl0    );
	printf("dsi_0_0x140_phy_dig_ctrl4     = 0x%08x\n", dsi_0_0x140_phy_dig_ctrl4    );
	printf("dsi_0_0x148_phy_dig_to_0      = 0x%08x\n", dsi_0_0x148_phy_dig_to_0     );
	printf("dsi_0_0x14C_phy_dig_to_1      = 0x%08x\n", dsi_0_0x14C_phy_dig_to_1     );
	printf("dsi_0_0x150_phy_dig_to_2      = 0x%08x\n", dsi_0_0x150_phy_dig_to_2     );
	printf("dsi_0_0x154_phy_dig_to_3      = 0x%08x\n", dsi_0_0x154_phy_dig_to_3     );
	printf("dsi_0_0x0C0_phy_status        = 0x%08x\n", dsi_0_0x0C0_phy_status       );

}


void dsi_1_configure_read()
{

	printf("dsi_1_0x004_clkmgr_cfg        = 0x%08x\n", dsi_1_0x004_clkmgr_cfg       );
	printf("dsi_1_0x0B4_phy_if_cfg        = 0x%08x\n", dsi_1_0x0B4_phy_if_cfg       );
	printf("dsi_1_0x018_pckhdl_cfg        = 0x%08x\n", dsi_1_0x018_pckhdl_cfg       );
	printf("dsi_1_0x00C_dpi_color_coding  = 0x%08x\n", dsi_1_0x00C_dpi_color_coding );
	printf("dsi_1_0x010_dpi_cfg_pol       = 0x%08x\n", dsi_1_0x010_dpi_cfg_pol      );
	printf("dsi_1_0x020_mode_cfg          = 0x%08x\n", dsi_1_0x020_mode_cfg         );
	printf("dsi_1_0x024_vid_mode_cfg      = 0x%08x\n", dsi_1_0x024_vid_mode_cfg     );
	printf("dsi_1_0x028_vid_pkt_size      = 0x%08x\n", dsi_1_0x028_vid_pkt_size     );
	printf("dsi_1_0x02C_vid_num_chunks    = 0x%08x\n", dsi_1_0x02C_vid_num_chunks   );
	printf("dsi_1_0x030_vid_null_size     = 0x%08x\n", dsi_1_0x030_vid_null_size    );
	printf("dsi_1_0x034_vid_hsa_time      = 0x%08x\n", dsi_1_0x034_vid_hsa_time     );
	printf("dsi_1_0x038_vid_hbp_time      = 0x%08x\n", dsi_1_0x038_vid_hbp_time     );
	printf("dsi_1_0x03C_vid_hline_time    = 0x%08x\n", dsi_1_0x03C_vid_hline_time   );
	printf("dsi_1_0x040_vid_vsa_lines     = 0x%08x\n", dsi_1_0x040_vid_vsa_lines    );
	printf("dsi_1_0x044_vid_vbp_lines     = 0x%08x\n", dsi_1_0x044_vid_vbp_lines    );
	printf("dsi_1_0x048_vid_vfp_lines     = 0x%08x\n", dsi_1_0x048_vid_vfp_lines    );
	printf("dsi_1_0x04C_vid_vactive_lines = 0x%08x\n", dsi_1_0x04C_vid_vactive_lines);
	printf("dsi_1_0x0A0_lpclk_ctrl        = 0x%08x\n", dsi_1_0x0A0_lpclk_ctrl       );
	printf("dsi_1_0x0A4_phy_tmr_lpclk_cfg = 0x%08x\n", dsi_1_0x0A4_phy_tmr_lpclk_cfg);
	printf("dsi_1_0x0A8_phy_tmr_cfg       = 0x%08x\n", dsi_1_0x0A8_phy_tmr_cfg      );
	printf("dsi_1_0x12C_tx_pll            = 0x%08x\n", dsi_1_0x12C_tx_pll           );
	printf("dsi_1_0x130_phy_dig_ctrl0     = 0x%08x\n", dsi_1_0x130_phy_dig_ctrl0    );
	printf("dsi_1_0x148_phy_dig_to_0      = 0x%08x\n", dsi_1_0x148_phy_dig_to_0     );
	printf("dsi_1_0x14C_phy_dig_to_1      = 0x%08x\n", dsi_1_0x14C_phy_dig_to_1     );
	printf("dsi_1_0x150_phy_dig_to_2      = 0x%08x\n", dsi_1_0x150_phy_dig_to_2     );
	printf("dsi_1_0x154_phy_dig_to_3      = 0x%08x\n", dsi_1_0x154_phy_dig_to_3     );
	printf("dsi_1_0x0C0_phy_status        = 0x%08x\n", dsi_1_0x0C0_phy_status       );

}
