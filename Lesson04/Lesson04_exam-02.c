#include<stdio.h>
#include<stdlib.h>

int main() {
	int cnt = 1, data = 0;
	int* num = NULL;
	int res = 0;
	num = (int*)malloc(sizeof(int) * 1);
	for (int i = 1; ; i++)
	{
		printf("%d¹øÂ° ¼ýÀÚ: ", i);
		scanf("%d", &data);
		if (data != 0)
		{
			cnt++;
			num = (int*)realloc(num, sizeof(int) * i);
			*(num + i - 1) = data;
		}
		else break;
	}
	for (int i = 0; i < cnt; i++)
	{
		if (*(num + i) % 2 == 0) res += *(num + i);
	}
	printf("Â¦¼öÇÕ=> %d", res);
	free(num);
}
