#include<stdio.h>

const float pi = 3.14;

float area(float r) {
	return pi * r * r;
}

float circumference(float r) {
	return 2 * pi * r;
}

int main() {
	int r;

	printf("반지름 입력:");
	scanf("%d", &r);

	printf("반지름: %d\n", r);
	printf("넓이: %lf\n", area(r));
	printf("둘레: %lf", circumference(r));


}
