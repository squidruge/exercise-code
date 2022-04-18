/*1951393 自动化 张儒戈*/
#include<iostream>
#include<cmath>
#define Pi 3.14159
using namespace std;

int main()
{
	double x, y;
	cout << "请输入x的值" << endl;
	cin >> x;

	if (x < 15) {
		y = 2 * x - 1;
	}
	else if (x >= 15 && x < 45) {
		y = x *x - sin(x/180*Pi);
	}
	else {
		y = 3.0 * x - sqrt(x);
	}



	cout << "y=" << y<<endl;
	return 0;
}