#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <random>

void printMenu(); // 메뉴를 출력하는 함수
int* newTicket(); // int형 변수 6개가 들어가는 일차원배열을 동적할당 생성해서 중복 없는 1~45 범위의 6개 숫자를 오름차순으로 저장한 후 리턴하는 함수
int winTicket(int ans[], int* com); // 정답 번호의 배열과 구매한 티켓 번호의 배열이 같은지 비교하고 등수를 출력하는 함수

int main()
{
	int answer[7], seven = 0; // 정답 번호의 배열, 정답 번호에 중복 없는 숫자를 넣기 위해 while문을 돌릴 때 종료 조건으로 사용하기 위해 만든 변수
	int ticket = 0, win[5] = { 0, }, money = 0; // 구매한 티켓의 수, 등수 별로 몇 번 했는지 담는 배열, 복권 당첨 총 금액
	srand(time(NULL)); // 항상 똑같은 수가 나오지 않도록 난수 생성 규칙 변경
	while (seven != 7) { // 7개의 번호가 생성되면 반목문 종료
		int judge = 0, n = rand() % 45 + 1; // 중복된 숫자인지 판단하기 위해 만든 변수, 임시로 1~45 범위의 난수를 받아두는 변수
		for (int i = 0; i < seven; i++) { // 지금까지 생성한 정답 번호의 수만큼 for문 돌림
			if (answer[i] == n) { // 지금까지 생성한 정답 번호와 임시로 받은 변수의 값을 비교, 같으면
				judge++; // 판단하기 위한 변수의 값 증가시킨 후
				break; // for문 탈출
			}
		}
		if (judge == 0) { // 판단하기 위한 변수가 그대로 0이라면
			answer[seven] = n; // 임시로 저장했던 값을 다음 정답 번호로 넣어주고
			seven++; // 탈출 조건의 값 1 증가
		}
	}
	for (int i = 0; i < 6; i++) { // 오름차순으로 정렬하기 위한 이중 for문
		for (int j = i; j < 6; j++) {
			if (answer[i] > answer[j]) {
				int temp = answer[i];
				answer[i] = answer[j];
				answer[j] = temp;
			}
		}
	}
	printf("당첨 번호 : ");
	for (int i = 0; i < 6; i++) // 정답 번호 출력
		printf("%d ", answer[i]);
	printf("보너스 : %d", answer[6]); // 보너스 번호 출력
	printf("\n");
	int** bok = NULL; // 전체 구매 티켓 목록을 담을 이중 포인터 변수 선언
	while (1) {
		char num; // 문자 입력도 예외처리하기 위해 char형으로 선언
		printMenu(); // 메뉴 출력
		scanf(" %c", &num); // 메뉴에서 무엇을 실행할지 입력 받음
		if (num == '1') { // 1을 입력했을 때
			int n; // 추가 구매할 티켓 수
			printf("How many lines will you buy? : ");
			scanf("%d", &n); // 몇 장의 티켓을 추가로 구매할지 입력 받음
			if (ticket == 0) { // 지금까지 구매한 티켓이 없을 때
				bok = (int **)malloc(n * sizeof(int *)); // 일차원 배열(번호들)이 담길 이차원 공간(티켓의 수) 동적 할당
				for (int i = 0; i < n; i++) // 일차원 배열(번호들)을 동적 할당하기 위한 for문
					bok[i] = (int*)malloc(6 * sizeof(int)); // 각 일차원 배열(번호들) 동적 할당
			}
			else { // 지금까지 구매한 티켓이 있을 때
				bok = (int **)realloc(bok, (ticket + n) * sizeof(int*)); // 일차원 배열(번호들)이 담길 이차원 공간(티켓의 수)를 늘려 동적 할당
				for (int i = ticket; i < ticket + n; i++) // 일차원 배열(번호들)을 동적 할당하기 위한 for문
					bok[i] = (int*)malloc(6 * sizeof(int)); // 각 일차원 배열(번호들) 동적 할당
			}
			for (int i = ticket; i < ticket + n; i++)
				bok[i] = newTicket(); // 전체 구매 티켓 목록에 있는 각 티켓에 6개의 중복 없는 임의의 수를 넣음
			for (int i = 0; i < ticket + n; i++) { // 티켓 번호와 그 안의 6개의 번호들 출력
				printf("tikect %d : ", i + 1);
				for (int j = 0; j < 6; j++)
					printf("%3d", bok[i][j]);
				if (winTicket(answer, bok[i]) != 0) // 만약 당첨이 되었다면
					printf("  축!! %d등!!", winTicket(answer, bok[i])); // 몇 등인지 같이 출력
				printf("\n");
			}
			for (int i = ticket; i < ticket + n; i++) { // 새로 구매한 티켓의 범위 만큼 for문
				if (winTicket(answer, bok[i]) == 1) { // 1등이 나왔다면
					win[0]++; // 1등 한 횟수 1 증가
					money += 2000000000; // 1등 당첨 금액만큼 증가
				}
				else if (winTicket(answer, bok[i]) == 2) { // 2등이 나왔다면
					win[1]++; // 2등 한 횟수 1 증가
					money += 100000000; // 2등 당첨 금액만큼 증가
				}
				else if (winTicket(answer, bok[i]) == 3) { // 3등이 나왔다면
					win[2]++; // 3등 한 횟수 1 증가
					money += 2000000; // 3등 당첨 금액만큼 증가
				}
				else if (winTicket(answer, bok[i]) == 4) { // 4등이 나왔다면
					win[3]++; // 4등 한 횟수 1 증가
					money += 50000; // 4등 당첨 금액만큼 증가
				}
				else if (winTicket(answer, bok[i]) == 5) { // 5등이 나왔다면
					win[4]++; // 5등 한 횟수 1 증가
					money += 5000; // 5등 당첨 금액만큼 증가
				}
			}
			ticket += n; // 총 티켓 수 = 이전 티켓 수 + 새로 산 티켓 수
		}
		else if (num == '2') // 2을 입력했을 때
			printf("You bought %d tickets, and the total cost is %d won\n", ticket, ticket * 1000); // 구매한 티켓 수와 구매할 때 쓴 금액 출력
		else if (num == '3') { // 3을 입력했을 때
			for (int i = 0; i < 5; i++)
				if (win[i] != 0) // 당첨이 한 번이라도 되었다면
					printf("%d등 : %d번\n", i + 1, win[i]); // 당첨된 티켓의 순위와 횟수 출력
			printf("You earned %d won\n", money); // 당첨된 총 금액 출력
		}
		else if (num == '4') { // 4을 입력했을 때
			char sure; // 진짜 진행할건지 입력 받는 변수
			printf("Are you sure? (y or n) : ");
			scanf(" %c", &sure); // 진짜 진행할건지 입력
			int win1 = 0, ticket1 = 0, money1 = 0; // 4번이 실행되는 동안에 4등 이상이 나왔는지 세는 변수, 4번이 진행되는 동안 구매한 티켓의 수, 4번이 진행되는 동안 당첨된 총 금액
			if (sure == 'y') { // 진짜 진행할 때
				while (win1 == 0) { // 종료 조건 : 4번이 실행되는 동안 4등 이상이 당첨될 때
					ticket1++; // 티켓 구매할 때 1 증가
					bok = (int **)realloc(bok, (ticket + ticket1) * sizeof(int *)); // 일차원 배열(번호들)이 담길 이차원 공간(티켓의 수)를 늘려 동적 할당
					bok[(ticket + ticket1) - 1] = (int*)malloc(6 * sizeof(int)); // 새로 구매한 티켓의 일차원 배열(번호들) 동적 할당
					bok[(ticket + ticket1) - 1] = newTicket(); // 새로 구매한 티켓에 6개의 중복 없는 임의의 수를 넣음
					if (winTicket(answer, bok[(ticket + ticket1) - 1]) == 1) { // 새로 구매한 티켓이 1등이 나왔다면
						win1++; // 4등 이상이므로 탈출하기 위해 1증가
						win[0]++; // 1등 한 횟수 1 증가
						money1 += 2000000000; // 1등 당첨 금액만큼 증가
						printf("축! 1등 당첨\n");
					}
					else if (winTicket(answer, bok[(ticket + ticket1) - 1]) == 2) { // 새로 구매한 티켓이 2등이 나왔다면
						win1++; // 4등 이상이므로 탈출하기 위해 1증가
						win[1]++; // 2등 한 횟수 1 증가
						money1 += 100000000; // 2등 당첨 금액만큼 증가
						printf("축! 2등 당첨\n");
					}
					else if (winTicket(answer, bok[(ticket + ticket1) - 1]) == 3) { // 새로 구매한 티켓이 3등이 나왔다면
						win1++; // 4등 이상이므로 탈출하기 위해 1증가
						win[2]++; // 3등 한 횟수 1 증가
						money1 += 2000000; // 3등 당첨 금액만큼 증가
						printf("축! 3등 당첨\n");
					}
					else if (winTicket(answer, bok[(ticket + ticket1) - 1]) == 4) { // 새로 구매한 티켓이 4등이 나왔다면
						win1++; // 4등 이상이므로 탈출하기 위해 1증가
						win[3]++; // 4등 한 횟수 1 증가
						money1 += 50000; // 4등 당첨 금액만큼 증가
						printf("축! 4등 당첨\n");
					}
					else if (winTicket(answer, bok[(ticket + ticket1) - 1]) == 5) { // 새로 구매한 티켓이 5등이 나왔다면
						win[4]++; // 5등 한 횟수 1 증가
						money1 += 5000; // 1등 당첨 금액만큼 증가
					}
				}
				printf("You bought %d tickets, and the total cost is %d won\n", ticket1, ticket1 * 1000); // 4번이 진행될 동안 구매한 티켓 수와 구매할 때 쓴 금액 출력
				printf("You earned %d won\n", money1); // 4번이 진행될 동안 당첨된 총 금액 출력
				ticket += ticket1; // 총 티켓 수 = 이전 티켓 수 + 4번이 진행될 동안 새로 산 티켓 수
				money += money1; // 총 당첨 금액 = 이전 당첨 금액 + 4번이 진행될 동안 당첨된 총 금액
			}
		}
		else if (num == '0') { // 0을 입력했을 때
			printf("bye");
			for (int i = 0; i < ticket; i++)
				free(bok[i]); // 일차원 배열이 할당되었던 각 공간을 전부 free
			free(bok); // 일차원 배열의 포인터를 저장했던 이차원 공간을 전부 free
			break; // while문 탈출
		}
		else // 1,2,3,4,0 이외의 값을 입력했을 때
			printf("input error\n");
	}
	return 0;
}

