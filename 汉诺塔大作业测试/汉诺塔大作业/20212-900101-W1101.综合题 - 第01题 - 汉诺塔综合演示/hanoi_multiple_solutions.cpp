/*1951393 自动化 张儒戈*/


/* ----------------------------------------------------------------------------------

	 本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

	 本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
#define ax 11 //数组塔柱中心
#define bx 21
#define cx 31
#define plate_Ax 1		//第一个盘柱的最左侧
#define colum_Ax 12		//第一个盘柱
#define PlateLength 23	//盘底宽度
#define dizuo_y_mode8 27  //mode8 数组塔的底座
#define dizuo_y_mode4 12  //mode4 数组塔的底座
#define plate_chazhi (PlateLength+9) //盘柱间的差值
#define plate_y 15	//盘底

using namespace std;

static int cnt; //总移动步数
static int delay;//延时设置

static int top[3] = { 0 }; //圆柱上现有圆盘的数量 top[i] 依次为 A B C
static int plate[3][10] = { 0 };//圆柱上现有圆盘的 行标表示柱

const int x[3] = { ax,bx,cx };//数组塔柱中心x坐标，封装成数组方便使用
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
void hanoi(int n, char src, char tmp, char dst, char mode)
{
	if (n == 1) {
		hanoi_step(n, src, tmp, dst, mode);
	}
	else {
		hanoi(n - 1, src, dst, tmp, mode);
		hanoi_step(n, src, tmp, dst, mode);
		hanoi(n - 1, tmp, src, dst, mode);
	}
}
/***************************************************************************
  函数名称：hanoi_step
  功    能：不同模式对应汉诺塔每次要完成的内容
  输入参数：int n：层数
			char src：起始柱
			char tmp：中间柱
			char dst：目标柱
  返 回 值：
  说    明：
***************************************************************************/
void hanoi_step(int n, char src, char tmp, char dst, char mode)
{
	if (mode == '1') {
		cout << n << "# " << src << "---->" << dst << endl;
	}
	if (mode == '2') {
		cout << "第" << setw(4) << ++cnt << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ")" << endl;
	}
	if (mode == '3') {
		yidong_sz(src, dst);//移动数组中的盘子编号
		printline(n, src, dst, mode);//横向打印
	}
	if (mode == '4') {

		yidong_sz(src, dst);//移动数组中的盘子编号

		printline(n, src, dst, mode);//横向打印
		printshu(src, dst, mode);//纵向输出

		yanshi();

	}
	if (mode == '8' || mode == '9') {

		yidong_sz(src, dst);//移动数组中的盘子编号

		printline(n, src, dst, mode);//横向打印

		cct_setcursor(CURSOR_INVISIBLE);
		printshu(src, dst, mode);//纵向输出

		move_once(n, src, tmp, dst);
		yanshi();
	}

}

