/*1951393 �Զ��� �����*/
#include<iostream>
#include<iomanip>
#include<cmath>
#define Pi 3.14159f
using namespace std;

int main()
{
	int a, b, deg;
	float ans;
	cout << "�����������ε����߼���нǣ��Ƕȣ� : " << endl;
	cin >> a>>b>> deg;

	ans = 0.5f * a * b * sin(deg * Pi / 180);

	cout << setiosflags(ios::fixed)
	    	<< setprecision(3) << "���������Ϊ : " << ans << endl;

	return 0;
}



