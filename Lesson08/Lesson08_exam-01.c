#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {

	struct subject
	{
		int credit;
		float grade;
		char* name;
	};

	struct subject* sub = (struct subject*)malloc(1);
	FILE* grade;
	char buffer[100], buffer2[10];
	char** name = (char**)malloc(1);
	int credit = 0;
	int toc = 0;
	int cnt = 0;
	float totalg = 0;

	grade = fopen("grade.txt", "r");

	for (int i = 0; !feof(grade); i++)
	{
		if (i == 0) {
			fgets(buffer, 100, grade);
		}
		else {
			cnt++;
			if (fscanf(grade, "%s %d %s", buffer, &credit, buffer2) != EOF) {
				sub = (struct subject*)realloc(sub, i * sizeof(struct subject));
				(sub + (i - 1))->name = (char*)malloc(strlen(buffer) * sizeof(char));
				(sub + (i - 1))->credit = credit;

				strcpy((sub + (i - 1))->name, buffer);
				if (!strcmp(buffer2, "A+"))
				{
					(sub + (i - 1))->grade = 4.5;
				}
				else if (!strcmp(buffer2, "A0"))
				{
					(sub + (i - 1))->grade = 4;
				}
				else if (!strcmp(buffer2, "B+"))
				{
					(sub + (i - 1))->grade = 3.5;
				}
				else if (!strcmp(buffer2, "B0"))
				{
					(sub + (i - 1))->grade = 3;
				}
				else if (!strcmp(buffer2, "C+"))
				{
					(sub + (i - 1))->grade = 2.5;
				}
				else if (!strcmp(buffer2, "C0"))
				{
					(sub + (i - 1))->grade = 2;
				}
				else if (!strcmp(buffer2, "D+"))
				{
					(sub + (i - 1))->grade = 1.5;
				}
				else if (!strcmp(buffer2, "D0"))
				{
					(sub + (i - 1))->grade = 1;
				}
				else
				{
					(sub + (i - 1))->grade = 0;
				}
			}
		}
	}
	for (int i = 0; i < cnt - 1; i++)
	{
		totalg += (sub + i)->credit * (sub + i)->grade;
		printf("%s: %.2f\n", (sub + i)->name, (sub + i)->credit * (sub + i)->grade);
		toc += (sub + i)->credit;
	}
	printf("√— ∆Ú¡°: %f", totalg / toc);
	for (int i = 0; i < cnt - 1; i++) {
		free((sub + i)->name);
	}
	free(sub);
	fclose(grade);
}
