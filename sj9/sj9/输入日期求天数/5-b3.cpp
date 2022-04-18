/*1951393 自动化 张儒戈*/
#include<iostream>
#define month1 31
#define month2 28
#define month3 31
#define month4 30
#define month5 31
#define month6 30
#define month7 31
#define month8 31
#define month9 30
#define month10 31
#define month11 30
#define month12 31
using namespace std;

/***************************************************************************
	 函数名称：isLeap
	 功    能：求是否为闰年
	 输入参数：int year:年份
	 返 回 值：bool
	 说    明：
   ***************************************************************************/
bool isLeap(int year)
{

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return true;
	}
	else {
		return false;
	}
}
/***************************************************************************
	 函数名称：tianshu
	 功    能：求天数
	 输入参数：int year:年份
	 返 回 值：
	 说    明：
   ***************************************************************************/
int tianshu(int year, int month, int day)
{
	int a[12] = { month1 ,month2,month3,month4,month5,month6,
	month7 ,month8 ,month9 ,month10 ,month11 ,month12 };
	int ans = 0;

	if (day > a[month - 1]+ isLeap(year)) {
		//flag2 = false;
		cout << "错误输入-日与月的关系非法" << endl;
	}
	else {
		if (month > 2)
			ans += isLeap(year);

		for (int i = 0; i < month - 1; i++) {

			ans += a[i];

		}
		ans += day;

	}
	return ans;
}


int main()
{
	int year, month, day;


	cout << "请输入年，月，日" << endl;
	cin >> year >> month >> day;

	if (month > 12 || month < 1) {
		cout << "错误输入-月份不正确" << endl;
		return 0;
	}


	if (tianshu(year, month, day)) {
		cout << year << "-" << month << "-" << day << "是" << year << "年的第" << tianshu(year, month, day) << "天" << endl;
	}

	return 0;
}

 