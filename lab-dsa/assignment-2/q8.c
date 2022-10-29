// select r from n

#include <stdio.h>
int fact(int N){
	if(N == 1)
		return 1;
	else
		return fact(N-1)*N;
}
int nCr(int N, int R){
	return fact(N) / (fact(R) * fact(N-R));
}
int main()
{
	int n,r;
	scanf("%d%d", &n, &r);
	printf("%d", nCr(n,r));
	return 0;
}
