/*1951393 �Զ��� �����*/
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�����������hanoi�ж���һ����̬�ֲ�����
   3������������������������ʼ/Ŀ�����ĺ���������������ʹ��ѭ�������������
   4����������ú������У���main�в���������κ���ʽ��ѭ����while��do-while��for��if-goto��
	  ���������main�н��У���main���������ѭ��
   --------------------------------------------------------------------- */
int cnt = 0;
int topA = 0, topB = 0, topC = 0;
int A[10] = { 0 }, B[10] = { 0 }, C[10] = { 0 };

   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
	 ���������int n������
			   char src����ʼ��
			   char tmp���м���
			   char dst��Ŀ����
	 �� �� ֵ��
	 ˵    ����1�����������βΡ��������;���׼��
			   2������������������κ���ʽ��ѭ��
			   3��������һ����̬�ֲ�����
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{


	if (n == 1) {

		cout << "��" << setw(4) << ++cnt << "��(" << setw(2) << n << "): "  << src << "-->" << dst<<" ";

		switch (src)
		{
		case 'A':
			switch (dst)
			{
			case 'B':
				B[topB++] =A[--topA];
				break;
			case 'C':
				C[topC++] = A[--topA];
				break;
			default:
				break;
			}

			break;
		case 'B':
			switch (dst)
			{
			case 'A':
				A[topA++] = B[--topB];
				break;
			case 'C':
				C[topC++] =B[--topB];
				break;
			default:
				break;
			}
			break;
		case 'C':
			switch (dst)
			{
			case 'B':
				B[topB++] = C[--topC];
				break;
			case 'A':
				A[topA++] =C[--topC];
				break;
			default:
				break;
			}

			break;
		default:
			break;
		}

		cout << "A:";
		for (int i = 0; i < 10; i++) {
			if (i < topA) {
				cout << setw(2) << A[i];
			}
			else {
				cout << "  ";
			}
		}

		cout << " B:";
		for (int i = 0; i < 10; i++) {
			if (i < topB) {
				cout << setw(2) << B[i];
			}
			else {
				cout << "  ";
			}
		}

		cout << " C:";
		for (int i = 0; i < 10; i++) {
			if (i < topC) {
				cout << setw(2) << C[i];
			}
			else {
				cout << "  ";
			}
		}

		cout << endl;
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		cout << "��" << setw(4) << ++cnt << "��(" << setw(2) << n << "): "<< src << "-->" << dst<<" ";
		switch (src)
		{
		case 'A':
			switch (dst)
			{
			case 'B':
				B[topB++] = A[--topA];
				break;
			case 'C':
				C[topC++] = A[--topA];
				break;
			default:
				break;
			}

			break;
		case 'B':
			switch (dst)
			{
			case 'A':
				A[topA++] = B[--topB];
				break;
			case 'C':
				C[topC++] = B[--topB];
				break;
			default:
				break;
			}

	
			break;
		case 'C':
			switch (dst)
			{
			case 'B':
				B[topB++] = C[--topC];
				break;
			case 'A':
				A[topA++] = C[--topC];
				break;
			default:
				break;
			}

			break;
		default:
			break;
		}

		cout << "A:";
		for (int i = 0; i < 10; i++) {
			if (i < topA) {
				cout <<setw(2)<< A[i] ;
			}
			else {
				cout << "  "  ;
			}
		}

		cout << " B:";
		for (int i = 0; i < 10; i++) {
			if (i < topB) {
				cout << setw(2) << B[i];
			}
			else {
				cout << "  "  ;
			}
		}

		cout << " C:";
		for (int i = 0; i <10; i++) {
			if (i < topC) {
				cout << setw(2) << C[i];
			}
			else {
				cout << "  "  ;
			}
		}
		cout << endl;
	
		hanoi(n - 1, tmp, src, dst);
		
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������(��������뺯��)�����õݹ麯��
***************************************************************************/
int main()
{
	int n;
	char src, dst, tmp = 'A';

	while (1) {
		cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
		cin >> n;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		cin.ignore(1024, '\n');
		if (n >= 1 && n <= 10) {
			break;
		}

	}

	while (1) {
		cout << "��������ʼ��(A-C)" << endl;
		cin >> src;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');

			continue;
		}
		cin.ignore(1024, '\n');
		if (src == 'A' || src == 'B' || src == 'C') {
			//cin.ignore(1024, '\n');
			break;
		}
		if (src == 'a' || src == 'b' || src == 'c') {
			src += ('A' - 'a');
			//cin.ignore(1024, '\n');
			break;
		}

	}


	while (1) {
		cout << "������Ŀ����(A-C)" << endl;
		cin >> dst;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		cin.ignore(1024, '\n');

		if (dst == 'A' || dst == 'B' || dst == 'C') {
			//cin.ignore(1024, '\n');
			if (dst == src) {
				cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
			}
			else {
				break;
			}
		}

		if (dst == 'a' || dst == 'b' || dst == 'c') {
			dst += ('A' - 'a');
			//cin.ignore(1024, '\n');
			if (dst == src) {
				cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
			}
			else {
				break;
			}
		}


	}

	while (tmp == dst || tmp == src)
		tmp++;

	switch (src)
	{
	case 'A':
		topA = n;
		for (int i = 0; i < n; i++) {
			A[i] = n - i;
		}
		break;
	case 'B':
		topB = n;
		for (int i = 0; i < n; i++) {
			B[i] = n - i;
		}
		break;
	case 'C':
		topC = n;
		for (int i = 0; i < n; i++) {
			C[i] = n - i;
		}
		break;
	default:
		break;
	}
	cout << "��ʼ:" <<setw(15)<<" ";
	cout << "A:";
	for (int i = 0; i < 10; i++) {
		if (i < topA) {
			cout << setw(2) << A[i];
		}
		else {
			cout << "  ";
		}
	}

	cout << " B:";
	for (int i = 0; i < 10; i++) {
		if (i < topB) {
			cout << setw(2) << B[i];
		}
		else {
			cout << "  ";
		}
	}

	cout << " C:";
	for (int i = 0; i < 10; i++) {
		if (i < topC) {
			cout << setw(2) << C[i];
		}
		else {
			cout << "  ";
		}
	}
	cout << endl;
	hanoi(n, src, tmp, dst);

	return 0;
} 