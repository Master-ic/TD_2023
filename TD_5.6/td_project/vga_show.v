//file name:	vga_show.v
//author:		ETree
//date:			2021.10.2
//function:		VGA显示器驱动
//log:

module vga_show(
	input        vga_clk,
	input        rst_n, 		        //VGA复位，低电平有效
	
	output       vga_hsync,
	output       vga_vsync,
	output [4:0] vga_r,
	output [5:0] vga_g,
	output [4:0] vga_b,
	
	output       vga_frame_sync,
	output       vga_valid,	
	
	input [31:0] ddr_data,          //DDR中的图像数据
	output reg   ddr_rden,	
	input        ddr_init_done
);

// 水平扫描参数的设定640*480 VGA 60FPS_25MHz
parameter LinePeriod =800;            //行周期数
parameter H_SyncPulse=96;             //行同步脉冲（Sync a）
parameter H_BackPorch=48 ;            //显示后沿（Back porch b）
parameter H_ActivePix=640;            //显示时序段（Display interval c）
parameter H_FrontPorch=16;            //显示前沿（Front porch d）
parameter Hde_start=144;
parameter Hde_end=784;

// 垂直扫描参数的设定640*480 VGA
parameter FramePeriod =525;           //列周期数
parameter V_SyncPulse=2;              //列同步脉冲（Sync o）
parameter V_BackPorch=33 ;            //显示后沿（Back porch p）
parameter V_ActivePix=480;            //显示时序段（Display interval q）
parameter V_FrontPorch=10;            //显示前沿（Front porch r）
parameter Vde_start=35;
parameter Vde_end=515;



localparam SIDE_W  = 11'd40;                    //屏幕边框宽度
localparam BLOCK_W = 11'd40;                    //方块宽度
localparam WHITE  = 24'b11111111_11111111_11111111;  //RGB888 白色
localparam BLACK  = 24'b00000000_00000000_00000000;  //RGB888 黑色
localparam RED    = 24'b11111111_00001100_00000000;  //RGB888 红色
localparam GREEN  = 24'b00000000_11111111_00000000;  //RGB888 绿色
localparam BLUE   = 24'b00000000_00000000_11111111;  //RGB888 蓝色

reg [10 : 0] h_cnt;
reg [9 : 0]  v_cnt;
reg [4 : 0]  vga_r_reg;
reg [5 : 0]  vga_g_reg;
reg [4 : 0]  vga_b_reg;  


reg hsync_r;
reg vsync_r; 
reg vsync_de;
reg hsync_de;

reg [31:0] ddr_data_reg;               //ddr的输入数据存储
reg  cnt_tag;         
reg first_read;

