/*1951393 �Զ��� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x;
	char ch;
	while (1) {
		printf("������x��ֵ[0-100] : ");
		//scanf("%d", &x); //����x�ķ�ʽ������scanf�Ҹ�ʽ��Ϊ%d����׼�÷�scanf
		if (!scanf("%d", &x)) {
			while ((ch = getchar()) != EOF && ch != '\n')
				;
			continue;
		}
		if (x >= 0 && x <= 100)
			break;
	
	}
	printf("x=%d\n", x);
	return 0;
}
