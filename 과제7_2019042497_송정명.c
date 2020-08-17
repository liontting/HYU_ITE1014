#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct _time { // 음악의 길이(분, 초)를 담는 구조체
	int minute;
	int second;
} Time;

typedef struct _song { // 음악의 정보(제목, 가수, 곡의 길이)를 담는 구조체
	char title[100];
	char artist[100];
	Time length;
} Song;

typedef struct _songList { // 음악 리스트를 담는 구조체
	Song *songs; // 음악의 정보
	int size; // 실제 들어있는 음악의 수
	int capacity; // 배열의 크기
} SongList;

SongList dataLoad(); // 파일 안의 데이터를 읽어오는 함수
int dataSave(SongList); // 구조체 안에 있는 음악 리스트를 파일 안에 덮어쓰며 저장하기 위한 함수
void printMenu(); // 메뉴를 출력하는 함수
void printSong(Song*); // 선택한 음악의 정보를 출력하는 함수
void printSongMenu(); // 메뉴의 1번 안의 음악 수정, 삭제, 이전 메뉴를 출력하는 함수
Song* searchSong(SongList, char*, char*); // 음악 리스트 안에 음악이 있는지 찾는 함수
int editSong(Song*); // 선택한 음악의 정보를 수정하는 함수
int deleteSong(SongList*, Song*); // 음악 리스트에서 선택한 음악을 지우는 함수
int addSong(SongList*); // 새로운 음악을 음악 리스트에 추가하는 함수
void printAllSongs(SongList); // 음악 리스트에 있는 음악들을 출력하는 함수
int deleteAll(SongList*); // 음악 리스트에 있는 음악들을 모두 삭제하는 함수

int main()
{
	SongList songlist; // 파일 안의 음악 리스트를 불러와 담을 구조체
	printf("----- Mini Music Library -----\n\n");
	songlist = dataLoad(); // 선언한 구조체에 파일 안의 음악 리스트와 정보를 담음
	while (1) {
		int num; // 메뉴에서 몇 번을 고를 것인지 담는 변수
		char ch; // 버퍼에 남은 잘못 입력된 문자를 처리하기 위한 변수
		printMenu(); // 메뉴 출력
		while (scanf(" %d", &num) != 1) { // 변수에 메뉴에서 몇 번을 고를 것인지 받으면서 문자를 입력 받는 것을 걸러줌
			while ((ch = getchar()) != '\n'); // 버퍼 안의 값을 비움
			printf("Wrong input\n");
			printMenu();
		}
		if (num == 1) { // 1번 메뉴를 선택했을 때
			int n; // 메뉴의 1번 안의 메뉴에서 몇 번을 고를 것인지 담는 변수
			char title[100] = { 0, }, artist[100] = { 0, }; // 선택할 음악의 제목, 가수를 담는 배열
			Song* sng; // 선택한 음악을 담는 구조체
			printf("Input title: ");
			scanf(" %[^\n]s", title); // 변수에 선택할 음악의 제목을 담음
			printf("Input artist: ");
			scanf(" %[^\n]s", artist); // 변수에 선택할 음악의 가수를 담음
			sng = searchSong(songlist, title, artist); // 음악 리스트에서 선택한 음악을 찾아서 변수에 담음
			if (sng != 0) { // 음악 리스트 안에 음악이 있을 때
				printSong(sng); // 선택한 음악의 정보를 출력
				while (1) {
					printSongMenu(); // 메뉴의 1번 안의 음악 수정, 삭제, 이전 메뉴를 출력
					while (scanf(" %d", &n) != 1) { // 변수에 수정, 삭제, 이전 메뉴에서 몇 번을 고를 것인지 받으면서 문자를 입력 받는 것을 걸러줌
						while ((ch = getchar()) != '\n'); // 버퍼 안의 값을 비움
						printf("Wrong input\n");
						printSongMenu();
					}
					if (n == 1) { // 1번을 골랐을 때
						editSong(sng); // 선택한 음악의 정보를 수정
						break;
					}
					else if (n == 2) { // 2번을 골랐을 때
						deleteSong(&songlist, sng); // 음악 리스트에서 선택한 음악을 지움
						break;
					}
					else if (n == 0) // 0번을 골랐을 때
						break;
					else // 잘못 입력했을 때
						printf("wrong input\n");
				}
			}
			else // 음악 리스트 안에 음악이 없을 때
				printf("Wrong input!\n");
		}
		else if (num == 2) // 2번 메뉴를 선택했을 때
			addSong(&songlist); // 새로운 음악을 음악 리스트에 추가
		else if (num == 3) // 3번 메뉴를 선택했을 때
			printAllSongs(songlist); // 음악 리스트에 있는 음악들을 출력
		else if (num == 4) // 4번 메뉴를 선택했을 때
			deleteAll(&songlist); // 음악 리스트에 있는 음악들을 모두 삭제
		else if (num == 0) { // 0번 메뉴를 선택했을 때
			dataSave(songlist); // 구조체 안에 있는 음악 리스트를 파일 안에 덮어쓰며 저장
			break;
		}
		else // 메뉴에 없는 것을 입력했을 때
			printf("Wrong input\n");
	}
	free(songlist.songs); // 동적할당되었던 각 공간을 전부 free
	return 0;
}

