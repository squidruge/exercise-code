/*1951393 自动化 张儒戈*/
#include <iostream>
#include<iomanip>
using namespace std;


int main()
{
	int a[13][13] = { 0 };
	

	int n;


	cout << "请输入要打印的行数[3..13]" << endl;
	cin >> n;

	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "0         1         2         3         4         5         6         7" << endl;
	cout << "01234567890123456789012345678901234567890123456789012345678901234567890123456789" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;


	for (int i = 0; i < n; i++)
	{
		a[i][0] = 1;//行第一个置1
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			//杨辉三角计算公式
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			
		}
	}

	//输出部分
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != 0) {
				if (j == 0) {
					cout << setw(6 + 3 * (n - i - 1)) << a[i][j];
				}
				else {
					cout << setw(6) << a[i][j];
				}

			}


		}
		cout << endl;
	}



	cout << "--------------------------------------------------------------------------------" << endl;

	cout << "01234567890123456789012345678901234567890123456789012345678901234567890123456789" << endl;
	cout << "0         1         2         3         4         5         6         7" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	return 0;
}