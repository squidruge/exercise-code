/*1951393 自动化 张儒戈*/
#include<iostream>
using namespace std;

int main()
{
	double val;
	int y50 = 0, y20 = 0, y10 = 0, y5 = 0, y1 = 0, j5 = 0, j1 = 0, f5 = 0, f2 = 0, f1 = 0;
	int cnt = 0;
	cout << "请输入找零值:" << endl;
	cin >> val;

	int part1 = static_cast<int>(val);
	int part2 = static_cast<int>((val+0.001)*100)%100;
	//int part2 = static_cast<int>(val * 100) % 100;
	//cout << part1 << " " << part2 << endl;

	if (part1 >= 50) {
		y50 = part1 / 50;
		part1 = part1 - 50 * y50;
	}
	if (part1 >= 20) {
		y20 = part1 / 20;
		part1 = part1 - 20 * y20;
	}
	
	if (part1 >= 10) {
		y10 = part1 / 10;
		part1 = part1 - 10 * y10;
	}
if (part1 >= 5) {
		y5 = part1 / 5;
		part1 = part1 - 5 * y5;
	}
	y1 = part1 / 1;

	if (part2 >= 50) {
		j5 = part2 / 50;
		part2 = part2 - 50 * j5;
	}
	if (part2 >= 10) {
		j1 = part2 / 10;
		part2 = part2 - 10 * j1;
	}
	if (part2 >= 5) {
		f5 = part2 / 5;
		part2 = part2 - 5 * f5;
	}
	if (part2 >= 2) {
		f2 = part2 / 2;
		part2 = part2 - 2 * f2;
	}

	f1 = part2;



	cnt = y50 + y20 + y10 + y5 + y1 + j5 + j1 + f5 + f2 + f1;
	cout << "共" << cnt << "张找零，具体如下："<<endl;
	if (y50) {
		cout << "50元 : " << y50 << "张" << endl;
	}
	if (y20) {
		cout << "20元 : " << y20 << "张" << endl;
	}
	if (y10) {
		cout << "10元 : " << y10 << "张" << endl;
	}
	if (y5) {
		cout << "5元  : " << y5 << "张" << endl;
	}
	if (y1) {
		cout << "1元  : " << y1 << "张" << endl;
	}
	if (j5) {
		cout << "5角  : " << j5 << "张" << endl;
	}
	if (j1) {
		cout << "1角  : " << j1 << "张" << endl;
	}
	if (f5) {
		cout << "5分  : " << f5 << "张" << endl;
	}
	if (f2) {
		cout << "2分  : " << f2 << "张" << endl;
	}
	if (f1) {
		cout << "1分  : " << f1 << "张" << endl;
	}
	return 0;
}
