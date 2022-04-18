/*1951393 自动化 张儒戈*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//可按需增加需要的头文件
#include <string.h>
const char chistr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */

char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void daxie(int num, int flag_of_zero)
{

	if (num == 0) {
		if (flag_of_zero) {
			strncat(result, chistr, 2);

		}

	}
	else {

		strncat(result, chistr + 2 * num, 2);
	}

} 

int main()
{
	/* --允许添加需要的内容 --*/


	double num;
	int shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen;

	printf("请输入[0-100亿)之间的数字:\n");
	scanf("%lf", &num);
	printf("大写结果是:\n");

	//printf("%s", chistr);

	shiyi = (int)(num / 1.0e9);
	yi = (int)(num / 1.0e8) % 10;
	qianwan = (int)(num / 1.0e7) % 10;
	baiwan = (int)(num / 1.0e6) % 10;
	shiwan = (int)(num / 1.0e5) % 10;
	wan = (int)(num / 1.0e4) % 10;
	qian = (int)(num / 1000.0) % 10;
	bai = (int)(num / 100.0) % 10;
	shi = (int)((num - shiyi * 1.0e9 - yi * 1.0e8 - qianwan * 1.0e7) / 10) % 10;
	yuan = (int)(num - shiyi * 1.0e9 - yi * 1.0e8 - qianwan * 1.0e7) % 10;
	jiao = (int)((num - shiyi * 1.0e9 - yi * 1.0e8 - qianwan * 1.0e7 + 0.00500) * 10) % 10;
	fen = (int)((num - shiyi * 1.0e9 - yi * 1.0e8 - qianwan * 1.0e7 + 0.00500) * 100) % 10;

	int flag_yi = shiyi || yi;
	if (flag_yi) {
		daxie(shiyi, 0);
		if (shiyi)
			strcat(result, "拾");

		daxie(yi, 0);

		strcat(result, "亿");
	}

	int flag_wan = qianwan || baiwan || shiwan || wan;

	if (flag_wan) {
		daxie(qianwan, flag_yi && baiwan);
		if (qianwan)
			strcat(result, "仟");

		daxie(baiwan, (flag_yi || qianwan) && shiwan);

		if (baiwan)
			strcat(result, "佰");
		daxie(shiwan, (flag_yi || qianwan || baiwan) && wan);

		if (shiwan)
			strcat(result, "拾");

		daxie(wan, 0);
		 
		strcat(result, "万");
	}

	int flag_yuan = qian || bai || shi || yuan;


	if (flag_yuan) {
		daxie(qian, (flag_yi || flag_wan) && bai);
		if (qian)
			strcat(result, "仟");

		daxie(bai, (flag_yi || flag_wan || qian) && shi);
		if (bai)
			strcat(result, "佰");

		daxie(shi, (flag_yi || flag_wan || qian || bai) && yuan);
		if (shi)
			strcat(result, "拾");


		//daxie(yuan, !(flag_yi || flag_wan || flag_yuan || jiao || fen));

		//cout << "圆";
	}

	if (flag_yi || flag_wan || flag_yuan || jiao || fen) {
		daxie(yuan, 0);
		if (flag_yi || flag_wan || flag_yuan)
			strcat(result, "圆");
	}
	else {
		daxie(yuan, 1);

		strcat(result, "圆整");
	}

	/*
	if (flag_yi || flag_wan || flag_yuan) {
		cout << "圆";
	}
	*/

	if (jiao || fen) {
		daxie(jiao, flag_yi || flag_wan || flag_yuan);
		if (jiao)

			strcat(result, "角");
		if (fen) {
			daxie(fen, 0);

			strcat(result, "分");
		}
		else {

			strcat(result, "整");
		}
	}
	else {
		if (flag_yi || flag_wan || flag_yuan) {
			strcat(result, "整");
		}


	}



	printf("%s\n", result);  /* 转换得到的大写结果，只允许用本语句输出，之前不允许任何形式的部分输出 */
	return 0;
}
