// Example 1

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

	int count = 0;
	for(int i = 0; i < size; i++){
		target += arr[i];
		
		if (target == s){
			printf("%d	%d", i-count, i);
			break;
		}
		else if (target > s){
			target -= arr[count];
			count++;
		}
	}			
	return 0;
}	
