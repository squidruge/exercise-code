/*1951393 �Զ��� �����*/
#include<iostream>
using namespace std;

int main()
{
	double num;
	int a12, a11, a10,a9,a8,a7,a6,
		a5,a4,a3,a2,a1;	//�ɸߵ��͸�λ��
	cout << "������[0-100��)֮�������:" << endl;
	cin >> num;


	a12 = static_cast<int>(num / 1.0e9);
	a11 = static_cast<int>(num / 1.0e8) % 10;
	a10 = static_cast<int>(num / 1.0e7) % 10;
	a9 = static_cast<int>(num / 1.0e6) % 10;
	a8 = static_cast<int>(num / 1.0e5) % 10;
	a7 = static_cast<int>(num / 1.0e4) % 10;
	a6 = static_cast<int>(num / 1000.0) % 10;
	a5 = static_cast<int>(num / 100.0) % 10;
	a4 = static_cast<int>((num - a12 * 1.0e9 - a11 * 1.0e8 - a10 * 1.0e7) / 10) % 10;
	a3 = static_cast<int>(num - a12 * 1.0e9 - a11 * 1.0e8 - a10 * 1.0e7) % 10;
	a2= static_cast<int>((num - a12 * 1.0e9 - a11 * 1.0e8 - a10 * 1.0e7+0.00500)*10) % 10;
	a1= static_cast<int>((num - a12 * 1.0e9 - a11 * 1.0e8 - a10 * 1.0e7+0.00500) * 100) % 10;


	cout << "ʮ��λ : " << a12 << endl;
	cout << "��     : " << a11<< endl;
	cout << "ǧ��λ : "<< a10 << endl;
	cout << "����λ : " << a9 << endl;
	cout << "ʮ��λ : " << a8 << endl;
	cout << "��λ   : " << a7 << endl;
	cout << "ǧλ   : " << a6 << endl;
	cout << "��λ   : " << a5 << endl;
	cout << "ʮλ   : " << a4 << endl;
	cout << "Բ     : " << a3 << endl;
	cout << "��     : " <<a2 << endl;
	cout << "��     : " << a1 << endl;

	return 0;
}

// 9999999999.99   9999999999.90  9999999999.09  9900000000
//8912003005.78 2501200350.03 1203056740.00 9999999999.09
//23000056.82 3051200.72  301000.35   10001.34
//8070.23  9876.54  803.03  12.30
//10.03  9.30 7.03  0.35
//0.30 0.07 0.03   0
