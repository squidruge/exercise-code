/*1951393 自动化 张儒戈*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{

	int a, n;
	int sum = 0;
	int cnt;

	cout << "请输入a和n的值" << endl;
	cin >> a >> n;

	for (cnt = n; cnt >= 1; cnt--)
		sum += a * cnt * (int)pow(10, n - cnt);

	cout << "S=" << sum << endl;

	return 0;

}


