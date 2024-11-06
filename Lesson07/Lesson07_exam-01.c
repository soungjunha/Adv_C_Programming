#include<stdio.h>

int main() {
	int dan;
	FILE* gu;
	gu = fopen("x_dan.txt", "w");
	scanf("%d", &dan);
	for (int i = 1; i <= 9; i++)
	{
		fprintf(gu, "%d * %d = %d\n", dan, i, dan * i);
	}
	fclose(gu);
}
