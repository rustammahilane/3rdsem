#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int a;
    printf("enter a digit( ""2,4,2,1"" system):");
    scanf("%d",&a);
    char *b[50];
    b[0] = "0000";
    b[1] = "0001";
    b[2] = "0010";
    b[9] = "1111";
    b[3] = "0011";
    b[4] = "0100";
    b[5] = "1011";
    b[6] = "1100";
    b[7] = "1101";
    b[8] = "1110";
    b[9] = "1111";

    char c[50];
    int d[4] = {2, 4, 2, 1};
    strcpy(c, b[a]);
    for(int i = 0; i  <4; i++){
        if (c[i]=='1')
            c[i]='0';
        else
            c[i] = '1';
    }
    printf("%d = %s\n", a, b[a]);
    int ans = 0;
    for(int i = 0; i  <4; i++){
        if (c[i]=='1')
            ans+= d[i];
    }
    printf("%d's complement is %d = %s\n", a, ans, c);
    printf("hence it is self complimenting\n");
    return 0;
}