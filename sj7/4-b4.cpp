/*1951393 自动化 张儒戈*/
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/***************************************************************************
  函数名称：move_by_ijkl
  功    能：move
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：键盘输入的字符
  返 回 值：无
  说    明
***************************************************************************/
void move(const HANDLE hout, int X, int Y, char mode)
{
	int ch;
	int key;
	while (1) {
		if (mode == '1' || mode == '2') {
			ch = _getch();
		}
		else if (mode == '3' || mode == '4') {
			key = _getwch();
			if (key == 'Q' || key == 'q' || key == ' ') {
				ch = key;
			}
			else {
				ch = _getwch();
			}
			
		}
		else {
			ch = _getwch();
			//cout << ch << endl;
		}

		if (ch == 'q' || ch == 'Q')
			break;

		if (ch == ' ') {
			showch(hout, X, Y, ch);
			gotoxy(hout, X, Y);
			continue;
		}

		switch (mode)
		{
		case '1':
			switch (ch)
			{
			case 73:
			case 105:
				//Y--;//I 上
				if (Y != 1)
					gotoxy(hout, X, --Y);
				break;
			case 75:
			case 107:
				//Y++;//K 下
				if (Y != MAX_Y)
					gotoxy(hout, X, ++Y);
				break;
			case 74:
			case 106:
				if (X != 1)
					//X--;//J 左
					gotoxy(hout, --X, Y);
				break;
			case 76:
			case 108:
				if (X != MAX_X)
					//X++;//L 右
					gotoxy(hout, ++X, Y);
				break;
			default:
				break;
			}
			break;
		case '2':
			switch (ch)
			{
			case 73:
			case 105:
				//Y--;//I 上
				if (Y != 1)
					Y--;
				else
					Y = MAX_Y;

				gotoxy(hout, X, Y);
				break;
			case 75:
			case 107:
				//Y++;//K 下
				if (Y != MAX_Y)
					Y++;
				else
					Y = 1;

				gotoxy(hout, X, Y);
				break;
			case 74:
			case 106:
				if (X != 1)
					//X--;//J 左
					X--;
				else
					X = MAX_X;

				gotoxy(hout, X, Y);
				break;
			case 76:
			case 108:
				if (X != MAX_X)
					//X++;//L 右
					X++;
				else
					X = 1;

				gotoxy(hout, X, Y);
				break;
			default:
				break;
			}
			break;
		case '3':

			if (key == 224) {
				switch (ch)
				{
				case 72: //上
					if (Y != 1)
						gotoxy(hout, X, --Y);
					break;
				case 80:// 下
					if (Y != MAX_Y)
						gotoxy(hout, X, ++Y);
					break;
				case 75://左
					if (X != 1)
						gotoxy(hout, --X, Y);
					break;
				case 77:// 右
					if (X != MAX_X)
						gotoxy(hout, ++X, Y);
					break;
				default:
					break;
				}
			}

			break;

		case '4':
			if (key == 224) {
			
				switch (ch)
				{
				case 72: //上
					if (Y != 1)
						Y--;
					else
						Y = MAX_Y;

					gotoxy(hout, X, Y);
					break;
				case 80:// 下
					if (Y != MAX_Y)
						Y++;
					else
						Y = 1;

					gotoxy(hout, X, Y);
					break;
				case 75://左
					if (X != 1)
						X--;
					else
						X = MAX_X;

					gotoxy(hout, X, Y);
					break;
				case 77:// 右
					if (X != MAX_X)
						X++;
					else
						X = 1;

					gotoxy(hout, X, Y);
					break;

				default:
					break;
				}
			}
			break;
		case '5':
			if (ch == 224) {
				key = _getwch();
				if (key == 75)
					break;
			}

			switch (ch)
			{
			case 73:
			case 105:
				//Y--;//I 上
				if (Y != 1)
					gotoxy(hout, X, --Y);
				break;
			case 75:
			case 107:
				//Y++;//K 下
				if (Y != MAX_Y)
					gotoxy(hout, X, ++Y);
				break;
			case 74:
			case 106:
				if (X != 1)
					//X--;//J 左
					gotoxy(hout, --X, Y);
				break;
			case 76:
			case 108:
				if (X != MAX_X)
					//X++;//L 右
					gotoxy(hout, ++X, Y);
				break;
			default:
				break;
			}
			break;
		case '6':

			if (ch == 224) {
				key = _getwch();
				if (key == 75)
					break;
			}

			switch (ch)
			{
			case 73:
			case 105:
				//Y--;//I 上
				if (Y != 1)
					Y--;
				else
					Y = MAX_Y;

				gotoxy(hout, X, Y);
				break;
			case 75:
			case 107:
				//Y++;//K 下
				if (Y != MAX_Y)
					Y++;
				else
					Y = 1;

				gotoxy(hout, X, Y);
				break;
			case 74:
			case 106:
				if (X != 1)
					//X--;//J 左
					X--;
				else
					X = MAX_X;

				gotoxy(hout, X, Y);
				break;
			case 76:
			case 108:
				if (X != MAX_X)
					//X++;//L 右
					X++;
				else
					X = 1;

				gotoxy(hout, X, Y);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}


	}

}

/***************************************************************************
  函数名称：menu
  功    能：生成菜单，传回选项 
  输入参数：
  返 回 值：mode  0 - 6
  说    明：
***************************************************************************/
int menu() {

	cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)" << endl;
	cout << "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)" << endl;
	cout << "3.用箭头键控制上下左右，边界停止" << endl;
	cout << "4.用箭头键控制上下左右，边界回绕" << endl;
	cout << "5.用I、J、K、L键控制上下左右(大小写均可，边界停止,按左箭头键不准向下移动)" << endl;
	cout << "6.用I、J、K、L键控制上下左右(大小写均可，边界回绕,按左箭头键不准向下移动)" << endl;
	cout << "0.退出" << endl;
	cout << "[请选择0 - 6] ";
	char mode;
	mode = _getche();

	return mode;
}

/* -- 按需增加的若干函数可以放在此处 --*/


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄



	char mode = 1;


	while (mode != '0') {
		/* 此句的作用是调用系统的cls命令清屏 */
		cls(hout);
		while (1) {
			mode = menu();
			if (mode == '0' || mode == '1' || mode == '2' || mode == '3' || mode == '4' || mode == '5' || mode == '6') {
				break;
			}
			else {
				cls(hout);
			}
		}
		if (mode == '0')
			break;
		/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
		srand((unsigned int)(time(0)));

		/* 此句的作用是调用系统的cls命令清屏 */
		cls(hout);

		/* 显示初始的边框及其中的随机字符 */
		init_border(hout);

		int X = 35, Y = 9;//停在中央
		gotoxy(hout, X, Y);
		//暂停


		move(hout, X, Y, mode);



		gotoxy(hout, 0, 23);
		cout << "游戏结束，按回车键退出." << endl;

		//暂停(此处作业要求是只能按回车退出，目前的getchar示例，是允许按任意键+回车退出，且任意键会出现在屏幕上)
		while (_getch() != 13)
			;
		//修改为循环
	}
	return 0;
}
