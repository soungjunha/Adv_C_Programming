#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _book {
	int* id;
	char* title;
	int cnt;
	int* borrow_id;
	int borrow_cnt;
}Book;

int has_value(int* arr, int value, int len) {
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == value) {
			return i + 1;
		}
	}
	return 0;
}

Book* initial_booklist(int* len) {
	FILE* booklist;
	char input_buffer[100];
	char cnt_buffer[15];
	char title_buffer[100];
	Book* books;
	int b_id = 1;
	books = (Book*)malloc(1);
	booklist = fopen("books.txt", "r");
	fgets(input_buffer, 100, booklist);
	for (int i = 1; !feof(booklist); i++)
	{
		int j = 0, k = 0;
		books = (Book*)realloc(books, sizeof(Book) * i);
		fgets(input_buffer, 100, booklist);
		//books[i - 1].id = i;
		for (j = 0; input_buffer[j] != '\t'; j++)
		{
			title_buffer[j] = input_buffer[j];
		}
		title_buffer[j] = '\0';
		books[i - 1].title = (char*)malloc(sizeof(char) * (strlen(title_buffer) + 1));
		strcpy(books[i - 1].title, title_buffer);
		for (k = 0; input_buffer[j] != '\0'; j++)
		{
			if (input_buffer[j] >= '0' && input_buffer[j] <= '9') {
				cnt_buffer[k] = input_buffer[j];
				k++;
			}
		}
		cnt_buffer[k] = '\0';
		books[i - 1].cnt = atoi(cnt_buffer);
		books[i - 1].id = (int*)malloc(sizeof(int) * (books[i - 1].cnt ? books[i - 1].cnt : 1));
		if (books[i - 1].cnt != 0)
		{
			for (int j = 0; j < books[i - 1].cnt; j++)
			{
				books[i - 1].id[j] = b_id++;
			}
		}
		else {
			books[i - 1].id[0] = 0;
		}
		books[i - 1].borrow_id = (int*)calloc(books[i - 1].cnt ? books[i - 1].cnt : 1, sizeof(int));
		books[i - 1].borrow_cnt = 0;
		(*len)++;
	}
	fclose(booklist);
	return books;
}

void manage_booklist(Book* books, int book_id, int len) {
	int f = 0;
	int id_index = -200;
	for (int i = 0; i < len; i++)
	{
		if (id_index = has_value(books[i].id, book_id, books[i].cnt))
		{
			printf("%s을(를) 대여하였습니다.\n", books[i].title);
			books[i].borrow_id[books[i].borrow_cnt] = books[i].id[id_index - 1];
			books[i].id[id_index - 1] = 0;
			for (int j = id_index; j < books[i].cnt; j++)
			{
				books[i].id[j - 1] = books[i].id[j];
			}
			books[i].borrow_cnt++;
			books[i].cnt--;
			f = 1;
			break;
		}
		else if (books[i].cnt != 0)
		{
			printf("해당 책을 대여 하려면 ");
			for (int m = 0; m < (books[i].cnt ? books[i].cnt : 1); m++)
			{
				printf("%d ", books[i].id[m]);
			}
			printf("을(를)대여해주세요.");
			f = 1;
			break;
		}
	}
	if (f == 0)
		printf("책을 소유하고 있지 않습니다\n");
}

void admin_check(Book* books, int len) {
	FILE* admin_auth;
	char buffer[101];
	char input_ID[101];
	char input_PW[101];
	char* admin_ID;
	char* admin_PW;

	admin_auth = fopen("admin_auth.txt", "r");

	fscanf(admin_auth, "%s", buffer);
	fscanf(admin_auth, "%s", buffer);
	admin_ID = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	strcpy(admin_ID, buffer);
	fscanf(admin_auth, "%s", buffer);
	fscanf(admin_auth, "%s", buffer);
	admin_PW = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	strcpy(admin_PW, buffer);


	printf("ID:");
	scanf("%s", input_ID);
	printf("PW:");
	scanf("%s", input_PW);

	if (!strcmp(input_ID, admin_ID) && !strcmp(input_PW, admin_PW)) {
		printf("관리자 인증이 완료되었습니다.");
		printf("\n\t\t    책 보유 현황\n ID\t\t\t이름\t\t\t수량\n");
		for (int k = 0; k < len; k++)
		{
			for (int m = 0; m < (books[k].cnt ? books[k].cnt : 1); m++)
			{
				printf("%d,", books[k].id[m]);
			}
			printf("\t%32s\t%2d\n", books[k].title, books[k].cnt);
		}
	}
	else printf("인증 실패");

	fclose(admin_auth);
}

int main(int argc, char** argv) {

	Book* books;
	int book_id;
	int len = 0;

	books = initial_booklist(&len);
	if (argc >= 1 && !strcmp("admin", argv[1]))
		admin_check(books, len);
	do
	{
		printf("\n\t\t    책 리스트\n ID\t\t\t이름\t\t\t수량\n");
		for (int k = 0; k < len; k++)
		{
			for (int m = 0; m < (books[k].cnt ? books[k].cnt : 1); m++)
			{
				printf("%d,", books[k].id[m]);
			}
			printf("\t%32s\t%2d\n", books[k].title, books[k].cnt);
		}
		printf("\n대여할 책의 ID(종료를 원할경우 0을 입력):");
		scanf("%d", &book_id);
		manage_booklist(books, book_id, len);
		printf("\n\t\t    대여 현황\n ID\t\t\t이름\t\t\t수량\n");
		for (int k = 0; k < len; k++)
		{
			for (int m = 0; m < (books[k].borrow_cnt ? books[k].borrow_cnt : 1); m++)
			{
				printf("%d ", books[k].borrow_id[m]);
			}
			printf(" %32s\t%2d\n", books[k].title, books[k].borrow_cnt);
		}
	} while (book_id != 0);
	for (int i = 0; i < len; i++)
	{
		free(books[i].id);
		free(books[i].borrow_id);
		free(books[i].title);
	}
	free(books);
}
