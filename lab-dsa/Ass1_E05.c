// Leaders in an array
    // INPUT: N = 6, A[] = {16,17,4,5,3,2}
    // OUTPUT: 17 5 3 2
    // CONSTRAINTS: T = On, aS = On

#include <stdio.h>
#include <stdlib.h>
int k;
int* leaders(int, int a[]);
int main()
{
    int n, *p;
    
    printf("Enter n: ");
    scanf("%d", &n);
    p = (int*)malloc(n*sizeof(int));
    printf("Enter elements:");
    for(int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    int *t = leaders(n,p);
    for(int i = k-1; i >= 0; i--)
        printf("%d ", *(t+i));
    return 0;
}

int* leaders(int size, int A[size]){
    int *ptr;
    ptr = (int*)calloc(size,sizeof(int));

    //  right_sum is sum of elements to the right
    //  k is globally declared
    int right_sum=0;
    for(int i = size-1; i >= 0; i--){
        if(right_sum <= A[i])
        ptr[k++] = A[i];
        right_sum += A[i];
    }
    return ptr;
}