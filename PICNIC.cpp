#include <stdio.h>
/*
�ȵ�θ޴� ��ġ�� �ͽ��������ݿ����� ���� �ֿ� ������������ ��ǳ�� ���ϴ�.
���� �������� ��ǳ �� �л����� �θ� ¦�� ���� �ൿ�ϰ� �Ϸ��� �մϴ�.
�׷��� ���� ģ���� �ƴ� �л��鳢�� ¦�� ���� �ָ� ���� �ο�ų� ���� ���ƴٴ��� �ʱ� ������
�׻� ���� ģ���� �л��鳢���� ¦�� ����� �մϴ�.
�� �л����� �ֿ� ���� �̵��� ���� ģ������ ���ΰ� �־��� ��, �л����� ¦���� �� �ִ�
����� ���� ����ϴ� ���α׷��� �ۼ��ϼ���. ¦�� �Ǵ� �л����� �Ϻθ� �ٸ����� �ٸ� ����̶�� ���ϴ�.
���� ��� ���� �� ���� ����� ���� �ٸ� ����Դϴ�.

- (�¿�,����ī) (���,Ƽ�Ĵ�) (ȿ��, ����)
- (�¿�,����ī) (���,����) (ȿ��,Ƽ�Ĵ�)

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