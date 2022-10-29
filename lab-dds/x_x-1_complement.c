// nice
#include<stdio.h>
#include<math.h>
int to_decimal(int old_num,int base){
    int new_num = 0, weight = 0;
    while(old_num){
        new_num = (old_num % 10) * pow(base, weight++);
        old_num /= 10;
    }
    return new_num;
}
int max_digit(int num){
    int max = 0;
    while(num){
        int digit = num % 10;
        if(digit > max)
            max = digit;
    }
    return max;
}
int main()
{
    int num,x,i,n=0,r;
    printf("Enter the number: ");
    scanf("%d",&num);
    printf("Enter the radix(%d-10): ", max_digit(num) + 1);
    scanf("%d",&x);
    for(i=0;num>0;num/=10)
    n+=(num%10)*pow(x,i++);
    r=pow(x,i)-n;
    printf("%d's compliment: %d\n",x,to_decimal(r,x));
    printf("%d's compliment: %d\n",x-1,to_decimal(r-1,x));
}