//水平扫描计数
always @(posedge vga_clk)
	if(1'b0)    
		h_cnt <= 1;
	else if(h_cnt == LinePeriod) 
		h_cnt <= 1;
	else 
		h_cnt <= h_cnt+ 1'b1;
		 
//水平扫描信号hsync,hsync_de产生
always @(posedge vga_clk)
begin
	if(1'b0) 
		hsync_r <= 1'b1;
	else if(h_cnt == 1) 
		hsync_r <= 1'b0;	//产生hsync信号
	else if(h_cnt == H_SyncPulse) 
		hsync_r <= 1'b1;
			
	if(1'b0) 
		hsync_de <= 1'b0;
	else if(h_cnt == Hde_start) 
		hsync_de <= 1'b1;	//产生hsync_de信号
	else if(h_cnt == Hde_end) 
		hsync_de <= 1'b0;					 
	
end

//垂直扫描计数
always @(posedge vga_clk)
	if(1'b0) 
		v_cnt <= 1;
	else if(v_cnt == FramePeriod) 
		v_cnt <= 1;
	else if(h_cnt == LinePeriod) 
		v_cnt <= v_cnt + 1'b1;
	

// 垂直扫描信号vsync, vsync_de产生
always @(posedge vga_clk)
begin
	if(1'b0) 
		vsync_r <= 1'b1;
	else if(v_cnt == 1) 
		vsync_r <= 1'b0;    //产生vsync信号
	else if(v_cnt == V_SyncPulse) vsync_r <= 1'b1;

	if(1'b0) 
		vsync_de <= 1'b0;
	else if(v_cnt == Vde_start) 
		vsync_de <= 1'b1;    //产生vsync_de信号
	else if(v_cnt == Vde_end) 
		vsync_de <= 1'b0;	 
end
		 

//提前产生一个ddr读数据 
always @(posedge vga_clk)
begin
   if (~rst_n)
	begin
	    first_read <= 1'b0;
   end
   else 
	begin
       if((h_cnt==Hde_start-1'b1) && (v_cnt==Vde_start-1'b1))
	        first_read <= 1'b1;
		 else
		     first_read <= 1'b0;		   
	 end
end

//ddr读请求信号产生程序, 32bit的DDR数据转成2个像素输出
always @(negedge vga_clk)
begin
	if (~rst_n && ~ddr_init_done) 
	begin
		 ddr_data_reg <= 0;
		 vga_r_reg <= 0;
		 vga_g_reg <= 0;
		 vga_b_reg <= 0;
		 cnt_tag <= 0;
		 ddr_rden <= 0;   
	end
	else 
	begin
		if(first_read==1'b1) 
			ddr_rden <= 1'b1;	//产生第一个数据读信号,让数据准备好     	    
		else if(hsync_de && vsync_de ) 
		begin	//如果vga输出有效的图像数据
			if(cnt_tag==1'b0) 
			begin
				vga_r_reg <= ddr_data_reg[31:27]; 
				vga_g_reg <= ddr_data_reg[26:21];
				vga_b_reg <= ddr_data_reg[20:16];
				ddr_data_reg <= ddr_data_reg;
				ddr_rden <= 1'b1;	//ddr读数据请求 				 
				cnt_tag <= 1'b1;				 
			end	
			else 
			begin	 
				vga_r_reg <= ddr_data_reg[15:11];
				vga_g_reg <= ddr_data_reg[10:5];
				vga_b_reg <= ddr_data_reg[4:0];	
				ddr_data_reg <= ddr_data;	//ddr数据改变							
				ddr_rden <= 1'b0;
				cnt_tag <= 1'b0;
			end
		end		 
		else 
		begin
			vga_r_reg <= 0;                    
			vga_g_reg <= 0;
			vga_b_reg <= 0;
			cnt_tag <= 0;	
			ddr_rden <= 0;
			ddr_data_reg <= ddr_data;	//ddr数据改变
		end
	end
end








reg [15:0]vga_rgb_pixel;

assign vga_hsync = hsync_r;
assign vga_vsync = vsync_r;  


assign vga_frame_sync = vsync_de;
assign vga_valid = hsync_de && vsync_de; 


 
 
parameter BASE_SHOW_R=11'd640;
parameter BASE_SHOW_R_END=11'd640+11'd27;

parameter BASE_SHOW_T=11'd320;
parameter BASE_SHOW_T_END=11'd320+11'd27;

wire [13:0]rom_addr;
reg[9:0]img_idx;
wire [3:0]pic_num;
wire [7:0] rom_data;





wire read_en;
assign read_en=(h_cnt>=BASE_SHOW_R)&&(h_cnt<=BASE_SHOW_R_END)&&(v_cnt>=BASE_SHOW_T)&&(v_cnt<=BASE_SHOW_T_END);

always @(posedge vga_clk or negedge rst_n) begin
    if(!rst_n)
        img_idx<=0;
     else if(img_idx==10'd784)
        img_idx<=0;
    else if(read_en)
        img_idx<=img_idx+1;   
end


assign rom_addr=img_idx+pic_num*784;



// PIC_ROM ROM (
//   .clka(vga_clk),    // input wire clka
//   .addra(rom_addr),  // input wire [13 : 0] addra
//   .douta(rom_data)  // output wire [7 : 0] douta
// );

 ROM u5 ( 
 .doa(rom_data), 
 .addra(rom_addr), 
 .clka(vga_clk), 
 .rsta(~rst_n ));

reg [23:0] pixel_data;
always @(posedge vga_clk or negedge rst_n) begin
    if (!rst_n)
        pixel_data <= 24'd0;
    else if(read_en)
        pixel_data<={rom_data,rom_data,rom_data};

    else begin
        if((h_cnt >= 0) && (h_cnt < (H_ActivePix/5)*1))
            pixel_data <= WHITE;
        else if((h_cnt >= (H_ActivePix/5)*1) && (h_cnt < (H_ActivePix/5)*2))
            pixel_data <= BLACK;  
        else if((h_cnt >= (H_ActivePix/5)*2) && (h_cnt < (H_ActivePix/5)*3))
            pixel_data <= RED;  
        else if((h_cnt >= (H_ActivePix/5)*3) && (h_cnt < (H_ActivePix/5)*4))
            pixel_data <= GREEN;
        else 
            pixel_data <= BLUE;
end
end 
 
 
 
 
 
 
 

 
 
assign vga_r = (hsync_de & vsync_de)?pixel_data[23:19]:5'b0_0000;
assign vga_g = (hsync_de & vsync_de)?pixel_data[15:10]:6'b00_0000;
assign vga_b = (hsync_de & vsync_de)?pixel_data[7:3]:5'b0_0000;
endmodule
