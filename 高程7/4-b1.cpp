/*1951393 �Զ��� �����*/
#include <iostream>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */
 
/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
	case 0:
		if (flag_of_zero)	//�˱��ʲô��˼������˼��
			cout << "��";
		break;
	case 1:
		cout << "Ҽ";
		break;
	case 2:
		cout << "��";
		break;
	case 3:
		cout << "��";
		break;
	case 4:
		cout << "��";
		break;
	case 5:
		cout << "��";
		break;
	case 6:
		cout << "½";
		break;
	case 7:
		cout << "��";
		break;
	case 8:
		cout << "��";
		break;
	case 9:
		cout << "��";
		break;
	default:
		cout << "error";
		break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/

int main()
{
	/* ������� */

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
			cout << "ʰ";
		daxie(yi, 0);

		cout << "��";
	}

	bool flag_wan = qianwan || baiwan || shiwan || wan;

	if (flag_wan) {
		daxie(qianwan, flag_yi && baiwan);
		if (qianwan)
			cout << "Ǫ";
		daxie(baiwan, (flag_yi || qianwan) && shiwan);
		if (baiwan)
			cout << "��";
		daxie(shiwan, (flag_yi || qianwan || baiwan) && wan);
		if (shiwan)
			cout << "ʰ";
		daxie(wan, 0);
		cout << "��";
	}

	bool flag_yuan = qian || bai || shi || yuan;

	if (flag_yuan) {
		daxie(qian, (flag_yi || flag_wan) && bai);
		if (qian)
			cout << "Ǫ";

		daxie(bai, (flag_yi || flag_wan || qian) && shi);
		if (bai)
			cout << "��";

		daxie(shi, (flag_yi || flag_wan || qian || bai) && yuan);
		if (shi)
			cout << "ʰ";


		//daxie(yuan, !(flag_yi || flag_wan || flag_yuan || jiao || fen));

		//cout << "Բ";
	}

	if (flag_yi || flag_wan || flag_yuan || jiao || fen) {
		daxie(yuan, 0);
		if (flag_yi || flag_wan || flag_yuan)
			cout << "Բ";
	}
	else {
		daxie(yuan, 1);
		cout << "Բ��";
	}

	/*
	if (flag_yi || flag_wan || flag_yuan) {
		cout << "Բ";
	}
	*/

	if (jiao || fen) {
		daxie(jiao, flag_yi || flag_wan || flag_yuan);
		if (jiao)
			cout << "��";
		if (fen) {
			daxie(fen, 0);
			cout << "��";
		}
		else {
			cout << "��";
		}
	}
	else {
		if (flag_yi || flag_wan || flag_yuan) {
			cout << "��";
		}


	}
	cout << endl;


	return 0;
}
