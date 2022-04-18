/*1951393 �Զ��� �����*/
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "5-b7.h"

#define ax 11
#define bx 21
#define cx 31
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�����������hanoi�ж���һ����̬�ֲ�����
   3������������������������ʼ/Ŀ�����ĺ���������������ʹ��ѭ�������������
   4����������ú������У���main�в���������κ���ʽ��ѭ����while��do-while��for��if-goto��
	  ���������main�н��У���main���������ѭ��
   --------------------------------------------------------------------- */

int topA = 0, topB = 0, topC = 0;
int A[10] = { 0 }, B[10] = { 0 }, C[10] = { 0 };
static int speed;
static bool xianshi;
int cnt = 0;

void print_shu(int a[],int top,int x,int y)//�����ӡ,���ڳ�ʼ��
{
	

	for (int i = 0; i < top; i++) {
		cct_gotoxy(x-1, y-i);
		if (i < top) {
			cout <<setw(2)<< a[i];
		}
		
		
	}

}

void speed_input()
{
	while (1) {
		cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
		cin >> speed;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');

			continue;
		}
		cin.ignore(1024, '\n');
		if (speed >=0&&speed<=5) {
			
			break;
		}
		
	}
}

void yidong(char src,char dst)
{
	
	switch (src)
	{
	case 'A':
		switch (dst)
		{
		case 'B':
			cct_gotoxy(ax-1, 11-topA);
			cout << setw(2)<< " ";
			cct_gotoxy(bx - 1, 12-topB);
			cout << setw(2)<<B[topB-1];

			break;
		case 'C':
			cct_gotoxy(ax - 1, 11-topA);
			cout << setw(2)<< " ";
			cct_gotoxy(cx - 1, 12-topC);
			cout << setw(2) << C[topC-1];
			break;
		default:
			break;
		}

		break;
	case 'B':
		switch (dst)
		{
		case 'A':
			cct_gotoxy(bx - 1, 11-topB);
			cout << "  ";
			cct_gotoxy(ax - 1, 12-topA );
			cout << setw(2) << A[topA-1];
			break;
		case 'C':
			cct_gotoxy(bx - 1, 11-topB);
			cout << "  ";
			cct_gotoxy(cx - 1, 12-topC);
			cout << setw(2) << C[topC-1];
			break;
		default:
			break;
		}
		break;
	case 'C':
		switch (dst)
		{
		case 'B':
			cct_gotoxy(cx - 1, 11-topC);
			cout << "  ";
			cct_gotoxy(bx - 1, 12-topB);
			cout << setw(2) << B[topB-1];
			break;
		case 'A':
			cct_gotoxy(cx - 1, 11-topC);
			cout << "  ";
			cct_gotoxy(ax - 1, 12-topA);
			cout << setw(2) << A[topA-1];
			break;
			break;
		default:
			break;
		}

		break;
	default:
		break;
	}
}

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


void xianshi_input()
{
	while (1) {
		cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
		cin >> xianshi;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');

			continue;
		}
		cin.ignore(1024, '\n');
		if (xianshi == 0 || xianshi ==1) {

			break;
		}

	}
}


void yidong_sz(char src,char dst)
{
	switch (src)
	{
	case 'A':
		switch (dst)
		{
		case 'B':
			B[topB++] = A[--topA];
			break;
		case 'C':
			C[topC++] = A[--topA];
			break;
		default:
			break;
		}

		break;
	case 'B':
		switch (dst)
		{
		case 'A':
			A[topA++] = B[--topB];
			break;
		case 'C':
			C[topC++] = B[--topB];
			break;
		default:
			break;
		}
		break;
	case 'C':
		switch (dst)
		{
		case 'B':
			B[topB++] = C[--topC];
			break;
		case 'A':
			A[topA++] = C[--topC];
			break;
		default:
			break;
		}

		break;
	default:
		break;
	}
}
void printline()
{
	cout << "A:";
	for (int i = 0; i < 10; i++) {
		if (i < topA) {
			cout << setw(2) << A[i];
		}
		else {
			cout << "  ";
		}
	}

	cout << " B:";
	for (int i = 0; i < 10; i++) {
		if (i < topB) {
			cout << setw(2) << B[i];
		}
		else {
			cout << "  ";
		}
	}

	cout << " C:";
	for (int i = 0; i < 10; i++) {
		if (i < topC) {
			cout << setw(2) << C[i];
		}
		else {
			cout << "  ";
		}
	}

	cout << endl;



}


