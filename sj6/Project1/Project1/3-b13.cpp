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

int main()
{
	int year,month,first;
	bool isLeap=false;
	int day=0;

	while (1) {
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> year>>month;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "����Ƿ�������������" << endl;
			continue;
		}
		if ((year >= 2000 && year <= 2030)&& (month >= 1 && month <= 12))
			break;
		cout << "����Ƿ�������������" << endl;
	}


	while (1) {
		cout << "������"<<year<<"��"<<month<<"��1�յ�����(0-6��ʾ������-������) : ";
		cin >> first;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "����Ƿ�������������" << endl;
			continue;
		}
		if (first >= 0 && first <= 6)
			break;
		cout << "����Ƿ�������������" << endl;
	}



	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		isLeap = true;
	}

	switch (month)
	{
	case 1:
		day = month1;
		break;
	case 2:
		day = month2+isLeap;
		break;
	case 3:
		day = month3;
		break;
	case 4:
		day = month4;
		break;
	case 5:
		day = month5;
		break;
	case 6:
		day = month6;
		break;
	case 7:
		day = month7;
		break;
	case 8:
		day = month8;
		break;
	case 9:
		day = month9;
		break;
	case 10:
		day = month10;
		break;
	case 11:
		day = month11;
		break;
	case 12:
		day = month12;
		break;
	default:
		break;
	}

	cout << "\n"<<year<<"��"<<month<<"�µ�����Ϊ:" << endl;
	cout<<"������  ����һ  ���ڶ�  ������  ������  ������  ������"<<endl;
	for (int cnt0=0; cnt0<first; cnt0++) {
		cout << "        " ;
	}
	for (int cnt1=1; cnt1 <= day; cnt1++) {
		if ((cnt1 + first) % 7) {
			cout << setiosflags(ios::right) << setw(4) << cnt1 << "    ";
		}
		else {
			cout << setiosflags(ios::right) << setw(4) << cnt1 << endl;
		}
	}


	
	return 0;
}
