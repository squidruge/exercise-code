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
  ��    �ܣ�mode  '1' '2' ��ʵ�� '2'�ǵݹ鷽ʽ �˺���ͨ�����οɱ�����mode����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int mode12(int matrix[][10], int matrix_mark[][10], int& x, int& y, int xm, int ym, char mode)
{

	int flag = 0;//���ÿ��ѭ��Ѱ�����ޱ�����ӣ������ӣ����˳�ѭ�� ��Ŀ1����

	cout << "��ǰ���飺" << endl;
	print_matrix(matrix, matrix_mark, 0, 0, xm, ym);


	int num = 0; //matrix[y][x] ;

	//�޿ɺϲ��������
	if (is_over(matrix, matrix_mark, xm, ym)) {

		cct_setcolor(COLOR_HYELLOW, COLOR_RED);
		cout << "�޿ɺϲ������Ϸ����" << endl;
		cct_setcolor();

		if (mode == '1' || mode == '2') {
			int X, Y;
			cct_getxy(X, Y);
			is_end(0, Y + 1);

		}
		return 0;
	}

	while (1) {

		cout << "������ĸ+������ʽ[����c2]����������꣺";
		input_posi(matrix_mark, matrix, x, y, num, xm, ym);

		if (mode == '1') {
			while (1) {
				flag = 0;
				for (int j = 0; j <= ym; j++) {
					for (int i = 0; i <= xm; i++) {

						if (matrix_mark[j][i]) {

							if (find_near(matrix, matrix_mark, i, j, xm, ym, '1'))
								flag++;//���һ��ѭ���мӱ�־����flag��Ϊ0

						}
					}
				}

				if (!flag) {
					break;
				}
			}
		}
		else if (mode == '2') {
			find_near(matrix, matrix_mark, x, y, xm, ym, '2');//�ݹ麯��
		}
		else {
			find_near(matrix, matrix_mark, x, y, xm, ym, '2');//��������С������mode12 ѡ��ݹ�����޲��
		}

		if (count(matrix_mark, 1, xm, ym) > 1) {
			cout << endl;
			break;
		}
		else {

			cout << "����ľ�������λ�ô���������ֵͬ������������" << endl;
		}
	}


	cout << "���ҽ�����飺" << endl;
	print_matrix(matrix_mark, matrix_mark, 0, 1, xm, ym);


	cout << endl << "��ǰ���飺(��ͬɫ��ʶ)" << endl;
	print_matrix(matrix, matrix_mark, 1, 0, xm, ym);

	if (mode == '1' || mode == '2') {
		int X, Y;
		cct_getxy(X, Y);
		is_end(0, Y + 1);
	}
	return 1;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�mode  '3''4'  ��ʵ��
  ���������
  �� �� ֵ��
  ˵    ����
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

		cout << "��ȷ���Ƿ�����ڵ���ֵͬ�ϲ���" << char(y + 'A') << x << "��(Y/N/Q)��";

		ch = _getch();
		while (ch != 'Y' && ch != 'Q' && ch != 'N' &&
			ch != 'y' && ch != 'q' && ch != 'n')
		{
			ch = _getch();
		}

		cout << char(ch) << endl << endl;

		if (ch == 'Y' || ch == 'y') {
			cout << "��ֵͬ�鲢�������(��ͬɫ��ʶ)��" << endl;
			merge(matrix, matrix_mark, x, y, xm, ym);
			print_matrix(matrix, matrix_mark, 1, 0, xm, ym);
			matrix_mark[y][x] = 0;
			score += (count(matrix, 0, xm, ym) + 1) * (matrix[y][x] - 1) * 3;
			cout << "���ε÷֣�" << (count(matrix, 0, xm, ym) + 1) * (matrix[y][x] - 1) * 3
				<< " �ܵ÷֣�" << score << " �ϳ�Ŀ�꣺" << goal << endl;

			cout << endl << "���س����������������0����..." << endl;
			is_enter();
			fall(matrix, matrix_mark, x, y, xm, ym);
			cout << "��0�������(��ͬɫ��ʶ)��" << endl;
			print_matrix(matrix, matrix_mark, 1, 0, xm, ym);

			cout << "���س���������ֵ���..." << endl;
			is_enter();
			max_num = find_max(matrix, xm, ym);
			fill_up(matrix, matrix_mark, x, y, xm, ym, max_num);
			cout << "��ֵ���������(��ͬɫ��ʶ)��" << endl;
			print_matrix(matrix, matrix_mark, 1, 0, xm, ym);

			if (mode == '4') {
				cout << "���κϳɽ��������س���������һ�εĺϳ�..." << endl;
				max_num = find_max(matrix, xm, ym);
				if (goal == max_num) {
					cct_setcolor(COLOR_HYELLOW, COLOR_RED);
					cout << "�Ѿ��ϳɵ�" << goal;
					cct_setcolor(COLOR_BLACK, COLOR_WHITE);
					cout << endl << "���س������������Ŀ�����..." << endl;
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
  �������ƣ�
  ��    �ܣ���ӡ����(�ڲ�����)
  ���������high_light 1 ��ɫ 0 ��ɫ numҪ��ǵ���ɫ
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�
  ��    �ܣ����� x,y
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void input_posi(int matrix_mark[][10], int matrix[][10], int& x, int& y, int& num, int xm, int ym)
{
	int x_cursor, y_cursor;//��¼���λ��
	char posi_str[3] = { '\0' };//��һ���ַ��� y �ڶ��� x
	matrix_set0(matrix_mark, xm, ym);
	//int wrong_input=0;

	cct_getxy(x_cursor, y_cursor);

	while (1) {
		cin.getline(posi_str, 3);//��demo��ͬ demoӦ����ֻ��ǰ����


		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����������������.";
			cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//10�ɸ���
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
			cout << "�����������������.";
			cct_showch(x_cursor, y_cursor, ' ', COLOR_BLACK, COLOR_WHITE, 20);//10�ɸ���
			cct_gotoxy(x_cursor, y_cursor);

		}

	}

	y = posi_str[0] - 'A';
	x = posi_str[1] - '0';
	matrix_mark[y][x] = 1;
	num = matrix[y][x];
	cout << "����Ϊ" << posi_str[0] << "��" << x << "��";
	/*
	ͻȻ��ʶ���ⲻ������Ϊ֮��ϸ�� ֻ��û�������
	if (wrong_input)
		cout << "��������.";*/
	cout << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ������󣨶�ά���飩��ʼ�� �������
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�
  ��    �ܣ�ȡ�����
  ���������
  �� �� ֵ��
  ˵    ����
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
			ret = temp / (80 / (max_num - 3)) + 1;// 80%(x-3) ���ֺ�ȡ��
		}
		break;
	}

	return ret;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�������4��������ֵͬ�������б��   mode == '1'��Ӧ��ʽ1ѭ����ʽ  mode == '2'��Ӧ�ݹ鷽ʽ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int find_near(int matrix[][10], int matrix_mark[][10], int x, int y, int xm, int ym, char mode)
{
	int num = matrix[y][x];
	int x_cur, y_cur;
	int flag = 0;//���ÿ��ѭ��Ѱ�����ޱ�����ӣ������ӣ����˳�ѭ��

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
				find_near(matrix, matrix_mark, x_cur, y_cur, xm, ym, '2');//�ݹ�
		}
	}
	return flag;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ȴ�һ���س�
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�
  ��    �ܣ���ֵͬ�鲢
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void merge(int matrix[][10], int matrix_mark[][10], int x, int y, int xm, int ym)
{
	matrix[y][x]++;

	for (int j = 0; j <= ym; j++) {
		for (int i = 0; i <= xm; i++) {

			if (matrix_mark[j][i]) {

				if (i != x || j != y) {
					matrix[j][i] = 0;//��Ǿ�����0 ����ʹ�ý�������0
				}


			}
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void fall(int matrix[][10], int matrix_mark[][10], int x, int y, int xm, int ym)
{
	int cnt0 = 0;//0�ĸ���

	for (int i = xm; i >= 0; i--) {
		for (int j = ym; j > 0; ) {

			if (matrix[j][i] == 0) {
				cnt0 = 0;
				for (int k = j; k >= 0; k--) {

					if (matrix[k][i] == 0) {
						cnt0++;
					}
				}
				//cout << "i=" << i << " " << cnt0 << endl;//debug�� ��cnt0 д��cnt�������Ƕ���
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
  �������ƣ�
  ��    �ܣ����0��λ��
  ���������
  �� �� ֵ��
  ˵    ����
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



