#include<stdio.h>

int main() {
	union Rrn_or_callNum {
		char num[15];
	};
	struct Person
	{
		union Rrn_or_callNum id;
		char name[10];
	}person;

	printf("이름:");
	scanf("%s", &person.name);
	printf("전화번호 또는 주민번호:");
	scanf("%s", &person.id.num);

	printf("이름: %s\n", person.name);
	printf("전화번호/주민번호: %s", person.id.num);

}
