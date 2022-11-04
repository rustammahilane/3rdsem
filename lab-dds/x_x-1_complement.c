#include<stdio.h>
#include<math.h>
// function that converts given decimal number to its base x equivalent
int decimal_to_x(int dec_num,int base_x){
    int x_num = 0, weight = 0;
    while(dec_num){
        x_num += (dec_num % base_x) * pow(10, weight++);
        dec_num /= base_x;
    }
    return x_num;
}
// function that provides largest digit in the number
int max_digit(int num){
    int max = 0;
    while(num){
        int digit = num % 10;
        if(digit > max)
            max = digit;
            num /= 10;
    }
    return max;
}
int main()
{
    int num,x;
    int N=0,r_compliment = 0;
    printf("Enter the number: ");
    scanf("%d",&num);
    printf("Enter the radix(%d-10): ", max_digit(num) + 1);
    scanf("%d",&x);

    int i;
    for(i = 0; num > 0; num /= 10)
    N += (num%10)*pow(x,i++);
    r_compliment=pow(x,i)-N;
  
    printf("%d's compliment: %d\n",x,decimal_to_x(r_compliment,x));
    printf("%d's compliment: %d\n",x-1,decimal_to_x(r_compliment - 1,x));
}
