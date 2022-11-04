// to illustrate memory allocation in upper and lower triangular matrix
#include <stdio.h>
int is_upper = 1, is_lower = 1;
void upper(int r, int c, int arr[][c]){
    printf("upper triangular matrix\n");
    int max = (r < c) ? c : r;
    int nonzeroes = max * (max + 1) / 2;
    int row_maj[nonzeroes], col_maj[nonzeroes];
    int k=0;
    // for row major
    for(int i = 0; i < r; i++){
        for(int j = i; j < c; j++){
            row_maj[k++] = arr[i][j];
        }
    }
    // for column major
    // assigning of elements is done from last to first element from 2d matrix
    for(int i = c-1; i >= 0; i--){
        for(int j = r +(i-c); j >= 0; j--)
            col_maj[--k] = arr[j][i];
    }
    printf("row major: ");
    for(int i = 0; i < nonzeroes; i++)
        printf("%d ",row_maj[i]);
    printf("\ncolumn major: ");
    for(int i = 0; i < nonzeroes; i++)
        printf("%d ",col_maj[i]);
}
void lower(int r, int c, int arr[][c]){
    printf("lower triangular matrix\n");
    int max = (r < c) ? c : r;
    int nonzeroes = max * (max + 1) / 2;
    int row_maj[nonzeroes], col_maj[nonzeroes];
    int k=0;
    // for column major
    for(int i = 0; i < c; i++){
        for(int j = i; j < r; j++){
            col_maj[k++] = arr[j][i];
        }
    }
    // for row major
    // assigning of elements is done from last to first element from 2d matrix
    for(int i = c-1; i >= 0; i--){
        for(int j = r +(i-c); j >= 0; j--)
            row_maj[--k] = arr[i][j];
    }
    printf("row major: ");
    for(int i = 0; i < nonzeroes; i++)
        printf("%d ",row_maj[i]);
    printf("\ncolumn major: ");
    for(int i = 0; i < nonzeroes; i++)
        printf("%d ",col_maj[i]);
}
void  is_upperlower(int r, int c, int arr[][c]){
    for(int i = 0; i < r; i++)
        for(int j = i; j < c; j++){
            if(i < j){
                if(arr[i][j] != 0)
                    is_lower = 0;
                if(arr[j][i] != 0)
                    is_upper = 0;
            }
        }
}
int main()
{
    int row, col;
    printf("Enter no of row and col:");
    scanf("%d%d", &row, &col);
    int arr[row][col];
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            scanf("%d", &arr[i][j]);

    // check for upper or lower matrix
    is_upperlower(row, col, arr);

    if(is_upper == 1 && is_lower == 1)
        printf("Null matrix!");
    else if(is_upper == 0 && is_lower == 0)
        printf("Not upper or lower triangular matrix!");
    else if(is_lower == 1)
        lower(row, col, arr);
    else if(is_upper == 1)
        upper(row, col, arr);
}