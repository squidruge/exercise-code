#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;

/* -----------------------------------------

	 ���ļ����ܣ�
	1���ű� hanoi_main.cpp/hanoi_menu.cpp �еĸ��������õĲ˵������Ӧ��ִ�к���

	 ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------- */
static int sum = 0;  //��¼�ƶ�����
static int abc[3][10] = { {0},{0},{0} }; //����ֵ
static int tabc[3] = { 0 };  //��¼ջ��λ��

/* ���ڸ�sum���������㸳��ֵ���� */
void fresh()
{
	int i, j;
	sum = 0;
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			abc[i][j] = 0;
		}
		tabc[i] = 0;
	}
	return;
}
/* ����������飬�������Ϊ�������Լ���ʼ��xy����� */
void output_szline(int a[], int n, int x, int y) //����������飬�������Ϊ�������Լ���ʼ��xy�����
{
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		cct_gotoxy(x, y - i);
		cout << a[i];
	}
	return;
}
/* ֱ������enter������ */
void is_enter()
{
	char ch;
	ch = _getch();
	while (ch != '\r')
	{
		ch = _getch();
	}
	return;
}

/* ��¼ջ��λ��,a[x]!=0ʱ����x+1,���ҵ�a[0]==0ʱ������0 */
int top(int a[], int n)
{
	int i = 0;
	for (i = n - 1; i >= 0; --i)
	{
		if (a[i] != 0)
			break;
	}
	return i + 1;    //��¼ջ����λ��
}
/* ������������� */
void output_sz(int a[], int n)   //���ĳ�������Լ���ߵĿո�
{
	int k = 21 - 2 * n;
	for (int j = 0; j < n; ++j)
	{
		cout << setw(2) << a[j];
	}
	cout << setw(k) << " ";
	return;
}

/* �����鸳ֵ��a[0]�������� */
void input_sz(int a[], int n)  //�����鸳ֵ,a[0]������
{
	int s = 0;
	int t = 1;
	for (s = n - 1; s >= 0; --s)
	{
		a[s] = t;
		t++;
	}
	return;
}

/* ����ʼʱ�����ӣ��������Ϊ��ʼ������źͲ��� */
void tianchongsz(char src, int n)
{
	input_sz(abc[src - 'A'], n);
}

/* ѡ��12����Ҫspeed������Ĭ��Ϊ0 */
void print_steps_12(int n, char src, char tmp, char dst, char choice, int speed)
{
	if (choice == '1')
	{
		cout << n << "# " << src << "-->" << dst << endl;
	}
	if (choice == '2')
	{
		cout << "��" << setw(4) << ++sum << " ��(" << setw(2) << n << "#: " << src << "-->" << dst << ")" << endl;
	}
	return;
}
/* ����348�ĺ����ӡ */
void print_steps_row(int n, char src, char tmp, char dst, char choice, int speed)
{
	if (choice == '3')
	{
		abc[src - 'A'][--tabc[src - 'A']] = 0;  //     abc[0][--tabc[0]] = 0;
		abc[dst - 'A'][tabc[dst - 'A']++] = n;		
		cout << "��" << setw(4) << ++sum << " " << "��(" << setw(2) << n << "#: " << src << "-->" << dst << ")  ";
		cout << "A:";
		output_sz(abc[0], tabc[0]);  //�����ջ��
		cout << "B:";
		output_sz(abc[1], tabc[1]);
		cout << "C:";
		output_sz(abc[2], tabc[2]);
		cout << endl;
	}
	if (choice == '4'||choice=='8')
	{
		abc[src - 'A'][--tabc[src - 'A']] = 0;  //     abc[0][--tabc[0]] = 0;
		abc[dst - 'A'][tabc[dst - 'A']++] = n;
		switch (speed)
		{
			case 5:
				break;
			case 4:
				Sleep(50);
				break;
			case 3:
				Sleep(200);
				break;
			case 2:
				Sleep(500);
				break;
			case 1:
				Sleep(1000);
				break;
			case 0:
				is_enter();
				break;
		}
		if (choice == '4') //���4 8λ�ò�ͬ��һ��ѡ��ṹ
		{
			cct_gotoxy(0, 17);
		}
		else
		{
			cct_gotoxy(0, 32);
		}
		cout << "��" << setw(4) << ++sum << " ��( " << n << "#: " << src << "-->" << dst << ")  ";
		cout << "A:";
		output_sz(abc[0], tabc[0]);  //�����ջ��
		cout << "B:";
		output_sz(abc[1], tabc[1]);
		cout << "C:";
		output_sz(abc[2], tabc[2]);
	}
}
/* ����48�������ӡ */
void print_steps_column(int n, char src, char tmp, char dst, char choice, int speed)
{
	if (choice == '4')
	{
		cct_gotoxy(11 + (src - 'A') * 10, 11 - tabc[src - 'A']);   //������ʼ����ջ��λ��
		cout << " ";
		cct_gotoxy(11 + (dst - 'A') * 10, 12 - tabc[dst - 'A']);   //����Ŀ������ջ��λ��
		cout << n;
	}
	if (choice == '8')
	{
		cct_gotoxy(11 + (src - 'A') * 10, 26 - tabc[src - 'A']);   //������ʼ����ջ��λ��
		cout << " ";
		cct_gotoxy(11 + (dst - 'A') * 10, 27 - tabc[dst - 'A']);   //����Ŀ������ջ��λ��
		cout << n;
	}
}
/* ����8,���ӵĴ�ӡ */
void print_steps_plates(int n, char src, char tmp, char dst, char choice, int speed)
{
	move_once(14 - tabc[src - 'A'], 15 - tabc[dst - 'A'], n, src, tmp, dst, speed);
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}

