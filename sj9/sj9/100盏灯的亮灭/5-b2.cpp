/*1951393 自动化 张儒戈*/
#include <iostream>
#define num 100

using namespace std;

int main()
{
	int a[num] = { 0 };

	for (int i = 0; i < num; i++) {
		for (int j = 1; j <= num; j++) {
			if ((i + 1) % j == 0)
				a[i] ++;
		}
	}

	for (int i = 0; i < num; i++) {
		if (a[i] % 2) {
			cout << (i + 1) << " ";
		}
	}

	cout << endl;

	return 0;
}

