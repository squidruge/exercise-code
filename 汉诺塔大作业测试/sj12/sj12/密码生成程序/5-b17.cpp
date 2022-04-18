/*1951393 自动化 张儒戈*/
#include <iostream>
#define MAX 16
#define MIN 12
#include <time.h>
using namespace std;


//打乱按序生成的密码
void daluan(int len, char pass_word[MAX + 1])
{
	int i;

	for (int j = 0; j < 10; j++) {
		for (i = 0; i < len; i++) {

			char temp;
			int swap_num;//要交换的位置
			swap_num = rand() % 10;
			temp = pass_word[i];
			pass_word[i] = pass_word[swap_num];
			pass_word[swap_num] = temp;

		}
	}
	 
}


//生成密码
void mima(char pass_word[MAX + 1], int len, int  up_num, int low_num, int  figure_num, int other_num)
{
	int cnt = 0;

	int i;

	//大写
	for (i = 0; i < up_num; i++) {
		pass_word[cnt++] = 'A' + rand() % ('Z' - 'A' + 1);
	}

	//小写
	for (i = 0; i < low_num; i++) {
		pass_word[cnt++] = 'a' + rand() % ('z' - 'a' + 1);
	}

	//数字
	for (i = 0; i < figure_num; i++) {
		pass_word[cnt++] = '0' + rand() % 10;
	}

	//其他
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

	//随意排序
	daluan(len, pass_word);

}



int main()
{

	char pass_word[MAX + 1] = { '\0' };

	int len, up_num, low_num, figure_num, other_num;

	int cnt = 0;//记录数组中已生成的字符
	//int cnt[4] = { 0 };//记录四种字符的当前数量
	cout << "请输入密码长度(12-16)，大写字母个数(≥2)，小写字母个数(≥2)，数字个数(≥2)，其它符号个数(≥2)" << endl;

	cin >> len >> up_num >> low_num >> figure_num >> other_num;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "输入含有非法字符." << endl;
		return 0;

	}

	if (len<MIN || len>MAX) {
		cout << "密码长度[" << len << "]不正确" << endl;
		return 0;
	}

	if (up_num < 2) {
		cout << "大写字母个数[" << up_num << "]不正确" << endl;

		return 0;
	}

	if (low_num < 2) {
		cout << "小写字母个数[" << low_num << "]不正确" << endl;
		return 0;
	}
	if (figure_num < 2) {
		cout << "数字个数[" << figure_num << "]不正确" << endl;
		return 0;
	}
	if (other_num < 2) {
		cout << "其它符号个数[" << other_num << "]不正确" << endl;
		return 0;
	}

	if (up_num + low_num + figure_num + other_num > len) {
		cout << "所有字符类型之和[" << up_num << "+" << low_num << "+" << figure_num << "+" << other_num << "]大于总密码长度[" << len << "]" << endl;
		return 0;
	}

	cout << len << " " << up_num << " " << low_num << " " << figure_num << " " << other_num << endl;

	int i;

	srand((unsigned int)(time(0)));

	//输出十组
	for (i = 0; i < 10; i++) {


		mima(pass_word, len, up_num, low_num, figure_num, other_num);
		cout << pass_word << endl;
	}
	 
	return 0;
}



