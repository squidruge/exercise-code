/*1951393 �Զ��� �����*/
#include<iostream>
#include <iomanip>
#define Pi 3.14159
using namespace std;

int main()
{
	double r, h;
	
	cout << "������뾶�͸߶�" << endl;
	cin >> r >> h;

	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << "Բ�ܳ�     : " << 2 * Pi * r << endl;
	cout << "Բ���     : " << Pi * r *r<< endl;
	cout << "Բ������ : " << 4 * Pi * r * r << endl;
	cout << "Բ�����   : " << 4.0/3.0 * Pi * r * r * r << endl;
	cout << "Բ�����   : " << Pi * r * r*h << endl;
	return 0;
}
