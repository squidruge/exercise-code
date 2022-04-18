/*1951393 �Զ��� �����*/
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
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

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/***************************************************************************
  �������ƣ�move_by_ijkl
  ��    �ܣ�move
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ������������ַ�
  �� �� ֵ����
  ˵    ��
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
				//Y--;//I ��
				if (Y != 1)
					gotoxy(hout, X, --Y);
				break;
			case 75:
			case 107:
				//Y++;//K ��
				if (Y != MAX_Y)
					gotoxy(hout, X, ++Y);
				break;
			case 74:
			case 106:
				if (X != 1)
					//X--;//J ��
					gotoxy(hout, --X, Y);
				break;
			case 76:
			case 108:
				if (X != MAX_X)
					//X++;//L ��
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
				//Y--;//I ��
				if (Y != 1)
					Y--;
				else
					Y = MAX_Y;

				gotoxy(hout, X, Y);
				break;
			case 75:
			case 107:
				//Y++;//K ��
				if (Y != MAX_Y)
					Y++;
				else
					Y = 1;

				gotoxy(hout, X, Y);
				break;
			case 74:
			case 106:
				if (X != 1)
					//X--;//J ��
					X--;
				else
					X = MAX_X;

				gotoxy(hout, X, Y);
				break;
			case 76:
			case 108:
				if (X != MAX_X)
					//X++;//L ��
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
				case 72: //��
					if (Y != 1)
						gotoxy(hout, X, --Y);
					break;
				case 80:// ��
					if (Y != MAX_Y)
						gotoxy(hout, X, ++Y);
					break;
				case 75://��
					if (X != 1)
						gotoxy(hout, --X, Y);
					break;
				case 77:// ��
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
				case 72: //��
					if (Y != 1)
						Y--;
					else
						Y = MAX_Y;

					gotoxy(hout, X, Y);
					break;
				case 80:// ��
					if (Y != MAX_Y)
						Y++;
					else
						Y = 1;

					gotoxy(hout, X, Y);
					break;
				case 75://��
					if (X != 1)
						X--;
					else
						X = MAX_X;

					gotoxy(hout, X, Y);
					break;
				case 77:// ��
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
				//Y--;//I ��
				if (Y != 1)
					gotoxy(hout, X, --Y);
				break;
			case 75:
			case 107:
				//Y++;//K ��
				if (Y != MAX_Y)
					gotoxy(hout, X, ++Y);
				break;
			case 74:
			case 106:
				if (X != 1)
					//X--;//J ��
					gotoxy(hout, --X, Y);
				break;
			case 76:
			case 108:
				if (X != MAX_X)
					//X++;//L ��
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
				//Y--;//I ��
				if (Y != 1)
					Y--;
				else
					Y = MAX_Y;

				gotoxy(hout, X, Y);
				break;
			case 75:
			case 107:
				//Y++;//K ��
				if (Y != MAX_Y)
					Y++;
				else
					Y = 1;

				gotoxy(hout, X, Y);
				break;
			case 74:
			case 106:
				if (X != 1)
					//X--;//J ��
					X--;
				else
					X = MAX_X;

				gotoxy(hout, X, Y);
				break;
			case 76:
			case 108:
				if (X != MAX_X)
					//X++;//L ��
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
  �������ƣ�menu
  ��    �ܣ����ɲ˵�������ѡ�� 
  ���������
  �� �� ֵ��mode  0 - 6
  ˵    ����
***************************************************************************/
int menu() {

	cout << "1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" << endl;
	cout << "2.��I��J��K��L��������������(��Сд���ɣ��߽����)" << endl;
	cout << "3.�ü�ͷ�������������ң��߽�ֹͣ" << endl;
	cout << "4.�ü�ͷ�������������ң��߽����" << endl;
	cout << "5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ,�����ͷ����׼�����ƶ�)" << endl;
	cout << "6.��I��J��K��L��������������(��Сд���ɣ��߽����,�����ͷ����׼�����ƶ�)" << endl;
	cout << "0.�˳�" << endl;
	cout << "[��ѡ��0 - 6] ";
	char mode;
	mode = _getche();

	return mode;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��



	char mode = 1;


	while (mode != '0') {
		/* �˾�������ǵ���ϵͳ��cls�������� */
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
		/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
		srand((unsigned int)(time(0)));

		/* �˾�������ǵ���ϵͳ��cls�������� */
		cls(hout);

		/* ��ʾ��ʼ�ı߿����е�����ַ� */
		init_border(hout);

		int X = 35, Y = 9;//ͣ������
		gotoxy(hout, X, Y);
		//��ͣ


		move(hout, X, Y, mode);



		gotoxy(hout, 0, 23);
		cout << "��Ϸ���������س����˳�." << endl;

		//��ͣ(�˴���ҵҪ����ֻ�ܰ��س��˳���Ŀǰ��getcharʾ���������������+�س��˳�������������������Ļ��)
		while (_getch() != 13)
			;
		//�޸�Ϊѭ��
	}
	return 0;
}
