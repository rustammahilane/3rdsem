// program to convert binary to hexadecimal number system
#include <stdio.h>
#include <math.h>
int main()
{
	int bin, dec =0;
	printf("Enter binary: ");
	scanf("%d", &bin);
	int temp = bin;
	int weight = 0;

	while (temp){
		int last_dig = temp % 10;
		dec = dec + last_dig*pow(2, weight++);
		temp = temp / 10;
	}
    char hex[100];
    int i = 0;

    while(dec){
        temp = 0;
        temp = dec%16;
        if(temp < 10)
            hex[i++] = temp + 48;
        else
            hex[i++] = temp + 55;
        dec = dec/16;
    }
    for(int j = i-1; j>= 0; j--)
    printf("%c\n", hex[j]);
	return 0;
}
