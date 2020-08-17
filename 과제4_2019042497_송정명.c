#include <stdio.h>
#include <stdlib.h>

float res, value; // 함수 안에서 결과 값 담는 변수
void Menu() { // 메뉴 출력 함수
	printf("----------------------------------------------\n");
	printf("1. add\n");
	printf("2. sub\n");
	printf("3. mul\n");
	printf("4. div\n");
	printf("0. exit\n");
	printf("----------------------------------------------\n");
	printf(">>> ");
}

float add(float a, float b) { // 덧셈 함수
	return res = a + b;
}

float sub(float a, float b) { // 뺄셈 함수
	return res = a - b;
}

float mul(float a, float b) { // 곱셈 함수
	return res = a * b;
}

float div(float a, float b) { // 나눗셈 함수
	return res = a / b;
}

float inputa() { // 숫자 입력 받는 함수
	char val[1000]; // 충분한 크기로 char형 배열 선언
	while (true) { // 숫자를 제대로 받을 때까지 무한 루프
		scanf("%s", val); // 값 입력 받음
		if (val[0] != '0' && atof(val) == 0) // 문자가 입력되었을 때
			printf("Wrong input! Input again: ");
		else { // 숫자가 잘 입력되었을 때
			value = atof(val); // 문자열에 있는 숫자를 float형으로 바꿔 줌
			break; // 무한루프 탈출
		}
	}
	return value;
}

int main() {
	char menu = '-1'; // 처음 while문이 제대로 돌아가기 위해 0이 아닌 숫자로 초기화함
	float first, second; // 계산할 때 들어가는 숫자를 담는 float형 변수
	int judge = 0; // 첫 번째 계산인지 판단해주는 변수
	float result; // 연산 결과 값을 담는 변수
	printf("----------------------------------------------\n");
	printf("\t\tLast Calculator\n");
	printf("----------------------------------------------\n");
	while (menu != '0') { // menu에 '0'이 입력되지 않았을 때 무한 루프 진행
		Menu(); // 메뉴 출력 함수
		scanf(" %c", &menu); // 어떤 연산을 진행할 것인지, 또는 무한루프를 끝낼 것인지 입력
		switch (menu) { // menu에 들어간 값에 따라 여러 경우 진행
		case '1': // '1'이 입력되었을 때
			if (!judge) { // 첫 번째 계산이면
				printf("Input first operand: ");
				first = inputa(); // 계산할 첫 번째 숫자 입력
				printf("Input second operand: ");
				second = inputa(); // 계산할 두 번째 숫자 입력
				result = add(first, second); // 덧셈 함수 실행 후 결과 값을 result에 대입
				judge++; // 첫 번째 계산을 마쳤기 때문에 judge의 값을 0이 아니게 만들어줌
			}
			else { // 첫 번째 계산이 아니면
				printf("%0.4f + ", result); // 전에 계산했던 결과 값을 첫 번째 숫자로 놔둠
				second = inputa(); // 계산할 두 번째 숫자 입력
				result = add(result, second); // 덧셈 함수 실행 후 결과 값을 result에 대입
			}
			printf("Result is %0.4f\n", result); // 계산 결과 값을 소수점 넷째 자리까지 출력
			break; // switch case문 탈출
		case '2': // '2'가 입력되었을 때
			if (!judge) { // 첫 번째 계산이면
				printf("Input first operand: ");
				first = inputa(); // 계산할 첫 번째 숫자 입력
				printf("Input second operand: ");
				second = inputa(); // 계산할 두 번째 숫자 입력
				result = sub(first, second); // 뺄셈 함수 실행 후 결과 값을 result에 대입
				judge++; // 첫 번째 계산을 마쳤기 때문에 judge의 값을 0이 아니게 만들어줌
			}
			else { // 첫 번째 계산이 아니면
				printf("%0.4f - ", result); // 전에 계산했던 결과 값을 첫 번째 숫자로 놔둠
				second = inputa(); // 계산할 두 번째 숫자 입력
				result = sub(result, second); // 뺄셈 함수 실행 후 결과 값을 result에 대입
			}
			printf("Result is %0.4f\n", result); // 계산 결과 값을 소수점 넷째 자리까지 출력
			break; // switch case문 탈출
		case '3': // '3'이 입력되었을 때
			if (!judge) { // 첫 번째 계산이면
				printf("Input first operand: ");
				first = inputa(); // 계산할 첫 번째 숫자 입력
				printf("Input second operand: ");
				second = inputa(); // 계산할 두 번째 숫자 입력
				result = mul(first, second); // 곱셈 함수 실행 후 결과 값을 result에 대입
				judge++; // 첫 번째 계산을 마쳤기 때문에 judge의 값을 0이 아니게 만들어줌
			}
			else { // 첫 번째 계산이 아니면
				printf("%0.4f * ", result); // 전에 계산했던 결과 값을 첫 번째 숫자로 놔둠
				second = inputa(); // 계산할 두 번째 숫자 입력
				result = mul(result, second); // 곱셈 함수 실행 후 결과 값을 result에 대입
			}
			printf("Result is %0.4f\n", result); // 계산 결과 값을 소수점 넷째 자리까지 출력
			break; // switch case문 탈출
		case '4': // '4'가 입력되었을 때
			if (!judge) { // 첫 번째 계산이면
				printf("Input first operand: ");
				first = inputa(); // 계산할 첫 번째 숫자 입력
				printf("Input second operand: ");
				second = inputa(); // 계산할 두 번째 숫자 입력
				if (!second) { // 두 번째 숫자가 0이면
					printf("Can't divide by zero\n");
					break; // 계산 진행하지 않고 다시 어떤 연산할건지 입력 받음
				}
				else { // 두 번째 숫자가 0이 아니면
					result = div(first, second); // 나눗셈 함수 실행 후 결과 값을 result에 대입
					judge++; // 첫 번째 계산을 마쳤기 때문에 judge의 값을 0이 아니게 만들어줌
				}
			}
			else { // 첫 번째 계산이 아니면
				printf("%0.4f / ", result); // 전에 계산했던 결과 값을 첫 번째 숫자로 놔둠
				second = inputa(); // 계산할 두 번째 숫자 입력
				if (!second) // 두 번째 숫자가 0이면
					printf("Can't divide by zero\n");
				else // 두 번째 숫자가 0이 아니면
					result = div(result, second); // 나눗셈 함수 실행 후 결과 값을 result에 대입
			}
			printf("Result is %0.4f\n", result); // 계산 결과 값을 소수점 넷째 자리까지 출력
			break; // switch case문 탈출
		case '0': // '0'이 입력되었을 때
			printf("\nGood bye!");
			break; // switch case문 탈출
		default: // 다른 값이 입력되었을 때
			printf("Wrong command!\n");
			break; // switch case문 탈출
		}
	}
	return 0;
}