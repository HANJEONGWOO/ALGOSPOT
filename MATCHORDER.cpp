#include <stdio.h>

int TC;
int N;

int russian[110];

int korean[110];
int korean_is_used[110];

int result;

void init(void);
void input(void);
void selection_sort(int *arr, int size);
void process(void);

int main(void)
{
	scanf("%d", &TC);

	while (TC--)
	{
		init();

		input();

		selection_sort(russian, N);
		selection_sort(korean, N);

		process();

		printf("%d\n", result);
	}

	return 0;
}

void init(void)
{
	result = 0; //set result;

	for (int i = 0; i < 110; i++) {
		korean[i] = russian[i] = korean_is_used[i] = 0; //set value;
	}

}

void input(void)
{
	int i, j;

	scanf("%d", &N); //input N

	for (i = 0; i < N; i++) {
		scanf("%d", &russian[i]);
	}
	for (i = 0; i < N; i++) {
		scanf("%d", &korean[i]);
	}
}

void selection_sort(int *arr, int size)
{
	int index, temp;

	for (int i = 0; i < size - 1; i++)
	{
		index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[index] > arr[j])
				index = j;
		}
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
}

void process(void)
{
	int i, j;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if ((russian[i] <= korean[j]) && (korean_is_used[j] == 0))
			{
				korean_is_used[j] = 1; //already used
				result++; //plus result value

				break; //after process, break it.
			}
		} //for j

	} //for i

}