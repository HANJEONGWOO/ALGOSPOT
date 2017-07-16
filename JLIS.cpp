#include <stdio.h>
#include <limits.h>

int c;

//�Է��� 32��Ʈ ��ȣ �ִ� ������ ��� ���� ���� �� �����Ƿ�
//�������� �ּ�ġ�� 64��Ʈ���� �Ѵ�.
const long long int NEGINF = (-2147483647 - 1);
int n, m, A[100], B[100];
int cache[101][101];

int result;

int jlis(int indexA, int indexB);
int max(long long int a, long long int b);

int main(void)
{
	scanf("%d", &c);

	while (c--)
	{
		result = 0;
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				cache[i][j] = -1; //set -1;
			}
		}
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++)
			scanf("%d", &A[i]);
		for (int i = 0; i < m; i++)
			scanf("%d", &B[i]);

		result = jlis(-1, -1);
		printf("%d\n", result - 2);
	}

	return 0;
}


//min(A[indexA], B[indexB]), max(A[indexA], B[indexB])�� �����ϴ�
//��ģ ���� �κ� ������ �ִ� ���̸� ��ȯ�Ѵ�.
//�� indexA == indexB == -1 Ȥ�� A[indexA] != B[indexB]��� �����Ѵ�.
int jlis(int indexA, int indexB) {
	//�޸������̼�
	int &ret = cache[indexA + 1][indexB + 1];
	if (ret != -1) return ret;

	//ó������ indexA, indexB�� �����Ƿ� ���ϰ��� 2�� �����Ѵ�.
	ret = 2;
	long long a = (indexA == -1) ? NEGINF : A[indexA];
	long long b = (indexB == -1) ? NEGINF : B[indexB];
	long long maxvalue = max(a, b);

	for (int nextA = indexA + 1; nextA < n; nextA++) {
		if (maxvalue < A[nextA])
			ret = max(ret, jlis(nextA, indexB) + 1);
	}
	for (int nextB = indexB + 1; nextB < m; nextB++) {
		if (maxvalue < B[nextB])
			ret = max(ret, jlis(indexA, nextB) + 1);
	}

	return ret;
}

int max(long long int a, long long int b) {
	return a > b ? a : b;
}