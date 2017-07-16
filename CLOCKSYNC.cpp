#include <stdio.h>

#define SWITCH 10
#define CLOCKS 16

char swtch[SWITCH][CLOCKS + 1] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x..",
};

int C;
int clock[16];

int result;

bool is_aligned(void);
void Push(int swtch_num);
void Sync(int swtch_num, int push_num);
int main(void)
{

	scanf("%d", &C); //input C

	while (C--)
	{
		result = 987654321;

		for (int i = 0; i < 16; i++) {
			scanf("%d", &clock[i]); //input clock time.
		}
		Sync(0, 0); //
		if (result == 987654321)
			printf("-1\n");
		else
			printf("%d\n", result);
	}

	return 0;
}

bool is_aligned(void)
{
	bool ret = true;
	for (int i = 0; i < CLOCKS; i++) {
		if (clock[i] != 12) {
			ret = false;
			break;
		}
	}

	return ret;
}

void Push(int swtch_num) {

	for (int i = 0; i < CLOCKS; i++) {
		if (swtch[swtch_num][i] == 'x') {
			clock[i] += 3;
			if (clock[i] == 15)
				clock[i] = 3;
		}
	}
}

void Sync(int swtch_num, int push_num)
{
	if (swtch_num == SWITCH) //end
	{
		if ((is_aligned() == true) && (result > push_num))
			result = push_num;
		return;
	}

	for (int i = 0; i < 4; i++) {
		Sync(swtch_num + 1, push_num + i); // call next push, and plus push_num;
		Push(swtch_num);
	}
}