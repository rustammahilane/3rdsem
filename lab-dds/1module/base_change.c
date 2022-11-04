// program to convert a given number to another base
// NOTE : FOR BASE <= 10
#include <stdio.h>
#include <math.h>
int to_base(int old_num,int old_base, int new_base){
    int new_num = 0, weight = 0;
    while(old_num){
        new_num = (old_num % new_base) * pow(old_base, weight++);
        old_num /= new_base;
    }
    return new_num;
}

int main()
{
    printf("%d", to_base(100, 2, 10));
    return 0;
}