/*1951393 �Զ��� �����*/
#include <iostream>
#include <string>
//�ɰ���������Ҫ��ͷ�ļ�
using namespace std;

const char chistr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
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
	/* --���������Ҫ������ --*/
	double num;
	int shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen;


	cout << "������[0-100��)֮�������:" << endl;
	cin >> num;
	cout << "��д�����:" << endl;


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

			result.append("ʰ");
		daxie(yi, 0);
		if (yi)
			result.append("��");

	}

	bool flag_wan = qianwan || baiwan || shiwan || wan;

	if (flag_wan) {
		daxie(qianwan, flag_yi && baiwan);
		if (qianwan)
			result.append("Ǫ");

		daxie(baiwan, (flag_yi || qianwan) && shiwan);
		if (baiwan)
			result.append("��");

		daxie(shiwan, (flag_yi || qianwan || baiwan) && wan);
		if (shiwan)
			result.append("ʰ");

		daxie(wan, 0);
		result.append("��");

	}

	bool flag_yuan = qian || bai || shi || yuan;


	if (flag_yuan) {
		daxie(qian, (flag_yi || flag_wan) && bai);
		if (qian)
			result.append("Ǫ");

		daxie(bai, (flag_yi || flag_wan || qian) && shi);
		if (bai)
			result.append("��");

		daxie(shi, (flag_yi || flag_wan || qian || bai) && yuan);
		if (shi)
			result.append("ʰ");


		//daxie(yuan, !(flag_yi || flag_wan || flag_yuan || jiao || fen));

		//cout << "Բ";
	}

	if (flag_yi || flag_wan || flag_yuan || jiao || fen) {
		daxie(yuan, 0);
		if (flag_yi || flag_wan || flag_yuan)
			result.append("Բ");

	}
	else {
		daxie(yuan, 1);
		result.append("Բ��");

	}

	/*
	if (flag_yi || flag_wan || flag_yuan) {
		cout << "Բ";
	}
	*/

	if (jiao || fen) {
		daxie(jiao, flag_yi || flag_wan || flag_yuan);
		if (jiao)


			result.append("��");
		if (fen) {
			daxie(fen, 0);
			result.append("��");

		}
		else {
			result.append("��");

		}
	}
	else {
		if (flag_yi || flag_wan || flag_yuan) {
			result.append("��");
		}


	}




	cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ���������֮ǰ�������κ���ʽ�Ĳ������ */
	return 0;
}