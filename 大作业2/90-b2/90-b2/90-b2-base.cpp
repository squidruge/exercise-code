/*1951393 自动化 张儒戈*/

#include <iostream>
#include <conio.h>
#include "90-b2.h"
#include<time.h> 
#include<iomanip> 
#include <Windows.h>
#include "cmd_console_tools.h"

using namespace std;
 

/***************************************************************************
  函数名称：
  功    能：mode  '1' '2' 的实现 '2'是递归方式 此函数通过传参可被其他mode调用
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int mode12(int matrix[][10], int matrix_mark[][10], int& x, int& y, int xm, int ym, char mode)
{

	int flag = 0;//标记每次循环寻找有无标记增加，无增加，则退出循环 题目1有用

	cout << "当前数组：" << endl;
	print_matrix(matrix, matrix_mark, 0, 0, xm, ym);


	int num = 0; //matrix[y][x] ;

	//无可合并项则结束
	if (is_over(matrix, matrix_mark, xm, ym)) {

		cct_setcolor(COLOR_HYELLOW, COLOR_RED);
		cout << "无可合并的项，游戏结束" << endl;
		cct_setcolor();

		if (mode == '1' || mode == '2') {
			int X, Y;
			cct_getxy(X, Y);
			is_end(0, Y + 1);

		}
		return 0;
	}

	while (1) {

		cout << "请以字母+数字形式[例：c2]输入矩阵坐标：";
		input_posi(matrix_mark, matrix, x, y, num, xm, ym);

		if (mode == '1') {
			while (1) {
				flag = 0;
				for (int j = 0; j <= ym; j++) {
					for (int i = 0; i <= xm; i++) {

						if (matrix_mark[j][i]) {

							if (find_near(matrix, matrix_mark, i, j, xm, ym, '1'))
								flag++;//如果一轮循环有加标志，则flag不为0

						}
					}
				}

				if (!flag) {
					break;
				}
			}
		}
		else if (mode == '2') {
			find_near(matrix, matrix_mark, x, y, xm, ym, '2');//递归函数
		}
		else {
			find_near(matrix, matrix_mark, x, y, xm, ym, '2');//用于其他小题利用mode12 选择递归与否无差别
		}

		if (count(matrix_mark, 1, xm, ym) > 1) {
			cout << endl;
			break;
		}
		else {

			cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
		}
	}


	cout << "查找结果数组：" << endl;
	print_matrix(matrix_mark, matrix_mark, 0, 1, xm, ym);


	cout << endl << "当前数组：(不同色标识)" << endl;
	print_matrix(matrix, matrix_mark, 1, 0, xm, ym);

	if (mode == '1' || mode == '2') {
		int X, Y;
		cct_getxy(X, Y);
		is_end(0, Y + 1);
	}
	return 1;
}
/***************************************************************************
  函数名称：
  功    能：mode  '3''4'  的实现
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void mode34(int matrix[][10], int matrix_mark[][10], int& x, int& y, int xm, int ym, char mode, int goal)
{

	int max_num = 0;
	int score = 0;
	int ch;

	while (1) {
		if (mode12(matrix, matrix_mark, x, y, xm, ym, '3') == 0) {
			break;
		}

		cout << "请确认是否把相邻的相同值合并到" << char(y + 'A') << x << "中(Y/N/Q)：";

		ch = _getch();
		while (ch != 'Y' && ch != 'Q' && ch != 'N' &&
			ch != 'y' && ch != 'q' && ch != 'n')
		{
			ch = _getch();
		}

		cout << char(ch) << endl << endl;

		if (ch == 'Y' || ch == 'y') {
			cout << "相同值归并后的数组(不同色标识)：" << endl;
			merge(matrix, matrix_mark, x, y, xm, ym);
			print_matrix(matrix, matrix_mark, 1, 0, xm, ym);
			matrix_mark[y][x] = 0;
			score += (count(matrix, 0, xm, ym) + 1) * (matrix[y][x] - 1) * 3;
			cout << "本次得分：" << (count(matrix, 0, xm, ym) + 1) * (matrix[y][x] - 1) * 3
				<< " 总得分：" << score << " 合成目标：" << goal << endl;

			cout << endl << "按回车键进行数组下落除0操作..." << endl;
			is_enter();
			fall(matrix, matrix_mark, x, y, xm, ym);
			cout << "除0后的数组(不同色标识)：" << endl;
			print_matrix(matrix, matrix_mark, 1, 0, xm, ym);

			cout << "按回车键进行新值填充..." << endl;
			is_enter();
			max_num = find_max(matrix, xm, ym);
			fill_up(matrix, matrix_mark, x, y, xm, ym, max_num);
			cout << "新值填充后的数组(不同色标识)：" << endl;
			print_matrix(matrix, matrix_mark, 1, 0, xm, ym);

			if (mode == '4') {
				cout << "本次合成结束，按回车键继续新一次的合成..." << endl;
				max_num = find_max(matrix, xm, ym);
				if (goal == max_num) {
					cct_setcolor(COLOR_HYELLOW, COLOR_RED);
					cout << "已经合成到" << goal;
					cct_setcolor(COLOR_BLACK, COLOR_WHITE);
					cout << endl << "按回车键继续向更高目标进发..." << endl;
				}
				is_enter();
			}
			else if (mode == '3') {
				break;
			}

		}
		else if (((ch == 'N' || ch == 'n') && mode == '4')) {
			continue;
		}
		else {
			break;
		}
	}

	int X, Y;
	cct_getxy(X, Y);
	is_end(0, Y + 1);

}


/***************************************************************************
  函数名称：
  功    能：打印矩阵(内部数组)
  输入参数：high_light 1 有色 0 无色 num要标记的颜色
  返 回 值：
  说    明：
***************************************************************************/
void print_matrix(int matrix[][10], int matrix_mark[][10], int high_light, int is_mark, int xm, int ym)
{
	cout << setw(3) << "|";
	for (int i = 0; i <= xm; i++) {
		cout << setw(3) << i;
	}
	cout << endl;

	cout << "--+";
	for (int i = 0; i <= xm; i++) {
		cout << "---";

	}
	cout << endl;
	for (int j = 0; j <= ym; j++) {
		cout << char('A' + j) << " |";
		for (int i = 0; i <= xm; i++) {

			if (high_light && matrix_mark[j][i]) {
				cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
				if (is_mark) {
					cout << setw(3) << char((matrix[j][i] == 0) ? '0' : '*');
				}
				else {
					cout << setw(3) << matrix[j][i];
				}
				cct_setcolor(COLOR_BLACK, COLOR_WHITE);
			}
			else {
				if (is_mark) {
					cout << setw(3) << char((matrix[j][i] == 0) ? '0' : '*');
				}
				else {
					cout << setw(3) << matrix[j][i];
				}
			}

		}
		cout << endl;
	}
	cout << endl;
}

