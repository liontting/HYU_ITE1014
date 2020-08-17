#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

int main() {
	int a[12][12] = { 0 };
	int num = 1;
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			if (i % 2 == 1) {
				a[i][j] = num;
				num++;
			}
			else {
				a[i][11 - j] = num;
				num++;
			}
		}
	}
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}