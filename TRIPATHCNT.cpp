#include <stdio.h>
#include <string.h>
int C;
int N;

int triangle[110][110];

int cache[110][110]; //input cache;
int countCache[110][110];

int result;

int count(int y, int x);

int main(void)
{
	scanf("%d", &C); //input C;

	while (C--)
	{
		for (int i = 0; i < 110; i++) {
			for (int j = 0; j < 110; j++) {
				cache[i][j] = countCache[i][j] = -1;
			}
		}

		scanf("%d", &N); //input N;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= i; j++) {
				scanf("%d", &triangle[i][j]);
			} //for j
		} //for i

		result = count(0, 0);
		printf("%d\n", result);
	}

	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

//path_seq1
//x, y의 최적부분문제(optimal subsequence problem) 해결하는 함수
int path_seq1(int y, int x)
{
	int &ret = cache[y][x];

	//base-condition
	if (y == N - 1)
		return ret = triangle[y][x];

	//if pre-calculated, return ret;
	if (ret != -1)
		return ret;
	else
		return ret = max(path_seq1(y + 1, x), path_seq1(y + 1, x + 1)) + triangle[y][x];
}

//삼각형 위의 최대 경로의 수를 찾는 동적 계획법 알고리즘

//(y, x)에서 시작하여, 맨 아래줄까지  내려가는 경로 중 최대 경로의 개수를 반환한다.
int count(int y, int x)
{
	int &ret = countCache[y][x];

	//기저 사례 : 맨 아래줄에 도달한 경우
	if (y == N - 1)
		return ret = 1;

	if (ret != -1)
		return ret;

	ret = 0;
	if (path_seq1(y + 1, x + 1) >= path_seq1(y + 1, x)) ret += count(y + 1, x + 1);
	if (path_seq1(y + 1, x + 1) <= path_seq1(y + 1, x)) ret += count(y + 1, x);

	return ret;
}