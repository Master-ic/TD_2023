//`timescale 1ms / 1ns

//module ahb_pwm(
//    input              I_ahb_clk,
//    input              I_rst,

//    input   [1:0]      I_ahb_htrans,
//    input              I_ahb_hwrite,
//    input   [31:0]     I_ahb_haddr,       //synthesis keep
//    input   [2:0]      I_ahb_hsize,
//    input   [2:0]      I_ahb_hburst,
//    input   [3:0]      I_ahb_hprot,
//    input              I_ahb_hmastlock,
//    input   [31:0]     I_ahb_hwdata,      //synthesis keep
//    output  reg  [31:0] O_ahb_hrdata,      //synthesis keep
//    output  wire[1:0]  O_ahb_hresp,
//    output  reg        O_ahb_hready,
//    output  [7:0]  	   pwmo

//);

//    reg        S_ahb_wr_trig;
//    reg        S_ahb_wr_trig_1d;
//    reg[31:0]  S_ahb_wr_addr;
//    reg[31:0]  S_ahb_wr_data;

//    reg        S_ahb_rd_trig;
//    reg        S_ahb_rd_trig_1d;
//    reg[31:0]  S_ahb_rd_addr;
//    reg[31:0]  S_ahb_rd_data; 
    
    
  
//// Registers
//// reg [31:00] clkdiv;
//// reg [31:00] period0;
//// reg [31:00] period1;
//// reg [31:00] period2;
//// reg [31:00] period3;
//// reg [31:00] period4;
//// reg [31:00] period5;
//// reg [31:00] period6;
//// reg [31:00] period7;
//// reg [31:00] duty0;
//// reg [31:00] duty1;
//// reg [31:00] duty2;
//// reg [31:00] duty3;
//// reg [31:00] duty4;
//// reg [31:00] duty5;
//// reg [31:00] duty6;
//// reg [31:00] duty7;
//reg [7:0]	en;


//reg  [31:0] fc_begin;
//reg signed  [31:0] fc_end;
//reg  [31:0] fc_1;
//reg  [31:0] fc_2;
//reg signed [31:0] fc_3;
//reg signed [31:0] fc_4;
//reg signed [31:0] fc_5;
//reg signed [31:0] fc_6;
//reg signed [31:0] fc_7;
//reg signed [31:0] fc_8;
//reg signed [31:0] fc_9;
//reg signed [31:0] fc_10;
//reg signed [31:0] fc_11;
//reg signed [31:0] fc_12;
//reg signed [31:0] fc_13;
//reg signed [31:0] fc_14;
//reg signed [31:0] fc_15;
//reg signed [31:0] fc_16;

//reg signed [31:0] fc_17;
//reg signed [31:0] fc_18;
//reg signed [31:0] fc_19;
//reg signed [31:0] fc_20;
//reg signed [31:0] fc_21;
//reg signed [31:0] fc_22;
//reg signed [31:0] fc_23;
//reg signed [31:0] fc_24;
//reg signed [31:0] fc_25;
//reg signed [31:0] fc_26;
//reg signed [31:0] fc_27;
//reg signed [31:0] fc_28;
//reg signed [31:0] fc_29;
//reg signed [31:0] fc_30;
//reg signed [31:0] fc_31;
//reg signed [31:0] fc_32;
//reg signed [31:0] fc_33;
//reg signed [31:0] fc_34;
//reg signed [31:0] fc_35;
//reg signed [31:0] fc_36;
//reg signed [31:0] fc_37;
//reg signed [31:0] fc_38;
//reg signed [31:0] fc_39;
//reg signed [31:0] fc_40;
//reg signed [31:0] fc_41;
//reg signed [31:0] fc_42;
//reg signed [31:0] fc_43;
//reg signed [31:0] fc_44;
//reg signed [31:0] fc_45;
//reg signed [31:0] fc_46;
//reg signed [31:0] fc_47;
//reg signed [31:0] fc_48;



//    always @(posedge I_ahb_clk or posedge I_rst) begin
//        if(I_rst)
//            O_ahb_hready <= 1'b1;
//        else
//            if(I_ahb_htrans == 2'b10)
//                O_ahb_hready <= 1'b0;
//            else if(S_ahb_wr_trig_1d || S_ahb_rd_trig_1d)
//                O_ahb_hready <= 1'b1;
//            else
//                O_ahb_hready <= O_ahb_hready;
//    end

    
//    always @(posedge I_ahb_clk or posedge I_rst) begin
//        if(I_rst)
//            S_ahb_wr_trig <= 1'b0;
//        else
//            if(I_ahb_htrans == 2'b10 && I_ahb_hwrite)
//                S_ahb_wr_trig <= 1'b1;
//            else
//                S_ahb_wr_trig <= 1'b0;
//    end

