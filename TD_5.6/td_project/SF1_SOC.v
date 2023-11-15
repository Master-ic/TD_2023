module SF1_SOC( 

    input wire        I_clk_25m,
    input wire        I_rst_n,

    input wire        I_jtag_tck,
    output wire       O_jtag_tdo,
    input wire        I_jtag_tms,
    input wire        I_jtag_tdi,

    input wire        I_uart_rx,
    output wire       O_uart_tx,

	output wire       O_led0,
    output wire       O_led1,
    output wire       O_led2,

    
    
    
    
//VGA
	 output vga_hsync,
	 output vga_vsync,
	 output [4:0] vga_red,
	 output [5:0] vga_green,
	 output [4:0] vga_blue

);
wire [7:0] O_pwm;
    wire      S_sys_clk_100m;
	wire      S_rst;
    assign S_rst = ~I_rst_n;
    
  wire vga_clk_0;
    pll u_pll(
        .refclk   ( I_clk_25m      ),
        .reset    ( S_rst          ),
        .extlock  (				   ),
        .clk0_out ( S_sys_clk_100m ),
        .clk1_out ( vga_clk_0 )
    );

    wire S_gpio0_out;
    wire S_gpio0_dir;
    wire S_gpio0_in ;
    wire S_gpio1_out;
    wire S_gpio1_dir;
    wire S_gpio1_in ;
    wire S_gpio2_out;
    wire S_gpio2_dir;
    wire S_gpio2_in ;
    
    wire[1:0]  S_ahb_htrans_master;      
    wire       S_ahb_hwrite_master;      
    wire[31:0] S_ahb_haddr_master;       
    wire[2:0]  S_ahb_hsize_master;       
    wire[2:0]  S_ahb_hburst_master;      
    wire[3:0]  S_ahb_hprot_master;       
    wire       S_ahb_hmastlock_master;   
    wire[31:0] S_ahb_hwdata_master;      
    wire[31:0] S_ahb_hrdata_master;      
    wire[1:0]  S_ahb_hresp_master;       
    wire       S_ahb_hready_master;   
    
    
    gpio_controler u0_gpio_controler(
        .O_gpio_in  ( S_gpio0_in  ),
        .I_gpio_dir ( S_gpio0_dir ),
        .I_gpio_out ( S_gpio0_out ),

        .IO_gpio    ( O_led0   )
    );

    gpio_controler u1_gpio_controler(
        .O_gpio_in  ( S_gpio1_in  ),
        .I_gpio_dir ( S_gpio1_dir ),
        .I_gpio_out ( S_gpio1_out ),

        .IO_gpio    ( O_led1   )
    );

    gpio_controler u2_gpio_controler(
        .O_gpio_in  ( S_gpio2_in  ),
        .I_gpio_dir ( S_gpio2_dir ),
        .I_gpio_out ( S_gpio2_out ),

        .IO_gpio    ( O_led2   )
    );

    SF1_MCU u_SF1_MCU(
        .core_clk         ( S_sys_clk_100m ),
		.timer_clk        ( I_clk_25m ), 
        .core_reset       ( S_rst       ),

        .jtag_tck         ( I_jtag_tck  ),
        .jtag_tdo         ( O_jtag_tdo  ),
        .jtag_tms         ( I_jtag_tms  ),
        .jtag_tdi         ( I_jtag_tdi  ),

        .soft_ip_apbm_en  ( 1'b0       ),
        .qspi0cfg1_mode   ( 1'b1       ),
        .qspi0cfg2_mode   ( 1'b1       ),

        .uart_tx          ( O_uart_tx  ),
        .uart_rx          ( I_uart_rx  ),
        
        .gpio0_out        ( S_gpio0_out  ),
        .gpio0_dir        ( S_gpio0_dir  ),
        .gpio0_in         ( S_gpio0_in   ),

        .gpio1_out        ( S_gpio1_out  ),
        .gpio1_dir        ( S_gpio1_dir  ),
        .gpio1_in         ( S_gpio1_in   ),

        .gpio2_out        ( S_gpio2_out  ),
        .gpio2_dir        ( S_gpio2_dir  ),
        .gpio2_in         ( S_gpio2_in   ),

        .htrans           (S_ahb_htrans_master     ),
        .hwrite           (S_ahb_hwrite_master     ),
        .haddr            (S_ahb_haddr_master      ),
        .hsize            (S_ahb_hsize_master      ),
        .hburst           (S_ahb_hburst_master     ),
        .hprot            (S_ahb_hprot_master      ),
        .hmastlock        (S_ahb_hmastlock_master  ),
        .hwdata           (S_ahb_hwdata_master     ),
        .hclk             (S_sys_clk_100m 		   ),
        .hrdata           (S_ahb_hrdata_master     ),
        .hresp            (S_ahb_hresp_master      ),
        .hready           (S_ahb_hready_master     ),

        .nmi              (  ),
        .clic_irq         (  ),
        .sysrstreq        (  ),
        .apb_clk_down     (  ),
        .apb_paddr_down   (  ),
        .apb_penable_down (  ),
        .apb_pprot_down   (  ),
        .apb_prdata_down  (  ),
        .apb_pready_down  (  ),
        .apb_pslverr_down (  ),
        .apb_pstrobe_down (  ),
        .apb_pwdata_down  (  ),
        .apb_pwrite_down  (  ),
        .apb_psel0_down   (  ),
        .apb_psel1_down   (  ),
        .apb_psel2_down   (  )
    );

ahb_pwm u_ahb_pwm(
    .I_ahb_clk      ( S_sys_clk_100m  ),
    .I_rst          ( S_rst  ),
    .I_ahb_htrans   ( S_ahb_htrans_master     ),
    .I_ahb_hwrite   ( S_ahb_hwrite_master     ),
    .I_ahb_haddr    ( S_ahb_haddr_master      ),     
    .I_ahb_hsize    ( S_ahb_hsize_master      ),
    .I_ahb_hburst   ( S_ahb_hburst_master     ),
    .I_ahb_hprot    ( S_ahb_hprot_master      ),
    .I_ahb_hmastlock( S_ahb_hmastlock_master  ),
    .I_ahb_hwdata   ( S_ahb_hwdata_master     ),    
    .O_ahb_hrdata   ( S_ahb_hrdata_master     ),    
    .O_ahb_hresp    ( S_ahb_hresp_master      ),
    .O_ahb_hready   ( S_ahb_hready_master     ),
    .pwmo           ( O_pwm  )
);



//--------------VGA----------------- 
vga_show	vga_show_inst
(
	//global clock
	.vga_clk			   (vga_clk_0),			//vga clock
	.rst_n				(~S_rst),		      //global reset
	
	//vga port
	.vga_hsync			(vga_hsync),		//vga horizontal sync 
	.vga_vsync			(vga_vsync),		//vga vertical sync
	.vga_r			   (vga_red),			//vga red data	
	.vga_g			   (vga_green),		//vga red data		
	.vga_b			   (vga_blue)			//vga red data	
);


endmodule
