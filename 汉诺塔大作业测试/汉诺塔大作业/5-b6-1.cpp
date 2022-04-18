/*1951393 自动化 张儒戈*/
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、仅允许hanoi中定义一个静态局部变量
   3、允许添加用于输入层数、起始/目标柱的函数，函数中允许使用循环处理错误输入
   4、如果输入用函数进行，则main中不允许出现任何形式的循环（while、do-while、for、if-goto）
	  如果输入在main中进行，则main中允许出现循环
   --------------------------------------------------------------------- */
int cnt = 0;
int topA = 0, topB = 0, topC = 0;
int A[10] = { 0 }, B[10] = { 0 }, C[10] = { 0 };

   /***************************************************************************
	 函数名称：
	 功    能：打印n层汉诺塔的移动顺序
	 输入参数：int n：层数
			   char src：起始柱
			   char tmp：中间柱
			   char dst：目标柱
	 返 回 值：
	 说    明：1、函数名、形参、返回类型均不准动
			   2、本函数不允许出现任何形式的循环
			   3、允许定义一个静态局部变量
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{


	if (n == 1) {

		cout << "第" << setw(4) << ++cnt << "步(" << setw(2) << n << "): "  << src << "-->" << dst<<" ";

		switch (src)
		{
		case 'A':
			switch (dst)
			{
			case 'B':
				B[topB++] =A[--topA];
				break;
			case 'C':
				C[topC++] = A[--topA];
				break;
			default:
				break;
			}

			break;
		case 'B':
			switch (dst)
			{
			case 'A':
				A[topA++] = B[--topB];
				break;
			case 'C':
				C[topC++] =B[--topB];
				break;
			default:
				break;
			}
			break;
		case 'C':
			switch (dst)
			{
			case 'B':
				B[topB++] = C[--topC];
				break;
			case 'A':
				A[topA++] =C[--topC];
				break;
			default:
				break;
			}

			break;
		default:
			break;
		}

		cout << "A:";
		for (int i = 0; i < 10; i++) {
			if (i < topA) {
				cout << setw(2) << A[i];
			}
			else {
				cout << "  ";
			}
		}

		cout << " B:";
		for (int i = 0; i < 10; i++) {
			if (i < topB) {
				cout << setw(2) << B[i];
			}
			else {
				cout << "  ";
			}
		}

		cout << " C:";
		for (int i = 0; i < 10; i++) {
			if (i < topC) {
				cout << setw(2) << C[i];
			}
			else {
				cout << "  ";
			}
		}

		cout << endl;
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		cout << "第" << setw(4) << ++cnt << "步(" << setw(2) << n << "): "<< src << "-->" << dst<<" ";
		switch (src)
		{
		case 'A':
			switch (dst)
			{
			case 'B':
				B[topB++] = A[--topA];
				break;
			case 'C':
				C[topC++] = A[--topA];
				break;
			default:
				break;
			}

			break;
		case 'B':
			switch (dst)
			{
			case 'A':
				A[topA++] = B[--topB];
				break;
			case 'C':
				C[topC++] = B[--topB];
				break;
			default:
				break;
			}

	
			break;
		case 'C':
			switch (dst)
			{
			case 'B':
				B[topB++] = C[--topC];
				break;
			case 'A':
				A[topA++] = C[--topC];
				break;
			default:
				break;
			}

			break;
		default:
			break;
		}

		cout << "A:";
		for (int i = 0; i < 10; i++) {
			if (i < topA) {
				cout <<setw(2)<< A[i] ;
			}
			else {
				cout << "  "  ;
			}
		}

		cout << " B:";
		for (int i = 0; i < 10; i++) {
			if (i < topB) {
				cout << setw(2) << B[i];
			}
			else {
				cout << "  "  ;
			}
		}

		cout << " C:";
		for (int i = 0; i <10; i++) {
			if (i < topC) {
				cout << setw(2) << C[i];
			}
			else {
				cout << "  "  ;
			}
		}
		cout << endl;
	
		hanoi(n - 1, tmp, src, dst);
		
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：完成输入(或调用输入函数)、调用递归函数
***************************************************************************/
int main()
{
	int n;
	char src, dst, tmp = 'A';

	while (1) {
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> n;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		cin.ignore(1024, '\n');
		if (n >= 1 && n <= 10) {
			break;
		}

	}

	while (1) {
		cout << "请输入起始柱(A-C)" << endl;
		cin >> src;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');

			continue;
		}
		cin.ignore(1024, '\n');
		if (src == 'A' || src == 'B' || src == 'C') {
			//cin.ignore(1024, '\n');
			break;
		}
		if (src == 'a' || src == 'b' || src == 'c') {
			src += ('A' - 'a');
			//cin.ignore(1024, '\n');
			break;
		}

	}


	while (1) {
		cout << "请输入目标柱(A-C)" << endl;
		cin >> dst;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		cin.ignore(1024, '\n');

		if (dst == 'A' || dst == 'B' || dst == 'C') {
			//cin.ignore(1024, '\n');
			if (dst == src) {
				cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
			}
			else {
				break;
			}
		}

		if (dst == 'a' || dst == 'b' || dst == 'c') {
			dst += ('A' - 'a');
			//cin.ignore(1024, '\n');
			if (dst == src) {
				cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
			}
			else {
				break;
			}
		}


	}

	while (tmp == dst || tmp == src)
		tmp++;

	switch (src)
	{
	case 'A':
		topA = n;
		for (int i = 0; i < n; i++) {
			A[i] = n - i;
		}
		break;
	case 'B':
		topB = n;
		for (int i = 0; i < n; i++) {
			B[i] = n - i;
		}
		break;
	case 'C':
		topC = n;
		for (int i = 0; i < n; i++) {
			C[i] = n - i;
		}
		break;
	default:
		break;
	}
	cout << "初始:" <<setw(15)<<" ";
	cout << "A:";
	for (int i = 0; i < 10; i++) {
		if (i < topA) {
			cout << setw(2) << A[i];
		}
		else {
			cout << "  ";
		}
	}

	cout << " B:";
	for (int i = 0; i < 10; i++) {
		if (i < topB) {
			cout << setw(2) << B[i];
		}
		else {
			cout << "  ";
		}
	}

	cout << " C:";
	for (int i = 0; i < 10; i++) {
		if (i < topC) {
			cout << setw(2) << C[i];
		}
		else {
			cout << "  ";
		}
	}
	cout << endl;
	hanoi(n, src, tmp, dst);

	return 0;
} 