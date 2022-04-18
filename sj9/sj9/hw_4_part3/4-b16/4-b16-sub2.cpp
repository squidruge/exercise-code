/*1951393 自动化 张儒戈*/
#include <iostream>
using namespace std;


void unequal_real(double a, double b, double c) {
	if (b * b - 4 * a * c >= 1e-6) {
		cout << "有两个不等实根：" << endl;
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