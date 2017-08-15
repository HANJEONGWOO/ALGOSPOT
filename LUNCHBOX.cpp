#include <stdio.h>

int TC;
int N;

typedef struct lunch_time_ {
	int m_time;
	int e_time;
} lunch_time;

lunch_time lunch_arr[11000];

int micro_time;
int result;

void input(void);
void selection_sort(lunch_time *arr, int size);
int max(int a, int b);
void init(void);

int main(void)
{
	scanf("%d", &TC); //input tc

	while (TC--)
	{
		//init
		init();

		input(); //input this

		selection_sort(lunch_arr, N);

		//TEST
		//		for (int i = 0; i < N; i++)
		//			printf("! %d %d\n", lunch_arr[i].m_time, lunch_arr[i].e_time);

		for (int i = 0; i < N; i++) {
			micro_time += lunch_arr[i].m_time;
			result = max(result, micro_time + lunch_arr[i].e_time);
		}

		printf("%d\n", result);
	}

	return 0;
}

void init(void)
{
	micro_time = 0;
	result = 0;
}

void input(void)
{
	scanf("%d", &N); //input

	for (int i = 0; i < N; i++)
		scanf("%d", &lunch_arr[i].m_time);
	for (int i = 0; i < N; i++)
		scanf("%d", &lunch_arr[i].e_time);
}

void selection_sort(lunch_time *arr, int size)
{
	lunch_time temp;
	int index;

	for (int i = 0; i < size - 1; i++) {
		index = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[index].e_time < arr[j].e_time)
				index = j;
		}
		//swap two value
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
}

int max(int a, int b)
{
	return a > b ? a : b;
}