/*1951393 自动化 张儒戈*/
#include <iostream>
using namespace std;

#define  N  81	/* 长度小于80的字符串+空字符 */

/***************************************************************************
  函数名称：
  功    能：判断是否为回文
  输入参数：
  返 回 值：
  说    明：返回1表示是
***************************************************************************/
int is_huiwen(char* str)
{
	char* p0 = str, * p1 = str;
	int ret = 1;

	//p1指向换行符
	while (*p1 != '\n') {
		p1++;
	}

	*p1-- = '\0';//替换为尾零，并指向最后一个有效字符


	//空串返回默认的1，非空继续判断
	if (*str != '\0') {

		while (p0 <= p1) {
			if (*p0++ != *p1--) {
				ret = 0;
				break;
			}
		}

	}

	return ret;
}


int main()
{
	char str[N];
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(str, N, stdin);

	if (is_huiwen(str)) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

	return 0;
}


