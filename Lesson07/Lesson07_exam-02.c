#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	FILE* grade;
	char buffer[100], buffer2[10];
	char** name = (char**)malloc(1);
	int credit = 0;
	int toc = 0;
	float grade1 = 0;
	float totalg = 0;

	grade = fopen("grade.txt", "r");

	for (int i = 0; !feof(grade); i++)
	{
		if (i == 0) {
			fgets(buffer, 100, grade);
		}
		else {
			if (fscanf(grade, "%s %d %s", buffer, &credit, buffer2) != EOF) {
				name = (char**)realloc(name, i * sizeof(char*));
				name[i - 1] = (char*)malloc(strlen(buffer) * sizeof(char));
				toc += credit;

				strcpy(name[i - 1], buffer);
				if (!strcmp(buffer2, "A+"))
				{
					grade1 = 4.5;
				}
				else if (!strcmp(buffer2, "A0"))
				{
					grade1 = 4;
				}
				else if (!strcmp(buffer2, "B+"))
				{
					grade1 = 3.5;
				}
				else if (!strcmp(buffer2, "B0"))
				{
					grade1 = 3;
				}
				else if (!strcmp(buffer2, "C+"))
				{
					grade1 = 2.5;
				}
				else if (!strcmp(buffer2, "C0"))
				{
					grade1 = 2;
				}
				else if (!strcmp(buffer2, "D+"))
				{
					grade1 = 1.5;
				}
				else if (!strcmp(buffer2, "D0"))
				{
					grade1 = 1;
				}
				totalg += grade1 * credit;
				printf("%s %.1f\n", name[i - 1], grade1 * credit);
			}
		}
	}
	printf("√— ∆Ú¡°: %f", totalg / toc);
	for (int i = 0; i < toc; i++) {
		free(name[i]);
	}
	free(name);
	fclose(grade);
}
