/* 1951650 ��02 ���ʽ� */
#include <iostream>
#include <string>
using namespace std;

/* ������������������ά���飬����ѧ���ɴ�С���� */
void rank_stu_num(string stu_num[], string name[], int score[10])
{
	int i, j;
	string tmp_stu_num, tmp_name;
	int tmp_score;
	int now_max_order = 0;      //�洢��ǰ���ֵ�Ľű�
	for (i = 0; i < 10; ++i)
	{
		now_max_order = i;
		for (j = i; j < 10; ++j) 
		{
			if (stu_num[j] > stu_num[now_max_order])  //�����˸���Ĵ�
			{
				now_max_order = j;
			}
		}
		tmp_stu_num = stu_num[i];
		tmp_name = name[i];
		tmp_score = score[i];
		stu_num[i] = stu_num[now_max_order];
		name[i] = name[now_max_order];
		score[i] = score[now_max_order];
		stu_num[now_max_order] = tmp_stu_num;
		name[now_max_order] = tmp_name;
		score[now_max_order] = tmp_score;
	}
	return;
}

/* �������������� */
void input(string stu_num[], string name[], int score[10])
{
	int i = 0;
	for (i = 0; i < 10; ++i)
	{
		cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�" << endl;
		cin >> stu_num[i];
		cin >> name[i];
		cin >> score[i];
	}
	return;
}

/* �����Ѿ���ѧ���ź�������飬������������� */
void output(string stu_num[], string name[], int score[10])
{
	int i = 0;
	cout << endl << "����������:" << endl;   //��ӡ��ʾ��Ϣ  
	for (i = 0; i < 10; ++i)
	{
		if (score[i] < 60)
		{
			cout << name[i] << " " << stu_num[i] << " " << score[i] << endl;
		}
	}
	return;
}

int main()
{
	string stu_num[10], name[10];
	int score[10];
	input(stu_num, name, score);
	rank_stu_num(stu_num, name, score);
	output(stu_num, name, score);
	return 0;
}
