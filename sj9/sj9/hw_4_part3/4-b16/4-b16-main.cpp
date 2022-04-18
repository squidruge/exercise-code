/*1951393 自动化 张儒戈*/
#include <iostream>
#include "4-b16.h"
using namespace std;



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