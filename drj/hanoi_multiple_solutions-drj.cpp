#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;

/* -----------------------------------------

	 本文件功能：
	1、放被 hanoi_main.cpp/hanoi_menu.cpp 中的各函数调用的菜单各项对应的执行函数

	 本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------- */
static int sum = 0;  //记录移动步数
static int abc[3][10] = { {0},{0},{0} }; //赋初值
static int tabc[3] = { 0 };  //记录栈顶位置

/* 用于给sum，数组置零赋初值功能 */
void fresh()
{
	int i, j;
	sum = 0;
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			abc[i][j] = 0;
		}
		tabc[i] = 0;
	}
	return;
}
/* 竖着输出数组，输入参数为该数组以及初始的xy坐标点 */
void output_szline(int a[], int n, int x, int y) //竖着输出数组，输入参数为该数组以及初始的xy坐标点
{
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		cct_gotoxy(x, y - i);
		cout << a[i];
	}
	return;
}
/* 直到遇到enter键跳出 */
void is_enter()
{
	char ch;
	ch = _getch();
	while (ch != '\r')
	{
		ch = _getch();
	}
	return;
}

/* 记录栈顶位置,a[x]!=0时返回x+1,并且当a[0]==0时，返回0 */
int top(int a[], int n)
{
	int i = 0;
	for (i = n - 1; i >= 0; --i)
	{
		if (a[i] != 0)
			break;
	}
	return i + 1;    //记录栈顶的位置
}
/* 横向输出数组用 */
void output_sz(int a[], int n)   //输出某个数组以及后边的空格
{
	int k = 21 - 2 * n;
	for (int j = 0; j < n; ++j)
	{
		cout << setw(2) << a[j];
	}
	cout << setw(k) << " ";
	return;
}

/* 给数组赋值，a[0]存的数最大 */
void input_sz(int a[], int n)  //给数组赋值,a[0]存的最大
{
	int s = 0;
	int t = 1;
	for (s = n - 1; s >= 0; --s)
	{
		a[s] = t;
		t++;
	}
	return;
}

/* 填充初始时的盘子，输入参数为起始柱的序号和层数 */
void tianchongsz(char src, int n)
{
	input_sz(abc[src - 'A'], n);
}

/* 选项12不需要speed，可以默认为0 */
void print_steps_12(int n, char src, char tmp, char dst, char choice, int speed)
{
	if (choice == '1')
	{
		cout << n << "# " << src << "-->" << dst << endl;
	}
	if (choice == '2')
	{
		cout << "第" << setw(4) << ++sum << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ")" << endl;
	}
	return;
}
/* 对于348的横向打印 */
void print_steps_row(int n, char src, char tmp, char dst, char choice, int speed)
{
	if (choice == '3')
	{
		abc[src - 'A'][--tabc[src - 'A']] = 0;  //     abc[0][--tabc[0]] = 0;
		abc[dst - 'A'][tabc[dst - 'A']++] = n;		
		cout << "第" << setw(4) << ++sum << " " << "步(" << setw(2) << n << "#: " << src << "-->" << dst << ")  ";
		cout << "A:";
		output_sz(abc[0], tabc[0]);  //输出到栈顶
		cout << "B:";
		output_sz(abc[1], tabc[1]);
		cout << "C:";
		output_sz(abc[2], tabc[2]);
		cout << endl;
	}
	if (choice == '4'||choice=='8')
	{
		abc[src - 'A'][--tabc[src - 'A']] = 0;  //     abc[0][--tabc[0]] = 0;
		abc[dst - 'A'][tabc[dst - 'A']++] = n;
		switch (speed)
		{
			case 5:
				break;
			case 4:
				Sleep(50);
				break;
			case 3:
				Sleep(200);
				break;
			case 2:
				Sleep(500);
				break;
			case 1:
				Sleep(1000);
				break;
			case 0:
				is_enter();
				break;
		}
		if (choice == '4') //针对4 8位置不同用一个选择结构
		{
			cct_gotoxy(0, 17);
		}
		else
		{
			cct_gotoxy(0, 32);
		}
		cout << "第" << setw(4) << ++sum << " 步( " << n << "#: " << src << "-->" << dst << ")  ";
		cout << "A:";
		output_sz(abc[0], tabc[0]);  //输出到栈顶
		cout << "B:";
		output_sz(abc[1], tabc[1]);
		cout << "C:";
		output_sz(abc[2], tabc[2]);
	}
}
/* 对于48的纵向打印 */
void print_steps_column(int n, char src, char tmp, char dst, char choice, int speed)
{
	if (choice == '4')
	{
		cct_gotoxy(11 + (src - 'A') * 10, 11 - tabc[src - 'A']);   //跳到起始柱的栈顶位置
		cout << " ";
		cct_gotoxy(11 + (dst - 'A') * 10, 12 - tabc[dst - 'A']);   //跳到目标柱的栈顶位置
		cout << n;
	}
	if (choice == '8')
	{
		cct_gotoxy(11 + (src - 'A') * 10, 26 - tabc[src - 'A']);   //跳到起始柱的栈顶位置
		cout << " ";
		cct_gotoxy(11 + (dst - 'A') * 10, 27 - tabc[dst - 'A']);   //跳到目标柱的栈顶位置
		cout << n;
	}
}
/* 对于8,盘子的打印 */
void print_steps_plates(int n, char src, char tmp, char dst, char choice, int speed)
{
	move_once(14 - tabc[src - 'A'], 15 - tabc[dst - 'A'], n, src, tmp, dst, speed);
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}

