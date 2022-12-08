// mergesort
#include <stdio.h>

void merge(int a[], int low, int mid, int high){
    int n = high-low+1;
    int b[n];
    int left=low, right=mid+1, bIdx=0;
    while (left <= mid && right <= high) {
        if (a[left] <= a[right]) b[bIdx++] = a[left++];
        else b[bIdx++] = a[right++];
    }
    while (left <= mid) b[bIdx++] = a[left++];
    while (right <= high) b[bIdx++] = a[right++];
    for(int k = 0; k < n; k++)
    a[low+k] = b[k];
}

void mergesort(int a[], int low, int high){
    if(low < high){
        int mid = (high + low) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int size;
    printf("Enter size:");
    scanf("%d", &size);

    int a[size];
    printf("Enter elements:");
    for(int i = 0; i < size; i++)
        scanf(" %d", &a[i]);

    mergesort(a, 0, size - 1);
    printf("Sorted elements:");
    for (int i = 0; i < size; i++){
        printf("%d ", a[i]);
    }
    return 0;
}