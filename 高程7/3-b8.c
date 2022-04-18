/*1951393 自动化 张儒戈*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double val;
	int y50 = 0, y20 = 0, y10 = 0, y5 = 0, y1 = 0, j5 = 0, j1 = 0, f5 = 0, f2 = 0, f1 = 0;
	int cnt = 0;
	printf("请输入找零值:\n");
	scanf("%lf", &val);

	int part1 = (int)(val);
	int part2 = (int)((val + 0.001) * 100) % 100;
	//int part2 = static_cast<int>(val * 100) % 100;
	//cout << part1 << " " << part2 << endl;
	
	if (part1 >= 50) {
		y50 = part1 / 50;
		part1 = part1 - 50 * y50;
	}
	if (part1 >= 20) {
		y20 = part1 / 20;
		part1 = part1 - 20 * y20;
	}

	if (part1 >= 10) {
		y10 = part1 / 10;
		part1 = part1 - 10 * y10;
	}
	if (part1 >= 5) {
		y5 = part1 / 5;
		part1 = part1 - 5 * y5;
	}
	y1 = part1 / 1;

	if (part2 >= 50) {
		j5 = part2 / 50;
		part2 = part2 - 50 * j5;
	}
	if (part2 >= 10) {
		j1 = part2 / 10;
		part2 = part2 - 10 * j1;
	}
	if (part2 >= 5) {
		f5 = part2 / 5;
		part2 = part2 - 5 * f5;
	}
	if (part2 >= 2) {
		f2 = part2 / 2;
		part2 = part2 - 2 * f2;
	}

	f1 = part2;


	cnt = y50 + y20 + y10 + y5 + y1 + j5 + j1 + f5 + f2 + f1;

	printf("共%d张找零，具体如下：\n",cnt);
	if (y50) {
		printf("50元 : %d张\n", y50);
	}
	if (y20) {
		printf("20元 : %d张\n", y20);
	}
	if (y10) {
		printf("10元 : %d张\n", y10);
	}
	if (y5) {
		printf("5元  : %d张\n", y5);
	}
	if (y1) {
		printf("1元  : %d张\n", y1);
	}
	if (j5) {
		printf("5角  : %d张\n", j5);
	}
	if (j1) {
		printf("1角  : %d张\n", j1);
	}
	if (f5) {
		printf("5分  : %d张\n",f5);
	}
	if (f2) {
		printf("2分  : %d张\n",f2);
	}
	if (f1) {
		printf("1分  : %d张\n",f1);
	}
	return 0;
}