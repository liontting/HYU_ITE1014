#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void star(int num, FILE* f);
void space(int num, FILE* f);

int main() {
	int num;
	FILE* f = fopen("C:\\Star.txt", "r+");

	if (f == NULL) {
		printf("Open Error!\n");
		return -1;
	}
	fscanf(f, "%d", &num);
	fprintf(f, "\n");
	space(num, f);
	fclose(f);
	return 0;
}

void star(int num, FILE* f) {
	if (num >= 5)
		return;
	star(num + 1, f);
	fprintf(f, "*");
}

void space(int num, FILE* f) {
	if (num >= 5)
		return;
	star(num, f);
	fprintf(f, "\n");
	space(num + 1, f);
}