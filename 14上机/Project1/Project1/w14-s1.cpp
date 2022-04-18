/*1951393 自动化 张儒戈*/
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量（全局只读变量或宏定义不受此限制）
   3、最多允许添加一个函数，且需要满足要求
   ---------------------------------------------------------------------
*/

#define N	10

struct course {
	float value;	//某课程的成绩（百分制）
	float weight;	//某课程的学分（权重）
	int   gpa;	//某课程的绩点（同济规则，[0..60) - 0, [60,70) - 2, [70,80) - 3, [80-90) - 4,[90,100] - 5）
};

struct student {
	int   no;               //学号（虽然用int不够合理，此处不考虑）
	char  name[9];          //假设姓名最长4个汉字
	struct course score[3]; //数组放三门课的成绩（未使用宏定义，函数实现时，直接写3即可）
	double junji ;                    //均绩  可增加其它你认为需要增加的结构体成员（限一个），不要则删除本行
};

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：此处最多允许添加一个函数，且函数的形参、自动变量等都必须是简单变量（即不允许[]形式）
***************************************************************************/



/***************************************************************************
  函数名称：
  功    能：输入10个学生的信息
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义N
***************************************************************************/
void input(struct student* stu, int num)
{
	/* 除这两个整型变量外，本函数不再允许定义任何形式的变量
		 如果不用，允许删除，但不得增加或替换为其它形式的变量
		包括for(int k=0; )形式的新变量定义同样禁止 */
	int i, j;

	/* 函数的实现部分 */

	for (i = 0; i < num; i++) {

		cout << "请输入第"<<setw(2)<<i+1<<"个学生的信息 : ";

		cin >> stu[i].no >> stu[i].name >> stu[i].score[0].value >> stu[i].score[0].weight
			>> stu[i].score[1].value >> stu[i].score[1].weight
			>> stu[i].score[2].value >> stu[i].score[2].weight;

		//gpa;	//某课程的绩点（同济规则，[0..60) - 0, [60,70) - 2, [70,80) - 3, [80-90) - 4,[90,100] - 5）
		stu[i].junji = 0;
		for (j = 0; j < 3; j++) {

			
			if (stu[i].score[j].value <= 100 && stu[i].score[j].value >= 90) {
				stu[i].score[j].gpa = 5;
			}
			else if (stu[i].score[j].value >= 80) {
				stu[i].score[j].gpa = 4;
			}
			else if (stu[i].score[j].value >= 70) {
				stu[i].score[j].gpa = 3;
			}
			else if (stu[i].score[j].value >= 60) {
				stu[i].score[j].gpa = 2;
			}
			else if (stu[i].score[j].value < 60) {
				stu[i].score[j].gpa = 0;
			}
			stu[i].junji += (double)stu[i].score[j].gpa * stu[i].score[j].weight;//累加 绩点*权重 循环结束再除总权重
	
		}
		stu[i].junji/= ((double)stu[i].score[0].weight + stu[i].score[1].weight + stu[i].score[2].weight);//计算均绩
	}

}

/***************************************************************************
  函数名称：
  功    能：输出基本信息
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义N
***************************************************************************/
void output_base(struct student* stu, int num)
{
	/* 除这两个指针变量外，本函数不再允许定义任何形式的变量
		 如果不用，允许删除，但不得增加或替换为其它形式的变量
		包括for(int i=0; )形式的新变量定义同样禁止 */
	struct student* ps;
	struct course* pc;

	/* 函数的实现部分，不允许任何形式的[]出现 */

	cout << endl;
	cout << "10个学生的成绩为" << endl;
	cout << "序号 学号    姓名     绩点1 权重1 绩点2 权重2 绩点3 权重3 平均绩点" << endl;
	cout << "==================================================================" << endl;

	for (ps = stu; ps - stu < num; ps++) {
		cout << setiosflags(ios::left) << setw(4) << ps - stu + 1 << " ";
		cout << setiosflags(ios::left) << setw(7) << ps->no << " ";
		cout << setiosflags(ios::left) << setw(8) << ps->name << " ";
		for (pc = ps->score; pc - ps->score < 3; pc++) {
			cout << setiosflags(ios::left) << setw(5) << pc->gpa << " ";
			cout << setiosflags(ios::left) << setw(5) << pc->weight << " ";
		}
		cout << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(3) << setw(8) << ps->junji << endl;
		cout << resetiosflags(ios::fixed);

	}

}

/***************************************************************************
  函数名称：
  功    能：输出绩点最高的学生（可能有并列）
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义N
***************************************************************************/
void output_max(struct student* stu, int num)
{
	/* 本函数中允许定义各种类型的简单变量，但不允许定义数组 */
	cout << endl;
	cout << "10个学生的成绩为" << endl;
	cout << "序号 学号    姓名     绩点1 权重1 绩点2 权重2 绩点3 权重3 平均绩点" << endl;
	cout << "==================================================================" << endl;

	double junji_max = 0.0;
	struct student* ps;
	struct course* pc;

	for (ps = stu; ps - stu < num; ps++) {
		if (ps->junji > junji_max) {
			junji_max = ps->junji;
		}
	}

	for (ps = stu; ps - stu < num; ps++) {
		if (ps->junji == junji_max) {
			cout << setiosflags(ios::left) << setw(4) << ps - stu + 1 << " ";
			cout << setiosflags(ios::left) << setw(7) << ps->no << " ";
			cout << setiosflags(ios::left) << setw(8) << ps->name << " ";
			for (pc = ps->score; pc - ps->score < 3; pc++) {
				cout << setiosflags(ios::left) << setw(5) << pc->gpa << " ";
				cout << setiosflags(ios::left) << setw(5) << pc->weight << " ";
			}
			cout << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(3) << setw(8) << ps->junji << endl;
			cout << resetiosflags(ios::fixed);

		}

	}

}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	struct student stu[N];

	input(stu, 10);		//输入10个学生的信息
	output_base(stu, 10);	//输出10个学生的基本信息
	output_max(stu, 10);	//输出最高（可能有多个）

	return 0;
}

/*
测试数据，复制到cmd即可，姓名随机抓取，无任何特殊含义（测试时，不限于这一组）

1950083	刘智宇 76.5 4 82 5 52 2
1950641	黄智文 63 4 49 1 87 6
1950894	吴霓衫 56 3 76 4 69 5
1951220	伊啸 44.5 2 83.5 4 87 6
1951748	罗力信 91 4 43.5 1 66 3
1952398	唐超 79 6 85.5 3 62 2
1953463	郭卫冉 86 3 63 3 77.5 4
1953634	孟令森 49.5 3 86 6 93.5 3
1954131	顾洪州 81.5 2 64.5 3 87 4
1954263	宋子铭 73 3 62 2 85 5

*/