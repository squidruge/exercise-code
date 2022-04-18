/* 1951650 信02 戴仁杰 */
#include <iostream>
using namespace std;

#define  N  10	/* 假设最多转换10个数字 */

/* 不允许再定义其它函数、全局变量 */

int main()
{
	/* 如果有不需要的变量，允许删除，但不允许添加或替换为其它类型的变量 */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* 上面的定义不准动(删除不需要的变量除外)，下面为程序的具体实现，要求不得再定义任何变量、常量、常变量 */
	cout << "请输入间隔含有若干正负数字的字符串" << endl;
	#if (__GNUC__)
		gets(str);
	#elif (_MSC_VER)
		gets_s(str, 256);
	#endif
	p = str;
	pnum = a;
	pa = a;
	while (*p != '\0' && pnum - pa < 10)
	{
		is_num = 0;
		while (*p >= '0' && *p <= '9')
		{
			*pnum = *pnum * 10 + *p - '0';
			p++;
			is_num = 1;   //将此处赋值为1
		}
		if (is_num)
		{
			pnum++;
			--p;  //减去上边的++p，避免重复加
		}
		++p;
	}
	cout << "共有" << pnum - pa << "个整数" << endl;
	for (pa = a; pa < pnum; ++pa)
	{
		cout << *pa << " ";
	}
	cout << endl;
	return 0;
}