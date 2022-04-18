/*1951393 自动化 张儒戈*/
#include <iostream>
#include <cmath>
using namespace std;

double cross_product(double a[], double b[], double c[])//叉乘
{
	double t;
	//公式:s=(x1-x3)*(y2-y3)-(x2-x3)*(y1-y3)  
	//当s>0时,p1,p2,p3三个点呈逆时针  
	//当s<0时,p1,p2,p3三个点呈顺时针  
	//t = (a[0] - c[0]) * (b[1] - c[1]) - (b[0] - c[0]) * (a[1] - c[1]);
	t = (b[0] - a[0]) * (c[1] - b[1]) - (c[0] - b[0]) * (b[1] - a[1]);
	return t;
}

//是否全为正数
bool is_positive(double a[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] < 1e-6) {
			return false;
		}
	}
	return true;
}
//是否全为负数
bool is_negative(double a[], int n) {
	for (int i = 0; i < n; i++) {
		if (-a[i] < 1e-6) {
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	double coor[7][2] = { 0 };//各点的坐标
	double sub_0[6][2] = { 0 };//各点减去coor[0][0]
	double prod[7] = { 0 };//叉乘结果
	double s = 0;

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

	cout << "请按顺时针/逆时针方向输入"<<n<<"个顶点的x,y坐标：" << endl;

	for (int i = 0; i < n; i++) {



		while (1) {
			cout << "请输入第" << i + 1 << "个顶点的坐标：" << endl;
			cin >> coor[i][0] >> coor[i][1];   //读入x的方式必须是 cin>>int型变量，不允许其他方式
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}

			break;

		}
	}

	for (int i = 0; i < n - 2; i++) {
		prod[i] = cross_product(coor[i], coor[i + 1], coor[i + 2]);
	}
	prod[n - 2] = cross_product(coor[n - 2], coor[n - 1], coor[0]);
	prod[n - 1] = cross_product(coor[n - 1], coor[0], coor[1]);


	for (int i = 0; i < n - 1; ++i)
	{
		sub_0[i][0] = coor[i + 1][0] - coor[0][0];
		sub_0[i][1] = coor[i + 1][1] - coor[0][1];
	}
	//以上完成对分块用向量的计算
	for (int i = 0; i < n - 2; ++i)
	{
		s+=0.5 * fabs(sub_0[i][0] * sub_0[i+1][1] - sub_0[i+1][0] * sub_0[i][1]);
		
	}
	//利用向量叉乘求面积，完成相加过程

	if (is_positive(prod,n) || is_negative(prod,n)) {

		/*
		for (int i = 0; i < n; i++) {
			s += 0.5 *fabs(prod[i]);
		}*/
		cout << "凸" << n << "边形的面积=" << s<<endl;
	}
	else {
		cout << "不是凸" << n << "边形" << endl;;
	}

	
	return 0;
}