#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int my_strcmp(char* str[2]) {
	int f = 0;
	for (int i = 0; str[0][i] != '\0' || str[1][i] != '\0'; i++)
	{
		if (str[0][i] != str[1][i] && str[0][i] - str[1][i] != 32 && str[0][i] - str[1][i] != -32)
		{
			f = 1;
			break;
		}
	}
	if (f == 1)
		return 0;
	else
		return 1;
}

int main() {
	char data[100];
	char* str[2];

	for (int i = 0; i < 2; i++)
	{
		scanf("%s", data);
		str[i] = (char*)malloc((strlen(data) + 1) * sizeof(char));
		strcpy(str[i], data);
	}

	printf("%s", (my_strcmp(str))?"true":"flase");

	for (int i = 0; i < 2; i++)
	{
		free(str[i]);
	}
	
}
