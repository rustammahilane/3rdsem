// program to illustrate memory mapping in 2D array using row & col major

#include <stdio.h>

void print_arr(int a[], int length){
	for(int i = 0; i < length; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	int m, n;
	printf("no of row & col:");
	scanf("%d%d", &n,&m);
	int arr[n][m];
	int row_maj[n*m];
	int col_maj[n*m];

	printf("enter elements:");
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);

	int index = 0;
	// row major
	printf("row major: ");
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			row_maj[index++] = arr[i][j];
	print_arr(row_maj, index);
	index  = 0;
	// column major
	printf("col major: ");
	for(int j = 0; j < m; j++)
		for(int i = 0; i < n; i++)
			col_maj[index++] = arr[i][j];
	print_arr(col_maj, index);
	return 0;
}
