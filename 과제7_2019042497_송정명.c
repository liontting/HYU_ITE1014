#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct _time { // ������ ����(��, ��)�� ��� ����ü
	int minute;
	int second;
} Time;

typedef struct _song { // ������ ����(����, ����, ���� ����)�� ��� ����ü
	char title[100];
	char artist[100];
	Time length;
} Song;

typedef struct _songList { // ���� ����Ʈ�� ��� ����ü
	Song *songs; // ������ ����
	int size; // ���� ����ִ� ������ ��
	int capacity; // �迭�� ũ��
} SongList;

SongList dataLoad(); // ���� ���� �����͸� �о���� �Լ�
int dataSave(SongList); // ����ü �ȿ� �ִ� ���� ����Ʈ�� ���� �ȿ� ����� �����ϱ� ���� �Լ�
void printMenu(); // �޴��� ����ϴ� �Լ�
void printSong(Song*); // ������ ������ ������ ����ϴ� �Լ�
void printSongMenu(); // �޴��� 1�� ���� ���� ����, ����, ���� �޴��� ����ϴ� �Լ�
Song* searchSong(SongList, char*, char*); // ���� ����Ʈ �ȿ� ������ �ִ��� ã�� �Լ�
int editSong(Song*); // ������ ������ ������ �����ϴ� �Լ�
int deleteSong(SongList*, Song*); // ���� ����Ʈ���� ������ ������ ����� �Լ�
int addSong(SongList*); // ���ο� ������ ���� ����Ʈ�� �߰��ϴ� �Լ�
void printAllSongs(SongList); // ���� ����Ʈ�� �ִ� ���ǵ��� ����ϴ� �Լ�
int deleteAll(SongList*); // ���� ����Ʈ�� �ִ� ���ǵ��� ��� �����ϴ� �Լ�

int main()
{
	SongList songlist; // ���� ���� ���� ����Ʈ�� �ҷ��� ���� ����ü
	printf("----- Mini Music Library -----\n\n");
	songlist = dataLoad(); // ������ ����ü�� ���� ���� ���� ����Ʈ�� ������ ����
	while (1) {
		int num; // �޴����� �� ���� �� ������ ��� ����
		char ch; // ���ۿ� ���� �߸� �Էµ� ���ڸ� ó���ϱ� ���� ����
		printMenu(); // �޴� ���
		while (scanf(" %d", &num) != 1) { // ������ �޴����� �� ���� �� ������ �����鼭 ���ڸ� �Է� �޴� ���� �ɷ���
			while ((ch = getchar()) != '\n'); // ���� ���� ���� ���
			printf("Wrong input\n");
			printMenu();
		}
		if (num == 1) { // 1�� �޴��� �������� ��
			int n; // �޴��� 1�� ���� �޴����� �� ���� �� ������ ��� ����
			char title[100] = { 0, }, artist[100] = { 0, }; // ������ ������ ����, ������ ��� �迭
			Song* sng; // ������ ������ ��� ����ü
			printf("Input title: ");
			scanf(" %[^\n]s", title); // ������ ������ ������ ������ ����
			printf("Input artist: ");
			scanf(" %[^\n]s", artist); // ������ ������ ������ ������ ����
			sng = searchSong(songlist, title, artist); // ���� ����Ʈ���� ������ ������ ã�Ƽ� ������ ����
			if (sng != 0) { // ���� ����Ʈ �ȿ� ������ ���� ��
				printSong(sng); // ������ ������ ������ ���
				while (1) {
					printSongMenu(); // �޴��� 1�� ���� ���� ����, ����, ���� �޴��� ���
					while (scanf(" %d", &n) != 1) { // ������ ����, ����, ���� �޴����� �� ���� �� ������ �����鼭 ���ڸ� �Է� �޴� ���� �ɷ���
						while ((ch = getchar()) != '\n'); // ���� ���� ���� ���
						printf("Wrong input\n");
						printSongMenu();
					}
					if (n == 1) { // 1���� ����� ��
						editSong(sng); // ������ ������ ������ ����
						break;
					}
					else if (n == 2) { // 2���� ����� ��
						deleteSong(&songlist, sng); // ���� ����Ʈ���� ������ ������ ����
						break;
					}
					else if (n == 0) // 0���� ����� ��
						break;
					else // �߸� �Է����� ��
						printf("wrong input\n");
				}
			}
			else // ���� ����Ʈ �ȿ� ������ ���� ��
				printf("Wrong input!\n");
		}
		else if (num == 2) // 2�� �޴��� �������� ��
			addSong(&songlist); // ���ο� ������ ���� ����Ʈ�� �߰�
		else if (num == 3) // 3�� �޴��� �������� ��
			printAllSongs(songlist); // ���� ����Ʈ�� �ִ� ���ǵ��� ���
		else if (num == 4) // 4�� �޴��� �������� ��
			deleteAll(&songlist); // ���� ����Ʈ�� �ִ� ���ǵ��� ��� ����
		else if (num == 0) { // 0�� �޴��� �������� ��
			dataSave(songlist); // ����ü �ȿ� �ִ� ���� ����Ʈ�� ���� �ȿ� ����� ����
			break;
		}
		else // �޴��� ���� ���� �Է����� ��
			printf("Wrong input\n");
	}
	free(songlist.songs); // �����Ҵ�Ǿ��� �� ������ ���� free
	return 0;
}