/***************************************************************************
  函数名称：input
  功    能：输入部分
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void input(char* psrc, char* pdst, char* ptmp, int* pn, char mode)
{
	cout << endl << endl << endl;
	int n;
	char src, dst, tmp = 'A';

	while (1) {
		cout << "请输入汉诺塔的层数(1-10)：" << endl;
		cin >> n;
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
		cout << "请输入起始柱(A-C)：" << endl;
		cin >> src;
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
		cout << "请输入目标柱(A-C)：" << endl;
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

			if (dst == src) {
				cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
			}
			else {
				break;
			}
		}
	}
	tmp = 'A' + 'B' + 'C' - dst - src;

	*pn = n;
	*psrc = src;
	*pdst = dst;
	*ptmp = tmp;

	if (mode == '4' || mode == '8') {
		delay_input();
	}
}
/***************************************************************************
  函数名称：modeXX
  功    能：各个模式对应的函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void mode123(char mode, int n, char src, char dst, char tmp)
{
	Plate_Init(src, n);
	hanoi(n, src, tmp, dst, mode);
	cout << endl;
}

void mode4(int n, char src, char dst, char tmp)
{
	cct_setcursor(CURSOR_INVISIBLE);

	Plate_Init(src, n);
	chushihua(src, dst, n, '4');

	hanoi(n, src, tmp, dst, '4');

	cct_gotoxy(0, 38);   //转到下方打印结束提示
}

void mode5()
{
	cct_setcursor(CURSOR_INVISIBLE);   //关闭光标显示
	cct_cls();
	cnt = 0;
	draw_column();

	cct_setcolor(); //恢复缺省颜色;
	cct_gotoxy(0, 38);   //转到下方打印结束提示
}

void mode6(int n, char src, char dst, char tmp)
{
	cct_setcursor(CURSOR_INVISIBLE);   //关闭光标显示
	cct_cls();

	cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层" << endl;
	draw_column();
	draw_plate(src, n);

	cct_setcolor(); //恢复缺省颜色;
	cct_gotoxy(0, 38);  //回到底下去打印结束提示
}

void mode7(int n, char src, char dst, char tmp)
{
	delay = 4;

	Plate_Init(src, n);

	cct_setcursor(CURSOR_INVISIBLE);   //关闭光标显示
	cct_cls();

	cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层" << endl;
	draw_column();
	draw_plate(src, n);
	Sleep(1000);

	if (n % 2)
	{
		yidong_sz(src, dst);
		move_once(1, src, tmp, dst);  //奇数->目标柱
	}
	else
	{
		yidong_sz(src, tmp);
		move_once(1, src, dst, tmp);    //偶数->中转柱
	}
	cct_gotoxy(0, 38);   //转到下方打印结束提示
}
void mode8(int n, char src, char dst, char tmp)
{
	Plate_Init(src, n);

	chushihua(src, dst, n, '8');

	cct_setcursor(CURSOR_INVISIBLE);   //关闭光标显示

	draw_column();

	draw_plate(src, n);
	Sleep(1000);
	yanshi();
	hanoi(n, src, tmp, dst, '8');

	cct_gotoxy(0, 38);   //转到下方打印结束提示
}


void mode9(int n, char src, char dst, char tmp)
{

	char src_cur = 'A', dst_cur = 'A';//当前要移动的 src 和 dst

	delay = 5;

	Plate_Init(src, n);

	chushihua(src, dst, n, '9');//使用9的初始化函数

	cct_setcursor(CURSOR_INVISIBLE);   //关闭光标显示

	draw_column();
	draw_plate(src, n);

	int i = 0;
	char ch;

	while (1)
	{
		cct_setcolor(); //恢复缺省颜色;
		cct_gotoxy(0, 34);
		cct_setcursor(CURSOR_VISIBLE_NORMAL);  //光标显示正常
		cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
		cct_gotoxy(60, 34);

		cct_setcursor(CURSOR_VISIBLE_NORMAL);
		//输入20个自动清除
		for (i = 0; i < 20; i++) {

			ch = getch_mode9();

			if (i == 0)
				src_cur = ch;

			if (i == 1)
				dst_cur = ch;

			if (ch == 13)
				break;

		}

		if (judge(n, i, src_cur, dst_cur))
			break;

		if (top[dst - 'A'] == n) {

			cct_setcolor(); //恢复缺省颜色;
			cct_gotoxy(0, 35);
			cout << "游戏结束!!!!!" << endl;
			break;
		}

	}
	cct_gotoxy(0, 38);   //转到下方打印结束提示
}
/***************************************************************************
  函数名称：
  功    能：竖向打印,用于初始化
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void print_shu(int a[], int top, int x, int y)
{

	cct_setcolor();
	for (int i = 0; i < top; i++) {
		cct_gotoxy(x - 1, y - i);
		if (i < top) {
			cout << setw(2) << a[i];
		}
	}

}

/***************************************************************************
  函数名称：
  功    能：输入延时参数
  输入参数：
  返 回 值：
  说    明：mode4 mode8
***************************************************************************/
void delay_input()
{
	while (1) {
		cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短) " ;
		cin >> delay;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');

			continue;
		}
		cin.ignore(1024, '\n');
		if (delay >= 0 && delay <= 5) {

			break;
		}

	}
}

/***************************************************************************
  函数名称：
  功    能：移动纵向的数组塔，非图形
  输入参数：
  返 回 值：
  说    明：mode4 mode8
***************************************************************************/
void printshu(char src, char dst, char mode)
{
	cct_setcolor();
	int y = dizuo_y_mode8 - 1;

	if (mode == '4') {
		y = dizuo_y_mode4 - 1;
	}

	if (mode == '8') {
		y = dizuo_y_mode8 - 1;
	}
	 
	cct_gotoxy(x[src - 'A'] - 1, y - top[src - 'A']);
	cout << setw(2) << " ";
	cct_gotoxy(x[dst - 'A'] - 1, y + 1 - top[dst - 'A']);
	cout << setw(2) << plate[dst - 'A'][top[dst - 'A'] - 1];

}

