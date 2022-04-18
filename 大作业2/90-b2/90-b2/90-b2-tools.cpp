/*1951393 �Զ��� �����*/


#include <iostream>
#include <conio.h>
#include<time.h> 
#include<iomanip> 
#include <Windows.h>
#include "90-b2.h"
#include "cmd_console_tools.h"

using namespace std;



/***************************************************************************
  �������ƣ�
  ��    �ܣ���������
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�
  ��    �ܣ�Ѱ�Ҿ����е����ֵ��random�����ֵ����
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�
  ��    �ܣ��ϲ��ĸ��� ���ڼ������
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�
  ��    �ܣ���ʼ���� ���� �ϳ�Ŀ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void input_init(int& x_size_cur, int& y_size_cur, int& goal, char mode)
{
	int x_cursor, y_cursor;//��¼���λ��



	cct_cls();
	cout << "����������(5-8)��";
	cct_getxy(x_cursor, y_cursor);

	while (1) {
		cin >> y_size_cur;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����������������.";
			cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//10�ɸ���
			cct_gotoxy(x_cursor, y_cursor);

			continue;
		}

		if (y_size_cur >= 5 && y_size_cur <= 8) {
			cct_getxy(x_cursor, y_cursor);
			cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//20�ɸ���,�������
			cct_gotoxy(x_cursor, y_cursor);
			break;
		}
		else {
			cout << "�����������������.";
			cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//20�ɸ���,�������
			cct_gotoxy(x_cursor, y_cursor);

		}

	}

	cout << "����������(5-10)��";
	cct_getxy(x_cursor, y_cursor);
	while (1) {
		cin >> x_size_cur;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����������������.";
			cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//10�ɸ���
			cct_gotoxy(x_cursor, y_cursor);

			continue;
		}

		if (x_size_cur >= 5 && x_size_cur <= 10) {
			cct_getxy(x_cursor, y_cursor);
			cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//20�ɸ���,�������
			cct_gotoxy(x_cursor, y_cursor);
			break;
		}
		else {
			cout << "�����������������.";
			cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//20�ɸ���,�������
			cct_gotoxy(x_cursor, y_cursor);

		}

	}

	if (mode == '3' || mode == '4' || mode == '8' || mode == '9') {
		cout << "������ϳ�Ŀ��(5-20)��";
		cct_getxy(x_cursor, y_cursor);
		while (1) {
			cin >> goal;//�ǵüӴ���

			if (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�����������������.";
				cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//10�ɸ���
				cct_gotoxy(x_cursor, y_cursor);

				continue;
			}

			if (goal >= 5 && goal <= 20) {
				cct_getxy(x_cursor, y_cursor);
				cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//20�ɸ���,�������
				cct_gotoxy(x_cursor, y_cursor);
				break;
			}
			else {
				cout << "�����������������.";
				cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//20�ɸ���,�������
				cct_gotoxy(x_cursor, y_cursor);

			}

		}
	}

	cout << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ж��Ƿ���������޿ɺϲ����������
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�
  ��    �ܣ��ȴ�����end��ΪÿһС��Ľ���
  ���������X��Y��ʾ��ʱ����λ��
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void is_end(int X, int Y)
{
	int X1, Y1;//�ݴ���λ��
	char str[100] = { '\0' };
	cct_gotoxy(X, Y);
	cct_showstr(X, Y, " ", 0, 7, 40);
	cct_gotoxy(X, Y);
	cout << "��С�������������End����...";
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
		cout << "�����������������";
		cct_gotoxy(X1, Y1);
	}

}