/* 1951650 ��02 ���ʽ� */
#include <iostream>
using namespace std;

/* ���������ַ��ǲ���ָ�����ͣ�ͨ������ѡ���жϵ��ַ��ͣ�Ҫ�ж�ʲô
   �����ָ���Ķ������ͷ���1�����򷵻�0
*/
int check(char ch, char choice)
{
	if (choice == 'u'&&ch>='A'&&ch<='Z')  //�жϴ�д
	{
		return 1;
	}
	if (choice == 'l' && ch >= 'a' && ch <= 'z')  //�ж�Сд
	{
		return 1;
	}
	if (choice == 'n' && ch >= '0' && ch <= '9')  //�ж�����
	{
		return 1;
	}
	if (choice == 's' && ch == ' ')  //�жϿո�
	{
		return 1;
	}
	return 0;
}

int main()
{
	int i = 0, j = 0;
	int word_upper = 0, word_lower = 0, num = 0, space = 0, other = 0;
	char str[3][128];
	for (i = 0; i < 3; ++i)
	{
		cout << "�������" << i + 1 << "��" << endl;
		cin.getline(str[i], 128);
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; str[i][j] != '\0'; ++j)
		{
			if (check(str[i][j], 'u'))
			{
				++word_upper;
				continue;
			}
			if (check(str[i][j], 'l'))
			{
				++word_lower;
				continue;
			}
			if (check(str[i][j], 'n'))
			{
				++num;
				continue;
			}
			if (check(str[i][j], 's'))
			{
				++space;
				continue;
			}
			++other;   //ɶ��û���� ��������
		}
	}
	cout << "��д : " << word_upper<< endl;
	cout << "Сд : " << word_lower << endl;
	cout << "���� : " << num << endl;
	cout << "�ո� : " << space << endl;
	cout << "���� : " << other << endl;

	return 0;
}