SongList dataLoad() { // 파일 안의 데이터를 읽어오는 함수
	int num = 0; // 음악의 개수를 받는 변수
	SongList snglist; // 파일 안의 음악 리스트를 불러와 담을 구조체 선언
	FILE *f = fopen("input.txt", "r"); // 읽기 모드로 파일 열기
	if (f == NULL) { // input.txt 파일이 없을 때
		FILE *f = fopen("input.txt", "a"); // input.txt 파일을 추가
		snglist.songs = (Song*)malloc(num * sizeof(Song)); // 음악의 개수만큼 동적할당함(나중에 realloc을 위해)
		snglist.capacity = snglist.size = 0; // 음악의 개수인 0을 음악 리스트 안의 정보에 넣음
		fprintf(f, "0"); // 음악의 개수인 0 적어둠
		fclose(f); // 파일을 닫음
	}
	else { // input.txt 파일이 있을 때
		fscanf(f, " %d", &num); // 가장 먼저 있는 음악의 개수 읽어옴
		snglist.songs = (Song*)malloc(num * sizeof(Song)); // 음악의 개수만큼 동적할당함
		snglist.capacity = snglist.size = num; // 음악의 개수를 음악 리스트 안의 정보에 넣음
		for (int i = 0; i < num; i++) { // for문을 음악의 개수만큼 반복
			fscanf(f, " %d %d", &snglist.songs[i].length.minute, &snglist.songs[i].length.second); // 곡의 길이(분, 초)를 읽어옴
			fscanf(f, " %[^\n]s", snglist.songs[i].title); // 곡의 제목을 읽어옴
			fscanf(f, " %[^\n]s", snglist.songs[i].artist); // 곡의 가수를 읽어옴
		}
		fclose(f); // 파일을 닫음
	}
	printf("... Data load success\n");
	return snglist; // 음악 리스트 return
}

int dataSave(SongList snglist) { // 구조체 안에 있는 음악 리스트를 파일 안에 덮어쓰며 저장하기 위한 함수
	FILE *f = fopen("input.txt", "w"); // 파일을 덮어 쓰는 모드로 파일을 열기
	fprintf(f, "%d\n", snglist.size); // 음악의 개수 먼저 파일에 적음
	for (int i = 0; i < snglist.capacity; i++) { // for문을 배열의 크기만큼 돌림
		if (snglist.songs[i].length.minute != 0 || snglist.songs[i].length.second != 0) { // 음악의 길이가 0m 0s이 아니면
			fprintf(f, "%d %d\n", snglist.songs[i].length.minute, snglist.songs[i].length.second); // 음악의 길이를 파일에 적음
			fprintf(f, "%s\n", snglist.songs[i].title); // 음악의 제목 파일에 적음
			fprintf(f, "%s\n", snglist.songs[i].artist); // 음악의 가수 파일에 적음
		}
	}
	fclose(f); // 파일을 닫음
	printf("... Data save success\n");
	return 0;
}

