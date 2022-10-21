// Subarray with given sum
	// INPUT: N=5, S=12, A[]={1,2,3,7,5}
	// OUTPUT: 2	4
	// CONSTRAINTS: T=On, S=O1
		
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *p, s, n;
	int target = 0;
	printf("Enter size of arr:");
	scanf("%d", &n);
	p = (int*)malloc(n*sizeof(int));
	printf("Enter sum: ");
	scanf("%d", &s);
	
	printf("Enter arr elements: ");
	for(int i = 0; i < n; i++){
		scanf("%d", &p[i]);
	}
	
	// in and out are indices of initial and end position of subarray
	int in = 0, out = 0;
	while (in <= out){
		if(target < s)
			target += p[out++];
		else if(target > s)
			target -= p[in++];
		else if(target == s){
			printf("%d %d", in+1, out);
			break;
		}		
	}
	return 0;
}
