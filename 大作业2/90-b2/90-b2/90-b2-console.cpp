/*1951393 �Զ��� �����*/

#include <iostream>
#include <conio.h>
#include "90-b2.h"
#include<time.h> 
#include<iomanip> 
#include <Windows.h>
#include "cmd_console_tools.h"
using namespace std;


/***************************************************************************
  �������ƣ�
  ��    �ܣ����mode5�Ŀ��(��������6789)
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void frame(int matrix[][10], int matrix_mark[][10], int x_size_cur, int  y_size_cur)
{
	/*��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(6 * x_size_cur + 5, 3 * y_size_cur + 7, 120, 9000);

	cct_showstr(0, 1, "�X", COLOR_HWHITE, COLOR_BLACK, 1);

	for (int x = 1; x <= x_size_cur; x++) {
		Sleep(25);
		cct_showstr(2 + 6 * (x - 1), 1, "�T�T�T", COLOR_HWHITE, COLOR_BLACK, 1);

	}
	cct_setcolor();
	cct_showstr(6 * x_size_cur + 3, 1, " ");
	cct_showstr(6 * x_size_cur + 2, 1, "�[", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_setcolor();


	for (int y = 1 + 1; y <= 3 * y_size_cur + 2; y++) {
		Sleep(50);
		cct_showstr(0, y, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
		cct_showstr(6 * x_size_cur + 2, y, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
	}

	cct_showstr(0, y_size_cur * 3 + 2, "�^", COLOR_HWHITE, COLOR_BLACK, 1);


	for (int x = 1; x <= x_size_cur; x++) {
		Sleep(25);
		cct_showstr(2 + 6 * (x - 1), y_size_cur * 3 + 2, "�T�T�T", COLOR_HWHITE, COLOR_BLACK, 1);

	}
	cct_showstr(6 * x_size_cur + 2, y_size_cur * 3 + 2, "�a", COLOR_HWHITE, COLOR_BLACK, 1);

	cct_setcolor();
	cct_gotoxy(0, 0);
	cout << "��Ļ��ǰ����Ϊ��" << 3 * y_size_cur + 7 << "��" << 6 * x_size_cur + 5 << "��";
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��������
  ���������
  �� �� ֵ��state: common=0 ��ʾ���� light=1 ��ʾ����  pick=2 ��ʾѡ��
				  non=3��ʾ�գ����ϲ���ķ����״̬  dark=4��ʾȫ�ڣ�����������˸Ч��
  ˵    ��������modeѡ���С ����stateѡ�񷽿����ɫ
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
		//������������xy ��Ӧʵ�����Ͻ�������  2+6*x 1+3*y
		cct_showstr(2 + 6 * x, 2 + 3 * y, "�X�T�[", bg_color, fg_color, 1);
		cct_showstr(2 + 6 * x, 3 + 3 * y, "�U  ", bg_color, fg_color, 1);
		//cct_showstr(5 + 6 * x, 3 + 3 * y, num_str, bg_color, fg_color, 1);
		if (num >= 10) {
			cct_showstr(4 + 6 * x, 3 + 3 * y, num_str, bg_color, fg_color, 1);

		}
		else {
			cct_showstr(5 + 6 * x, 3 + 3 * y, num_str, bg_color, fg_color, 1);
		}
		cct_showstr(6 + 6 * x, 3 + 3 * y, "�U", bg_color, fg_color, 1);
		cct_showstr(2 + 6 * x, 4 + 3 * y, "�^�T�a", bg_color, fg_color, 1);
		cct_setcolor();
	}
	else {
		cct_showstr(2 + 8 * x, 2 + 4 * y, "�X�T�[", bg_color, fg_color, 1);
		cct_showstr(2 + 8 * x, 3 + 4 * y, "�U  ", bg_color, fg_color, 1);

		//cct_showstr(5 + 8 * x, 3 + 4 * y, num_str, bg_color, fg_color, 1);
		if (num >= 10) {
			cct_showstr(4 + 8 * x, 3 + 4 * y, num_str, bg_color, fg_color, 1);

		}
		else {
			cct_showstr(5 + 8 * x, 3 + 4 * y, num_str, bg_color, fg_color, 1);
		}
		cct_showstr(6 + 8 * x, 3 + 4 * y, "�U", bg_color, fg_color, 1);
		cct_showstr(2 + 8 * x, 4 + 4 * y, "�^�T�a", bg_color, fg_color, 1);
		cct_setcolor();
	}

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��������ʱ��������ѡ��ɫ
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�
  ��    �ܣ�������� ������mode6789
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void background(int matrix[][10], int matrix_mark[][10], int x_size, int  y_size, char mode)
{

	const int row = 4 * y_size + 6;
	const int colum = 8 * x_size + 3;

	/*��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(colum, row, 120, 9000);


	//��ӡ�ϱ߿�
	cct_showstr(0, 1, "�X", COLOR_HWHITE, COLOR_BLACK, 1);
	for (int x = 1; x <= x_size; x++) {
		if (mode == '6') {
			Sleep(20);
		}

		cct_showstr(2 + 8 * (x - 1), 1, "�T�T�T", COLOR_HWHITE, COLOR_BLACK, 1);
		if (x != x_size) {
			cct_showstr(8 + 8 * (x - 1), 1, "�h", COLOR_HWHITE, COLOR_BLACK, 1);
		}
		else {
			cct_showstr(colum - 3, 1, "�[", COLOR_HWHITE, COLOR_BLACK, 1);
		}
	}//delay


	//��ӡʣ�²���
	for (int i = 1; i <= y_size; i++) {
		for (int j = 1; j <= 3; j++) {
			if (mode == '6') {
				Sleep(30);
			}
			cct_showstr(0, 4 * (i - 1) + j + 1, "�U", COLOR_HWHITE, COLOR_BLACK, 1);

			for (int k = 1; k <= x_size; k++) {
				cct_showstr(8 * (k - 1) + 2, 4 * (i - 1) + j + 1, "      ", COLOR_HWHITE, COLOR_BLACK, 1);
				if (k != x_size) {
					cct_showstr(8 * k, 4 * (i - 1) + j + 1, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				}
			}
			cct_showstr(colum - 3, 4 * (i - 1) + j + 1, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
		}

		cct_showstr(0, 4 * (i - 1) + 4 + 1, "�c", COLOR_HWHITE, COLOR_BLACK, 1);

		if (i < y_size) {
			for (int k = 1; k <= x_size; k++) {
				cct_showstr(8 * (k - 1) + 2, 4 * (i - 1) + 4 + 1, "������", COLOR_HWHITE, COLOR_BLACK, 1);
				if (k != x_size) {
					cct_showstr(8 * k, 4 * (i - 1) + 4 + 1, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				}
			}
			cct_showstr(colum - 3, 4 * (i - 1) + 4 + 1, "�f", COLOR_HWHITE, COLOR_BLACK, 1);
		}
		else {
			cct_showstr(0, row - 5, "�^", COLOR_HWHITE, COLOR_BLACK, 1);
			for (int x = 1; x <= x_size; x++) {
				cct_showstr(2 + 8 * (x - 1), row - 5, "�T�T�T", COLOR_HWHITE, COLOR_BLACK, 1);
				if (x != x_size) {
					cct_showstr(8 + 8 * (x - 1), row - 5, "�k", COLOR_HWHITE, COLOR_BLACK, 1);
				}
				else {
					cct_showstr(colum - 3, row - 5, "�a", COLOR_HWHITE, COLOR_BLACK, 1);
				}
			}//delay
		}


	}
	cct_setcolor();
	cct_gotoxy(0, 0);
	cout << "��Ļ��ǰ����Ϊ��" << row << "��" << colum << "��";

}

/***************************************************************************
  �������ƣ�move_and_pick
  ��    �ܣ�ͨ��������ƶ���ѡ��ɫ��
  ���������
  �� �� ֵ��
  ˵    �� ����mode������
***************************************************************************/
void move_and_pick(int matrix[][10], int matrix_mark[][10], int& x, int& y, const int xm, const int ym, char mode)
{

	int loop = 1;
	int X, Y, maction, keycode1, keycode2, ret;
	int enter_flag = 0;//��¼��ʱ�������»س��Ĵ�����һ�α�ʾ������ֵͬ�����α�ʾѡ�в��ϲ�
	int mark = 0;
	x = 0, y = 0;
	block(matrix, matrix_mark, x, y, '8', 1);
	while (loop) {

		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);


		if (ret == CCT_KEYBOARD_EVENT) {

			switch (keycode1) {
			case 13:	//ENTER��
				if (mode == '7') {
					loop = 0;
				}
				else {
					enter_flag++;
					if (enter_flag == 2) {
						//�������ΰ��»س���ֹͣѭ��
						loop = 0;
						enter_flag = 0;
					}
					else if (enter_flag == 1) {
						//��һ�ΰ��»س���������Χ��ֵͬ�����ޣ��������ʾ
						if (mode == '7') {
							return;
						}
						matrix_set0(matrix_mark, xm, ym);
						find_near(matrix, matrix_mark, x, y, xm, ym, '2');//�ݹ�

						matrix_mark[y][x] = 0;
						mark = 0;//��¼�Ƿ�����ֵͬ
						for (int i = 0; i <= xm; i++) {
							for (int j = 0; j <= ym; j++) {
								if (matrix_mark[j][i] == 1 && (j != y || i != x)) {
									block(matrix, matrix_mark, i, j, '8', light);//������ֵͬ
									mark++;
								}
							}
						}

						//����ֵͬ��������ʾ������ֵͬ����ɫ��ɿ�pick
						if (mark == 0) {

							cct_setcolor(0, COLOR_HYELLOW);
							cct_gotoxy(0, 4 * ym + 6);
							cout << "��Χ����ֵͬ";
							cct_setcolor();
							cout << "��ͷ���ƶ����س���ѡ��";

							enter_flag = 0;
						}
						else {
							cct_setcolor();
							cct_gotoxy(0, 4 * ym + 6);
							cout << "��ͷ���ƶ���ȡ����ǰѡ�񣬻س����ϳ�";
							block(matrix, matrix_mark, x, y, '8', pick);//��ɫ��ɿ�pick
						}

					}
				}
				break;
			case 224:
				cct_setcolor();
				cct_gotoxy(0, 4 * ym + 6);
				cout << "                                    ";
				cct_gotoxy(0, 4 * ym + 6);
				cout << "��ͷ���ƶ����س���ѡ��";

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


		}//end of else if(ret == CCT_KEYBOARD_EVENT��

	}
}