void printMenu() { // 메뉴를 출력하는 함수
	printf("------------------------------\n");
	printf("1. Search\n");
	printf("2. New song\n");
	printf("3. Print all\n");
	printf("4. Delete all\n");
	printf("0. Exit\n");
	printf("------------------------------\n");
	printf(">>> ");
}

void printSong(Song* sng) { // 선택한 음악의 정보를 출력하는 함수
	printf("\n");
	printf("Title  : %s\n", sng->title);
	printf("Artist : %s\n", sng->artist);
	printf("Length : %d min %d sec\n", sng->length.minute, sng->length.second);
	printf("\n");
}

void printSongMenu() { // 메뉴의 1번 안의 음악 수정, 삭제, 이전 메뉴를 출력하는 함수
	printf("------------------------------\n");
	printf("1. Edit\n");
	printf("2. Delete\n");
	printf("0. Previous\n");
	printf("------------------------------\n");
	printf(">>> ");
}

Song* searchSong(SongList snglist, char* tle, char* tist) { // 음악 리스트 안에 음악이 있는지 찾는 함수
	for (int i = 0; i < snglist.capacity; i++) // for문을 배열의 크기만큼 돌림
		if (!strcmp(snglist.songs[i].title, tle) && !strcmp(snglist.songs[i].artist, tist)) // 음악의 제목과 가수가 같다면
			return &snglist.songs[i]; // 그 음악 정보 return
	return 0;
}

int editSong(Song* sng) { // 선택한 음악의 정보를 수정하는 함수
	int min = 0, sec = 0; // 수정할 음악의 길이 (분, 초) 담는 변수
	char ti[100] = { 0, }, ar[100] = { 0, }; // 수정할 음악의 제목과 가수를 담는 배열
	printf("Input new title: ");
	scanf(" %[^\n]s", ti); // 수정할 제목 입력
	printf("Input new artist: ");
	scanf(" %[^\n]s", ar); // 수정할 가수 입력
	strcpy(sng->title, ti); // 제목 수정
	strcpy(sng->artist, ar); // 가수 수정
	while (1) {
		printf("Input new length\n");
		printf("        minute: ");
		scanf(" %d", &min); // 수정할 음악의 길이(분) 입력
		printf("        second: ");
		scanf(" %d", &sec); // 수정할 음악의 길이(초) 입력
		if (min >= 0 && sec >= 0 && sec < 60 && (min != 0 || sec != 0)) // 분,초가 음수이거나 60이상의 초거나 0m 0s인 경우가 아닐 때
			break; // while문 나감
		else // 분,초가 음수이거나 60이상의 초거나 0m 0s인 경우일 때
			printf("Wrong input about time\n");
	}
	sng->length.minute = min; // 음악의 길이(분) 수정
	sng->length.second = sec; // 음악의 길이(초) 수정
	return 0;
}

int deleteSong(SongList* sl, Song* sng) { // 음악 리스트에서 선택한 음악을 지우는 함수
	sl->size -= 1; // 음악의 개수 하나 줄임
	strcpy(sng->title, ""); // 제목 없앰
	strcpy(sng->artist, ""); // 가수 없앰
	sng->length.minute = 0; // 분 0으로 함
	sng->length.second = 0; // 초 0으로 함
	printf("\n... delete success\n");
	return 0;
}

