/*1951393 �Զ��� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define Num_Len 7	//ѧ����󳤶� ���鳤�� Num_Len+1
#define Name_Len 8	//������󳤶� ���鳤�� Name_Len+1
#define N 10		//ѧ������

void input(char xuehao[][Num_Len + 1], char name[][Name_Len + 1], int score[], int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf("�������%d���˵�ѧ�š��������ɼ�\n", i + 1);
		scanf("%s", xuehao[i]);
		scanf("%s", name[i]);
		scanf("%d", &(score[i]));
	}

}


void paixu(char xuehao[][Num_Len + 1], char name[][Name_Len + 1], int score[], int n)
{
	int i, j;
	// i��ʾð�ݷ���ѭ�� j��ʾð�ݷ���ѭ��

	char temp1[Num_Len + 1] = { '\0' };
	char temp2[Name_Len + 1] = { '\0' };
	int temp3 = 0;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - (i + 1); j++)
			if (strcmp(xuehao[j], xuehao[j + 1]) < 0) {

				strcpy(temp1, xuehao[j]);
				strcpy(xuehao[j], xuehao[j + 1]);
				strcpy(xuehao[j + 1], temp1);

				strcpy(temp2, name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], temp2);

				temp3 = score[j];
				score[j] = score[j + 1];
				score[j + 1] = temp3;


			}

	}
}

void output(char xuehao[][Num_Len + 1], char name[][Name_Len + 1], int score[], int n)
{
	int i;

	printf("\n����������:\n");

	for (i = 0; i < n; i++) {
		//printf("����������:\n");

		if (score[i] < 60 && score[i] >= 0) {
			printf("%s %s %d\n", name[i], xuehao[i], score[i]);

		}
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����������롢���õݹ麯�������
***************************************************************************/
int main()
{

	char xuehao[N][Num_Len + 1];
	char name[N][Name_Len + 1];
	int score[N];

	input(xuehao, name, score, N);
	paixu(xuehao, name, score, N);
	output(xuehao, name, score, N);

	return 0;
}