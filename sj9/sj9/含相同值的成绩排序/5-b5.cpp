/*1951393 �Զ��� �����*/
#include<iostream>
#define size 1000
using namespace std;

int main()
{
	int num[101] = { 0 };
	int score[1000];

	for (int i = 0; i < 1000; i++) {
		score[i] = -1;
	}

	cout << "������ɼ������1000��������-1����" << endl;

	int cnt = 0;
	while (cnt < size - 1) {

		cin >> score[cnt];

		if (score[cnt] < 0) {
			break;
		}
		cnt++;
	}

	if (score[0] < 0) {
		cout << "����Ч����" << endl;
		return 0;
	}

	cout << "���������Ϊ:";

	for (int i = 0; i < size - 1; i++) {
		if (i % 10 == 0) {
			cout << endl;
		}

		if (score[i] >= 0) {
			cout << score[i] << " ";
		}
		else {
			cout << endl;
			break;
		}
	}

	int temp;
	for (int i = 0; i < size; i++) {
		if (score[i] >= 0) {
			for (int j = size - 1; j > 0; j--) {
				if (score[j] > score[j - 1]) {
					temp = score[j];
					score[j] = score[j - 1];
					score[j - 1] = temp;
				}
			}

		}
		else {
			break;
		}
	}

	cout << "���������εĶ�Ӧ��ϵΪ:" << endl;

	int n = 1;
	for (int i = 0; i < size; i++) {
		
		if (score[i] >= 0) {
			if (i > 0 && score[i] != score[i - 1]) {
				n = i + 1;

			}
			cout << score[i] << " " << n << endl;
		}

	}
	return 0;
}


