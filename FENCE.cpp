#include <stdio.h>

int C;
int N;

int fence[22000];

int result;

int solve(int left, int right);
int mymin(int a, int b);
int mymax(int a, int b);

int main(void)
{
	scanf("%d", &C); //input TC

	while (C--)
	{
		scanf("%d", &N); //input N

		for (int i = 0; i < N; i++) {
			scanf("%d", &fence[i]); //input fence
		}

		result = solve(0, N - 1);
		printf("%d\n", result);
	}

	return 0;
}

int solve(int left, int right)
{
	int lo, hi;
	int mid;
	int ret;

	int min_height;

	//base case
	if (right == left)
		return fence[right];//if length is one, return fence.

	mid = (left + right) / 2; //get mid
	ret = mymax(solve(left, mid), solve(mid + 1, right)); //divide two problem;

														  //get inverval value
	lo = mid; hi = mid + 1;
	min_height = mymin(fence[lo], fence[hi]); //get min height. where two values.
	ret = mymax(ret, min_height * (hi - lo + 1)); //compare with ret.

	while (left < lo || hi < right)
	{
		if ((left < lo) && ((hi == right) || (fence[lo - 1] > fence[hi + 1]))) {
			lo--;
			min_height = mymin(min_height, fence[lo]);
		}
		else
		{
			hi++;
			min_height = mymin(min_height, fence[hi]);
		}
		ret = mymax(ret, min_height * (hi - lo + 1));
	}

	return ret;
}

int mymin(int a, int b)
{
	return (a > b) ? b : a;
}

int mymax(int a, int b)
{
	return (a > b) ? a : b;
}