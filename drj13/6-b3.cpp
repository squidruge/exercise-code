/* 1951650 信02 戴仁杰 */
#include <iostream>
using namespace std;

/* 将2进制串转换为10进制整数返回 */
unsigned int base2to10(char* p)
{
	unsigned int num = 0;
	char* s = p;
	while (*s != '\0')
	{
		num = num * 2 + *s - '0';
		++s;
	}
	return num;
}
int main()
{
	char str[33];
	unsigned int num10 = 0;
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;	
	cin.getline(str, 33);
	num10 = base2to10(str);
	cout << num10 << endl;
	return 0;
}