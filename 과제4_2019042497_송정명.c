#include <stdio.h>
#include <stdlib.h>

float res, value; // �Լ� �ȿ��� ��� �� ��� ����
void Menu() { // �޴� ��� �Լ�
	printf("----------------------------------------------\n");
	printf("1. add\n");
	printf("2. sub\n");
	printf("3. mul\n");
	printf("4. div\n");
	printf("0. exit\n");
	printf("----------------------------------------------\n");
	printf(">>> ");
}

float add(float a, float b) { // ���� �Լ�
	return res = a + b;
}

float sub(float a, float b) { // ���� �Լ�
	return res = a - b;
}

float mul(float a, float b) { // ���� �Լ�
	return res = a * b;
}

float div(float a, float b) { // ������ �Լ�
	return res = a / b;
}

float inputa() { // ���� �Է� �޴� �Լ�
	char val[1000]; // ����� ũ��� char�� �迭 ����
	while (true) { // ���ڸ� ����� ���� ������ ���� ����
		scanf("%s", val); // �� �Է� ����
		if (val[0] != '0' && atof(val) == 0) // ���ڰ� �ԷµǾ��� ��
			printf("Wrong input! Input again: ");
		else { // ���ڰ� �� �ԷµǾ��� ��
			value = atof(val); // ���ڿ��� �ִ� ���ڸ� float������ �ٲ� ��
			break; // ���ѷ��� Ż��
		}
	}
	return value;
}

int main() {
	char menu = '-1'; // ó�� while���� ����� ���ư��� ���� 0�� �ƴ� ���ڷ� �ʱ�ȭ��
	float first, second; // ����� �� ���� ���ڸ� ��� float�� ����
	int judge = 0; // ù ��° ������� �Ǵ����ִ� ����
	float result; // ���� ��� ���� ��� ����
	printf("----------------------------------------------\n");
	printf("\t\tLast Calculator\n");
	printf("----------------------------------------------\n");
	while (menu != '0') { // menu�� '0'�� �Էµ��� �ʾ��� �� ���� ���� ����
		Menu(); // �޴� ��� �Լ�
		scanf(" %c", &menu); // � ������ ������ ������, �Ǵ� ���ѷ����� ���� ������ �Է�
		switch (menu) { // menu�� �� ���� ���� ���� ��� ����
		case '1': // '1'�� �ԷµǾ��� ��
			if (!judge) { // ù ��° ����̸�
				printf("Input first operand: ");
				first = inputa(); // ����� ù ��° ���� �Է�
				printf("Input second operand: ");
				second = inputa(); // ����� �� ��° ���� �Է�
				result = add(first, second); // ���� �Լ� ���� �� ��� ���� result�� ����
				judge++; // ù ��° ����� ���Ʊ� ������ judge�� ���� 0�� �ƴϰ� �������
			}
			else { // ù ��° ����� �ƴϸ�
				printf("%0.4f + ", result); // ���� ����ߴ� ��� ���� ù ��° ���ڷ� ����
				second = inputa(); // ����� �� ��° ���� �Է�
				result = add(result, second); // ���� �Լ� ���� �� ��� ���� result�� ����
			}
			printf("Result is %0.4f\n", result); // ��� ��� ���� �Ҽ��� ��° �ڸ����� ���
			break; // switch case�� Ż��
		case '2': // '2'�� �ԷµǾ��� ��
			if (!judge) { // ù ��° ����̸�
				printf("Input first operand: ");
				first = inputa(); // ����� ù ��° ���� �Է�
				printf("Input second operand: ");
				second = inputa(); // ����� �� ��° ���� �Է�
				result = sub(first, second); // ���� �Լ� ���� �� ��� ���� result�� ����
				judge++; // ù ��° ����� ���Ʊ� ������ judge�� ���� 0�� �ƴϰ� �������
			}
			else { // ù ��° ����� �ƴϸ�
				printf("%0.4f - ", result); // ���� ����ߴ� ��� ���� ù ��° ���ڷ� ����
				second = inputa(); // ����� �� ��° ���� �Է�
				result = sub(result, second); // ���� �Լ� ���� �� ��� ���� result�� ����
			}
			printf("Result is %0.4f\n", result); // ��� ��� ���� �Ҽ��� ��° �ڸ����� ���
			break; // switch case�� Ż��
		case '3': // '3'�� �ԷµǾ��� ��
			if (!judge) { // ù ��° ����̸�
				printf("Input first operand: ");
				first = inputa(); // ����� ù ��° ���� �Է�
				printf("Input second operand: ");
				second = inputa(); // ����� �� ��° ���� �Է�
				result = mul(first, second); // ���� �Լ� ���� �� ��� ���� result�� ����
				judge++; // ù ��° ����� ���Ʊ� ������ judge�� ���� 0�� �ƴϰ� �������
			}
			else { // ù ��° ����� �ƴϸ�
				printf("%0.4f * ", result); // ���� ����ߴ� ��� ���� ù ��° ���ڷ� ����
				second = inputa(); // ����� �� ��° ���� �Է�
				result = mul(result, second); // ���� �Լ� ���� �� ��� ���� result�� ����
			}
			printf("Result is %0.4f\n", result); // ��� ��� ���� �Ҽ��� ��° �ڸ����� ���
			break; // switch case�� Ż��
		case '4': // '4'�� �ԷµǾ��� ��
			if (!judge) { // ù ��° ����̸�
				printf("Input first operand: ");
				first = inputa(); // ����� ù ��° ���� �Է�
				printf("Input second operand: ");
				second = inputa(); // ����� �� ��° ���� �Է�
				if (!second) { // �� ��° ���ڰ� 0�̸�
					printf("Can't divide by zero\n");
					break; // ��� �������� �ʰ� �ٽ� � �����Ұ��� �Է� ����
				}
				else { // �� ��° ���ڰ� 0�� �ƴϸ�
					result = div(first, second); // ������ �Լ� ���� �� ��� ���� result�� ����
					judge++; // ù ��° ����� ���Ʊ� ������ judge�� ���� 0�� �ƴϰ� �������
				}
			}
			else { // ù ��° ����� �ƴϸ�
				printf("%0.4f / ", result); // ���� ����ߴ� ��� ���� ù ��° ���ڷ� ����
				second = inputa(); // ����� �� ��° ���� �Է�
				if (!second) // �� ��° ���ڰ� 0�̸�
					printf("Can't divide by zero\n");
				else // �� ��° ���ڰ� 0�� �ƴϸ�
					result = div(result, second); // ������ �Լ� ���� �� ��� ���� result�� ����
			}
			printf("Result is %0.4f\n", result); // ��� ��� ���� �Ҽ��� ��° �ڸ����� ���
			break; // switch case�� Ż��
		case '0': // '0'�� �ԷµǾ��� ��
			printf("\nGood bye!");
			break; // switch case�� Ż��
		default: // �ٸ� ���� �ԷµǾ��� ��
			printf("Wrong command!\n");
			break; // switch case�� Ż��
		}
	}
	return 0;
}