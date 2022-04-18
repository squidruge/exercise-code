/*1951393 �Զ��� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int cnt = 0;
int top[3] = { 0 };
int a[3][10] = { 0 };
/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
   3������������������������ʼ/Ŀ�����ĺ���������������ʹ��ѭ�������������
   4����������ú������У���main�в���������κ���ʽ��ѭ����while��do-while��for��if-goto��
	  ���������main�н��У���main���������ѭ��
   --------------------------------------------------------------------- */


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
   ***************************************************************************/

void hanoi(int n, char src, char tmp, char dst)
{

	if (n == 1) {

		printf( "��%4d ��(%2d): %c-->%c ", ++cnt,n,src,dst);

		switch (src)
		{
		case 'A':
			switch (dst)
			{
			case 'B':
				a[1][top[1]++] = a[0][--top[0]];
				break;
			case 'C':
				a[2][top[2]++] = a[0][--top[0]];
				break;
			default:
				break;
			}

			break;
		case 'B':
			switch (dst)
			{
			case 'A':
				a[0][top[0]++] = a[1][--top[1]];
				break;
			case 'C':
				a[2][top[2]++] = a[1][--top[1]];
				break;
			default:
				break;
			}
			break;
		case 'C':
			switch (dst)
			{
			case 'B':
				a[1][top[1]++] = a[2][--top[2]];
				break;
			case 'A':
				a[0][top[0]++] = a[2][--top[2]];
				break;
			default:
				break;
			}

			break;
		default:
			break;
		}


		printf("A:");
		for (int i = 0; i < 10; i++) {
			if (i < top[0]) {
				printf("%2d", a[0][i]);
			}
			else {
				printf("  ");
			}
		}

		printf(" B:");
		for (int i = 0; i < 10; i++) {
			if (i < top[1]) {
				printf("%2d", a[1][i]);
			}
			else {
				printf("  ");
			}
		}

		printf(" C:");
		for (int i = 0; i < 10; i++) {
			if (i < top[2]) {
				printf("%2d", a[2][i]);
			}
			else {
				printf("  ");
			}
		}

		printf("\n");
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		printf("��%4d ��(%2d): %c-->%c ", ++cnt, n, src, dst);

		switch (src)
		{
		case 'A':
			switch (dst)
			{
			case 'B':
				a[1][top[1]++] = a[0][--top[0]];
				break;
			case 'C':
				a[2][top[2]++] = a[0][--top[0]];
				break;
			default:
				break;
			}

			break;
		case 'B':
			switch (dst)
			{
			case 'A':
				a[0][top[0]++] = a[1][--top[1]];
				break;
			case 'C':
				a[2][top[2]++] = a[1][--top[1]];
				break;
			default:
				break;
			}
			break;
		case 'C':
			switch (dst)
			{
			case 'B':
				a[1][top[1]++] = a[2][--top[2]];
				break;
			case 'A':
				a[0][top[0]++] = a[2][--top[2]];
				break;
			default:
				break;
			}

			break;
		default:
			break;
		}


		printf("A:");
		for (int i = 0; i < 10; i++) {
			if (i < top[0]) {
				printf("%2d", a[0][i]);
			}
			else {
				printf("  ");
			}
		}

		printf(" B:");
		for (int i = 0; i < 10; i++) {
			if (i < top[1]) {
				printf("%2d", a[1][i]);
			}
			else {
				printf("  ");
			}
		}

		printf(" C:");
		for (int i = 0; i < 10; i++) {
			if (i < top[2]) {
				printf("%2d", a[2][i]);
			}
			else {
				printf("  ");
			}
		}

		printf("\n");

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
	char ch;

	while (1) {
		printf("�����뺺ŵ���Ĳ���(1-10)\n");
		if (!scanf("%d", &n)) {
			while ((ch = getchar()) != EOF && ch != '\n')
				;
			continue;
		}
		while ((ch = getchar()) != EOF && ch != '\n')
			;

		if (n >= 1 && n <= 10) {
			break;
		}

	}


	while (1) {
		printf("��������ʼ��(A-C)\n");
		if (!scanf("%c", &src)) {
			while ((ch = getchar()) != EOF && ch != '\n')
				;
			continue;
		}

		while ((ch = getchar()) != EOF && ch != '\n')
			;
		if (src == 'A' || src == 'B' || src == 'C') {
			break;
		}
		if (src == 'a' || src == 'b' || src == 'c') {
			src += ('A' - 'a');
			break;
		}

	}


	while (1) {
		printf("������Ŀ����(A-C)\n");
		if (!scanf("%c", &dst)) {
			while ((ch = getchar()) != EOF && ch != '\n')
				;
			continue;
		}

		while ((ch = getchar()) != EOF && ch != '\n')
			;

		if (dst == 'A' || dst == 'B' || dst == 'C') {
			//cin.ignore(1024, '\n');
			if (dst == src) {
				printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", dst, src);
			}
			else {
				break;
			}
		}

		if (dst == 'a' || dst == 'b' || dst == 'c') {
			dst += ('A' - 'a');
			//cin.ignore(1024, '\n');
			if (dst == src) {
				printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", dst, src);
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
		top[0] = n;
		for (int i = 0; i < n; i++) {
			a[0][i] = n - i;
		}
		break;
	case 'B':
		top[1] = n;
		for (int i = 0; i < n; i++) {
			a[1][i] = n - i;
		}
		break;
	case 'C':
		top[2] = n;
		for (int i = 0; i < n; i++) {
			a[2][i] = n - i;
		}
		break;
	default:
		break;
	}
	printf("��ʼ:%16c",' ');

	printf("A:");
	for (int i = 0; i < 10; i++) {
		if (i < top[0]) {
			printf("%2d", a[0][i]);
		}
		else {
			printf("  ");
		}
	}

	printf(" B:");
	for (int i = 0; i < 10; i++) {
		if (i < top[1]) {
			printf("%2d", a[1][i]);
		}
		else {
			printf("  ");
		}
	}

	printf(" C:");
	for (int i = 0; i < 10; i++) {
		if (i < top[2]) {
			printf("%2d", a[2][i]);
		}
		else {
			printf("  ");
		}
	}

	printf("\n");


	hanoi(n, src, tmp, dst);

	return 0;
}
 