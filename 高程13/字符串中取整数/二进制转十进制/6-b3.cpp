/*1951393 �Զ��� �����*/
#include <iostream>
using namespace std;

#define  N  33	/* ���Ȳ�����32�ַ���+���ַ� */

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ж��Ƿ�Ϊ����
  ���������
  �� �� ֵ��
  ˵    ��������1��ʾ��
***************************************************************************/
unsigned int B2D(char*bin)
{
	unsigned int DEC = 0;

	//char* begin = bin, * end = bin;
	char* p = bin;

	while ( *p!= '\0') {
		DEC = DEC * 2 + *p-'0';
		p++;
	}

	return DEC;
}


int main()
{
	char bin[N] = { '\0' };

	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
	cin >> bin;

	cout << B2D(bin) << endl;

	return 0;
}


