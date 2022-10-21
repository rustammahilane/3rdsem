// Missing number in array
    // INPUT: N=5, A{1,3,2,5}
    // OUTPUT: 4
    // CONTRAINTS: T= On, S= O1

#include <stdio.h>
#include <stdlib.h>
int MissingNumber(int , int a[]);
int main()
{
    int n;
    int *p;
    printf("Enter n:");
    scanf("%d", &n);
    p = (int*)malloc((n-1)*sizeof(int));
    printf("Enter elements:");
    for(int i = 0; i < n-1; i++)
    scanf("%d", &p[i]);
    int m = MissingNumber(n,p);
    printf("Missing Number: %d\n", m);
    return 0;
}
int MissingNumber(int n, int a[n-1]){
    int sum = 0, sum_n = n*(n+1)/2;
    for(int i = 0; i < n-1; i++)
        sum += a[i];
    return (sum_n - sum);
}