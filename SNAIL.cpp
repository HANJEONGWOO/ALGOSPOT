#include <stdio.h>

int C;
int water_depth, flood_days;

double result;

double table[1100][2 * 1100];

double flood(int days, int climbed);

int main(void)
{

	scanf("%d", &C);

	while (C--)
	{
		for (int i = 0; i < 1100; i++) {
			for (int j = 0; j < 2 * 1100; j++) {
				table[i][j] = -1.0;
			}
		}

		scanf("%d %d", &water_depth, &flood_days); //input depth N and length M

		result = flood(0, 0);

		printf("%.11lf\n", result);
	}




	return 0;
}

double flood(int days, int climbed)
{
	//base-case
	if (days == flood_days)
		return (water_depth <= climbed) ? 1.0 : 0.0;

	double &ret = table[days][climbed];

	if (ret != -1.0)
		return ret; //memorized;
	else
		return ret = (0.75 * flood(days + 1, climbed + 2)) + (0.25 * flood(days + 1, climbed + 1));
}