/* �ܵĴ�ӡ���� */
void print_steps(int n, char src, char tmp, char dst, char choice, int speed)
{	
	if (choice == '1' || choice == '2')  //��һ�������
	{
		print_steps_12(n, src, tmp, dst, choice, speed);
	}
	if (choice == '3' || choice == '4' || choice == '8')
	{
		print_steps_row(n, src, tmp, dst, choice, speed);
		if (choice == '4' || choice == '8')
		{
			print_steps_column(n, src, tmp, dst, choice, speed);
		}
		if (choice == '8')
		{
			print_steps_plates(n, src, tmp, dst, choice, speed);
		}
	}
}

/* �����ӵĺ���,����x��y����1,15 */
void draw_tree(int x,int y)
{
	//cct_setcursor(CURSOR_INVISIBLE);  //�رչ����ʾ
	int i, j;
	for (i = 0; i < 3; ++i)  //�����
	{
		cct_showch(x + 32 * i, y, ' ', COLOR_HYELLOW, COLOR_WHITE, 23);
	}
	for (i = 0; i < 12; ++i)  //������
	{
		//cct_gotoxy(12 + x, y - 1 - i);
		for (j = 0; j < 3; ++j)
		{
			cct_showch(11 + x + 32 * j, y - 1 - i, ' ', COLOR_HYELLOW, COLOR_WHITE, 1);
		}
		Sleep(150);    //��ͣ0.15s�����ڹ۲�
	}
	//cct_setcursor(CURSOR_VISIBLE_NORMAL);  //�����ʾ����
	return;
}

/* ����Ϊnʱ��src�ϻ�n������ */
void draw_plates(int n, char src, char dst)
{
	//cct_setcursor(CURSOR_INVISIBLE);  //�رչ����ʾ
	int i = 0;
	int left_lowest = (12 + (src - 'A') * 32) - n;
	int lenth_begin = 2 * n + 1;
	for (i = 0; i < n; ++i)
	{
		cct_showch(left_lowest + i, 14 - i, ' ', n - i, COLOR_WHITE, lenth_begin - 2 * i);  //������
		Sleep(50);
	}
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);  //�ָ�������ɫ
	//cct_setcursor(CURSOR_VISIBLE_NORMAL);  //�����ʾ����
}

