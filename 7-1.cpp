#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;
/*
int main() {
	int n, a[7] = { 0, }, st[1000] = { 0, };
	srand(time(NULL));
	printf("Dice Proogram\n");
	printf("Lest's Roll : ");
	scanf("%d", &n);
	printf("Rolling . . .\n");
	Sleep(3000);
	for (int i = 0; i < 20; i++)
		st[i] = (rand() % 6) + 1;
	for (int i = 0; i < 20; i++)
		a[st[i]]++;
	printf("Dice number    1   2   3   4   5   6\n");
	printf("Result         %d   %d   %d   %d   %d   %d\n", a[1], a[2], a[3], a[4], a[5], a[6]);
	return 0;
}
*/

int N, M, min, value, gcd;

int G(int n, int m) {
	if (n >= m)
		min = m;
	else
		min = n;
	for (int i = 1; i <= min; i++) {
		if (n%i == 0 && m%i == 0)
			value = i;
	}
	return value;
}

int main() {
	printf("Input two natural numbers\n");
	scanf("%d %d", &N, &M);
	gcd = G(N, M);
	printf("Greatest Common Divisor : %d\n", gcd);
	printf("Least Common Divisor : %d", N*M / gcd);
}

