#include<stdio.h>

int main() {
	enum Month
	{
		January=1,
		February=2,
		March=3,
		April=4,
		May=5,
		June=6,
		July=7,
		August=8,
		September=9,
		October=10,
		November=11,
		December=12
	};

	enum Month mon;
	printf("월: ");
	scanf("%d", &mon);

	printf("%d월은 ", mon);

	switch (mon)
	{
	case January:
		printf("%s입니다.","January");
		break;
	case February:
		printf("%s입니다.", "February");
		break;
	case March:
		printf("%s입니다.", "March");
		break;
	case April:
		printf("%s입니다.", "April");
		break;
	case May:
		printf("%s입니다.", "May");
		break;
	case June:
		printf("%s입니다.", "June");
		break;
	case July:
		printf("%s입니다.", "July");
		break;
	case August:
		printf("%s입니다.", "August");
		break;
	case September:
		printf("%s입니다.", "September");
		break;
	case October:
		printf("%s입니다.", "October");
		break;
	case November:
		printf("%s입니다.", "November");
		break;
	case December:
		printf("%s입니다.", "December");
		break;
	default:
		break;
	}

}
