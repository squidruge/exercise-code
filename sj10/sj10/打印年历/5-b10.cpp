/*1951393 �Զ��� �����*/
#include <iostream>
#include <iomanip>
#include<limits> 

using namespace std;

void print_space(int cnt) {

	for (int i = 0; i < cnt; i++) {
		cout << " ";
	}

}
//��ӡ�º�����
void print_m(int season) {
	if (season == 3) {

		for (int i = 0; i < 3; i++) {
			print_space(11);
			cout << season * 3 + i+1 << "��";
			print_space(17);
			if (i == 2) {
				cout << endl;
			}
		}

	}
	else {
		for (int i = 0; i < 3; i++) {
			print_space(12);
			cout << season * 3 + i+1 << "��";
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
	int first[12];//�洢��һ�������
	int last[12];//�洢���һ�������
	int max_day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int day_cnt[12] = { 0 };//��¼ÿ�����Ѿ���ӡ�˶���
	int over[12] = { 0 };//��¼�Ƿ��ӡ��

	while (1) {
		cout << "��������[1900-2100]" << endl;
		cin >> year;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "�����������������" << endl;
			continue;
		}


		if (year >= 1900 && year <= 2100) {
			break;
		}
		/*
		else {
			cout << "��ݲ���ȷ������������" << endl;
		}*/
	}

	max_day[1] += isLeap(year);

	cout << year << "�������:" << endl << endl;
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

						//�·������ӡ�ո�
						if (!day_cnt[month - 1]) {
							print_space(4 * first[month - 1]);
						}
						//��ӡ��
						cout << setw(4) << setiosflags(ios::left) << ++day_cnt[month - 1];

						//�ж��Ƿ��ÿ��ĩβ
						if ((day_cnt[month - 1] + first[month - 1]) % 7 == 0) {

							//�����һ������Ϊ��ӡ���
							if (day_cnt[month - 1] == max_day[month - 1]) {
								over[month - 1] = 1;

							}
							//�¼�ദ��
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
							//�¼�ദ��
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

		//����֮�����
		cout << endl;

	}

	cout << endl;//�������




	return 0;
}