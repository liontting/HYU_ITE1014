#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

int main() {
	int a[12][12] = { 0 };
	int num = 1;
	int cnt = 0;
	for (int i = 1; i < 11; i++) {
		if (i % 2 == 1) {
			cnt++;
			for (int j = cnt; j <= 11 - cnt; j++) {
				a[cnt][j] = num;
				num++;
			}
			for (int k = cnt + 1; k <= 11 - cnt; k++) {
				a[k][11 - cnt] = num;
				num++;
			}
		}
		else {
			for (int j = cnt; j < 11 - cnt; j++) {
				a[11 - cnt][10 - j] = num;
				num++;
			}
			for (int k = cnt + 1; k < 11 - cnt; k++) {
				a[11 - k][cnt] = num;
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