/*1951393 自动化 张儒戈*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	 
	int num1, num2, num3;
	int ge1, shi1, bai1;
	int ge2, shi2, bai2;
	int ge3, shi3, bai3;
	int cnt = 0;

	for (bai1 = 1; bai1 <= 9; bai1++) {
		for (shi1 = 1; shi1 <= 9; shi1++) {
			if (shi1 == bai1)
				continue;
			for (ge1 = 1; ge1 <= 9; ge1++) {
				if (ge1 == shi1 || ge1 == bai1)
					continue;
				for (bai2 = 1; bai2 <= 9; bai2++) {
					if (bai2 == ge1 || bai2 == shi1 || bai2 == bai1)
						continue;
					for (shi2 = 1; shi2 <= 9; shi2++) {
						if (shi2 == bai2 || shi2 == ge1 || shi2 == shi1 || shi2 == bai1)
							continue;
						for (ge2 = 1; ge2 <= 9; ge2++) {
							if (ge2 == shi2 || ge2 == bai2 || ge2 == ge1 || ge2 == shi1 || ge2 == bai1)
								continue;
							for (bai3 = 1; bai3 <= 9; bai3++) {
								if (bai3 == ge2 || bai3 == shi2 || bai3 == bai2 || bai3 == ge1 || bai3 == shi1 || bai3 == bai1)
									continue;
								for (shi3 = 1; shi3 <= 9; shi3++) {
									if (shi3 == bai3 || shi3 == ge2 || shi3 == shi2 || shi3 == bai2 || shi3 == ge1 || shi3 == shi1 || shi3 == bai1)
										continue;
									for (ge3 = 1; ge3 <= 9; ge3++) {
										if (ge3 == shi3 || ge3 == bai3 || ge3 == ge2 || ge3 == shi2 || ge3 == bai2 || ge3 == ge1 || ge3 == shi1 || ge3 == bai1)
											continue;

										num1 = bai1 * 100 + shi1 * 10 + ge1;
										num2 = bai2 * 100 + shi2 * 10 + ge2;
										num3 = bai3 * 100 + shi3 * 10 + ge3;
										if ((num1 + num2 + num3) == 1953 && num1 < num2 && num2 < num3) {
											cnt++;
											printf("No.%3d : %d+%d+%d=1953\n", cnt, num1, num2, num3);
										
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("total=%d\n", cnt);
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6lf秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);
	return 0;
}
