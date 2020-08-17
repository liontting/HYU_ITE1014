#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void strReverse(char*, int);

int main(void) {
	char str[100];

	printf("Input string: \t");
	scanf("%[^\n]s", str);
	strReverse(str, sizeof(str));
	printf("Reversed:\t%s\n", str);
	return 0;
}

void strReverse(char* arr, int size) {
	int n = 0;
	char temp;
	for (int i = 0; i < size; i++) {
		if (arr[i] != NULL)
			n++;
		else
			break;
	}
	for (int i = 0; i < n/2; i++) {
		temp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = temp;
	}
}