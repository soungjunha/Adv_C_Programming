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

	printf("�̸�:");
	scanf("%s", &person.name);
	printf("��ȭ��ȣ �Ǵ� �ֹι�ȣ:");
	scanf("%s", &person.id.num);

	printf("�̸�: %s\n", person.name);
	printf("��ȭ��ȣ/�ֹι�ȣ: %s", person.id.num);

}
