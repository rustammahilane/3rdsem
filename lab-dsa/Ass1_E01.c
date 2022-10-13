// Example 1
	// INPUT: N=5, S=12, A[]={1,2,3,7,5}
	// OUTPUT: 2	4
	// CONSTRAINTS: T=On, S=On
		
#include <stdio.h>
#define max 20
int main()
{
	int arr[max], s, size;
	int target = 0;
	printf("Enter size of arr:");
	scanf("%d", &size);
	printf("Enter sum: ");
	scanf("%d", &s);
	
	printf("Enter arr elements: ");
	for(int i = 0; i < size; i++){
		scanf("%d", &arr[i]);
	}
	
	int in = 0, out = 0;
	while (in <= out){
		if(target < s)
			target += arr[out++];
		else if(target > s)
			target -= arr[in++];
		else if(target == s){
			printf("\n%d	%d", in+1, out);
			break;
		}		
	}
	return 0;
}
