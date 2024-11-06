#include<stdio.h>

void seive(int* arr) {
	for (int i = 2; i < 31; i++)
	{
		for (int j = 2 * i; j <= 30; j += i)
		{
			arr[j] = 1;
		}
	}
}

int main() {
	int arr[31] = { 1,1, };

	seive(arr);

	for (int i = 0; i <= 30; i++)
	{
		if (arr[i] == 0)
			printf("%d ", i);
	}

}
