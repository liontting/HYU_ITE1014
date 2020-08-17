#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <random>

typedef struct _student {
	char name[4];
	unsigned int id;
	float score;
	char grade;
} Student;

Student* fillStudents(const int);
void printStudents(Student*, const int);

int main()
{
	int num;
	Student* student;
	srand(time(NULL));
	printf("Input number of students : ");
	scanf("%d", &num);
	student = fillStudents(num);
	printStudents(student, num);
	free(student);
	return 0;
}

Student* fillStudents(const int n) {
	Student* haksaeng;
	haksaeng = (Student*)malloc(n * sizeof(Student));
	char tmp[4] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++)
			tmp[j] = rand() % 26 + 65;
		strcpy(haksaeng[i].name, tmp);
		haksaeng[i].id = 2019000000 + rand() % 1000000;
		haksaeng[i].score = rand() % 451 * 0.01;
		if (haksaeng[i].score >= 4)
			haksaeng[i].grade = 'A';
		else if (haksaeng[i].score >= 3)
			haksaeng[i].grade = 'B';
		else
			haksaeng[i].grade = 'F';
	}
	return haksaeng;
}

void printStudents(Student* haksaeng, const int n) {
	for (int i = 0; i < n; i++) {
		printf("       Student %d\n", i + 1);
		printf("name  : %s\n", haksaeng[i].name);
		printf("id    : %d\n", haksaeng[i].id);
		printf("score : %.2f\n", haksaeng[i].score);
		printf("grade : %c\n", haksaeng[i].grade);
		printf("------------------------\n");
	}
}