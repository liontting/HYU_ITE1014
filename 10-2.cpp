#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
void ispri(int *Arr);
int *RanArr(int *size);

int main()
{
	int size;
	printf("Input Array size : ");
	scanf("%d", &size);
	ispri(RanArr(&size));
	system("pause");
	return 0;
}

void ispri(int *Arr) {
	int *arr = (int*)malloc(0);
	int n = 0;
	for (int i = 0; i < _msize(Arr) / sizeof(int); i++) {
		int num = 0;
		for (int j = 1; j <= Arr[i]; j++) {
			if (Arr[i] % j == 0)
				num++;
		}
		if (num == 2) {
			n++;
			arr = (int *)realloc(arr, n * sizeof(int));
			arr[n - 1] = Arr[i];
		}
	}
	printf("In Array Primes : ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

int *RanArr(int *size) {
	int *ar = (int *)malloc(*size * sizeof(int));
	srand(time(NULL));
	printf("In Array Values : ");
	for (int i = 0; i < *size; i++) {
		ar[i] = rand() % 50 + 1;
		printf("%d ", ar[i]);
	}
	printf("\n");
	return ar;
}