/* 1951650 信02 戴仁杰 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/* 排序函数，传入三个二维数组，按照学号由大到小排序 */
void rank_stu_num(char stu_num[][8], char name[][9], int score[10])
{
	int i, j;
	char tmp_stu_num[8], tmp_name[9];
	int tmp_score;
	int now_max_order = 0;  //存储当前最大值的脚标
	for (i = 0; i < 10; ++i)
	{
		now_max_order = i;
		for (j = i; j < 10; ++j)
		{
			if (strcmp(stu_num[j], stu_num[now_max_order]) > 0)  //遇到了更大的串
			{
				now_max_order = j;
			}
		}
		strcpy(tmp_stu_num, stu_num[i]);  //将当前最左边的和最大的交换
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

/* 给三个数组输入 */
void input(char stu_num[][8], char name[][9], int score[10])
{
	int i = 0;
	for (i = 0; i < 10; ++i)
	{
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s", stu_num[i]);
		scanf("%s", name[i]);
		scanf("%d", &score[i]);
	}
	return;
}

/* 传入已经按学号排好序的数组，输出不及格名单 */
void output(char stu_num[][8], char name[][9], int score[10])
{
	int i = 0;
	printf("\n不及格名单:\n");  //打印提示信息
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
	char stu_num[10][8]; //7位学号
	char name[10][9];    //最长8字节的名字
	int score[10];   //整数成绩
	input(stu_num, name, score);
	rank_stu_num(stu_num, name, score);
	output(stu_num, name, score);
	return 0;
}