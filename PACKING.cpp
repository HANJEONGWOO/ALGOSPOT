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
	//���� ���
	if (n == N)
		return 0; //���� ��� �������� �� ������ ���� 0�� �����Ѵ�.

	int &ret = cache[capacity][n]; //memoization

	if (ret != -1)
		return ret;

	//�̹� �������� ���� ���� ��,
	ret = dynamic(capacity, n + 1);

	if (capacity - volume[n] >= 0) //�̹� ���Ǹ� ���� �뷮���� Ŭ ��
	{
		ret = max(ret, dynamic(capacity - volume[n], n + 1) + need[n]);
	}

	return ret; //���ڵ� ��ȯ
}

void backtrack(int capacity, int n)
{
	if (n == N)
		return;

	if (dynamic(capacity, n) == dynamic(capacity, n + 1)) {
		//�̹� �������� �߰����� ���� ����� ������ �̹� ����� ���� �ʿ䰡 ����.
		backtrack(capacity, n + 1);
	}
	else {
		//�̹� �������� �߰��ϴ� ���� �̵��̹Ƿ� ������ �����Ѵ�.
		strcpy(result_name[result_pnum++], name[n]);
		backtrack(capacity - volume[n], n + 1);
	}
}