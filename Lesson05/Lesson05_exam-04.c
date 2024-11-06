#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int n;
	int len = 1;
	char* roman_num = (char*)malloc(1);

	scanf("%d", &n);
	while (n!=0)
	{
		if (n - 900 >= 0) {
			n -= 900;
			len += 2;
			roman_num = (char*)realloc(roman_num, len * sizeof(char));
			roman_num[len - 3] = 'C';
			roman_num[len - 2] = 'M';
		}
		else if (n - 500 >= 0) {
			n -= 500;
			len += 1;
			roman_num = (char*)realloc(roman_num, len * sizeof(char));
			roman_num[len - 2] = 'D';
		}
		else if (n - 400 >= 0) {
			n -= 400;
			len += 2;
			roman_num = (char*)realloc(roman_num, len * sizeof(char));
			roman_num[len - 3] = 'C';
			roman_num[len - 2] = 'D';
		}
		else if (n - 100 >= 0) {
			n -= 100;
			len += 1;
			roman_num = (char*)realloc(roman_num, len * sizeof(char));
			roman_num[len - 2] = 'C';
		}
		else if (n - 90 >= 0) {
			n -= 90;
			len += 2;
			roman_num = (char*)realloc(roman_num, len * sizeof(char));
			roman_num[len - 3] = 'X';
			roman_num[len - 2] = 'C';
		}
		else if (n - 50 >= 0) {
			n -= 50;
			len += 1;
			roman_num = (char*)realloc(roman_num, len * sizeof(char));
			roman_num[len - 2] = 'L';
		}
		else if (n - 40 >= 0) {
			n -= 40;
			len += 2;
			roman_num = (char*)realloc(roman_num, len * sizeof(char));
			roman_num[len - 3] = 'X';
			roman_num[len - 2] = 'L';
		}
		else if (n - 10 >= 0) {
			n -= 10;
			len += 1;
			roman_num = (char*)realloc(roman_num, len * sizeof(char));
			roman_num[len - 2] = 'X';
		}
		else if (n - 9 >= 0) {
			n -= 9;
			len += 2;
			roman_num = (char*)realloc(roman_num, len * sizeof(char));
			roman_num[len - 3] = 'I';
			roman_num[len - 2] = 'X';
		}
		else if (n - 5 >= 0) {
			n -= 5;
			len += 1;
			roman_num = (char*)realloc(roman_num, len * sizeof(char));
			roman_num[len - 2] = 'V';
		}
		else if (n - 4 >= 0) {
			n -= 4;
			len += 2;
			roman_num = (char*)realloc(roman_num, len * sizeof(char));
			roman_num[len - 3] = 'I';
			roman_num[len - 2] = 'V';
		}
		else if (n - 1 >= 0) {
			n -= 1;
			len += 1;
			roman_num = (char*)realloc(roman_num, len * sizeof(char));
			roman_num[len - 2] = 'I';
		}
	}
	roman_num[len - 1] = '\0';
	printf("%s\n", roman_num);
	printf("%d", len-1);
	free(roman_num);
}
