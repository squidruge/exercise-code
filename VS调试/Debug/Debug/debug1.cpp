/*1951393 自动化 张儒戈*/
#include <iostream>
#include <time.h>

#define X_MAX 25
#define Y_MAX 9

using namespace std;

void count(int cnt)
{
	static int num = 0;
	for (int i = 0; i < cnt; i++,num++) {
		cout << i << " ";
		
	}
}


int main()
{
	char ch='A';
	int a=6;
	float b=1.1f;

	int array[10] = { 0 };
	int* p = array;

	count(a);
	a = 3 * 4 = 4 * 5;
	return 0;

}
