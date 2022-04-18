/*1951393 自动化 张儒戈*/
#include <iostream>
#define size 21
using namespace std;

int main()
{
	int a[size] = { 0 };
	int cnt = 0;
	int num;//要插入的数



	cout << "请输入任意个正整数（升序，最多20个），以-1结束" << endl;
	while (cnt < size - 1) {

		cin >> a[cnt];

		if (a[cnt] <= 0) {
			break;
		}
		cnt++;
	}
	cin.ignore(1024, '\n');

	if (a[0] <= 0) {
		cout << "无有效输入" << endl;
		return 0;
	}

	cout << "原数组为：" << endl;

	for (int i = 0; i < size - 1; i++) {
		if (a[i] > 0) {
			cout << a[i] << " ";
		}
		else {
			break;
		}
	}

	cout << endl;
	cout << "请输入要插入的正整数" << endl;
	cin >> num;

	if (num < a[0]) {
		for (int i = 0; i < size - 2; i++) {
			a[i + 1] = a[i];
		}
		a[0] = num;
	}
	else {
		for (int i = size - 2; i >= 0; i--) {

			if (num > a[i] && a[i] > 0) {

				for (int j = size - 1; j > i + 1; j--) {
					a[j] = a[j - 1];
				}
				a[i + 1] = num;
				break;
			}
		}
	}


	cout << "插入后的数组为：" << endl;

	for (int i = 0; i < size; i++) {
		if (a[i] > 0) {
			cout << a[i] << " ";
		}
		else {
			break;
		}
	}
	cout << endl;

	return 0;
}
