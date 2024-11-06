#include<stdio.h>
#include<string.h>

void asc_sort(char* arr, int len) {
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len; j++)
		{
			if (*(arr + i) < *(arr + j)) {
				char tmp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = tmp;
			}
		}
	}
}

void des_sort(char* arr,int len) {
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len; j++)
		{
			if (*(arr + i) > *(arr + j)) {
				char tmp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = tmp;
			}
		}
	}
}

void input_char(char* arr,char* method) {
	gets_s(arr, 101);

	
	printf("오름차순과 내림차순을 정하시오(오름차순:u,내림차순:d):");
	scanf(" %c", &method);
}

void func_print(char* arr) {
	printf("%s", arr);
}

int main() {
	char arr[101];
	char method = 0;
	int len;

	input_char(arr, &method);
	len = strlen(arr);

	if (method == 'u')
		asc_sort(arr,len);
	else
		des_sort(arr,len);
	func_print(arr);

}
