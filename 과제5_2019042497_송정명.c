#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int** rotate(int** matrix); // 회전한 크기에 맞는 이차원 배열을 새로 생성하여 값을 복사해 넣고 기존 배열의 메모리는 해제하고 새로운 배열을 리턴하는 함수

int main()
{
	int sizeRow, sizeCol, n = 3; // 행과 열의 크기 변수 선언, n=3은 90,180,270도 회전을 짧은 코드로 표현하기 위해 선언, 정의
	printf("Input row size of the matrix : ");
	scanf("%d", &sizeRow); // 행의 크기 입력 받음
	printf("Input column size of the matrix : ");
	scanf("%d", &sizeCol); // 열의 크기 입력 받음

	int** arr = NULL; // 이중 포인터 변수 선언
	arr = (int **)malloc(sizeRow * sizeof(int *)); // 일차원 배열이 담길 이차원 공간 동적 할당
	for (int i = 0; i < sizeRow; i++) // 일차원 배열들 동적 할당하기 위한 for문
		arr[i] = (int*)malloc(sizeCol * sizeof(int)); // 각 일차원 배열들 동적 할당

	for (int i = 0; i < sizeRow; i++) // sizeRow를 행의 크기로
		for (int j = 0; j < sizeCol; j++) // sizeCol을 열의 크기로
			arr[i][j] = sizeCol * i + j + 1; // 1부터 증가시켜서 값을 넣음

	printf("< degree : 0 >\n"); // 회전시키지 않았을 때(0도일 때)
	for (int i = 0; i < sizeRow; i++) {
		for (int j = 0; j < sizeCol; j++)
			printf("%4d", arr[i][j]); // 회전시키지 않았을 때(0도일 때)의 값 출력
		printf("\n");
	}

	int** arr1 = NULL; // 회전시킨 배열을 담기위한 이중 포인터 변수 선언
	
	while (n--) { // 90도, 180도, 270도 회전을 간단히 표현하기 위해 n이 2,1,0 순서로 가도록 함
		printf("< degree : %d >\n", (3 - n) * 90); // n이 2일 때, 90도, n이 1일 때, 180도, n이 0일 때, 270도
		if (n % 2 == 1) { // 180도 회전일 때의 경우
			arr = rotate(arr1); // rotate 함수를 이용해 180도만큼 회전한 값을 먼저 선언한 변수에 넣음
			for (int i = 0; i < sizeRow; i++) { // 180도일 때의 행 크기만큼 for문 돌림
				for (int j = 0; j < sizeCol; j++) // 180도일 때의 열 크기만큼 for문 돌림
					printf("%4d", arr[i][j]);  // 180도일 때의 값 출력
				printf("\n");
			}
		}
		else { // 90도, 270도 회전일 때의 경우
			arr1 = rotate(arr); // rotate 함수를 이용해 90, 270도만큼 회전한 값을 먼저 선언한 변수에 넣음
			for (int i = 0; i < sizeCol; i++) { // 90, 270도일 때의 행 크기만큼 for문 돌림
				for (int j = 0; j < sizeRow; j++) // 90, 270도일 때의 열 크기만큼 for문 돌림
					printf("%4d", arr1[i][j]); // 90도, 270도일 때의 값 출력
				printf("\n");
			}
		}
	}
	
	for (int i = 0; i < sizeRow; i++)
		free(arr1[i]); // 일차원 배열이 할당되었던 각 공간을 전부 free
	free(arr1); // 일차원 배열의 포인터를 저장했던 이차원 공간을 전부 free

	return 0;
}

int** rotate(int** matrix) { // 회전한 크기에 맞는 이차원 배열을 새로 생성하여 값을 복사해 넣고 기존 배열의 메모리는 해제하고 새로운 배열을 리턴하는 함수
	int row = _msize(matrix[0]) / sizeof(int); // 매개변수로 받은 배열의 열의 크기 == 회전한 배열의 행의 크기
	int col = _msize(matrix) / sizeof(int); // 매개변수로 받은 배열의 행의 크기 == 회전한 배열의 열의 크기

	int** a = NULL; // 회전할 배열을 담을 이중 포인터 변수 선언
	a = (int **)malloc(row * sizeof(int *)); // 일차원 배열이 담길 이차원 공간 동적 할당
	for (int i = 0; i < row; i++) // 일차원 배열들 동적 할당하기 위한 for문
		a[i] = (int*)malloc(col * sizeof(int)); // 각 일차원 배열들 동적 할당

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			a[i][j] = matrix[col - 1 - j][i]; // 기존 배열의 값을 90도만큼 회전하여 새로운 배열에 담음
		}
	}

	for (int i = 0; i < col; i++)
		free(matrix[i]); // 기존 배열의 일차원 배열이 할당되었던 각 공간을 전부 free
	free(matrix); // 기존의 일차원 배열의 포인터를 저장했던 이차원 공간을 전부 free

	return a;
}