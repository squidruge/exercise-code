/* 1951650 信02 戴仁杰 */
#include <iostream>
using namespace std;

void eat_firstline();
int input_second(int ch[], int n);
void input_secret(char secret[][25], int n);
void count_4_chars(char secret[][25], int count_chars[][4], int n, int lenth);
int judge_secret(char secret[][25], int n, int second[]);


/* 吃掉第一行直到结束 */
void eat_firstline()
{
	char c;
	while ((c = getchar()) != EOF && c != '\n')  //吃掉第一行
		;
	return;
}

/* 读取第二行到参数串内，并判断是否合法，合法返回0，非法返回1 */
int input_second(int ch[], int n)
{
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		cin >> ch[i];
		if (cin.fail())  //读到非法字符了，直接返回0，表示错误
		{
			return 1;
		}
		if (ch[i] < 2)  //数字不对，返回错误
		{
			return 1;
		}
	}
	if (ch[0] >= 12 && ch[0] <= 16 && ch[1] + ch[2] + ch[3] + ch[4] <= ch[0])
	{
		return 0;
	}
	return 1;   //前式不满足，返回1
}

/* 将密码串读入字符数组 */
void input_secret(char secret[][25], int n)
{
	int i = 0;
	char c = 'a';
	while ((c = getchar()) != EOF && c != '\n')  //吃掉第二行最后的换行符
		;
	for (i = 0; i < n; ++i)
	{
		cin.getline(secret[i], 17);   //默认读入的最大是16个字符
	}
	return;
}

/* 计数各类字符有多少,存入count_chars数组中 */
void count_4_chars(char secret[][25], int count_chars[][4], int n, int lenth)
{
	int i = 0, j = 0;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < lenth; ++j)
		{
			if (secret[i][j] >= 'A' && secret[i][j] <= 'Z') //大写字母++
			{
				count_chars[i][0]++;
				continue;
			}
			if (secret[i][j] >= 'a' && secret[i][j] <= 'z') //小写字母++
			{
				count_chars[i][1]++;
				continue;
			}
			if (secret[i][j] >= '0' && secret[i][j] <= '9') //数字++
			{
				count_chars[i][2]++;
				continue;
			}
			if (secret[i][j] >= 33 && secret[i][j] <= 126) //满足为可见字符条件且不满足上边三个式子
			{
				count_chars[i][3]++;
			}
		}
	}
	return;
}

/* 判断密码是否合法,主要传入参数为目标字符数组，参数数组 
   返回值为0说明正确，返回值为1说明错误*/
int judge_secret(char secret[][25], int n, int second[])
{
	int j = 0;
	int lenth_tmp = 0;
	int count_chars[10][4] = { 0 };  //保存4类字符的数目
	for (j = 0; j < n; ++j)  //检查长度是否正确
	{
		lenth_tmp = strlen(secret[j]);
		if (lenth_tmp != second[0])
		{
			return 1;
		}
	}

	count_4_chars(secret, count_chars, 10, second[0]);  //统计好各种字符
	for (j = 0; j < n; ++j)
	{
		if (count_chars[j][0] < second[1])  //大写字母不够
		{
			return 1;
		}
		if (count_chars[j][1] < second[2])  //小写字母不够
		{
			return 1;
		}
		if (count_chars[j][2] < second[3])  //数字不够
		{
			return 1;
		}
		if (count_chars[j][3] < second[4])  //其他字符不够
		{
			return 1;
		}
		if (count_chars[j][0] + count_chars[j][1] + count_chars[j][2] + count_chars[j][3] != second[0])
		{
			return 1;   //字符加起来不等于总长度
		}
	}
	return 0;
}

int main()
{
	char secret[10][25] = { '\0' };  //存放后续的密码串
	int second[5] = { 0 };  //存放第二行的参数
	int judge1 = 0, judge2 = 0;
	eat_firstline();
	judge1 = input_second(second, 5);
	if (judge1)
	{
		cout << "错误" << endl;
		return 0;
	}
	input_secret(secret, 10);  //读入密码串
	judge2 = judge_secret(secret, 10, second);
	if (judge2)
	{
		cout << "错误" << endl;
		return 0;
	}
	cout << "正确" << endl;
	return 0;
}