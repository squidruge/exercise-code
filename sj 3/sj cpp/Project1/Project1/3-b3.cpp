/*1951393 �Զ��� �����*/
#include<iostream>
using namespace std;

int main()
{
	int num;

	cout << "������һ��[1..30000]�������:" << endl;
	cin >> num;

	cout << "��λ : " << num / 10000 << endl;
	cout << "ǧλ : " << (num / 1000) % 10 << endl;
	cout << "��λ : " << (num / 100) % 10 << endl;
	cout << "ʮλ : " << (num / 10) % 10 << endl;
	cout << "��λ : " << num  % 10 << endl;
	return 0;
}
