/*1951393 自动化 张儒戈*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdbool.h>
#define month1 31
#define month2 28
#define month3 31
#define month4 30
#define month5 31
#define month6 30
#define month7 31
#define month8 31
#define month9 30
#define month10 31
#define month11 30
#define month12 31
 
int main()
{
	int year, month, first;
	bool isLeap = false;
	int day = 0;
	char ch;
	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		//scanf("%d", &x); //读入x的方式必须是scanf且格式符为%d，不准用非scanf
		if (!scanf("%d", &year)) {
			while ((ch = getchar()) != EOF && ch != '\n')
				;
			printf("输入非法，请重新输入\n"); 
			continue;
		}
		
		if ( !scanf("%d", &month)) {
			while ((ch = getchar()) != EOF && ch != '\n')
				;
			printf("输入非法，请重新输入\n");
			continue;
		}

		if ((year >= 2000 && year <= 2030)&&(month >= 1 && month <= 12)) {
			break;
		}
		else {
			printf("输入非法，请重新输入\n");
			continue;
		}
	}
	

	while (1) {
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", year, month);
		
		if (!scanf("%d", &first)) {
			while ((ch = getchar()) != EOF && ch != '\n')
				;
			printf("输入非法，请重新输入\n");
			continue;
		}
		if (first >= 0 && first <= 6) 
			break;
		printf("输入非法，请重新输入\n");
	}



	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		isLeap = true;
	}

	switch (month)
	{
	case 1:
		day = month1;
		break;
	case 2:
		day = month2 + isLeap;
		break;
	case 3:
		day = month3;
		break;
	case 4:
		day = month4;
		break;
	case 5:
		day = month5;
		break;
	case 6:
		day = month6;
		break;
	case 7:
		day = month7;
		break;
	case 8:
		day = month8;
		break;
	case 9:
		day = month9;
		break;
	case 10:
		day = month10;
		break;
	case 11:
		day = month11;
		break;
	case 12:
		day = month12;
		break;
	default:
		break;
	}

	printf("\n%d年%d月的月历为:\n", year, month);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	int cnt0;
	for (cnt0 = 0; cnt0 < first; cnt0++) {
		printf( "        ");
	}
	int cnt1;
	for (cnt1 = 1; cnt1 <= day; cnt1++) {
		if ((cnt1 + first) % 7) {
			printf("%4d    ",cnt1);
		}
		else {
			printf("%4d\n", cnt1);
		}
	}



	return 0;
}
