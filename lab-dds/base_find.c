//Write a program to find ‘x’ and ‘y’ with respect to (number1)x = (number2)y, where,
// number1 and number2 are the inputs.
// considering bases are less than 10
#include <stdio.h>
#include <math.h>
int main()
{
    int num1, num2;
    printf("Enter num1:");
    scanf("%d", &num1);
    printf("Enter num2:");
    scanf("%d", &num2);

    printf("x  y\n");
    int temp1=num1, temp2=num2;
    for (int i = 1; i < 10; i++){
        for(int j = 1; j <= 10; j++){

            int weight = 0;
            int num1_decimal=0, num2_decimal=0;

            while (temp1){
            int last_dig = temp1 % 10;
            num1_decimal = num1_decimal + last_dig*pow(i, weight++);
            temp1 /= 10;
        }

        weight = 0;
            while (temp2){
                int last_dig = temp2 % 10;
                num2_decimal = num2_decimal + last_dig*pow(j, weight++);
                temp2 /= 10;
            }

        temp1 = num1;
        temp2 = num2;

            if(num1_decimal == num2_decimal)
            printf("%d  %d\n", i, j);
        }
    }
    return 0;
}