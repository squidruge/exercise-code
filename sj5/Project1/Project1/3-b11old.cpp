/*1951393 自动化 张儒戈*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */

	int num = 123456789;
	int num1, num2, num3;
	int temp;
	int ge1, shi1, bai1;
	int ge2, shi2, bai2;
	int ge3, shi3, bai3;
	int cnt = 0;


	bai1 = num / 100000000;
	shi1 = num / 10000000 % 10;
	ge1 = num / 1000000 % 10;
	bai2 = num / 100000 % 10;
	shi2 = num / 10000 % 10;
	ge2 = num / 1000 % 10;
	bai3 = num / 100 % 10;
	shi3 = num / 10 % 10;
	ge3 = num % 10;

	/*
	for (ge1 = 1; ge1 <= 9; ge1++) {
		for (shi1 = 1; shi1 <=9; shi1++) {
			if (shi1 != ge1) {
				for (bai1 = 1; bai1 <= 9; bai1++) {
					if(bai1!=ge1&&bai1!=shi1)
				}
			}

	}*/
/*
	for (num = 123456789; num <= 987654321; num++) {
		/*
		num1 = num / 100000000 * 100 + num / 10000000 %10* 10 + num / 1000000%10;
		num2 = num / 100000 %10* 100 + num / 10000%10 * 10 + num / 1000%10;
		num3 = num / 100%10 * 100 + num / 10%10 * 10 + num %10;
		*/

		bai1 = num / 100000000;
		shi1 = num / 10000000 % 10;
		ge1 = num / 1000000 % 10;
		bai2 = num / 100000 % 10;
		shi2 = num / 10000 % 10;
		ge2 = num / 1000 % 10;
		bai3 = num / 100 % 10;
		shi3 = num / 10 % 10;
		ge3 = num % 10;
		
		num1 = bai1 * 100 + shi1 * 10 + ge1;
		num2 = bai2 * 100 + shi2 * 10 + ge2;
		num3 = bai3 * 100 + shi3 * 10 + ge3;
		if (num1 < num2 && num2 < num3) {
			if (shi1 != ge1) {
				if (bai1 != ge1 && bai1 != shi1) {
					if (ge2 != ge1 && ge2 != shi1 && ge2 != bai1) {
						if (shi2 != ge1 && shi2 != shi1 && shi2 != bai1 && shi2 != ge2) {
							if (bai2 != ge1 && bai2 != shi1 && bai2 != bai1 && bai2 != ge2 && bai2 != shi2) {
								if (ge3 != ge1 && ge3 != shi1 && ge3 != bai1 && ge3 != ge2 && ge3 != shi2 && ge3 != bai2) {
									if (shi3 != ge1 && shi3 != shi1 && shi3 != bai1 && shi3 != ge2 && shi3 != shi2 && shi3 != bai2 && shi3 != ge3) {
										if (bai3 != ge1 && bai3 != shi1 && bai3 != bai1 && bai3 != ge2 && bai3 != shi2 && bai3 != bai2 && bai3 != ge3 && bai3 != shi3) {
											if ((num1 + num2 + num3) == 1953) {
												cnt++;
												cout << "No." << setiosflags(ios::right) << setw(3) << cnt
													<< " : " << num1 << "+" << num2 << "+" << num3 << "=1953" << endl;
											}

										}
									}
								}
							}
						}
					}
				}
				/*
						if (ge1&&shi1&&(ge1!=shi1)&&(ge1!=bai1)&&(bai1!=shi1)) {
							for (int num2 = num1+1; num2 <= 999; num2++) {
								int ge2, shi2, bai2;
								ge2 = num2 % 10;
								shi2 = num2 / 10 % 10;
								bai2 = num2 / 100;
								if (ge2 && shi2 && (ge2 != shi2) && (ge2 != bai2) && (bai2 != shi2)) {
									for (int num3 = num2 + 1; num3 <= 999; num3++) {
										int ge3, shi3, bai3;
										ge3 = num3 % 10;
										shi3 = num3 / 10 % 10;
										bai3 = num3 / 100;
										if (ge3 && shi3 && (ge3 != shi3) && (ge3 != bai3) && (bai3 != shi3)) {
											if ((num1 + num2 + num3 )== 1953) {
												cnt++;
												cout << "No." << setiosflags(ios::right) << setw(3) << cnt
													<< " : " << num1 << "+" << num2 << "+" << num3 << "=1953" << endl;

											}
										}
									}
								}
							}
						}

					   }
		}*/
	}

	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}
