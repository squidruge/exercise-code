/* 1951650 ��02 ���ʽ� */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n = -1; 
	int i;
	double x[10] = { 0 };     //����x
	double y[10] = { 0 };     //����y
	double xlx[10] = { 0 };   //����x
	double xly[10] = { 0 };   //����y
	double chacheng[10] = { 0 };  //��Ų�˵�ֵ�������ж��ǲ���͹�����
	double fkxl_x[10] = { 0 };  //������ڶ���ηֿ������x��ֵ
	double fkxl_y[10] = { 0 };
	double s[10] = { 0 };   //���С���������
	double total = 0;   //�����
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
	cout << "�밴˳ʱ��/��ʱ�뷽������5�������x,y���꣺" << endl;
	for (i = 0; i < n; ++i)
	{
		while (1)
		{
			cout << "�������" <<i+1<<"����������꣺"<< endl;
			cin >> x[i] >> y[i];
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			break;
		}
	}
	/* ��������˶�����Ϸ��Եļ�飬���Ϸ���������������� */

	for (i = 0; i < n-1; ++i)
	{
		xlx[i] = x[i + 1] - x[i];
		xly[i] = y[i + 1] - y[i];
	}
	xlx[n - 1] = x[0] - x[n - 1];
	xly[n - 1] = y[0] - y[n - 1];
	//������ɶ�ÿ��������ֵ�ļ���洢
	for (i = 0; i < n-1; ++i)
	{
		chacheng[i] = xlx[i] * xly[i + 1] - xlx[i + 1] * xly[i];
	}
	chacheng[n - 1] = xlx[n - 1] * xly[0] - xlx[0] * xly[n - 1];
	//������ɶ��������߲�˵�����
	for (i = 0; i < n-1; ++i)
	{
		fkxl_x[i] = x[i + 1] - x[0];
		fkxl_y[i] = y[i + 1] - y[0];
	}	
	//������ɶԷֿ��������ļ���
	for (i = 0; i < n - 2; ++i)
	{
		s[i] = 0.5 * fabs((fkxl_x[i] * fkxl_y[i + 1] - fkxl_x[i + 1] * fkxl_y[i]));
		total += s[i];
	}
	//�����������������������ӹ���


	if (fabs(chacheng[0]) < 1e-6)   //��ʼ�͹����ˣ��������
	{
		cout << "����͹" << n << "����" << endl;
		return 0;      //����������жϳ�����͹�����
	}
	if (chacheng[0] < 0)
	{
		for (i = 1; i < n; ++i)
		{
			if (chacheng[i] > 0 || fabs(chacheng[i]) < 1e-6)  //���ʼֵ��Ż���Ϊ0(����)���������
			{
				cout << "����͹" << n << "����" << endl;
				return 0;      //����������жϳ�����͹�����
			}
		}
		cout << "͹" << n << "���ε����=" << total;
		return 0;
	}
	if (chacheng[0] > 0)
	{
		for (i = 1; i < n; ++i)
		{
			if (chacheng[i] < 0 || fabs(chacheng[i]) < 1e-6)  //���ʼֵ��Ż���Ϊ0(����)���������
			{
				cout << "����͹" << n << "����" << endl;
				return 0;      //����������жϳ�����͹�����
			}			
		}
		cout << "͹" << n << "���ε����=" << total;
		return 0;
	}

	return 0;
}
