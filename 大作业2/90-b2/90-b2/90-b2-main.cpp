/*1951393 自动化 张儒戈*/


#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "cmd_console_tools.h"
#include <conio.h>
#include "90-b2.h"
#define x_size 10
#define y_size 8
using namespace std;
 


/***************************************************************************
  函数名称：
  功    能：菜单 并调用参数输入的函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char menu()
{
	char mode;

	cout << "---------------------------------" << endl;
	cout << "1.命令行找出可合成项并标识（非递归）" << endl;
	cout << "2.命令行找出可合成项并标识（递归）" << endl;
	cout << "3.命令行完成一次合成（分步骤显示）" << endl;
	cout << "4.命令行完整版（分步骤显示）" << endl;
	cout << "5.伪图形界面显示初始数组（无分隔线）" << endl;
	cout << "6.伪图形界面显示初始数组（有分隔线）" << endl;
	cout << "7.伪图形界面下用箭头键选择当前色块" << endl;
	cout << "8.伪图形界面完成一次合成（分步骤）" << endl;
	cout << "9.伪图形界面完整版" << endl;
	cout << "0.退出" << endl;
	cout << "---------------------------------" << endl;
	cout << "[请选择0-9] ";

	while (1)
	{
		mode = _getch();
		if (mode >= '0' && mode <= '9')
		{
			cout << mode;
			break;
		}
	}

	return mode;
}

/***************************************************************************
  函数名称：
  功    能：调用选项对应的函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void ChooseMode(int matrix[][10], int matrix_mark[][10], int& x, int& y, int x_size_cur, int  y_size_cur, char mode, int goal)
{
	switch (mode)
	{
	case '1':
	case '2':
		mode12(matrix, matrix_mark, x, y, x_size_cur - 1, y_size_cur - 1, mode);
		break;
	case '3':
	case '4':
		mode34(matrix, matrix_mark, x, y, x_size_cur - 1, y_size_cur - 1, mode, goal);
		break;
	case '5':
		mode5(matrix, matrix_mark, x, y, x_size_cur, y_size_cur);
		break;
	case '6':
		mode6(matrix, matrix_mark, x, y, x_size_cur, y_size_cur);
		break;
	case '7':
		mode7(matrix, matrix_mark, x, y, x_size_cur, y_size_cur);
		break;
	case '8':
	case '9':
		mode89(matrix, matrix_mark, x, y, x_size_cur, y_size_cur, mode, goal);
		break;
	default:
		break;
	}

}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

int main()
{

	int x = 0, y = 0;
	int x_size_cur, y_size_cur;
	int goal = 5;//合成目标

	char mode;


	while (1) {
		cct_setconsoleborder(80, 25, 80, 250);
		cct_cls();

		mode = menu();
		if (mode == '0')
			break;


		int matrix[y_size][x_size] = { 0 };
		int matrix_mark[y_size][x_size] = { 0 };

		input_init(x_size_cur, y_size_cur, goal, mode);

		srand(unsigned int(time(NULL)));
		matrix_init(matrix, x_size_cur - 1, y_size_cur - 1);

		ChooseMode(matrix, matrix_mark, x, y, x_size_cur, y_size_cur, mode, goal);//根据选项调用菜单各项对应的执行函数
		matrix_set0(matrix, x_size_cur - 1, y_size_cur - 1);
		matrix_set0(matrix_mark, x_size_cur - 1, y_size_cur - 1);

		
		cct_setcolor(); //恢复缺省颜色;
		cct_setcursor(CURSOR_VISIBLE_NORMAL);  //光标显示正常
		
		//cct_setcursor(CURSOR_INVISIBLE);
	}

	return 0;
}