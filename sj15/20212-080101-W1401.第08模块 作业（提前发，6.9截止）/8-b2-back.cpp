/*1951393 �Զ��� �����*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>	//��getch
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
	cerr << "�ļ���������ʽ�����ԣ�" << endl;
	cerr << "    a.txt������·����ʽ" << endl;
	cerr << "    ..\\data\\b.dat�����·����ʽ"<< endl;
	cerr << "    C : \\Windows\\System32\\c.dat���������·����ʽ"<< endl;


	cerr << "�������ļ���:" ;
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
	

	ifstream in(file_str, ios::in | ios::binary); //�ɼ�ios::binary

	if (in.is_open() == 0) {
		cerr << "�ļ�" << filename << "��ʧ��!" << endl;
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
//���ܻ���һ�� �ǵø� 


	in.close();

	return 0;
}
