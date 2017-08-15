#include <stdio.h>
#include <string.h>

int C;
int N, W;

char name[100][22];
int volume[100];
int need[100];

int cache[1100][100];

int result_need;
int result_pnum;
char result_name[100][22];

int max(int a, int b);
int dynamic(int capacity, int n);
void backtrack(int capacity, int n);

int main(void)
{
	scanf("%d", &C); //input tc

	while (C--)
	{
		for (int i = 0; i < 1100; i++) {
			for (int j = 0; j < 100; j++) {
				cache[i][j] = -1; //init cache memory
			} //for j
		} //for i
		result_need = 0;
		result_pnum = 0;

		scanf("%d %d", &N, &W); // product num, career volume

		for (int i = 0; i < N; i++) {
			scanf("%s %d %d", name[i], &volume[i], &need[i]);
		} //for i

		  //print result;
		result_need = dynamic(W, 0);
		backtrack(W, 0);

		printf("%d %d\n", result_need, result_pnum);
		for (int i = 0; i < result_pnum; i++) {
			printf("%s\n", result_name[i]); //print result_name
		} //for i

	} //tc

	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int dynamic(int capacity, int n)
{
	//기저 사례
	if (n == N)
		return 0; //만약 모든 아이템을 다 돌았을 때는 0을 리턴한다.

	int &ret = cache[capacity][n]; //memoization

	if (ret != -1)
		return ret;

	//이번 아이템을 고르지 않을 때,
	ret = dynamic(capacity, n + 1);

	if (capacity - volume[n] >= 0) //이번 부피를 빼고도 용량보다 클 때
	{
		ret = max(ret, dynamic(capacity - volume[n], n + 1) + need[n]);
	}

	return ret; //절박도 반환
}

void backtrack(int capacity, int n)
{
	if (n == N)
		return;

	if (dynamic(capacity, n) == dynamic(capacity, n + 1)) {
		//이번 아이템을 추가하지 않은 결과와 같으면 이번 결과를 더할 필요가 없다.
		backtrack(capacity, n + 1);
	}
	else {
		//이번 아이템을 추가하는 것이 이득이므로 아이템 저장한다.
		strcpy(result_name[result_pnum++], name[n]);
		backtrack(capacity - volume[n], n + 1);
	}
}