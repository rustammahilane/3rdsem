// program to convert binary to octal number system

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
		dec = dec + last_dig*pow(2, weight);
		weight++;
		temp = temp / 10;
	}

    int oct=0;
    int t =1;
    while(dec!=0){
        oct = oct + (dec%8)*t;
        t = t*10;
        dec = dec/8;
    }
	printf("oct: %d\n", oct);
	return 0;
}
