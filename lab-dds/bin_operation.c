// program to perfor arithmetic operation on binary numbers

#include <stdio.h>
#include <math.h>

int bin_to_dec(int binary){
    int weight = 0, decimal = 0;
    while(binary){
        decimal += (binary%10) *pow(2, (weight++));
        binary /= 10;
    }
    return decimal;
}

int dec_to_bin(int decimal){
    int binary = 0, weight = 0;
    while(decimal){
        binary += (decimal%2) * pow(10, weight++);
        decimal /= 2;
    }
    return binary;
}

int main()
{
    int bin1, bin2;
    scanf("%d", &bin1);
    scanf("%d", &bin2);

    int sum = bin_to_dec(bin1) + bin_to_dec(bin2);
    int diff = bin_to_dec(bin1) - bin_to_dec(bin2);
    int multi = bin_to_dec(bin1) * bin_to_dec(bin2);
    int div = bin_to_dec(bin1) / bin_to_dec(bin2);
    
    printf("Sum: %d\n", dec_to_bin(sum));
    printf("Difference: %d\n", dec_to_bin(diff));
    printf("Multiplication: %d\n", dec_to_bin(multi));
    printf("Division: %d\n", dec_to_bin(div));
    
}