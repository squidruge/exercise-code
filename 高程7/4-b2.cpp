/*1951393 �Զ��� �����*/
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

	if (w < 0) {
		do
		{
			w += 7;
		} while (w<0);
	}
	return w%7;
}


int main()
{
	int year, month, day,day_max;
	bool isLeap = false;



	while (1) {
		cout << "��������[1900-2100]���¡��գ�"<<endl;
		cin >> year >> month>>day;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "�����������������" << endl;
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
					cout<<"�ղ���ȷ������������"<<endl;
				}
			}else{
				cout<<"�·ݲ���ȷ������������"<<endl; 
			}
			
		}else{
			cout<<"��ݲ���ȷ������������"<<endl;
		}			
	}
	
		switch(zeller(year,month,day))
		{
		case 1:
			cout<<"����һ"<<endl;
			break;
		case 2:
			cout<<"���ڶ�"<<endl;
			break;
		case 3:
			cout<<"������"<<endl;
			break;
		case 4:
			cout<<"������"<<endl;
			break;
		case 5:
			cout<<"������"<<endl;
			break;
		case 6: 
			cout<<"������"<<endl;
			break;
		case 0:
			cout<<"������"<<endl;
			break;
		default:
			cout<<zeller(year, month, day) << endl;
			cout << "error" << endl;
			break;	
		}
	
	


	return 0;
}
