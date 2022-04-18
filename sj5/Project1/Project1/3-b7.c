/*1951393 ×Ô¶¯»¯ ÕÅÈå¸ê*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdbool.h>
int main()
{
	double num;
	int a12, a11, a10, a9, a8, a7, a6,
		a5, a4, a3, a2, a1;	//ÓÉ¸ßµ½µÍ¸÷Î»Êı

	bool flag = false;
	printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:\n");
	scanf("%lf",&num);
	printf("´óĞ´½á¹ûÊÇ:\n");


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

	//ÒÚÎ»Êä³ö²¿·Ö
	if (a12 || a11) {
		flag = true;
		switch (a12)
		{
		case 1:
			printf( "Ò¼Ê°");
			break;
		case 2:
			printf( "·¡Ê°");
			break;
		case 3:
			printf( "ÈşÊ°");
			break;
		case 4:
			printf( "ËÁÊ°");
			break;
		case 5:
			printf( "ÎéÊ°");
			break;
		case 6:
			printf( "Â½Ê°");
			break;
		case 7:
			printf( "ÆâÊ°");
			break;
		case 8:
			printf( "°ÆÊ°");
			break;
		case 9:
			printf( "¾ÁÊ°");
			break;
		default:
			break;
		}
		switch (a11)
		{
		case 1:
			printf( "Ò¼");
			break;
		case 2:
			printf( "·¡");
			break;
		case 3:
			printf( "Èş");
			break;
		case 4:
			printf( "ËÁ");
			break;
		case 5:
			printf( "Îé");
			break;
		case 6:
			printf( "Â½");
			break;
		case 7:
			printf( "Æâ");
			break;
		case 8:
			printf( "°Æ");
			break;
		case 9:
			printf( "¾Á");
			break;
		default:
			break;
		}
		print("ÒÚ"); 
	}



	//´¦ÀíÍòÎ»²¿·Ö
	if (a10 || a9 || a8 || a7) {
		switch (a10)
		{
		case 1:
			printf( "Ò¼Çª");
			break;
		case 2:
			printf( "·¡Çª");
			break;
		case 3:
			printf( "ÈşÇª");
			break;
		case 4:
			printf( "ËÁÇª");
			break;
		case 5:
			printf( "ÎéÇª");
			break;
		case 6:
			printf( "Â½Çª");
			break;
		case 7:
			printf( "ÆâÇª");
			break;
		case 8:
			printf( "°ÆÇª");
			break;
		case 9:
			printf( "¾ÁÇª");
			break;
		default:
			if (flag) {
				flag = false;
				printf( "Áã");

			}
			break;
		}
		if (a10) {
			flag = true;
		}

		switch (a9)
		{
		case 1:
			printf( "Ò¼°Û");
			break;
		case 2:
			printf( "·¡°Û");
			break;
		case 3:
			printf( "Èş°Û");
			break;
		case 4:
			printf( "ËÁ°Û");
			break;
		case 5:
			printf( "Îé°Û");
			break;
		case 6:
			printf( "Â½°Û");
			break;
		case 7:
			printf( "Æâ°Û");
			break;
		case 8:
			printf( "°Æ°Û");
			break;
		case 9:
			printf( "¾Á°Û");
			break;
		default:
			if (flag) {
				flag = false;
				if (a8 || a7) {
					printf( "Áã");
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
			printf( "Ò¼Ê°");
			break;
		case 2:
			printf( "·¡Ê°");
			break;
		case 3:
			printf( "ÈşÊ°");
			break;
		case 4:
			printf( "ËÁÊ°");
			break;
		case 5:
			printf( "ÎéÊ°");
			break;
		case 6:
			printf( "Â½Ê°");
			break;
		case 7:
			printf( "ÆâÊ°");
			break;
		case 8:
			printf( "°ÆÊ°");
			break;
		case 9:
			printf( "¾ÁÊ°");
			break;
		default:
			if (flag) {
				flag = false;
				if (a7) {
					printf( "Áã");
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
			printf( "Ò¼");
			break;
		case 2:
			printf( "·¡");
			break;
		case 3:
			printf( "Èş");
			break;
		case 4:
			printf( "ËÁ");
			break;
		case 5:
			printf( "Îé");
			break;
		case 6:
			printf( "Â½");
			break;
		case 7:
			printf( "Æâ");
			break;
		case 8:
			printf( "°Æ");
			break;
		case 9:
			printf( "¾Á");
			break;
		default:
			break;
		}

		printf( "Íò");
	}
	if (a12 || a11 || a10 || a9 || a8 || a7) {
		flag = true;
	}
	else {
		flag = false;
	}


	//Ç§~Ôª
	if (a6 || a5 || a4 || a3) {
		switch (a6)
		{
		case 1:
			printf( "Ò¼Çª");
			break;
		case 2:
			printf( "·¡Çª");
			break;
		case 3:
			printf( "ÈşÇª");
			break;
		case 4:
			printf( "ËÁÇª");
			break;
		case 5:
			printf( "ÎéÇª");
			break;
		case 6:
			printf( "Â½Çª");
			break;
		case 7:
			printf( "ÆâÇª");
			break;
		case 8:
			printf( "°ÆÇª");
			break;
		case 9:
			printf( "¾ÁÇª");
			break;
		default:
			if (flag) {
				flag = false;
				printf( "Áã");

			}
			break;
		}
		if (a6) {
			flag = true;
		}

		switch (a5)
		{
		case 1:
			printf( "Ò¼°Û");
			break;
		case 2:
			printf( "·¡°Û");
			break;
		case 3:
			printf( "Èş°Û");
			break;
		case 4:
			printf( "ËÁ°Û");
			break;
		case 5:
			printf( "Îé°Û");
			break;
		case 6:
			printf( "Â½°Û");
			break;
		case 7:
			printf( "Æâ°Û");
			break;
		case 8:
			printf( "°Æ°Û");
			break;
		case 9:
			printf( "¾Á°Û");
			break;
		default:
			if (flag) {
				flag = false;
				if (a4 || a3) {
					printf( "Áã");
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
			printf( "Ò¼Ê°");
			break;
		case 2:
			printf( "·¡Ê°");
			break;
		case 3:
			printf( "ÈşÊ°");
			break;
		case 4:
			printf( "ËÁÊ°");
			break;
		case 5:
			printf( "ÎéÊ°");
			break;
		case 6:
			printf( "Â½Ê°");
			break;
		case 7:
			printf( "ÆâÊ°");
			break;
		case 8:
			printf( "°ÆÊ°");
			break;
		case 9:
			printf( "¾ÁÊ°");
			break;
		default:
			if (flag) {
				flag = false;
				if (a3) {
					printf( "Áã");
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
			printf( "Ò¼");
			break;
		case 2:
			printf( "·¡");
			break;
		case 3:
			printf( "Èş");
			break;
		case 4:
			printf( "ËÁ");
			break;
		case 5:
			printf( "Îé");
			break;
		case 6:
			printf( "Â½");
			break;
		case 7:
			printf( "Æâ");
			break;
		case 8:
			printf( "°Æ");
			break;
		case 9:
			printf( "¾Á");
			break;
		default:
			break;
		}
	}
	if (!a12 && !a11 && !a10 && !a9 && !a8 && !a7 && !a6 && !a5 && !a4 && !a3 && !a2 && !a1) {
		printf( "ÁãÔ²");
	}

	if (a12 || a11 || a10 || a9 || a8 || a7 || a6 || a5 || a4 || a3) {
		printf ( "Ô²");
		flag = true;
	}
	else {
		flag = false;
	}

	switch (a2)
	{
	case 1:
		printf("Ò¼½Ç");
		break;
	case 2:
		printf("·¡½Ç");
		break;
	case 3:
		printf("Èş½Ç");
		break;
	case 4:
		printf("ËÁ½Ç");
		break;
	case 5:
		printf("Îé½Ç");
		break;
	case 6:
		printf("Â½½Ç");
		break;
	case 7:
		printf("Æâ½Ç");
		break;
	case 8:
		printf("°Æ½Ç");
		break;
	case 9:
		printf( "¾Á½Ç");
		break;
	default:
		if (flag) {
			flag = false;
			if (a1) {
				printf( "Áã");
			}
		}
		break;
	}


	switch (a1)
	{
	case 1:
		printf("Ò¼·Ö");
		break;
	case 2:
		printf("·¡·Ö");
		break;
	case 3:
		printf("Èş·Ö");
		break;
	case 4:
		printf("ËÁ·Ö");
		break;
	case 5:
		printf("Îé·Ö");
		break;
	case 6:
		printf("Â½·Ö");
		break;
	case 7:
		printf("Æâ·Ö");
		break;
	case 8:
		printf("°Æ·Ö");
		break;
	case 9:
		printf("¾Á·Ö");
		break;
	default:
		printf("Õû");
		break;
	}
	return 0;
}