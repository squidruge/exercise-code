/*1951393 �Զ��� �����*/
#include <iostream>

using namespace std;

bool a_is_0(double a);

void unequal_real(double a, double b, double c);

void equal_real(double a, double b, double c);

void virtual_roots(double a, double b, double c);

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