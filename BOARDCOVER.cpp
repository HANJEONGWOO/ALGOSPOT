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

		if(ny < 0 || ny >= saero || nx < 0 || nx >= garo)//�����ų� ��ġ�ų� �ϸ� ����
			ok = false;
		else if( (board[ny][nx] += delta) > 1)	//���� ĭ�� ���� �� ����
			ok = false;
	}

	return ok;
}

//board�� ��� �� ĭ�� ���� �� �ִ� ����� ���� ��ȯ�Ѵ�.
//board[i][j] = 1 �̹� ���� ĭ Ȥ�� ���� ĭ
//board[i][j] = 0 ���� ������ ���� ĭ

int cover()	{
	//���� ä���� ���� ĭ �� ���� ���� ���ʿ� �ִ� ĭ�� ã�´�.
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

	//���� ���� : ��� ĭ�� ä������ 1�� ��ȯ�Ѵ�.
	if(y == -1) return 1;

	int ret = 0;
	for(int type = 0; type < 4; type++)	{
		//���� board[y][x]�� type���·� ���� �� ������ ��� ȣ���Ѵ�.
		if(set(y, x, type, 1) )
			ret += cover();
		//������ ����� ġ���.
		set(y, x, type, -1);
	}

	return ret;
}

