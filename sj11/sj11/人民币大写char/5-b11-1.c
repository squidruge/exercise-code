/*1951393 �Զ��� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//�ɰ���������Ҫ��ͷ�ļ�
#include <string.h>
const char chistr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */

char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

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
			strncat(result, chistr, 2);

		}

	}
	else {

		strncat(result, chistr + 2 * num, 2);
	}

} 

int main()
{
	/* --���������Ҫ������ --*/


	double num;
	int shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen;

	printf("������[0-100��)֮�������:\n");
	scanf("%lf", &num);
	printf("��д�����:\n");

	//printf("%s", chistr);

	shiyi = (int)(num / 1.0e9);
	yi = (int)(num / 1.0e8) % 10;
	qianwan = (int)(num / 1.0e7) % 10;
	baiwan = (int)(num / 1.0e6) % 10;
	shiwan = (int)(num / 1.0e5) % 10;
	wan = (int)(num / 1.0e4) % 10;
	qian = (int)(num / 1000.0) % 10;
	bai = (int)(num / 100.0) % 10;
	shi = (int)((num - shiyi * 1.0e9 - yi * 1.0e8 - qianwan * 1.0e7) / 10) % 10;
	yuan = (int)(num - shiyi * 1.0e9 - yi * 1.0e8 - qianwan * 1.0e7) % 10;
	jiao = (int)((num - shiyi * 1.0e9 - yi * 1.0e8 - qianwan * 1.0e7 + 0.00500) * 10) % 10;
	fen = (int)((num - shiyi * 1.0e9 - yi * 1.0e8 - qianwan * 1.0e7 + 0.00500) * 100) % 10;

	int flag_yi = shiyi || yi;
	if (flag_yi) {
		daxie(shiyi, 0);
		if (shiyi)
			strcat(result, "ʰ");

		daxie(yi, 0);

		strcat(result, "��");
	}

	int flag_wan = qianwan || baiwan || shiwan || wan;

	if (flag_wan) {
		daxie(qianwan, flag_yi && baiwan);
		if (qianwan)
			strcat(result, "Ǫ");

		daxie(baiwan, (flag_yi || qianwan) && shiwan);

		if (baiwan)
			strcat(result, "��");
		daxie(shiwan, (flag_yi || qianwan || baiwan) && wan);

		if (shiwan)
			strcat(result, "ʰ");

		daxie(wan, 0);
		 
		strcat(result, "��");
	}

	int flag_yuan = qian || bai || shi || yuan;


	if (flag_yuan) {
		daxie(qian, (flag_yi || flag_wan) && bai);
		if (qian)
			strcat(result, "Ǫ");

		daxie(bai, (flag_yi || flag_wan || qian) && shi);
		if (bai)
			strcat(result, "��");

		daxie(shi, (flag_yi || flag_wan || qian || bai) && yuan);
		if (shi)
			strcat(result, "ʰ");


		//daxie(yuan, !(flag_yi || flag_wan || flag_yuan || jiao || fen));

		//cout << "Բ";
	}

	if (flag_yi || flag_wan || flag_yuan || jiao || fen) {
		daxie(yuan, 0);
		if (flag_yi || flag_wan || flag_yuan)
			strcat(result, "Բ");
	}
	else {
		daxie(yuan, 1);

		strcat(result, "Բ��");
	}

	/*
	if (flag_yi || flag_wan || flag_yuan) {
		cout << "Բ";
	}
	*/

	if (jiao || fen) {
		daxie(jiao, flag_yi || flag_wan || flag_yuan);
		if (jiao)

			strcat(result, "��");
		if (fen) {
			daxie(fen, 0);

			strcat(result, "��");
		}
		else {

			strcat(result, "��");
		}
	}
	else {
		if (flag_yi || flag_wan || flag_yuan) {
			strcat(result, "��");
		}


	}



	printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ���������֮ǰ�������κ���ʽ�Ĳ������ */
	return 0;
}