//    always @(posedge I_ahb_clk) begin
//        S_ahb_wr_trig_1d <= S_ahb_wr_trig;
//    end

//    always @(posedge I_ahb_clk or posedge I_rst) begin
//        if(I_rst)
//            S_ahb_wr_addr <= 'd0;
//        else
//            if(S_ahb_wr_trig)
//                S_ahb_wr_addr <= I_ahb_haddr;
//            else
//                S_ahb_wr_addr <= S_ahb_wr_addr;
//    end

//    always @(posedge I_ahb_clk or posedge I_rst) begin
//        if(I_rst)
//            S_ahb_wr_data <= 'd0;
//        else
//            if(S_ahb_wr_trig)
//                S_ahb_wr_data <= I_ahb_hwdata;
//            else
//                S_ahb_wr_data <= S_ahb_wr_data;
//    end


//reg [31:0]no;
//    always @(posedge I_ahb_clk or posedge I_rst) begin
//        if(I_rst)
//            begin
//fc_begin<='d0;
////fc_end<='d0;
//fc_1<='d0;
//fc_2<='d0;
//fc_3<='d0;
//fc_4<='d0;
//fc_5<='d0;
//fc_6<='d0;
//fc_7<='d0;
//fc_8<='d0;
//fc_9<='d0;
//fc_10<='d0;
//fc_11<='d0;
//fc_12<='d0;
//fc_13<='d0;
//fc_14<='d0;
//fc_15<='d0;
//fc_16<='d0;
//fc_17<='d0;
//fc_18<='d0;
//fc_19<='d0;
//fc_20<='d0;
//fc_21<='d0;
//fc_22<='d0;
//fc_23<='d0;
//fc_24<='d0;
//fc_25<='d0;
//fc_26<='d0;
//fc_27<='d0;
//fc_28<='d0;
//fc_29<='d0;
//fc_30<='d0;
//fc_31<='d0;
//fc_32<='d0;
//fc_33<='d0;
//fc_34<='d0;
//fc_35<='d0;
//fc_36<='d0;
//fc_37<='d0;
//fc_38<='d0;
//fc_39<='d0;
//fc_40<='d0;
//fc_41<='d0;
//fc_42<='d0;
//fc_43<='d0;
//fc_44<='d0;
//fc_45<='d0;
//fc_46<='d0;
//fc_47<='d0;
//fc_48<='d0;

