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
//x, y�� �����κй���(optimal subsequence problem) �ذ��ϴ� �Լ�
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

//�ﰢ�� ���� �ִ� ����� ���� ã�� ���� ��ȹ�� �˰���

//(y, x)���� �����Ͽ�, �� �Ʒ��ٱ���  �������� ��� �� �ִ� ����� ������ ��ȯ�Ѵ�.
int count(int y, int x)
{
	int &ret = countCache[y][x];

	//���� ��� : �� �Ʒ��ٿ� ������ ���
	if (y == N - 1)
		return ret = 1;

	if (ret != -1)
		return ret;

	ret = 0;
	if (path_seq1(y + 1, x + 1) >= path_seq1(y + 1, x)) ret += count(y + 1, x + 1);
	if (path_seq1(y + 1, x + 1) <= path_seq1(y + 1, x)) ret += count(y + 1, x);

	return ret;
}