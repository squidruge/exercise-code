/*1951393 �Զ��� �����*/
#include <iostream>
#include <string>

#define Num_Len 7	//ѧ����󳤶� ���鳤�� Num_Len+1
#define Name_Len 8	//������󳤶� ���鳤�� Name_Len+1
#define N 10		//ѧ������

using namespace std;
void input(string xuehao[], string name[], int score[], int n)
{
	int i;

	for (i = 0; i < n; i++) {

		cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�" << endl;
		cin >> xuehao[i];
		cin >> name[i];
		cin >> score[i];
	}

}


void paixu(string xuehao[], string name[], int score[], int n)
{
	int i, j;
	// i��ʾð�ݷ���ѭ�� j��ʾð�ݷ���ѭ��

	string temp1;
	int temp2 = 0;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - (i + 1); j++)
			if (xuehao[j].compare("xuehao[j + 1]") < 0) {

				temp1 = xuehao[j];
				xuehao[j] = xuehao[j + 1];
				xuehao[j + 1] = temp1;

				temp1 = name[j];
				name[j] = name[j + 1];
				name[j + 1] = temp1;

				temp2 = score[j];
				score[j] = score[j + 1];
				score[j + 1] = temp2;


			}

	}
}

void output(string xuehao[], string name[], int score[], int n)
{
	int i;

	cout << endl;
	cout << "����������:" << endl;

	for (i = 0; i < n; i++) {
		//printf("����������:\n");

		if (score[i] < 60 && score[i] >= 0) {

			cout << name[i] << " " << xuehao[i] << " " << score[i] << endl;


		}
	}
}

int main()
{
	string xuehao[N];
	string name[N];
	int score[N];

	input(xuehao, name, score, N);
	paixu(xuehao, name, score, N);
	output(xuehao, name, score, N);



	return 0;
}