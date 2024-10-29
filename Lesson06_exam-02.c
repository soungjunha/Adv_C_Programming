#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char data[100];
	char* p[3];
	FILE* input;
	FILE* output;
	input = fopen("in.txt", "r");
	output = fopen("output2.txt", "w");
	for (int i = 0; i < 3; i++)
	{
		fscanf(input, "%s", data);
		p[i] = (char*)malloc(sizeof(char) * (strlen(data) + 1));
		for (int j = strlen(data); j > 0; j--)
		{
			*(p[i] + j - 1) = data[strlen(data) - j];
		}
		*(p[i] + strlen(data)) = '\0';
	}

	for (int i = 2; i >= 0; i--)
	{
		fprintf(output, "%s\n", p[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		free(p[i]);
	}
	fclose(input);
	fclose(output);
}
