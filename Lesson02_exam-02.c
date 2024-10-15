#include<stdio.h>

void swap1(int* arr) {

	int tmp;

	tmp = *arr;
	*arr = *(arr+1);
	*(arr + 1) = tmp;

}

void swap2(int* p1, int* p2) {

	int tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;

}

int main() {
	int arr[2];

	for (int i = 0; i < 2; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("before: ");
	for (int i = 0; i < 2; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	swap1(arr);
	printf("after: ");
	for (int i = 0; i < 2; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("---------------------------------------------\n");

	for (int i = 0; i < 2; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("before: ");
	for (int i = 0; i < 2; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	swap2(arr,arr+1);
	printf("after: ");
	for (int i = 0; i < 2; i++)
	{
		printf("%d ", arr[i]);
	}

}
