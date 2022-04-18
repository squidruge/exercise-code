/*1951393 自动化 张儒戈*/
#include <iostream>
#include <string>

#define Num_Len 7	//学号最大长度 数组长度 Num_Len+1
#define Name_Len 8	//名字最大长度 数组长度 Name_Len+1
#define N 10		//学生总数

using namespace std;
void input(string xuehao[], string name[], int score[], int n)
{
	int i;

	for (i = 0; i < n; i++) {

		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> xuehao[i];
		cin >> name[i];
		cin >> score[i];
	}

}


void paixu(string xuehao[], string name[], int score[], int n)
{
	int i, j;
	// i表示冒泡法外循环 j表示冒泡法内循环

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
	cout << "不及格名单:" << endl;

	for (i = 0; i < n; i++) {
		//printf("不及格名单:\n");

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