/***************************************************************************
  函数名称：
  功    能：等待读取enter
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
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

/***************************************************************************
  函数名称：
  功    能：移动数组内的盘子
  输入参数：
  返 回 值：
  说    明：虽然只有一句，封装起来便于使用
***************************************************************************/
void yidong_sz(char src, char dst)
{

	plate[dst - 'A'][top[dst - 'A']++] = plate[src - 'A'][--top[src - 'A']];

}
/***************************************************************************
  函数名称：
  功    能：横向打印数组 3 4 8 9
  输入参数：
  返 回 值：
  说    明：mode3 mode4 mode8 mode9
***************************************************************************/
void printline(int n, char src, char dst, char mode)
{

	if (mode != 'I') {
		if (mode == '4') {
			cct_gotoxy(0, 17);
		}
		if (mode == '8' || mode == '9') {
			cct_setcolor();
			cct_gotoxy(0, 32);
		}
		cout << "第" << setw(4) << ++cnt << "步(" << setw(2) << n << "#: " << src << "-->" << dst << ")  ";
	}

	cout << "A:";
	for (int i = 0; i < 10; i++) {
		if (i < top[0]) {
			cout << setw(2) << plate[0][i];
		}
		else {
			cout << "  ";
		}
	}

	cout << " B:";
	for (int i = 0; i < 10; i++) {
		if (i < top[1]) {
			cout << setw(2) << plate[1][i];
		}
		else {
			cout << "  ";
		}
	}

	cout << " C:";
	for (int i = 0; i < 10; i++) {
		if (i < top[2]) {
			cout << setw(2) << plate[2][i];
		}
		else {
			cout << "  ";
		}
	}

	cout << endl;

}

