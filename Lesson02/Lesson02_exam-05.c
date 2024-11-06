#include<stdio.h>

void asc_sort(int* arr) {
	for (int i = 0; i < 100; i++)
	{
		for (int j = i; j < 100; j++)
		{
			if (*(arr + i) > *(arr + j)) {
				int tmp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = tmp;
			}
		}
	}
}

void des_sort(int* arr) {
	for (int i = 0; i < 100; i++)
	{
		for (int j = i; j < 100; j++)
		{
			if (*(arr + i) < *(arr + j)) {
				int tmp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = tmp;
			}
		}
	}
}

int main() {
	int arr[100] = { 1,5 };
	char method = 0;

	for (int i = 2; i < 100; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15634;
	}

	printf("오름차순과 내림차순을 정하시오(오름차순:u,내림차순:d):");
	scanf("%c", &method);

	if (method == 'u')
		asc_sort(arr);
	else
		des_sort(arr);

	for (int i = 0; i < 100; i++)
	{
		printf("%d ", arr[i]);
	}

}
