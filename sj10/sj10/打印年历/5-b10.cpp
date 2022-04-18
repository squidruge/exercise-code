/*1951393 自动化 张儒戈*/
#include <iostream>
#include <iomanip>
#include<limits> 

using namespace std;

void print_space(int cnt) {

	for (int i = 0; i < cnt; i++) {
		cout << " ";
	}

}
//打印月和星期
void print_m(int season) {
	if (season == 3) {

		for (int i = 0; i < 3; i++) {
			print_space(11);
			cout << season * 3 + i+1 << "月";
			print_space(17);
			if (i == 2) {
				cout << endl;
			}
		}

	}
	else {
		for (int i = 0; i < 3; i++) {
			print_space(12);
			cout << season * 3 + i+1 << "月";
			print_space(17);
			if (i == 2) {
				cout << endl;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		cout << "Sun Mon Tue Wed Thu Fri Sat";
		if (i == 2) {
			cout << endl;

		}
		else {
			print_space(5);
		}
	}

}


bool isLeap(int year) {

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return  true;
	}
	else {
		return false;
	}

}

int zeller(int y, int m, int d)
{
	int w, c;

	if (m < 3) {
		m += 12;
		y--;
	}

	c = y / 100;
	y %= 100;
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	while (w < 0) {
		w += 7;
	}
	return w % 7;
}

int main()
{
	system("mode con cols=120 lines=45");

	int year, month;
	int day = 0;
	int first[12];//存储第一天的星期
	int last[12];//存储最后一天的星期
	int max_day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int day_cnt[12] = { 0 };//记录每个月已经打印了多少
	int over[12] = { 0 };//记录是否打印完

	while (1) {
		cout << "请输入年[1900-2100]" << endl;
		cin >> year;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "输入错误，请重新输入" << endl;
			continue;
		}


		if (year >= 1900 && year <= 2100) {
			break;
		}
		/*
		else {
			cout << "年份不正确，请重新输入" << endl;
		}*/
	}

	max_day[1] += isLeap(year);

	cout << year << "年的日历:" << endl << endl;
	for (int season = 0; season < 4; season++) {

		print_m(season);

		for (int i = 0; i < 3; i++) {
			month = season * 3 + i + 1;
			first[month - 1] = zeller(year, month, 1);
			last[month - 1] = zeller(year, month, max_day[month - 1]);


		}

		while (over[season * 3] == 0 || over[season * 3 + 1] == 0 || over[season * 3 + 2] == 0) {


			for (month = season * 3 + 1; month <= (season + 1) * 3; month++) {

				if (over[month-1]) {
					print_space(7 * 4);
					if (month % 3) {
						print_space(4);
					}
					else {
						cout << endl;
					}
					continue;
				}
				else {
					while (1) {

						//月份最初打印空格
						if (!day_cnt[month - 1]) {
							print_space(4 * first[month - 1]);
						}
						//打印日
						cout << setw(4) << setiosflags(ios::left) << ++day_cnt[month - 1];

						//判断是否打到每周末尾
						if ((day_cnt[month - 1] + first[month - 1]) % 7 == 0) {

							//打到最后一天则标记为打印完成
							if (day_cnt[month - 1] == max_day[month - 1]) {
								over[month - 1] = 1;

							}
							//月间距处理
							if (month % 3) {
								print_space(4);

							}
							else {
								cout << endl;
							}

							break;
						}

						if (day_cnt[month - 1] == max_day[month - 1]) {

							print_space(4 * (6 - last[month - 1]));
							//月间距处理
							if (month % 3) {
								print_space(4);

							}
							else {
								cout << endl;
							}
							over[month - 1] = 1;
							break;

						}
					}

				}


			}

		}

		//季度之间空行
		cout << endl;

	}

	cout << endl;//多空两行




	return 0;
}