/*1951393 自动化 张儒戈*/
#include<iostream>
#include <iomanip>
using namespace std;

int main()
{
	for (int r_num = 1; r_num <= 9; r_num++) {
		for (int c_num = 1; c_num <= r_num; c_num++) {
			cout << c_num << 'x' << r_num<<'=';
			cout << setiosflags(ios::left) << setw(4) << (r_num * c_num);
			if (c_num == r_num)
				cout << endl;
		}
		
	}

	return 0;
}