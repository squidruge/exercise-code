/*1951393 �Զ��� �����*/
#include <iostream>
using namespace std;

bool a_is_0(double a)
{
	int flag = false;

	if (fabs(a) < 1e-6) {
		cout << "����һԪ���η���" << endl;
		flag = true;
	}
	return flag;
}