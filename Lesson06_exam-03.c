#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort_acending(char** str) {
	char* temp;
	for (int i = 0; str[i][0] != '\0'; i++) {
		for (int j = 0; str[j][0] != '\0'; j++) {
			if (str[j][0] > str[i][0] != '\0') {
				temp = str[j][0];
				str[j][0] = str[i][0];
				str[i][0] = temp;
			}
		}
	}
}

void sort_decending(char** str) {
	char* temp;
	for (int i = 0; str[i][0] != '\0'; i++) {
		for (int j = 0; str[j][0] != '\0'; j++) {
			if (str[j][0] < str[i][0] != '\0') {
				temp = str[j][0];
				str[j][0] = str[i][0];
				str[i][0] = temp;
			}
		}
	}
}

void write_result_to_file(char** str) {
	FILE* desending, * asending;
	desending = fopen("Result_Desending.txt", "w");
	asending = fopen("Result_Asending.txt", "w");

	sort_acending(str);
	for (int i = 0; str[i][0]!='\0'; i++)
	{
		fprintf(asending, "%d. %s\n", i+1, str[i]);
	}
	sort_decending(str);
	for (int i = 0; str[i][0] != '\0'; i++)
	{
		fprintf(desending, "%d. %s\n", i + 1, str[i]);
	}

	fclose(desending);
	fclose(asending);
}

int main() {
	char buffer[100];
	char* str_a[5];
	char* str_b[20];
	FILE* input;
	int cnt = 0,lcnt=0;
	input = fopen("data.txt", "r");

	for (int i = 0; !feof(input); i++)
	{
		fgets(buffer, 100, input);
		str_a[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
		strcpy(str_a[i], buffer);
		lcnt++;
	}

	for (int i = 0; i < lcnt-1; i++) {
		int start = 0;
		int length = strlen(str_a[i]);
		for (int j = 0; j <= length; j++) {
			if (str_a[i][j] == ',' || str_a[i][j] == '\0' || str_a[i][j] == '\n') {
				if (j > start) {
					int token_length = j - start;
					str_b[cnt] = (char*)malloc((token_length + 1) * sizeof(char));
					strncpy(str_b[cnt], &str_a[i][start], token_length);
					str_b[cnt][token_length] = '\0';
					cnt++;
				}
				start = j + 1;
			}
		}
	}
	str_b[cnt] = (char**)malloc(1);
	str_b[cnt][0] = '\0';

	write_result_to_file(str_b);

	for (int i = 0; i < 5; i++)
	{
		free(str_a[i]);
	}

	for (int i = 0; i < 20; i++)
	{
		free(str_b[i]);
	}

	fclose(input);
}
