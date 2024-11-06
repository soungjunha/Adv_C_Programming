#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char data[100];
	char* str[3];

	for (int i = 0; i < 2; i++)
	{
		printf("%d:", i + 1);
		gets_s(data, 100);
		str[i] = (char*)malloc(sizeof(char) * (strlen(data) + 1));
		strcpy(str[i], data);
	}
	str[2] = (char*)malloc(sizeof(char) * (strlen(str[0]) + strlen(str[1]) + 1));
	strcpy(str[2], str[0]);
	strcat(str[2], str[1]);
	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", str[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		free(str[i]);
	}
}
