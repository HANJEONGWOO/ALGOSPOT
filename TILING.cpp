#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int C;
int N;

int cache[110];

int result = 0;

int tiling(int n);

int main(void)
{

	scanf("%d", &C);

	while (C--)
	{
		memset(cache, -1, 110 * sizeof(int)); //init value;

		scanf("%d", &N);

		result = tiling(N);

		printf("%d\n", result); //print result value;
	}

	return 0;
}

int tiling(int n)
{
	int &ret = cache[n];

	//1. 기저사례
	if (n <= 1)
		return ret = 1;

	//2. 이미 계산하였는지 확인

	if (ret != -1)
		return cache[n];
	else
		return ret = (tiling(n - 1) + tiling(n - 2)) % MOD;
}