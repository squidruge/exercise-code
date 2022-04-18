/*1951393 自动化 张儒戈*/
#include <iostream>
#include <iomanip>
#include<limits> 
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

int zeller(int y,int m,int d)
{
	int w,c;
	
	if(m<3){
		m+=12;	
		y--;
	}
	
	c=y/100;
	y%=100;
	w=y+y/4+c/4-2*c+13*(m+1)/5+d-1;
	return w%7;
}


int main()
{
	int year, month, day,day_max;
	bool isLeap = false;



	while (1) {
		cout << "请输入年[1900-2100]、月、日："<<endl;
		cin >> year >> month>>day;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "输入错误，请重新输入" << endl;
			continue;
		}

		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
				isLeap = true;
			}

		if (year >= 1900 && year <= 2100) {
			if(month >= 1 && month <= 12){
				
				switch (month)
				{
				case 1:
					day_max = month1;
					break;
				case 2:
					day_max = month2 + isLeap;
					break;
				case 3:
					day_max = month3;
					break;
				case 4:
					day_max = month4;
					break;
				case 5:
					day_max = month5;
					break;
				case 6:
					day_max = month6;
					break;
				case 7:
					day_max = month7;
					break;
				case 8:
					day_max = month8;
					break;
				case 9:
					day_max = month9;
					break;
				case 10:
					day_max = month10;
					break;
				case 11:
					day_max = month11;
					break;
				case 12:
					day_max = month12;
					break;
				default:
					break;
				}

				if(day>0&&day<=day_max){
					break;
				}else{
					cout<<"日不正确，请重新输入"<<endl;
				}
			}else{
				cout<<"月份不正确，请重新输入"<<endl; 
			}
			
		}else{
			cout<<"年份不正确，请重新输入"<<endl;
		}			
	}
	
		switch(zeller(year,month,day))
		{
		case 1:
			cout<<"一"<<endl;
			break;
		case 2:
			cout<<"二"<<endl;
			break;
		case 3:
			cout<<"三"<<endl;
			break;
		case 4:
			cout<<"四"<<endl;
			break;
		case 5:
			cout<<"五"<<endl;
			break;
		case 6:
			cout<<"六"<<endl;
			break;
		case 0:
			cout<<"日"<<endl;
			break;
		default:
			break;	
		}
	
	


	return 0;
}
