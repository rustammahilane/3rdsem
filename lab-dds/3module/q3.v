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
