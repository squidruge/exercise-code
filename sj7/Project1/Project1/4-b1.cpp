/*1951393 自动化 张儒戈*/
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
	case 0:
		if (flag_of_zero)	//此标记什么意思请自行思考
			cout << "零";
		break;
	case 1:
		cout << "壹";
		break;
	case 2:
		cout << "贰";
		break;
	case 3:
		cout << "叁";
		break;
	case 4:
		cout << "肆";
		break;
	case 5:
		cout << "伍";
		break;
	case 6:
		cout << "陆";
		break;
	case 7:
		cout << "柒";
		break;
	case 8:
		cout << "捌";
		break;
	case 9:
		cout << "玖";
		break;
	default:
		cout << "error";
		break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

int main()
{
	/* 按需完成 */

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
			cout << "拾";
		daxie(yi, 0);
		if (yi)
			cout << "亿";
	}

	bool flag_wan = qianwan || baiwan || shiwan || wan;

	if (flag_wan) {
		daxie(qianwan, flag_yi && baiwan);
		if (qianwan)
			cout << "仟";
		daxie(baiwan, (flag_yi || qianwan) && shiwan);
		if (baiwan)
			cout << "佰";
		daxie(shiwan, (flag_yi || qianwan || baiwan) && wan);
		if (shiwan)
			cout << "拾";
		daxie(wan, 0);
		cout << "万";
	}

	bool flag_yuan = qian || bai || shi || yuan;

	if (flag_yuan) {
		daxie(qian, (flag_yi || flag_wan) && bai);
		if(qian)
		cout << "仟";
		daxie(bai, (flag_yi || flag_wan || qian) && shi);
		if(bai)
		cout << "佰";
		daxie(shi, (flag_yi || flag_wan || qian || bai) && yuan);
		if(shi)
		cout << "拾";
		daxie(yuan, 0);
		cout << "圆";
	}
	if (jiao || fen) {
		daxie(jiao, flag_yi||flag_wan||flag_yuan);
		if(jiao)
		cout << "角";
		if (fen) {
			daxie(fen, 0);
			cout << "分";
		}
		else {
			cout << "整";
		}
	}
	else {
		if (flag_yi || flag_wan || flag_yuan) {
			cout << "整";
		}
		else {
			cout << "零圆整";
		}

	}



	return 0;
}
