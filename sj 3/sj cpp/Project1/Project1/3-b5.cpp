/*1951393 自动化 张儒戈*/
#include<iostream>
#include<iomanip>
#include<cmath>
#define Pi 3.14159f
using namespace std;

int main()
{
	int a, b, deg;
	float ans;
	cout << "请输入三角形的两边及其夹角（角度） : " << endl;
	cin >> a>>b>> deg;

	ans = 0.5f * a * b * sin(deg * Pi / 180);

	cout << setiosflags(ios::fixed)
	    	<< setprecision(3) << "三角形面积为 : " << ans << endl;

	return 0;
}



