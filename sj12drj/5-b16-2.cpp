/* 1951650 信02 戴仁杰 */
#include <iostream>
#include <string>
using namespace std;

/* 排序函数，传入三个二维数组，按照学号由大到小排序 */
void rank_stu_num(string stu_num[], string name[], int score[10])
{
	int i, j;
	string tmp_stu_num, tmp_name;
	int tmp_score;
	int now_max_order = 0;      //存储当前最大值的脚标
	for (i = 0; i < 10; ++i)
	{
		now_max_order = i;
		for (j = i; j < 10; ++j) 
		{
			if (stu_num[j] > stu_num[now_max_order])  //遇到了更大的串
			{
				now_max_order = j;
			}
		}
		tmp_stu_num = stu_num[i];
		tmp_name = name[i];
		tmp_score = score[i];
		stu_num[i] = stu_num[now_max_order];
		name[i] = name[now_max_order];
		score[i] = score[now_max_order];
		stu_num[now_max_order] = tmp_stu_num;
		name[now_max_order] = tmp_name;
		score[now_max_order] = tmp_score;
	}
	return;
}

/* 给三个数组输入 */
void input(string stu_num[], string name[], int score[10])
{
	int i = 0;
	for (i = 0; i < 10; ++i)
	{
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> stu_num[i];
		cin >> name[i];
		cin >> score[i];
	}
	return;
}

/* 传入已经按学号排好序的数组，输出不及格名单 */
void output(string stu_num[], string name[], int score[10])
{
	int i = 0;
	cout << endl << "不及格名单:" << endl;   //打印提示信息  
	for (i = 0; i < 10; ++i)
	{
		if (score[i] < 60)
		{
			cout << name[i] << " " << stu_num[i] << " " << score[i] << endl;
		}
	}
	return;
}

int main()
{
	string stu_num[10], name[10];
	int score[10];
	input(stu_num, name, score);
	rank_stu_num(stu_num, name, score);
	output(stu_num, name, score);
	return 0;
}
