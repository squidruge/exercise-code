/*1951393 �Զ��� �����*/
#include <iostream>

using namespace std;

int main()
{
	int a[10000] = { 0 };
	int n;
	int digit;
	int cnt=0;
	
	cout << "���������ݵĸ���[1..10000]" << endl;
	cin >> n;
	cout << "������"<<n<<"��������" << endl;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << "����������[0..9]" << endl;
	cin >> digit;

	for (int i = 0; i < n; i++) {
		while (a[i]) {

			if (a[i] % 10 == digit) {
				cnt++;
			}
			a[i] /= 10;
		}
	}

	cout << n<<"�����к���"<<digit<<"�ĸ��� : "<<cnt << endl;

	return 0;
}