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
	printf("��: ");
	scanf("%d", &mon);

	printf("%d���� ", mon);

	switch (mon)
	{
	case January:
		printf("%s�Դϴ�.","January");
		break;
	case February:
		printf("%s�Դϴ�.", "February");
		break;
	case March:
		printf("%s�Դϴ�.", "March");
		break;
	case April:
		printf("%s�Դϴ�.", "April");
		break;
	case May:
		printf("%s�Դϴ�.", "May");
		break;
	case June:
		printf("%s�Դϴ�.", "June");
		break;
	case July:
		printf("%s�Դϴ�.", "July");
		break;
	case August:
		printf("%s�Դϴ�.", "August");
		break;
	case September:
		printf("%s�Դϴ�.", "September");
		break;
	case October:
		printf("%s�Դϴ�.", "October");
		break;
	case November:
		printf("%s�Դϴ�.", "November");
		break;
	case December:
		printf("%s�Դϴ�.", "December");
		break;
	default:
		break;
	}

}
