/*1951393 �Զ��� �����*/
#include <iostream>
using namespace std;


void equal_real(double a, double b, double c) {
	if (fabs(b * b - 4 * a * c) < 1e-6) {
		cout << "���������ʵ����" << endl;

		double x;
		x = (-b) / (2 * a);

		if (fabs(x) < 1e-6) {
			x = 0.0;
		}

		cout << "x1=x2=" << x << endl;

	}
}