#include<stdio.h>
#include<stdlib.h>

int main() {
	int cnt = 0;
	int* num = NULL;
	int res = 0;
	printf("�Է� ����?");
	scanf("%d", &cnt);
	num = (int*)malloc(sizeof(int) * cnt);
	for (int i = 0; i < cnt; i++)
	{
		printf("%d��° ����: ", i + 1);
		scanf("%d", num + i);
	}
	for (int i = 0; i < cnt; i++)
	{
		if (*(num + i) % 2 == 0) res += *(num + i);
	}
	printf("¦����=> %d", res);
	free(num);
}
