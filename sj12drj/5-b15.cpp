/* 1951650 信02 戴仁杰 */
#include <iostream>
using namespace std;

/* 检查输入的字符是不是指定类型，通过参数选择被判断的字符和，要判断什么
   如果是指定的东西，就返回1，否则返回0
*/
int check(char ch, char choice)
{
	if (choice == 'u'&&ch>='A'&&ch<='Z')  //判断大写
	{
		return 1;
	}
	if (choice == 'l' && ch >= 'a' && ch <= 'z')  //判断小写
	{
		return 1;
	}
	if (choice == 'n' && ch >= '0' && ch <= '9')  //判断数字
	{
		return 1;
	}
	if (choice == 's' && ch == ' ')  //判断空格
	{
		return 1;
	}
	return 0;
}

int main()
{
	int i = 0, j = 0;
	int word_upper = 0, word_lower = 0, num = 0, space = 0, other = 0;
	char str[3][128];
	for (i = 0; i < 3; ++i)
	{
		cout << "请输入第" << i + 1 << "行" << endl;
		cin.getline(str[i], 128);
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; str[i][j] != '\0'; ++j)
		{
			if (check(str[i][j], 'u'))
			{
				++word_upper;
				continue;
			}
			if (check(str[i][j], 'l'))
			{
				++word_lower;
				continue;
			}
			if (check(str[i][j], 'n'))
			{
				++num;
				continue;
			}
			if (check(str[i][j], 's'))
			{
				++space;
				continue;
			}
			++other;   //啥都没遇到 就是其它
		}
	}
	cout << "大写 : " << word_upper<< endl;
	cout << "小写 : " << word_lower << endl;
	cout << "数字 : " << num << endl;
	cout << "空格 : " << space << endl;
	cout << "其它 : " << other << endl;

	return 0;
}