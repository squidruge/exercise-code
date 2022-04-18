/*1951393 �Զ��� �����*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ����������һ�����������������������ӵĺ����в������κ���ʽ��ѭ��
				 ������ų���
				 ����const�ͱ���
		������ ������ȫ�ֱ���
   ----------------------------------------------------------------------------------- */
/***************************************************************************
	�������ƣ���������ӡ��������ĳһ������ 
	��    �ܣ�
	���������order - 0 �������ӡ
			  order - 1 �������ӡ
	�� �� ֵ��
	˵    ����
  ***************************************************************************/
void print_line(char start_ch, char end_ch, int order)
{

	if (order) {
		if (end_ch - start_ch >= 0) {
			cout << end_ch;
			//cout << " ";
			print_line(start_ch, end_ch - 1, order);

		}
	}
	else {
		if (end_ch - start_ch >= 0) {
			print_line(start_ch, end_ch - 1, order);
			cout << end_ch;
		}

	}

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���������ӡ������
  ���������order - 0 ������������
			order - 1 ������������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void print_tower(char start_ch, char end_ch, int order)
{


	/* ����ʵ�֣������в������κ���ʽ��ѭ�����������徲̬�ֲ����� */
	if (order == 0) {
		if (end_ch - start_ch >= 0) {

			cout << setfill(' ') << setw(end_ch - start_ch + 1);
			print_line('A' + 1, start_ch, 1);
			cout << 'A';
			print_line('A' + 1, start_ch, 0);
			cout << endl;
			print_tower(start_ch + 1, end_ch, order);

		}

	}
	else {
		if (end_ch - start_ch >= 0) {

			print_line(start_ch , end_ch -1, 0);
			cout << end_ch;
			print_line(start_ch , end_ch -1, 1);
			cout << endl;
			
			cout << setfill(' ') << setw(start_ch-'A'+2 );
			print_tower(start_ch + 1, end_ch, order);
			//cout << " ";

		}
	}


}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч) */
	while (1) {
		cout << "����������ַ�(A~Z)" << endl;
		end_ch = getchar();			//����������һ���ַ�
		while (getchar() != '\n')	//��ջ�����ʣ���ַ�
			;
		if (end_ch >= 'A' && end_ch <= 'Z')
			break;
	}

	/* ��������ĸ��(�м�ΪA) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl;/* ����ĸ����󳤶����= */
	cout << "��������ĸ��" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl;/* ����ĸ����󳤶����= */
	print_tower('A', end_ch, 0);
	cout << endl;

	/* ��������ĸ��(����ΪA) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl; /* ����ĸ����󳤶����= */
	cout << "��������ĸ��" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl; /* ����ĸ����󳤶����= */
	print_tower('A', end_ch, 1);
	cout << endl;

	return 0;
}
