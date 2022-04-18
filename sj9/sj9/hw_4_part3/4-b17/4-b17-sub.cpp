/*1951393 �Զ��� �����*/
#include <iostream>
#include <cmath>
using namespace std;

extern double a, b, c;

bool a_is_0()
{
	int flag = false;

	if (fabs(a) < 1e-6) {
		cout << "����һԪ���η���" << endl;
		flag = true;
	}
	return flag;
}

void unequal_real() {
	if (b * b - 4 * a * c >= 1e-6) {
		cout << "����������ʵ����" << endl;
		double x1, x2;
		x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

		if (fabs(x1) < 1e-6) {
			x1 = 0.0;
		}
		if (fabs(x2) < 1e-6) {
			x2 = 0.0;
		}

		if (x1 > x2) {
			cout << "x1=" << x1 << endl;
			cout << "x2=" << x2 << endl;
		}
		else {
			cout << "x1=" << x2 << endl;
			cout << "x2=" << x1 << endl;
		}

	}
}

void equal_real() {
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

void virtual_roots() {
	double delta = b * b - 4 * a * c;
	double real = -b / (2 * a);
	double imag = sqrt(-delta) / (2 * a);

	if (imag < 0)
		imag = -imag;

	if (-delta > 1e-6) {
		cout << "�����������" << endl;
		//if(abs(b / 2))
		if (fabs(delta) < 1e-6) {
			if (fabs(imag - 1) < 1e-6) {
				cout << "x1=i" << endl;
				cout << "x2=-i" << endl;
			}
			else {
				cout << "x1=" << imag << "i" << endl;
				cout << "x2=-" << imag << "i" << endl;
			}

		}
		else {
			if (fabs(imag - 1) < 1e-6) {
				cout << "x1=" << real << "+i" << endl;
				cout << "x2=" << real << "-i" << endl;
			}
			else {
				cout << "x1=" << real << "+" << imag << "i" << endl;
				cout << "x2=" << real << "-" << imag << "i" << endl;
			}
		}


	}
}