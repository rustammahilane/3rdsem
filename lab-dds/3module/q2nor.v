module nor_to_other(
    output a_not,b_not,ab_or,ab_and,ab_nor,ab_nand,
    input a,b
);
nor(b_not,b,b);
nor(a_not,a,a);
nor(ab_nor,a,b);
nor(ab_and,a_not,b_not);
nor(ab_or, ab_nor,ab_nor);
nor(ab_nand,ab_and,ab_and);
endmodule
