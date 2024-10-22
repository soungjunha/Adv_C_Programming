#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char data[100];
	char* str;

	scanf("%s", data);
	str = (char*)malloc((strlen(data) + 1) * sizeof(char));

	strcpy(str, data);

	for (int i = 0; i < strlen(data); i++)
	{
		if (*(str + i) > 90)
			*(str + i) -= 32;
		else
			*(str + i) += 32;
	}

	printf("%s", str);

	free(str);
}
