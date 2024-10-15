#include<stdio.h>

int my_strcmp(char* str1, char* str2) {
	int i = 0;
	for (i = 0; *(str1 + i) != '\0' && *(str2 + i) != '\0'; i++)
	{
		if (*(str1 + i) > *(str2 + i)) {
			return 1;
		}
		else if (*(str1 + i) < *(str2 + i))
		{
			return -1;
		}
	}
	if (*(str1 + i) > *(str2 + i)) {
		return 1;
	}
	else if (*(str1 + i) < *(str2 + i))
	{
		return -1;
	}
	else
		return 0;
}

char* my_strcat(char* str1, char* str2, char* res) {
	int i = 0;
	for (i = 0; *(str1 + i) != '\0'; i++)
	{
		*(res + i) = *(str1 + i);
	}
	for (int j = 0; *(str2 + j) != '\0'; i++,j++)
	{
		*(res + i) = *(str2 + j);
	}
	*(res + i) = '\0';
	return res;
}
char* my_strcpy(char* str1, char* res) {
	int i = 0;
	for (i = 0; *(str1 + i) != '\0'; i++)
	{
		*(res + i) = *(str1 + i);
	}
	*(res + i) = '\0';
	return res;
}

int main() {
	char str1[6], str2[6];
	char res[11];
	scanf("%s", str1);
	scanf("%s", str2);
	printf("%d\n", my_strcmp(str1, str2));
	printf("%s\n", my_strcat(str1, str2, res));
	printf("%s\n", my_strcpy(str1, res));
}