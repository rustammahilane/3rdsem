// program for memory mapping in 2D symmetric array into 1D array
#include <stdio.h>
#include <stdlib.h>
void print_arr(int n, int arr[]);
int is_symmetric(int N, int* ptr[N]);
void symmetric(int N, int* ptr[N]);
int main()
{
    int n;
    printf("Enter order of matrix:");
    scanf("%d", &n);
    int *p[n];
    for (int i = 0; i < n; i++)
        p[i] = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            scanf("%d", *(p+i) + j);
        }

    if(is_symmetric(n, p) == 0)
        printf("Not a symmetric matrix!");
    else
        symmetric(n, p);

    return  0;
}
// checks for a 2D array whether symmetrical
int is_symmetric(int N, int* ptr[N]){
    int symmetry = 1;
    for(int i = 0; i < N; i++)
        for(int j = i; j < N; j++){
            if( *(*(ptr+i)+j) != *(*(ptr+j)+i) )
                symmetry = 0;
        }
    return symmetry;
}
void symmetric(int N, int* ptr[N]){
    int no_of_elements = N * (N + 1) / 2;
    int row_maj[no_of_elements], col_maj[no_of_elements];

    int k = 0;
    for(int i = 0; i < N; i++)
        for(int j = i; j < N; j++){
            row_maj[k++] = *(*(ptr + i) + j);
        }
    for(int i = N - 1; i >= 0; i--)
        for(int j = N - 1; j >= i; j--)
            col_maj[--k] = *(*(ptr + i) + j);

    printf("row major:");
    print_arr(no_of_elements, row_maj);
    printf("\ncol major:");
    print_arr(no_of_elements, col_maj);

}
void print_arr(int n, int arr[]){
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}