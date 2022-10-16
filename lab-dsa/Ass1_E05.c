// Leaders in an array
    // INPUT: N = 6, A[] = {16,17,4,5,3,2}
    // OUTPUT: 17 5 2

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

    // int lead[] = leaders(n,p);
    for(int i = 0; i < n; i++)
    printf("%d\n", *(leaders(n,p)+i));
    return 0;
}

int* leaders(int size, int A[size]){
    int *ptr;
    ptr = (int*)calloc(size,sizeof(int));

    int right_sum=0;
    for(int i = size-1; i >= 0; i--){
        if(right_sum <= A[i])
        ptr[i] = A[i];
        right_sum += A[i];
    }

    for(int i = 0; i < size; i++){
        if(ptr == 0){
            ptr[i] = ptr[i+1];

        }
        else
            break;
    }
    return ptr;
}