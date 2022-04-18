/*1951393 自动化 张儒戈*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>	//用getch
#include <fstream>
#include <cstring>
using namespace std;

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

int main(int argc, char* argv[])
{

	char filename[512] = { '\0' };
	char file_str[1024] = { '\0' };
	cerr << "文件名以下形式均可以：" << endl;
	cerr << "    a.txt：不带路径形式" << endl;
	cerr << "    ..\\data\\b.dat：相对路径形式"<< endl;
	cerr << "    C : \\Windows\\System32\\c.dat：绝对相对路径形式"<< endl;


	cerr << "请输入文件名:" ;
	cin.getline(filename, 512,'\n');

	int i = 0;
	char *pstr=file_str,*pfile=filename;
	
	while (*pfile != '\0') {
		*pstr=*pfile;
		
		if (*pfile == '\\') {
			*pstr++;
			*pstr=*pfile;
		}

		pstr++;
		pfile++;
	}
	

	ifstream in(file_str, ios::in | ios::binary); //可加ios::binary

	if (in.is_open() == 0) {
		cerr << "文件" << filename << "打开失败!" << endl;
		return -1;
	}
	char ch;
	int cnt = 0;
	char ch16[16] = { '\0' };

	while (in.get(ch)) {
		cnt++;

		if ((cnt % 16)==1) {
			cout << setfill('0')<<setw(8)<<hex <<(cnt-1) << "  ";
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

	for (int i = cnt % 16+1; i <= 16; i++)
		cout << "   ";

	cout << "      ";

	for (int i = 0; i < cnt % 16; i++) {
		if (ch16[i] >= 33 && ch16[i] <= 126) {
			cout << ch16[i];
		}
		else {
			cout << ".";
		}
	}
	cout << endl;
//可能会多打一个 记得改 


	in.close();

	return 0;
}