/***************************************************************************
  函数名称：
  功    能：输入 x,y
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void input_posi(int matrix_mark[][10], int matrix[][10], int& x, int& y, int& num, int xm, int ym)
{
	int x_cursor, y_cursor;//记录光标位置
	char posi_str[3] = { '\0' };//第一个字符存 y 第二个 x
	matrix_set0(matrix_mark, xm, ym);
	//int wrong_input=0;

	cct_getxy(x_cursor, y_cursor);

	while (1) {
		cin.getline(posi_str, 3);//与demo不同 demo应该是只读前两个


		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入错误，请重新输入.";
			cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//10可更大
			cct_gotoxy(x_cursor, y_cursor);
			//wrong_input = 1;
			continue;
		}
		if (((posi_str[0] >= 'a' && posi_str[0] <= 'a' + ym)
			|| (posi_str[0] >= 'A' && posi_str[0] <= 'A' + ym))
			&& (posi_str[1] >= '0' && posi_str[1] <= '0' + xm)) {

			if (posi_str[0] >= 'a' && posi_str[0] <= 'a' + ym)
				posi_str[0] += 'A' - 'a';
			break;
		}
		else {
			cout << "输入错误，请重新输入.";
			cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//10可更大
			cct_gotoxy(x_cursor, y_cursor);

		}

	}

	y = posi_str[0] - 'A';
	x = posi_str[1] - '0';
	matrix_mark[y][x] = 1;
	num = matrix[y][x];
	cout << "输入为" << posi_str[0] << "行" << x << "列";
	/*
	突然意识到这不是有意为之的细节 只是没清除而已
	if (wrong_input)
		cout << "重新输入.";*/
	cout << endl;
}

