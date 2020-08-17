#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
using namespace std;

int main() {
	char str[100] = { 0, };
	int num;
	printf("Input a sentence\n");
	scanf("%[^\n]s", str);
	printf("Input a natural number: ");
	scanf("%d", &num);
	for (int i = 1; str[i-1]; i++) {
		printf("%c", str[i-1]);
		if (i % num == 0 && str[i] != 0)
			printf("\n");
	}
	return 0;
}

/*
int main() {
	char str[100] = { 0, };
	int num, n=0;
	printf("Input a sentence\n");
	scanf("%[^\n]s", str);
	printf("Input a natural number: ");
	scanf("%d", &num);
	for (int i = 0; str[i]!=0; i++)
		n++;
	for (int i = 0; i <= (n-1) / num; i++) {
		for (int j = 0; j < num; j++)
			printf("%c", str[num * i + j]);
		printf("\n");
	}
	system("pause");
	return 0;
}
*/