/* 总的打印函数 */
void print_steps(int n, char src, char tmp, char dst, char choice, int speed)
{	
	if (choice == '1' || choice == '2')  //第一二种情况
	{
		print_steps_12(n, src, tmp, dst, choice, speed);
	}
	if (choice == '3' || choice == '4' || choice == '8')
	{
		print_steps_row(n, src, tmp, dst, choice, speed);
		if (choice == '4' || choice == '8')
		{
			print_steps_column(n, src, tmp, dst, choice, speed);
		}
		if (choice == '8')
		{
			print_steps_plates(n, src, tmp, dst, choice, speed);
		}
	}
}

/* 画柱子的函数,本题x与y带入1,15 */
void draw_tree(int x,int y)
{
	//cct_setcursor(CURSOR_INVISIBLE);  //关闭光标显示
	int i, j;
	for (i = 0; i < 3; ++i)  //打底座
	{
		cct_showch(x + 32 * i, y, ' ', COLOR_HYELLOW, COLOR_WHITE, 23);
	}
	for (i = 0; i < 12; ++i)  //打柱子
	{
		//cct_gotoxy(12 + x, y - 1 - i);
		for (j = 0; j < 3; ++j)
		{
			cct_showch(11 + x + 32 * j, y - 1 - i, ' ', COLOR_HYELLOW, COLOR_WHITE, 1);
		}
		Sleep(150);    //暂停0.15s，便于观察
	}
	//cct_setcursor(CURSOR_VISIBLE_NORMAL);  //光标显示正常
	return;
}

/* 输入为n时给src上画n个盘子 */
void draw_plates(int n, char src, char dst)
{
	//cct_setcursor(CURSOR_INVISIBLE);  //关闭光标显示
	int i = 0;
	int left_lowest = (12 + (src - 'A') * 32) - n;
	int lenth_begin = 2 * n + 1;
	for (i = 0; i < n; ++i)
	{
		cct_showch(left_lowest + i, 14 - i, ' ', n - i, COLOR_WHITE, lenth_begin - 2 * i);  //打盘子
		Sleep(50);
	}
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);  //恢复正常颜色
	//cct_setcursor(CURSOR_VISIBLE_NORMAL);  //光标显示正常
}