//            end
//        else
//            begin
//                if(S_ahb_wr_trig_1d)
//                    begin
//                        case(S_ahb_wr_addr[7:0])
//                            8'd0:  fc_begin   <= S_ahb_wr_data;  
//                            8'd4:  no         <= S_ahb_wr_data;  
//                            8'd8:   fc_1       <= S_ahb_wr_data; 
//                            8'd12:  fc_2      <= S_ahb_wr_data; 
//                            8'd16:  fc_3      <= S_ahb_wr_data; 
//                            8'd20:  fc_4      <= S_ahb_wr_data; 
//                            8'd24:  fc_5      <= S_ahb_wr_data; 
//                            8'd28:  fc_6      <= S_ahb_wr_data; 
//                            8'd32:  fc_7      <= S_ahb_wr_data; 
//                            8'd36:  fc_8      <= S_ahb_wr_data; 
//                            8'd40:  fc_9      <= S_ahb_wr_data; 
//                            8'd44:  fc_10      <= S_ahb_wr_data; 
//                            8'd48:  fc_11      <= S_ahb_wr_data; 
//                            8'd52:  fc_12      <= S_ahb_wr_data; 
//                            8'd56:  fc_13      <= S_ahb_wr_data; 
//                            8'd60:  fc_14      <= S_ahb_wr_data; 
//                            8'd64:  fc_15      <= S_ahb_wr_data; 
//                            8'd68:  fc_16      <= S_ahb_wr_data; 
//                            8'd72:  fc_17      <= S_ahb_wr_data; 
//                            8'd76:  fc_18      <= S_ahb_wr_data; 
//                            8'd80:  fc_19      <= S_ahb_wr_data; 
//                            8'd84:  fc_20      <= S_ahb_wr_data; 
//                            8'd88:  fc_21      <= S_ahb_wr_data; 
//                            8'd92:  fc_22      <= S_ahb_wr_data; 
//                            8'd96:  fc_23      <= S_ahb_wr_data; 
//                            8'd100:  fc_24      <= S_ahb_wr_data; 
//                            8'd104:  fc_25      <= S_ahb_wr_data; 
//                            8'd108:  fc_26      <= S_ahb_wr_data; 
//                            8'd112:  fc_27      <= S_ahb_wr_data; 
//                            8'd116:  fc_28      <= S_ahb_wr_data; 
//                            8'd120:  fc_29      <= S_ahb_wr_data; 
//                            8'd124:  fc_30      <= S_ahb_wr_data; 
//                            8'd128:  fc_31      <= S_ahb_wr_data; 
//                            8'd132:  fc_32      <= S_ahb_wr_data; 
//                            8'd136:  fc_33      <= S_ahb_wr_data; 
//                            8'd140:  fc_34      <= S_ahb_wr_data; 
//                            8'd144:  fc_35      <= S_ahb_wr_data; 
//                            8'd148:  fc_36      <= S_ahb_wr_data; 
//                            8'd152:  fc_37      <= S_ahb_wr_data; 
//                            8'd156:  fc_38      <= S_ahb_wr_data; 
//                            8'd160:  fc_39      <= S_ahb_wr_data; 
//                            8'd164:  fc_40      <= S_ahb_wr_data; 
//                            8'd168:  fc_41      <= S_ahb_wr_data; 
//                            8'd172:  fc_42      <= S_ahb_wr_data; 
//                            8'd176:  fc_43      <= S_ahb_wr_data; 
//                            8'd180:  fc_44      <= S_ahb_wr_data; 
//                            8'd184:  fc_45      <= S_ahb_wr_data; 
//                            8'd188:  fc_46      <= S_ahb_wr_data; 
//                            8'd192:  fc_47      <= S_ahb_wr_data; 
//                            8'd196:  fc_48      <= S_ahb_wr_data; 
//                        endcase
//                    end
//                else
//                    begin
//                        fc_begin<=fc_begin;
//                       no<=fc_end;
//                        fc_1<=fc_1;
//                        fc_2<=fc_2;
//                        fc_3<=fc_3;
//                        fc_4<=fc_4;
//                        fc_5<=fc_5;
//                        fc_6<=fc_6;
//                        fc_7<=fc_7;
//                        fc_8<=fc_8;
//                        fc_9<=fc_9;
//                        fc_10<=fc_10;
//                        fc_11<=fc_11;
//                        fc_12<=fc_12;
//                        fc_13<=fc_13;
//                        fc_14<=fc_14;
//                        fc_15<=fc_15;
//                        fc_16<=fc_16;
//                        fc_17<=fc_17;
//                        fc_18<=fc_18;
//                        fc_19<=fc_19;
//                        fc_20<=fc_20;
//                        fc_21<=fc_21;
//                        fc_22<=fc_22;
//                        fc_23<=fc_23;
//                        fc_24<=fc_24;
//                        fc_25<=fc_25;
//                        fc_26<=fc_26;
//                        fc_27<=fc_27;
//                        fc_28<=fc_28;
//                        fc_29<=fc_29;
//                        fc_30<=fc_30;
//                        fc_31<=fc_31;
//                        fc_32<=fc_32;
//                        fc_33<=fc_33;
//                        fc_34<=fc_34;
//                        fc_35<=fc_35;
//                        fc_36<=fc_36;
//                        fc_37<=fc_37;
//                        fc_38<=fc_38;
//                        fc_39<=fc_39;
//                        fc_40<=fc_40;
//                        fc_41<=fc_41;
//                        fc_42<=fc_42;
//                        fc_43<=fc_43;
//                        fc_44<=fc_44;
//                        fc_45<=fc_45;
//                        fc_46<=fc_46;
//                        fc_47<=fc_47;
//                        fc_48<=fc_48;
//                    end
//            end
//    end



//    always @(posedge I_ahb_clk or posedge I_rst) begin
//        if(I_rst)
//            S_ahb_rd_trig <= 1'b0;
//        else
//            if(I_ahb_htrans == 2'b10 && (!I_ahb_hwrite))
//                S_ahb_rd_trig <= 1'b1;
//            else
//                S_ahb_rd_trig <= 1'b0;
//    end

//    always @(posedge I_ahb_clk) begin
//        S_ahb_rd_trig_1d <= S_ahb_rd_trig;
//    end

