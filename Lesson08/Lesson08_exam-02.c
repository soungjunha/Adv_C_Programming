#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	struct student
	{
		char* name;
		int age;
	};

	struct student* students;
	char buffer[30];
	int num;

	scanf("%d", &num);
	students = (struct student*)malloc(sizeof(struct student) * num);
	for (int i = 0; i < num; i++)
	{
		printf("이름과 나이: ");
		scanf("%s %d", buffer, &students[i].age);
		students[i].name = (char*)malloc(sizeof(char) * (strlen(buffer)+1));
		strcpy(students[i].name, buffer);
	}

	for (int i = 0; i < num; i++)
	{
		printf("이름: %s 나이: %d", students[i].name, students[i].age);
	}
	for (int i = 0; i < num; i++)
	{
		free(students[i].name);
	}
	free(students);
}
