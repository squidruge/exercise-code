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

int main()
{
	int year, month, day;
	int ans = 0;
	bool isLeap = false, flag1 = true, flag2 = true;
	//isLeap���ڼ�¼�Ƿ�Ϊ���� flag1���ڼ�¼�����·���ȷ��� flag2���ڼ�¼�����¹�ϵ��ȷ���
	cout << "�������꣬�£���" << endl;
	cin >> year >> month >> day;

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		isLeap = true;
	}

	switch (month)
	{
	case 1:
		if (day > month1) {
			flag2 = false;
			cout << "��������-�����µĹ�ϵ�Ƿ�" << endl;
		}
		else {
			ans = day;
		}
		break;
	case 2:
		if (isLeap) {
			if (day > month2 + 1) {
				flag2 = false;
				cout << "��������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			else {
				ans = month1 + day;
			}
		}
		else {
			if (day > month2) {
				flag2 = false;
				cout << "��������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			else {
				ans = month1 + day;
			}
		}

		break;
	case 3:
		if (day > month3) {
			flag2 = false;
			cout << "��������-�����µĹ�ϵ�Ƿ�" << endl;
		}
		else {
			if (isLeap) {
				ans = month1 + (month2 + 1) + day;
			}
			else {
				ans = month1 + month2 + day;
			}

		}
		break;
	case 4:
		if (day > month4) {
			flag2 = false;
			cout << "��������-�����µĹ�ϵ�Ƿ�" << endl;
		}
		else {
			if (isLeap) {
				ans = month1 + (month2 + 1) + month3 + day;
			}
			else {
				ans = month1 + month2 + month3 + day;
			}

		}
		break;
	case 5:
		if (day > month5) {
			flag2 = false;
			cout << "��������-�����µĹ�ϵ�Ƿ�" << endl;
		}
		else {
			if (isLeap) {
				ans = month1 + (month2 + 1) + month3 + month4 + day;
			}
			else {
				ans = month1 + month2 + month3 + month4 + day;
			}

		}
		break;
	case 6:
		if (day > month6) {
			flag2 = false;
			cout << "��������-�����µĹ�ϵ�Ƿ�" << endl;
		}
		else {
			if (isLeap) {
				ans = month1 + (month2 + 1) + month3 + month4 + month5 + day;
			}
			else {
				ans = month1 + month2 + month3 + month4 + month5 + day;
			}

		}
		break;
	case 7:
		if (day > month7) {
			flag2 = false;
			cout << "��������-�����µĹ�ϵ�Ƿ�" << endl;
		}
		else {
			if (isLeap) {
				ans = month1 + (month2 + 1) + month3 + month4 + month5 + month6 + day;
			}
			else {
				ans = month1 + month2 + month3 + month4 + month5 + month6 + day;
			}

		}
		break;
	case 8:
		if (day > month8) {
			flag2 = false;
			cout << "��������-�����µĹ�ϵ�Ƿ�" << endl;
		}
		else {
			if (isLeap) {
				ans = month1 + (month2 + 1) + month3 + month4 + month5 + month6 + month7 + day;
			}
			else {
				ans = month1 + month2 + month3 + month4 + month5 + month6 + month7 + day;
			}

		}
		break;
	case 9:
		if (day > month9) {
			flag2 = false;
			cout << "��������-�����µĹ�ϵ�Ƿ�" << endl;
		}
		else {
			if (isLeap) {
				ans = month1 + (month2 + 1) + month3 + month4 + month5 + month6 + month7 + month8 + day;
			}
			else {
				ans = month1 + month2 + month3 + month4 + month5 + month6 + month7 + month8 + day;
			}

		}
		break;
	case 10:
		if (day > month10) {
			flag2 = false;
			cout << "��������-�����µĹ�ϵ�Ƿ�" << endl;
		}
		else {
			if (isLeap) {
				ans = month1 + (month2 + 1) + month3 + month4 + month5 + month6 + month7
					+ month8 + month9 + day;
			}
			else {
				ans = month1 + month2 + month3 + month4 + month5 + month6 + month7
					+ month8 + month9 + day;
			}

		}
		break;
	case 11:
		if (day > month11) {
			flag2 = false;
			cout << "��������-�����µĹ�ϵ�Ƿ�" << endl;
		}
		else {
			if (isLeap) {
				ans = month1 + (month2 + 1) + month3 + month4 + month5 + month6 + month7
					+ month8 + month9 + month10 + day;
			}
			else {
				ans = month1 + month2 + month3 + month4 + month5 + month6 + month7
					+ month8 + month9 + month10 + day;
			}

		}
		break;
	case 12:
		if (day > month12) {
			flag2 = false;
			cout << "��������-�����µĹ�ϵ�Ƿ�" << endl;
		}
		else {
			if (isLeap) {
				ans = month1 + (month2 + 1) + month3 + month4 + month5 + month6 + month7
					+ month8 + month9 + month10 + month11 + day;
			}
			else {
				ans = month1 + month2 + month3 + month4 + month5 + month6 + month7
					+ month8 + month9 + month10 + month11 + day;
			}

		}
		break;
	default:
		flag1 = false;
		cout << "��������-�·ݲ���ȷ" << endl;
		break;
	}
	if (flag1 == true && day <= 0) {
		flag2 = false;
		cout << "��������-�����µĹ�ϵ�Ƿ�" << endl;
	}

	if (flag1 && flag2) {
		cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << ans << "��" << endl;
	}

	return 0;
}

//��������
// 2019-