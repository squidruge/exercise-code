/*1951393 自动化 张儒戈*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

/***************************************************************************
  函数名称：
  功    能：输入文件名
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void input_filename(char src_file[], char dst_file[])
{

	cout << "文件名以下形式均可以：" << endl;
	cout << "    a.txt：不带路径形式" << endl;
	cout << "    ..\\data\\b.dat：相对路径形式" << endl;
	cout << "    C:\\Windows\\System32\\c.dat：绝对相对路径形式" << endl;
	cout << "请输入要转换的hex格式文件名 : ";
	cin >> src_file;
	cout << "请输入转换后的文件名 : ";
	cin >> dst_file;

}

/***************************************************************************
  函数名称：
  功    能：hex转十进制 用来处理offset
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hex2dec(char offset_hex[], unsigned int* poffset)
{
	char* p = offset_hex;
	int cnt = 0;

	if (offset_hex[0]=='\0')

		return;

	while (*p != '\0') {
		p++;
	}
	
	p--;
	for (; cnt<8; p--,cnt++) {

		if (*p <= '9' && *p >= '0') {
			if (cnt == 0) {
				*poffset = 0;
			}
			*poffset +=( *p-'0')* int(pow(16,cnt));
		}
		else if (*p <= 'f' && *p >= 'a') {
			if (cnt == 0) {
				*poffset = 0;
			}
			
			*poffset += (*p - 'a' + 10) * int(pow(16, cnt));
		}

		if (p == offset_hex)
			break;

	}
}

/***************************************************************************
  函数名称：
  功    能：hex转成char字符
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hex2char(char line_hex[], char line_dec[], int* pcnt)
{
	(*pcnt) = 0;
	for (char* phex = line_hex, *pdec = line_dec; *phex != '\0'; phex++) {

		if (*phex <= '9' && *phex >= '0') {
			*pdec = *phex - '0';
		}
		else if (*phex <= 'f' && *phex >= 'a') {
			*pdec = *phex - 'a' + 10;
		}

		phex++;

		if (*phex <= '9' && *phex >= '0') {
			*pdec = (*pdec) * 16 + *phex - '0';
		}
		else if (*phex <= 'f' && *phex >= 'a') {
			*pdec = (*pdec) * 16 + *phex - 'a' + 10;
		}
		pdec++;

		(*pcnt)++;
	}

}


/***************************************************************************
  函数名称：
  功    能：把每一行所需的16进制数读入line_hex[]
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int input_hex(char line_hex[], char line[], char offset_hex[], int* pline_cnt)
{

	int i = 0, count_hex = 0;
	(*pline_cnt)++;

	for (i = 0; ; ++i)  //偏移量 
	{
		if (line[i] == EOF)
			return 0;
				
		if ((line[i] >= '0' && line[i] <= '9') || (line[i] >= 'a' && line[i] <= 'f')) {
			offset_hex[i] = line[i];
		}
		else {
			offset_hex[i]='\0';
			break;
		}
	}

	//每一行10~59是要读的16进制 
	for (i = 10; i < 59; ++i)
	{
		if ((line[i] >= '0' && line[i] <= '9') || (line[i] >= 'a' && line[i] <= 'f'))
		{
			if (line[i] == EOF)
				return 0;

			line_hex[count_hex] = line[i];
			count_hex++;

		}
	}

	return 1;
}


/***************************************************************************
  函数名称：
  功    能：置零
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void set_0(char* str, int n)
{
	for (int i = 0; i < n; i++) {
		str[i] = '\0';
	}
}

/***************************************************************************
  函数名称：main
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main(int argc, char* argv[])
{

	char src_file[128] = { '\0' }, dst_file[128] = { '\0' };// 要转化的文件名 转换后的文件名

	input_filename(src_file, dst_file);

	ifstream in(src_file, ios::in | ios::binary); //可加ios::binary

	if (in.is_open() == 0) {
		cout << "文件" << src_file << "打开失败!" << endl;
		return -1;
	}

	ofstream out(dst_file, ios::out | ios::binary); //可加ios::binary
	if (out.is_open() == 0) {
		cout << "文件" << dst_file << "打开失败!" << endl;
		in.close();
		return -1;
	}

	//这里要做处理****

	char line[128] = { '\0' };
	char line_hex[33] = { '\0' };
	char line_dec[16] = { '\0' };
	char offset_hex[33] = { '\0' };//正常情况下9即可 为防止特殊情况 设为33

	int line_cnt = -1;//记首行为0 

	int flag = 1;	//int cnt=0;//debug
	int cnt = 0;
	unsigned int offset=0xcccccccc;
	
	while (1) {
		//	cnt++;
		set_0(line_hex, 33);
		set_0(line_dec, 16);
		set_0(line, 128);
		set_0(offset_hex, 33);

		//偏移量 3435973836
		/*
		in >> hex >> offset;

		if (!in.good()) {
			if (in.eof()) {
				flag = 0;
			}
			in.clear();
		}//读到非法字符 clear 若是EOF，标记已读到文件末尾
*/
		in.read(line, 82 );//每行82 除去被int 读到的8bit

		if (!in.good()) {
			in.clear();
			flag = 0;//标记是否读到文件末尾 
		}


		if (input_hex(line_hex, line, offset_hex,&line_cnt) == 0)
			break;//读入每一行需要的16进制字符,EOF返回0

		hex2dec( offset_hex, &offset);

		if (line_cnt * 16 != offset && flag)
		{
			//偏移量不对 且未到EOF
			cout << "最左侧的偏移量0x" << setw(8) << setfill('0') << hex << offset << "不是期望值0x" << setw(8) << line_cnt * 16 << endl;

			cout << setfill(' ');
			return -1;

		}


		int cnt_byte = 0;

		//16进制转成字符
		hex2char(line_hex, line_dec, &cnt_byte);

		out.write(line_dec, cnt_byte);

		//到EOF 退出
		if (!flag) {
			break;
		}

	}


	in.close();
	out.close();

	return 0;
}
