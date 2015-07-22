#include <stdio.h>

int N;
int garo, saero;
int board[30][30];
char temp[30];

int result;

const int coverType[4][3][2] =	{
	{ {0, 0}, {1, 0}, {0, 1}	},	//b
	{ {0, 0}, {0, 1}, {1, 1}	},	//c
	{ {0, 0}, {1, 0}, {1, 1}	},	//d
	{ {0, 0}, {1, 0}, {1, -1}	}	//e
};

bool set(int y, int x, int type, int delta);
int cover();

int main(void)
{
	int i, j;

	scanf("%d", &N);	//input N;;

	while(N--)
	{
		scanf("%d %d", &saero, &garo);	//input saero and garo

		for(i=0; i<saero; i++)	{
			scanf("%s", &temp);	//input string;;
			for(j=0; j<garo; j++)	{
				if(temp[j] == '#')
					board[i][j] = 1;
				else
					board[i][j] = 0;
			}
		}	//input

		result = cover();
		printf("%d\n", result);

		for(i=0; i<saero; i++)	{
			for(j=0; j<garo; j++)	{
				board[i][j] = 0;
			}
		}

	}	//while

	return 0;
}

bool set(int y, int x, int type, int delta)
{
	bool ok = true;

	for(int i=0; i<3; i++)	{
		const int ny = y + coverType[type][i][0];	//add type;
		const int nx = x + coverType[type][i][1];	//add type;

		if(ny < 0 || ny >= saero || nx < 0 || nx >= garo)//나가거나 겹치거나 하면 거짓
			ok = false;
		else if( (board[ny][nx] += delta) > 1)	//검은 칸을 덮을 때 거짓
			ok = false;
	}

	return ok;
}

//board의 모든 빈 칸을 덮을 수 있는 방법의 수를 반환한다.
//board[i][j] = 1 이미 덮인 칸 혹은 검은 칸
//board[i][j] = 0 아직 덮이지 않은 칸

int cover()	{
	//아직 채우지 못한 칸 중 가장 윗줄 왼쪽에 있는 칸을 찾는다.
	int y = -1, x = -1;

	for(int i=0; i<saero; i++)	{
		for(int j=0; j<garo; j++)	{
			if(board[i][j] == 0)	{
				y = i;
				x=  j;
				break;
			}
		}
		if(y!= -1)
			break;
	}

	//종료 조건 : 모든 칸을 채웠으면 1을 반환한다.
	if(y == -1) return 1;

	int ret = 0;
	for(int type = 0; type < 4; type++)	{
		//만약 board[y][x]를 type형태로 덮을 수 있으면 재귀 호출한다.
		if(set(y, x, type, 1) )
			ret += cover();
		//덮었던 블록을 치운다.
		set(y, x, type, -1);
	}

	return ret;
}

