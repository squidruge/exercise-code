/*1951393 �Զ��� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdbool.h>
int main()
{
	double num;
	int a12, a11, a10, a9, a8, a7, a6,
		a5, a4, a3, a2, a1;	//�ɸߵ��͸�λ��

	bool flag = false;
	printf("������[0-100��)֮�������:\n");
	scanf("%lf",&num);
	printf("��д�����:\n");
 
	  
	a12 = (int)(num / 1.0e9);
	a11 = (int)(num / 1.0e8) % 10;
	a10 = (int)(num / 1.0e7) % 10;
	a9 = (int)(num / 1.0e6) % 10;
	a8 = (int)(num / 1.0e5) % 10;
	a7 = (int)(num / 1.0e4) % 10;
	a6 = (int)(num / 1000.0) % 10;
	a5 = (int)(num / 100.0) % 10;
	a4 = (int)((num - a12 * 1.0e9 - a11 * 1.0e8 - a10 * 1.0e7) / 10) % 10;
	a3 = (int)(num - a12 * 1.0e9 - a11 * 1.0e8 - a10 * 1.0e7) % 10;
	a2 = (int)((num - a12 * 1.0e9 - a11 * 1.0e8 - a10 * 1.0e7 + 0.00500) * 10) % 10;
	a1 = (int)((num - a12 * 1.0e9 - a11 * 1.0e8 - a10 * 1.0e7 + 0.00500) * 100) % 10;

	//��λ�������
	if (a12 || a11) {
		flag = true;
		switch (a12)
		{
		case 1:
			printf( "Ҽʰ");
			break;
		case 2:
			printf( "��ʰ");
			break;
		case 3:
			printf( "��ʰ");
			break;
		case 4:
			printf( "��ʰ");
			break;
		case 5:
			printf( "��ʰ");
			break;
		case 6:
			printf( "½ʰ");
			break;
		case 7:
			printf( "��ʰ");
			break;
		case 8:
			printf( "��ʰ");
			break;
		case 9:
			printf( "��ʰ");
			break;
		default:
			break;
		}
		switch (a11)
		{
		case 1:
			printf( "Ҽ");
			break;
		case 2:
			printf( "��");
			break;
		case 3:
			printf( "��");
			break;
		case 4:
			printf( "��");
			break;
		case 5:
			printf( "��");
			break;
		case 6:
			printf( "½");
			break;
		case 7:
			printf( "��");
			break;
		case 8:
			printf( "��");
			break;
		case 9:
			printf( "��");
			break;
		default:
			break;
		}
		printf("��"); 
	}



	//������λ����
	if (a10 || a9 || a8 || a7) {
		switch (a10)
		{
		case 1:
			printf( "ҼǪ");
			break;
		case 2:
			printf( "��Ǫ");
			break;
		case 3:
			printf( "��Ǫ");
			break;
		case 4:
			printf( "��Ǫ");
			break;
		case 5:
			printf( "��Ǫ");
			break;
		case 6:
			printf( "½Ǫ");
			break;
		case 7:
			printf( "��Ǫ");
			break;
		case 8:
			printf( "��Ǫ");
			break;
		case 9:
			printf( "��Ǫ");
			break;
		default:
			if (flag) {
				flag = false;
				printf( "��");

			}
			break;
		}
		if (a10) {
			flag = true;
		}

		switch (a9)
		{
		case 1:
			printf( "Ҽ��");
			break;
		case 2:
			printf( "����");
			break;
		case 3:
			printf( "����");
			break;
		case 4:
			printf( "����");
			break;
		case 5:
			printf( "���");
			break;
		case 6:
			printf( "½��");
			break;
		case 7:
			printf( "���");
			break;
		case 8:
			printf( "�ư�");
			break;
		case 9:
			printf( "����");
			break;
		default:
			if (flag) {
				flag = false;
				if (a8 || a7) {
					printf( "��");
				}
			}
			break;
		}
		if (a9) {
			flag = true;
		}


		switch (a8)
		{
		case 1:
			printf( "Ҽʰ");
			break;
		case 2:
			printf( "��ʰ");
			break;
		case 3:
			printf( "��ʰ");
			break;
		case 4:
			printf( "��ʰ");
			break;
		case 5:
			printf( "��ʰ");
			break;
		case 6:
			printf( "½ʰ");
			break;
		case 7:
			printf( "��ʰ");
			break;
		case 8:
			printf( "��ʰ");
			break;
		case 9:
			printf( "��ʰ");
			break;
		default:
			if (flag) {
				flag = false;
				if (a7) {
					printf( "��");
				}
			}
			break;
		}
		if (a8) {
			flag = true;
		}


		switch (a7)
		{
		case 1:
			printf( "Ҽ");
			break;
		case 2:
			printf( "��");
			break;
		case 3:
			printf( "��");
			break;
		case 4:
			printf( "��");
			break;
		case 5:
			printf( "��");
			break;
		case 6:
			printf( "½");
			break;
		case 7:
			printf( "��");
			break;
		case 8:
			printf( "��");
			break;
		case 9:
			printf( "��");
			break;
		default:
			break;
		}

		printf( "��");
	}
	if (a12 || a11 || a10 || a9 || a8 || a7) {
		flag = true;
	}
	else {
		flag = false;
	}


	//ǧ~Ԫ
	if (a6 || a5 || a4 || a3) {
		switch (a6)
		{
		case 1:
			printf( "ҼǪ");
			break;
		case 2:
			printf( "��Ǫ");
			break;
		case 3:
			printf( "��Ǫ");
			break;
		case 4:
			printf( "��Ǫ");
			break;
		case 5:
			printf( "��Ǫ");
			break;
		case 6:
			printf( "½Ǫ");
			break;
		case 7:
			printf( "��Ǫ");
			break;
		case 8:
			printf( "��Ǫ");
			break;
		case 9:
			printf( "��Ǫ");
			break;
		default:
			if (flag) {
				flag = false;
				printf( "��");

			}
			break;
		}
		if (a6) {
			flag = true;
		}

		switch (a5)
		{
		case 1:
			printf( "Ҽ��");
			break;
		case 2:
			printf( "����");
			break;
		case 3:
			printf( "����");
			break;
		case 4:
			printf( "����");
			break;
		case 5:
			printf( "���");
			break;
		case 6:
			printf( "½��");
			break;
		case 7:
			printf( "���");
			break;
		case 8:
			printf( "�ư�");
			break;
		case 9:
			printf( "����");
			break;
		default:
			if (flag) {
				flag = false;
				if (a4 || a3) {
					printf( "��");
				}
			}
			break;
		}
		if (a5) {
			flag = true;
		}


		switch (a4)
		{
		case 1:
			printf( "Ҽʰ");
			break;
		case 2:
			printf( "��ʰ");
			break;
		case 3:
			printf( "��ʰ");
			break;
		case 4:
			printf( "��ʰ");
			break;
		case 5:
			printf( "��ʰ");
			break;
		case 6:
			printf( "½ʰ");
			break;
		case 7:
			printf( "��ʰ");
			break;
		case 8:
			printf( "��ʰ");
			break;
		case 9:
			printf( "��ʰ");
			break;
		default:
			if (flag) {
				flag = false;
				if (a3) {
					printf( "��");
				}
			}
			break;
		}
		if (a4) {
			flag = true;
		}


		switch (a3)
		{
		case 1:
			printf( "Ҽ");
			break;
		case 2:
			printf( "��");
			break;
		case 3:
			printf( "��");
			break;
		case 4:
			printf( "��");
			break;
		case 5:
			printf( "��");
			break;
		case 6:
			printf( "½");
			break;
		case 7:
			printf( "��");
			break;
		case 8:
			printf( "��");
			break;
		case 9:
			printf( "��");
			break;
		default:
			break;
		}
	}
	if (!a12 && !a11 && !a10 && !a9 && !a8 && !a7 && !a6 && !a5 && !a4 && !a3 && !a2 && !a1) {
		printf( "��Բ");
	}

	if (a12 || a11 || a10 || a9 || a8 || a7 || a6 || a5 || a4 || a3) {
		printf ( "Բ");
		flag = true;
	}
	else {
		flag = false;
	}

	switch (a2)
	{
	case 1:
		printf("Ҽ��");
		break;
	case 2:
		printf("����");
		break;
	case 3:
		printf("����");
		break;
	case 4:
		printf("����");
		break;
	case 5:
		printf("���");
		break;
	case 6:
		printf("½��");
		break;
	case 7:
		printf("���");
		break;
	case 8:
		printf("�ƽ�");
		break;
	case 9:
		printf( "����");
		break;
	default:
		if (flag) {
			flag = false;
			if (a1) {
				printf( "��");
			}
		}
		break;
	}


	switch (a1)
	{
	case 1:
		printf("Ҽ��");
		break;
	case 2:
		printf("����");
		break;
	case 3:
		printf("����");
		break;
	case 4:
		printf("����");
		break;
	case 5:
		printf("���");
		break;
	case 6:
		printf("½��");
		break;
	case 7:
		printf("���");
		break;
	case 8:
		printf("�Ʒ�");
		break;
	case 9:
		printf("����");
		break;
	default:
		printf("��");
		break;
	}

	printf("\n");
	return 0;
}
