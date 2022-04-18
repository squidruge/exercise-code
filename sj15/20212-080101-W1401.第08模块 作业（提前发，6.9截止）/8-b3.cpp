/*1951393 �Զ��� �����*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

/***************************************************************************
  �������ƣ�
  ��    �ܣ������ļ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
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

/***************************************************************************
  �������ƣ�
  ��    �ܣ�hexתʮ���� ��������offset
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�
  ��    �ܣ�hexת��char�ַ�
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�
  ��    �ܣ���ÿһ�������16����������line_hex[]
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int input_hex(char line_hex[], char line[], char offset_hex[], int* pline_cnt)
{

	int i = 0, count_hex = 0;
	(*pline_cnt)++;

	for (i = 0; ; ++i)  //ƫ���� 
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

	//ÿһ��10~59��Ҫ����16���� 
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
  �������ƣ�
  ��    �ܣ�����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void set_0(char* str, int n)
{
	for (int i = 0; i < n; i++) {
		str[i] = '\0';
	}
}

/***************************************************************************
  �������ƣ�main
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char* argv[])
{

	char src_file[128] = { '\0' }, dst_file[128] = { '\0' };// Ҫת�����ļ��� ת������ļ���

	input_filename(src_file, dst_file);

	ifstream in(src_file, ios::in | ios::binary); //�ɼ�ios::binary

	if (in.is_open() == 0) {
		cout << "�ļ�" << src_file << "��ʧ��!" << endl;
		return -1;
	}

	ofstream out(dst_file, ios::out | ios::binary); //�ɼ�ios::binary
	if (out.is_open() == 0) {
		cout << "�ļ�" << dst_file << "��ʧ��!" << endl;
		in.close();
		return -1;
	}

	//����Ҫ������****

	char line[128] = { '\0' };
	char line_hex[33] = { '\0' };
	char line_dec[16] = { '\0' };
	char offset_hex[33] = { '\0' };//���������9���� Ϊ��ֹ������� ��Ϊ33

	int line_cnt = -1;//������Ϊ0 

	int flag = 1;	//int cnt=0;//debug
	int cnt = 0;
	unsigned int offset=0xcccccccc;
	
	while (1) {
		//	cnt++;
		set_0(line_hex, 33);
		set_0(line_dec, 16);
		set_0(line, 128);
		set_0(offset_hex, 33);

		//ƫ���� 3435973836
		/*
		in >> hex >> offset;

		if (!in.good()) {
			if (in.eof()) {
				flag = 0;
			}
			in.clear();
		}//�����Ƿ��ַ� clear ����EOF������Ѷ����ļ�ĩβ
*/
		in.read(line, 82 );//ÿ��82 ��ȥ��int ������8bit

		if (!in.good()) {
			in.clear();
			flag = 0;//����Ƿ�����ļ�ĩβ 
		}


		if (input_hex(line_hex, line, offset_hex,&line_cnt) == 0)
			break;//����ÿһ����Ҫ��16�����ַ�,EOF����0

		hex2dec( offset_hex, &offset);

		if (line_cnt * 16 != offset && flag)
		{
			//ƫ�������� ��δ��EOF
			cout << "������ƫ����0x" << setw(8) << setfill('0') << hex << offset << "��������ֵ0x" << setw(8) << line_cnt * 16 << endl;

			cout << setfill(' ');
			return -1;

		}


		int cnt_byte = 0;

		//16����ת���ַ�
		hex2char(line_hex, line_dec, &cnt_byte);

		out.write(line_dec, cnt_byte);

		//��EOF �˳�
		if (!flag) {
			break;
		}

	}


	in.close();
	out.close();

	return 0;
}
