// nice
#include<stdio.h>
#include<math.h>
int decimalTo(int n,int x)
{
    int i,num=0;
    for(i=0;n>=x;n/=x){
        num+=(n%x)*pow(10,i);
        i++;
    }
    num+=(n)*pow(10,i);
    return num;
}
int main()
{
    int num,x,i,n=0,r;
    printf("Enter the number: ");
    scanf("%d",&num);
    printf("Enter the radix(2-10): ");
    scanf("%d",&x);
    for(i=0;num>0;num/=10)
    n+=(num%10)*pow(x,i++);
    r=pow(x,i)-n;
    printf("%d's compliment: %d\n",x,decimalTo(r,x));
    printf("%d's compliment: %d\n",x-1,decimalTo(r-1,x));
}
