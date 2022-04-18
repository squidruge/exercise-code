/* 1951650 信02 戴仁杰 */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n = -1; 
	int i;
	double x[10] = { 0 };     //坐标x
	double y[10] = { 0 };     //坐标y
	double xlx[10] = { 0 };   //向量x
	double xly[10] = { 0 };   //向量y
	double chacheng[10] = { 0 };  //存放叉乘的值，用来判断是不是凸多边形
	double fkxl_x[10] = { 0 };  //存放用于多边形分块的向量x的值
	double fkxl_y[10] = { 0 };
	double s[10] = { 0 };   //存放小三角形面积
	double total = 0;   //总面积
	while (1)
	{
		cout << "请输入多边形的顶点数量(4-7)" << endl;
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (n >= 4 && n <= 7)
		{
			break;
		}
	}
	cout << "请按顺时针/逆时针方向输入5个顶点的x,y坐标：" << endl;
	for (i = 0; i < n; ++i)
	{
		while (1)
		{
			cout << "请输入第" <<i+1<<"个顶点的坐标："<< endl;
			cin >> x[i] >> y[i];
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			break;
		}
	}
	/* 以上完成了对输入合法性的检查，将合法的输入存入了数组 */

	for (i = 0; i < n-1; ++i)
	{
		xlx[i] = x[i + 1] - x[i];
		xly[i] = y[i + 1] - y[i];
	}
	xlx[n - 1] = x[0] - x[n - 1];
	xly[n - 1] = y[0] - y[n - 1];
	//以上完成对每条边向量值的计算存储
	for (i = 0; i < n-1; ++i)
	{
		chacheng[i] = xlx[i] * xly[i + 1] - xlx[i + 1] * xly[i];
	}
	chacheng[n - 1] = xlx[n - 1] * xly[0] - xlx[0] * xly[n - 1];
	//以上完成对相邻两边叉乘的运算
	for (i = 0; i < n-1; ++i)
	{
		fkxl_x[i] = x[i + 1] - x[0];
		fkxl_y[i] = y[i + 1] - y[0];
	}	
	//以上完成对分块用向量的计算
	for (i = 0; i < n - 2; ++i)
	{
		s[i] = 0.5 * fabs((fkxl_x[i] * fkxl_y[i + 1] - fkxl_x[i + 1] * fkxl_y[i]));
		total += s[i];
	}
	//利用向量叉乘求面积，完成相加过程


	if (fabs(chacheng[0]) < 1e-6)   //初始就共线了，程序结束
	{
		cout << "不是凸" << n << "边形" << endl;
		return 0;      //程序结束，判断出不是凸多边形
	}
	if (chacheng[0] < 0)
	{
		for (i = 1; i < n; ++i)
		{
			if (chacheng[i] > 0 || fabs(chacheng[i]) < 1e-6)  //与初始值异号或者为0(共线)，程序结束
			{
				cout << "不是凸" << n << "边形" << endl;
				return 0;      //程序结束，判断出不是凸多边形
			}
		}
		cout << "凸" << n << "边形的面积=" << total;
		return 0;
	}
	if (chacheng[0] > 0)
	{
		for (i = 1; i < n; ++i)
		{
			if (chacheng[i] < 0 || fabs(chacheng[i]) < 1e-6)  //与初始值异号或者为0(共线)，程序结束
			{
				cout << "不是凸" << n << "边形" << endl;
				return 0;      //程序结束，判断出不是凸多边形
			}			
		}
		cout << "凸" << n << "边形的面积=" << total;
		return 0;
	}

	return 0;
}
