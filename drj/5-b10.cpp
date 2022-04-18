/* 1951650 ��02 ���ʽ� */
#include <iostream>
#include <iomanip>
using namespace std;

/***************************************************************************
  �������ƣ�zeller
  ��    �ܣ�������������ռ����������
  ������������ �·� ��
  �� �� ֵ��int���͵�������w
  ˵    ��������ֵΪ���յ���������0-6��ʾ���յ�����
***************************************************************************/
int zeller(int y, int m, int d)
{
	int w = -2, c, y0;
	if (m < 3)  //������һ���13 14��
	{
		y--;
		m += 12;
	}
	c = y / 100;   //���ͼ�1
	y0 = y % 100;  //���빫ʽ����� 
	w = y0 + (y0 / 4) + (c / 4) - (2 * c) + (13 * (m + 1) / 5) + d - 1;
	while (w < 0)
	{
		w += 7;
	}
	w = w % 7;
	return w;
}

/* �����ȷ����� */
int input_year()
{
	int y = -1;
	while (1)
	{
		cout << "���������[1900-2100]" << endl;
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
	int judge[4] = { 0 };   //�ж��ò��ò�һ���س�
	int date[12][42] = { 0 };
	int first_day[12] = { 0 };   //�洢12���µ�1�Ŷ������ڼ�
	int day_of_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //2����ʱ����ƽ�긳ֵ
	int i, j, k;
	y = input_year();  //�������
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) //��������꣬����һ�µ���
	{
		day_of_month[1] = 29;
	}
	

	for (i = 0; i < 12; ++i)  //�������i+1�µĵ�һ�����ܼ�
	{
		first_day[i] = zeller(y, i + 1, 1);
	}

	for (i = 0; i < 12; ++i)  //��ɶ�����ĸ�ֵ
	{
		count = 0;
		for (j = first_day[i]; j < first_day[i] + day_of_month[i]; ++j)
		{
			date[i][j] = ++count;
		}
	}

	for (i = 0; i < 4; ++i)  //�����жϵ������ǲ��������ӣ���������������У������ӵĻ�judge[i]��Ϊ1
	{
		judge[i] = date[0 + 3 * i][35] + date[1 + 3 * i][35] + date[2 + 3 * i][35];
		if (judge[i] != 0)
		{
			judge[i] = 1;
		}
	}
	cout << y << "�������:" << endl << endl;
	cout << "            1��                             2��                             3��" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	for (i = 0; i < 5 + judge[0]; ++i)  //6��  &&(date[0][35])
	{
		for (j = 0; j < 3; ++j)   //3���·�
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

	cout << "            4��                             5��                             6��" << endl;
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

	cout << "            7��                             8��                             9��" << endl;
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

	cout << "           10��                            11��                            12��" << endl;
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
	cout << endl;  //���ֺ�demoһ�£���һ������

	return 0;
}