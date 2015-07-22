#include <stdio.h>
/*
안드로메다 유치원 익스프레스반에서는 다음 주에 율동공원으로 소풍을 갑니다.
원석 선생님은 소풍 때 학생들을 두명씩 짝을 지어 행동하게 하려고 합니다.
그런데 서로 친구가 아닌 학생들끼리 짝을 지어 주면 서로 싸우거나 같이 돌아다니지 않기 때문에
항상 서로 친구인 학생들끼리만 짝을 지어야 합니다.
각 학생들의 쌍에 대해 이들이 서로 친구인지 여부가 주어질 때, 학생들을 짝지을 수 있는
방법의 수를 계산하는 프로그램을 작성하세요. 짝이 되는 학생들이 일부만 다르더라도 다른 방법이라고 봅니다.
예를 들어 다음 두 가지 방법은 서로 다른 방법입니다.

- (태연,제시카) (써니,티파니) (효연, 유리)
- (태연,제시카) (써니,유리) (효연,티파니)

3 
2 1 
0 1 
4 6 
0 1 1 2 2 3 3 0 0 2 1 3 
6 10 
0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5
*/

int N;	//TC
int n, m;


int taken[10];	//is it checked?
int pairing[10][10];
int f1, f2;

int result;

int countpair(void);

int main(void)
{
	int i, j;

	scanf("%d", &N);	//TC

	while(N--)
	{
		scanf("%d %d", &n, &m);	//input

		for(i=0; i<m; i++)	{
			scanf("%d %d", &f1, &f2);	//input this
			pairing[f1][f2] = 1;
			pairing[f2][f1] = 1;	//check this
		}

		result = countpair();

		printf("%d\n", result);

		for(i=0; i<10; i++)	{
			for(j=0; j<10; j++)	{
				pairing[i][j] = 0;					
			}	//for j
		}	//for i
		result = 0;

	}


	return 0;
}

int countpair(void)
{
	int i, j;
	int first=-1;
	int ret = 0;

	for(i=0; i<n; i++)	{
		if(taken[i] == 0)	{
			first = i;
			break;
		}
	}

	if(first == -1) return 1;	//search 1 statement

	//next searching number is first +1 to n;;;
	for(i=first+1; i<n; i++)	{
		if(taken[i] == 0 && pairing[first][i] == 1)	{
			taken[first] = taken[i] = 1;	//set flag one
			ret += countpair();	
			taken[first] = taken[i] = 0;	//reset flag zero
		}	//taken[i]
	}	//for i

	return ret;

}	//countpair