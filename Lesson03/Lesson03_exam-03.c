#include<stdio.h>

void x_transform(int x, int y) {
	y *= -1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j == ((x > 0) ? 1 : 2) + x && i == ((y > 0) ? 2 : 1) - y) {
				printf("X");
			}
			else {
				printf("O");
			}
		}
		printf("\n");
	}
}
void y_transform(int x, int y) {
	x *= -1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j == ((x > 0) ? 1 : 2) + x && i == ((y > 0) ? 2 : 1) - y) {
				printf("X");
			}
			else {
				printf("O");
			}
		}
		printf("\n");
	}
}
void xy_transform(int x, int y) {
	x *= -1;
	y *= -1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j == ((x > 0) ? 1 : 2) + x && i == ((y > 0) ? 2 : 1) - y) {
				printf("X");
			}
			else {
				printf("O");
			}
		}
		printf("\n");
	}
}

int main() {
	int x, y;
	printf("x: ");
	scanf("%d", &x);
	printf("y: ");
	scanf("%d", &y);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j == ((x > 0) ? 1 : 2) + x && i == ((y > 0) ? 2 : 1) - y) {
				printf("X");
			}
			else {
				printf("O");
			}
		}
		printf("\n");
	}
	printf("\n");
	x_transform(x, y);
	printf("\n");
	y_transform(x, y);
	printf("\n");
	xy_transform(x, y);
}
