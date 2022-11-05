
module or_tb;
        reg a,b;
        wire y;

or_ test(a,b,y);
initial
        begin
        $monitor("%b%b %b", a,b,y);
        $dumpfile("ortest.vcd");
        $dumpvars();
        a = 0; b = 0; #5;
        a = 0; b = 1; #5;
        a = 1; b = 0; #5;
        a = 1; b = 1; #5;
        end
endmodule
