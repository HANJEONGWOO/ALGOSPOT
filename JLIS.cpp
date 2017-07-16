#include <stdio.h>
#include <limits.h>

int c;

//입력이 32비트 부호 있는 정수의 모든 값을 가질 수 있으므로
//인위적인 최소치는 64비트여야 한다.
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


//min(A[indexA], B[indexB]), max(A[indexA], B[indexB])로 시작하는
//합친 증가 부분 수열의 최대 길이를 반환한다.
//단 indexA == indexB == -1 혹은 A[indexA] != B[indexB]라고 가정한다.
int jlis(int indexA, int indexB) {
	//메모이제이션
	int &ret = cache[indexA + 1][indexB + 1];
	if (ret != -1) return ret;

	//처음부터 indexA, indexB가 있으므로 리턴값은 2로 세팅한다.
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