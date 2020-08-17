#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
	int judge, num;
	do {
		printf("-----------------------------------\n");
		printf("\t\tPRINTER\n");
		printf("-----------------------------------\n");
		printf("\t1. Square\n");
		printf("\t2. Reversed triangle\n");
		printf("\t0. Exit\n");
		printf("-----------------------------------\n");
		printf("Input: ");
		scanf("%d", &judge);
		switch (judge) {
		case 1:
			printf("Input size of the square: ");
			scanf("%d", &num);
			for (int i = 0; i < num; i++) {
				printf("*");
				for (int j = 1; j < num - 1; j++) {
					if (i == 0 || i == num - 1)
						printf("*");
					else
						printf(" ");
				}
				printf("*\n");
			}
			break;
		case 2:
			printf("Input size of the triangle: ");
			scanf("%d", &num);
			for (int i = 0; i < num / 2 + 1; i++) {
				for (int j = 0; j < num; j++) {
					if (i == 0)
						printf("*");
					else {
						if (j == i || j == num - (i + 1))
							printf("*");
						else
							printf(" ");
					}
				}
				printf("\n");
			}
			break;
		case 0:
			printf("Good bye!\n");
			break;
		default:
			printf("Wrong command\n");
		}
	} while (judge != 0);
	system("pause");
	return 0;
}