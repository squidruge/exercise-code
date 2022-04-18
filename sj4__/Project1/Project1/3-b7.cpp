/*1951393 ×Ô¶¯»¯ ÕÅÈå¸ê*/
#include<iostream>
using namespace std;

int main()
{
	double num;
	int a12, a11, a10, a9, a8, a7, a6,
		a5, a4, a3, a2, a1;	//ÓÉ¸ßµ½µÍ¸÷Î»Êı

	bool flag = false;
	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;
	cin >> num;
	cout << "´óĞ´½á¹ûÊÇ:" << endl;


	a12 = static_cast<int>(num / 1.0e9);
	a11 = static_cast<int>(num / 1.0e8) % 10;
	a10 = static_cast<int>(num / 1.0e7) % 10;
	a9 = static_cast<int>(num / 1.0e6) % 10;
	a8 = static_cast<int>(num / 1.0e5) % 10;
	a7 = static_cast<int>(num / 1.0e4) % 10;
	a6 = static_cast<int>(num / 1000.0) % 10;
	a5 = static_cast<int>(num / 100.0) % 10;
	a4 = static_cast<int>((num - a12 * 1.0e9 - a11 * 1.0e8 - a10 * 1.0e7) / 10) % 10;
	a3 = static_cast<int>(num - a12 * 1.0e9 - a11 * 1.0e8 - a10 * 1.0e7) % 10;
	a2 = static_cast<int>((num - a12 * 1.0e9 - a11 * 1.0e8 - a10 * 1.0e7 + 0.00500) * 10) % 10;
	a1 = static_cast<int>((num - a12 * 1.0e9 - a11 * 1.0e8 - a10 * 1.0e7 + 0.00500) * 100) % 10;

	//ÒÚÎ»Êä³ö²¿·Ö
	if (a12 || a11) {
		flag = true;
		switch (a12)
		{
		case 1:
			cout << "Ò¼Ê°";
			break;
		case 2:
			cout << "·¡Ê°";
			break;
		case 3:
			cout << "ÈşÊ°";
			break;
		case 4:
			cout << "ËÁÊ°";
			break;
		case 5:
			cout << "ÎéÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 9:
			cout << "¾ÁÊ°";
			break;
		default:
			break;
		}
		switch (a11)
		{
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èş";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		default:
			break;
		}
		cout << "ÒÚ";
	}



	//´¦ÀíÍòÎ»²¿·Ö
	if (a10 || a9 || a8 || a7) {
		switch (a10)
		{
		case 1:
			cout << "Ò¼Çª";
			break;
		case 2:
			cout << "·¡Çª";
			break;
		case 3:
			cout << "ÈşÇª";
			break;
		case 4:
			cout << "ËÁÇª";
			break;
		case 5:
			cout << "ÎéÇª";
			break;
		case 6:
			cout << "Â½Çª";
			break;
		case 7:
			cout << "ÆâÇª";
			break;
		case 8:
			cout << "°ÆÇª";
			break;
		case 9:
			cout << "¾ÁÇª";
			break;
		default:
			if (flag) {
				flag = false;
				cout << "Áã";

			}
			break;
		}
		if (a10) {
			flag = true;
		}

		switch (a9)
		{
		case 1:
			cout << "Ò¼°Û";
			break;
		case 2:
			cout << "·¡°Û";
			break;
		case 3:
			cout << "Èş°Û";
			break;
		case 4:
			cout << "ËÁ°Û";
			break;
		case 5:
			cout << "Îé°Û";
			break;
		case 6:
			cout << "Â½°Û";
			break;
		case 7:
			cout << "Æâ°Û";
			break;
		case 8:
			cout << "°Æ°Û";
			break;
		case 9:
			cout << "¾Á°Û";
			break;
		default:
			if (flag) {
				flag = false;
				if (a8 || a7) {
					cout << "Áã";
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
			cout << "Ò¼Ê°";
			break;
		case 2:
			cout << "·¡Ê°";
			break;
		case 3:
			cout << "ÈşÊ°";
			break;
		case 4:
			cout << "ËÁÊ°";
			break;
		case 5:
			cout << "ÎéÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 9:
			cout << "¾ÁÊ°";
			break;
		default:
			if (flag) {
				flag = false;
				if (a7) {
					cout << "Áã";
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
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èş";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		default:
			break;
		}

		cout << "Íò";
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
			cout << "Ò¼Çª";
			break;
		case 2:
			cout << "·¡Çª";
			break;
		case 3:
			cout << "ÈşÇª";
			break;
		case 4:
			cout << "ËÁÇª";
			break;
		case 5:
			cout << "ÎéÇª";
			break;
		case 6:
			cout << "Â½Çª";
			break;
		case 7:
			cout << "ÆâÇª";
			break;
		case 8:
			cout << "°ÆÇª";
			break;
		case 9:
			cout << "¾ÁÇª";
			break;
		default:
			if (flag) {
				flag = false;
				cout << "Áã";

			}
			break;
		}
		if (a6) {
			flag = true;
		}

		switch (a5)
		{
		case 1:
			cout << "Ò¼°Û";
			break;
		case 2:
			cout << "·¡°Û";
			break;
		case 3:
			cout << "Èş°Û";
			break;
		case 4:
			cout << "ËÁ°Û";
			break;
		case 5:
			cout << "Îé°Û";
			break;
		case 6:
			cout << "Â½°Û";
			break;
		case 7:
			cout << "Æâ°Û";
			break;
		case 8:
			cout << "°Æ°Û";
			break;
		case 9:
			cout << "¾Á°Û";
			break;
		default:
			if (flag) {
				flag = false;
				if (a4 || a3) {
					cout << "Áã";
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
			cout << "Ò¼Ê°";
			break;
		case 2:
			cout << "·¡Ê°";
			break;
		case 3:
			cout << "ÈşÊ°";
			break;
		case 4:
			cout << "ËÁÊ°";
			break;
		case 5:
			cout << "ÎéÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 9:
			cout << "¾ÁÊ°";
			break;
		default:
			if (flag) {
				flag = false;
				if (a3) {
					cout << "Áã";
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
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èş";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		default:
			break;
		}
	}
	if (!a12 && !a11 && !a10 && !a9 && !a8 && !a7 && !a6 && !a5 && !a4 && !a3 && !a2 && !a1) {
		cout << "ÁãÔ²";
	}
	
	if (a12 || a11 || a10 || a9 || a8 || a7 || a6 || a5 || a4 || a3) {
		cout << "Ô²";
		flag = true;
	}
	else {
		flag = false;
	}

	switch (a2)
	{
	case 1:
		cout << "Ò¼½Ç";
		break;
	case 2:
		cout << "·¡½Ç";
		break;
	case 3:
		cout << "Èş½Ç";
		break;
	case 4:
		cout << "ËÁ½Ç";
		break;
	case 5:
		cout << "Îé½Ç";
		break;
	case 6:
		cout << "Â½½Ç";
		break;
	case 7:
		cout << "Æâ½Ç";
		break;
	case 8:
		cout << "°Æ½Ç";
		break;
	case 9:
		cout << "¾Á½Ç";
		break;
	default:
		if (flag) {
			flag = false;
			if (a1) {
				cout << "Áã";
			}
		}
		break;
	}


	switch (a1)
	{
	case 1:
		cout << "Ò¼·Ö";
		break;
	case 2:
		cout << "·¡·Ö";
		break;
	case 3:
		cout << "Èş·Ö";
		break;
	case 4:
		cout << "ËÁ·Ö";
		break;
	case 5:
		cout << "Îé·Ö";
		break;
	case 6:
		cout << "Â½·Ö";
		break;
	case 7:
		cout << "Æâ·Ö";
		break;
	case 8:
		cout << "°Æ·Ö";
		break;
	case 9:
		cout << "¾Á·Ö";
		break;
	default:
		cout << "Õû" << endl;
		break;
	}
	return 0;
}
