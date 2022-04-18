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
  功    能：绘出mode5的框架(不适用于6789)
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void frame(int matrix[][10], int matrix_mark[][10], int x_size_cur, int  y_size_cur)
{
	/*将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(6 * x_size_cur + 5, 3 * y_size_cur + 7, 120, 9000);

	cct_showstr(0, 1, "╔", COLOR_HWHITE, COLOR_BLACK, 1);

	for (int x = 1; x <= x_size_cur; x++) {
		Sleep(25);
		cct_showstr(2 + 6 * (x - 1), 1, "═══", COLOR_HWHITE, COLOR_BLACK, 1);

	}
	cct_setcolor();
	cct_showstr(6 * x_size_cur + 3, 1, " ");
	cct_showstr(6 * x_size_cur + 2, 1, "╗", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_setcolor();


	for (int y = 1 + 1; y <= 3 * y_size_cur + 2; y++) {
		Sleep(50);
		cct_showstr(0, y, "║", COLOR_HWHITE, COLOR_BLACK, 1);
		cct_showstr(6 * x_size_cur + 2, y, "║", COLOR_HWHITE, COLOR_BLACK, 1);
	}

	cct_showstr(0, y_size_cur * 3 + 2, "╚", COLOR_HWHITE, COLOR_BLACK, 1);


	for (int x = 1; x <= x_size_cur; x++) {
		Sleep(25);
		cct_showstr(2 + 6 * (x - 1), y_size_cur * 3 + 2, "═══", COLOR_HWHITE, COLOR_BLACK, 1);

	}
	cct_showstr(6 * x_size_cur + 2, y_size_cur * 3 + 2, "╝", COLOR_HWHITE, COLOR_BLACK, 1);

	cct_setcolor();
	cct_gotoxy(0, 0);
	cout << "屏幕当前设置为：" << 3 * y_size_cur + 7 << "行" << 6 * x_size_cur + 5 << "列";
}

/***************************************************************************
  函数名称：
  功    能：绘出方块
  输入参数：
  返 回 值：state: common=0 表示正常 light=1 表示高亮  pick=2 表示选中
				  non=3表示空，被合并后的方块的状态  dark=4表示全黑，用于制造闪烁效果
  说    明：根据mode选择大小 根据state选择方块的颜色
***************************************************************************/
void block(int matrix[][10], int matrix_mark[][10], int x, int  y, char mode, int state)
{

	int num = matrix[y][x];
	int bg_color = 0, fg_color = 0;
	char num_str[3] = { '\0' };
	if (num < 10) {
		num_str[0] = num + '0';
	}
	else if (num >= 10) {
		num_str[0] = num / 10 + '0';
		num_str[1] = num % 10 + '0';
	}
	if (state == light) {
		bg_color = COLOR_HYELLOW;
		fg_color = COLOR_HBLUE;
	}
	else if (state == pick) {
		bg_color = COLOR_HYELLOW;
		fg_color = COLOR_HRED;
	}
	else if (state == non) {
		bg_color = COLOR_HWHITE;
		fg_color = COLOR_HWHITE;
	}
	else if (state == dark) {
		bg_color = COLOR_BLACK;
		fg_color = COLOR_BLACK;
	}
	else {
		bg_color = num2color(num);
		fg_color = COLOR_BLACK;
	}


	if (mode == '5') {
		//矩阵中坐标是xy 相应实际左上角坐标是  2+6*x 1+3*y
		cct_showstr(2 + 6 * x, 2 + 3 * y, "╔═╗", bg_color, fg_color, 1);
		cct_showstr(2 + 6 * x, 3 + 3 * y, "║  ", bg_color, fg_color, 1);
		//cct_showstr(5 + 6 * x, 3 + 3 * y, num_str, bg_color, fg_color, 1);
		if (num >= 10) {
			cct_showstr(4 + 6 * x, 3 + 3 * y, num_str, bg_color, fg_color, 1);

		}
		else {
			cct_showstr(5 + 6 * x, 3 + 3 * y, num_str, bg_color, fg_color, 1);
		}
		cct_showstr(6 + 6 * x, 3 + 3 * y, "║", bg_color, fg_color, 1);
		cct_showstr(2 + 6 * x, 4 + 3 * y, "╚═╝", bg_color, fg_color, 1);
		cct_setcolor();
	}
	else {
		cct_showstr(2 + 8 * x, 2 + 4 * y, "╔═╗", bg_color, fg_color, 1);
		cct_showstr(2 + 8 * x, 3 + 4 * y, "║  ", bg_color, fg_color, 1);

		//cct_showstr(5 + 8 * x, 3 + 4 * y, num_str, bg_color, fg_color, 1);
		if (num >= 10) {
			cct_showstr(4 + 8 * x, 3 + 4 * y, num_str, bg_color, fg_color, 1);

		}
		else {
			cct_showstr(5 + 8 * x, 3 + 4 * y, num_str, bg_color, fg_color, 1);
		}
		cct_showstr(6 + 8 * x, 3 + 4 * y, "║", bg_color, fg_color, 1);
		cct_showstr(2 + 8 * x, 4 + 4 * y, "╚═╝", bg_color, fg_color, 1);
		cct_setcolor();
	}

}

/***************************************************************************
  函数名称：
  功    能：绘出方块时根据数字选颜色
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int num2color(int num)
{

	switch (num % 11)
	{
	case 1:
		return 8;
		break;
	case 2:
		return 13;
		break;
	case 3:
		return 7;
		break;
	case 4:
		return COLOR_YELLOW;
		break;
	case 5:
		return COLOR_PINK;
		break;
	case 6:
		return COLOR_HBLUE;
		break;
	case 7:
		return COLOR_HCYAN;
		break;
	case 8:
		return COLOR_HGREEN;
		break;
	case 9:
		return COLOR_HYELLOW;
		break;
	case 10:
		return COLOR_RED;
		break;
	case 0:
		return COLOR_GREEN;
		break;
	default:
		break;
	}
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：绘出背景 适用于mode6789
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void background(int matrix[][10], int matrix_mark[][10], int x_size, int  y_size, char mode)
{

	const int row = 4 * y_size + 6;
	const int colum = 8 * x_size + 3;

	/*将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(colum, row, 120, 9000);


	//打印上边框
	cct_showstr(0, 1, "╔", COLOR_HWHITE, COLOR_BLACK, 1);
	for (int x = 1; x <= x_size; x++) {
		if (mode == '6') {
			Sleep(20);
		}

		cct_showstr(2 + 8 * (x - 1), 1, "═══", COLOR_HWHITE, COLOR_BLACK, 1);
		if (x != x_size) {
			cct_showstr(8 + 8 * (x - 1), 1, "╤", COLOR_HWHITE, COLOR_BLACK, 1);
		}
		else {
			cct_showstr(colum - 3, 1, "╗", COLOR_HWHITE, COLOR_BLACK, 1);
		}
	}//delay


	//打印剩下部分
	for (int i = 1; i <= y_size; i++) {
		for (int j = 1; j <= 3; j++) {
			if (mode == '6') {
				Sleep(30);
			}
			cct_showstr(0, 4 * (i - 1) + j + 1, "║", COLOR_HWHITE, COLOR_BLACK, 1);

			for (int k = 1; k <= x_size; k++) {
				cct_showstr(8 * (k - 1) + 2, 4 * (i - 1) + j + 1, "      ", COLOR_HWHITE, COLOR_BLACK, 1);
				if (k != x_size) {
					cct_showstr(8 * k, 4 * (i - 1) + j + 1, "│", COLOR_HWHITE, COLOR_BLACK, 1);
				}
			}
			cct_showstr(colum - 3, 4 * (i - 1) + j + 1, "║", COLOR_HWHITE, COLOR_BLACK, 1);
		}

		cct_showstr(0, 4 * (i - 1) + 4 + 1, "╟", COLOR_HWHITE, COLOR_BLACK, 1);

		if (i < y_size) {
			for (int k = 1; k <= x_size; k++) {
				cct_showstr(8 * (k - 1) + 2, 4 * (i - 1) + 4 + 1, "───", COLOR_HWHITE, COLOR_BLACK, 1);
				if (k != x_size) {
					cct_showstr(8 * k, 4 * (i - 1) + 4 + 1, "┼", COLOR_HWHITE, COLOR_BLACK, 1);
				}
			}
			cct_showstr(colum - 3, 4 * (i - 1) + 4 + 1, "╢", COLOR_HWHITE, COLOR_BLACK, 1);
		}
		else {
			cct_showstr(0, row - 5, "╚", COLOR_HWHITE, COLOR_BLACK, 1);
			for (int x = 1; x <= x_size; x++) {
				cct_showstr(2 + 8 * (x - 1), row - 5, "═══", COLOR_HWHITE, COLOR_BLACK, 1);
				if (x != x_size) {
					cct_showstr(8 + 8 * (x - 1), row - 5, "╧", COLOR_HWHITE, COLOR_BLACK, 1);
				}
				else {
					cct_showstr(colum - 3, row - 5, "╝", COLOR_HWHITE, COLOR_BLACK, 1);
				}
			}//delay
		}


	}
	cct_setcolor();
	cct_gotoxy(0, 0);
	cout << "屏幕当前设置为：" << row << "行" << colum << "列";

}

/***************************************************************************
  函数名称：move_and_pick
  功    能：通过方向键移动并选择色块
  输入参数：
  返 回 值：
  说    明 根据mode做调整
***************************************************************************/
void move_and_pick(int matrix[][10], int matrix_mark[][10], int& x, int& y, const int xm, const int ym, char mode)
{

	int loop = 1;
	int X, Y, maction, keycode1, keycode2, ret;
	int enter_flag = 0;//记录此时连续按下回车的次数，一次表示高亮相同值，两次表示选中并合并
	int mark = 0;
	x = 0, y = 0;
	block(matrix, matrix_mark, x, y, '8', 1);
	while (loop) {

		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);


		if (ret == CCT_KEYBOARD_EVENT) {

			switch (keycode1) {
			case 13:	//ENTER键
				if (mode == '7') {
					loop = 0;
				}
				else {
					enter_flag++;
					if (enter_flag == 2) {
						//连续两次按下回车，停止循环
						loop = 0;
						enter_flag = 0;
					}
					else if (enter_flag == 1) {
						//第一次按下回车，高亮周围相同值，若无，则给出提示
						if (mode == '7') {
							return;
						}
						matrix_set0(matrix_mark, xm, ym);
						find_near(matrix, matrix_mark, x, y, xm, ym, '2');//递归

						matrix_mark[y][x] = 0;
						mark = 0;//记录是否有相同值
						for (int i = 0; i <= xm; i++) {
							for (int j = 0; j <= ym; j++) {
								if (matrix_mark[j][i] == 1 && (j != y || i != x)) {
									block(matrix, matrix_mark, i, j, '8', light);//高亮相同值
									mark++;
								}
							}
						}

						//无相同值，给出提示，有相同值，颜色标成可pick
						if (mark == 0) {

							cct_setcolor(0, COLOR_HYELLOW);
							cct_gotoxy(0, 4 * ym + 6);
							cout << "周围无相同值";
							cct_setcolor();
							cout << "箭头键移动，回车键选择";

							enter_flag = 0;
						}
						else {
							cct_setcolor();
							cct_gotoxy(0, 4 * ym + 6);
							cout << "箭头键移动并取消当前选择，回车键合成";
							block(matrix, matrix_mark, x, y, '8', pick);//颜色标成可pick
						}

					}
				}
				break;
			case 224:
				cct_setcolor();
				cct_gotoxy(0, 4 * ym + 6);
				cout << "                                    ";
				cct_gotoxy(0, 4 * ym + 6);
				cout << "箭头键移动，回车键选择";

				enter_flag = 0;
				for (int i = 0; i <= xm; i++) {
					for (int j = 0; j <= ym; j++) {
						if (matrix_mark[j][i] == 1 && (j != y || i != x)) {
							block(matrix, matrix_mark, i, j, '8', common);

						}
					}

				}
				matrix_set0(matrix_mark, xm, ym);
				block(matrix, matrix_mark, x, y, '6', 0);
				switch (keycode2) {
				case KB_ARROW_UP:
					if (y != 0)
						y--;
					else
						y = ym;
					break;
				case KB_ARROW_DOWN:
					if (y != ym)
						y++;
					else
						y = 0;
					break;
				case KB_ARROW_LEFT:
					if (x != 0)
						x--;
					else
						x = xm;
					break;

				case KB_ARROW_RIGHT:
					if (x != xm)
						x++;
					else
						x = 0;
					break;
				}
				break;
			default:
				break;
			}//end of swicth(keycode1)
			if (enter_flag == 0 && keycode1 == 224) {
				block(matrix, matrix_mark, x, y, mode, 1);
			}


		}//end of else if(ret == CCT_KEYBOARD_EVENT）

	}
}

