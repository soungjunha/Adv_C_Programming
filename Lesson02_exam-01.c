#include<stdio.h>

void swap1(int a, int b) {
	int tmp;

	tmp = a;
	a = b;
	b = tmp;
	printf("after in function: A: %d B: %d\n", a, b);
}

void swap2(int* p1, int* p2) {

	int tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
	printf("after in function: A: %d B: %d\n", *p1, *p2);
}

int main() {
	int a, b;

	printf("A: ");
	scanf("%d", &a);
	printf("B: ");
	scanf("%d", &b);

	swap1(a, b);
	printf("after in main: A: %d B: %d\n", a, b);
	swap2(&a, &b);

	printf("after in main: A: %d B: %d\n", a, b);

}
