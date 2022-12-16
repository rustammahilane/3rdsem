// insertion sort
#include <stdio.h>
void insertion_sort(int , int a[]);
int main()
{
    int size;
    printf("Enter size:");
    scanf("%d", &size);
    int A[size];
    printf("Enter elements:");
    for(int i = 0; i < size; i++)
        scanf("%d", &A[i]);
    printf("Sorted array:");
    insertion_sort(size, A);
    for(int i = 0; i < size; i++)
        printf("%d ", A[i]);
    
}
void insertion_sort(int n, int A[n]){
     for(int i = 1; i < n; i++){
        int next = A[i], j;
        for(j = i - 1; j >= 0 && A[j] > next; j--)
            A[j+1] = A[j];
        A[j+1] = next;
    }
}