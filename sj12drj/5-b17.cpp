/* 1951650 信02 戴仁杰 */
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int input_judge(int a[], int n);
int num_of_char(int min, int max);
void creat(int start, char b[], char min, char max, int n, int choice);
void rerank(char src[], char dst[], int n);
void bezero(char dst[], int n);
void central(int all[], int tmp_num_of_char[], char tmparray[], char randarray[]);

/* 判断输入的参数是否合理，
   返回值：合理为0，界限不对为1，非法字符为2 */
int input_judge(int a[], int n)
{
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		cin >> a[i];    //输入
		if (cin.fail()) //输入非法
		{
			cout << "输入含有非法字符" << endl;
			return 2;
		}
	}
	if (a[0] < 12 || a[0] > 16)   //检查各种错误
	{
		cout << "密码长度[" << a[0] << "]不正确" << endl;
		return 1;
	}
	if (a[1] < 2 || a[0] < a[1])
	{
		cout << "大写字母个数[" << a[1] << "]不正确" << endl;
		return 1;
	}
	if (a[2] < 2 || a[0] < a[2])
	{
		cout << "小写字母个数[" << a[2] << "]不正确" << endl;
		return 1;
	}
	if (a[3] < 2 || a[0] < a[3])
	{
		cout << "数字个数[" << a[3] << "]不正确" << endl;
		return 1;
	}
	if (a[4] < 2 || a[0] < a[4])
	{
		cout << "其他符号个数[" << a[4] << "]不正确" << endl;
		return 1;
	}
	if (a[0] < a[1] + a[2] + a[3] + a[4])
	{
		cout << "所有字符类型之和[" << a[1] << "+" << a[2] << "+" << a[3] << "+" << a[4] << "]大于总密码长度[" << a[0] << "]" << endl;
		return 1;
	}

	return 0;  //以上情况都没发生，返回0；
}

/* 随机确定该种字符的个数,min与max为数目上下界 */
int num_of_char(int min, int max)  //上下界如下
{
	int a;
	a = rand() % (max - min + 1) + min;
	return a;
}

/* 生成n个指定范围字符，范围从min到max,存到数组b里,通过choice选择是不是其他字符 */
void creat(int start, char b[], char min, char max, int n, int choice)
{
	int i = 0;
	char tmp0 = '\0';
	//srand((unsigned int)(time(0))); //随机种子
	if (choice == 0)
	{
		for (i = start; i < n + start; ++i)
		{
			b[i] = rand() % (max - min + 1) + min;
		}
	}
	if (choice == 1)
	{
		for (i = start; i < n + start; ++i)
		{
			tmp0 = rand() % (126 - 33 + 1) + 33;  //随机生成一个可见字符
			if ((tmp0 >= 'A' && tmp0 <= 'Z') || (tmp0 >= 'a' && tmp0 <= 'z') || (tmp0 >= '0' && tmp0 <= '9'))
			{
				--i;       //退回去重新来
				continue;  //如果是大小写字母和数字就忽略
			}
			b[i] = tmp0;  //其他字符就给存进数组去
		}
	}

	return;
}

/* 调整顺序，把原有的顺序给打乱,参数n为非零字符的数目 */
void rerank(char src[], char dst[], int n)
{
	int rank_num = 0;
	int i = 0;	
	while (i < n)
	{
		rank_num = rand() % n;
		if (dst[rank_num] != '\0')
		{
			continue;    //如果该位置已经被占了，那再找一个
		}
		dst[rank_num] = src[i];
		i++;
	}
	return;
}
/* 给存储的数组置零，进行下一次存储密码 */
void bezero(char dst[], int n)
{
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		dst[i] = '\0';
	}
	return;
}

/* 中心函数，统筹调用其他函数，使得main函数更简洁 */
void central(int all[], int tmp_num_of_char[], char tmparray[], char randarray[])
{
	int i = 0, j = 0;
	for (i = 0; i < 4; ++i)
	{
		cout << all[i] << " ";
	}
	cout << all[4];
	cout << endl;
	for (j = 0; j < 10; ++j)  //重复制造十次密码
	{
		tmp_num_of_char[0] = num_of_char(all[1], all[0] - all[2] - all[3] - all[4]);
		tmp_num_of_char[1] = num_of_char(all[2], all[0] - tmp_num_of_char[0] - all[3] - all[4]);
		tmp_num_of_char[2] = num_of_char(all[3], all[0] - tmp_num_of_char[0] - tmp_num_of_char[1] - all[4]);
		tmp_num_of_char[3] = all[0] - tmp_num_of_char[0] - tmp_num_of_char[1] - tmp_num_of_char[2];
		//完成存储随机字符的数目
		creat(0, tmparray, 'A', 'Z', tmp_num_of_char[0], 0);  //填入大写
		creat(tmp_num_of_char[0], tmparray, 'a', 'z', tmp_num_of_char[1], 0);
		creat(tmp_num_of_char[0] + tmp_num_of_char[1], tmparray, '0', '9', tmp_num_of_char[2], 0);
		creat(tmp_num_of_char[0] + tmp_num_of_char[1] + tmp_num_of_char[2], tmparray, 33, 126, tmp_num_of_char[3], 1);
		rerank(tmparray, randarray, all[0]);
		cout << randarray << endl;
		bezero(randarray, all[0]);
	}
	return;
}

int main()
{
	int all[5] = { 0 }, tmp_num_of_char[4] = { 0 };
	char tmparray[17] = { '\0' };  //暂存生成的字符
	char randarray[17] = { '\0' };  //存最终的乱序字符
	int test = 0;
	cout << "请输入密码长度(12-16)，大写字母个数(≥2)，小写字母个数(≥2)，数字个数(≥2)，其它符号个数(≥2)" << endl;
	srand((unsigned int)(time(0))); //随机种子
	test = input_judge(all, 5);
	if (test)  //输入非法，直接结束
	{
		return 0;
	}
	central(all, tmp_num_of_char, tmparray, randarray);
	return 0;
}