/***************************************************************************
  函数名称：
  功    能：mode4 mode8 对应的延时，并非mode8中盘移动的速度
  输入参数：
  返 回 值：
  说    明： mode4
***************************************************************************/
void yanshi()
{
	switch (delay)
	{
	case 5:
		break;
	case 4:
		Sleep(30);
		break;
	case 3:
		Sleep(150);
		break;
	case 2:
		Sleep(300);
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

/***************************************************************************
  函数名称：
  功    能：mode8对应移动过程的延时
  输入参数：
  返 回 值：
  说    明： mode8
***************************************************************************/
void yanshi_move()
{
	switch (delay)
	{
	case 5:
		break;
	case 4:
		Sleep(30);
		break;
	case 3:
		Sleep(100);
		break;
	case 2:
		Sleep(300);
		break;
	case 1:
		Sleep(600);
		break;
	case 0:
		Sleep(30);
		break;
	}
}

/***************************************************************************
  函数名称：chushihua
  功    能： 横向纵向打印初始的数组
  输入参数：
  返 回 值：
  说    明：用于 mode4 mode8 mode9
***************************************************************************/
void chushihua(char src, char dst, int n, char mode)
{
	cct_cls();
	cct_setcolor();
	int y = dizuo_y_mode8 - 1;

	if (mode == '4') {
		y = dizuo_y_mode4 - 1;
	}
	if (mode == '8'|| mode == '9') {
		y = dizuo_y_mode8 - 1;
	}

	if (mode == '4' || mode == '8') {
		cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << delay << endl;
	}
	else if(mode == '9') {
		cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层" << endl;
	}
	

	cct_gotoxy(0, y + 6);


	cout << "初始:" << "  ";
	printline(n, src, dst, 'I'); //I表示mode为初始化init
	//yanshi();

	cct_gotoxy(9, y + 1);
	cout << "=========================";
	cct_gotoxy(11, y + 2);
	cout << "A         B         C" << endl;

	print_shu(plate[0], top[0], 11, y);
	print_shu(plate[1], top[1], 21, y);
	print_shu(plate[2], top[2], 31, y);

	if (mode == '4') {
		yanshi();
	}
}

/***************************************************************************
  函数名称：Plate_Init
  功    能： 向起始柱逆序填入n个数字，即初始盘子 top为 最后一个元素的下一个位置
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void Plate_Init(char src, int n)
{
	top[src-'A'] = n;
	for (int i = 0; i < n; i++) {
		plate[src-'A'][i] = n - i;
	}

}

/***************************************************************************
  函数名称：draw_column
  功    能： 画柱
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void draw_column()
{
	const int len = 23;//低座长度
	for (int i = 0; i < 3; i++) {

		cct_showch(plate_Ax + i * plate_chazhi, plate_y, ' ', COLOR_HYELLOW, COLOR_WHITE, len);
	}
	for (int j = 1; j <= 12; j++) {
		for (int i = 0; i < 3; i++) {
			cct_showch(colum_Ax + i * plate_chazhi, plate_y - j, ' ', COLOR_HYELLOW);
			Sleep(50);
		}
	}
}

/***************************************************************************
  函数名称：draw_plate
  功    能： 画盘
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void draw_plate(char src, int n)
{

	for (int j = 1; j <= n; j++) {

		cct_showch(colum_Ax + (src - 'A') * plate_chazhi - (n - j + 1), plate_y - j, ' ', n - j + 1, 7, 2 * (n - j + 1) + 1);
		Sleep(50);
	}
}

/***************************************************************************
  函数名称：move_once
  功    能： 移动一次
  输入参数：
  返 回 值：
  说    明：此时数组已经移动完成
***************************************************************************/
void move_once(int n, char src, char tmp, char dst)
{
	cct_setcursor(CURSOR_INVISIBLE);  //关闭光标显示
	move_up(n, src, dst);
	move_lr(n, src, dst);
	move_down(n, dst);
}
/***************************************************************************
  函数名称：move_lr
  功    能： 左右移动，从src头顶移动到dst头顶
  输入参数：int n, char src, char dst, int delay
  返 回 值：
  说    明：此时数组已经移动完成
***************************************************************************/
void move_lr(int n, char src, char dst)
{
	int x, y, x_src, x_dst, len;

	y = 1;

	x_src = colum_Ax + (src - 'A') * plate_chazhi - n;  //src最左边的x 
	x_dst = colum_Ax + (dst - 'A') * plate_chazhi - n;  //dst最左边的x 
	len = 2 * n + 1;

	if (x_src < x_dst) {
		for (x = x_src; x <= x_dst; x++) {
			cct_showch(x, y, ' ', n, 7, len);
			yanshi_move();

			cct_showch(x, y, ' ', 0, 7, len);
			if (delay != 5) {
				Sleep(30);
			}
		}
	}
	else {
		for (x = x_src; x >= x_dst; x--) {
			cct_showch(x, y, ' ', n, 7, len);

			yanshi_move();

			cct_showch(x, y, ' ', 0, 7, len);
			if (delay != 5) {
				Sleep(30);
			}
		}
	}
}

/***************************************************************************
  函数名称：move_up
  功    能：上移
  输入参数：int n 总盘数  char src, char dst,
  返 回 值：
  说    明：此时数组已经移动完成
***************************************************************************/
void move_up(int n, char src, char dst)
{
	int x, y, len;
	y = 15 - top[src - 'A'] - 1;//原柱中的位置

	int plate_xuhao;
	plate_xuhao = plate[dst - 'A'][top[dst - 'A'] - 1];//获得移动的盘的自身标号

	x = colum_Ax + (src - 'A') * plate_chazhi - plate_xuhao;  //src最左边的x 

	len = 2 * plate_xuhao + 1;



	for (; y >= 1; y--) {
		cct_showch(x, y, ' ', plate_xuhao, 7, len);
		yanshi_move();

		cct_showch(x, y, ' ', 0, 7, len);
		if (y >= 3 && y <= 14) {
			cct_showch(colum_Ax + (src - 'A') * plate_chazhi, y, ' ', 14);
		}
		if (delay != 5) {
			Sleep(30);
		}
	}

}

/***************************************************************************
  函数名称：move_down
  功    能：下移
  输入参数：int n 盘编号 与汉诺塔递归函数保持一致   char dst, int delay
  返 回 值：
  说    明：此时数组已经移动完成
***************************************************************************/
void move_down(int n, char dst)
{
	int x, y, len;

	y = 1;
	int plate_xuhao;
	plate_xuhao = plate[dst - 'A'][top[dst - 'A'] - 1];

	x = colum_Ax + (dst - 'A') * plate_chazhi - plate_xuhao;  //src最左边的x 

	len = 2 * plate_xuhao + 1;


	for (; y <= 15 - top[dst - 'A']; y++) {

		cct_showch(x, y, ' ', plate_xuhao, 7, len);
		yanshi_move();
		//Sleep(100);


		if (y != 15 - top[dst - 'A']) {
			cct_showch(x, y, ' ', 0, 7, len);
			if (y >= 3 && y <= 14) {
				cct_showch(colum_Ax + (dst - 'A') * plate_chazhi, y, ' ', 14);
			}
		}

		if (delay != 5) {
			Sleep(30);
		}

	}

}


/***************************************************************************
  函数名称：
  功    能：mode9 得到单个字符的函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char getch_mode9()
{

	unsigned char ch;

	while (1)
	{
		ch = _getch();

		if (ch == 13)
		{
			return ch;
		}

		if (ch == 224)  //去除方向键干扰
		{
			ch = _getch();
			continue;
		}

		if (ch >= 33 && ch <= 126)
		{
			cout << ch;
			if (ch >= 'a' && ch <= 'z')  //小写转大写
			{
				ch += 'A' - 'a';
			}
			return ch;
		}

	}
}

/***************************************************************************
  函数名称：
  功    能：mode9 判断输入的字符的执行含义
  输入参数：
  返 回 值：1表示按下了Q 要退出循环
  说    明：
***************************************************************************/
int judge(int n, int i, char src_cur, char dst_cur)
{
	int flag = 0;//1 表示跳出
	int src_cur_bianhao, dst_cur_bianhao;//当前 起始 和 目标 最上方的盘编号
	src_cur_bianhao = plate[src_cur - 'A'][top[src_cur - 'A'] - 1];
	dst_cur_bianhao = plate[dst_cur - 'A'][top[dst_cur - 'A'] - 1];

	if (i == 1) {

		if (src_cur == 'Q' || src_cur == 'q') {
			cct_gotoxy(0, 35);
			cout << "游戏中止!!!!!" << endl;
			flag = 1;
		}
		else {
			cct_showch(60, 34, ' ', 0, 7, 25);//清除字符

		}
	}
	else if (i == 2 && src_cur >= 'A' &&
		src_cur <= 'C' && dst_cur >= 'A' &&
		dst_cur <= 'C' && src_cur != dst_cur) {

		//只输入两个字符，且在ABC中

		cct_gotoxy(0, 35);
		if (top[src_cur - 'A'] == 0) {
			cout << "源柱为空!" << endl;
			Sleep(1500);
			cct_showch(60, 34, ' ', 0, 7, 25);//清除字符
			cct_showch(0, 35, ' ', 0, 7, 25);//清除错误提示
		}
		else if ((src_cur_bianhao > dst_cur_bianhao) && top[dst_cur - 'A'] != 0) {
			cout << "大盘压小盘，非法移动!" << endl;
			Sleep(1500);
			cct_showch(60, 34, ' ', 0, 7, 25);//清除字符
			cct_showch(0, 35, ' ', 0, 7, 25);//清除错误提示
		}
		else {

			cct_showch(60, 34, ' ', 0, 7, 25);//清除字符
			hanoi_step(src_cur_bianhao, src_cur, 'A' + 'B' + 'C' - src_cur - dst_cur, dst_cur, '9');

		}
	}
	else {

		cct_showch(60, 34, ' ', 0, 7, 25);//清除字符
	}

	return flag;
}

/***************************************************************************
  函数名称：
  功    能：根据选项调用菜单各项对应的执行函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void ChooseMode(char mode, int n, char src, char dst, char tmp)
{
	Global_Init();

	switch (mode)
	{
	case '1':
	case '2':
	case '3':
		mode123(mode, n, src, dst, tmp);
		break;
	case '4':
		mode4(n, src, dst, tmp);
		break;
	case '5':
		mode5();
		break;
	case '6':
		mode6(n, src, dst, tmp);
		break;
	case '7':
		mode7(n, src, dst, tmp);
		break;
	case '8':
		mode8(n, src, dst, tmp);
		break;
	case '9':
		mode9(n, src, dst, tmp);
		break;
	default:
		break;
	}
}

/***************************************************************************
  函数名称：
  功    能：对全局变量置零初始化
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void Global_Init()
{
	cnt = 0;

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {
			plate[i][j] = 0;
		}
		top[i] = 0;
	}
}