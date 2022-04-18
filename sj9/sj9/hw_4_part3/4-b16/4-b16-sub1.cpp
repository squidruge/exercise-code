/*1951393 自动化 张儒戈*/
#include <iostream>
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