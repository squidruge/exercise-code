/*1951393 自动化 张儒戈*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：按需增加一个或多个函数，但是所有增加的函数中不允许任何形式的循环
				 定义符号常量
				 定义const型变量
		不允许 ：定义全局变量
   ----------------------------------------------------------------------------------- */
/***************************************************************************
	函数名称：正向或反向打印三角塔的某一行序列 
	功    能：
	输入参数：order - 0 ：正序打印
			  order - 1 ：倒序打印
	返 回 值：
	说    明：
  ***************************************************************************/
void print_line(char start_ch, char end_ch, int order)
{

	if (order) {
		if (end_ch - start_ch >= 0) {
			cout << end_ch;
			//cout << " ";
			print_line(start_ch, end_ch - 1, order);

		}
	}
	else {
		if (end_ch - start_ch >= 0) {
			print_line(start_ch, end_ch - 1, order);
			cout << end_ch;
		}

	}

}

/***************************************************************************
  函数名称：
  功    能：正向或反向打印三角塔
  输入参数：order - 0 ：正三角形塔
			order - 1 ：倒三角形塔
  返 回 值：
  说    明：
***************************************************************************/
void print_tower(char start_ch, char end_ch, int order)
{


	/* 按需实现，函数中不允许任何形式的循环，不允许定义静态局部变量 */
	if (order == 0) {
		if (end_ch - start_ch >= 0) {

			cout << setfill(' ') << setw(end_ch - start_ch + 1);
			print_line('A' + 1, start_ch, 1);
			cout << 'A';
			print_line('A' + 1, start_ch, 0);
			cout << endl;
			print_tower(start_ch + 1, end_ch, order);

		}

	}
	else {
		if (end_ch - start_ch >= 0) {

			print_line(start_ch , end_ch -1, 0);
			cout << end_ch;
			print_line(start_ch , end_ch -1, 1);
			cout << endl;
			
			cout << setfill(' ') << setw(start_ch-'A'+2 );
			print_tower(start_ch + 1, end_ch, order);
			//cout << " ";

		}
	}


}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效) */
	while (1) {
		cout << "请输入结束字符(A~Z)" << endl;
		end_ch = getchar();			//读缓冲区第一个字符
		while (getchar() != '\n')	//清空缓冲区剩余字符
			;
		if (end_ch >= 'A' && end_ch <= 'Z')
			break;
	}

	/* 正三角字母塔(中间为A) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl;/* 按字母塔最大长度输出= */
	cout << "正三角字母塔" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl;/* 按字母塔最大长度输出= */
	print_tower('A', end_ch, 0);
	cout << endl;

	/* 倒三角字母塔(两边为A) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl; /* 按字母塔最大长度输出= */
	cout << "倒三角字母塔" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl; /* 按字母塔最大长度输出= */
	print_tower('A', end_ch, 1);
	cout << endl;

	return 0;
}
