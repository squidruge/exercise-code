/*1951393 �Զ��� �����*/


/* ----------------------------------------------------------------------------------

	 ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

	 ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
#define ax 11 //������������
#define bx 21
#define cx 31
#define plate_Ax 1		//��һ�������������
#define colum_Ax 12		//��һ������
#define PlateLength 23	//�̵׿��
#define dizuo_y_mode8 27  //mode8 �������ĵ���
#define dizuo_y_mode4 12  //mode4 �������ĵ���
#define plate_chazhi (PlateLength+9) //������Ĳ�ֵ
#define plate_y 15	//�̵�

using namespace std;

static int cnt; //���ƶ�����
static int delay;//��ʱ����

static int top[3] = { 0 }; //Բ��������Բ�̵����� top[i] ����Ϊ A B C
static int plate[3][10] = { 0 };//Բ��������Բ�̵� �б��ʾ��

const int x[3] = { ax,bx,cx };//������������x���꣬��װ�����鷽��ʹ��
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
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst, char mode)
{
	if (n == 1) {
		hanoi_step(n, src, tmp, dst, mode);
	}
	else {
		hanoi(n - 1, src, dst, tmp, mode);
		hanoi_step(n, src, tmp, dst, mode);
		hanoi(n - 1, tmp, src, dst, mode);
	}
}
/***************************************************************************
  �������ƣ�hanoi_step
  ��    �ܣ���ͬģʽ��Ӧ��ŵ��ÿ��Ҫ��ɵ�����
  ���������int n������
			char src����ʼ��
			char tmp���м���
			char dst��Ŀ����
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void hanoi_step(int n, char src, char tmp, char dst, char mode)
{
	if (mode == '1') {
		cout << n << "# " << src << "---->" << dst << endl;
	}
	if (mode == '2') {
		cout << "��" << setw(4) << ++cnt << " ��(" << setw(2) << n << "#: " << src << "-->" << dst << ")" << endl;
	}
	if (mode == '3') {
		yidong_sz(src, dst);//�ƶ������е����ӱ��
		printline(n, src, dst, mode);//�����ӡ
	}
	if (mode == '4') {

		yidong_sz(src, dst);//�ƶ������е����ӱ��

		printline(n, src, dst, mode);//�����ӡ
		printshu(src, dst, mode);//�������

		yanshi();

	}
	if (mode == '8' || mode == '9') {

		yidong_sz(src, dst);//�ƶ������е����ӱ��

		printline(n, src, dst, mode);//�����ӡ

		cct_setcursor(CURSOR_INVISIBLE);
		printshu(src, dst, mode);//�������

		move_once(n, src, tmp, dst);
		yanshi();
	}

}

/***************************************************************************
  �������ƣ�input
  ��    �ܣ����벿��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void input(char* psrc, char* pdst, char* ptmp, int* pn, char mode)
{
	cout << endl << endl << endl;
	int n;
	char src, dst, tmp = 'A';

	while (1) {
		cout << "�����뺺ŵ���Ĳ���(1-10)��" << endl;
		cin >> n;
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
		cout << "��������ʼ��(A-C)��" << endl;
		cin >> src;
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
		cout << "������Ŀ����(A-C)��" << endl;
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

			if (dst == src) {
				cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
			}
			else {
				break;
			}
		}
	}
	tmp = 'A' + 'B' + 'C' - dst - src;

	*pn = n;
	*psrc = src;
	*pdst = dst;
	*ptmp = tmp;

	if (mode == '4' || mode == '8') {
		delay_input();
	}
}
/***************************************************************************
  �������ƣ�modeXX
  ��    �ܣ�����ģʽ��Ӧ�ĺ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void mode123(char mode, int n, char src, char dst, char tmp)
{
	Plate_Init(src, n);
	hanoi(n, src, tmp, dst, mode);
	cout << endl;
}

void mode4(int n, char src, char dst, char tmp)
{
	cct_setcursor(CURSOR_INVISIBLE);

	Plate_Init(src, n);
	chushihua(src, dst, n, '4');

	hanoi(n, src, tmp, dst, '4');

	cct_gotoxy(0, 38);   //ת���·���ӡ������ʾ
}

void mode5()
{
	cct_setcursor(CURSOR_INVISIBLE);   //�رչ����ʾ
	cct_cls();
	cnt = 0;
	draw_column();

	cct_setcolor(); //�ָ�ȱʡ��ɫ;
	cct_gotoxy(0, 38);   //ת���·���ӡ������ʾ
}

void mode6(int n, char src, char dst, char tmp)
{
	cct_setcursor(CURSOR_INVISIBLE);   //�رչ����ʾ
	cct_cls();

	cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��" << endl;
	draw_column();
	draw_plate(src, n);

	cct_setcolor(); //�ָ�ȱʡ��ɫ;
	cct_gotoxy(0, 38);  //�ص�����ȥ��ӡ������ʾ
}

void mode7(int n, char src, char dst, char tmp)
{
	delay = 4;

	Plate_Init(src, n);

	cct_setcursor(CURSOR_INVISIBLE);   //�رչ����ʾ
	cct_cls();

	cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��" << endl;
	draw_column();
	draw_plate(src, n);
	Sleep(1000);

	if (n % 2)
	{
		yidong_sz(src, dst);
		move_once(1, src, tmp, dst);  //����->Ŀ����
	}
	else
	{
		yidong_sz(src, tmp);
		move_once(1, src, dst, tmp);    //ż��->��ת��
	}
	cct_gotoxy(0, 38);   //ת���·���ӡ������ʾ
}
void mode8(int n, char src, char dst, char tmp)
{
	Plate_Init(src, n);

	chushihua(src, dst, n, '8');

	cct_setcursor(CURSOR_INVISIBLE);   //�رչ����ʾ

	draw_column();

	draw_plate(src, n);
	Sleep(1000);
	yanshi();
	hanoi(n, src, tmp, dst, '8');

	cct_gotoxy(0, 38);   //ת���·���ӡ������ʾ
}


void mode9(int n, char src, char dst, char tmp)
{

	char src_cur = 'A', dst_cur = 'A';//��ǰҪ�ƶ��� src �� dst

	delay = 5;

	Plate_Init(src, n);

	chushihua(src, dst, n, '9');//ʹ��9�ĳ�ʼ������

	cct_setcursor(CURSOR_INVISIBLE);   //�رչ����ʾ

	draw_column();
	draw_plate(src, n);

	int i = 0;
	char ch;

	while (1)
	{
		cct_setcolor(); //�ָ�ȱʡ��ɫ;
		cct_gotoxy(0, 34);
		cct_setcursor(CURSOR_VISIBLE_NORMAL);  //�����ʾ����
		cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��";
		cct_gotoxy(60, 34);

		cct_setcursor(CURSOR_VISIBLE_NORMAL);
		//����20���Զ����
		for (i = 0; i < 20; i++) {

			ch = getch_mode9();

			if (i == 0)
				src_cur = ch;

			if (i == 1)
				dst_cur = ch;

			if (ch == 13)
				break;

		}

		if (judge(n, i, src_cur, dst_cur))
			break;

		if (top[dst - 'A'] == n) {

			cct_setcolor(); //�ָ�ȱʡ��ɫ;
			cct_gotoxy(0, 35);
			cout << "��Ϸ����!!!!!" << endl;
			break;
		}

	}
	cct_gotoxy(0, 38);   //ת���·���ӡ������ʾ
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ������ӡ,���ڳ�ʼ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void print_shu(int a[], int top, int x, int y)
{

	cct_setcolor();
	for (int i = 0; i < top; i++) {
		cct_gotoxy(x - 1, y - i);
		if (i < top) {
			cout << setw(2) << a[i];
		}
	}

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�������ʱ����
  ���������
  �� �� ֵ��
  ˵    ����mode4 mode8
***************************************************************************/
void delay_input()
{
	while (1) {
		cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���) " ;
		cin >> delay;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');

			continue;
		}
		cin.ignore(1024, '\n');
		if (delay >= 0 && delay <= 5) {

			break;
		}

	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ƶ����������������ͼ��
  ���������
  �� �� ֵ��
  ˵    ����mode4 mode8
