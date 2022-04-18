/*1951393 自动化 张儒戈*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int cnt = 0;
int top[3] = { 0 };
int a[3][10] = { 0 };
/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
   3、允许添加用于输入层数、起始/目标柱的函数，函数中允许使用循环处理错误输入
   4、如果输入用函数进行，则main中不允许出现任何形式的循环（while、do-while、for、if-goto）
	  如果输入在main中进行，则main中允许出现循环
   --------------------------------------------------------------------- */


   /***************************************************************************
	 函数名称：
	 功    能：打印n层汉诺塔的移动顺序
	 输入参数：int n：层数
			   char src：起始柱
			   char tmp：中间柱
			   char dst：目标柱
	 返 回 值：
	 说    明：1、函数名、形参、返回类型均不准动
			   2、本函数不允许出现任何形式的循环
   ***************************************************************************/

void hanoi(int n, char src, char tmp, char dst)
{

	if (n == 1) {

		printf( "第%4d 步(%2d): %c-->%c ", ++cnt,n,src,dst);

		switch (src)
		{
		case 'A':
			switch (dst)
			{
			case 'B':
				a[1][top[1]++] = a[0][--top[0]];
				break;
			case 'C':
				a[2][top[2]++] = a[0][--top[0]];
				break;
			default:
				break;
			}

			break;
		case 'B':
			switch (dst)
			{
			case 'A':
				a[0][top[0]++] = a[1][--top[1]];
				break;
			case 'C':
				a[2][top[2]++] = a[1][--top[1]];
				break;
			default:
				break;
			}
			break;
		case 'C':
			switch (dst)
			{
			case 'B':
				a[1][top[1]++] = a[2][--top[2]];
				break;
			case 'A':
				a[0][top[0]++] = a[2][--top[2]];
				break;
			default:
				break;
			}

			break;
		default:
			break;
		}


		printf("A:");
		for (int i = 0; i < 10; i++) {
			if (i < top[0]) {
				printf("%2d", a[0][i]);
			}
			else {
				printf("  ");
			}
		}

		printf(" B:");
		for (int i = 0; i < 10; i++) {
			if (i < top[1]) {
				printf("%2d", a[1][i]);
			}
			else {
				printf("  ");
			}
		}

		printf(" C:");
		for (int i = 0; i < 10; i++) {
			if (i < top[2]) {
				printf("%2d", a[2][i]);
			}
			else {
				printf("  ");
			}
		}

		printf("\n");
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		printf("第%4d 步(%2d): %c-->%c ", ++cnt, n, src, dst);

		switch (src)
		{
		case 'A':
			switch (dst)
			{
			case 'B':
				a[1][top[1]++] = a[0][--top[0]];
				break;
			case 'C':
				a[2][top[2]++] = a[0][--top[0]];
				break;
			default:
				break;
			}

			break;
		case 'B':
			switch (dst)
			{
			case 'A':
				a[0][top[0]++] = a[1][--top[1]];
				break;
			case 'C':
				a[2][top[2]++] = a[1][--top[1]];
				break;
			default:
				break;
			}
			break;
		case 'C':
			switch (dst)
			{
			case 'B':
				a[1][top[1]++] = a[2][--top[2]];
				break;
			case 'A':
				a[0][top[0]++] = a[2][--top[2]];
				break;
			default:
				break;
			}

			break;
		default:
			break;
		}


		printf("A:");
		for (int i = 0; i < 10; i++) {
			if (i < top[0]) {
				printf("%2d", a[0][i]);
			}
			else {
				printf("  ");
			}
		}

		printf(" B:");
		for (int i = 0; i < 10; i++) {
			if (i < top[1]) {
				printf("%2d", a[1][i]);
			}
			else {
				printf("  ");
			}
		}

		printf(" C:");
		for (int i = 0; i < 10; i++) {
			if (i < top[2]) {
				printf("%2d", a[2][i]);
			}
			else {
				printf("  ");
			}
		}

		printf("\n");

		hanoi(n - 1, tmp, src, dst);

	}


}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：完成输入(或调用输入函数)、调用递归函数
***************************************************************************/
int main()
{
	int n;
	char src, dst, tmp = 'A';
	char ch;

	while (1) {
		printf("请输入汉诺塔的层数(1-10)\n");
		if (!scanf("%d", &n)) {
			while ((ch = getchar()) != EOF && ch != '\n')
				;
			continue;
		}
		while ((ch = getchar()) != EOF && ch != '\n')
			;

		if (n >= 1 && n <= 10) {
			break;
		}

	}


	while (1) {
		printf("请输入起始柱(A-C)\n");
		if (!scanf("%c", &src)) {
			while ((ch = getchar()) != EOF && ch != '\n')
				;
			continue;
		}

		while ((ch = getchar()) != EOF && ch != '\n')
			;
		if (src == 'A' || src == 'B' || src == 'C') {
			break;
		}
		if (src == 'a' || src == 'b' || src == 'c') {
			src += ('A' - 'a');
			break;
		}

	}


	while (1) {
		printf("请输入目标柱(A-C)\n");
		if (!scanf("%c", &dst)) {
			while ((ch = getchar()) != EOF && ch != '\n')
				;
			continue;
		}

		while ((ch = getchar()) != EOF && ch != '\n')
			;

		if (dst == 'A' || dst == 'B' || dst == 'C') {
			//cin.ignore(1024, '\n');
			if (dst == src) {
				printf("目标柱(%c)不能与起始柱(%c)相同\n", dst, src);
			}
			else {
				break;
			}
		}

		if (dst == 'a' || dst == 'b' || dst == 'c') {
			dst += ('A' - 'a');
			//cin.ignore(1024, '\n');
			if (dst == src) {
				printf("目标柱(%c)不能与起始柱(%c)相同\n", dst, src);
			}
			else {
				break;
			}
		}


	}

	while (tmp == dst || tmp == src)
		tmp++;


	switch (src)
	{
	case 'A':
		top[0] = n;
		for (int i = 0; i < n; i++) {
			a[0][i] = n - i;
		}
		break;
	case 'B':
		top[1] = n;
		for (int i = 0; i < n; i++) {
			a[1][i] = n - i;
		}
		break;
	case 'C':
		top[2] = n;
		for (int i = 0; i < n; i++) {
			a[2][i] = n - i;
		}
		break;
	default:
		break;
	}
	printf("初始:%16c",' ');

	printf("A:");
	for (int i = 0; i < 10; i++) {
		if (i < top[0]) {
			printf("%2d", a[0][i]);
		}
		else {
			printf("  ");
		}
	}

	printf(" B:");
	for (int i = 0; i < 10; i++) {
		if (i < top[1]) {
			printf("%2d", a[1][i]);
		}
		else {
			printf("  ");
		}
	}

	printf(" C:");
	for (int i = 0; i < 10; i++) {
		if (i < top[2]) {
			printf("%2d", a[2][i]);
		}
		else {
			printf("  ");
		}
	}

	printf("\n");


	hanoi(n, src, tmp, dst);

	return 0;
}
 