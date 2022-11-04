// program to convert binary to decimal number system

#include <stdio.h>
#include <math.h>
int main()
{
	int bin, dec =0;
	printf("Enter binary: ");
	scanf("%d", &bin);
	int temp = bin;
	int weight = 0;
	
	// temp stores value of bin
	while (temp){
		int last_dig = temp % 10;
		dec = dec + last_dig*pow(2, weight++);
		temp = temp / 10;
	}
	printf("dec: %d\n", dec);
	return 0;
}
