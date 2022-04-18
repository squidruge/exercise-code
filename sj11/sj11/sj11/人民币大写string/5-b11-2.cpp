/*1951393 自动化 张儒戈*/
#include <iostream>
#include <string>
//可按需增加需要的头文件
using namespace std;

const char chistr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

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

			result.append(chistr, 2);

		}

	}
	else {


		result.append(chistr + 2 * num, 2);
	}

}

int main()
{
	/* --允许添加需要的内容 --*/
	double num;
	int shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen;


	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> num;
	cout << "大写结果是:" << endl;


	shiyi = static_cast<int>(num / 1.0e9);
	yi = static_cast<int>(num / 1.0e8) % 10;
	qianwan = static_cast<int>(num / 1.0e7) % 10;
	baiwan = static_cast<int>(num / 1.0e6) % 10;
	shiwan = static_cast<int>(num / 1.0e5) % 10;
	wan = static_cast<int>(num / 1.0e4) % 10;
	qian = static_cast<int>(num / 1000.0) % 10;
	bai = static_cast<int>(num / 100.0) % 10;
	shi = static_cast<int>((num - shiyi * 1.0e9 - yi * 1.0e8 - qianwan * 1.0e7) / 10) % 10;
	yuan = static_cast<int>(num - shiyi * 1.0e9 - yi * 1.0e8 - qianwan * 1.0e7) % 10;
	jiao = static_cast<int>((num - shiyi * 1.0e9 - yi * 1.0e8 - qianwan * 1.0e7 + 0.00500) * 10) % 10;
	fen = static_cast<int>((num - shiyi * 1.0e9 - yi * 1.0e8 - qianwan * 1.0e7 + 0.00500) * 100) % 10;

	bool flag_yi = shiyi || yi;
	if (flag_yi) {
		daxie(shiyi, 0);
		if (shiyi)

			result.append("拾");
		daxie(yi, 0);
		if (yi)
			result.append("亿");

	}

	bool flag_wan = qianwan || baiwan || shiwan || wan;

	if (flag_wan) {
		daxie(qianwan, flag_yi && baiwan);
		if (qianwan)
			result.append("仟");

		daxie(baiwan, (flag_yi || qianwan) && shiwan);
		if (baiwan)
			result.append("佰");

		daxie(shiwan, (flag_yi || qianwan || baiwan) && wan);
		if (shiwan)
			result.append("拾");

		daxie(wan, 0);
		result.append("万");

	}

	bool flag_yuan = qian || bai || shi || yuan;


	if (flag_yuan) {
		daxie(qian, (flag_yi || flag_wan) && bai);
		if (qian)
			result.append("仟");

		daxie(bai, (flag_yi || flag_wan || qian) && shi);
		if (bai)
			result.append("佰");

		daxie(shi, (flag_yi || flag_wan || qian || bai) && yuan);
		if (shi)
			result.append("拾");


		//daxie(yuan, !(flag_yi || flag_wan || flag_yuan || jiao || fen));

		//cout << "圆";
	}

	if (flag_yi || flag_wan || flag_yuan || jiao || fen) {
		daxie(yuan, 0);
		if (flag_yi || flag_wan || flag_yuan)
			result.append("圆");

	}
	else {
		daxie(yuan, 1);
		result.append("圆整");

	}

	/*
	if (flag_yi || flag_wan || flag_yuan) {
		cout << "圆";
	}
	*/

	if (jiao || fen) {
		daxie(jiao, flag_yi || flag_wan || flag_yuan);
		if (jiao)


			result.append("角");
		if (fen) {
			daxie(fen, 0);
			result.append("分");

		}
		else {
			result.append("整");

		}
	}
	else {
		if (flag_yi || flag_wan || flag_yuan) {
			result.append("整");
		}


	}




	cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，之前不允许任何形式的部分输出 */
	return 0;
}