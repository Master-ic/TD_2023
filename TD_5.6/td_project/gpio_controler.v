module gpio_controler (
    output wire   O_gpio_in,
    input wire    I_gpio_dir,  ///1'b0: input , 1'b1: output
    input wire    I_gpio_out,

    inout wire    IO_gpio
);


    assign IO_gpio = I_gpio_dir ? I_gpio_out : 1'bz;

    assign O_gpio_in = IO_gpio;
    
endmodule