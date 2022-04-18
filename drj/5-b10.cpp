/* 1951650 信02 戴仁杰 */
#include <iostream>
#include <iomanip>
using namespace std;

/***************************************************************************
  函数名称：zeller
  功    能：将输入的年月日计算出星期数
  输入参数：年份 月份 日
  返 回 值：int类型的星期数w
  说    明：返回值为该日的星期数，0-6表示周日到周六
***************************************************************************/
int zeller(int y, int m, int d)
{
	int w = -2, c, y0;
	if (m < 3)  //看做上一年的13 14月
	{
		y--;
		m += 12;
	}
	c = y / 100;   //世纪减1
	y0 = y % 100;  //带入公式的年份 
	w = y0 + (y0 / 4) + (c / 4) - (2 * c) + (13 * (m + 1) / 5) + d - 1;
	while (w < 0)
	{
		w += 7;
	}
	w = w % 7;
	return w;
}

/* 获得正确的年份 */
int input_year()
{
	int y = -1;
	while (1)
	{
		cout << "请输入年份[1900-2100]" << endl;
		cin >> y;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (y >= 1900 && y <= 2100)
		{
			break;
		}
	}
	return y;
}

int main()
{
	system("mode con cols=120 lines=45");
	int y;
	int count = 0;
	int judge[4] = { 0 };   //判断用不用补一个回车
	int date[12][42] = { 0 };
	int first_day[12] = { 0 };   //存储12个月的1号都是星期几
	int day_of_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //2月暂时按照平年赋值
	int i, j, k;
	y = input_year();  //输入年份
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) //如果是闰年，进行一下调整
	{
		day_of_month[1] = 29;
	}
	

	for (i = 0; i < 12; ++i)  //计算出第i+1月的第一天是周几
	{
		first_day[i] = zeller(y, i + 1, 1);
	}

	for (i = 0; i < 12; ++i)  //完成对数组的赋值
	{
		count = 0;
		for (j = first_day[i]; j < first_day[i] + day_of_month[i]; ++j)
		{
			date[i][j] = ++count;
		}
	}

	for (i = 0; i < 4; ++i)  //用来判断第六行是不是有日子，用来决定输出几行，有日子的话judge[i]就为1
	{
		judge[i] = date[0 + 3 * i][35] + date[1 + 3 * i][35] + date[2 + 3 * i][35];
		if (judge[i] != 0)
		{
			judge[i] = 1;
		}
	}
	cout << y << "年的日历:" << endl << endl;
	cout << "            1月                             2月                             3月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	for (i = 0; i < 5 + judge[0]; ++i)  //6行  &&(date[0][35])
	{
		for (j = 0; j < 3; ++j)   //3个月份
		{
			for (k = 7 * i; k < 7 + 7 * i; ++k)
			{
				cout << setiosflags(ios::left);
				if (date[j][k] != 0)
				{
					cout << setw(4) << date[j][k];
				}
				else
				{
					cout << setw(4) << " ";
				}
			}
			if ((j + 1) % 3 != 0)
			{
				cout << setw(4) << " ";
			}
		}
		cout << endl;
	}
	cout << endl;

	cout << "            4月                             5月                             6月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	
	for (i = 0; i < 5 + judge[1]; ++i)
	{
		for (j = 3; j < 6; ++j)
		{
			for (k = 7 * i; k < 7 + 7 * i; ++k)
			{
				cout << setiosflags(ios::left);
				if (date[j][k] != 0)
				{
					cout << setw(4) << date[j][k];
				}
				else
				{
					cout << setw(4) << " ";
				}
			}
			if ((j + 1) % 3 != 0)
			{
				cout << setw(4) << " ";
			}
		}
		cout << endl;
	}
	cout << endl;

	cout << "            7月                             8月                             9月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	for (i = 0; i < 5 + judge[2]; ++i)
	{
		for (j = 6; j < 9; ++j)
		{
			for (k = 7 * i; k < 7 + 7 * i; ++k)
			{
				cout << setiosflags(ios::left);
				if (date[j][k] != 0)
				{
					cout << setw(4) << date[j][k];
				}
				else
				{
					cout << setw(4) << " ";
				}
			}
			if ((j + 1) % 3 != 0)
			{
				cout << setw(4) << " ";
			}
		}
		cout << endl;
	}
	cout << endl;

	cout << "           10月                            11月                            12月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	for (i = 0; i < 5 + judge[3]; ++i)
	{
		for (j = 9; j < 12; ++j)
		{
			for (k = 7 * i; k < 7 + 7 * i; ++k)
			{
				cout << setiosflags(ios::left);
				if (date[j][k] != 0)
				{
					cout << setw(4) << date[j][k];
				}
				else
				{
					cout << setw(4) << " ";
				}
			}
			if ((j + 1) % 3 != 0)
			{
				cout << setw(4) << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;  //保持和demo一致，多一个换行

	return 0;
}