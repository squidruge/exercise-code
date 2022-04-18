/* 1951650 信02 戴仁杰 */
#include <iostream>
using namespace std;

/* 判断是不是回文串，是输出yes，否输出no */
void judge(char* p)
{
	char* pstr, * s, * e;   
	int n = 0;    //记录字符的个数
	pstr = p;
	while (*pstr != '\n')
	{
		pstr++;
	}
	*pstr = '\0';   //将回车替换为尾零
	n = pstr - p;   //统计字符的个数

	s = p;     //指向开头begin和结尾end的两个指针
	e = p + n - 1;
	while (s <= e)
	{
		if (*s != *e)
		{
			break;
		}
		s++;
		e--;
	}
	if (s <= e)  //此时说明是遇到了不等的情况，输出no
	{
		cout << "no" << endl;
	}
	else
	{
		cout << "yes" << endl;
	}
	return;
}

int main()
{
	char str[81];
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(str, 81, stdin);
	judge(str);
	return 0;
}