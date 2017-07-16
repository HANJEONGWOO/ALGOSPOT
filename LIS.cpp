#include <stdio.h>

int C;
int N;

int arr[550];
int cache[550];

int result;

int lis(int start);
int max(int a, int b);

int main(void)
{
	scanf("%d", &C);

	while (C--)
	{
		result = 0;
		for (int i = 0; i < 550; i++) {
			cache[i] = -1;
			arr[i] = 0;
		}

		scanf("%d", &N); //input N

		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}

		result = 0;
		for (int i = 0; i < N; i++) {
			result = max(result, lis(i));
		}

		printf("%d\n", result); //print result it.
	}

	return 0;
}

int lis(int start)
{
	int &ret = cache[start];

	if (ret != -1) return ret;

	ret = 1; //맨 처음 값만 하더라도 1이므로 초기값을 1로 둔다.
	for (int next = start + 1; next < N; next++) {
		if (arr[start] < arr[next])
			ret = max(ret, lis(next) + 1);
	}

	return ret;
}

int max(int a, int b) {
	return a > b ? a : b;
}