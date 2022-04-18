/*1951393 自动化 张儒戈*/
#include <iostream>

using namespace std;

int min(int a = 2147483647, int b = 2147483647, int c = 2147483647,int d= 2147483647) {
	int s = (a < b) ? a : b;
	int t = (s < c) ? s : c;
	int r = (t < d) ? t : d;

	return r;

}


int main()
{
	int a, b, c, d;
	int num;

	while (1) {
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> num;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (num >= 2 && num <= 4) {
			switch (num)
			{
			case 2:

				cin >> a >> b;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (a > 0 && b > 0) {
					cout << "min=" << min(a, b) << endl;
					return 0;
				}
				break;
			case 3:

				cin >> a >> b >> c;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				if (a > 0 && b > 0 && c > 0) {
					cout << "min=" << min(a, b, c) << endl;
					return 0;
				}
				break;
			case 4:

				cin >> a >> b >> c >> d;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				if (a > 0 && b > 0 && c > 0 && d > 0) {
					cout << "min=" << min(a, b, c, d) << endl;
					return 0;
				}
				break;
			default:
				break;
			}
			//break;
		}
		else {
			cout << "个数输入错误" << endl;
			return 0;
		}

	}


	return 0;
}