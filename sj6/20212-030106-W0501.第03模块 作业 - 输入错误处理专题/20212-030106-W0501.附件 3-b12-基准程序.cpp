/* �༶ ѧ�� ���� */
#include <iostream>
using namespace std;

int main()
{
	int x;

	while (1) {
		cout << "������x��ֵ[0-100] : ";
		cin >> x;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (x >= 0 && x <= 100)
			break;
	}

	cout << "x=" << x << endl;

	return 0;
}
