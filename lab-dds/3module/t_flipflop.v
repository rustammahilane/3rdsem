module flipflop(
    input clk, t,
    output reg q
);
initial begin
    q<= 0;
end
always@(posedge clk)
case({t})
    1'b0 : q<=q;
    1'b1 : q<= ~q;
endcase
endmodule

//testbench
module testbench;
reg t=0; 
reg clk=0;
wire q;
flipflop uut(clk,t,q);
always begin
    t = ~t; #10;
    clk = ~clk; #5;
end

initial begin
    $dumpfile("tff.vcd");
    $dumpvars(0,testbench);
    $monitor("T:%b Q:%b",t, q);
    #100;
    $finish;
end
endmodule