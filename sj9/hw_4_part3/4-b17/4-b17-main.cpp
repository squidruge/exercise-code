/*1951393 �Զ��� �����*/
#include <iostream>

using namespace std;

double a, b, c;

bool a_is_0();

void unequal_real();

void equal_real();

void virtual_roots();

int main()
{
	
	cout << "������һԪ���η��̵�����ϵ��a,b,c:" << endl;
	cin >> a >> b >> c;
	if (!a_is_0()) {
		unequal_real();
		equal_real();
		virtual_roots();
	}


	return 0;
}