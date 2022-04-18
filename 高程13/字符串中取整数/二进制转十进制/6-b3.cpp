/*1951393 自动化 张儒戈*/
#include <iostream>
using namespace std;

#define  N  33	/* 长度不超过32字符串+空字符 */

/***************************************************************************
  函数名称：
  功    能：判断是否为回文
  输入参数：
  返 回 值：
  说    明：返回1表示是
***************************************************************************/
unsigned int B2D(char*bin)
{
	unsigned int DEC = 0;

	//char* begin = bin, * end = bin;
	char* p = bin;

	while ( *p!= '\0') {
		DEC = DEC * 2 + *p-'0';
		p++;
	}

	return DEC;
}


int main()
{
	char bin[N] = { '\0' };

	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin >> bin;

	cout << B2D(bin) << endl;

	return 0;
}