//    always @(posedge I_ahb_clk or posedge I_rst) begin
//        if(I_rst)
//            S_ahb_rd_addr <= 'd0;
//        else
//            if(S_ahb_rd_trig)
//                S_ahb_rd_addr <= I_ahb_haddr;
//            else
//                S_ahb_rd_addr <= S_ahb_rd_addr;
//    end


//    always @(posedge I_ahb_clk or posedge I_rst) begin
//        if(I_rst)
//            O_ahb_hrdata <= 'd0;
//        else
//            begin
//                if(S_ahb_rd_trig_1d)
//                    begin
//                        case(S_ahb_rd_addr[7:0])
//                            8'd0:  O_ahb_hrdata<=  weight1      ;  
//                            8'd4:  O_ahb_hrdata<=  fc_end    ;  
//                            8'd8:  O_ahb_hrdata<=fc_1     ;
//                            8'd12:  O_ahb_hrdata<=fc_2    ;
//                            8'd16:  O_ahb_hrdata<=ahb_return_data     ;
//                            8'd20:  O_ahb_hrdata<=weight45     ;
//                            8'd24:  O_ahb_hrdata<=weight44     ;
//                            8'd28:  O_ahb_hrdata<=weight43     ;
//                            8'd32:  O_ahb_hrdata<=weight42     ;
//                            8'd36:  O_ahb_hrdata<=weight41     ;
//                            8'd40:  O_ahb_hrdata<=weight40     ;
//                            8'd44:  O_ahb_hrdata<=weight39    ;
//                            8'd48:  O_ahb_hrdata<=weight38    ;
//                            8'd52:  O_ahb_hrdata<=weight37    ;
//                            8'd56:  O_ahb_hrdata<=weight36    ;
//                            8'd60:  O_ahb_hrdata<=weight35    ;
//                            8'd64:  O_ahb_hrdata<=weight34    ;
//                            8'd68:  O_ahb_hrdata<=weight33    ;
//                            8'd72:  O_ahb_hrdata<=weight32    ;
//                            8'd76:  O_ahb_hrdata<=weight31    ;
//                            8'd80:  O_ahb_hrdata<=weight30    ;
//                            8'd84:  O_ahb_hrdata<=weight29    ;
//                            8'd88:  O_ahb_hrdata<=fc_20    ;
//                            8'd92:  O_ahb_hrdata<=fc_21    ;
//                            8'd96:  O_ahb_hrdata<=fc_22    ;
//                            8'd100: O_ahb_hrdata<=fc_23    ;
//                            8'd104: O_ahb_hrdata<=fc_24    ;
//                            8'd108: O_ahb_hrdata<=fc_26    ;
//                            8'd112: O_ahb_hrdata<=fc_27    ;
//                            8'd116: O_ahb_hrdata<=fc_28    ;
//                            8'd120: O_ahb_hrdata<=fc_29    ;
//                            8'd124: O_ahb_hrdata<=fc_30    ;
//                            8'd128: O_ahb_hrdata<=fc_31    ;
//                            8'd132: O_ahb_hrdata<=fc_32    ;
//                            8'd136: O_ahb_hrdata<=fc_33    ;
//                            8'd140: O_ahb_hrdata<=fc_34    ;
//                            8'd144: O_ahb_hrdata<=fc_35    ;
//                            8'd148: O_ahb_hrdata<=fc_36    ;
//                            8'd152: O_ahb_hrdata<=fc_37    ;
//                            8'd156: O_ahb_hrdata<=fc_38    ;
//                            8'd160: O_ahb_hrdata<=fc_39    ;
//                            8'd164: O_ahb_hrdata<=fc_40    ;
//                            8'd168: O_ahb_hrdata<=fc_41    ;
//                            8'd172: O_ahb_hrdata<=fc_42    ;
//                            8'd176: O_ahb_hrdata<=fc_43    ;
//                            8'd180: O_ahb_hrdata<=fc_44    ;
//                            8'd184: O_ahb_hrdata<=fc_45    ;
//                            8'd188: O_ahb_hrdata<=fc_46    ;
//                            8'd192: O_ahb_hrdata<=fc_47    ;
//                            8'd196: O_ahb_hrdata<=fc_48    ;
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
//                        endcase
//                    end
//                else
//                    O_ahb_hrdata <= O_ahb_hrdata;
//            end
//    end


