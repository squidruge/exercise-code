/*1951393 自动化 张儒戈*/
#include <iostream>
using namespace std;


void virtual_roots(double a, double b, double c) {
	double delta = b * b - 4 * a * c;
	double real = -b / (2 * a);
	double imag = sqrt(-delta) / (2 * a);

	if (imag < 0)
		imag = -imag;

	if (-delta > 1e-6) {
		cout << "有两个虚根：" << endl;
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