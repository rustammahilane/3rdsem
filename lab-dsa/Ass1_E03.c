// Missing number in array
    // INPUT: N=5, A{1,3,2,5}
    // OUTPUT: 4
    // CONTRAINTS: T= On, S= O1
    
#include <stdio.h>
#include <stdlib.h>
int MissingNumber(int a[], int);
int main()
{
    int n;
    int A[n-1];
    int *p;
    p = (int*)malloc(n*sizeof(int));
    printf("Enter n:");
    scanf("%d", &n);
    printf("Enter elements:");
    for(int i = 0; i < n-1; i++)
    scanf("%d", &A[i]);
    printf("Missing Number: %d", MissingNumber(A, n));
    return 0;
}
int MissingNumber(int a[], int n){
    int sum = 0, sum_n = n;
    for(int i = 0; i < n-1; i++){
        sum += a[i];
        sum_n += i+1;
    }
    return sum_n - sum;
}