SongList dataLoad() { // ���� ���� �����͸� �о���� �Լ�
	int num = 0; // ������ ������ �޴� ����
	SongList snglist; // ���� ���� ���� ����Ʈ�� �ҷ��� ���� ����ü ����
	FILE *f = fopen("input.txt", "r"); // �б� ���� ���� ����
	if (f == NULL) { // input.txt ������ ���� ��
		FILE *f = fopen("input.txt", "a"); // input.txt ������ �߰�
		snglist.songs = (Song*)malloc(num * sizeof(Song)); // ������ ������ŭ �����Ҵ���(���߿� realloc�� ����)
		snglist.capacity = snglist.size = 0; // ������ ������ 0�� ���� ����Ʈ ���� ������ ����
		fprintf(f, "0"); // ������ ������ 0 �����
		fclose(f); // ������ ����
	}
	else { // input.txt ������ ���� ��
		fscanf(f, " %d", &num); // ���� ���� �ִ� ������ ���� �о��
		snglist.songs = (Song*)malloc(num * sizeof(Song)); // ������ ������ŭ �����Ҵ���
		snglist.capacity = snglist.size = num; // ������ ������ ���� ����Ʈ ���� ������ ����
		for (int i = 0; i < num; i++) { // for���� ������ ������ŭ �ݺ�
			fscanf(f, " %d %d", &snglist.songs[i].length.minute, &snglist.songs[i].length.second); // ���� ����(��, ��)�� �о��
			fscanf(f, " %[^\n]s", snglist.songs[i].title); // ���� ������ �о��
			fscanf(f, " %[^\n]s", snglist.songs[i].artist); // ���� ������ �о��
		}
		fclose(f); // ������ ����
	}
	printf("... Data load success\n");
	return snglist; // ���� ����Ʈ return
}

int dataSave(SongList snglist) { // ����ü �ȿ� �ִ� ���� ����Ʈ�� ���� �ȿ� ����� �����ϱ� ���� �Լ�
	FILE *f = fopen("input.txt", "w"); // ������ ���� ���� ���� ������ ����
	fprintf(f, "%d\n", snglist.size); // ������ ���� ���� ���Ͽ� ����
	for (int i = 0; i < snglist.capacity; i++) { // for���� �迭�� ũ�⸸ŭ ����
		if (snglist.songs[i].length.minute != 0 || snglist.songs[i].length.second != 0) { // ������ ���̰� 0m 0s�� �ƴϸ�
			fprintf(f, "%d %d\n", snglist.songs[i].length.minute, snglist.songs[i].length.second); // ������ ���̸� ���Ͽ� ����
			fprintf(f, "%s\n", snglist.songs[i].title); // ������ ���� ���Ͽ� ����
			fprintf(f, "%s\n", snglist.songs[i].artist); // ������ ���� ���Ͽ� ����
		}
	}
	fclose(f); // ������ ����
	printf("... Data save success\n");
	return 0;
}

