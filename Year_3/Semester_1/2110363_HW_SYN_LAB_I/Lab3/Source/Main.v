`timescale 1ns / 1ps

module Main (
    input wire [3:0] up, down,
    input wire set, reset,
    input wire clock,
    output wire [3:0] An,
    output wire [6:0] C_LED
    );
    wire [3:0] up_imp, down_imp; // output after input buffer 
    wire [3:0] add_signal, sub_signal; // can be add ?
    wire set_imp, reset_imp; // output after input buffer

    wire cout[3:0], bout[3:0];
    wire [3:0] A,B,C,D;


    InputBuffer i0(up[0], clock, up_imp[0]);
    InputBuffer i1(up[1], clock, up_imp[1]);
    InputBuffer i2(up[2], clock, up_imp[2]);
    InputBuffer i3(up[3], clock, up_imp[3]);
    
    InputBuffer i4(down[0], clock, down_imp[0]);
    InputBuffer i5(down[1], clock, down_imp[1]);
    InputBuffer i6(down[2], clock, down_imp[2]);
    InputBuffer i7(down[3], clock, down_imp[3]);

    InputBuffer i8(set, clock, set_imp);
    InputBuffer i9(reset, clock, reset_imp);

    assign add_signal[0] = ({D,C,B,A} != 16'h9999 && up_imp[0]);
    assign add_signal[1] = ({D,C,B} != 12'h999 && (up_imp[1] || cout[0] ));
    assign add_signal[2] = ({D,C} != 8'h99 && (up_imp[2] || cout[1] )); 
    assign add_signal[3] = ({D} != 4'h9 && (up_imp[3] || cout[2] )); 


    assign sub_signal[0] = ({D,C,B,A} != 16'h0 && down_imp[0]); 
    assign sub_signal[1] = ({D,C,B} != 12'h0 && (down_imp[1] || bout[0])); 
    assign sub_signal[2] = ({D,C} != 8'h0 && (down_imp[2] || bout[1]));
    assign sub_signal[3] = ({D} != 4'h0 && (down_imp[3] || bout[2])); 

    BCD u0(add_signal[0], sub_signal[0], set_imp, reset_imp, clock, A, cout[0], bout[0]);
    BCD u1(add_signal[1], sub_signal[1], set_imp, reset_imp, clock, B, cout[1], bout[1]);
    BCD u2(add_signal[2], sub_signal[2], set_imp, reset_imp, clock, C, cout[2], bout[2]);
    BCD u3(add_signal[3], sub_signal[3], set_imp, reset_imp, clock, D, cout[3], bout[3]);
    SevenSegment sg(A, B, C, D, clock, C_LED, An);
    
endmodule