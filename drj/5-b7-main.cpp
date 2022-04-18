/* 1951650 信02 戴仁杰 */
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "5-b7.h"
using namespace std;

int sum = 0;
int a[10] = { 0 }, b[10] = { 0 }, c[10] = { 0 };
int ta, tb, tc;
int yanshi, xianshi;  //延时和是否显示数组

/***************************************************************************
  函数名称：input_n
  功    能：完成合法输入层数
  输入参数：
  返 回 值：返回合法的输出
  说    明：
***************************************************************************/
int input_n()
{
	int x;  //汉诺塔的层数	
	while (1)
	{
		cout << "请输入汉诺塔的层数(1-10):" << endl;
		cin >> x;   //读入x的方式必须是cin>>int型变量			
		cin.clear();     //是否非法都清空缓存区
		cin.ignore(1024, '\n');
		if (cin.fail())
		{
			continue;   //输入非法的话，就再输入，不再进行判断输入是否合理
		}
		if (x >= 1 && x <= 10)
			break;
	}
	return x;
}

/***************************************************************************
  函数名称：input_src
  功    能：完成合法输入起始柱
  输入参数：
  返 回 值：返回合法的输出
  说    明：
***************************************************************************/
char input_src()
{
	char src = '1';
	while (1)
	{
		cout << "请输入起始柱(A-C):" << endl;
		cin >> src;
		cin.clear();     //是否非法都清空缓存区
		cin.ignore(1024, '\n');
		if (cin.fail())
		{
			continue;   //输入非法的话，就再输入，不再进行判断输入是否合理
		}
		if (src >= 'A' && src <= 'C')
		{
			break;
		}
		if (src >= 'a' && src <= 'c')
		{
			src = src - 32;   //小写转大写
			break;
		}
	}
	return src;
}

/***************************************************************************
  函数名称：input_dst
  功    能：完成合法输入目标柱
  输入参数：输入起始柱的号
  返 回 值：返回合法的输出
  说    明：
***************************************************************************/
char input_dst(char src)
{
	char dst = '1';
	while (1)
	{
		cout << "请输入目标柱(A-C):" << endl;
		cin >> dst;
		cin.clear();     //是否非法都清空缓存区
		cin.ignore(1024, '\n');
		if (cin.fail())
		{
			continue;   //输入非法的话，就再输入，不再进行判断输入是否合理
		}

		if (dst >= 'A' && dst <= 'C')
		{
			if (dst == src)  //目标柱和起始柱相同就重新输
			{
				cout << "目标柱(" << dst << ")不能与起始柱(" << dst << ")相同" << endl;
				continue;
			}
			else
			{
				break;
			}
		}
		if (dst >= 'a' && dst <= 'c')
		{
			dst = dst - 32;  //转大写
			if (dst == src)  //目标柱和起始柱相同就重新输
			{
				cout << "目标柱(" << dst << ")不能与起始柱(" << dst << ")相同" << endl;
				continue;
			}
			else
			{
				break;
			}
		}
	}
	return dst;
}

/* 输入合法的延时选择 */
void choice_yanshi()
{
	yanshi = -1;
	while (1)
	{
		cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
		cin >> yanshi;   
		if (cin.fail())
		{			
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (yanshi >= 0 && yanshi <= 5)
			break;
	}
	return;
}
/* 输入合法的显示选择 */
void choice_xianshi()
{
	xianshi = -1;
	while (1)
	{
		cout << "请输入是否显示内部数组值(0-不显示 1-显示))" << endl;
		cin >> xianshi;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (xianshi >= 0 && xianshi <= 1)
			break;
	}
	return;
}

/* 直到遇到enter键跳出 */
void is_enter()
{
	char ch;
	ch = _getch();
	while (ch != 13)
	{
		ch = _getch();
	}
	return;
}

/* 记录栈顶位置 */
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

/* 输入输出数组部分，完成对指定数组的输入输出 */
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

void output_szline(int a[], int n, int x, int y) //竖着输出数组，输入参数为该数组以及初始的xy坐标点
{
	int i = 0;	
	for (i = 0; i < n; ++i)
	{
		cct_gotoxy(x, y-i);
		cout << a[i];
	}	
	return;
}
void output_space(int n, int x, int y)  //竖着打印n个空格用于局部清屏，后两个参数为初始xy坐标点
{
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		cct_gotoxy(x, y - i);
		cout << " ";
	}
	return;
}

