/*1951393 自动化 张儒戈*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define Num_Len 7	//学号最大长度 数组长度 Num_Len+1
#define Name_Len 8	//名字最大长度 数组长度 Name_Len+1
#define N 10		//学生总数

void input(char xuehao[][Num_Len + 1], char name[][Name_Len + 1], int score[], int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s", xuehao[i]);
		scanf("%s", name[i]);
		scanf("%d", &(score[i]));
	}

}


void paixu(char xuehao[][Num_Len + 1], char name[][Name_Len + 1], int score[], int n)
{
	int i, j;
	// i表示冒泡法外循环 j表示冒泡法内循环

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

	printf("\n不及格名单:\n");

	for (i = 0; i < n; i++) {
		//printf("不及格名单:\n");

		if (score[i] < 60 && score[i] >= 0) {
			printf("%s %s %d\n", name[i], xuehao[i], score[i]);

		}
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：完成输入、调用递归函数、输出
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