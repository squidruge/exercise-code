/*1951393 �Զ��� �����*/
#include <iostream>
#define MAX 16
#define MIN 12
#include <time.h>
using namespace std;


//���Ұ������ɵ�����
void daluan(int len, char pass_word[MAX + 1])
{
	int i;

	for (int j = 0; j < 10; j++) {
		for (i = 0; i < len; i++) {

			char temp;
			int swap_num;//Ҫ������λ��
			swap_num = rand() % 10;
			temp = pass_word[i];
			pass_word[i] = pass_word[swap_num];
			pass_word[swap_num] = temp;

		}
	}
	 
}


//��������
void mima(char pass_word[MAX + 1], int len, int  up_num, int low_num, int  figure_num, int other_num)
{
	int cnt = 0;

	int i;

	//��д
	for (i = 0; i < up_num; i++) {
		pass_word[cnt++] = 'A' + rand() % ('Z' - 'A' + 1);
	}

	//Сд
	for (i = 0; i < low_num; i++) {
		pass_word[cnt++] = 'a' + rand() % ('z' - 'a' + 1);
	}

	//����
	for (i = 0; i < figure_num; i++) {
		pass_word[cnt++] = '0' + rand() % 10;
	}

	//����
	for (i = 0; i < other_num; i++) {

		char temp = '!' + rand() % (126 - 33 + 1);
		if ((temp >= 'A' && temp <= 'Z') || (temp >= 'a' && temp <= 'z') || (temp >= '0' && temp <= '9')) {
			i--;
			continue;
		}
		pass_word[cnt++] = temp;
	}

	for (i = 0; i < len - up_num - low_num - figure_num - other_num; i++) {

		pass_word[cnt++] = '!' + rand() % (126 - 33 + 1);



	}

	//��������
	daluan(len, pass_word);

}



int main()
{

	char pass_word[MAX + 1] = { '\0' };

	int len, up_num, low_num, figure_num, other_num;

	int cnt = 0;//��¼�����������ɵ��ַ�
	//int cnt[4] = { 0 };//��¼�����ַ��ĵ�ǰ����
	cout << "���������볤��(12-16)����д��ĸ����(��2)��Сд��ĸ����(��2)�����ָ���(��2)���������Ÿ���(��2)" << endl;

	cin >> len >> up_num >> low_num >> figure_num >> other_num;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "���뺬�зǷ��ַ�." << endl;
		return 0;

	}

	if (len<MIN || len>MAX) {
		cout << "���볤��[" << len << "]����ȷ" << endl;
		return 0;
	}

	if (up_num < 2) {
		cout << "��д��ĸ����[" << up_num << "]����ȷ" << endl;

		return 0;
	}

	if (low_num < 2) {
		cout << "Сд��ĸ����[" << low_num << "]����ȷ" << endl;
		return 0;
	}
	if (figure_num < 2) {
		cout << "���ָ���[" << figure_num << "]����ȷ" << endl;
		return 0;
	}
	if (other_num < 2) {
		cout << "�������Ÿ���[" << other_num << "]����ȷ" << endl;
		return 0;
	}

	if (up_num + low_num + figure_num + other_num > len) {
		cout << "�����ַ�����֮��[" << up_num << "+" << low_num << "+" << figure_num << "+" << other_num << "]���������볤��[" << len << "]" << endl;
		return 0;
	}

	cout << len << " " << up_num << " " << low_num << " " << figure_num << " " << other_num << endl;

	int i;

	srand((unsigned int)(time(0)));

	//���ʮ��
	for (i = 0; i < 10; i++) {


		mima(pass_word, len, up_num, low_num, figure_num, other_num);
		cout << pass_word << endl;
	}
	 
	return 0;
}



