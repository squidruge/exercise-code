/*1951393 �Զ��� �����*/
#include <iostream>
#include "4-b16.h"
using namespace std;



int main()
{
	double a, b, c;
	cout << "������һԪ���η��̵�����ϵ��a,b,c:" << endl;
	cin >> a >> b >> c;
	if (!a_is_0(a)) {
		unequal_real(a, b, c);
		equal_real(a, b, c);
		virtual_roots(a, b, c);
	}


	return 0;
}