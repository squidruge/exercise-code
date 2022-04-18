/* 1951650 ��02 ���ʽ� */
#include <iostream>
using namespace std;

int input_num(int i, int j)
{
	int x = -1;
	while (1)
	{
		cin >> x;
		if (cin.fail())
		{
			cout << "�����������" << i << "��" << j << "��(���о���1��ʼ����)��ֵ" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (x >= 1 && x <= 9)
			break;
		cout << "�����������" << i << "��" << j << "��(���о���1��ʼ����)��ֵ" << endl;
	}
	return x;
}

/* ��һά�����жϣ�����1-9�����־ͷ���1�����򷵻�0 */
int judge(int num[], int n)
{
	int a[10] = { 0 };  //�洢��ͬ�����Ƿ����
	int i = 0, j = 0;
	int tmp = 0;
	int sum = 0;
	for (i = 0; i < n; ++i)
	{
		tmp = num[i];
		a[tmp] = 1;  //ֻҪ���ָ������ͼ���1 
	}
	for (j = 1; j <= n; ++j)
	{
		sum += a[j];
	}
	if (sum == 9)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int main()
{
	
	int i, j, s, t;
	int fuzhu = 0; 
	int total = 0;
	int tmp[9] = { 0 };  //�ݴ�Ҫ�ж���9����
	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;
	int num[9][9] = { 0 };
	int trans_num[9][9] = { 0 };   //��ÿ��С�������Ū��һ��
	for (i = 0; i < 9; ++i)
	{
		for (j = 0; j < 9; ++j)
		{
			num[i][j] = input_num(i + 1, j + 1);
		}
	}	
	//������ɺϷ�����

	for (i = 0; i < 9; ++i)  //�ж�9���ǲ��Ƕ�����
	{
		total += judge(num[i], 9);
	}
	if (total != 9)   //�в�����ʱ������
	{
		cout << "���������Ľ�" << endl;
		return 0;
	}

	total = 0; //��ʼ��total
	for (i = 0; i < 9; ++i)  //���н��в���
	{
		for (j = 0; j < 9; ++j)
		{
			tmp[j] = num[j][i];
		}
		total += judge(tmp, 9);
	}
	if (total != 9)   //�в�����ʱ����ֹ
	{
		cout << "���������Ľ�" << endl;
		return 0;
	}

	total = 0;
	for (s = 0; s < 9; s += 3)
	{
		for (t = 0; t < 9; t += 3)
		{
			for (i = 0; i < 3; i = i + 1)   //��s,tΪ��ʼ�ĵط���ʼ �Ǹ�С����
			{
				for (j = 0; j < 3; j = j + 1)
				{
					
					tmp[fuzhu] = num[i + s][j + t];		
					fuzhu++;
				}
			}
			total += judge(tmp, 9);
			fuzhu = 0;
		}
	}
	if (total != 9)   //�в�����ʱ����ֹ
	{
		cout << "���������Ľ�" << endl;
		return 0;
	}

	cout << "�������Ľ�" << endl;
	return 0;
}