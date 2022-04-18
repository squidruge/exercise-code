/*1951393 �Զ��� �����*/
/* ����֤ 1950095 �����졢1951347 ��������1950681 ���塢1952037 �����1952357 �����Ρ�1952756 ������ ��hex�ļ����� */
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ַ�ת��Ϊ��λ��16������ ֱ�����
  ���������
  �� �� ֵ�� 
  ˵    ����
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
  �������ƣ�
  ��    �ܣ������ļ�������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void input_filename( char filename[])
{
	cerr << "�ļ���������ʽ�����ԣ�" << endl;
	cerr << "    a.txt������·����ʽ" << endl;
	cerr << "    ..\\data\\b.dat�����·����ʽ" << endl;
	cerr << "    C : \\Windows\\System32\\c.dat���������·����ʽ" << endl;

	cerr << "�������ļ���:";
	cin.getline(filename, 512, '\n');

}
/***************************************************************************
  �������ƣ�
  ��    �ܣ����һ���ַ���Ӧ��16����
  ���������
  �� �� ֵ��
  ˵    ����
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

	ifstream in(filename, ios::in | ios::binary); //�ɼ�ios::binary


	if (in.is_open() == 0) {
		cerr << "�ļ�" << filename << "��ʧ��!" << endl;
		return -1;
	}


	char ch;//��ʱ����ַ�
	int cnt = 0;//��¼�ַ���
	char ch16[16] = { '\0' };//���ÿһ�ŵ�16���ַ�


	while (in.get(ch)) {

		cnt++;
		output(cnt, ch, ch16);

	}


	//�����һ��û��ӡ�� �������ӡ�����ַ�
	if (cnt % 16 != 0) {

		for (int i = cnt % 16 + 1; i <= 16; i++)
			cout << "   ";

		//cout << "      ";//6��
		if((cnt% 16)<=8){
			cout << "      ";//6��
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
