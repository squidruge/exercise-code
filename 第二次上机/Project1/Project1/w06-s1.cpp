/*1951393 �Զ��� �����*/
#include<iostream>
#include<cmath>
#define Pi 3.14159
using namespace std;

int main()
{
	double x, y;
	cout << "������x��ֵ" << endl;
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