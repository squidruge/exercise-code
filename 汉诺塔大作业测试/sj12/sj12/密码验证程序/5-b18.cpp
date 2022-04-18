/*1951393 �Զ��� �����*/
#include <iostream>
#define MAX 16
#define MIN 12

using namespace std;


/*��ȡ��һ�в�����*/
void firstline()
{
	char ch;

	while ((ch = getchar()) != EOF && ch != '\n')
		;
}

/*�жϵڶ�����������Ƿ���ȷ������ȷ����0����ȷ����1 */
int secondline(int num[], int n)
{
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		cin >> num[i];
		if (cin.fail())  //�Ƿ��ַ�������0����ʾ����
		{
			return 0;
		}
		if (num[i] < 2)  //���ֲ��ԣ�����0����ʾ����
		{
			return 0;
		}
	}

	if (num[0] >= 12 && num[0] <= 16 && num[1] + num[2] + num[3] + num[4] <= num[0])
	{
		return 1;
	}


	return 0;
}

/* �����봮�����ַ����� */
void input_password(char pass_word[][MAX + 1], int n)
{
	char ch;

	//����ڶ���ʣ��Ļ��з� 
	while ((ch = getchar()) != EOF && ch != '\n')
		;

	for (int i = 0; i < n; ++i)
	{
		//�������룬���MAX���ַ���ȱʡ���س�ֹͣ���Ҷ��� 
		cin.getline(pass_word[i], MAX + 1);
		//fgets(pass_word[i], MAX + 1, stdin);

	}

}


//��֤���� ���󷵻�0 
int yanzheng(char pass_word[MAX + 1], int len, int  up_num, int low_num, int  figure_num, int other_num)
{
	int cnt[4] = { 0 };


	int i;

	//ͳ�� 
	for (i = 0; pass_word[i] != '\0'; i++) {
		if (pass_word[i] >= 'A' && pass_word[i] <= 'Z') {
			cnt[0]++;
			continue;
		}

		if (pass_word[i] >= 'a' && pass_word[i] <= 'z') {
			cnt[1]++;
			continue;
		}

		if (pass_word[i] >= '0' && pass_word[i] <= '9') {
			cnt[2]++;
			continue;
		}

		cnt[3]++;

	}

	//�ж���������ȷ�� 
	if (cnt[0] < up_num || cnt[1] < low_num ||
		cnt[2] < figure_num || cnt[3] < other_num ||
		i < len) {

		return 0;

	}
	else {
		return 1;
	}



}



int main()
{


	char pass_word[10][MAX + 1] = { '\0' };

	int num[5];

	firstline();

	if (!secondline(num, 5)) {
		cout << "����" << endl;
		return 0;
	}

	
	input_password(pass_word, 10);


	for (int i = 0; i < 10; i++) {

		if (!yanzheng(pass_word[i], num[0], num[1], num[2], num[3], num[4])) {
			cout << "����" << endl;

			return 0;

		}


	}

	cout << "��ȷ" << endl;

	return 0;
}



