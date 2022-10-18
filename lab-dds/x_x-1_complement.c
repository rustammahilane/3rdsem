// Write a program to perform the ‘x’ and ‘x-1’complemention of (number) x.
// considering x <= 10
#include <stdio.h>
#include <string.h>

int main()
{
    char str[10];
    int x;
    printf("Enter num:");
    scanf("%s", &str);
    printf("Enter x: ");
    scanf("%d", &x);

    char eq[] = {'0','1','2','3','4','5','6','7','8','9'};
    char r_1[strlen(str)];

    for(int i = 0; i < strlen(str); i++){
        int temp = str[i] - '0';
        r_1[i] = eq[x-1]-temp;
    }
    printf("%s",r_1);
    return 0;
}