//wire signed [31:0]ahb_return_data;
//assign ahb_return_data=fc_1*fc_2;
////always @(posedge I_ahb_clk or posedge I_rst) begin
////    if (I_rst) begin
////        fc_end<=0;
////        ahb_return_data<=0;
////end
////    else if (fc_begin==1)begin
////        ahb_return_data<=fc_1+fc_2;
////        fc_end<=1;

////        end
    
////end


    
//wire [383:0]  weight;  
//rom_weight uut(
//   .doa(weight),
//   .addra(4'd0),
//   .clka(I_ahb_clk),
//   .rsta(I_rst));
    
//wire signed  [7:0]weight1; 
//wire signed  [7:0]weight2; 
//wire  signed [7:0]weight3; 
//wire  signed [7:0]weight4; 
//wire  signed [7:0]weight5; 
//wire   signed[7:0]weight6; 
//wire   signed[7:0]weight7; 
//wire   signed[7:0]weight8; 
//wire   signed[7:0]weight9; 
//wire   signed[7:0]weight10; 
//wire signed  [7:0]weight11; 
//wire signed  [7:0]weight12; 
//wire signed  [7:0]weight13; 
//wire signed  [7:0]weight14; 
//wire signed  [7:0]weight15; 
//wire signed  [7:0]weight16; 
//wire signed  [7:0]weight17; 
//wire signed  [7:0]weight18; 
//wire signed  [7:0]weight19; 
//wire signed  [7:0]weight20; 
//wire signed  [7:0]weight21; 
//wire signed  [7:0]weight22; 
//wire signed  [7:0]weight23; 
//wire signed  [7:0]weight24; 
//wire signed  [7:0]weight25; 
//wire signed  [7:0]weight26; 
//wire signed  [7:0]weight27; 
//wire signed  [7:0]weight28; 
//wire signed  [7:0]weight29; 
//wire signed  [7:0]weight30; 
//wire signed  [7:0]weight31; 
//wire signed  [7:0]weight32; 
//wire signed  [7:0]weight33; 
//wire signed  [7:0]weight34; 
//wire signed  [7:0]weight35; 
//wire signed  [7:0]weight36; 
//wire signed  [7:0]weight37; 
//wire signed  [7:0]weight38; 
//wire signed  [7:0]weight39; 
//wire signed [7:0]weight40; 
//wire signed[7:0]weight41; 
//wire signed[7:0]weight42; 
//wire signed[7:0]weight43; 
//wire signed[7:0]weight44; 
//wire signed [7:0]weight45; 
//wire signed [7:0]weight46; 
//wire signed [7:0]weight47; 
//wire signed [7:0]weight48; 

// //assign weight48 = (weight[7] == 1) ? -($unsigned({1'b0, weight[7:0]}) ^ 8'b11111111) - 1 : weight;
    
//assign weight48 =weight[7:0];
//assign weight47 = weight[15:8];
//assign weight46= weight[23:16];
//assign weight45=weight[31:24];
//assign weight44=weight[39:32];
//assign weight43=weight[47:40];
//assign weight42=weight[55:48];
//assign weight41=weight[63:56];
//assign weight40=weight[71:64];
//assign weight39=weight[79:72];
//assign weight38=weight[87:80];
//assign weight37=weight[95:88];
//assign weight36=weight[103:96];
//assign weight35=weight[111:104];
//assign weight34=weight[119:112];
//assign weight33=weight[127:120];
//assign weight32=weight[135:128];
//assign weight31=weight[143:136];
//assign weight30=weight[151:144];
//assign weight29=weight[159:152];
//assign weight28=weight[167:160];
//assign weight27=weight[175:168];
//assign weight26=weight[183:176];
//assign weight25=weight[191:184];
//assign weight24=weight[199:192];
//assign weight23=weight[207:200];
//assign weight22=weight[215:208];
//assign weight21=weight[223:216];
//assign weight20=weight[231:224];
//assign weight19=weight[239:232];
//assign weight18=weight[247:240];
//assign weight17=weight[255:248];
//assign weight16=weight[263:256];
//assign weight15=weight[271:264];
//assign weight14=weight[279:272];
//assign weight13=weight[287:280];
//assign weight12=weight[295:288];
//assign weight11=weight[303:296];
//assign weight10=weight[311:304];
//assign weight9=weight[319:312];
//assign weight8=weight[327:320];
//assign weight7=weight[335:328];
//assign weight6=weight[343:336];
//assign weight5=weight[351:344];
//assign weight4=weight[359:352];
//assign weight3=weight[367:360];
//assign weight2=weight[375:368];
//assign weight1=weight[383:376];



