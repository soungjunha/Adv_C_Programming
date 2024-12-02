#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	char* name;
	int id;
	int price;
	int cnt;
}MENU;

int check_ID();
MENU* reset_drink_menu();
MENU* reset_snack_menu();
MENU* service_mode(MENU* drinks, MENU* snacks);
void print_receipt(MENU* order);

int money = 0;

int main() {

	MENU* drinks = reset_drink_menu();
	MENU* snacks = reset_snack_menu();
	MENU* order;
	FILE* asset = fopen("asset.txt", "r");

	fscanf(asset, "%d", &money);
	fclose(asset);

	if (check_ID())
	{
		printf("admin mode\n");
	}
	else {
		printf("user mode\n");
		order = service_mode(drinks, snacks);
		print_receipt(order);
	}
	for (int i = 0; i < _msize(drinks) / sizeof(MENU); i++)
	{
		free(drinks[i].name);
	}
	for (int i = 0; i < _msize(snacks) / sizeof(MENU); i++)
	{
		free(snacks[i].name);
	}
	for (int i = 0; i < _msize(order) / sizeof(MENU); i++)
	{
		free(order[i].name);
	}
	free(drinks);
	free(snacks);
	free(order);
}

int check_ID() {
	char buffer[50];

	while (1)
	{
		printf("mode select(admin or user): ");
		scanf("%s", buffer);
		if (!strcmp(buffer, "admin")) {
			return 1;
		}
		else if (!strcmp(buffer, "user")) {
			return 0;
		}
		else {
			printf("wrong input\n");

		}
	}

}

MENU* reset_drink_menu() {
	FILE* drink = fopen("drink2.txt", "r");
	MENU* drinks = (MENU*)malloc(1);
	char buffer[100];
	for (int i = 0; !feof(drink); i++)
	{
		char* buffer2;
		drinks = (MENU*)realloc(drinks, (i + 1) * sizeof(MENU));
		if (fgets(buffer, 100, drink) != NULL) {
			buffer2 = strtok(buffer, "\t");
			drinks[i].name = (char*)malloc((strlen(buffer2) + 1) * sizeof(char));
			strcpy(drinks[i].name, buffer2);
			buffer2 = strtok(NULL, "\t");
			drinks[i].price = atoi(buffer2);
			buffer2 = strtok(NULL, "\t");
			drinks[i].cnt = atoi(buffer2);
			drinks[i].id = i + 1;
		}
	}
	fclose(drink);
	return drinks;
}
MENU* reset_snack_menu() {
	FILE* snack = fopen("snack2.txt", "r");
	MENU* snacks = (MENU*)malloc(1);
	char buffer[100], * buffer2;
	for (int i = 0; !feof(snack); i++)
	{
		snacks = (MENU*)realloc(snacks, (i + 1) * sizeof(MENU));
		if (fgets(buffer, 100, snack) != NULL) {
			buffer2 = strtok(buffer, "\t");
			snacks[i].name = (char*)malloc((strlen(buffer2) + 1) * sizeof(char));
			strcpy(snacks[i].name, buffer2);
			buffer2 = strtok(NULL, "\t");
			snacks[i].price = atoi(buffer2);
			buffer2 = strtok(NULL, "\t");
			snacks[i].cnt = atoi(buffer2);
			snacks[i].id = i + 1;
		}

	}
	fclose(snack);
	return snacks;
}
MENU* service_mode(MENU* drinks, MENU* snacks) {
	int type = 0;
	int id;
	MENU* order = (MENU*)malloc(1);
	for (int i = 0;; i++)
	{
		printf("-----------drink menu----------\n");
		for (int i = 0; i < _msize(drinks) / sizeof(MENU); i++)
		{
			if (drinks[i].cnt > 0) {
				printf("%2d  :  %15s\t%5d\t%3d\n", drinks[i].id, drinks[i].name, drinks[i].price, drinks[i].cnt);
			}
		}
		printf("\n");
		printf("-----------snack menu----------\n");
		for (int i = 0; i < _msize(snacks) / sizeof(MENU); i++)
		{
			if (snacks[i].cnt > 0) {
				printf("%2d  :  %15s\t%5d\t%3d\n", snacks[i].id, snacks[i].name, snacks[i].price, snacks[i].cnt);
			}
		}
		printf("Type 1 for drink, 2 for snack,3 for buy: ");
		scanf("%d", &type);
		if (type == 1)
		{
			printf("Type drink id to buy:");
			scanf("%d", &id);
			if (id > _msize(drinks) / sizeof(MENU)) {
				printf("Not enought ID for drink\n\n");
				i--;
				continue;
			}
			if (drinks[id - 1].cnt > 0)
			{
				order = (MENU*)realloc(order, (i + 1) * sizeof(MENU));
				order[i].name = (char*)malloc((strlen(drinks[id - 1].name) + 1) * sizeof(char));
				strcpy(order[i].name, drinks[id - 1].name);
				order[i].price = drinks[id - 1].price;
				money += drinks[id - 1].price;
				drinks[id - 1].cnt--;
			}
			else {
				printf("해당 제품은 품절되었습니다.\n");
			}
		}
		else if (type == 2)
		{
			printf("Type snack id to buy:");
			scanf("%d", &id);
			if (id > _msize(snacks) / sizeof(MENU)) {
				printf("Not enought ID for snack\n\n");
				i--;
				continue;
			}
			if (snacks[id - 1].cnt > 0) {
				order = (MENU*)realloc(order, (i + 1) * sizeof(MENU));
				order[i].name = (char*)malloc((strlen(snacks[id - 1].name) + 1) * sizeof(char));
				strcpy(order[i].name, snacks[id - 1].name);
				order[i].price = snacks[id - 1].price;
				money += snacks[id - 1].price;
				snacks[id - 1].cnt--;
			}
			else {
				printf("해당 제품은 품절되었습니다.\n");
			}
		}
		else if (type == 3) {

			FILE* drink = fopen("drink2.txt", "w");
			FILE* snack = fopen("snack2.txt", "w");

			for (int k = 0; k < _msize(drinks) / sizeof(MENU); k++)
			{
				fprintf(drink, "%s\t%d\t%d\n", drinks[k].name, drinks[k].price, drinks[k].cnt);
			}

			for (int k = 0; k < _msize(snacks) / sizeof(MENU); k++)
			{
				fprintf(snack, "%s\t%d\t%d\n", snacks[k].name, snacks[k].price, snacks[k].cnt);
			}

			fclose(drink);
			fclose(snack);

			return order;
		}
		else {
			printf("Error: Wrong input for type\n");
		}
	}
}

void print_receipt(MENU* order) {
	FILE* receipt = fopen("receipt.txt", "w");
	int total = 0;
	printf("-----------receipt----------\n");
	fprintf(receipt, "-----------receipt----------\n");

	for (int j = 0; j < _msize(order) / sizeof(MENU); j++)
	{
		printf("%s\t%5d\n", order[j].name, order[j].price);
		fprintf(receipt, "%s\t%5d\n", order[j].name, order[j].price);
		total += order[j].price;
	}
	printf("total: %8d", total);
	fprintf(receipt, "total: %8d", total);
	fclose(receipt);
}
