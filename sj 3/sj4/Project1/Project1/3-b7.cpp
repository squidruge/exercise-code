/*1951393 �Զ��� �����*/
#include<iostream>
using namespace std;

int main()
{
	double num;
	int a12, a11, a10, a9, a8, a7, a6,
		a5, a4, a3, a2, a1;	//�ɸߵ��͸�λ��

	bool flag = false;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> num;
	cout << "��д�����:" << endl;


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

	//��λ�������
	if (a12 || a11) {
		flag = true;
		switch (a12)
		{
		case 1:
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;
		default:
			break;
		}
		switch (a11)
		{
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
			break;
		}
		cout << "��";
	}



	//������λ����
	if (a10 || a9 || a8 || a7) {
		switch (a10)
		{
		case 1:
			cout << "ҼǪ";
			break;
		case 2:
			cout << "��Ǫ";
			break;
		case 3:
			cout << "��Ǫ";
			break;
		case 4:
			cout << "��Ǫ";
			break;
		case 5:
			cout << "��Ǫ";
			break;
		case 6:
			cout << "½Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 9:
			cout << "��Ǫ";
			break;
		default:
			if (flag) {
				flag = false;
				cout << "��";

			}
			break;
		}
		if (a10) {
			flag = true;
		}

		switch (a9)
		{
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 9:
			cout << "����";
			break;
		default:
			if (flag) {
				flag = false;
				if (a8 || a7) {
					cout << "��";
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
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;
		default:
			if (flag) {
				flag = false;
				if (a7) {
					cout << "��";
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
			break;
		}

		cout << "��";
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
			cout << "ҼǪ";
			break;
		case 2:
			cout << "��Ǫ";
			break;
		case 3:
			cout << "��Ǫ";
			break;
		case 4:
			cout << "��Ǫ";
			break;
		case 5:
			cout << "��Ǫ";
			break;
		case 6:
			cout << "½Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 9:
			cout << "��Ǫ";
			break;
		default:
			if (flag) {
				flag = false;
				cout << "��";

			}
			break;
		}
		if (a6) {
			flag = true;
		}

		switch (a5)
		{
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 9:
			cout << "����";
			break;
		default:
			if (flag) {
				flag = false;
				if (a4 || a3) {
					cout << "��";
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
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;
		default:
			if (flag) {
				flag = false;
				if (a3) {
					cout << "��";
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
			break;
		}
	}
	if (!a12 && !a11 && !a10 && !a9 && !a8 && !a7 && !a6 && !a5 && !a4 && !a3 && !a2 && !a1) {
		cout << "��Բ";
	}
	
	if (a12 || a11 || a10 || a9 || a8 || a7 || a6 || a5 || a4 || a3) {
		cout << "Բ";
		flag = true;
	}
	else {
		flag = false;
	}

	switch (a2)
	{
	case 1:
		cout << "Ҽ��";
		break;
	case 2:
		cout << "����";
		break;
	case 3:
		cout << "����";
		break;
	case 4:
		cout << "����";
		break;
	case 5:
		cout << "���";
		break;
	case 6:
		cout << "½��";
		break;
	case 7:
		cout << "���";
		break;
	case 8:
		cout << "�ƽ�";
		break;
	case 9:
		cout << "����";
		break;
	default:
		if (flag) {
			flag = false;
			if (a1) {
				cout << "��";
			}
		}
		break;
	}


	switch (a1)
	{
	case 1:
		cout << "Ҽ��";
		break;
	case 2:
		cout << "����";
		break;
	case 3:
		cout << "����";
		break;
	case 4:
		cout << "����";
		break;
	case 5:
		cout << "���";
		break;
	case 6:
		cout << "½��";
		break;
	case 7:
		cout << "���";
		break;
	case 8:
		cout << "�Ʒ�";
		break;
	case 9:
		cout << "����";
		break;
	default:
		cout << "��" << endl;
		break;
	}
	return 0;
}
