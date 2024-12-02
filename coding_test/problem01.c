#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int check_ID();

int main() {
	if (check_ID())
	{
		printf("admin mode");
	}
	else {
		printf("user mode");
	}
}

int check_ID() {
	char buffer[50];

	while (1)
	{
		printf("mode select(admin or user): ");
		scanf("%s", buffer);
		if (!strcmp(buffer, "admin")) {
			return 1;
		}
		else if (!strcmp(buffer, "user")) {
			return 0;
		}
		else {
			printf("wrong input\n");

		}
	}

}
