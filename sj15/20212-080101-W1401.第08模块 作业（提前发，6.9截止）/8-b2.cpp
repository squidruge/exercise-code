/*1951393 自动化 张儒戈*/
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/***************************************************************************
  函数名称：
  功    能：将字符转化为两位的16进制数 直接输出
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void char2hex(char ch)
{
	if (ch <= 15 && ch >= 0) {
		cout << hex << "0" << int(ch) << " ";
	}
	else if (ch < 0) {

		cout << hex << (unsigned int)(unsigned char)ch << " ";
	}
	else {
		cout << hex << int(ch) << " ";
	}
}

/***************************************************************************
  函数名称：
  功    能：输入文件名部分
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void input_filename( char filename[])
{
	cerr << "文件名以下形式均可以：" << endl;
	cerr << "    a.txt：不带路径形式" << endl;
	cerr << "    ..\\data\\b.dat：相对路径形式" << endl;
	cerr << "    C : \\Windows\\System32\\c.dat：绝对相对路径形式" << endl;

	cerr << "请输入文件名:";
	cin.getline(filename, 512, '\n');

}
/***************************************************************************
  函数名称：
  功    能：输出一个字符对应的16进制
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void output(int cnt, char ch, char ch16[16])
{

	if ((cnt % 16) == 1) {
		cout << setfill('0') << setw(8) << hex << (cnt - 1) << "  ";
	}


	char2hex(ch);
	ch16[(cnt - 1) % 16] = ch;

	if (!(cnt % 8) && (cnt % 16)) {
		cout << "- ";
	}



	if (!(cnt % 16)) {
		cout << "    ";
		for (int i = 0; i < 16; i++) {
			if (ch16[i] >= 33 && ch16[i] <= 126) {
				cout << ch16[i];
			}
			else {
				cout << ".";
			}
		}
		cout << endl;
	}
}


int main(int argc, char* argv[])
{

	char filename[512] = { '\0' };

	input_filename(filename);

	ifstream in(filename, ios::in | ios::binary); //可加ios::binary


	if (in.is_open() == 0) {
		cerr << "文件" << filename << "打开失败!" << endl;
		return -1;
	}


	char ch;//临时存放字符
	int cnt = 0;//记录字符数
	char ch16[16] = { '\0' };//存放每一排的16个字符


	while (in.get(ch)) {

		cnt++;
		output(cnt, ch, ch16);

	}


	//若最后一排没打印完 则继续打印后续字符
	if (cnt % 16 != 0) {

		for (int i = cnt % 16 + 1; i <= 16; i++)
			cout << "   ";

		//cout << "      ";//6个
		if((cnt% 16)<=8){
			cout << "      ";//6个
		}else{
			cout << "    ";
		}


		for (int i = 0; i < cnt % 16; i++) {
			if (ch16[i] >= 33 && ch16[i] <= 126) {
				cout << ch16[i];
			}
			else {
				cout << ".";
			}
		}
		cout << endl;

	}

	in.close();

	return 0;
}
