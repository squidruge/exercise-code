/*1951393 自动化 张儒戈*/

/* 允许按需加入系统的宏定义、需要的头文件等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;

#define MAX_STU_NUM			150	//约定最大人数为150人（两轮的总和，包括退选、补选）
#define MAX_NAME_LEN			20	//姓名的最大长度不超过9个汉字
#define MAX_FILENAME_LEN		256	//文件名的最大长度

class stu_list;
/* stu_info 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_info {
private:
	int  stu_no;			//学号
	char stu_name[MAX_NAME_LEN];	//姓名

	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */
	char round_1[5] = { '\0' };
	char round_2[5] = { '\0' };
	friend class stu_list;

public:
	/* 本类不允许定义任何的公有数据成员、成员函数 */
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];

	/* 允许按需加入private数据成员和成员函数 */
	int cnt=0;

public:
	int read(const char* filename, const int append = 0);	//从文件中读入选课信息并进行处理，第2个参数值为0表示覆盖方式，1表示追加方式
	int print(const char* prompt = NULL);			//打印当前读入的选课名单

	/* 允许按需加入其它public成员函数 */

};

/* --- 此处给出上面两个类的成员函数的体外实现 --- */
int stu_list::read(const char* filename, const int append)
{
	//stu_info temp[MAX_STU_NUM + 1];//暂存读取的数据
	stu_info temp;//暂存


	ifstream in(filename, ios::in);

	if (in.is_open() == 0) {
		cerr << "文件[" << filename << "]打开失败" << endl;
		return -1;
	}
	if (append == 0) {

		cnt = 0;

		//输入
		while (1) {
			cnt++;

			in >> stu[cnt].stu_no;
			if (in.eof()) {
				cnt--;
				in.clear();
				break;
			}


			in >> stu[cnt].stu_name;
			if (in.eof()) {
				cnt--;
				in.clear();

				break;
			}

			strcpy(stu[cnt].round_1, "Y");
			strcpy(stu[cnt].round_2, "退课");

		}


		//排序
		for (int i = 1; i <= cnt; i++) {
			for (int j = i + 1; j <= cnt; j++) {
				if (stu[i].stu_no > stu[j].stu_no) {
					temp.stu_no = stu[i].stu_no;
					stu[i].stu_no = stu[j].stu_no;
					stu[j].stu_no = temp.stu_no;

					strcpy(temp.stu_name, stu[i].stu_name);
					strcpy(stu[i].stu_name, stu[j].stu_name);
					strcpy(stu[j].stu_name, temp.stu_name);
				}
			}
		}

	}
	else {
		while (1) {
			//将append的内容暂存入temp
			in >> temp.stu_no;
			if (in.eof()) {
				in.clear();
				break;
			}

			in >> temp.stu_name;
			if (in.eof()) {
				in.clear();
				break;
			}
			//如果前一轮无数据
			if (cnt == 0) {
				strcpy(stu[cnt + 1].stu_name, temp.stu_name);
				stu[cnt + 1].stu_no = temp.stu_no;
				strcpy(stu[cnt + 1].round_1, "/");
				strcpy(stu[cnt + 1].round_2, "补选");
				cnt++;
				continue;
			}
			//判断两轮都选了的
			int i;
			for (i = 1; i <= cnt; i++) {
				if (stu[i].stu_no == temp.stu_no) {
					strcpy(stu[i].round_2, "Y");
					break;
				}
			}
			//用i作为哨兵判断
			if (cnt >= i)
				continue;

			//要添加的位置如果是第一个
			for (int j = 1; j <= cnt; j++) {

				if (j == 1 && temp.stu_no < stu[j].stu_no)
				{
					for (int k = cnt; k >= j; k--) {
						strcpy(stu[k + 1].stu_name, stu[k].stu_name);
						stu[k + 1].stu_no = stu[k].stu_no;
						strcpy(stu[k + 1].round_1, stu[k].round_1);
						strcpy(stu[k + 1].round_2, stu[k].round_2);
					}

					strcpy(stu[1].stu_name, temp.stu_name);
					stu[1].stu_no = temp.stu_no;
					strcpy(stu[1].round_1, "/");
					strcpy(stu[1].round_2, "补选");
					cnt++;
					break;
				}


				//两学号之间，或大于最后一个
				if (temp.stu_no > stu[j].stu_no) {

					if (cnt != j && temp.stu_no < stu[j + 1].stu_no) {
						for (int k = cnt; k >= j + 1; k--) {
							strcpy(stu[k + 1].stu_name, stu[k].stu_name);
							stu[k + 1].stu_no = stu[k].stu_no;
							strcpy(stu[k + 1].round_1, stu[k].round_1);
							strcpy(stu[k + 1].round_2, stu[k].round_2);
						}
					}

					if (temp.stu_no < stu[j + 1].stu_no || cnt == j) {
						strcpy(stu[j + 1].stu_name, temp.stu_name);
						stu[j + 1].stu_no = temp.stu_no;
						strcpy(stu[j + 1].round_1, "/");
						strcpy(stu[j + 1].round_2, "补选");
						cnt++;
						break;
					}

				}

			}//end of for

		}//end of while
	}//end of else

	in.close();
	return 1;
}
 
int stu_list::print(const char* prompt)
{

	cout << prompt << endl;
	cout << "===========================================" << endl;
	cout << "序号 学号    姓名             第一轮 第二轮" << endl;
	cout << "===========================================" << endl;
	for (int i = 1; i <= cnt; i++) {
		cout << setiosflags(ios::left) << setw(5) << i
			<< setw(8) << stu[i].stu_no << setw(17) << stu[i].stu_name
			<< setw(7) << stu[i].round_1 << setw(7) << stu[i].round_2 << endl;

	}
	printf("===========================================\n");
	return 1;
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
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	cin >> file1;
	cout << "请输入后一轮选课的数据文件 : ";
	cin >> file2;

	stu_list list;

	/* 读入第一个数据文件 */
	if (list.read(file1) < 0)
		return -1;

#if 0
	/* 打开这个宏定义，可以打印首轮读入的选课名单，用于调试 */
	list.print("前一轮选课名单");
	cout << endl << endl;
#endif

	/* 读入第二个数据文件，参数2的值为1表示追加方式 */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("最终选课名单");

	return 0;
}