void input_sz(int a[], int n)  //给数组赋值
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
	if (src == 'A')
	{
		input_sz(a, n);
	}
	if (src == 'B')
	{
		input_sz(b, n);
	}
	if (src == 'C')
	{
		input_sz(c, n);
	}     //根据起始柱赋初值
}

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
			3、允许定义一个静态局部变量
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	int i = 0;
	if (sum == 0 && n == 1)  //只有当没输出且执行到最后一层的时候才输出一次
	{	
		if (xianshi == 1)
		{
			cct_gotoxy(0, 17);
			cout << "初始:" << setw(16) << " ";
			cout << "A:";
			output_sz(a, ta);
			cout << "B:";
			output_sz(b, tb);
			cout << "C:";
			output_sz(c, tc);   //打印第一行
		}
		if (yanshi == 0 && xianshi == 1)
		{
			is_enter();
		}
		cct_gotoxy(9, 12);  //打印底座部分
		cout << "=========================" << endl;
		cct_gotoxy(11, 13);
		cout << "A         B         C" << endl;
		
		output_szline(a, ta, 11, 11);
		output_szline(b, tb, 21, 11);
		output_szline(c, tc, 31, 11);
	}

	if (n == 1)
	{		
		if (src == 'A')
		{
			a[--ta] = 0;
		}
		if (src == 'B')
		{
			b[--tb] = 0;
		}
		if (src == 'C')
		{
			c[--tc] = 0;
		}
		if (dst == 'A')
		{
			a[ta++] = 1;
		}
		if (dst == 'B')
		{
			b[tb++] = 1;
		}
		if (dst == 'C')
		{
			c[tc++] = 1;
		}

		//设置延迟时间
		switch (yanshi)
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
		cct_gotoxy(0, 17);
		cout << "第" << setw(4) << ++sum << "步(" << 1 << "#: " << src << "-->" << dst << ")  ";
		if (xianshi == 1)
		{
			cout << "A:";
			output_sz(a, ta);  //输出到栈顶
			cout << "B:";
			output_sz(b, tb);
			cout << "C:";
			output_sz(c, tc);
		}
		//cout << endl;
		if (xianshi == 1 && yanshi == 0)
		{
			is_enter();
		}
		output_space(10, 11, 11);				
		output_space(10, 21, 11);			
		output_space(10, 31, 11);
		output_szline(a, ta, 11, 11);
		output_szline(b, tb, 21, 11);
		output_szline(c, tc, 31, 11);		
	}
	else
	{
		hanoi(n - 1, src, dst, tmp);
		if (src == 'A')
		{
			a[--ta] = 0;
		}
		if (src == 'B')
		{
			b[--tb] = 0;
		}
		if (src == 'C')
		{
			c[--tc] = 0;
		}
		if (dst == 'A')
		{
			a[ta++] = n;
		}
		if (dst == 'B')
		{
			b[tb++] = n;
		}
		if (dst == 'C')
		{
			c[tc++] = n;
		}

		//设置延迟时间
		switch (yanshi)
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
		cct_gotoxy(0, 17);
		cout << "第" << setw(4) << ++sum <<  "步(" << n << "#: " << src << "-->" << dst << ")  ";
		if (xianshi == 1)
		{
			cout << "A:";
			output_sz(a, ta);  //输出到栈顶
			cout << "B:";
			output_sz(b, tb);
			cout << "C:";
			output_sz(c, tc);
		}

		if (xianshi == 1 && yanshi == 0)
		{
			is_enter();
		}

		output_space(10, 11, 11);
		output_space(10, 21, 11);
		output_space(10, 31, 11);
		output_szline(a, ta, 11, 11);
		output_szline(b, tb, 21, 11);
		output_szline(c, tc, 31, 11);

		hanoi(n - 1, tmp, src, dst);
	}
}

int main()
{
	int n = input_n();
	char src = input_src();
	char dst = input_dst(src);
	char tmp = 198 - src - dst;
	choice_yanshi();
	choice_xianshi();   //以上完成合法输入初始化部分

	tianchongsz(src, n);  //给数组填充对应的盘子

	ta = top(a, n);      //记录栈顶位置
	tb = top(b, n);
	tc = top(c, n);
	cct_cls();

	cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << yanshi << "，";
	if (!xianshi)
	{
		cout << "不";
	}
	cout << "显示内部数组值" << endl;  //输出第一行

	hanoi(n, src, tmp, dst);
	cct_gotoxy(0, 27);
	return 0;
}