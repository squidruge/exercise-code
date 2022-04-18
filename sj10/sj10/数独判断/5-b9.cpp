/*1951393 �Զ��� �����*/
#include <iostream>
using namespace std;


//�ж�ÿһ����û���ظ�
bool hang(int a[9][9]) {
	
	for (int i = 0; i < 9; i++) {

		int cnt[9] = { 0 };//��¼1~9���ֹ�����
		for (int j = 0; j < 9; j++) {
			cnt[a[i][j] - 1]++;
		}
		for (int j = 0; j < 9; j++) {
			if (cnt[j] > 1) {
				return false;
			}
		}
	}
	return true;
}
//�ж�ÿһ����û���ظ�
bool lie(int a[9][9]) {
	
	for (int i = 0; i < 9; i++) {

		int cnt[9] = { 0 };//��¼1~9���ֹ�����

		for (int j = 0; j < 9; j++) {
			cnt[a[j][i] - 1]++;
		}
		for (int j = 0; j < 9; j++) {
			if (cnt[j] > 1) {
				return false;
			}
		}
	}
	return true;
}

//�ж�ÿһ�Ź�����û���ظ�
bool kuai(int a[9][9]) {

	//int cnt[9] = { 0 };//��¼1~9���ֹ�����
	for (int i0 = 0; i0 < 3; i0++) {
		for (int j0 = 0; j0 < 3; j0++) {
			int cnt[9] = { 0 };
			for (int i1 = 0; i1 < 3; i1++) {
				for (int j1 = 0; j1 < 3; j1++) {
					cnt[a[i0 * 3 + i1][j0 * 3 + j1] - 1]++;
				}
			}

			for (int i = 0; i < 9; i++) {
				if (cnt[i] > 1) {
					return false;
				}
			}


		}
	}

	return true;
}

int main()
{
	int num[9][9];
	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			while (1) {

				cin >> num[i][j];   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
					continue;
				}

				if (num[i][j] >= 1 && num[i][j] <= 9)
				{
					break;
				}

				cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
			}
		}
	}

	if (hang(num) && lie(num) && kuai(num)) {
		cout << "�������Ľ�" << endl;
	}
	else {
		cout << "���������Ľ�" << endl;
	}
	return 0;
}