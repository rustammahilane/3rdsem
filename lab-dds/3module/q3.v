module question3 (
    input a,b,c,
    output na,nb,nc, w,x,y
);
assign na = ~a;
assign nb = ~b;
assign nc = ~c;
// 1 below repesents fixed carry
assign w = (~a&(~1)) | (~a&c) | (~a&b) | (a&(~b)&(~c)&1);
assign x = ((~b)&(~1)) | ((~b)&c) | (b&(~c)&1);
assign y = ((~c)&(~1)) | (c&1);
endmodule

//testbench code
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