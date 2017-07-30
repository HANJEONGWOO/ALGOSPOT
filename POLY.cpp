#include <stdio.h>

#define MOD 10000000

int C;
int N;

int cache[110][110];
int result;

int poly(int n, int first);

int main(void)
{
	scanf("%d", &C);

	while (C--)
	{
		//initialize
		result = 0;

		scanf("%d", &N); //input N;;

		for (int i = 1; i <= N; i++) {
			//initialize_cache_memory
			for (int j = 0; j < 110; j++) {
				for (int k = 0; k < 110; k++) {
					cache[j][k] = -1;
				}
			}

			result += poly(N, i);
			result %= MOD;
		}

		printf("%d\n", result);
	}

	return 0;
}

int poly(int n, int first)
{
	//base-case
	if (n == first)
		return 1;

	//memoization
	int &ret = cache[n][first];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int second = 1; second <= n - first; second++)
	{
		int add = first + second - 1; //맞닿아 있는 수를 구한다. 맞닿은 수는 first + second -1이다.
		add *= poly(n - first, second); //poly를 재귀호출한다.
		add %= MOD;
		ret += add;
		ret %= MOD;
	}

	return ret;
}