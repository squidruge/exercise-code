/* 1951650 信02 戴仁杰 */
#include <iostream>
using namespace std;

int input_num(int i, int j)
{
	int x = -1;
	while (1)
	{
		cin >> x;
		if (cin.fail())
		{
			cout << "请重新输入第" << i << "行" << j << "列(行列均从1开始计数)的值" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (x >= 1 && x <= 9)
			break;
		cout << "请重新输入第" << i << "行" << j << "列(行列均从1开始计数)的值" << endl;
	}
	return x;
}

/* 给一维数组判断，满足1-9都出现就返回1，否则返回0 */
int judge(int num[], int n)
{
	int a[10] = { 0 };  //存储不同数字是否出现
	int i = 0, j = 0;
	int tmp = 0;
	int sum = 0;
	for (i = 0; i < n; ++i)
	{
		tmp = num[i];
		a[tmp] = 1;  //只要出现该数，就记做1 
	}
	for (j = 1; j <= n; ++j)
	{
		sum += a[j];
	}
	if (sum == 9)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int main()
{
	
	int i, j, s, t;
	int fuzhu = 0; 
	int total = 0;
	int tmp[9] = { 0 };  //暂存要判定的9个数
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	int num[9][9] = { 0 };
	int trans_num[9][9] = { 0 };   //把每个小方块里的弄成一行
	for (i = 0; i < 9; ++i)
	{
		for (j = 0; j < 9; ++j)
		{
			num[i][j] = input_num(i + 1, j + 1);
		}
	}	
	//以上完成合法输入

	for (i = 0; i < 9; ++i)  //判断9行是不是都满足
	{
		total += judge(num[i], 9);
	}
	if (total != 9)   //行不满足时，跳出
	{
		cout << "不是数独的解" << endl;
		return 0;
	}

	total = 0; //初始化total
	for (i = 0; i < 9; ++i)  //对列进行操作
	{
		for (j = 0; j < 9; ++j)
		{
			tmp[j] = num[j][i];
		}
		total += judge(tmp, 9);
	}
	if (total != 9)   //列不满足时，终止
	{
		cout << "不是数独的解" << endl;
		return 0;
	}

	total = 0;
	for (s = 0; s < 9; s += 3)
	{
		for (t = 0; t < 9; t += 3)
		{
			for (i = 0; i < 3; i = i + 1)   //从s,t为初始的地方开始 那个小方块
			{
				for (j = 0; j < 3; j = j + 1)
				{
					
					tmp[fuzhu] = num[i + s][j + t];		
					fuzhu++;
				}
			}
			total += judge(tmp, 9);
			fuzhu = 0;
		}
	}
	if (total != 9)   //列不满足时，终止
	{
		cout << "不是数独的解" << endl;
		return 0;
	}

	cout << "是数独的解" << endl;
	return 0;
}