//reg signed[31:0]fc_pipe1;
//always @(posedge I_ahb_clk or posedge I_rst) begin
//    if (I_rst ) 
//    fc_pipe1<=0;
//    else 
//    fc_pipe1<=weight1*fc_1+weight2*fc_2+weight3*fc_3+weight4*fc_4;  
//   end

//reg signed[31:0]fc_pipe2;
//always @(posedge I_ahb_clk or posedge I_rst) begin
//    if (I_rst ) 
//    fc_pipe2<=0;
//    else 
//    fc_pipe2<=weight5*fc_5+weight6*fc_6+weight7*fc_7+weight8*fc_8+fc_pipe1;  
//   end


//reg signed[31:0]fc_pipe3;
//always @(posedge I_ahb_clk or posedge I_rst) begin
//    if (I_rst ) 
//    fc_pipe3<=0;
//    else 
//    fc_pipe3<=weight9*fc_9+weight10*fc_10+weight11*fc_11+weight12*fc_12+fc_pipe2;  
//   end

//reg signed[31:0]fc_pipe4;
//always @(posedge I_ahb_clk or posedge I_rst) begin
//    if (I_rst ) 
//    fc_pipe4<=0;
//    else 
//    fc_pipe4<=weight13*fc_13+weight14*fc_14+weight15*fc_15+weight16*fc_16+fc_pipe3;  
//   end

//reg signed[31:0]fc_pipe5;
//always @(posedge I_ahb_clk or posedge I_rst) begin
//    if (I_rst ) 
//    fc_pipe5<=0;
//    else 
//    fc_pipe5<=weight17*fc_17+weight18*fc_18+weight19*fc_19+weight20*fc_20+fc_pipe4;  
//   end

//reg signed[31:0]fc_pipe6;
//   always @(posedge I_ahb_clk or posedge I_rst) begin
//    if (I_rst ) 
//    fc_pipe6<=0;
//    else 
//    fc_pipe6<=weight21*fc_21+weight22*fc_22+weight23*fc_23+weight24*fc_24+fc_pipe5;  
//   end

//reg signed[31:0]fc_pipe7;
//   always @(posedge I_ahb_clk or posedge I_rst) begin
//    if (I_rst ) 
//    fc_pipe7<=0;
//    else 
//    fc_pipe7<=weight25*fc_25+weight26*fc_26+weight27*fc_27+weight28*fc_28+fc_pipe6;  
//   end

//reg signed[31:0]fc_pipe8;
//   always @(posedge I_ahb_clk or posedge I_rst) begin
//    if (I_rst ) 
//    fc_pipe8<=0;
//    else 
//    fc_pipe8<=weight29*fc_29+weight30*fc_30+weight31*fc_31+weight32*fc_32+fc_pipe7;  
//   end

//reg signed[31:0]fc_pipe9;
//   always @(posedge I_ahb_clk or posedge I_rst) begin
//    if (I_rst ) 
//    fc_pipe9<=0;
//    else 
//    fc_pipe9<=weight33*fc_33+weight34*fc_34+weight35*fc_35+weight36*fc_36+fc_pipe8;  
//   end

//reg signed[31:0]fc_pipe10;
//   always @(posedge I_ahb_clk or posedge I_rst) begin
//    if (I_rst ) 
//    fc_pipe10<=0;
//    else 
//    fc_pipe10<=weight37*fc_37+weight38*fc_38+weight39*fc_39+weight40*fc_40+fc_pipe9;  
//   end

//reg signed[31:0]fc_pipe11;
//   always @(posedge I_ahb_clk or posedge I_rst) begin
//    if (I_rst ) 
//    fc_pipe11<=0;
//    else 
//    fc_pipe11<=weight41*fc_41+weight42*fc_42+weight43*fc_43+weight44*fc_44+fc_pipe10;  
//   end

//reg signed[31:0]fc_pipe12;
//   always @(posedge I_ahb_clk or posedge I_rst) begin
//    if (I_rst ) 
//    fc_pipe12<=0;
//    else 
//    fc_pipe12<=weight45*fc_45+weight46*fc_46+weight47*fc_47+weight48*fc_48+fc_pipe11;  
//   end



//reg signed[31:0]fc_pipe_real;
//   always @(posedge I_ahb_clk or posedge I_rst) begin
//    if (I_rst ) 
//    fc_pipe_real<=0;
//    else 
//    fc_pipe_real<=fc_pipe12;  
//   end

//endmodule



