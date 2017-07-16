#include <stdio.h>

int C;
char wildcard[110];

int N;
char file[110];

char answer[1100][110];
int answer_num = 0;

int cache[101][101]; //for memoization;

int mystrlen(const char *s);
char *mystrcpy(char *dest, const char *src);
int mystrcmp(char *s1, char *s2);

void selection_sort(int num);

bool matchMemoized(int w, int s);

int main(void)
{
	scanf("%d", &C);

	while (C--)
	{
		answer_num = 0;


		scanf("%s", &wildcard); //input wildcard

		scanf("%d", &N); //file number

		for (int i = 0; i < N; i++) {
			scanf("%s", file);

			for (int j = 0; j < 101; j++) {
				for (int k = 0; k < 101; k++) {
					cache[j][k] = -1;
				}
			}

			if (matchMemoized(0, 0) == true) {
				mystrcpy(answer[answer_num++], file);
			}
		}

		selection_sort(answer_num);
		for (int i = 0; i < answer_num; i++) {
			printf("%s\n", answer[i]); //print result;
		}

	}

	return 0;
}

//-1은 아직 답이 계산되지 않았음을 의미한다.
//0은 해당 입력들이 서로 대응되지 않음을 의미한다.
//1은 해당 입력들이 서로 대응됨을 의미한다.


//와일드카드 패턴 wildcard가 문자열 file에 대응되는지 여부를 반환한다.
bool matchMemoized(int w, int s)
{
	int &ret = cache[w][s];
	if (ret != -1) return ret;

	//만약 매치된다면 w, s를 옮긴다.
	while (w < mystrlen(wildcard) && s < mystrlen(file) & (wildcard[w] == '?' || wildcard[w] == file[s])) {
		w++;
		s++;
	}

	//만약, w가 문자의 끝이라면, s도 문자의 끝이여야 한다.
	if (w == mystrlen(wildcard)) {
		return ret = (s == mystrlen(file));
	}

	//만약, *라면, 메모이제이션 재귀 호출
	if (wildcard[w] == '*') {
		for (int skip = 0; s + skip <= mystrlen(file); skip++) {
			if (matchMemoized(w + 1, s + skip))
				return ret = 1; //메모
		}
	}

	return ret = 0; //메모
}


int mystrlen(const char *s)
{
	int i = 0;
	while (s[i] != 0)
		i++;
	return i;
}

char *mystrcpy(char *dest, const char *src)
{
	int i = 0;
	while (src[i] != 0) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0; //set null;

	return dest;
}

int mystrcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
		i++;

	return s1[i] - s2[i];
}

void selection_sort(int num)
{
	int i, j;
	char temp[110];
	int idx;

	for (int i = 0; i < num - 1; i++) {
		idx = i;
		for (int j = i + 1; j < num; j++) {
			//get the lowest value;
			if (mystrcmp(answer[idx], answer[j]) > 0)
				idx = j;
		}
		//swap the two value
		mystrcpy(temp, answer[i]);
		mystrcpy(answer[i], answer[idx]);
		mystrcpy(answer[idx], temp);
	}
}