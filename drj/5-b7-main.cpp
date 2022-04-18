/* 1951650 ��02 ���ʽ� */
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "5-b7.h"
using namespace std;

int sum = 0;
int a[10] = { 0 }, b[10] = { 0 }, c[10] = { 0 };
int ta, tb, tc;
int yanshi, xianshi;  //��ʱ���Ƿ���ʾ����

/***************************************************************************
  �������ƣ�input_n
  ��    �ܣ���ɺϷ��������
  ���������
  �� �� ֵ�����غϷ������
  ˵    ����
***************************************************************************/
int input_n()
{
	int x;  //��ŵ���Ĳ���	
	while (1)
	{
		cout << "�����뺺ŵ���Ĳ���(1-10):" << endl;
		cin >> x;   //����x�ķ�ʽ������cin>>int�ͱ���			
		cin.clear();     //�Ƿ�Ƿ�����ջ�����
		cin.ignore(1024, '\n');
		if (cin.fail())
		{
			continue;   //����Ƿ��Ļ����������룬���ٽ����ж������Ƿ����
		}
		if (x >= 1 && x <= 10)
			break;
	}
	return x;
}

/***************************************************************************
  �������ƣ�input_src
  ��    �ܣ���ɺϷ�������ʼ��
  ���������
  �� �� ֵ�����غϷ������
  ˵    ����
***************************************************************************/
char input_src()
{
	char src = '1';
	while (1)
	{
		cout << "��������ʼ��(A-C):" << endl;
		cin >> src;
		cin.clear();     //�Ƿ�Ƿ�����ջ�����
		cin.ignore(1024, '\n');
		if (cin.fail())
		{
			continue;   //����Ƿ��Ļ����������룬���ٽ����ж������Ƿ����
		}
		if (src >= 'A' && src <= 'C')
		{
			break;
		}
		if (src >= 'a' && src <= 'c')
		{
			src = src - 32;   //Сдת��д
			break;
		}
	}
	return src;
}

/***************************************************************************
  �������ƣ�input_dst
  ��    �ܣ���ɺϷ�����Ŀ����
  ���������������ʼ���ĺ�
  �� �� ֵ�����غϷ������
  ˵    ����
***************************************************************************/
char input_dst(char src)
{
	char dst = '1';
	while (1)
	{
		cout << "������Ŀ����(A-C):" << endl;
		cin >> dst;
		cin.clear();     //�Ƿ�Ƿ�����ջ�����
		cin.ignore(1024, '\n');
		if (cin.fail())
		{
			continue;   //����Ƿ��Ļ����������룬���ٽ����ж������Ƿ����
		}

		if (dst >= 'A' && dst <= 'C')
		{
			if (dst == src)  //Ŀ��������ʼ����ͬ��������
			{
				cout << "Ŀ����(" << dst << ")��������ʼ��(" << dst << ")��ͬ" << endl;
				continue;
			}
			else
			{
				break;
			}
		}
		if (dst >= 'a' && dst <= 'c')
		{
			dst = dst - 32;  //ת��д
			if (dst == src)  //Ŀ��������ʼ����ͬ��������
			{
				cout << "Ŀ����(" << dst << ")��������ʼ��(" << dst << ")��ͬ" << endl;
				continue;
			}
			else
			{
				break;
			}
		}
	}
	return dst;
}

/* ����Ϸ�����ʱѡ�� */
void choice_yanshi()
{
	yanshi = -1;
	while (1)
	{
		cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
		cin >> yanshi;   
		if (cin.fail())
		{			
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (yanshi >= 0 && yanshi <= 5)
			break;
	}
	return;
}
/* ����Ϸ�����ʾѡ�� */
void choice_xianshi()
{
	xianshi = -1;
	while (1)
	{
		cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ))" << endl;
		cin >> xianshi;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (xianshi >= 0 && xianshi <= 1)
			break;
	}
	return;
}

/* ֱ������enter������ */
void is_enter()
{
	char ch;
	ch = _getch();
	while (ch != 13)
	{
		ch = _getch();
	}
	return;
}

/* ��¼ջ��λ�� */
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

/* ����������鲿�֣���ɶ�ָ�������������� */
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

void output_szline(int a[], int n, int x, int y) //����������飬�������Ϊ�������Լ���ʼ��xy�����
{
	int i = 0;	
	for (i = 0; i < n; ++i)
	{
		cct_gotoxy(x, y-i);
		cout << a[i];
	}	
	return;
}
void output_space(int n, int x, int y)  //���Ŵ�ӡn���ո����ھֲ�����������������Ϊ��ʼxy�����
{
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		cct_gotoxy(x, y - i);
		cout << " ";
	}
	return;
}

