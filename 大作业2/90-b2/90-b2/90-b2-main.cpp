/*1951393 �Զ��� �����*/


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
  �������ƣ�
  ��    �ܣ��˵� �����ò�������ĺ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char menu()
{
	char mode;

	cout << "---------------------------------" << endl;
	cout << "1.�������ҳ��ɺϳ����ʶ���ǵݹ飩" << endl;
	cout << "2.�������ҳ��ɺϳ����ʶ���ݹ飩" << endl;
	cout << "3.���������һ�κϳɣ��ֲ�����ʾ��" << endl;
	cout << "4.�����������棨�ֲ�����ʾ��" << endl;
	cout << "5.αͼ�ν�����ʾ��ʼ���飨�޷ָ��ߣ�" << endl;
	cout << "6.αͼ�ν�����ʾ��ʼ���飨�зָ��ߣ�" << endl;
	cout << "7.αͼ�ν������ü�ͷ��ѡ��ǰɫ��" << endl;
	cout << "8.αͼ�ν������һ�κϳɣ��ֲ��裩" << endl;
	cout << "9.αͼ�ν���������" << endl;
	cout << "0.�˳�" << endl;
	cout << "---------------------------------" << endl;
	cout << "[��ѡ��0-9] ";

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
  �������ƣ�
  ��    �ܣ�����ѡ���Ӧ�ĺ���
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/

int main()
{

	int x = 0, y = 0;
	int x_size_cur, y_size_cur;
	int goal = 5;//�ϳ�Ŀ��

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

		ChooseMode(matrix, matrix_mark, x, y, x_size_cur, y_size_cur, mode, goal);//����ѡ����ò˵������Ӧ��ִ�к���
		matrix_set0(matrix, x_size_cur - 1, y_size_cur - 1);
		matrix_set0(matrix_mark, x_size_cur - 1, y_size_cur - 1);

		
		cct_setcolor(); //�ָ�ȱʡ��ɫ;
		cct_setcursor(CURSOR_VISIBLE_NORMAL);  //�����ʾ����
		
		//cct_setcursor(CURSOR_INVISIBLE);
	}

	return 0;
}