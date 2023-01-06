module flipflop(
    input clk, d,
    output reg q
);
always@(posedge clk)
begin
        q = d;
end
endmodule

//testbench
`timescale 1ns/1ns
module testbench;
reg d = 0; 
reg clk = 0;
wire q;
flipflop uut(clk,d,q);
always begin
    clk = ~clk; #10;
end
initial begin
    $dumpfile("dff.vcd");
    $dumpvars(0,testbench);
    $monitor("D:%b Q:%b",d, q);
    d = 1; #40;
    d = 0; #40;
    $finish;
end
endmodule