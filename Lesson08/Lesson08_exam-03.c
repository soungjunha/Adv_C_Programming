#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	struct student
	{
		char* name;
		float en;
		float kr;
	};

	struct avg_score
	{
		float* persnal_avg;
		float en_avg;
		float kr_avg;
		float total_avg;
	};

	int num;
	int total_score=0;
	struct student* students;
	struct avg_score avg = { NULL,0,0,0 };
	char buffer[20];
	FILE* avg_student;

	scanf("%d", &num);

	students = (struct student*)malloc(sizeof(struct student) * num);
	avg.persnal_avg = (float*)malloc(sizeof(float) * num);
	avg_student = fopen("average_student.txt", "w");

	for (int i = 0; i < num; i++)
	{
		printf("학생 이름: ");
		scanf("%s", buffer);
		students[i].name = (char*)malloc(sizeof(char) * (strlen(buffer)+1));
		strcpy(students[i].name, buffer);
		printf("국어 점수: ");
		scanf("%f", &students[i].kr);
		printf("영어 점수: ");
		scanf("%f", &students[i].en);
		avg.persnal_avg[i] = (students[i].kr + students[i].en) / 2;
		avg.kr_avg += students[i].kr;
		avg.en_avg += students[i].en;
		avg.total_avg += avg.persnal_avg[i];
		fprintf(avg_student, "%s: %.1f\n",students[i].name, avg.persnal_avg[i]);
	}
	avg.kr_avg /= num;
	avg.en_avg /= num;
	avg.total_avg /= num;

	fprintf(avg_student, "국어 평균: %.1f\n", avg.kr_avg);
	fprintf(avg_student, "영어 평균: %.1f\n", avg.en_avg);
	fprintf(avg_student, "총 평균: %.1f", avg.total_avg);

	fclose(avg_student);

}
