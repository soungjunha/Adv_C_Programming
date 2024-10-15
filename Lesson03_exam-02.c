#include<stdio.h>
int main() {
	int mat[4][8];
	for (int i = 0; i < 8; i++)
	{
		scanf("%d", (*(mat + 0) + i));
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 8; j += 2)
		{
			*(*(mat + i + 1) + j / 2) = *(*(mat + i) + j) + *(*(mat + i) + j + 1);
		}
	}
	printf("%d", *(*(mat + 3)));
}