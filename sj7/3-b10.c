/*1951393 自动化 张儒戈*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	for (int r_num = 1; r_num <= 9; r_num++) {
		for (int c_num = 1; c_num <= r_num; c_num++) {
			printf("%dx%d=", c_num, r_num);
			printf("%-4d", (r_num * c_num));
			if (c_num == r_num)
				printf("\n");
		}

	}

	return 0;
}