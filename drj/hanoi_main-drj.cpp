#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;

/* -----------------------------------------

	 本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

	 本文件要求：
	1、不允许定义全局变量（含外部全局和静态全集，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------- */

   /***************************************************************************
	 函数名称：
	 功    能：
	 输入参数：
	 返 回 值：
	 说    明：
   ***************************************************************************/
int main()
{
	char choice='P', src='\0', tmp='\0', dst='\0';
	char judge_9 = '\0';   //用于第9项存储是不是Q/q来用
	int n = 0, speed = 0;
	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while (choice != '0')
	{   
		cct_cls();
		choice = menu();
		cout << choice << endl << endl << endl;
		if (choice != '0' && choice != '5' && choice != '9')  //5不用输入参数，9在下方单独输入参数
		{
			input(&n, &src, &dst, &speed, choice, &judge_9);  //总输入函数，唯一允许使用指针的函数，同时改变多个参数值
			tmp = 'A' + 'B' + 'C' - src - dst;
		}
		mode_choice(n, src, tmp, dst, choice, speed); //执行各个菜单选项的功能性函数		
	}
	return 0;
}