/* ��src�����ϱߵ����Ӵ�y==top�ᵽy==1�ĵط� */
void move_up(int top_src, int top_dst, int num_plate, char src, char tmp, char dst, int speed)
{
	int x, y, lenth;
	x = 12 + (src - 'A') * 32 - num_plate;  //��ʼsrc������ߵ�xֵ
	lenth = 2 * num_plate + 1;
	for (y = top_src; y >= 1; y--)
	{
		cct_showstr(x, y, " ", num_plate, COLOR_WHITE, lenth);   // ������ߴ�ӡlenth���ȸ��ո�		
		switch (speed)
		{
			case 5:
				break;
			case 4:
				Sleep(50);
				break;
			case 3:
				Sleep(100);
				break;
			case 2:
				Sleep(500);
				break;
			case 1:
				Sleep(1000);
				break;
			case 0:
				Sleep(100);     //��ʱ������˸�������������ֻ���ƶ�һ�����Ӱ���һ��enter
				break;
		}
		if (y != 1)
		{
			/* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
			cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, lenth);
			if (y > 2)
			{
				cct_showch(x + num_plate, y, ' ', COLOR_HYELLOW, COLOR_WHITE, 1);  //���м������������ɫ
			}
		}
	}
}

/* �����ƶ�����srcͷ���ƶ���dstͷ�� */
void move_lr(int num_plate, char src, char tmp, char dst, int speed)
{
	int x, y, x0, x_dst, lenth;
	y = 1;
	int judge = dst - src;   //�жϳ�ʼ����Ŀ����˭��˭С
	x0 = 12 + (src - 'A') * 32 - num_plate;  //��ʼsrc������ߵ�xֵ
	x_dst = 12 + (dst - 'A') * 32 - num_plate;   //�յ�dst������ߵ�xֵ
	lenth = 2 * num_plate + 1;
	if (judge > 0)  //��ʼ���Ƚ�С�������ƶ�
	{
		for (x = x0; x <= x_dst; x++)
		{
			/* ������(x,2)λ�ô�������ӡ10���ַ� */
			cct_showch(x, y, ' ', num_plate, COLOR_WHITE, lenth);
			switch (speed)
			{
				case 5:
					break;
				case 4:
					Sleep(50);
					break;
				case 3:
					Sleep(100);
					break;
				case 2:
					Sleep(500);
					break;
				case 1:
					Sleep(1000);
					break;
				case 0:
					//is_enter();
					Sleep(100);     //��ʱ������˸�������������ֻ���ƶ�һ�����Ӱ���һ��enter
					break;
			}
			if (x < x_dst)
			{
				/* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
				cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, lenth);
			}
		} //end of for
	}
	if (judge < 0)  //��ʼ���Ƚ�С,�����ƶ�
	{
		for (x = x0; x >= x_dst; x--)
		{
			/* ������(x,1)λ�ô�������ӡ10���ַ� */
			cct_showch(x, y, ' ', num_plate, COLOR_WHITE, lenth);
			switch (speed)
			{
				case 5:
					break;
				case 4:
					Sleep(50);
					break;
				case 3:
					Sleep(100);
					break;
				case 2:
					Sleep(500);
					break;
				case 1:
					Sleep(1000);
					break;
				case 0:
					//is_enter();
					Sleep(100);     //��ʱ������˸�������������ֻ���ƶ�һ�����Ӱ���һ��enter
					break;
			}
			if (x > x_dst)
			{
				/* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
				cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, lenth);
			}
		} //end of for
	}
}

/* ��dst�����ϱߵ����Ӵ�y==1�ᵽy==top�ĵط� */
void move_down(int top_src, int top_dst, int num_plate, char src, char tmp, char dst, int speed)
{
	int x, y, lenth;
	x = 12 + (dst - 'A') * 32 - num_plate;  //��ʼsrc������ߵ�xֵ
	lenth = 2 * num_plate + 1;
	for (y = 1; y <= top_dst; y++)
	{
		cct_showstr(x, y, " ", num_plate, COLOR_WHITE, lenth);   // ������(x,2)λ�ô�������ӡ10���ַ�		
		switch (speed)
		{
			case 5:
				break;
			case 4:
				Sleep(50);
				break;
			case 3:
				Sleep(100);
				break;
			case 2:
				Sleep(500);
				break;
			case 1:
				Sleep(1000);
				break;
			case 0:
				//is_enter();
				Sleep(100);     //��ʱ������˸�������������ֻ���ƶ�һ�����Ӱ���һ��enter
				break;
		}
		if (y < top_dst)
		{
			/* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
			cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, lenth);
			if (y < top_dst && y>2)
			{
				cct_showch(x + num_plate, y, ' ', COLOR_HYELLOW, COLOR_WHITE, 1);  //���м������������ɫ
			}
		}
	}
}

/* ��ɴ�src��top��dst��topһ���ƶ��ĺ��� */
void move_once(int top_src, int top_dst, int num_plate, char src, char tmp, char dst, int speed)
{
	//cct_setcursor(CURSOR_INVISIBLE);  //�رչ����ʾ
	move_up(top_src, top_dst, num_plate, src, tmp, dst, speed);
	move_lr(num_plate, src, tmp, dst, speed);
	move_down(top_src, top_dst, num_plate, src, tmp, dst, speed);
	//cct_setcursor(CURSOR_VISIBLE_NORMAL);  //�����ʾ����
	return;
}

/* �˵�123��Ĺ��ܺ��� */
void mode_123(int n, char src, char tmp, char dst, char choice, int speed)
{
	cct_setcursor(CURSOR_INVISIBLE);  //�رչ����ʾ
	tianchongsz(src, n);  //����������Ӧ������
	tabc[0] = top(abc[0], n);      //��¼ջ��λ��
	tabc[1] = top(abc[1], n);
	tabc[2] = top(abc[2], n);
	hanoi(n, src, tmp, dst, choice, speed);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);  //�����ʾ����
	fresh();
	cout << endl;
	cout << "���س�������";
	is_enter();
}
/* �˵�4��Ĺ��ܺ��� */
void mode_4(int n, char src, char tmp, char dst, char choice, int speed)
{
	cct_setcursor(CURSOR_INVISIBLE);  //�رչ����ʾ
	tianchongsz(src, n);  //����������Ӧ������
	tabc[0] = top(abc[0], n);      //��¼ջ��λ��
	tabc[1] = top(abc[1], n);
	tabc[2] = top(abc[2], n); 

	cct_cls();
	cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << speed;
	cct_gotoxy(0, 17);
	cout << "��ʼ:  ";
	cout << "A:";
	output_sz(abc[0], tabc[0]);
	cout << "B:";
	output_sz(abc[1], tabc[1]);
	cout << "C:";
	output_sz(abc[2], tabc[2]);   //��ӡ��һ��

	cct_gotoxy(9, 12);  //��ӡ��������
	cout << "=========================" << endl;
	cct_gotoxy(11, 13);
	cout << "A         B         C" << endl;

	output_szline(abc[0], tabc[0], 11, 11);
	output_szline(abc[1], tabc[1], 21, 11);
	output_szline(abc[2], tabc[2], 31, 11);
	hanoi(n, src, tmp, dst, choice, speed);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);  //�����ʾ����
	fresh();   //��ʼ��ȫ�ֱ���
	cct_gotoxy(0, 38);  //�ص�����ȥ��ӡ������ʾ
	cout << "���س�������";
	is_enter();
}
/* �˵�5��Ĺ��ܺ��� */
void mode_5()
{
	cct_setcursor(CURSOR_INVISIBLE);  //�رչ����ʾ
	cct_cls();
	draw_tree(1, 15);
	cct_setcolor(); //�ָ�ȱʡ��ɫ;
	cct_gotoxy(0, 38);  //�ص�����ȥ��ӡ������ʾ
	cct_setcursor(CURSOR_VISIBLE_NORMAL);  //�����ʾ����
	cout << "���س�������";
	is_enter();
}
/* �˵�6��Ĺ��ܺ��� */
void mode_6(int n, char src, char tmp, char dst)
{
	cct_setcursor(CURSOR_INVISIBLE);  //�رչ����ʾ
	cct_cls();  //����
	cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��";
	draw_tree(1, 15);
	draw_plates(n, src, dst);
	cct_setcolor(); //�ָ�ȱʡ��ɫ
	cct_setcursor(CURSOR_VISIBLE_NORMAL);  //�����ʾ����
	cct_gotoxy(0, 38);
	cout << "���س�������";
	is_enter();
}
/* �˵�7��Ĺ��ܺ��� */
void mode_7(int n, char src, char tmp, char dst, char choice, int speed)
{
	cct_setcursor(CURSOR_INVISIBLE);  //�رչ����ʾ
	cct_cls();  //����
	cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��";
	draw_tree(1, 15);
	Sleep(500);
	draw_plates(n, src, dst);
	Sleep(500);
	if (n % 2 == 1)
	{
		move_once(15 - n, 14, 1, src, tmp, dst, 3);  //����Ų��Ŀ����
	}
	else
	{
		move_once(15 - n, 14, 1, src, dst, tmp, 3);    //ż��Ų����ת��
	}
	cct_setcolor(); //�ָ�ȱʡ��ɫ
	cct_gotoxy(0, 38);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);  //�����ʾ����
	cout << "���س�������";
	is_enter();
}
/* �˵�8��Ĺ��ܺ��� */
void mode_8(int n, char src, char tmp, char dst, char choice, int speed)
{
	cct_setcursor(CURSOR_INVISIBLE);  //�رչ����ʾ
	tianchongsz(src, n);  //����������Ӧ������
	tabc[0] = top(abc[0], n);      //��¼ջ��λ��
	tabc[1] = top(abc[1], n);
	tabc[2] = top(abc[2], n);

	cct_cls();
	cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << speed;
	cct_gotoxy(0, 32);
	cout << "��ʼ:  ";
	cout << "A:";
	output_sz(abc[0], tabc[0]);
	cout << "B:";
	output_sz(abc[1], tabc[1]);
	cout << "C:";
	output_sz(abc[2], tabc[2]);   //��ӡ��һ��

	cct_gotoxy(9, 27);  //��ӡ��������
	cout << "=========================" << endl;
	cct_gotoxy(11, 28);
	cout << "A         B         C" << endl;

	draw_tree(1, 15);
	draw_plates(n, src, dst);   //������
	output_szline(abc[0], tabc[0], 11, 26);
	output_szline(abc[1], tabc[1], 21, 26);
	output_szline(abc[2], tabc[2], 31, 26);
	hanoi(n, src, tmp, dst, choice, speed);  //��ŵ����Ҫ���ܺ���
	cct_setcursor(CURSOR_VISIBLE_NORMAL);  //�����ʾ����
	fresh();   //��ʼ��ȫ�ֱ���
	cct_gotoxy(0, 38);  //�ص�����ȥ��ӡ������ʾ
	cout << "���س�������";
	is_enter();
}
/* ��Ϸ�汾 */
void game_pattern(int n, char src, char tmp, char dst, char choice, int speed)
{
	char dst_first = dst;  //��¼��ʼʱ��Ŀ����
	cct_setcursor(CURSOR_INVISIBLE);  //�رչ����ʾ
	tianchongsz(src, n);  //����������Ӧ������
	tabc[0] = top(abc[0], n);      //��¼ջ��λ��
	tabc[1] = top(abc[1], n);
	tabc[2] = top(abc[2], n);
	char judge_9 = 'O';  //��ʼ��,������ΪQ/q
	char tmparray[50] = " ";
	cct_cls();
	cout << "��" << src << "�ƶ���" << dst << "����" << n << "��";	
	cct_gotoxy(0, 32);
	cout << "��ʼ:  ";
	cout << "A:";
	output_sz(abc[0], tabc[0]);
	cout << "B:";
	output_sz(abc[1], tabc[1]);
	cout << "C:";
	output_sz(abc[2], tabc[2]);   //��ӡ��һ��
	cct_gotoxy(9, 27);  //��ӡ��������
	cout << "=========================" << endl;
	cct_gotoxy(11, 28);
	cout << "A         B         C" << endl;
	draw_tree(1, 15);     //������
	draw_plates(n, src, dst);   //������
	output_szline(abc[0], tabc[0], 11, 26);  //��ӡ��ʼ�ڲ�����
	output_szline(abc[1], tabc[1], 21, 26);
	output_szline(abc[2], tabc[2], 31, 26);	
	while (judge_9 != 'Q')
	{		
		input(&n, &src, &dst, &speed, '9', &judge_9);  //�����������ȥֵ  ��ε��ã����׳�������  12.2����
		if (judge_9 == 'Q')  //Q����
		{
			cct_gotoxy(0, 35);
			cout << "��Ϸ��ֹ!!!!!";
			break;
		}
		if (tabc[src - 'A'] == 0)  //ջ����0������
		{
			cct_gotoxy(0, 35);
			cout << "Դ��Ϊ��!";
			Sleep(1500);
			cct_gotoxy(0, 35);
			cout << "          "; //��ո�����⼸����
			continue;
		}
		if (tabc[dst - 'A'] != 0 && abc[src - 'A'][tabc[src - 'A'] - 1] > abc[dst - 'A'][tabc[dst - 'A'] - 1])  //����ѹС��
		{
			cct_gotoxy(0, 35);
			cout << "����ѹС�̣��Ƿ��ƶ�!";
			Sleep(1500);
			cct_gotoxy(0, 35);
			cout << "                            "; //��ո�����⼸����
			continue;
		}		
		abc[dst - 'A'][tabc[dst - 'A']++] = abc[src - 'A'][tabc[src - 'A'] - 1];  //����ʼջ���ĸ��ù�ȥ
		abc[src - 'A'][--tabc[src - 'A']] = 0;
		move_once(14 - tabc[src - 'A'], 15 - tabc[dst - 'A'], abc[dst - 'A'][tabc[dst - 'A'] - 1], src, tmp, dst, 5);
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);  //�ָ���ɫ
		cct_gotoxy(0, 32);  //׼������ȥ ��ӡ�����ڲ�����
		cout << "��" << setw(4) << ++sum << " " << "��(" << setw(2) << abc[dst - 'A'][tabc[dst - 'A'] - 1] << "#: " << src << "-->" << dst << ")  ";
		cout << "A:";
		output_sz(abc[0], tabc[0]);  //�����ջ��
		cout << "B:";
		output_sz(abc[1], tabc[1]);
		cout << "C:";
		output_sz(abc[2], tabc[2]);
		//����ȥ��ӡ��������
		cct_gotoxy(11 + (src - 'A') * 10, 26 - tabc[src - 'A']);   //������ʼ����ջ��λ��
		cout << " ";
		cct_gotoxy(11 + (dst - 'A') * 10, 27 - tabc[dst - 'A']);   //����Ŀ������ջ��λ��
		cout << abc[dst - 'A'][tabc[dst - 'A'] - 1];
		if (tabc[dst_first - 'A'] == n)  //��ҳɹ���ɺ�ŵ��
		{
			cct_gotoxy(0, 35);
			cout << "��Ϸ����!!!!!";
			break;
		}
	} 
	cct_setcursor(CURSOR_VISIBLE_NORMAL);  //�����ʾ����
	fresh();   //��ʼ��ȫ�ֱ���
	cct_gotoxy(0, 38);  //�ص�����ȥ��ӡ������ʾ
	cout << "���س�������";
	is_enter();
}
/* ѡ���ĸ�ģʽ�������� */
void mode_choice(int n, char src, char tmp, char dst, char choice, int speed)
{
	char judge_9 = 'P';
	switch (choice)
	{
		case '1':
		case '2':
		case '3':
			mode_123(n, src, tmp, dst, choice, speed);
			break;
		case '4':
			mode_4(n, src, tmp, dst, choice, speed);
			break;
		case '5':
			mode_5();
			break;
		case '6':
			mode_6(n, src, tmp, dst);
			break;
		case '7':
			mode_7(n, src, tmp, dst, choice, speed);
			break;
		case '8':
			mode_8(n, src, tmp, dst, choice, speed);
			break;
		case '9':
			input(&n, &src, &dst, &speed, '3', &judge_9);  //�ȳ�ʼ�����������
			game_pattern(n, src, tmp, dst, choice, speed);
			break;
		case '0':
			cct_gotoxy(0, 37);
			break;
	}
}


/***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
	 ��������� int n������
			   char src����ʼ��
			   char tmp���м���
			   char dst��Ŀ����
			   int choice: �˵�ѡ��
			   int speed: �ӳ�ѡ��
	 �� �� ֵ��
	 ˵    ����1�����������βΡ��������;���׼��
			   2������������������κ���ʽ��ѭ��
			   3��������һ����̬�ֲ�����
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst, char choice, int speed)
{	
	if (n == 1)   //1ʱ����
		print_steps(n, src, tmp, dst, choice, speed);
	else
	{
		hanoi(n - 1, src, dst, tmp, choice, speed);    //��1ִ��
		print_steps(n, src, tmp, dst, choice, speed);  //δ�����
		hanoi(n - 1, tmp, src, dst, choice, speed);
	}		
}

/* �ھ���ĵ����ַ����뺯��,ֻҪ�ǿɼ��ַ������ǻس����ͷ��ظü� */
char input_9_once()
{
	unsigned char ch;
	while (1)
	{
		ch = _getch();
		if (ch == 224)  //�����������Ҽ�ͷ����
		{
			ch = _getch();
			continue;
		}
		if (ch == '\r')  //�س�����
		{
			return ch;
		}
		if (ch >= 33 && ch <= 126) //�ɼ��ַ��ʹ��ȥ
		{
			cout << ch;   //�����ԭ���ַ����˹��������Ч��	
			if (ch >= 'a' && ch <= 'z')  //Сд���ش�д
			{
				ch = ch + 'A' - 'a';
			}
			return ch;
		}
	}
}

/* ����char�ַ������룬����Ϊ��ʾ�䣬�ж��ǲ�����ȵ�char��ѡ��ģʽ */
char input_char(const char remind[], char judge_char)
{
	char aim = '1';              //cout << "��������ʼ��(A-C)" << endl   cout << "������Ŀ����(A-C)" << endl;
	while (1)
	{
		cout << remind << endl;		
		cin >> aim;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;   //����Ƿ��Ļ����������룬���ٽ����ж������Ƿ����
		}
		cin.ignore(65536, '\n');  //�Ƿ�Ƿ�����ջ�����

		if (aim >= 'a' && aim <= 'c')
		{
			aim = aim + 'A' - 'a';  //ת��д
		}

		if (aim >= 'A' && aim <= 'C')
		{
			if (aim == judge_char)  //Ŀ��������ʼ����ͬ��������
			{
				cout << "Ŀ����(" << aim << ")��������ʼ��(" << aim << ")��ͬ" << endl;
				continue;
			}
			else
			{
				break;
			}
		}
	}
	return aim;
}
/* ��������������ٶ�speed */
int input_int(const char remind[], const int min, const int max)
{
	int s = -1;  //�ƶ��ٶ�(0-5)
	while (1)
	{
		cout << remind << endl;  //�����ʾ
		//cout << "�������ƶ��ٶ�(0-5��0-���س�������ʾ 1-��ʱ� 5-��ʱ���) " << endl;
		//cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
		cin >> s;   
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(65536, '\n');
			continue;   //����Ƿ��Ļ����������룬���ٽ����ж������Ƿ����
		}
		cin.ignore(65536, '\n');  //��ȷҲ��ջ�����
		if (s >= min && s <= max)
			break;
	}
	return s;
}
/* �ܵ�����������������ݲ�ͬ��choice����������ʲô���� */
void input(int* n, char* src, char* dst, int* speed, char choice, char* judge_9)
{
	int ch, i = 0, j = 0;
	//char src, dst;
	char tmparray[50] = " ";
	if (choice == '5')  //ֻ�����ӵĲ���������Щ
		return;

	if (choice == '9')
	{
		cct_gotoxy(0, 34);
		cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��";
		while (1)
		{
			i = 0;  //��ʼ��
			ch = 'F';  //��ʼ�����Ҳ��ܵ��ڻس�
			while (ch != '\r' && i < 20)  //���ǻس�����û�ﵽ20�������ȵ���һֱ���磬���Ҵ�����
			{
				ch = input_9_once(); //�ٴ�����
				tmparray[i] = ch;				
				i++;
			}  //�����˾�˵��ch=='\r'��
			//�Ϸ�����1:�����˲���ͬ����A-C��ĸ(3����Ϊ�пո�)
			if (i == 3 && tmparray[0] >= 'A' && tmparray[0] <= 'C' && tmparray[1] >= 'A' && tmparray[1] <= 'C' && tmparray[0] != tmparray[1])
			{
				*src = tmparray[0];
				*dst = tmparray[1];
				break;
			}
			if (i == 2 && tmparray[0] == 'Q')  //�Ϸ�����2:�����˸�Q
			{
				*judge_9 = tmparray[0];
				break;
			}  //�����������ԣ���������
			cct_gotoxy(60, 34);
			for (j = 0; j < i; ++j)
				cout << " ";    //�ո��������
			cct_gotoxy(60, 34);
		}
		cct_gotoxy(60, 34);
		for (j = 0; j < i; ++j)
			cout << " ";    //�ո��������
		cct_gotoxy(60, 34);
		return;
	}
	*n = input_int("�����뺺ŵ���Ĳ���(1-10)", MIN_n, MAX_n);
	*src = input_char("��������ʼ��(A-C)", '\0');
	*dst = input_char("������Ŀ����(A-C)", *src);   //12 2�� �����������bug
	if (choice == '4' || choice == '8') //����4��8�ٶ��һ������speed
	{
		*speed = input_int("�������ƶ��ٶ�(0-5��0-���س�������ʾ 1-��ʱ� 5-��ʱ���) ", MIN_speed, MAX_speed);
	}	
}