void printMenu() { // �޴��� ����ϴ� �Լ�
	printf("------------------------------\n");
	printf("1. Search\n");
	printf("2. New song\n");
	printf("3. Print all\n");
	printf("4. Delete all\n");
	printf("0. Exit\n");
	printf("------------------------------\n");
	printf(">>> ");
}

void printSong(Song* sng) { // ������ ������ ������ ����ϴ� �Լ�
	printf("\n");
	printf("Title  : %s\n", sng->title);
	printf("Artist : %s\n", sng->artist);
	printf("Length : %d min %d sec\n", sng->length.minute, sng->length.second);
	printf("\n");
}

void printSongMenu() { // �޴��� 1�� ���� ���� ����, ����, ���� �޴��� ����ϴ� �Լ�
	printf("------------------------------\n");
	printf("1. Edit\n");
	printf("2. Delete\n");
	printf("0. Previous\n");
	printf("------------------------------\n");
	printf(">>> ");
}

Song* searchSong(SongList snglist, char* tle, char* tist) { // ���� ����Ʈ �ȿ� ������ �ִ��� ã�� �Լ�
	for (int i = 0; i < snglist.capacity; i++) // for���� �迭�� ũ�⸸ŭ ����
		if (!strcmp(snglist.songs[i].title, tle) && !strcmp(snglist.songs[i].artist, tist)) // ������ ����� ������ ���ٸ�
			return &snglist.songs[i]; // �� ���� ���� return
	return 0;
}

int editSong(Song* sng) { // ������ ������ ������ �����ϴ� �Լ�
	int min = 0, sec = 0; // ������ ������ ���� (��, ��) ��� ����
	char ti[100] = { 0, }, ar[100] = { 0, }; // ������ ������ ����� ������ ��� �迭
	printf("Input new title: ");
	scanf(" %[^\n]s", ti); // ������ ���� �Է�
	printf("Input new artist: ");
	scanf(" %[^\n]s", ar); // ������ ���� �Է�
	strcpy(sng->title, ti); // ���� ����
	strcpy(sng->artist, ar); // ���� ����
	while (1) {
		printf("Input new length\n");
		printf("        minute: ");
		scanf(" %d", &min); // ������ ������ ����(��) �Է�
		printf("        second: ");
		scanf(" %d", &sec); // ������ ������ ����(��) �Է�
		if (min >= 0 && sec >= 0 && sec < 60 && (min != 0 || sec != 0)) // ��,�ʰ� �����̰ų� 60�̻��� �ʰų� 0m 0s�� ��찡 �ƴ� ��
			break; // while�� ����
		else // ��,�ʰ� �����̰ų� 60�̻��� �ʰų� 0m 0s�� ����� ��
			printf("Wrong input about time\n");
	}
	sng->length.minute = min; // ������ ����(��) ����
	sng->length.second = sec; // ������ ����(��) ����
	return 0;
}

int deleteSong(SongList* sl, Song* sng) { // ���� ����Ʈ���� ������ ������ ����� �Լ�
	sl->size -= 1; // ������ ���� �ϳ� ����
	strcpy(sng->title, ""); // ���� ����
	strcpy(sng->artist, ""); // ���� ����
	sng->length.minute = 0; // �� 0���� ��
	sng->length.second = 0; // �� 0���� ��
	printf("\n... delete success\n");
	return 0;
}

