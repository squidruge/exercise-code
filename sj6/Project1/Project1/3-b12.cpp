/*1951393 自动化 张儒戈*/
#include <iostream>
#include<limits> 
using namespace std;

int main()
{
	int x;

	while (1) {
		cout << "请输入x的值[0-100] : ";
		cin >> x;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if(cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (x >= 0 && x <= 100)
			break;
	
		
	}

	cout << "x=" << x << endl;

	return 0;
}