/***************************************************************************
  函数名称：block_down
  功    能：色块下移
  输入参数：y起始值y_src,终止值y_dst 对应矩阵位置，而非窗口
  返 回 值：
  说    明
***************************************************************************/
void block_down(int matrix[][10], int matrix_mark[][10], int x_src, int  y_src, int x_dst, int  y_dst)
{
	int x = 2 + 8 * x_src, y = 2 + 4 * y_src;//x是相对屏幕的坐标 x_src是相对矩阵的坐标
	int num = matrix[y_src][x_src];
	int bg_color = 0, fg_color = 0;

	char num_str[3] = { '\0' };
	if (num < 10) {
		num_str[0] = num + '0';
	}
	else if (num >= 10) {
		num_str[0] = num / 10 + '0';
		num_str[1] = num % 10 + '0';
	}

	bg_color = num2color(num);
	fg_color = COLOR_BLACK;

	while (1) {
		bg_color = num2color(num);
		fg_color = COLOR_BLACK;
		Sleep(5);
		cct_showstr(x, y, "╔═╗", COLOR_HWHITE, COLOR_HWHITE, 1);
		cct_showstr(x, y + 1, "║  ", COLOR_HWHITE, COLOR_HWHITE, 1);
		//cct_showstr(2 + 6 * x, 3 + 3 * y, "", color, COLOR_BLACK, 1);
		//cct_showstr(x + 3, y + 1, num_str, COLOR_HWHITE, COLOR_HWHITE, 1);
		cct_gotoxy(x + 2, y + 1);
		cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
		cout << setw(2) << num;
		cct_showstr(x + 4, y + 1, "║", COLOR_HWHITE, COLOR_HWHITE, 1);
		cct_showstr(x, y + 2, "╚═╝", COLOR_HWHITE, COLOR_HWHITE, 1);
		cct_setcolor();
		if ((y - 5) % 4 == 0) {
			cct_showstr(x, y, "───", COLOR_HWHITE, COLOR_BLACK, 1);
		}

		y++;

		bg_color = num2color(num);
		fg_color = COLOR_BLACK;
		//矩阵中坐标是xy 相应实际左上角坐标是  2+6*x 1+3*y
		cct_showstr(x, y, "╔═╗", bg_color, fg_color, 1);
		cct_showstr(x, y + 1, "║  ", bg_color, fg_color, 1);
		//cct_showstr(2 + 6 * x, 3 + 3 * y, "", color, COLOR_BLACK, 1);
		//cct_showstr(x + 3, y + 1, num_str, bg_color, fg_color, 1);
		cct_gotoxy(x + 2, y + 1);
		cct_setcolor(bg_color, fg_color);
		cout << setw(2) << num;
		cct_showstr(x + 4, y + 1, "║", bg_color, fg_color, 1);
		cct_showstr(x, y + 2, "╚═╝", bg_color, fg_color, 1);
		cct_setcolor();

		if (y == 2 + 4 * y_dst) {
			break;
		}
	}

}