void input_sz(int a[], int n)  //�����鸳ֵ
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
	if (src == 'A')
	{
		input_sz(a, n);
	}
	if (src == 'B')
	{
		input_sz(b, n);
	}
	if (src == 'C')
	{
		input_sz(c, n);
	}     //������ʼ������ֵ
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
  ���������int n������
			char src����ʼ��
			char tmp���м���
			char dst��Ŀ����
  �� �� ֵ��
  ˵    ����1�����������βΡ��������;���׼��
			2������������������κ���ʽ��ѭ��
			3��������һ����̬�ֲ�����
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	int i = 0;
	if (sum == 0 && n == 1)  //ֻ�е�û�����ִ�е����һ���ʱ������һ��
	{	
		if (xianshi == 1)
		{
			cct_gotoxy(0, 17);
			cout << "��ʼ:" << setw(16) << " ";
			cout << "A:";
			output_sz(a, ta);
			cout << "B:";
			output_sz(b, tb);
			cout << "C:";
			output_sz(c, tc);   //��ӡ��һ��
		}
		if (yanshi == 0 && xianshi == 1)
		{
			is_enter();
		}
		cct_gotoxy(9, 12);  //��ӡ��������
		cout << "=========================" << endl;
		cct_gotoxy(11, 13);
		cout << "A         B         C" << endl;
		
		output_szline(a, ta, 11, 11);
		output_szline(b, tb, 21, 11);
		output_szline(c, tc, 31, 11);
	}

	if (n == 1)
	{		
		if (src == 'A')
		{
			a[--ta] = 0;
		}
		if (src == 'B')
		{
			b[--tb] = 0;
		}
		if (src == 'C')
		{
			c[--tc] = 0;
		}
		if (dst == 'A')
		{
			a[ta++] = 1;
		}
		if (dst == 'B')
		{
			b[tb++] = 1;
		}
		if (dst == 'C')
		{
			c[tc++] = 1;
		}

		//�����ӳ�ʱ��
		switch (yanshi)
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
		cct_gotoxy(0, 17);
		cout << "��" << setw(4) << ++sum << "��(" << 1 << "#: " << src << "-->" << dst << ")  ";
		if (xianshi == 1)
		{
			cout << "A:";
			output_sz(a, ta);  //�����ջ��
			cout << "B:";
			output_sz(b, tb);
			cout << "C:";
			output_sz(c, tc);
		}
		//cout << endl;
		if (xianshi == 1 && yanshi == 0)
		{
			is_enter();
		}
		output_space(10, 11, 11);				
		output_space(10, 21, 11);			
		output_space(10, 31, 11);
		output_szline(a, ta, 11, 11);
		output_szline(b, tb, 21, 11);
		output_szline(c, tc, 31, 11);		
	}
	else
	{
		hanoi(n - 1, src, dst, tmp);
		if (src == 'A')
		{
			a[--ta] = 0;
		}
		if (src == 'B')
		{
			b[--tb] = 0;
		}
		if (src == 'C')
		{
			c[--tc] = 0;
		}
		if (dst == 'A')
		{
			a[ta++] = n;
		}
		if (dst == 'B')
		{
			b[tb++] = n;
		}
		if (dst == 'C')
		{
			c[tc++] = n;
		}

		//�����ӳ�ʱ��
		switch (yanshi)
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
		cct_gotoxy(0, 17);
		cout << "��" << setw(4) << ++sum <<  "��(" << n << "#: " << src << "-->" << dst << ")  ";
		if (xianshi == 1)
		{
			cout << "A:";
			output_sz(a, ta);  //�����ջ��
			cout << "B:";
			output_sz(b, tb);
			cout << "C:";
			output_sz(c, tc);
		}

		if (xianshi == 1 && yanshi == 0)
		{
			is_enter();
		}

		output_space(10, 11, 11);
		output_space(10, 21, 11);
		output_space(10, 31, 11);
		output_szline(a, ta, 11, 11);
		output_szline(b, tb, 21, 11);
		output_szline(c, tc, 31, 11);

		hanoi(n - 1, tmp, src, dst);
	}
}

int main()
{
	int n = input_n();
	char src = input_src();
	char dst = input_dst(src);
	char tmp = 198 - src - dst;
	choice_yanshi();
	choice_xianshi();   //������ɺϷ������ʼ������

	tianchongsz(src, n);  //����������Ӧ������

	ta = top(a, n);      //��¼ջ��λ��
	tb = top(b, n);
	tc = top(c, n);
	cct_cls();

	cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << yanshi << "��";
	if (!xianshi)
	{
		cout << "��";
	}
	cout << "��ʾ�ڲ�����ֵ" << endl;  //�����һ��

	hanoi(n, src, tmp, dst);
	cct_gotoxy(0, 27);
	return 0;
}