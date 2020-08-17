#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <random>

int** make(int row, int col);
int** putin(int** a, int row, int col);
void afree(int** a, int col);

int main()
{
	int firRow, firCol, secRow, secCol;
	srand(time(NULL));

	while (1) {
		printf("---- MATRIX 1 GENERATION ----\n");
		printf("Input row size : ");
		scanf("%d", &firRow);
		printf("Input column size : ");
		scanf("%d", &firCol);
		printf("\n");
		printf("---- MATRIX 2 GENERATION ----\n");
		printf("Input row size : ");
		scanf("%d", &secRow);
		printf("Input column size : ");
		scanf("%d", &secCol);

		if (firCol == secRow) {
			int** first = make(firRow, firCol);
			int** second = make(secRow, secCol);
			int** answer = make(firRow, secCol);

			for (int i = 0; i < firRow; i++)
				memset(answer[i], 0, secCol * sizeof(int));
			printf("\n");

			printf("<matrix 1>\n");
			first = putin(first, firRow, firCol);

			printf("<matrix 2>\n");
			second = putin(second, secRow, secCol);

			printf("<matrix 1 X matrix 2>\n");
			for (int i = 0; i < firRow; i++)
				for (int j = 0; j < secCol; j++)
					for (int k = 0; k < firCol; k++)
						answer[i][j] += first[i][k] * second[k][j];

			for (int i = 0; i < firRow; i++) {
				for (int j = 0; j < secCol; j++)
					printf("%4d", answer[i][j]);
				printf("\n");
			}
			afree(first, firCol);
			afree(second, secCol);
			afree(answer, secCol);
			break;
		}
		else {
			printf("<SIZE ERROR> the column size of first matrix must be equal to the row size of second matirx\n");
			printf("\n");
		}
	}
	return 0;
}

int** make(int row, int col) {
	int** a = NULL;
	a = (int **)malloc(row * sizeof(int *));
	for (int i = 0; i < row; i++)
		a[i] = (int *)malloc(col * sizeof(int));
	return a;
}

int** putin(int** a, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			a[i][j] = rand() % 10;
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return a;
}

void afree(int** a, int col) {
	for (int i = 0; i < col; i++)
		free(a[i]);
	free(a);
}