module ahb_pwm(
    input              I_ahb_clk,
    input              I_rst,

    input   [1:0]      I_ahb_htrans,
    input              I_ahb_hwrite,
    input   [31:0]     I_ahb_haddr,       //synthesis keep
    input   [2:0]      I_ahb_hsize,
    input   [2:0]      I_ahb_hburst,
    input   [3:0]      I_ahb_hprot,
    input              I_ahb_hmastlock,
    input   [31:0]     I_ahb_hwdata,      //synthesis keep
    output  reg [31:0] O_ahb_hrdata,      //synthesis keep
    output  wire[1:0]  O_ahb_hresp,
    output  reg        O_ahb_hready,
    output  [7:0]  	   pwmo

);

    reg        S_ahb_wr_trig;
    reg        S_ahb_wr_trig_1d;
    reg[31:0]  S_ahb_wr_addr;
    reg[31:0]  S_ahb_wr_data;

    reg        S_ahb_rd_trig;
    reg        S_ahb_rd_trig_1d;
    reg[31:0]  S_ahb_rd_addr;
    reg[31:0]  S_ahb_rd_data; 
    
// Registers
reg [31:00] clkdiv;
reg [31:00] period0;
reg [31:00] period1;
reg [31:00] period2;
reg [31:00] period3;
reg [31:00] period4;
reg [31:00] period5;
reg [31:00] period6;
reg [31:00] period7;
reg [31:00] duty0;
reg [31:00] duty1;
reg [31:00] duty2;
reg [31:00] duty3;
reg [31:00] duty4;
reg [31:00] duty5;
reg [31:00] duty6;
reg [31:00] duty7;
reg [7:0]	en;

    always @(posedge I_ahb_clk or posedge I_rst) begin
        if(I_rst)
            O_ahb_hready <= 1'b1;
        else
            if(I_ahb_htrans == 2'b10)
                O_ahb_hready <= 1'b0;
            else if(S_ahb_wr_trig_1d || S_ahb_rd_trig_1d)
                O_ahb_hready <= 1'b1;
            else
                O_ahb_hready <= O_ahb_hready;
    end

    always @(posedge I_ahb_clk or posedge I_rst) begin
        if(I_rst)
            S_ahb_wr_trig <= 1'b0;
        else
            if(I_ahb_htrans == 2'b10 && I_ahb_hwrite)
                S_ahb_wr_trig <= 1'b1;
            else
                S_ahb_wr_trig <= 1'b0;
    end

    always @(posedge I_ahb_clk) begin
        S_ahb_wr_trig_1d <= S_ahb_wr_trig;
    end

    always @(posedge I_ahb_clk or posedge I_rst) begin
        if(I_rst)
            S_ahb_wr_addr <= 'd0;
        else
            if(S_ahb_wr_trig)
                S_ahb_wr_addr <= I_ahb_haddr;
            else
                S_ahb_wr_addr <= S_ahb_wr_addr;
    end

    always @(posedge I_ahb_clk or posedge I_rst) begin
        if(I_rst)
            S_ahb_wr_data <= 'd0;
        else
            if(S_ahb_wr_trig)
                S_ahb_wr_data <= I_ahb_hwdata;
            else
                S_ahb_wr_data <= S_ahb_wr_data;
    end
//总线写寄存器
    always @(posedge I_ahb_clk or posedge I_rst) begin
        if(I_rst)
            begin
                en  		<= 'd0;
                clkdiv	<= 'd0;     	
                period0 	<= 'd0;   
                period1  	<= 'd0;   
                period2  	<= 'd0;   
                period3  	<= 'd0;   
                period4  	<= 'd0;
                period5  	<= 'd0;   
                period6  	<= 'd0;   
                period7  	<= 'd0;   
		duty0  	<= 'd0;      	
		duty1  	<= 'd0;      	
		duty2 	<= 'd0;     	
                duty3 	<= 'd0;     	
                duty4 	<= 'd0;     	
                duty5 	<= 'd0;     	
                duty6 	<= 'd0;     	
                duty7 	<= 'd0;     	
            end
        else
            begin
                if(S_ahb_wr_trig_1d)
                    begin
                        case(S_ahb_wr_addr[7:0])
                            8'h00:  en  	       <= S_ahb_wr_data;  
                            8'h04:  clkdiv      <= S_ahb_wr_data;  
                            8'h08:  period0   <= S_ahb_wr_data;  
                            8'h0C:  period1   <= S_ahb_wr_data;  
                            8'h10:  period2   <= S_ahb_wr_data;  
                            8'h14:  period3   <= S_ahb_wr_data;  
                            8'h18:  period4   <= S_ahb_wr_data;  
                            8'h1C:  period5   <= S_ahb_wr_data;  
                            8'h20:  period6   <= S_ahb_wr_data;  
                            8'h24:  period7   <= S_ahb_wr_data;  
                            8'h28:  duty0  	<= S_ahb_wr_data;  
                            8'h2C:  duty1  	<= S_ahb_wr_data;  
                            8'h30:  duty2 	<= S_ahb_wr_data;  
                            8'h34:  duty3 	<= S_ahb_wr_data;  
                            8'h38:  duty4 	<= S_ahb_wr_data;  
                            8'h3c:  duty5 	<= S_ahb_wr_data;
                            8'h40:  duty6 	<= S_ahb_wr_data; 
                            8'h44:  duty7 	<= S_ahb_wr_data;
                        endcase
                    end
                else
                    begin
                        en  	 <= en  	;
                        clkdiv   <= clkdiv  ;
                        period0  <= period0 ;
                        period1  <= period1 ;
                        period2  <= period2 ;
                        period3  <= period3 ;
                        period4  <= period4 ;
                        period5  <= period5 ;
                        period6  <= period6 ;
                        period7  <= period7 ;
                        duty0  	 <= duty0  	;
                        duty1  	 <= duty1  	;
                        duty2 	 <= duty2 	;
                        duty3 	 <= duty3 	;
                        duty4 	 <= duty4 	;
                        duty5 	 <= duty5 	;
                        duty6 	 <= duty6 	;
                        duty7 	 <= duty7 	;
                    end
            end
    end

    always @(posedge I_ahb_clk or posedge I_rst) begin
        if(I_rst)
            S_ahb_rd_trig <= 1'b0;
        else
            if(I_ahb_htrans == 2'b10 && (!I_ahb_hwrite))
                S_ahb_rd_trig <= 1'b1;
            else
                S_ahb_rd_trig <= 1'b0;
    end

    always @(posedge I_ahb_clk) begin
        S_ahb_rd_trig_1d <= S_ahb_rd_trig;
    end

    always @(posedge I_ahb_clk or posedge I_rst) begin
        if(I_rst)
            S_ahb_rd_addr <= 'd0;
        else
            if(S_ahb_rd_trig)
                S_ahb_rd_addr <= I_ahb_haddr;
            else
                S_ahb_rd_addr <= S_ahb_rd_addr;
    end
//总线读寄存器
    always @(posedge I_ahb_clk or posedge I_rst) begin
        if(I_rst)
            O_ahb_hrdata <= 'd0;
        else
            begin
                if(S_ahb_rd_trig_1d)
                    begin
                        case(S_ahb_rd_addr[7:0])
                            8'h00: O_ahb_hrdata  <=en  	    ;
                            8'h04: O_ahb_hrdata  <=clkdiv   ;
                            8'h08: O_ahb_hrdata  <=period0  ;
                            8'h0C: O_ahb_hrdata  <=weight  ;
                            8'h10: O_ahb_hrdata  <=c  ;
                            8'h14: O_ahb_hrdata  <=period3  ;
                            8'h18: O_ahb_hrdata  <=period4  ;
                            8'h1C: O_ahb_hrdata  <=period5  ;
                            8'h20: O_ahb_hrdata  <=period6  ;
                            8'h24: O_ahb_hrdata  <=period7  ;
                            8'h28: O_ahb_hrdata  <=duty0    ;  
                            8'h2C: O_ahb_hrdata  <=duty1    ;  
                            8'h30: O_ahb_hrdata  <=duty2    ;  
                            8'h34: O_ahb_hrdata  <=duty3    ;  
                            8'h38: O_ahb_hrdata  <=duty4    ;  
                            8'h3c: O_ahb_hrdata  <=duty5    ;
                            8'h40: O_ahb_hrdata  <=duty6    ;
                            8'h44: O_ahb_hrdata  <=duty7    ; 
                        endcase
                    end
                else
                    O_ahb_hrdata <= O_ahb_hrdata;
            end
    end


wire [7:0]  weight;  
rom_weight uut(
   .doa(weight),
   .addra(period1),
   .clka(I_ahb_clk),
   .rsta(I_rst));



wire signed[31:0]a;
wire signed[7:0]b;
wire signed[31:0]c;
assign a=period0;
assign b=weight;
assign c=a*b;
endmodule