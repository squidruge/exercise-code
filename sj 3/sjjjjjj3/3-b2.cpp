/*1951393 自动化 张儒戈*/
#include<iostream>
#include <iomanip>
#define Pi 3.14159
using namespace std;

int main()
{
	double r, h;
	
	cout << "请输入半径和高度" << endl;
	cin >> r >> h;

	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << "圆周长     : " << 2 * Pi * r << endl;
	cout << "圆面积     : " << Pi * r *r<< endl;
	cout << "圆球表面积 : " << 4 * Pi * r * r << endl;
	cout << "圆球体积   : " << 4.0/3.0 * Pi * r * r * r << endl;
	cout << "圆柱体积   : " << Pi * r * r*h << endl;
	return 0;
}