int addSong(SongList* snglist) { // ���ο� ������ ���� ����Ʈ�� �߰��ϴ� �Լ�
	int cnt = 0, min, sec; // ������ ���̰� ����� �ԷµǾ����� Ȯ���ϴ� ����, �߰��� ������ ���� (��, ��) ��� ����
	char ti[100] = { 0, }, ar[100] = { 0, }; // �߰��� ������ ����, ���� ��� �迭
	printf("Input title: ");
	scanf(" %[^\n]s", ti); // �߰��� ������ ���� �Է�
	printf("Input artist: ");
	scanf(" %[^\n]s", ar); // �߰��� ������ ���� �Է�
	for (int i = 0; i < snglist->capacity; i++) { // for���� �迭�� ũ�⸸ŭ ����
		if (!strcmp(snglist->songs[i].title, ti) && !strcmp(snglist->songs[i].artist, ar)) { // �̹� ���� ����, ������ �뷡�� ������ ��
			printf("Same song already exists\n");
			return 0;
		}
	}
	printf("Input length\n");
	printf("        minute: ");
	scanf(" %d", &min); // �߰��� ������ ����(��) �Է�
	printf("        second: ");
	scanf(" %d", &sec); // �߰��� ������ ����(��) �Է�
	if (min < 0 || sec < 0 || sec >= 60 || (min == 0 && sec == 0)) // ��,�ʰ� �����̰ų� 60�̻��� �ʰų� 0m 0s�� ����� ��
		cnt++; // ������ �� ����
	if (cnt == 0) { // ������ ����(��, ��)�� ����� �Է��� �Ǿ��� ��
		snglist->capacity += 1; // �迭�� ũ�� ����
		snglist->size += 1; // ������ ���� ����
		snglist->songs = (Song*)realloc(snglist->songs, snglist->capacity * sizeof(Song)); // �ø� �迭�� ũ�⸸ŭ �����Ҵ���
		strcpy(snglist->songs[snglist->capacity - 1].title, ti); // �߰��� ������ ������ �Է�
		strcpy(snglist->songs[snglist->capacity - 1].artist, ar); // �߰��� ������ ������ �Է�
		snglist->songs[snglist->capacity - 1].length.minute = min; // �߰��� ������ ����(��) �Է�
		snglist->songs[snglist->capacity - 1].length.second = sec; // �߰��� ������ ����(��) �Է�
		printf("... add success\n");
	}
	else // ������ ����(��, ��)�� ����� �Է��� ���� �ʾ��� ��
		printf("Wrong input about time\n");
	return 0;
}

void printAllSongs(SongList snglist) { // ���� ����Ʈ�� �ִ� ���ǵ��� ����ϴ� �Լ�
	printf("\n");
	if (snglist.size == 0) // ������ ������ 0�� ��
		printf("No result\n");
	else // ������ ������ 0�� �ƴ� ��
		for (int i = 0; i < snglist.capacity; i++) // for���� �迭�� ������ŭ ����
			if (snglist.songs[i].length.minute != 0 || snglist.songs[i].length.second != 0) // ������ ���̰� 0m 0s�� �ƴϸ�
				printf("%s - %s (%d:%d)\n", snglist.songs[i].artist, snglist.songs[i].title, snglist.songs[i].length.minute, snglist.songs[i].length.second); // ���� ���
	printf("\n");
}

int deleteAll(SongList* sng) { // ���� ����Ʈ�� �ִ� ���ǵ��� ��� �����ϴ� �Լ�
	char sure; // ��¥ �� ������ ���� ���������� Ȯ���ϴ� ����
	while (1) {
		printf("Are you sure? (y or n): ");
		scanf(" %c", &sure); // ������ ��¥ �� ������ ���� ���������� Ȯ��
		if (sure == 'y') { // ��¥ �����Ѵٰ� �� ��
			for (int i = 0; i < sng->capacity; i++) { // for���� �迭�� ũ�⸸ŭ ����
				strcpy(sng->songs[i].title, ""); // ���� ����
				strcpy(sng->songs[i].artist, ""); // ���� ����
				sng->songs[i].length.minute = 0; // �� 0���� ��
				sng->songs[i].length.second = 0; // �� 0���� ��
			}
			sng->size = 0; // ������ ���� 0���� �ٲ�
			printf("Delete all complete\n");
			return 0;
		}
		else if (sure == 'n') // n�� �Է����� ��
			return 0;
		else // �߸��� �� �Է����� ��
			printf("Wrong input\n");
	}
}