***************************************************************************/
void printshu(char src, char dst, char mode)
{
	cct_setcolor();
	int y = dizuo_y_mode8 - 1;

	if (mode == '4') {
		y = dizuo_y_mode4 - 1;
	}

	if (mode == '8') {
		y = dizuo_y_mode8 - 1;
	}
	 
	cct_gotoxy(x[src - 'A'] - 1, y - top[src - 'A']);
	cout << setw(2) << " ";
	cct_gotoxy(x[dst - 'A'] - 1, y + 1 - top[dst - 'A']);
	cout << setw(2) << plate[dst - 'A'][top[dst - 'A'] - 1];

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ȴ���ȡenter
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
  ��    �ܣ��ƶ������ڵ�����
  ���������
  �� �� ֵ��
  ˵    ������Ȼֻ��һ�䣬��װ��������ʹ��
***************************************************************************/
void yidong_sz(char src, char dst)
{

	plate[dst - 'A'][top[dst - 'A']++] = plate[src - 'A'][--top[src - 'A']];

}
/***************************************************************************
  �������ƣ�
  ��    �ܣ������ӡ���� 3 4 8 9
  ���������
  �� �� ֵ��
  ˵    ����mode3 mode4 mode8 mode9
***************************************************************************/
void printline(int n, char src, char dst, char mode)
{

	if (mode != 'I') {
		if (mode == '4') {
			cct_gotoxy(0, 17);
		}
		if (mode == '8' || mode == '9') {
			cct_setcolor();
			cct_gotoxy(0, 32);
		}
		cout << "��" << setw(4) << ++cnt << "��(" << setw(2) << n << "#: " << src << "-->" << dst << ")  ";
	}

	cout << "A:";
	for (int i = 0; i < 10; i++) {
		if (i < top[0]) {
			cout << setw(2) << plate[0][i];
		}
		else {
			cout << "  ";
		}
	}

	cout << " B:";
	for (int i = 0; i < 10; i++) {
		if (i < top[1]) {
			cout << setw(2) << plate[1][i];
		}
		else {
			cout << "  ";
		}
	}

	cout << " C:";
	for (int i = 0; i < 10; i++) {
		if (i < top[2]) {
			cout << setw(2) << plate[2][i];
		}
		else {
			cout << "  ";
		}
	}

	cout << endl;

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�mode4 mode8 ��Ӧ����ʱ������mode8�����ƶ����ٶ�
  ���������
  �� �� ֵ��
  ˵    ���� mode4
***************************************************************************/
void yanshi()
{
	switch (delay)
	{
	case 5:
		break;
	case 4:
		Sleep(30);
		break;
	case 3:
		Sleep(150);
		break;
	case 2:
		Sleep(300);
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

/***************************************************************************
  �������ƣ�
  ��    �ܣ�mode8��Ӧ�ƶ����̵���ʱ
  ���������
  �� �� ֵ��
  ˵    ���� mode8
***************************************************************************/
void yanshi_move()
{
	switch (delay)
	{
	case 5:
		break;
	case 4:
		Sleep(30);
		break;
	case 3:
		Sleep(100);
		break;
	case 2:
		Sleep(300);
		break;
	case 1:
		Sleep(600);
		break;
	case 0:
		Sleep(30);
		break;
	}
}

/***************************************************************************
  �������ƣ�chushihua
  ��    �ܣ� ���������ӡ��ʼ������
  ���������
  �� �� ֵ��
  ˵    �������� mode4 mode8 mode9
***************************************************************************/
void chushihua(char src, char dst, int n, char mode)
{
	cct_cls();
	cct_setcolor();
	int y = dizuo_y_mode8 - 1;

	if (mode == '4') {
		y = dizuo_y_mode4 - 1;
	}
	if (mode == '8'|| mode == '9') {
		y = dizuo_y_mode8 - 1;
	}

	if (mode == '4' || mode == '8') {
		cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << delay << endl;
	}
	else if(mode == '9') {
		cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��" << endl;
	}
	

	cct_gotoxy(0, y + 6);


	cout << "��ʼ:" << "  ";
	printline(n, src, dst, 'I'); //I��ʾmodeΪ��ʼ��init
	//yanshi();

	cct_gotoxy(9, y + 1);
	cout << "=========================";
	cct_gotoxy(11, y + 2);
	cout << "A         B         C" << endl;

	print_shu(plate[0], top[0], 11, y);
	print_shu(plate[1], top[1], 21, y);
	print_shu(plate[2], top[2], 31, y);

	if (mode == '4') {
		yanshi();
	}
}

/***************************************************************************
  �������ƣ�Plate_Init
  ��    �ܣ� ����ʼ����������n�����֣�����ʼ���� topΪ ���һ��Ԫ�ص���һ��λ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void Plate_Init(char src, int n)
{
	top[src-'A'] = n;
	for (int i = 0; i < n; i++) {
		plate[src-'A'][i] = n - i;
	}

}

/***************************************************************************
  �������ƣ�draw_column
  ��    �ܣ� ����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void draw_column()
{
	const int len = 23;//��������
	for (int i = 0; i < 3; i++) {

		cct_showch(plate_Ax + i * plate_chazhi, plate_y, ' ', COLOR_HYELLOW, COLOR_WHITE, len);
	}
	for (int j = 1; j <= 12; j++) {
		for (int i = 0; i < 3; i++) {
			cct_showch(colum_Ax + i * plate_chazhi, plate_y - j, ' ', COLOR_HYELLOW);
			Sleep(50);
		}
	}
}

/***************************************************************************
  �������ƣ�draw_plate
  ��    �ܣ� ����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void draw_plate(char src, int n)
{

	for (int j = 1; j <= n; j++) {

		cct_showch(colum_Ax + (src - 'A') * plate_chazhi - (n - j + 1), plate_y - j, ' ', n - j + 1, 7, 2 * (n - j + 1) + 1);
		Sleep(50);
	}
}

/***************************************************************************
  �������ƣ�move_once
  ��    �ܣ� �ƶ�һ��
  ���������
  �� �� ֵ��
  ˵    ������ʱ�����Ѿ��ƶ����
***************************************************************************/
void move_once(int n, char src, char tmp, char dst)
{
	cct_setcursor(CURSOR_INVISIBLE);  //�رչ����ʾ
	move_up(n, src, dst);
	move_lr(n, src, dst);
	move_down(n, dst);
}
/***************************************************************************
  �������ƣ�move_lr
  ��    �ܣ� �����ƶ�����srcͷ���ƶ���dstͷ��
  ���������int n, char src, char dst, int delay
  �� �� ֵ��
  ˵    ������ʱ�����Ѿ��ƶ����
***************************************************************************/
void move_lr(int n, char src, char dst)
{
	int x, y, x_src, x_dst, len;

	y = 1;

	x_src = colum_Ax + (src - 'A') * plate_chazhi - n;  //src����ߵ�x 
	x_dst = colum_Ax + (dst - 'A') * plate_chazhi - n;  //dst����ߵ�x 
	len = 2 * n + 1;

	if (x_src < x_dst) {
		for (x = x_src; x <= x_dst; x++) {
			cct_showch(x, y, ' ', n, 7, len);
			yanshi_move();

			cct_showch(x, y, ' ', 0, 7, len);
			if (delay != 5) {
				Sleep(30);
			}
		}
	}
	else {
		for (x = x_src; x >= x_dst; x--) {
			cct_showch(x, y, ' ', n, 7, len);

			yanshi_move();

			cct_showch(x, y, ' ', 0, 7, len);
			if (delay != 5) {
				Sleep(30);
			}
		}
	}
}

/***************************************************************************
  �������ƣ�move_up
  ��    �ܣ�����
  ���������int n ������  char src, char dst,
  �� �� ֵ��
  ˵    ������ʱ�����Ѿ��ƶ����
***************************************************************************/
void move_up(int n, char src, char dst)
{
	int x, y, len;
	y = 15 - top[src - 'A'] - 1;//ԭ���е�λ��

	int plate_xuhao;
	plate_xuhao = plate[dst - 'A'][top[dst - 'A'] - 1];//����ƶ����̵�������

	x = colum_Ax + (src - 'A') * plate_chazhi - plate_xuhao;  //src����ߵ�x 

	len = 2 * plate_xuhao + 1;



	for (; y >= 1; y--) {
		cct_showch(x, y, ' ', plate_xuhao, 7, len);
		yanshi_move();

		cct_showch(x, y, ' ', 0, 7, len);
		if (y >= 3 && y <= 14) {
			cct_showch(colum_Ax + (src - 'A') * plate_chazhi, y, ' ', 14);
		}
		if (delay != 5) {
			Sleep(30);
		}
	}

}

/***************************************************************************
  �������ƣ�move_down
  ��    �ܣ�����
  ���������int n �̱�� �뺺ŵ���ݹ麯������һ��   char dst, int delay
  �� �� ֵ��
  ˵    ������ʱ�����Ѿ��ƶ����
***************************************************************************/
void move_down(int n, char dst)
{
	int x, y, len;

	y = 1;
	int plate_xuhao;
	plate_xuhao = plate[dst - 'A'][top[dst - 'A'] - 1];

	x = colum_Ax + (dst - 'A') * plate_chazhi - plate_xuhao;  //src����ߵ�x 

	len = 2 * plate_xuhao + 1;


	for (; y <= 15 - top[dst - 'A']; y++) {

		cct_showch(x, y, ' ', plate_xuhao, 7, len);
		yanshi_move();
		//Sleep(100);


		if (y != 15 - top[dst - 'A']) {
			cct_showch(x, y, ' ', 0, 7, len);
			if (y >= 3 && y <= 14) {
				cct_showch(colum_Ax + (dst - 'A') * plate_chazhi, y, ' ', 14);
			}
		}

		if (delay != 5) {
			Sleep(30);
		}

	}

}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�mode9 �õ������ַ��ĺ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char getch_mode9()
{

	unsigned char ch;

	while (1)
	{
		ch = _getch();

		if (ch == 13)
		{
			return ch;
		}

		if (ch == 224)  //ȥ�����������
		{
			ch = _getch();
			continue;
		}

		if (ch >= 33 && ch <= 126)
		{
			cout << ch;
			if (ch >= 'a' && ch <= 'z')  //Сдת��д
			{
				ch += 'A' - 'a';
			}
			return ch;
		}

	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�mode9 �ж�������ַ���ִ�к���
  ���������
  �� �� ֵ��1��ʾ������Q Ҫ�˳�ѭ��
  ˵    ����
***************************************************************************/
int judge(int n, int i, char src_cur, char dst_cur)
{
	int flag = 0;//1 ��ʾ����
	int src_cur_bianhao, dst_cur_bianhao;//��ǰ ��ʼ �� Ŀ�� ���Ϸ����̱��
	src_cur_bianhao = plate[src_cur - 'A'][top[src_cur - 'A'] - 1];
	dst_cur_bianhao = plate[dst_cur - 'A'][top[dst_cur - 'A'] - 1];

	if (i == 1) {

		if (src_cur == 'Q' || src_cur == 'q') {
			cct_gotoxy(0, 35);
			cout << "��Ϸ��ֹ!!!!!" << endl;
			flag = 1;
		}
		else {
			cct_showch(60, 34, ' ', 0, 7, 25);//����ַ�

		}
	}
	else if (i == 2 && src_cur >= 'A' &&
		src_cur <= 'C' && dst_cur >= 'A' &&
		dst_cur <= 'C' && src_cur != dst_cur) {

		//ֻ���������ַ�������ABC��

		cct_gotoxy(0, 35);
		if (top[src_cur - 'A'] == 0) {
			cout << "Դ��Ϊ��!" << endl;
			Sleep(1500);
			cct_showch(60, 34, ' ', 0, 7, 25);//����ַ�
			cct_showch(0, 35, ' ', 0, 7, 25);//���������ʾ
		}
		else if ((src_cur_bianhao > dst_cur_bianhao) && top[dst_cur - 'A'] != 0) {
			cout << "����ѹС�̣��Ƿ��ƶ�!" << endl;
			Sleep(1500);
			cct_showch(60, 34, ' ', 0, 7, 25);//����ַ�
			cct_showch(0, 35, ' ', 0, 7, 25);//���������ʾ
		}
		else {

			cct_showch(60, 34, ' ', 0, 7, 25);//����ַ�
			hanoi_step(src_cur_bianhao, src_cur, 'A' + 'B' + 'C' - src_cur - dst_cur, dst_cur, '9');

		}
	}
	else {

		cct_showch(60, 34, ' ', 0, 7, 25);//����ַ�
	}

	return flag;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����ѡ����ò˵������Ӧ��ִ�к���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void ChooseMode(char mode, int n, char src, char dst, char tmp)
{
	Global_Init();

	switch (mode)
	{
	case '1':
	case '2':
	case '3':
		mode123(mode, n, src, dst, tmp);
		break;
	case '4':
		mode4(n, src, dst, tmp);
		break;
	case '5':
		mode5();
		break;
	case '6':
		mode6(n, src, dst, tmp);
		break;
	case '7':
		mode7(n, src, dst, tmp);
		break;
	case '8':
		mode8(n, src, dst, tmp);
		break;
	case '9':
		mode9(n, src, dst, tmp);
		break;
	default:
		break;
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ȫ�ֱ��������ʼ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void Global_Init()
{
	cnt = 0;

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {
			plate[i][j] = 0;
		}
		top[i] = 0;
	}
}