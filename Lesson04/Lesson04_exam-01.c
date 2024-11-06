#include<stdio.h>
#include<stdlib.h>

int main() {
	int cnt = 0;
	int* num = NULL;
	int res = 0;
	printf("입력 개수?");
	scanf("%d", &cnt);
	num = (int*)malloc(sizeof(int) * cnt);
	for (int i = 0; i < cnt; i++)
	{
		printf("%d번째 숫자: ", i + 1);
		scanf("%d", num + i);
	}
	for (int i = 0; i < cnt; i++)
	{
		if (*(num + i) % 2 == 0) res += *(num + i);
	}
	printf("짝수합=> %d", res);
	free(num);
}
