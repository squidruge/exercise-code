/*1951393 自动化 张儒戈*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int cnt = 0;
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
		printf("%5d:%3d# %c-->%c\n", ++cnt, n, src, dst);
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		printf("%5d:%3d# %c-->%c\n", ++cnt, n, src, dst);
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
		printf("请输入汉诺塔的层数(1-16)\n");
		if (!scanf("%d", &n)) {
			while ((ch = getchar()) != EOF && ch != '\n')
				;
			continue;
		}
		while ((ch = getchar()) != EOF && ch != '\n')
			;

		if (n >= 1 && n <= 16) {
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


	printf("移动步骤为:\n");
	hanoi(n, src, tmp, dst);

	return 0;
}

