/* 1951650 ��02 ���ʽ� */
#include <iostream>
using namespace std;

/* ��2���ƴ�ת��Ϊ10������������ */
unsigned int base2to10(char* p)
{
	unsigned int num = 0;
	char* s = p;
	while (*s != '\0')
	{
		num = num * 2 + *s - '0';
		++s;
	}
	return num;
}
int main()
{
	char str[33];
	unsigned int num10 = 0;
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;	
	cin.getline(str, 33);
	num10 = base2to10(str);
	cout << num10 << endl;
	return 0;
}