/* 把src上最上边的盘子从y==top搬到y==1的地方 */
void move_up(int top_src, int top_dst, int num_plate, char src, char tmp, char dst, int speed)
{
	int x, y, lenth;
	x = 12 + (src - 'A') * 32 - num_plate;  //起始src处最左边的x值
	lenth = 2 * num_plate + 1;
	for (y = top_src; y >= 1; y--)
	{
		cct_showstr(x, y, " ", num_plate, COLOR_WHITE, lenth);   // 在最左边打印lenth长度个空格		
		switch (speed)
		{
			case 5:
				break;
			case 4:
				Sleep(50);
				break;
			case 3:
				Sleep(100);
				break;
			case 2:
				Sleep(500);
				break;
			case 1:
				Sleep(1000);
				break;
			case 0:
				Sleep(100);     //此时单次闪烁间隔并不算慢，只是移动一个盘子按下一次enter
				break;
		}
		if (y != 1)
		{
			/* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
			cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, lenth);
			if (y > 2)
			{
				cct_showch(x + num_plate, y, ' ', COLOR_HYELLOW, COLOR_WHITE, 1);  //给中间的柱子重新上色
			}
		}
	}
}

/* 左右移动，从src头顶移动到dst头顶 */
void move_lr(int num_plate, char src, char tmp, char dst, int speed)
{
	int x, y, x0, x_dst, lenth;
	y = 1;
	int judge = dst - src;   //判断初始柱和目标柱谁大谁小
	x0 = 12 + (src - 'A') * 32 - num_plate;  //起始src处最左边的x值
	x_dst = 12 + (dst - 'A') * 32 - num_plate;   //终点dst处最左边的x值
	lenth = 2 * num_plate + 1;
	if (judge > 0)  //起始柱比较小，往右移动
	{
		for (x = x0; x <= x_dst; x++)
		{
			/* 在坐标(x,2)位置处连续打印10个字符 */
			cct_showch(x, y, ' ', num_plate, COLOR_WHITE, lenth);
			switch (speed)
			{
				case 5:
					break;
				case 4:
					Sleep(50);
					break;
				case 3:
					Sleep(100);
					break;
				case 2:
					Sleep(500);
					break;
				case 1:
					Sleep(1000);
					break;
				case 0:
					//is_enter();
					Sleep(100);     //此时单次闪烁间隔并不算慢，只是移动一个盘子按下一次enter
					break;
			}
			if (x < x_dst)
			{
				/* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
				cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, lenth);
			}
		} //end of for
	}
	if (judge < 0)  //起始柱比较小,往左移动
	{
		for (x = x0; x >= x_dst; x--)
		{
			/* 在坐标(x,1)位置处连续打印10个字符 */
			cct_showch(x, y, ' ', num_plate, COLOR_WHITE, lenth);
			switch (speed)
			{
				case 5:
					break;
				case 4:
					Sleep(50);
					break;
				case 3:
					Sleep(100);
					break;
				case 2:
					Sleep(500);
					break;
				case 1:
					Sleep(1000);
					break;
				case 0:
					//is_enter();
					Sleep(100);     //此时单次闪烁间隔并不算慢，只是移动一个盘子按下一次enter
					break;
			}
			if (x > x_dst)
			{
				/* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
				cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, lenth);
			}
		} //end of for
	}
}

/* 把dst上最上边的盘子从y==1搬到y==top的地方 */
void move_down(int top_src, int top_dst, int num_plate, char src, char tmp, char dst, int speed)
{
	int x, y, lenth;
	x = 12 + (dst - 'A') * 32 - num_plate;  //起始src处最左边的x值
	lenth = 2 * num_plate + 1;
	for (y = 1; y <= top_dst; y++)
	{
		cct_showstr(x, y, " ", num_plate, COLOR_WHITE, lenth);   // 在坐标(x,2)位置处连续打印10个字符		
		switch (speed)
		{
			case 5:
				break;
			case 4:
				Sleep(50);
				break;
			case 3:
				Sleep(100);
				break;
			case 2:
				Sleep(500);
				break;
			case 1:
				Sleep(1000);
				break;
			case 0:
				//is_enter();
				Sleep(100);     //此时单次闪烁间隔并不算慢，只是移动一个盘子按下一次enter
				break;
		}
		if (y < top_dst)
		{
			/* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
			cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, lenth);
			if (y < top_dst && y>2)
			{
				cct_showch(x + num_plate, y, ' ', COLOR_HYELLOW, COLOR_WHITE, 1);  //给中间的柱子重新上色
			}
		}
	}
}

/* 完成从src的top到dst的top一次移动的函数 */
void move_once(int top_src, int top_dst, int num_plate, char src, char tmp, char dst, int speed)
{
	//cct_setcursor(CURSOR_INVISIBLE);  //关闭光标显示
	move_up(top_src, top_dst, num_plate, src, tmp, dst, speed);
	move_lr(num_plate, src, tmp, dst, speed);
	move_down(top_src, top_dst, num_plate, src, tmp, dst, speed);
	//cct_setcursor(CURSOR_VISIBLE_NORMAL);  //光标显示正常
	return;
}

/* 菜单123项的功能函数 */
void mode_123(int n, char src, char tmp, char dst, char choice, int speed)
{
	cct_setcursor(CURSOR_INVISIBLE);  //关闭光标显示
	tianchongsz(src, n);  //给数组填充对应的盘子
	tabc[0] = top(abc[0], n);      //记录栈顶位置
	tabc[1] = top(abc[1], n);
	tabc[2] = top(abc[2], n);
	hanoi(n, src, tmp, dst, choice, speed);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);  //光标显示正常
	fresh();
	cout << endl;
	cout << "按回车键继续";
	is_enter();
}
/* 菜单4项的功能函数 */
void mode_4(int n, char src, char tmp, char dst, char choice, int speed)
{
	cct_setcursor(CURSOR_INVISIBLE);  //关闭光标显示
	tianchongsz(src, n);  //给数组填充对应的盘子
	tabc[0] = top(abc[0], n);      //记录栈顶位置
	tabc[1] = top(abc[1], n);
	tabc[2] = top(abc[2], n); 

	cct_cls();
	cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << speed;
	cct_gotoxy(0, 17);
	cout << "初始:  ";
	cout << "A:";
	output_sz(abc[0], tabc[0]);
	cout << "B:";
	output_sz(abc[1], tabc[1]);
	cout << "C:";
	output_sz(abc[2], tabc[2]);   //打印第一行

	cct_gotoxy(9, 12);  //打印底座部分
	cout << "=========================" << endl;
	cct_gotoxy(11, 13);
	cout << "A         B         C" << endl;

	output_szline(abc[0], tabc[0], 11, 11);
	output_szline(abc[1], tabc[1], 21, 11);
	output_szline(abc[2], tabc[2], 31, 11);
	hanoi(n, src, tmp, dst, choice, speed);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);  //光标显示正常
	fresh();   //初始化全局变量
	cct_gotoxy(0, 38);  //回到底下去打印结束提示
	cout << "按回车键继续";
	is_enter();
}
/* 菜单5项的功能函数 */
void mode_5()
{
	cct_setcursor(CURSOR_INVISIBLE);  //关闭光标显示
	cct_cls();
	draw_tree(1, 15);
	cct_setcolor(); //恢复缺省颜色;
	cct_gotoxy(0, 38);  //回到底下去打印结束提示
	cct_setcursor(CURSOR_VISIBLE_NORMAL);  //光标显示正常
	cout << "按回车键继续";
	is_enter();
}
/* 菜单6项的功能函数 */
void mode_6(int n, char src, char tmp, char dst)
{
	cct_setcursor(CURSOR_INVISIBLE);  //关闭光标显示
	cct_cls();  //清屏
	cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层";
	draw_tree(1, 15);
	draw_plates(n, src, dst);
	cct_setcolor(); //恢复缺省颜色
	cct_setcursor(CURSOR_VISIBLE_NORMAL);  //光标显示正常
	cct_gotoxy(0, 38);
	cout << "按回车键继续";
	is_enter();
}
/* 菜单7项的功能函数 */
void mode_7(int n, char src, char tmp, char dst, char choice, int speed)
{
	cct_setcursor(CURSOR_INVISIBLE);  //关闭光标显示
	cct_cls();  //清屏
	cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层";
	draw_tree(1, 15);
	Sleep(500);
	draw_plates(n, src, dst);
	Sleep(500);
	if (n % 2 == 1)
	{
		move_once(15 - n, 14, 1, src, tmp, dst, 3);  //计数挪到目标柱
	}
	else
	{
		move_once(15 - n, 14, 1, src, dst, tmp, 3);    //偶数挪到中转柱
	}
	cct_setcolor(); //恢复缺省颜色
	cct_gotoxy(0, 38);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);  //光标显示正常
	cout << "按回车键继续";
	is_enter();
}
/* 菜单8项的功能函数 */
void mode_8(int n, char src, char tmp, char dst, char choice, int speed)
{
	cct_setcursor(CURSOR_INVISIBLE);  //关闭光标显示
	tianchongsz(src, n);  //给数组填充对应的盘子
	tabc[0] = top(abc[0], n);      //记录栈顶位置
	tabc[1] = top(abc[1], n);
	tabc[2] = top(abc[2], n);

	cct_cls();
	cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << speed;
	cct_gotoxy(0, 32);
	cout << "初始:  ";
	cout << "A:";
	output_sz(abc[0], tabc[0]);
	cout << "B:";
	output_sz(abc[1], tabc[1]);
	cout << "C:";
	output_sz(abc[2], tabc[2]);   //打印第一行

	cct_gotoxy(9, 27);  //打印底座部分
	cout << "=========================" << endl;
	cct_gotoxy(11, 28);
	cout << "A         B         C" << endl;

	draw_tree(1, 15);
	draw_plates(n, src, dst);   //画盘子
	output_szline(abc[0], tabc[0], 11, 26);
	output_szline(abc[1], tabc[1], 21, 26);
	output_szline(abc[2], tabc[2], 31, 26);
	hanoi(n, src, tmp, dst, choice, speed);  //汉诺塔主要功能函数
	cct_setcursor(CURSOR_VISIBLE_NORMAL);  //光标显示正常
	fresh();   //初始化全局变量
	cct_gotoxy(0, 38);  //回到底下去打印结束提示
	cout << "按回车键继续";
	is_enter();
}
/* 游戏版本 */
void game_pattern(int n, char src, char tmp, char dst, char choice, int speed)
{
	char dst_first = dst;  //记录开始时的目标柱
	cct_setcursor(CURSOR_INVISIBLE);  //关闭光标显示
	tianchongsz(src, n);  //给数组填充对应的盘子
	tabc[0] = top(abc[0], n);      //记录栈顶位置
	tabc[1] = top(abc[1], n);
	tabc[2] = top(abc[2], n);
	char judge_9 = 'O';  //初始化,让它不为Q/q
	char tmparray[50] = " ";
	cct_cls();
	cout << "从" << src << "移动到" << dst << "，共" << n << "层";	
	cct_gotoxy(0, 32);
	cout << "初始:  ";
	cout << "A:";
	output_sz(abc[0], tabc[0]);
	cout << "B:";
	output_sz(abc[1], tabc[1]);
	cout << "C:";
	output_sz(abc[2], tabc[2]);   //打印第一行
	cct_gotoxy(9, 27);  //打印底座部分
	cout << "=========================" << endl;
	cct_gotoxy(11, 28);
	cout << "A         B         C" << endl;
	draw_tree(1, 15);     //画柱子
	draw_plates(n, src, dst);   //画盘子
	output_szline(abc[0], tabc[0], 11, 26);  //打印初始内部数组
	output_szline(abc[1], tabc[1], 21, 26);
	output_szline(abc[2], tabc[2], 31, 26);	
	while (judge_9 != 'Q')
	{		
		input(&n, &src, &dst, &speed, '9', &judge_9);  //给变量输入进去值  多次调用，容易出现问题  12.2中午
		if (judge_9 == 'Q')  //Q跳出
		{
			cct_gotoxy(0, 35);
			cout << "游戏中止!!!!!";
			break;
		}
		if (tabc[src - 'A'] == 0)  //栈顶是0，空柱
		{
			cct_gotoxy(0, 35);
			cout << "源柱为空!";
			Sleep(1500);
			cct_gotoxy(0, 35);
			cout << "          "; //打空格清空这几个字
			continue;
		}
		if (tabc[dst - 'A'] != 0 && abc[src - 'A'][tabc[src - 'A'] - 1] > abc[dst - 'A'][tabc[dst - 'A'] - 1])  //大盘压小盘
		{
			cct_gotoxy(0, 35);
			cout << "大盘压小盘，非法移动!";
			Sleep(1500);
			cct_gotoxy(0, 35);
			cout << "                            "; //打空格清空这几个字
			continue;
		}		
		abc[dst - 'A'][tabc[dst - 'A']++] = abc[src - 'A'][tabc[src - 'A'] - 1];  //把起始栈顶的给拿过去
		abc[src - 'A'][--tabc[src - 'A']] = 0;
		move_once(14 - tabc[src - 'A'], 15 - tabc[dst - 'A'], abc[dst - 'A'][tabc[dst - 'A'] - 1], src, tmp, dst, 5);
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);  //恢复颜色
		cct_gotoxy(0, 32);  //准备跳过去 打印横向内部数组
		cout << "第" << setw(4) << ++sum << " " << "步(" << setw(2) << abc[dst - 'A'][tabc[dst - 'A'] - 1] << "#: " << src << "-->" << dst << ")  ";
		cout << "A:";
		output_sz(abc[0], tabc[0]);  //输出到栈顶
		cout << "B:";
		output_sz(abc[1], tabc[1]);
		cout << "C:";
		output_sz(abc[2], tabc[2]);
		//跳过去打印纵向数组
		cct_gotoxy(11 + (src - 'A') * 10, 26 - tabc[src - 'A']);   //跳到起始柱的栈顶位置
		cout << " ";
		cct_gotoxy(11 + (dst - 'A') * 10, 27 - tabc[dst - 'A']);   //跳到目标柱的栈顶位置
		cout << abc[dst - 'A'][tabc[dst - 'A'] - 1];
		if (tabc[dst_first - 'A'] == n)  //玩家成功完成汉诺塔
		{
			cct_gotoxy(0, 35);
			cout << "游戏结束!!!!!";
			break;
		}
	} 
	cct_setcursor(CURSOR_VISIBLE_NORMAL);  //光标显示正常
	fresh();   //初始化全局变量
	cct_gotoxy(0, 38);  //回到底下去打印结束提示
	cout << "按回车键继续";
	is_enter();
}
/* 选择哪个模式进行输入 */
void mode_choice(int n, char src, char tmp, char dst, char choice, int speed)
{
	char judge_9 = 'P';
	switch (choice)
	{
		case '1':
		case '2':
		case '3':
			mode_123(n, src, tmp, dst, choice, speed);
			break;
		case '4':
			mode_4(n, src, tmp, dst, choice, speed);
			break;
		case '5':
			mode_5();
			break;
		case '6':
			mode_6(n, src, tmp, dst);
			break;
		case '7':
			mode_7(n, src, tmp, dst, choice, speed);
			break;
		case '8':
			mode_8(n, src, tmp, dst, choice, speed);
			break;
		case '9':
			input(&n, &src, &dst, &speed, '3', &judge_9);  //先初始输入基本参数
			game_pattern(n, src, tmp, dst, choice, speed);
			break;
		case '0':
			cct_gotoxy(0, 37);
			break;
	}
}


/***************************************************************************
	 函数名称：
	 功    能：打印n层汉诺塔的移动顺序
	 输入参数： int n：层数
			   char src：起始柱
			   char tmp：中间柱
			   char dst：目标柱
			   int choice: 菜单选项
			   int speed: 延迟选项
	 返 回 值：
	 说    明：1、函数名、形参、返回类型均不准动
			   2、本函数不允许出现任何形式的循环
			   3、允许定义一个静态局部变量
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst, char choice, int speed)
{	
	if (n == 1)   //1时结束
		print_steps(n, src, tmp, dst, choice, speed);
	else
	{
		hanoi(n - 1, src, dst, tmp, choice, speed);    //非1执行
		print_steps(n, src, tmp, dst, choice, speed);  //未完待续
		hanoi(n - 1, tmp, src, dst, choice, speed);
	}		
}

/* 第九题的单个字符输入函数,只要是可见字符或者是回车，就返回该键 */
char input_9_once()
{
	unsigned char ch;
	while (1)
	{
		ch = _getch();
		if (ch == 224)  //避免上下左右箭头干扰
		{
			ch = _getch();
			continue;
		}
		if (ch == '\r')  //回车返回
		{
			return ch;
		}
		if (ch >= 33 && ch <= 126) //可见字符就存进去
		{
			cout << ch;   //打出来原来字符，人工制造回显效果	
			if (ch >= 'a' && ch <= 'z')  //小写返回大写
			{
				ch = ch + 'A' - 'a';
			}
			return ch;
		}
	}
}

/* 对于char字符的输入，参数为提示句，判断是不是相等的char，选择模式 */
char input_char(const char remind[], char judge_char)
{
	char aim = '1';              //cout << "请输入起始柱(A-C)" << endl   cout << "请输入目标柱(A-C)" << endl;
	while (1)
	{
		cout << remind << endl;		
		cin >> aim;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;   //输入非法的话，就再输入，不再进行判断输入是否合理
		}
		cin.ignore(65536, '\n');  //是否非法都清空缓冲区

		if (aim >= 'a' && aim <= 'c')
		{
			aim = aim + 'A' - 'a';  //转大写
		}

		if (aim >= 'A' && aim <= 'C')
		{
			if (aim == judge_char)  //目标柱和起始柱相同就重新输
			{
				cout << "目标柱(" << aim << ")不能与起始柱(" << aim << ")相同" << endl;
				continue;
			}
			else
			{
				break;
			}
		}
	}
	return aim;
}
/* 用于输入层数和速度speed */
int input_int(const char remind[], const int min, const int max)
{
	int s = -1;  //移动速度(0-5)
	while (1)
	{
		cout << remind << endl;  //输出提示
		//cout << "请输入移动速度(0-5：0-按回车单步演示 1-延时最长 5-延时最短) " << endl;
		//cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> s;   
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(65536, '\n');
			continue;   //输入非法的话，就再输入，不再进行判断输入是否合理
		}
		cin.ignore(65536, '\n');  //正确也清空缓冲区
		if (s >= min && s <= max)
			break;
	}
	return s;
}
/* 总的输入参数函数，根据不同的choice来决定输入什么内容 */
void input(int* n, char* src, char* dst, int* speed, char choice, char* judge_9)
{
	int ch, i = 0, j = 0;
	//char src, dst;
	char tmparray[50] = " ";
	if (choice == '5')  //只画盘子的不用输入这些
		return;

	if (choice == '9')
	{
		cct_gotoxy(0, 34);
		cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
		while (1)
		{
			i = 0;  //初始化
			ch = 'F';  //初始化并且不能等于回车
			while (ch != '\r' && i < 20)  //不是回车并且没达到20个，就先等着一直输如，并且存起来
			{
				ch = input_9_once(); //再次输入
				tmparray[i] = ch;				
				i++;
			}  //跳出了就说明ch=='\r'了
			//合法输入1:输入了不相同的俩A-C字母(3是因为有空格)
			if (i == 3 && tmparray[0] >= 'A' && tmparray[0] <= 'C' && tmparray[1] >= 'A' && tmparray[1] <= 'C' && tmparray[0] != tmparray[1])
			{
				*src = tmparray[0];
				*dst = tmparray[1];
				break;
			}
			if (i == 2 && tmparray[0] == 'Q')  //合法输入2:输入了个Q
			{
				*judge_9 = tmparray[0];
				break;
			}  //否则清完屏显，继续输入
			cct_gotoxy(60, 34);
			for (j = 0; j < i; ++j)
				cout << " ";    //空格清除屏显
			cct_gotoxy(60, 34);
		}
		cct_gotoxy(60, 34);
		for (j = 0; j < i; ++j)
			cout << " ";    //空格清除屏显
		cct_gotoxy(60, 34);
		return;
	}
	*n = input_int("请输入汉诺塔的层数(1-10)", MIN_n, MAX_n);
	*src = input_char("请输入起始柱(A-C)", '\0');
	*dst = input_char("请输入目标柱(A-C)", *src);   //12 2晚 参量输入错误bug
	if (choice == '4' || choice == '8') //对于4和8再多加一次输入speed
	{
		*speed = input_int("请输入移动速度(0-5：0-按回车单步演示 1-延时最长 5-延时最短) ", MIN_speed, MAX_speed);
	}	
}
