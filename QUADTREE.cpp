#include <stdio.h>

#define MAX_LENGTH 2048

int c;
char result[MAX_LENGTH];
char input[MAX_LENGTH];

void reverse(char **pp, char *result);

int main(void)
{
	scanf("%d", &c);
	char *p;
	while (c--)
	{
		scanf("%s", &input);
		p = input;
		reverse(&p, result);

		printf("%s\n", result);
	}

	return 0;
}


void reverse(char **pp, char *result)
{
	char topleft[MAX_LENGTH], topright[MAX_LENGTH], bottomleft[MAX_LENGTH], bottomright[MAX_LENGTH];
	char c;

	c = *(*pp)++; //진행될때마다 포인터를 한칸씩 옮긴다.
	if (c != 'x') {
		result[0] = c;
		result[1] = '\0';
		return;
	}
	else {
		reverse(pp, topleft);
		reverse(pp, topright);
		reverse(pp, bottomleft);
		reverse(pp, bottomright);

		sprintf(result, "x%s%s%s%s", bottomleft, bottomright, topleft, topright);
	}
}