/***************************************************************************
  函数名称：
  功    能：将矩阵（二维数组）初始化 置随机数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void matrix_init(int matrix[][10], int xm, int ym)
{
	for (int j = 0; j <= ym; j++) {
		for (int i = 0; i <= xm; i++) {

			matrix[j][i] = get_random(3);
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：取随机数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int get_random(int max_num)
{
	int ret = 0;
	int temp = 0;


	switch (max_num)
	{
	case 1:
	case 2:
	case 3:
		ret = rand() % 3 + 1;
		break;
	case 4:
		temp = rand() % 10;//0~9
		if (temp == 10) {
			ret = 4;
		}
		else {
			ret = temp / 3 + 1;
		}
		break;
	case 5:
		temp = rand() % 100;//0~99
		if (temp >= 90 && temp <= 99) {
			ret = 5;
		}
		else if (temp >= 75 && temp <= 89) {
			ret = 4;
		}
		else {
			ret = temp / 25 + 1;
		}
		break;
	case 6:
		temp = rand() % 100;//0~99
		if (temp >= 95 && temp <= 99) {
			ret = 6;
		}
		else if (temp >= 80 && temp <= 94) {
			ret = 5;
		}
		else {
			ret = temp / 20 + 1;
		}
		break;
	default:
		temp = rand() % 100;//0~99
		if (temp >= 95 && temp <= 99) {
			ret = max_num;
		}
		else if (temp >= 90 && temp <= 94) {
			ret = max_num - 1;
		}
		else if (temp >= 80 && temp <= 89) {
			ret = max_num - 2;
		}
		else {
			ret = temp / (80 / (max_num - 3)) + 1;// 80%(x-3) 均分后取整
		}
		break;
	}

	return ret;
}

/***************************************************************************
  函数名称：
  功    能：在相邻4格中找相同值，并进行标记   mode == '1'对应方式1循环方式  mode == '2'对应递归方式
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int find_near(int matrix[][10], int matrix_mark[][10], int x, int y, int xm, int ym, char mode)
{
	int num = matrix[y][x];
	int x_cur, y_cur;
	int flag = 0;//标记每次循环寻找有无标记增加，无增加，则退出循环

	position posi[4] = { 0 };
	posi[0].x = x - 1;
	posi[0].y = y;
	posi[1].x = x + 1;
	posi[1].y = y;
	posi[2].x = x;
	posi[2].y = y - 1;
	posi[3].x = x;
	posi[3].y = y + 1;


	for (int i = 0; i < 4; i++) {

		x_cur = posi[i].x;
		y_cur = posi[i].y;
		if (x_cur <= xm && x_cur >= 0 &&
			y_cur <= ym && y_cur >= 0 &&
			matrix[y_cur][x_cur] == num &&
			matrix_mark[y_cur][x_cur] == 0) {

			matrix_mark[y_cur][x_cur] = 1;

			if (mode == '1')
				flag = 1;

			if (mode == '2')
				find_near(matrix, matrix_mark, x_cur, y_cur, xm, ym, '2');//递归
		}
	}
	return flag;
}

/***************************************************************************
  函数名称：
  功    能：等待一个回车
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
  功    能：相同值归并
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void merge(int matrix[][10], int matrix_mark[][10], int x, int y, int xm, int ym)
{
	matrix[y][x]++;

	for (int j = 0; j <= ym; j++) {
		for (int i = 0; i <= xm; i++) {

			if (matrix_mark[j][i]) {

				if (i != x || j != y) {
					matrix[j][i] = 0;//标记矩阵不置0 后续使用结束再置0
				}


			}
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：下落
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void fall(int matrix[][10], int matrix_mark[][10], int x, int y, int xm, int ym)
{
	int cnt0 = 0;//0的个数

	for (int i = xm; i >= 0; i--) {
		for (int j = ym; j > 0; ) {

			if (matrix[j][i] == 0) {
				cnt0 = 0;
				for (int k = j; k >= 0; k--) {

					if (matrix[k][i] == 0) {
						cnt0++;
					}
				}
				//cout << "i=" << i << " " << cnt0 << endl;//debug用 把cnt0 写成cnt，而且是定义
				if ((j + 1) == cnt0) {

					break;
				}


				for (int k = j; k > 0; k--) {

					matrix[k][i] = matrix[k - 1][i];
					matrix_mark[k][i] = matrix_mark[k - 1][i];
				}
				matrix[0][i] = 0;
				matrix_mark[0][i] = 1;
			}

			if (matrix[j][i] != 0) {
				j--;
			}
		}


	}
}

/***************************************************************************
  函数名称：
  功    能：填充0的位置
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void fill_up(int matrix[][10], int matrix_mark[][10], int x, int y, int xm, int ym, int max_num)
{
	for (int j = 0; j <= ym; j++) {
		for (int i = 0; i <= xm; i++) {

			if (!matrix[j][i]) {

				matrix[j][i] = get_random(max_num);

			}
		}
	}
}