int addSong(SongList* snglist) { // 새로운 음악을 음악 리스트에 추가하는 함수
	int cnt = 0, min, sec; // 음악의 길이가 제대로 입력되었는지 확인하는 변수, 추가할 음악의 길이 (분, 초) 담는 변수
	char ti[100] = { 0, }, ar[100] = { 0, }; // 추가할 음악의 제목, 가수 담는 배열
	printf("Input title: ");
	scanf(" %[^\n]s", ti); // 추가할 음악의 제목 입력
	printf("Input artist: ");
	scanf(" %[^\n]s", ar); // 추가할 음악의 가수 입력
	for (int i = 0; i < snglist->capacity; i++) { // for문을 배열의 크기만큼 돌림
		if (!strcmp(snglist->songs[i].title, ti) && !strcmp(snglist->songs[i].artist, ar)) { // 이미 같은 제목, 가수의 노래가 존재할 때
			printf("Same song already exists\n");
			return 0;
		}
	}
	printf("Input length\n");
	printf("        minute: ");
	scanf(" %d", &min); // 추가할 음악의 길이(분) 입력
	printf("        second: ");
	scanf(" %d", &sec); // 추가할 음악의 길이(초) 입력
	if (min < 0 || sec < 0 || sec >= 60 || (min == 0 && sec == 0)) // 분,초가 음수이거나 60이상의 초거나 0m 0s인 경우일 때
		cnt++; // 변수의 값 증가
	if (cnt == 0) { // 음악의 길이(분, 초)가 제대로 입력이 되었을 때
		snglist->capacity += 1; // 배열의 크기 증가
		snglist->size += 1; // 음악의 개수 증가
		snglist->songs = (Song*)realloc(snglist->songs, snglist->capacity * sizeof(Song)); // 늘린 배열의 크기만큼 동적할당함
		strcpy(snglist->songs[snglist->capacity - 1].title, ti); // 추가할 음악의 제목을 입력
		strcpy(snglist->songs[snglist->capacity - 1].artist, ar); // 추가할 음악의 가수를 입력
		snglist->songs[snglist->capacity - 1].length.minute = min; // 추가할 음악의 길이(분) 입력
		snglist->songs[snglist->capacity - 1].length.second = sec; // 추가할 음악의 길이(초) 입력
		printf("... add success\n");
	}
	else // 음악의 길이(분, 초)가 제대로 입력이 되지 않았을 때
		printf("Wrong input about time\n");
	return 0;
}

void printAllSongs(SongList snglist) { // 음악 리스트에 있는 음악들을 출력하는 함수
	printf("\n");
	if (snglist.size == 0) // 음악의 개수가 0일 때
		printf("No result\n");
	else // 음악의 개수가 0이 아닐 때
		for (int i = 0; i < snglist.capacity; i++) // for문을 배열의 개수만큼 돌림
			if (snglist.songs[i].length.minute != 0 || snglist.songs[i].length.second != 0) // 음악의 길이가 0m 0s이 아니면
				printf("%s - %s (%d:%d)\n", snglist.songs[i].artist, snglist.songs[i].title, snglist.songs[i].length.minute, snglist.songs[i].length.second); // 음악 출력
	printf("\n");
}

int deleteAll(SongList* sng) { // 음악 리스트에 있는 음악들을 모두 삭제하는 함수
	char sure; // 진짜 다 삭제할 건지 마지막으로 확인하는 변수
	while (1) {
		printf("Are you sure? (y or n): ");
		scanf(" %c", &sure); // 변수에 진짜 다 삭제할 건지 마지막으로 확인
		if (sure == 'y') { // 진짜 삭제한다고 할 때
			for (int i = 0; i < sng->capacity; i++) { // for문을 배열의 크기만큼 돌림
				strcpy(sng->songs[i].title, ""); // 제목 없앰
				strcpy(sng->songs[i].artist, ""); // 가수 없앰
				sng->songs[i].length.minute = 0; // 분 0으로 함
				sng->songs[i].length.second = 0; // 초 0으로 함
			}
			sng->size = 0; // 음악의 개수 0으로 바꿈
			printf("Delete all complete\n");
			return 0;
		}
		else if (sure == 'n') // n을 입력했을 때
			return 0;
		else // 잘못된 값 입력했을 때
			printf("Wrong input\n");
	}
}