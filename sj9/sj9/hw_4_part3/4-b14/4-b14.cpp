/*1951393 自动化 张儒戈*/
#include <iostream>
#include <cmath>
using namespace std;

bool a_is_0(double a)
{
	int flag = false;

	if (fabs(a) < 1e-6) {
		cout << "不是一元二次方程" << endl;
		flag = true;
	}
	return flag;
}

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

		if (x1>x2) {
			cout << "x1=" << x1 << endl;
			cout << "x2=" << x2 << endl;
		}
		else {
			cout << "x1=" << x2 << endl;
			cout << "x2=" << x1<< endl;
		}

	}
}

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
				cout << "x1=" <<real<<"+i"<< endl;
				cout << "x2=" << real << "-i" << endl;
			}
			else {
				cout << "x1=" << real << "+" << imag << "i" << endl;
				cout << "x2=" << real << "-" << imag << "i" << endl;
			}
		}


	}
}

int main()
{
	double a, b, c;
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;
	if (!a_is_0(a)) {
		unequal_real(a, b, c);
		equal_real(a, b, c);
		virtual_roots(a, b, c);
	}


	return 0;
}