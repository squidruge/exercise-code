/*1951393 自动化 张儒戈*/
#include <iostream>

using namespace std;

int main()
{
	int a[10000] = { 0 };
	int n;
	int digit;
	int cnt=0;
	
	cout << "请输入数据的个数[1..10000]" << endl;
	cin >> n;
	cout << "请输入"<<n<<"个正整数" << endl;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << "请输入数码[0..9]" << endl;
	cin >> digit;

	for (int i = 0; i < n; i++) {
		while (a[i]) {

			if (a[i] % 10 == digit) {
				cnt++;
			}
			a[i] /= 10;
		}
	}

	cout << n<<"个数中含有"<<digit<<"的个数 : "<<cnt << endl;

	return 0;
}