/***************************************************************************
  函数名称：
  功    能：mode  '5'  的实现
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void mode5(int matrix[][10], int matrix_mark[][10], int& x, int& y, int x_size_cur, int  y_size_cur)
{

	frame(matrix, matrix_mark, x_size_cur, y_size_cur);


	for (int y = 0; y < y_size_cur; y++) {
		for (int x = 0; x < x_size_cur; x++) {
			block(matrix, matrix_mark, x, y, '5');
			Sleep(10);
		}
	}
	is_end(0, 3 * y_size_cur + 3);
}

/***************************************************************************
  函数名称：
  功    能：mode  '6'  的实现
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void mode6(int matrix[][10], int matrix_mark[][10], int& x, int& y, int x_size_cur, int  y_size_cur)
{

	background(matrix, matrix_mark, x_size_cur, y_size_cur, '6');
	for (int y = 0; y < y_size_cur; y++) {
		for (int x = 0; x < x_size_cur; x++) {
			block(matrix, matrix_mark, x, y, '6');
			Sleep(10);
		}
	}
	is_end(0, 4 * y_size_cur + 2);
}

/***************************************************************************
  函数名称：
  功    能：mode  '7'  的实现
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void mode7(int matrix[][10], int matrix_mark[][10], int& x, int& y, int x_size_cur, int  y_size_cur)
{

	background(matrix, matrix_mark, x_size_cur, y_size_cur, '7');
	for (int y = 0; y < y_size_cur; y++) {
		for (int x = 0; x < x_size_cur; x++) {
			block(matrix, matrix_mark, x, y, '6');
		}
	}

	int x_cur = 0, y_cur = 0;


	cct_setcolor();
	cct_gotoxy(0, 4 * y_size_cur + 2);
	cout << "箭头键移动，回车键选择并结束";
	move_and_pick(matrix, matrix_mark, x_cur, y_cur, x_size_cur - 1, y_size_cur - 1, '7');
	is_end(0, 4 * y_size_cur + 2);
}

/***************************************************************************
  函数名称：
  功    能：mode  8 9  的实现
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void mode89(int matrix[][10], int matrix_mark[][10], int& x, int& y, int x_size_cur, int  y_size_cur, char mode, int goal)
{
	int max_num = 0;
	int score = 0;
	int loop = 1;
	int flag = 0;//记录是否是第一次达到新的最大值
	int mark0 = 0;


	cct_setcursor(CURSOR_INVISIBLE);
	background(matrix, matrix_mark, x_size_cur, y_size_cur, mode);//画背景

	cct_setcolor();
	cct_gotoxy(0, 4 * y_size_cur + 2);
	cout << "箭头键移动，回车键选择";

	//画方块
	for (int y = 0; y < y_size_cur; y++) {
		for (int x = 0; x < x_size_cur; x++) {
			block(matrix, matrix_mark, x, y, '8');
		}
	}


	x = 0, y = 0;

	while (loop) {
		if (mode == '8')
			loop = 0;

		//无可合并项则结束
		if (is_over(matrix, matrix_mark, x_size_cur - 1, y_size_cur - 1)) {
			cct_gotoxy(0, 4 * y_size_cur + 3);
			//cct_showstr(0, 4 * y_size_cur + 2, " ", 0, 7, 8 * x_size_cur + 3);
			cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
			cout << "无可合并的项，游戏结束";
			cct_setcolor();
			cout << "按Q退出";
			int X, Y;
			cct_getxy(X, Y);
			while (1)
			{
				cct_showstr(X, Y, " ", 0, 7, 10);
				cct_gotoxy(X, Y);
				int ch;
				ch = _getche();
				if (ch == 'q' || ch == 'Q') {
					cct_showstr(0, Y, " ", 0, 7, 50);
					cct_showstr(0, Y + 1, " ", 0, 7, 50);
					break;
				}
				cout << endl << "输入错误，请重新输入";
			}
			break;
		}

		move_and_pick(matrix, matrix_mark, x, y, x_size_cur - 1, y_size_cur - 1, '8');
		merge(matrix, matrix_mark, x, y, x_size_cur - 1, y_size_cur - 1);
		//打印得分
		matrix_mark[y][x] = 0;
		cct_setcolor();
		cct_gotoxy(0, 0);
		cct_showstr(0, 0, " ", 0, 7, 50);
		cct_gotoxy(0, 0);
		score += (count(matrix, 0, x_size_cur - 1, y_size_cur - 1) + 1) * (matrix[y][x] - 1) * 3;
		cout << "本次得分：" << (count(matrix, 0, x_size_cur - 1, y_size_cur - 1) + 1) * (matrix[y][x] - 1) * 3
			<< " 总得分：" << score << " 合成目标：" << goal << endl;




		//闪烁效果
		block(matrix, matrix_mark, x, y, '8', dark);
		Sleep(25);
		block(matrix, matrix_mark, x, y, '8');
		Sleep(25);
		block(matrix, matrix_mark, x, y, '8', dark);
		Sleep(25);
		block(matrix, matrix_mark, x, y, '8');
		Sleep(25);
		block(matrix, matrix_mark, x, y, '8', dark);
		Sleep(25);
		block(matrix, matrix_mark, x, y, '8');


		matrix_mark[y][x] = 0;
		for (int i = 0; i < x_size_cur; i++) {
			for (int j = y_size_cur - 1; j >= 0; j--) {
				if (matrix[j][i] == 0) {
					block(matrix, matrix_mark, i, j, '8', 3);

				}

			}

		}

		block(matrix, matrix_mark, x, y, '8');


		if (mode == '8') {
			cct_showstr(0, 4 * y_size_cur + 2, " ", 0, 7, 8 * x_size_cur + 3);
			cct_gotoxy(0, 4 * y_size_cur + 2);
			cout << "完成合成，回车键下落0";

			is_enter();
		}

		for (int i = 0; i < x_size_cur; i++) {
			for (int j = y_size_cur - 1; j >= 0; j--) {
				if (matrix[j][i] != 0) {
					mark0 = 0;
					for (int k = y_size_cur - 1; k > j; k--) {

						if (matrix[k][i] == 0) {
							mark0++;
						}
					}
					if (mark0 > 0 && matrix[j][i] != 0) {
						block_down(matrix, matrix_mark, i, j, i, j + mark0);
					}

				}

			}

		}

		fall(matrix, matrix_mark, x, y, x_size_cur - 1, y_size_cur - 1);


		if (mode == '8') {
			cct_showstr(0, 4 * y_size_cur + 2, " ", 0, 7, 8 * x_size_cur + 3);
			cct_gotoxy(0, 4 * y_size_cur + 2);
			cout << "下落0完成，回车键填充新值";
			is_enter();
		}

		//更新max_num时,将falg置零
		if (max_num < find_max(matrix, x_size_cur - 1, y_size_cur - 1)) {
			flag = 0;
		}
		max_num = find_max(matrix, x_size_cur - 1, y_size_cur - 1);
		fill_up(matrix, matrix_mark, x, y, x_size_cur - 1, y_size_cur - 1, max_num);

		for (int i = 0; i < x_size_cur; i++) {
			for (int j = y_size_cur - 1; j >= 0; j--) {
				if (matrix_mark[j][i] == 1) {
					block(matrix, matrix_mark, i, j, '8', 0);

					Sleep(50);

				}

			}

		}

		if (mode == '8') {
			cct_showstr(0, 4 * y_size_cur + 2, " ", 0, 7, 8 * x_size_cur + 3);
			cct_gotoxy(0, 4 * y_size_cur + 2);
			cout << "本次合成结束，按C继续新一次的合成";
			int ch;
			ch = _getch();
			while (ch != 'c' && ch != 'C')
			{
				ch = _getch();
			}

		}

		if (mode == '9' && max_num >= goal && flag == 0) {
			flag++;
			cct_showstr(0, 4 * y_size_cur + 2, " ", 0, 7, 8 * x_size_cur + 3);
			cct_gotoxy(0, 4 * y_size_cur + 2);
			cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
			cout << "已经合成到" << max_num;
			cct_setcolor();
			cout << "按回车键继续向更高目标进发";
			is_enter();
			cct_showstr(0, 4 * y_size_cur + 2, " ", 0, 7, 8 * x_size_cur + 3);
			cct_gotoxy(0, 4 * y_size_cur + 2);
			cout << "箭头键移动，回车键选择";
		}

	}
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	is_end(0, 4 * y_size_cur + 2);

}
