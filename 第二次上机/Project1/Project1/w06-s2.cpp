/*1951393 �Զ��� �����*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{

	int a, n;
	int sum = 0;
	int cnt;

	cout << "������a��n��ֵ" << endl;
	cin >> a >> n;

	for (cnt = n; cnt >= 1; cnt--)
		sum += a * cnt * (int)pow(10, n - cnt);

	cout << "S=" << sum << endl;

	return 0;

}


