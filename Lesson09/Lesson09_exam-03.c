#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _book {
	int id;
	char* title;
	int cnt;
	int ballow_cnt;
}Book;

Book* initial_booklist(int* len) {
	FILE* booklist;
	char input_buffer[100];
	char cnt_buffer[15];
	char title_buffer[100];
	Book* books;
	books = (Book*)malloc(1);
	booklist = fopen("books.txt", "r");
	fgets(input_buffer, 100, booklist);
	for (int i = 1; !feof(booklist); i++)
	{
		int j = 0, k = 0;
		books = (Book*)realloc(books, sizeof(Book) * i);
		fgets(input_buffer, 100, booklist);
		books[i - 1].id = i;
		for ( j = 0; input_buffer[j]!='\t'; j++)
		{
			title_buffer[j] = input_buffer[j];
		}
		title_buffer[j] = '\0';
		books[i - 1].title = (char*)malloc(sizeof(char) * (strlen(title_buffer) + 1));
		strcpy(books[i - 1].title, title_buffer);
		for (k=0; input_buffer[j]!='\0'; j++)
		{
			if (input_buffer[j] >= '0' && input_buffer[j] <= '9') {
				cnt_buffer[k] = input_buffer[j];
				k++;
			}
		}
		cnt_buffer[k] = '\0';
		books[i - 1].cnt = atoi(cnt_buffer);
		books[i - 1].ballow_cnt = 0;
		(*len)++;
	}
	fclose(booklist);
	return books;
}

void manage_booklist(Book* books,int book_id,int len) {
	int f = 0;
	for (int i = 0; i < len; i++)
	{
		if (books[i].id==book_id)
		{
			if (books[i].cnt == 0) printf("å�� ��� �뿩 �Ǿ����ϴ�.\n");
			else {
				books[i].cnt--;
				books[i].ballow_cnt++;
				printf("%s��(��) �뿩�Ͽ����ϴ�.\n", books[i].title);
			}
			f = 1;
			break;
		}
	}
	if(f==0)
		printf("å�� �����ϰ� ���� �ʽ��ϴ�\n");
}

int main() {

	Book* books;
	int book_id;
	int len = 0;

	books = initial_booklist(&len);
	while (1)
	{
		printf("\n\t\t    å ����Ʈ\n ID\t\t\t�̸�\t\t\t����\n");
		for (int k = 0; k < len; k++)
		{
			printf(" %3d\t%32s\t%2d\n", books[k].id, books[k].title, books[k].cnt);
		}
		printf("\n�뿩�� å�� ID:");
		scanf("%d", &book_id);
		manage_booklist(books, book_id,len);
		printf("\n\t\t    �뿩 ��Ȳ\n ID\t\t\t�̸�\t\t\t����\n");
		for (int k = 0; k < len; k++)
		{
			printf(" %3d\t%32s\t%2d\n", books[k].id, books[k].title, books[k].ballow_cnt);
		}
	}
}
