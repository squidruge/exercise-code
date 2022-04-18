/*1951393 自动化 张儒戈*/
#include <iostream>

using namespace std;

double a, b, c;

bool a_is_0();

void unequal_real();

void equal_real();

void virtual_roots();

int main()
{
	
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;
	if (!a_is_0()) {
		unequal_real();
		equal_real();
		virtual_roots();
	}


	return 0;
}