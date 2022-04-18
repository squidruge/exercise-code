/*1951393 自动化 张儒戈*/
#include<iostream>
using namespace std;

int main()
{
	for (int num = 2; num <= 1000; ++num) {

		for (int factor = 1, sum = 0, cnt = 0; factor < num; factor++) {
			if (num % factor == 0) {
				sum += factor;
				cnt++;
			}

			if ((factor == num - 1) && (sum == num)) {
				cout << num << ",its factors are ";
				for (int factor = 1; factor < num; ++factor) {
					if (num % factor == 0) {
						cout << factor;
						if (cnt != 1) {
							cout << ",";
							cnt--;
						}
						else {
							cout << endl;
						}


					}
				}

			}


		}


	}
	return 0;
}