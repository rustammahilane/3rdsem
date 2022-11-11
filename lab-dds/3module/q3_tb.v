`include "q3.v"
module q3_tb;
reg a,b,c;
wire w,x,y;

question3 test(a,b,c,na,nb,nc,w,x,y);
initial begin
    $monitor("input: %b%b%b    1's: %b%b%b    2's: %b%b%b",
        a,b,c,na,nb,nc,w,x,y);
    $dumpfile("q3_tb.vcd");
    $dumpvars();
    a = 0; b = 0; c = 0; #5;
    a = 0; b = 0; c = 1; #5;
    a = 0; b = 1; c = 0; #5;
    a = 0; b = 1; c = 1; #5;

    a = 1; b = 0; c = 0; #5;
    a = 1; b = 0; c = 1; #5;
    a = 1; b = 1; c = 0; #5;
    a = 1; b = 1; c = 1; #5;
    $finish;
end
endmodule

