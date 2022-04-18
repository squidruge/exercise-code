/*1951393 自动化 张儒戈*/
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "5-b7.h"

#define ax 11
#define bx 21
#define cx 31
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、仅允许hanoi中定义一个静态局部变量
   3、允许添加用于输入层数、起始/目标柱的函数，函数中允许使用循环处理错误输入
   4、如果输入用函数进行，则main中不允许出现任何形式的循环（while、do-while、for、if-goto）
	  如果输入在main中进行，则main中允许出现循环
   --------------------------------------------------------------------- */

int topA = 0, topB = 0, topC = 0;
int A[10] = { 0 }, B[10] = { 0 }, C[10] = { 0 };
static int speed;
static bool xianshi;
int cnt = 0;

void print_shu(int a[],int top,int x,int y)//竖向打印,用于初始化
{
	

	for (int i = 0; i < top; i++) {
		cct_gotoxy(x-1, y-i);
		if (i < top) {
			cout <<setw(2)<< a[i];
		}
		
		
	}

}

void speed_input()
{
	while (1) {
		cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
		cin >> speed;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');

			continue;
		}
		cin.ignore(1024, '\n');
		if (speed >=0&&speed<=5) {
			
			break;
		}
		
	}
}

void yidong(char src,char dst)
{
	
	switch (src)
	{
	case 'A':
		switch (dst)
		{
		case 'B':
			cct_gotoxy(ax-1, 11-topA);
			cout << setw(2)<< " ";
			cct_gotoxy(bx - 1, 12-topB);
			cout << setw(2)<<B[topB-1];

			break;
		case 'C':
			cct_gotoxy(ax - 1, 11-topA);
			cout << setw(2)<< " ";
			cct_gotoxy(cx - 1, 12-topC);
			cout << setw(2) << C[topC-1];
			break;
		default:
			break;
		}

		break;
	case 'B':
		switch (dst)
		{
		case 'A':
			cct_gotoxy(bx - 1, 11-topB);
			cout << "  ";
			cct_gotoxy(ax - 1, 12-topA );
			cout << setw(2) << A[topA-1];
			break;
		case 'C':
			cct_gotoxy(bx - 1, 11-topB);
			cout << "  ";
			cct_gotoxy(cx - 1, 12-topC);
			cout << setw(2) << C[topC-1];
			break;
		default:
			break;
		}
		break;
	case 'C':
		switch (dst)
		{
		case 'B':
			cct_gotoxy(cx - 1, 11-topC);
			cout << "  ";
			cct_gotoxy(bx - 1, 12-topB);
			cout << setw(2) << B[topB-1];
			break;
		case 'A':
			cct_gotoxy(cx - 1, 11-topC);
			cout << "  ";
			cct_gotoxy(ax - 1, 12-topA);
			cout << setw(2) << A[topA-1];
			break;
			break;
		default:
			break;
		}

		break;
	default:
		break;
	}
}

void is_enter()
{
	int ch;
	ch = _getch();
	while (ch != 13)
	{
		ch = _getch();
	}
	return;
}


void xianshi_input()
{
	while (1) {
		cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
		cin >> xianshi;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');

			continue;
		}
		cin.ignore(1024, '\n');
		if (xianshi == 0 || xianshi ==1) {

			break;
		}

	}
}


void yidong_sz(char src,char dst)
{
	switch (src)
	{
	case 'A':
		switch (dst)
		{
		case 'B':
			B[topB++] = A[--topA];
			break;
		case 'C':
			C[topC++] = A[--topA];
			break;
		default:
			break;
		}

		break;
	case 'B':
		switch (dst)
		{
		case 'A':
			A[topA++] = B[--topB];
			break;
		case 'C':
			C[topC++] = B[--topB];
			break;
		default:
			break;
		}
		break;
	case 'C':
		switch (dst)
		{
		case 'B':
			B[topB++] = C[--topC];
			break;
		case 'A':
			A[topA++] = C[--topC];
			break;
		default:
			break;
		}

		break;
	default:
		break;
	}
}
void printline()
{
	cout << "A:";
	for (int i = 0; i < 10; i++) {
		if (i < topA) {
			cout << setw(2) << A[i];
		}
		else {
			cout << "  ";
		}
	}

	cout << " B:";
	for (int i = 0; i < 10; i++) {
		if (i < topB) {
			cout << setw(2) << B[i];
		}
		else {
			cout << "  ";
		}
	}

	cout << " C:";
	for (int i = 0; i < 10; i++) {
		if (i < topC) {
			cout << setw(2) << C[i];
		}
		else {
			cout << "  ";
		}
	}

	cout << endl;



}


