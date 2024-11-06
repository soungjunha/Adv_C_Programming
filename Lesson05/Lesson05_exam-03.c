#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char data[100];
	char** str;
	int n;
	int len = 0;

	printf("°³¼ö:");
	scanf("%d", &n);

	str = (char**)malloc(strlen(data) * sizeof(char*));

	for (int i = 0; i < n; i++)
	{
		scanf("%s", data);
		str[i] = (char*)malloc((strlen(data) + 1) * sizeof(char));
		strcpy(str[i], data);
		if (len < strlen(data))
			len = strlen(data);
	}

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < strlen(str[j]))
				printf("%c", str[j][i]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		free(str[i]);
	}
	free(str);

}
