/*1951393 �Զ��� �����*/
#include <iostream>
#include<limits> 
using namespace std;

int main()
{
	int x;

	while (1) {
		cout << "������x��ֵ[0-100] : ";
		cin >> x;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if(cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (x >= 0 && x <= 100)
			break;
	
		
	}

	cout << "x=" << x << endl;

	return 0;
}
