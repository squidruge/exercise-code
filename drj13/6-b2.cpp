/* 1951650 ��02 ���ʽ� */
#include <iostream>
using namespace std;

/* �ж��ǲ��ǻ��Ĵ��������yes�������no */
void judge(char* p)
{
	char* pstr, * s, * e;   
	int n = 0;    //��¼�ַ��ĸ���
	pstr = p;
	while (*pstr != '\n')
	{
		pstr++;
	}
	*pstr = '\0';   //���س��滻Ϊβ��
	n = pstr - p;   //ͳ���ַ��ĸ���

	s = p;     //ָ��ͷbegin�ͽ�βend������ָ��
	e = p + n - 1;
	while (s <= e)
	{
		if (*s != *e)
		{
			break;
		}
		s++;
		e--;
	}
	if (s <= e)  //��ʱ˵���������˲��ȵ���������no
	{
		cout << "no" << endl;
	}
	else
	{
		cout << "yes" << endl;
	}
	return;
}

int main()
{
	char str[81];
	cout << "������һ������С��80���ַ��������Ĵ���" << endl;
	fgets(str, 81, stdin);
	judge(str);
	return 0;
}