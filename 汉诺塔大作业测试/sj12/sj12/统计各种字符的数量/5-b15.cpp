/*1951393 �Զ��� �����*/
#include <iostream>
#include <cstdio>

using namespace std;

void tongji(int cnt[], char str[])
{
	int i;

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			cnt[0]++;
			continue;
		}

		if (str[i] >= 'a' && str[i] <= 'z') {
			cnt[1]++;
			continue;
		}

		if (str[i] >= '0' && str[i] <= '9') {
			cnt[2]++;
			continue;
		}

		if (str[i] == ' ') {
			cnt[3]++;
			continue;
		}
		if (str[i] != '\n') {
			cnt[4]++;//�����ַ�
		}


	}
}

int main()
{
	char str[3][128] = { '\0' };
	int cnt[5] = { 0 };
	for (int i = 0; i < 3; i++) {
		cout << "�������" << (i + 1) << "��" << endl;
		cin.getline(str[i], 128);
	}




	tongji(cnt, str[0]);
	tongji(cnt, str[1]);
	tongji(cnt, str[2]);

	cout << "��д : " << cnt[0] << endl;
	cout << "Сд : " << cnt[1] << endl;
	cout << "���� : " << cnt[2] << endl;
	cout << "�ո� : " << cnt[3] << endl;
	cout << "���� : " << cnt[4] << endl;


	return 0;
}
