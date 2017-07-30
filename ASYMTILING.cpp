#include <stdio.h>

#define MOD 1000000007

int C;
int N;

int tiling_cache[110];
int result;

int tiling(int n);
int asymmetric(int width);

int main(void)
{
	scanf("%d", &C); //input C

	for (int i = 0; i < 110; i++) {
		tiling_cache[i] = -1;
	}

	while (C--)
	{
		scanf("%d", &N); //input N

		result = asymmetric(N);

		printf("%d\n", result);
	}

	return 0;
}

int tiling(int n)
{
	//기저 사례
	if (n <= 1)
		return 1;

	//메모이제이션
	int &ret = tiling_cache[n];
	if (ret != -1)
		return ret;
	else
		return ret = (tiling(n - 1) + tiling(n - 2)) % MOD;
}

int asymmetric(int width)
{
	if (width % 2 == 1)
		return (tiling(width) - tiling(width / 2) + MOD) % MOD;
	else {
		int ret = tiling(width);
		ret = (ret - tiling(width / 2) + MOD) % MOD;
		ret = (ret - tiling(width / 2 - 1) + MOD) % MOD;
		return ret;
	}
}