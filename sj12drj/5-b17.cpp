/* 1951650 ��02 ���ʽ� */
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int input_judge(int a[], int n);
int num_of_char(int min, int max);
void creat(int start, char b[], char min, char max, int n, int choice);
void rerank(char src[], char dst[], int n);
void bezero(char dst[], int n);
void central(int all[], int tmp_num_of_char[], char tmparray[], char randarray[]);

/* �ж�����Ĳ����Ƿ����
   ����ֵ������Ϊ0�����޲���Ϊ1���Ƿ��ַ�Ϊ2 */
int input_judge(int a[], int n)
{
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		cin >> a[i];    //����
		if (cin.fail()) //����Ƿ�
		{
			cout << "���뺬�зǷ��ַ�" << endl;
			return 2;
		}
	}
	if (a[0] < 12 || a[0] > 16)   //�����ִ���
	{
		cout << "���볤��[" << a[0] << "]����ȷ" << endl;
		return 1;
	}
	if (a[1] < 2 || a[0] < a[1])
	{
		cout << "��д��ĸ����[" << a[1] << "]����ȷ" << endl;
		return 1;
	}
	if (a[2] < 2 || a[0] < a[2])
	{
		cout << "Сд��ĸ����[" << a[2] << "]����ȷ" << endl;
		return 1;
	}
	if (a[3] < 2 || a[0] < a[3])
	{
		cout << "���ָ���[" << a[3] << "]����ȷ" << endl;
		return 1;
	}
	if (a[4] < 2 || a[0] < a[4])
	{
		cout << "�������Ÿ���[" << a[4] << "]����ȷ" << endl;
		return 1;
	}
	if (a[0] < a[1] + a[2] + a[3] + a[4])
	{
		cout << "�����ַ�����֮��[" << a[1] << "+" << a[2] << "+" << a[3] << "+" << a[4] << "]���������볤��[" << a[0] << "]" << endl;
		return 1;
	}

	return 0;  //���������û����������0��
}

/* ���ȷ�������ַ��ĸ���,min��maxΪ��Ŀ���½� */
int num_of_char(int min, int max)  //���½�����
{
	int a;
	a = rand() % (max - min + 1) + min;
	return a;
}

/* ����n��ָ����Χ�ַ�����Χ��min��max,�浽����b��,ͨ��choiceѡ���ǲ��������ַ� */
void creat(int start, char b[], char min, char max, int n, int choice)
{
	int i = 0;
	char tmp0 = '\0';
	//srand((unsigned int)(time(0))); //�������
	if (choice == 0)
	{
		for (i = start; i < n + start; ++i)
		{
			b[i] = rand() % (max - min + 1) + min;
		}
	}
	if (choice == 1)
	{
		for (i = start; i < n + start; ++i)
		{
			tmp0 = rand() % (126 - 33 + 1) + 33;  //�������һ���ɼ��ַ�
			if ((tmp0 >= 'A' && tmp0 <= 'Z') || (tmp0 >= 'a' && tmp0 <= 'z') || (tmp0 >= '0' && tmp0 <= '9'))
			{
				--i;       //�˻�ȥ������
				continue;  //����Ǵ�Сд��ĸ�����־ͺ���
			}
			b[i] = tmp0;  //�����ַ��͸��������ȥ
		}
	}

	return;
}

/* ����˳�򣬰�ԭ�е�˳�������,����nΪ�����ַ�����Ŀ */
void rerank(char src[], char dst[], int n)
{
	int rank_num = 0;
	int i = 0;	
	while (i < n)
	{
		rank_num = rand() % n;
		if (dst[rank_num] != '\0')
		{
			continue;    //�����λ���Ѿ���ռ�ˣ�������һ��
		}
		dst[rank_num] = src[i];
		i++;
	}
	return;
}
/* ���洢���������㣬������һ�δ洢���� */
void bezero(char dst[], int n)
{
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		dst[i] = '\0';
	}
	return;
}

/* ���ĺ�����ͳ���������������ʹ��main��������� */
void central(int all[], int tmp_num_of_char[], char tmparray[], char randarray[])
{
	int i = 0, j = 0;
	for (i = 0; i < 4; ++i)
	{
		cout << all[i] << " ";
	}
	cout << all[4];
	cout << endl;
	for (j = 0; j < 10; ++j)  //�ظ�����ʮ������
	{
		tmp_num_of_char[0] = num_of_char(all[1], all[0] - all[2] - all[3] - all[4]);
		tmp_num_of_char[1] = num_of_char(all[2], all[0] - tmp_num_of_char[0] - all[3] - all[4]);
		tmp_num_of_char[2] = num_of_char(all[3], all[0] - tmp_num_of_char[0] - tmp_num_of_char[1] - all[4]);
		tmp_num_of_char[3] = all[0] - tmp_num_of_char[0] - tmp_num_of_char[1] - tmp_num_of_char[2];
		//��ɴ洢����ַ�����Ŀ
		creat(0, tmparray, 'A', 'Z', tmp_num_of_char[0], 0);  //�����д
		creat(tmp_num_of_char[0], tmparray, 'a', 'z', tmp_num_of_char[1], 0);
		creat(tmp_num_of_char[0] + tmp_num_of_char[1], tmparray, '0', '9', tmp_num_of_char[2], 0);
		creat(tmp_num_of_char[0] + tmp_num_of_char[1] + tmp_num_of_char[2], tmparray, 33, 126, tmp_num_of_char[3], 1);
		rerank(tmparray, randarray, all[0]);
		cout << randarray << endl;
		bezero(randarray, all[0]);
	}
	return;
}

int main()
{
	int all[5] = { 0 }, tmp_num_of_char[4] = { 0 };
	char tmparray[17] = { '\0' };  //�ݴ����ɵ��ַ�
	char randarray[17] = { '\0' };  //�����յ������ַ�
	int test = 0;
	cout << "���������볤��(12-16)����д��ĸ����(��2)��Сд��ĸ����(��2)�����ָ���(��2)���������Ÿ���(��2)" << endl;
	srand((unsigned int)(time(0))); //�������
	test = input_judge(all, 5);
	if (test)  //����Ƿ���ֱ�ӽ���
	{
		return 0;
	}
	central(all, tmp_num_of_char, tmparray, randarray);
	return 0;
}