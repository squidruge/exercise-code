/* 1951650 ��02 ���ʽ� */
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;
	#if (__GNUC__)
		gets(str);
	#elif (_MSC_VER)
		gets_s(str, 256);
	#endif
	p = str;
	pnum = a;
	pa = a;
	while (*p != '\0' && pnum - pa < 10)
	{
		is_num = 0;
		while (*p >= '0' && *p <= '9')
		{
			*pnum = *pnum * 10 + *p - '0';
			p++;
			is_num = 1;   //���˴���ֵΪ1
		}
		if (is_num)
		{
			pnum++;
			--p;  //��ȥ�ϱߵ�++p�������ظ���
		}
		++p;
	}
	cout << "����" << pnum - pa << "������" << endl;
	for (pa = a; pa < pnum; ++pa)
	{
		cout << *pa << " ";
	}
	cout << endl;
	return 0;
}