void yanshi()//延时
{
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
	default:
		break;
	}
	return;
}
//初始化
void chushihua(char src, char dst, int n) {
	cct_cls();
	if (xianshi) {
		cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << speed << "，显示内部数组值" << endl;
	}
	else {
		cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << speed << "，不显示内部数组值" << endl;
	}

	cct_gotoxy(0, 17);
	//cout << "初始:" << setw(16) << " ";
	if (xianshi) {
		cout << "初始:" << setw(16) << " ";
		printline();
		yanshi();
	}


	cct_gotoxy(9, 12);
	cout << "=========================";
	cct_gotoxy(11, 13);
	cout << "A         B         C" << endl;
	//int x = 11 + 10 * (ch - 'A'), y = 11;
	print_shu(A, topA, 11, 11);
	print_shu(B, topB, 21, 11);
	print_shu(C, topC, 31, 11);
	yanshi();


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
	//chushihua(src, dst, n);


	if (n == 1) {
		cct_gotoxy(0, 17);
		cout << "第" << setw(4) << ++cnt << "步(" << n << "#: " << src << "-->" << dst << ")  ";

		yidong_sz(src, dst);
		if (xianshi) {
			printline();
			yanshi();
		}
		yidong(src, dst);

		yanshi();
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		cct_gotoxy(0, 17);
		//cout << setw(5) << ++cnt << ":" << setw(3) << n << "# " << src << "-->" << dst << endl;
		cout << "第" << setw(4) << ++cnt << "步(" << n << "#: " << src << "-->" << dst << ")  ";
		yidong_sz(src, dst);

		if (xianshi) {
			printline();
			yanshi();
		}
		yidong(src, dst);

		yanshi();

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

	while (1) {
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> n;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		cin.ignore(1024, '\n');
		if (n >= 1 && n <= 10) {
			break;
		}

	}

	while (1) {
		cout << "请输入起始柱(A-C)" << endl;
		cin >> src;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');

			continue;
		}
		cin.ignore(1024, '\n');
		if (src == 'A' || src == 'B' || src == 'C') {
			//cin.ignore(1024, '\n');
			break;
		}
		if (src == 'a' || src == 'b' || src == 'c') {
			src += ('A' - 'a');
			//cin.ignore(1024, '\n');
			break;
		}

	}


	while (1) {
		cout << "请输入目标柱(A-C)" << endl;
		cin >> dst;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		cin.ignore(1024, '\n');

		if (dst == 'A' || dst == 'B' || dst == 'C') {
			//cin.ignore(1024, '\n');
			if (dst == src) {
				cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
			}
			else {
				break;
			}
		}

		if (dst == 'a' || dst == 'b' || dst == 'c') {
			dst += ('A' - 'a');
			//cin.ignore(1024, '\n');
			if (dst == src) {
				cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
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
		topA = n;
		for (int i = 0; i < n; i++) {
			A[i] = n - i;
		}
		break;
	case 'B':
		topB = n;
		for (int i = 0; i < n; i++) {
			B[i] = n - i;
		}
		break;
	case 'C':
		topC = n;
		for (int i = 0; i < n; i++) {
			C[i] = n - i;
		}
		break;
	default:
		break;
	}

	speed_input();
	xianshi_input();
	chushihua(src, dst, n);



	//getchar();
	
	hanoi(n, src, tmp, dst);
	//getchar();
	cct_gotoxy(0, 27);
	return 0;
}