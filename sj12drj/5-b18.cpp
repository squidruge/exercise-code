/* 1951650 ��02 ���ʽ� */
#include <iostream>
using namespace std;

void eat_firstline();
int input_second(int ch[], int n);
void input_secret(char secret[][25], int n);
void count_4_chars(char secret[][25], int count_chars[][4], int n, int lenth);
int judge_secret(char secret[][25], int n, int second[]);


/* �Ե���һ��ֱ������ */
void eat_firstline()
{
	char c;
	while ((c = getchar()) != EOF && c != '\n')  //�Ե���һ��
		;
	return;
}

/* ��ȡ�ڶ��е��������ڣ����ж��Ƿ�Ϸ����Ϸ�����0���Ƿ�����1 */
int input_second(int ch[], int n)
{
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		cin >> ch[i];
		if (cin.fail())  //�����Ƿ��ַ��ˣ�ֱ�ӷ���0����ʾ����
		{
			return 1;
		}
		if (ch[i] < 2)  //���ֲ��ԣ����ش���
		{
			return 1;
		}
	}
	if (ch[0] >= 12 && ch[0] <= 16 && ch[1] + ch[2] + ch[3] + ch[4] <= ch[0])
	{
		return 0;
	}
	return 1;   //ǰʽ�����㣬����1
}

/* �����봮�����ַ����� */
void input_secret(char secret[][25], int n)
{
	int i = 0;
	char c = 'a';
	while ((c = getchar()) != EOF && c != '\n')  //�Ե��ڶ������Ļ��з�
		;
	for (i = 0; i < n; ++i)
	{
		cin.getline(secret[i], 17);   //Ĭ�϶���������16���ַ�
	}
	return;
}

/* ���������ַ��ж���,����count_chars������ */
void count_4_chars(char secret[][25], int count_chars[][4], int n, int lenth)
{
	int i = 0, j = 0;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < lenth; ++j)
		{
			if (secret[i][j] >= 'A' && secret[i][j] <= 'Z') //��д��ĸ++
			{
				count_chars[i][0]++;
				continue;
			}
			if (secret[i][j] >= 'a' && secret[i][j] <= 'z') //Сд��ĸ++
			{
				count_chars[i][1]++;
				continue;
			}
			if (secret[i][j] >= '0' && secret[i][j] <= '9') //����++
			{
				count_chars[i][2]++;
				continue;
			}
			if (secret[i][j] >= 33 && secret[i][j] <= 126) //����Ϊ�ɼ��ַ������Ҳ������ϱ�����ʽ��
			{
				count_chars[i][3]++;
			}
		}
	}
	return;
}

/* �ж������Ƿ�Ϸ�,��Ҫ�������ΪĿ���ַ����飬�������� 
   ����ֵΪ0˵����ȷ������ֵΪ1˵������*/
int judge_secret(char secret[][25], int n, int second[])
{
	int j = 0;
	int lenth_tmp = 0;
	int count_chars[10][4] = { 0 };  //����4���ַ�����Ŀ
	for (j = 0; j < n; ++j)  //��鳤���Ƿ���ȷ
	{
		lenth_tmp = strlen(secret[j]);
		if (lenth_tmp != second[0])
		{
			return 1;
		}
	}

	count_4_chars(secret, count_chars, 10, second[0]);  //ͳ�ƺø����ַ�
	for (j = 0; j < n; ++j)
	{
		if (count_chars[j][0] < second[1])  //��д��ĸ����
		{
			return 1;
		}
		if (count_chars[j][1] < second[2])  //Сд��ĸ����
		{
			return 1;
		}
		if (count_chars[j][2] < second[3])  //���ֲ���
		{
			return 1;
		}
		if (count_chars[j][3] < second[4])  //�����ַ�����
		{
			return 1;
		}
		if (count_chars[j][0] + count_chars[j][1] + count_chars[j][2] + count_chars[j][3] != second[0])
		{
			return 1;   //�ַ��������������ܳ���
		}
	}
	return 0;
}

int main()
{
	char secret[10][25] = { '\0' };  //��ź��������봮
	int second[5] = { 0 };  //��ŵڶ��еĲ���
	int judge1 = 0, judge2 = 0;
	eat_firstline();
	judge1 = input_second(second, 5);
	if (judge1)
	{
		cout << "����" << endl;
		return 0;
	}
	input_secret(secret, 10);  //�������봮
	judge2 = judge_secret(secret, 10, second);
	if (judge2)
	{
		cout << "����" << endl;
		return 0;
	}
	cout << "��ȷ" << endl;
	return 0;
}