#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <random>
#include <string.h>

int main()
{
	char buf[100];
	int num, dap[10] = { 0, };
	char *ptr = NULL;
	while (1) {
		printf("Input 8 digit number : ");
		if (scanf("%d", &num) == 0) {
			printf("<ERROR> scanf error\n");
			while (getchar() != '\n');
			continue;
		}
		sprintf(buf, "%d", num);
		if (strlen(buf) != 8) {
			printf("<ERROR> wrong input error\n");
			continue;
		}
		else {
			printf("  0  1  2  3  4  5  6  7  8  9\n");
			printf("--------------------------------\n");
			for (int i = 0; i < 10; i++) {
				ptr = strchr(buf, 48 + i);
				while (ptr != NULL) {
					dap[i]++;
					ptr = strchr(ptr + 1, 48 + i);
				}
			}
			for (int i = 0; i < 10; i++)
				printf("  %d", dap[i]);
			break;
		}
	}
	return 0;
}