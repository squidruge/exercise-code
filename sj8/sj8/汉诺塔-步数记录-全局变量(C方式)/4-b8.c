/*1951393 �Զ��� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int cnt = 0;
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
		printf("%5d:%3d# %c-->%c\n", ++cnt, n, src, dst);
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		printf("%5d:%3d# %c-->%c\n", ++cnt, n, src, dst);
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
		printf("�����뺺ŵ���Ĳ���(1-16)\n");
		if (!scanf("%d", &n)) {
			while ((ch = getchar()) != EOF && ch != '\n')
				;
			continue;
		}
		while ((ch = getchar()) != EOF && ch != '\n')
			;

		if (n >= 1 && n <= 16) {
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


	printf("�ƶ�����Ϊ:\n");
	hanoi(n, src, tmp, dst);

	return 0;
}

