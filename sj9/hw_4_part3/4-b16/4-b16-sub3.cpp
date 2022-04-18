/*1951393 自动化 张儒戈*/
#include <iostream>
using namespace std;


void equal_real(double a, double b, double c) {
	if (fabs(b * b - 4 * a * c) < 1e-6) {
		cout << "有两个相等实根：" << endl;

		double x;
		x = (-b) / (2 * a);

		if (fabs(x) < 1e-6) {
			x = 0.0;
		}

		cout << "x1=x2=" << x << endl;

	}
}