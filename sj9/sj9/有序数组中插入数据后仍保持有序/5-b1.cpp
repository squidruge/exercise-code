/*1951393 �Զ��� �����*/
#include <iostream>
#define size 21
using namespace std;

int main()
{
	int a[size] = { 0 };
	int cnt = 0;
	int num;//Ҫ�������



	cout << "��������������������������20��������-1����" << endl;
	while (cnt < size - 1) {

		cin >> a[cnt];

		if (a[cnt] <= 0) {
			break;
		}
		cnt++;
	}
	cin.ignore(1024, '\n');

	if (a[0] <= 0) {
		cout << "����Ч����" << endl;
		return 0;
	}

	cout << "ԭ����Ϊ��" << endl;

	for (int i = 0; i < size - 1; i++) {
		if (a[i] > 0) {
			cout << a[i] << " ";
		}
		else {
			break;
		}
	}

	cout << endl;
	cout << "������Ҫ�����������" << endl;
	cin >> num;

	if (num < a[0]) {
		for (int i = 0; i < size - 2; i++) {
			a[i + 1] = a[i];
		}
		a[0] = num;
	}
	else {
		for (int i = size - 2; i >= 0; i--) {

			if (num > a[i] && a[i] > 0) {

				for (int j = size - 1; j > i + 1; j--) {
					a[j] = a[j - 1];
				}
				a[i + 1] = num;
				break;
			}
		}
	}


	cout << "����������Ϊ��" << endl;

	for (int i = 0; i < size; i++) {
		if (a[i] > 0) {
			cout << a[i] << " ";
		}
		else {
			break;
		}
	}
	cout << endl;

	return 0;
}
