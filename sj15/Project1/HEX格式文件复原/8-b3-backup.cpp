/*1951393 �Զ��� �����*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>	//��getch
#include <fstream>
#include <cstring>

using namespace std;


void input_filename(char src_file[], char dst_file[])
{

	cout << "�ļ���������ʽ�����ԣ�" << endl;
	cout << "    a.txt������·����ʽ" << endl;
	cout << "    ..\\data\\b.dat�����·����ʽ" << endl;
	cout << "    C:\\Windows\\System32\\c.dat���������·����ʽ" << endl;
	cout << "������Ҫת����hex��ʽ�ļ��� : ";
	cin >> src_file;
	cout << "������ת������ļ��� : ";
	cin >> dst_file;

}


void hex2dec(char order_hex[], int* poffset)
{
	
	for (char* phex = order_hex; *phex!=' '; phex++) {
		
		if (*phex <= '9' && *phex >= '0') {
			if(phex == order_hex){
			* poffset=0;
		}
			* poffset = (* poffset)*16+ *phex - '0';
		}
		else if (*phex <= 'f' && *phex >= 'a') {
			if(phex == order_hex){
			* poffset=0;
		}
			* poffset = (* poffset) * 16 +*phex - 'a' + 10;
		}else{
			return ;
		}

	}
}



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



//����һ��16������
int input_hex(char line_hex[], char order_hex[] ,char line[],int *pline_cnt)
{
	int i = 0, count_hex = 0;
	(*pline_cnt)++;
/*
	for (i = 0; line[i]!=' '; ++i){
		
			if (line[i] == EOF)
				return 0;

			order_hex[i] = line[i];
	
	}*/
	
	for (i = 10-8; i < 59-8; ++i)
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


void file_name2str(char* pfile, char* pstr)
{

	while (*pfile != '\0') {
		*pstr = *pfile;

		if (*pfile == '\\') {
			pstr++;
			*pstr = *pfile;
		}

		pstr++;
		pfile++;
	}
}


void set_0(char* str, int n)
{
	for (int i = 0; i < n; i++) {
		str[i] = '\0';
	}
}


int main(int argc, char* argv[])
{

	char src_file[128] = { '\0' }, dst_file[128] = { '\0' };// Ҫת�����ļ��� ת������ļ���
	char src_str[256] = { '\0' }, dst_str[256] = { '\0' };	// �ַ�����ʽ Ҫת�����ļ��� ת������ļ���

	input_filename(src_file, dst_file);


	file_name2str(src_file, src_str);

	ifstream in(src_str, ios::in | ios::binary); //�ɼ�ios::binary

	if (in.is_open() == 0) {
		cout << "�ļ�" << src_file << "��ʧ��!" << endl;
		return -1;
	}

	file_name2str(dst_file, dst_str);

	ofstream out(dst_str, ios::out | ios::binary); //�ɼ�ios::binary
	if (out.is_open() == 0) {
		cout << "�ļ�" << dst_file << "��ʧ��!" << endl;
		in.close();
		return -1;
	}

	//����Ҫ������****

	char line[128] = { '\0' };
	char line_hex[33] = { '\0' };
	char line_dec[16] = { '\0' };
	char order_hex[33] = { '\0' };

	int line_cnt = -1;//������Ϊ0 

	int flag = 1;	//int cnt=0;//debug
	
	while (1) {
		//	cnt++;
		set_0(line_hex, 32);
		set_0(line_dec, 16);
		set_0(line, 128);
		set_0(order_hex, 9);

		int cnt = 0;
		unsigned int offset=3435973836;
		
		in>>hex>>offset;
		
		if (!in.good()) {
			in.clear();
			//offset=3435973836;
		}
	//	in.seekg(-1, ios::cur);
		in.read(line, 82-8);

		if (!in.good()) {
			in.clear();
			//break;
			flag = 0;//����Ƿ�����ļ�ĩβ 
		}
		
			if (input_hex(line_hex,order_hex, line,&line_cnt) == 0)
			break;
		//λ�ÿ��ܲ���
	//	hex2dec(order_hex,  &offset);
		
		if (line_cnt * 16 != offset)
		{
			cout <<  "������ƫ����0x"<<setw(8)<<setfill('0')<<hex <<offset<<"��������ֵ0x"<<setw(8)<< line_cnt  * 16 << endl;
			
			cout<<setfill(' ');
			return -1;
		}



		int cnt_byte = 0;

		hex2char(line_hex, line_dec, &cnt_byte);

		out.write(line_dec, cnt_byte);

		if (!flag) {
			break;
		}

	}


	in.close();
	out.close();

	return 0;
}
