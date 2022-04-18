/*1951393 �Զ��� �����*/
#include <iostream>
#include <cmath>
using namespace std;

double cross_product(double a[], double b[], double c[])//���
{
	double t;
	//��ʽ:s=(x1-x3)*(y2-y3)-(x2-x3)*(y1-y3)  
	//��s>0ʱ,p1,p2,p3���������ʱ��  
	//��s<0ʱ,p1,p2,p3�������˳ʱ��  
	//t = (a[0] - c[0]) * (b[1] - c[1]) - (b[0] - c[0]) * (a[1] - c[1]);
	t = (b[0] - a[0]) * (c[1] - b[1]) - (c[0] - b[0]) * (b[1] - a[1]);
	return t;
}

//�Ƿ�ȫΪ����
bool is_positive(double a[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] < 1e-6) {
			return false;
		}
	}
	return true;
}
//�Ƿ�ȫΪ����
bool is_negative(double a[], int n) {
	for (int i = 0; i < n; i++) {
		if (-a[i] < 1e-6) {
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	double coor[7][2] = { 0 };//���������
	double sub_0[6][2] = { 0 };//�����ȥcoor[0][0]
	double prod[7] = { 0 };//��˽��
	double s = 0;

	while (1)
	{
		cout << "���������εĶ�������(4-7)" << endl;
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (n >= 4 && n <= 7)
		{
			break;
		}
	}

	cout << "�밴˳ʱ��/��ʱ�뷽������"<<n<<"�������x,y���꣺" << endl;

	for (int i = 0; i < n; i++) {



		while (1) {
			cout << "�������" << i + 1 << "����������꣺" << endl;
			cin >> coor[i][0] >> coor[i][1];   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}

			break;

		}
	}

	for (int i = 0; i < n - 2; i++) {
		prod[i] = cross_product(coor[i], coor[i + 1], coor[i + 2]);
	}
	prod[n - 2] = cross_product(coor[n - 2], coor[n - 1], coor[0]);
	prod[n - 1] = cross_product(coor[n - 1], coor[0], coor[1]);


	for (int i = 0; i < n - 1; ++i)
	{
		sub_0[i][0] = coor[i + 1][0] - coor[0][0];
		sub_0[i][1] = coor[i + 1][1] - coor[0][1];
	}
	//������ɶԷֿ��������ļ���
	for (int i = 0; i < n - 2; ++i)
	{
		s+=0.5 * fabs(sub_0[i][0] * sub_0[i+1][1] - sub_0[i+1][0] * sub_0[i][1]);
		
	}
	//�����������������������ӹ���

	if (is_positive(prod,n) || is_negative(prod,n)) {

		/*
		for (int i = 0; i < n; i++) {
			s += 0.5 *fabs(prod[i]);
		}*/
		cout << "͹" << n << "���ε����=" << s<<endl;
	}
	else {
		cout << "����͹" << n << "����" << endl;;
	}

	
	return 0;
}