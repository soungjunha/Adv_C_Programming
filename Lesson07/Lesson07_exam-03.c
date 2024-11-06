#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	FILE* menu, * receipt;
	char** menu_list = (char**)malloc(1);
	char** price = (char**)malloc(1);
	char buffer[100];
	int total_price = 0;
	int cnt = 0;

	menu = fopen("menu.txt", "r");
	receipt = fopen("receipt.txt", "w");

	for (int i = 0; !feof(menu); i++)
	{
		if (fgets(buffer, 100, menu) != EOF) {
			int j;
			for (j = 0; buffer[j] != ':'; j++)
			{
				menu_list = (char**)realloc(menu_list, (i + 1) * sizeof(char*));
				if (j == 0)	menu_list[i] = (char*)malloc(1);
				menu_list[i] = (char*)realloc(menu_list[i], (j + 1) * sizeof(char));
				menu_list[i][j] = buffer[j];
			}
			menu_list[i][j++] = '\0';
			for (; buffer[j] != '\n'; j++)
			{
				price = (char**)realloc(price, (i + 1) * sizeof(char*));
				if (j - (strlen(menu_list[i]) + 1) == 0)	price[i] = (char*)malloc(1);
				price[i] = (char*)realloc(price[i], (j - strlen(menu_list[i])) * sizeof(char));
				price[i][j - (strlen(menu_list[i]) + 1)] = buffer[j];
			}
			price[i][j - (strlen(menu_list[i]) + 1)] = '\0';
		}
		cnt++;
	}

	while (1)
	{
		int menu_num;
		printf("===================menu==================price\n\n\n");
		for (int i = 0; i < cnt; i++)
		{
			printf("[%2d]\t%15s\t\t\t%6s\n", i + 1, menu_list[i], price[i]);
		}
		printf("메뉴를 고르세요. 주문완료는 0을 누르세요: ");
		scanf("%d", &menu_num);
		if (menu_num == 0) {
			break;
		}
		else if (menu_num > cnt) {
			printf("입력이 잘못 되었습니다. 다시 입력해주세요.\n");
			continue;
		}
		else {
			printf("%s 주문 받았습니다.\n", menu_list[menu_num - 1]);
			fprintf(receipt, "%s: %s\n", menu_list[menu_num - 1], price[menu_num - 1]);
			total_price += atoi(price[menu_num - 1]);
		}

	}
	fprintf(receipt, "Payment amount : %d", total_price);
	fclose(menu);
	fclose(receipt);

	for (int i = 0; i < cnt; i++) {
		free(menu_list[i]);
		free(price[i]);
	}
	free(menu_list);
	free(price);

}
