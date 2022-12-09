// To search a key in an array using BINARY SEARCH
#include<stdio.h>
#define max 50
int b_search(int a[], int target, int low, int high){
    if(low <= high){
        int mid = (low + high) / 2;
        if(a[mid] == target)
            return mid;
        else if(a[mid] > target)
           return b_search(a,target, mid + 1, high);
        else if(a[mid] < target)
        return   b_search(a, target, low, mid-1);
    }
    else
    return -1;
}

int main()
{
    int arr[max], size, target;
    printf("Enter size of array:");
    scanf("%d",&size);
    printf("Enter elements in ascending order\n");
    for(int i = 0; i < size; i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter search element:");
    scanf("%d",&target);
    int pos = b_search(arr, target, 0, size-1);
    printf("found : %d", pos);
}