/***************************************************************************
  �������ƣ�block_down
  ��    �ܣ�ɫ������
  ���������y��ʼֵy_src,��ֵֹy_dst ��Ӧ����λ�ã����Ǵ���
  �� �� ֵ��
  ˵    ��
***************************************************************************/
void block_down(int matrix[][10], int matrix_mark[][10], int x_src, int  y_src, int x_dst, int  y_dst)
{
	int x = 2 + 8 * x_src, y = 2 + 4 * y_src;//x�������Ļ������ x_src����Ծ��������
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
		cct_showstr(x, y, "�X�T�[", COLOR_HWHITE, COLOR_HWHITE, 1);
		cct_showstr(x, y + 1, "�U  ", COLOR_HWHITE, COLOR_HWHITE, 1);
		//cct_showstr(2 + 6 * x, 3 + 3 * y, "", color, COLOR_BLACK, 1);
		//cct_showstr(x + 3, y + 1, num_str, COLOR_HWHITE, COLOR_HWHITE, 1);
		cct_gotoxy(x + 2, y + 1);
		cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
		cout << setw(2) << num;
		cct_showstr(x + 4, y + 1, "�U", COLOR_HWHITE, COLOR_HWHITE, 1);
		cct_showstr(x, y + 2, "�^�T�a", COLOR_HWHITE, COLOR_HWHITE, 1);
		cct_setcolor();
		if ((y - 5) % 4 == 0) {
			cct_showstr(x, y, "������", COLOR_HWHITE, COLOR_BLACK, 1);
		}

		y++;

		bg_color = num2color(num);
		fg_color = COLOR_BLACK;
		//������������xy ��Ӧʵ�����Ͻ�������  2+6*x 1+3*y
		cct_showstr(x, y, "�X�T�[", bg_color, fg_color, 1);
		cct_showstr(x, y + 1, "�U  ", bg_color, fg_color, 1);
		//cct_showstr(2 + 6 * x, 3 + 3 * y, "", color, COLOR_BLACK, 1);
		//cct_showstr(x + 3, y + 1, num_str, bg_color, fg_color, 1);
		cct_gotoxy(x + 2, y + 1);
		cct_setcolor(bg_color, fg_color);
		cout << setw(2) << num;
		cct_showstr(x + 4, y + 1, "�U", bg_color, fg_color, 1);
		cct_showstr(x, y + 2, "�^�T�a", bg_color, fg_color, 1);
		cct_setcolor();

		if (y == 2 + 4 * y_dst) {
			break;
		}
	}

}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�mode  '5'  ��ʵ��
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�
  ��    �ܣ�mode  '6'  ��ʵ��
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�
  ��    �ܣ�mode  '7'  ��ʵ��
  ���������
  �� �� ֵ��
  ˵    ����
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
	cout << "��ͷ���ƶ����س���ѡ�񲢽���";
	move_and_pick(matrix, matrix_mark, x_cur, y_cur, x_size_cur - 1, y_size_cur - 1, '7');
	is_end(0, 4 * y_size_cur + 2);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�mode  8 9  ��ʵ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void mode89(int matrix[][10], int matrix_mark[][10], int& x, int& y, int x_size_cur, int  y_size_cur, char mode, int goal)
{
	int max_num = 0;
	int score = 0;
	int loop = 1;
	int flag = 0;//��¼�Ƿ��ǵ�һ�δﵽ�µ����ֵ
	int mark0 = 0;


	cct_setcursor(CURSOR_INVISIBLE);
	background(matrix, matrix_mark, x_size_cur, y_size_cur, mode);//������

	cct_setcolor();
	cct_gotoxy(0, 4 * y_size_cur + 2);
	cout << "��ͷ���ƶ����س���ѡ��";

	//������
	for (int y = 0; y < y_size_cur; y++) {
		for (int x = 0; x < x_size_cur; x++) {
			block(matrix, matrix_mark, x, y, '8');
		}
	}


	x = 0, y = 0;

	while (loop) {
		if (mode == '8')
			loop = 0;

		//�޿ɺϲ��������
		if (is_over(matrix, matrix_mark, x_size_cur - 1, y_size_cur - 1)) {
			cct_gotoxy(0, 4 * y_size_cur + 3);
			//cct_showstr(0, 4 * y_size_cur + 2, " ", 0, 7, 8 * x_size_cur + 3);
			cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
			cout << "�޿ɺϲ������Ϸ����";
			cct_setcolor();
			cout << "��Q�˳�";
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
				cout << endl << "�����������������";
			}
			break;
		}

		move_and_pick(matrix, matrix_mark, x, y, x_size_cur - 1, y_size_cur - 1, '8');
		merge(matrix, matrix_mark, x, y, x_size_cur - 1, y_size_cur - 1);
		//��ӡ�÷�
		matrix_mark[y][x] = 0;
		cct_setcolor();
		cct_gotoxy(0, 0);
		cct_showstr(0, 0, " ", 0, 7, 50);
		cct_gotoxy(0, 0);
		score += (count(matrix, 0, x_size_cur - 1, y_size_cur - 1) + 1) * (matrix[y][x] - 1) * 3;
		cout << "���ε÷֣�" << (count(matrix, 0, x_size_cur - 1, y_size_cur - 1) + 1) * (matrix[y][x] - 1) * 3
			<< " �ܵ÷֣�" << score << " �ϳ�Ŀ�꣺" << goal << endl;




		//��˸Ч��
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
			cout << "��ɺϳɣ��س�������0";

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
			cout << "����0��ɣ��س��������ֵ";
			is_enter();
		}

		//����max_numʱ,��falg����
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
			cout << "���κϳɽ�������C������һ�εĺϳ�";
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
			cout << "�Ѿ��ϳɵ�" << max_num;
			cct_setcolor();
			cout << "���س������������Ŀ�����";
			is_enter();
			cct_showstr(0, 4 * y_size_cur + 2, " ", 0, 7, 8 * x_size_cur + 3);
			cct_gotoxy(0, 4 * y_size_cur + 2);
			cout << "��ͷ���ƶ����س���ѡ��";
		}

	}
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	is_end(0, 4 * y_size_cur + 2);

}
