// program for memory allocation of tridiagonal matrix
#include <stdio.h>
void print_arr(int n, int arr[]);
void diagonal_major(int n, int arr[][n]);
void row_major(int n, int arr[][n]);
void col_major(int n, int arr[][n]);
int is_tridiagonal(int n, int arr[][n]);
int main() {
    int n;
    printf("Enter order of matrix:");
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);

    if(is_tridiagonal(n, arr) == 0)
        printf("Not a tridiagonal matrix!");
    else{
        printf("%16s","diagonal major: ");
        diagonal_major(n, arr);
        printf("\n%16s","row major: ");
        row_major(n, arr);
        printf("\n%16s","column major: ");
        col_major(n, arr);
    }
    return 0;
}
void print_arr(int n, int arr[]){
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
void diagonal_major(int n, int arr[][n]) {
    int diag_maj[(3 * n) - 2];
    int k = 0;
    for (int j = 0; j < n-1; j++)
        diag_maj[k++] = arr[j+1][j];
    for (int j = 0; j < n; j++)
        diag_maj[k++] = arr[j][j];
    for (int j = 1; j < n; j++)
        diag_maj[k++] = arr[j-1][j];

    print_arr((3*n)-2, diag_maj);
}
void row_major(int n, int arr[][n]){
    int row_maj[(3*n)-2];
    int k = 0;
    for(int i = 0; i < n; i++)
        for(int j = i - 1; j <= i+1; j++){
            if(j<0 || j > n)
                continue;
            else
                row_maj[k++] = arr[i][j];
        }
    print_arr((3*n)-2, row_maj);
}
void col_major(int n, int arr[][n]){
    int col_maj[(3*n)-2];
    int k = 0;
    for(int i = 0; i < n; i++)
        for(int j = i - 1; j <= i+1; j++){
            if(j<0 || j > n)
                continue;
            else
                col_maj[k++] = arr[j][i];
        }
    print_arr((3*n)-2, col_maj);
}
int is_tridiagonal(int n, int arr[][n]){
    int true = 1;
    for(int i = 0; i < n; i++)
        for(int j = i+2; j < n; j++){
            if(arr[j][i] != 0)
                true = 0;
            if(arr[i][j] != 0)
                true = 0;
        }
    return true;
}