void yanshi()//��ʱ
{
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
	default:
		break;
	}
	return;
}
//��ʼ��
void chushihua(char src, char dst, int n) {
	cct_cls();
	if (xianshi) {
		cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << speed << "����ʾ�ڲ�����ֵ" << endl;
	}
	else {
		cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << speed << "������ʾ�ڲ�����ֵ" << endl;
	}

	cct_gotoxy(0, 17);
	//cout << "��ʼ:" << setw(16) << " ";
	if (xianshi) {
		cout << "��ʼ:" << setw(16) << " ";
		printline();
		yanshi();
	}


	cct_gotoxy(9, 12);
	cout << "=========================";
	cct_gotoxy(11, 13);
	cout << "A         B         C" << endl;
	//int x = 11 + 10 * (ch - 'A'), y = 11;
	print_shu(A, topA, 11, 11);
	print_shu(B, topB, 21, 11);
	print_shu(C, topC, 31, 11);
	yanshi();


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
	//chushihua(src, dst, n);


	if (n == 1) {
		cct_gotoxy(0, 17);
		cout << "��" << setw(4) << ++cnt << "��(" << n << "#: " << src << "-->" << dst << ")  ";

		yidong_sz(src, dst);
		if (xianshi) {
			printline();
			yanshi();
		}
		yidong(src, dst);

		yanshi();
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		cct_gotoxy(0, 17);
		//cout << setw(5) << ++cnt << ":" << setw(3) << n << "# " << src << "-->" << dst << endl;
		cout << "��" << setw(4) << ++cnt << "��(" << n << "#: " << src << "-->" << dst << ")  ";
		yidong_sz(src, dst);

		if (xianshi) {
			printline();
			yanshi();
		}
		yidong(src, dst);

		yanshi();

		hanoi(n - 1, tmp, src, dst);
		
	}
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������(��������뺯��)�����õݹ麯��
***************************************************************************/
int main()
{
	int n;
	char src, dst, tmp = 'A';

	while (1) {
		cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
		cin >> n;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		cin.ignore(1024, '\n');
		if (n >= 1 && n <= 10) {
			break;
		}

	}

	while (1) {
		cout << "��������ʼ��(A-C)" << endl;
		cin >> src;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');

			continue;
		}
		cin.ignore(1024, '\n');
		if (src == 'A' || src == 'B' || src == 'C') {
			//cin.ignore(1024, '\n');
			break;
		}
		if (src == 'a' || src == 'b' || src == 'c') {
			src += ('A' - 'a');
			//cin.ignore(1024, '\n');
			break;
		}

	}


	while (1) {
		cout << "������Ŀ����(A-C)" << endl;
		cin >> dst;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		cin.ignore(1024, '\n');

		if (dst == 'A' || dst == 'B' || dst == 'C') {
			//cin.ignore(1024, '\n');
			if (dst == src) {
				cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
			}
			else {
				break;
			}
		}

		if (dst == 'a' || dst == 'b' || dst == 'c') {
			dst += ('A' - 'a');
			//cin.ignore(1024, '\n');
			if (dst == src) {
				cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
			}
			else {
				break;
			}
		}


	}

	while (tmp == dst || tmp == src)
		tmp++;

	switch (src)
	{
	case 'A':
		topA = n;
		for (int i = 0; i < n; i++) {
			A[i] = n - i;
		}
		break;
	case 'B':
		topB = n;
		for (int i = 0; i < n; i++) {
			B[i] = n - i;
		}
		break;
	case 'C':
		topC = n;
		for (int i = 0; i < n; i++) {
			C[i] = n - i;
		}
		break;
	default:
		break;
	}

	speed_input();
	xianshi_input();
	chushihua(src, dst, n);



	//getchar();
	
	hanoi(n, src, tmp, dst);
	//getchar();
	cct_gotoxy(0, 27);
	return 0;
}
