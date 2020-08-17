#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int** rotate(int** matrix); // ȸ���� ũ�⿡ �´� ������ �迭�� ���� �����Ͽ� ���� ������ �ְ� ���� �迭�� �޸𸮴� �����ϰ� ���ο� �迭�� �����ϴ� �Լ�

int main()
{
	int sizeRow, sizeCol, n = 3; // ��� ���� ũ�� ���� ����, n=3�� 90,180,270�� ȸ���� ª�� �ڵ�� ǥ���ϱ� ���� ����, ����
	printf("Input row size of the matrix : ");
	scanf("%d", &sizeRow); // ���� ũ�� �Է� ����
	printf("Input column size of the matrix : ");
	scanf("%d", &sizeCol); // ���� ũ�� �Է� ����

	int** arr = NULL; // ���� ������ ���� ����
	arr = (int **)malloc(sizeRow * sizeof(int *)); // ������ �迭�� ��� ������ ���� ���� �Ҵ�
	for (int i = 0; i < sizeRow; i++) // ������ �迭�� ���� �Ҵ��ϱ� ���� for��
		arr[i] = (int*)malloc(sizeCol * sizeof(int)); // �� ������ �迭�� ���� �Ҵ�

	for (int i = 0; i < sizeRow; i++) // sizeRow�� ���� ũ���
		for (int j = 0; j < sizeCol; j++) // sizeCol�� ���� ũ���
			arr[i][j] = sizeCol * i + j + 1; // 1���� �������Ѽ� ���� ����

	printf("< degree : 0 >\n"); // ȸ����Ű�� �ʾ��� ��(0���� ��)
	for (int i = 0; i < sizeRow; i++) {
		for (int j = 0; j < sizeCol; j++)
			printf("%4d", arr[i][j]); // ȸ����Ű�� �ʾ��� ��(0���� ��)�� �� ���
		printf("\n");
	}

	int** arr1 = NULL; // ȸ����Ų �迭�� ������� ���� ������ ���� ����
	
	while (n--) { // 90��, 180��, 270�� ȸ���� ������ ǥ���ϱ� ���� n�� 2,1,0 ������ ������ ��
		printf("< degree : %d >\n", (3 - n) * 90); // n�� 2�� ��, 90��, n�� 1�� ��, 180��, n�� 0�� ��, 270��
		if (n % 2 == 1) { // 180�� ȸ���� ���� ���
			arr = rotate(arr1); // rotate �Լ��� �̿��� 180����ŭ ȸ���� ���� ���� ������ ������ ����
			for (int i = 0; i < sizeRow; i++) { // 180���� ���� �� ũ�⸸ŭ for�� ����
				for (int j = 0; j < sizeCol; j++) // 180���� ���� �� ũ�⸸ŭ for�� ����
					printf("%4d", arr[i][j]);  // 180���� ���� �� ���
				printf("\n");
			}
		}
		else { // 90��, 270�� ȸ���� ���� ���
			arr1 = rotate(arr); // rotate �Լ��� �̿��� 90, 270����ŭ ȸ���� ���� ���� ������ ������ ����
			for (int i = 0; i < sizeCol; i++) { // 90, 270���� ���� �� ũ�⸸ŭ for�� ����
				for (int j = 0; j < sizeRow; j++) // 90, 270���� ���� �� ũ�⸸ŭ for�� ����
					printf("%4d", arr1[i][j]); // 90��, 270���� ���� �� ���
				printf("\n");
			}
		}
	}
	
	for (int i = 0; i < sizeRow; i++)
		free(arr1[i]); // ������ �迭�� �Ҵ�Ǿ��� �� ������ ���� free
	free(arr1); // ������ �迭�� �����͸� �����ߴ� ������ ������ ���� free

	return 0;
}

int** rotate(int** matrix) { // ȸ���� ũ�⿡ �´� ������ �迭�� ���� �����Ͽ� ���� ������ �ְ� ���� �迭�� �޸𸮴� �����ϰ� ���ο� �迭�� �����ϴ� �Լ�
	int row = _msize(matrix[0]) / sizeof(int); // �Ű������� ���� �迭�� ���� ũ�� == ȸ���� �迭�� ���� ũ��
	int col = _msize(matrix) / sizeof(int); // �Ű������� ���� �迭�� ���� ũ�� == ȸ���� �迭�� ���� ũ��

	int** a = NULL; // ȸ���� �迭�� ���� ���� ������ ���� ����
	a = (int **)malloc(row * sizeof(int *)); // ������ �迭�� ��� ������ ���� ���� �Ҵ�
	for (int i = 0; i < row; i++) // ������ �迭�� ���� �Ҵ��ϱ� ���� for��
		a[i] = (int*)malloc(col * sizeof(int)); // �� ������ �迭�� ���� �Ҵ�

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			a[i][j] = matrix[col - 1 - j][i]; // ���� �迭�� ���� 90����ŭ ȸ���Ͽ� ���ο� �迭�� ����
		}
	}

	for (int i = 0; i < col; i++)
		free(matrix[i]); // ���� �迭�� ������ �迭�� �Ҵ�Ǿ��� �� ������ ���� free
	free(matrix); // ������ ������ �迭�� �����͸� �����ߴ� ������ ������ ���� free

	return a;
}