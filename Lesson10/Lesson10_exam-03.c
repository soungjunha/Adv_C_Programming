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

void print_booklist(Book* books,int len) {
	printf("\n\t\t    å ���� ��Ȳ\n ID\t\t\t�̸�\t\t\t����\n");
	for (int k = 0; k < len; k++)
	{
		for (int m = 0; m < (books[k].cnt ? books[k].cnt : 1); m++)
		{
			printf("%d,", books[k].id[m]);
		}
		printf("\t%32s\t%2d\n", books[k].title, books[k].cnt);
	}
}

Book* initial_booklist(int* len,int* total_book_num) {
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
		(*total_book_num) += books[i].cnt;
	}
	fclose(booklist);
	return books;
}

void manage_booklist(Book* books, int book_id, int len,int* total_book_num) {
	int f = 0;
	int id_index = -200;
	for (int i = 0; i < len; i++)
	{
		if (id_index = has_value(books[i].id, book_id, books[i].cnt))
		{
			printf("%s��(��) �뿩�Ͽ����ϴ�.\n", books[i].title);
			(*total_book_num)--;
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
			printf("�ش� å�� �뿩 �Ϸ��� ");
			for (int m = 0; m < (books[i].cnt ? books[i].cnt : 1); m++)
			{
				printf("%d ", books[i].id[m]);
			}
			printf("��(��)�뿩���ּ���.");
			f = 1;
			break;
		}
	}
	if (f == 0)
		printf("å�� �����ϰ� ���� �ʽ��ϴ�\n");
}

int admin_check() {
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

	fclose(admin_auth);

	printf("ID:");
	scanf("%s", input_ID);
	printf("PW:");
	scanf("%s", input_PW);

	if (!strcmp(input_ID, admin_ID) && !strcmp(input_PW, admin_PW)) {
		printf("������ ������ �Ϸ�Ǿ����ϴ�.");
		return 1;
	}
	else printf("���� ����");
	return 0;
}

Book* initial_storage(int* total_storage_num) {
	Book* storage = (Book*)malloc(1);
	FILE* file = fopen("storage.txt", "r");
	if (file == NULL) {
		printf("â�� ������ �� �� �����ϴ�.\n");
		return;
	}
	char buffer[50];
	int line_cnt = 0;

	fgets(buffer, sizeof(buffer), file);

	while (fgets(buffer, sizeof(buffer), file)) {
		int len = strlen(buffer);

		int i = len - 2;
		if (buffer[len - 1] != '\n') i++;

		char number[256];
		int number_index = 0;

		while (i >= 0 && buffer[i] >= '0' && buffer[i] <= '9') {
			number[number_index++] = buffer[i];
			i--;
		}
		number[number_index] = '\0';

		int cnt = 0;
		for (int j = number_index - 1; j >= 0; j--) {
			cnt = cnt * 10 + (number[j] - '0');
		}

		storage = (struct Book*)realloc(storage, (*total_storage_num + 1) * sizeof(Book));

		buffer[i + 1] = '\0';
		int j = i;
		
		while (j >= 0 && (buffer[j] == ' ' || buffer[j] == '\t')) {
			j--;
		}
		buffer[j + 1] = '\0';

		storage[*total_storage_num].title = (char*)malloc(strlen(buffer) + 1);

		storage[*total_storage_num].cnt = cnt;
		strcpy(storage[*total_storage_num].title, buffer);
		storage[*total_storage_num].id = *total_storage_num + 1;

		*total_storage_num++;
	}

	fclose(file);
}

void print_storage(Book* storage, int* total_storage_num) {
	printf("\n[â�� ��Ȳ]\n");
	printf("ID  �ܿ��Ǽ� ����\n");
	for (int i = 0; i < total_storage_num; i++) {
		printf("%-3d %d��      %s\n", storage[i].id, storage[i].cnt, storage[i].title);
	}
}

void expand_inventory_from_storage(Book* books, Book* storage,int* total_book_num,int* total_storage_num) {
	printf("\n��� Ȯ�� �۾� ����\n");
	for (int i = 0; i < *total_book_num; i++) {
		if (books[i].cnt == 0) {
			for (int j = 0; j < *total_storage_num; j++) {
				if (strcmp(books[i].title, storage[j].title) == 0) {
					int transferCount = (storage[j].cnt >= 3) ? 3 : storage[j].cnt;
					books[i].cnt += transferCount;
					storage[j].cnt -= transferCount;
					printf("'%s' ����: â���� %d�� ������ ���� ���� ��� %d������ Ȯ��\n",
						books[i].title, transferCount, books[i].cnt);
					break;
				}
			}
		}
	}
	printf("[��� Ȯ�� �۾� �Ϸ�]\n");
}

int main(int argc, char** argv) {

	Book* books;
	Book* storage;
	int book_id;
	int len = 0;
	int total_book_num=0;
	int total_storage_num=0;

	
	if (argc > 1 && strcmp(argv[1], "admin") == 0) {
		printf("������ ��忡 �����մϴ�.\n");

		if (admin_check()) {
			printf("������ ���� ����!\n");

			books = initial_booklist(&len, &total_book_num);
			storage = initial_storage(&total_storage_num);

			print_booklist(books, len);
			print_storage(storage, &total_storage_num);

			expand_inventory_from_storage(books,storage, &total_book_num,&total_storage_num);
			
			printf("\n===================������ ���� ä�� �� ���===================\n");
			print_booklist(books, len);
			print_storage(storage, &total_storage_num);

			char choice;
			printf("���� ���� ��ȯ�Ͻðڽ��ϱ�? (y/n): ");
			scanf(" %c", &choice);

			if (choice == 'y' || choice == 'Y') {
				printf("���� ���� ��ȯ�մϴ�.\n");
				int bookId;

				printf("\n�뿩�� ���ϴ� ������ ID�� �Է��ϼ���: ");
				if (scanf("%d", &bookId) == 1) {
					manage_booklist(books, book_id, len, &total_book_num);
					printf("\n\t\t    �뿩 ��Ȳ\n ID\t\t\t�̸�\t\t\t����\n");
					for (int k = 0; k < len; k++)
					{
						for (int m = 0; m < (books[k].borrow_cnt ? books[k].borrow_cnt : 1); m++)
						{
							printf("%d ", books[k].borrow_id[m]);
						}
						printf(" %32s\t%2d\n", books[k].title, books[k].borrow_cnt);
					}
				}
				else {
					printf("�߸��� �Է��Դϴ�.\n");
				}
			}
			else {
				printf("���α׷��� �����մϴ�.\n");
				return;
			}
		}
		else {
			printf("������ ���� ����! ���α׷��� �����մϴ�.\n");
			return;
		}
	}
	else {
		printf("������ ���� ������� �ʾҽ��ϴ�.\n");
		return;
	}
		
	do
	{
		print_booklist(books, len);
		printf("\n�뿩�� å�� ID(���Ḧ ���Ұ�� 0�� �Է�):");
		scanf("%d", &book_id);
		manage_booklist(books, book_id, len, &total_book_num);
		printf("\n\t\t    �뿩 ��Ȳ\n ID\t\t\t�̸�\t\t\t����\n");
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
