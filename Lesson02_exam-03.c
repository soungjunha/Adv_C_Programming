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

	printf("������ �Է�:");
	scanf("%d", &r);

	printf("������: %d\n", r);
	printf("����: %lf\n", area(r));
	printf("�ѷ�: %lf", circumference(r));


}
