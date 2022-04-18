/*1951393 �Զ��� �����*/
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
	 �������ƣ�isLeap
	 ��    �ܣ����Ƿ�Ϊ����
	 ���������int year:���
	 �� �� ֵ��bool
	 ˵    ����
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
	 �������ƣ�tianshu
	 ��    �ܣ�������
	 ���������int year:���
	 �� �� ֵ��
	 ˵    ����
   ***************************************************************************/
int tianshu(int year, int month, int day)
{
	int a[12] = { month1 ,month2,month3,month4,month5,month6,
	month7 ,month8 ,month9 ,month10 ,month11 ,month12 };
	int ans = 0;

	if (day > a[month - 1]+ isLeap(year)) {
		//flag2 = false;
		cout << "��������-�����µĹ�ϵ�Ƿ�" << endl;
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


	cout << "�������꣬�£���" << endl;
	cin >> year >> month >> day;

	if (month > 12 || month < 1) {
		cout << "��������-�·ݲ���ȷ" << endl;
		return 0;
	}


	if (tianshu(year, month, day)) {
		cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << tianshu(year, month, day) << "��" << endl;
	}

	return 0;
}

 