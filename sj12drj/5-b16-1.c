/* 1951650 ��02 ���ʽ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/* ������������������ά���飬����ѧ���ɴ�С���� */
void rank_stu_num(char stu_num[][8], char name[][9], int score[10])
{
	int i, j;
	char tmp_stu_num[8], tmp_name[9];
	int tmp_score;
	int now_max_order = 0;  //�洢��ǰ���ֵ�Ľű�
	for (i = 0; i < 10; ++i)
	{
		now_max_order = i;
		for (j = i; j < 10; ++j)
		{
			if (strcmp(stu_num[j], stu_num[now_max_order]) > 0)  //�����˸���Ĵ�
			{
				now_max_order = j;
			}
		}
		strcpy(tmp_stu_num, stu_num[i]);  //����ǰ����ߵĺ����Ľ���
		strcpy(tmp_name, name[i]);
		tmp_score = score[i];
		strcpy(stu_num[i], stu_num[now_max_order]);
		strcpy(name[i], name[now_max_order]);
		score[i] = score[now_max_order];
		strcpy(stu_num[now_max_order], tmp_stu_num);
		strcpy(name[now_max_order], tmp_name);
		score[now_max_order] = tmp_score;
	}
	return;
}

/* �������������� */
void input(char stu_num[][8], char name[][9], int score[10])
{
	int i = 0;
	for (i = 0; i < 10; ++i)
	{
		printf("�������%d���˵�ѧ�š��������ɼ�\n", i + 1);
		scanf("%s", stu_num[i]);
		scanf("%s", name[i]);
		scanf("%d", &score[i]);
	}
	return;
}

/* �����Ѿ���ѧ���ź�������飬������������� */
void output(char stu_num[][8], char name[][9], int score[10])
{
	int i = 0;
	printf("\n����������:\n");  //��ӡ��ʾ��Ϣ
	for (i = 0; i < 10; ++i)
	{
		if (score[i] < 60)
		{
			printf("%s %s %d\n", name[i], stu_num[i], score[i]);
		}
	}
	return;
}

int main()
{
	char stu_num[10][8]; //7λѧ��
	char name[10][9];    //�8�ֽڵ�����
	int score[10];   //�����ɼ�
	input(stu_num, name, score);
	rank_stu_num(stu_num, name, score);
	output(stu_num, name, score);
	return 0;
}