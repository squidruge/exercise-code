/*1951393 �Զ��� �����*/
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

	gets_s(str, 256);

	p = str;
	pa = a;
	pnum = a;
	is_num = 0;

	while ((pnum - a) < N) {

		if (*p >= '0' && *p <= '9') {
			is_num = 1;
			*pnum = (*pnum) * 10 + *p - '0';
			//*pnum = *p;
		}
		else {
			if (is_num) {
				//ǰһ�������� ��һ���������� ��pnum++
				pnum++;
				if (*p == '\0') {
					break;
				}
			}

			is_num = 0;
		}
		p++;

	}

	cout << "����" << pnum - a << "������" << endl;

	while (1)
	{
		cout << *pa++;
		if (pa == pnum ) {
			cout << endl;
			break;
		}
		else {
			cout << " ";
		}
	}

	return 0;
}
