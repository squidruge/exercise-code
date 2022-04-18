/*1951393 自动化 张儒戈*/


#include <iostream>
#include <conio.h>
#include<time.h> 
#include<iomanip> 
#include <Windows.h>
#include "90-b2.h"
#include "cmd_console_tools.h"

using namespace std;



/***************************************************************************
  函数名称：
  功    能：矩阵置零
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void matrix_set0(int matrix[][10], int xm, int ym)
{
	for (int j = 0; j <= ym; j++) {
		for (int i = 0; i <= xm; i++) {

			matrix[j][i] = 0;

		}
	}
}

/***************************************************************************
  函数名称：
  功    能：寻找矩阵中的最大值，random由最大值而定
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int find_max(int matrix[][10], int xm, int ym)
{
	int max_num = 0;

	for (int j = 0; j <= ym; j++) {
		for (int i = 0; i <= xm; i++) {

			if (matrix[j][i] > max_num)
				max_num = matrix[j][i];

		}
	}
	return max_num;
}

/***************************************************************************
  函数名称：
  功    能：合并的个数 用于计算分数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int count(int matrix[][10], int num, int xm, int ym)
{
	int cnt = 0;

	for (int j = 0; j <= ym; j++) {
		for (int i = 0; i <= xm; i++) {

			if (matrix[j][i] == num)
				cnt++;

		}
	}
	return cnt;

}


/***************************************************************************
  函数名称：
  功    能：初始输入 行列 合成目标
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void input_init(int& x_size_cur, int& y_size_cur, int& goal, char mode)
{
	int x_cursor, y_cursor;//记录光标位置



	cct_cls();
	cout << "请输入行数(5-8)：";
	cct_getxy(x_cursor, y_cursor);

	while (1) {
		cin >> y_size_cur;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入错误，请重新输入.";
			cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//10可更大
			cct_gotoxy(x_cursor, y_cursor);

			continue;
		}

		if (y_size_cur >= 5 && y_size_cur <= 8) {
			cct_getxy(x_cursor, y_cursor);
			cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//20可更大,用于清除
			cct_gotoxy(x_cursor, y_cursor);
			break;
		}
		else {
			cout << "输入错误，请重新输入.";
			cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//20可更大,用于清除
			cct_gotoxy(x_cursor, y_cursor);

		}

	}

	cout << "请输入列数(5-10)：";
	cct_getxy(x_cursor, y_cursor);
	while (1) {
		cin >> x_size_cur;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入错误，请重新输入.";
			cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//10可更大
			cct_gotoxy(x_cursor, y_cursor);

			continue;
		}

		if (x_size_cur >= 5 && x_size_cur <= 10) {
			cct_getxy(x_cursor, y_cursor);
			cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//20可更大,用于清除
			cct_gotoxy(x_cursor, y_cursor);
			break;
		}
		else {
			cout << "输入错误，请重新输入.";
			cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//20可更大,用于清除
			cct_gotoxy(x_cursor, y_cursor);

		}

	}

	if (mode == '3' || mode == '4' || mode == '8' || mode == '9') {
		cout << "请输入合成目标(5-20)：";
		cct_getxy(x_cursor, y_cursor);
		while (1) {
			cin >> goal;//记得加错判

			if (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "输入错误，请重新输入.";
				cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//10可更大
				cct_gotoxy(x_cursor, y_cursor);

				continue;
			}

			if (goal >= 5 && goal <= 20) {
				cct_getxy(x_cursor, y_cursor);
				cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//20可更大,用于清除
				cct_gotoxy(x_cursor, y_cursor);
				break;
			}
			else {
				cout << "输入错误，请重新输入.";
				cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//20可更大,用于清除
				cct_gotoxy(x_cursor, y_cursor);

			}

		}
	}

	cout << endl;
}

/***************************************************************************
  函数名称：
  功    能：判断是否结束，当无可合并对象，则结束
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
bool is_over(int matrix[][10], int matrix_mark[][10], int xm, int  ym)
{
	int mark = 0;
	for (int y = 0; y <= ym; y++) {
		for (int x = 0; x <= xm; x++) {
			mark = 0;
			matrix_set0(matrix_mark, xm, ym);
			find_near(matrix, matrix_mark, x, y, xm, ym, '2');
			for (int j = 0; j <= ym; j++) {
				for (int i = 0; i <= xm; i++) {
					if (matrix_mark[j][i] == 1 && (j != y || i != x)) {
						mark++;
					}
				}
			}

			if (mark)
				return 0;
		}
	}
	return 1;
}

/***************************************************************************
  函数名称：
  功    能：等待输入end作为每一小题的结束
  输入参数：X，Y表示此时光标的位置
  返 回 值：
  说    明：
***************************************************************************/
void is_end(int X, int Y)
{
	int X1, Y1;//暂存光标位置
	char str[100] = { '\0' };
	cct_gotoxy(X, Y);
	cct_showstr(X, Y, " ", 0, 7, 40);
	cct_gotoxy(X, Y);
	cout << "本小题结束，请输入End继续...";
	cct_getxy(X1, Y1);
	while (1) {
		//cin >> str;
		//cin.clear();
		//cin.getline(str, 100, '\n');
		for (int i = 0; i < 100; i++) {
			str[i] = _getche();
			if (str[i] == 13) {
				break;
			}
		}

		if ((str[0] == 'E' || str[0] == 'e') &&
			(str[1] == 'N' || str[1] == 'n') &&
			(str[2] == 'D' || str[2] == 'd')) {
			break;
		}
		cct_showstr(X1, Y1, " ", 0, 7, 40);
		cct_gotoxy(X, Y + 1);
		cout << "输入错误，请重新输入";
		cct_gotoxy(X1, Y1);
	}

}