/*1951393 自动化 张儒戈*/
#include <iostream>
using namespace std;


//判断每一行有没有重复
bool hang(int a[9][9]) {
	
	for (int i = 0; i < 9; i++) {

		int cnt[9] = { 0 };//记录1~9出现过几次
		for (int j = 0; j < 9; j++) {
			cnt[a[i][j] - 1]++;
		}
		for (int j = 0; j < 9; j++) {
			if (cnt[j] > 1) {
				return false;
			}
		}
	}
	return true;
}
//判断每一列有没有重复
bool lie(int a[9][9]) {
	
	for (int i = 0; i < 9; i++) {

		int cnt[9] = { 0 };//记录1~9出现过几次

		for (int j = 0; j < 9; j++) {
			cnt[a[j][i] - 1]++;
		}
		for (int j = 0; j < 9; j++) {
			if (cnt[j] > 1) {
				return false;
			}
		}
	}
	return true;
}

//判断每一九宫格有没有重复
bool kuai(int a[9][9]) {

	//int cnt[9] = { 0 };//记录1~9出现过几次
	for (int i0 = 0; i0 < 3; i0++) {
		for (int j0 = 0; j0 < 3; j0++) {
			int cnt[9] = { 0 };
			for (int i1 = 0; i1 < 3; i1++) {
				for (int j1 = 0; j1 < 3; j1++) {
					cnt[a[i0 * 3 + i1][j0 * 3 + j1] - 1]++;
				}
			}

			for (int i = 0; i < 9; i++) {
				if (cnt[i] > 1) {
					return false;
				}
			}


		}
	}

	return true;
}

int main()
{
	int num[9][9];
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			while (1) {

				cin >> num[i][j];   //读入x的方式必须是 cin>>int型变量，不允许其他方式
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					continue;
				}

				if (num[i][j] >= 1 && num[i][j] <= 9)
				{
					break;
				}

				cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
			}
		}
	}

	if (hang(num) && lie(num) && kuai(num)) {
		cout << "是数独的解" << endl;
	}
	else {
		cout << "不是数独的解" << endl;
	}
	return 0;
}