void printMenu() { // 메뉴를 출력하는 함수
	printf("----------- Lottery  Ticket -----------\n");
	printf("---------------------------------------\n");
	printf("1. Buy tickets\n");
	printf("2. Spent money\n");
	printf("3. Earned money\n");
	printf("4. Buy until I get 4th or higher prize\n");
	printf("0. exit\n");
	printf("---------------------------------------\n");
}

int* newTicket() { // int형 변수 6개가 들어가는 일차원배열을 동적할당 생성해서 중복 없는 1~45 범위의 6개 숫자를 오름차순으로 저장한 후 리턴하는 함수
	int six = 0; // 티켓 번호에 중복 없는 숫자를 넣기 위해 while문을 돌릴 때 종료 조건으로 사용하기 위해 만든 변수
	int* a = NULL; // 구매한 티켓에 번호를 담을 포인터 변수 선언
	a = (int *)malloc(6 * sizeof(int)); // 일차원 배열(번호들) 동적 할당
	while (six != 6) { // 6개의 번호가 생성되면 반목문 종료
		int judge = 0, n = rand() % 45 + 1; // 중복된 숫자인지 판단하기 위해 만든 변수, 임시로 1~45 범위의 난수를 받아두는 변수
		for (int i = 0; i < six; i++) {// 지금까지 생성한 번호의 수만큼 for문 돌림
			if (a[i] == n) { // 지금까지 생성한 번호와 임시로 받은 변수의 값을 비교, 같으면
				judge++; // 판단하기 위한 변수의 값 증가시킨 후
				break; // for문 탈출
			}
		}
		if (judge == 0) { // 판단하기 위한 변수가 그대로 0이라면
			a[six] = n; // 임시로 저장했던 값을 다음 번호로 넣어주고
			six++; // 탈출 조건의 값 1 증가
		}
	}
	for (int i = 0; i < 6; i++) { // 오름차순으로 정렬하기 위한 이중 for문
		for (int j = i; j < 6; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	return a;
}

int winTicket(int ans[], int* com) { // 정답 번호의 배열과 구매한 티켓 번호의 배열이 같은지 비교하고 등수를 출력하는 함수
	int count = 0, lotto = 0; // 정답 번호와 같은 번호가 몇 개인지 담는 변수, 보너스 번호와 같은 번호가 있는지 담는 변수
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (ans[i] == com[j]) { // 정답 번호 중 하나와 구매한 티켓 번호 중 하나가 같다면
				count++; // 같은 번호의 개수를 담는 변수를 1 증가
				break; // for문 하나만 탈출(이미 찾았으니 이 번호는 뒷 번호를 볼 필요 x)
			}
		}
	}
	for (int i = 0; i < 6; i++)
		if (ans[6] == com[i]) // 보너스 번호와 구매한 티켓 번호 중 하나가 같다면
			lotto++; // 보너스 번호가 있는지 판단하는 변수의 값을 1 증가
	if (count == 6) // 6개 숫자 정답일 때
		return 1; // 1등이므로 1 반환
	else if (count == 5 && lotto == 1) // 5개 숫자 정답 + 보너스 번호 정답일 때
		return 2; // 2등이므로 2 반환
	else if (count == 5) // 5개 숫자 정답 + 보너스 번호 정답 아닐 때
		return 3; // 3등이므로 3 반환
	else if (count == 4) // 4개 숫자 정답일 때
		return 4; // 4등이므로 4 반환
	else if (count == 3) // 3개 숫자 정답일 때
		return 5; // 5등이므로 5 반환
	else // 당첨이 아닐 때
		return 0; // 0 반환
}