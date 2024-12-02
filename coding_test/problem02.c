#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int check_ID();
char** reset_drink_menu();
char** reset_snack_menu();
char** service_mode(char** drinks, char** snacks);

int main() {

	char** drinks = reset_drink_menu();
	char** snacks = reset_snack_menu();
	char** order;

	if (check_ID())
	{
		printf("admin mode\n");
	}
	else {
		printf("user mode\n");
		order = service_mode(drinks, snacks);
		printf("-----------receipt----------\n");

		for (int j = 0; j < _msize(order) / sizeof(char*); j++)
		{
			printf("%s\n", order[j]);
		}
	}
	for (int i = 0; i < _msize(drinks) / sizeof(char*); i++)
	{
		free(drinks[i]);
	}
	for (int i = 0; i < _msize(snacks) / sizeof(char*); i++)
	{
		free(snacks[i]);
	}
	for (int i = 0; i < _msize(order) / sizeof(char*); i++)
	{
		free(order[i]);
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

char** reset_drink_menu() {
	FILE* drink = fopen("drink1.txt", "r");
	char** drinks = (char**)malloc(1);
	char buffer[100];
	for (int i = 0; !feof(drink); i++)
	{
		drinks = (char**)realloc(drinks, (i + 1) * sizeof(char*));
		fgets(buffer, 100, drink);
		drinks[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
		strcpy(drinks[i], buffer);
	}
	fclose(drink);
	return drinks;
}
char** reset_snack_menu() {
	FILE* snack = fopen("snack1.txt", "r");
	char** snacks = (char**)malloc(1);
	char buffer[100];
	for (int i = 0; !feof(snack); i++)
	{
		snacks = (char**)realloc(snacks, (i + 1) * sizeof(char*));
		fgets(buffer, 100, snack);
		snacks[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
		strcpy(snacks[i], buffer);
	}
	fclose(snack);
	return snacks;
}
char** service_mode(char** drinks, char** snacks) {
	int type = 0;
	int id;
	char** order = (char**)malloc(1);
	printf("-----------drink menu----------\n");
	for (int i = 0; i < _msize(drinks) / sizeof(char*); i++)
	{
		printf("%2d  :  %15s\n", i + 1, drinks[i]);
	}
	printf("\n");
	printf("-----------drink menu----------\n");
	for (int i = 0; i < _msize(snacks) / sizeof(char*); i++)
	{
		printf("%2d  :  %15s\n", i + 1, snacks[i]);
	}
	for (int i = 0;; i++)
	{
		printf("Type 1 for drink, 2 for snack,3 for buy: ");
		scanf("%d", &type);
		if (type == 1)
		{
			printf("Type drink id to buy:");
			scanf("%d", &id);
			if (id > _msize(drinks) / sizeof(char*)) {
				printf("Not enought ID for drink\n\n");
				i--;
				continue;
			}
			order = (char**)realloc(order, (i + 1) * sizeof(char*));
			order[i] = (char*)malloc((strlen(drinks[id - 1]) + 1) * sizeof(char));
			strcpy(order[i], drinks[id - 1]);
		}
		else if (type == 2)
		{
			printf("Type snack id to buy:");
			scanf("%d", &id);
			if (id > _msize(snacks) / sizeof(char*)) {
				printf("Not enought ID for snack\n\n");
				i--;
				continue;
			}
			order = (char**)realloc(order, (i + 1) * sizeof(char*));
			order[i] = (char*)malloc((strlen(snacks[id - 1]) + 1) * sizeof(char));
			strcpy(order[i], snacks[id - 1]);
		}
		else if (type == 3) {
			return order;
		}
		else {
			printf("Error: Wrong input for type\n");
		}
	}
}
