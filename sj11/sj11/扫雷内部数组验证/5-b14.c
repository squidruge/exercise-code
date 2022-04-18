/*1951393 �Զ��� �����*/
/* ����֤ 1951347 ��������1950681 ���塢1952037 �����1952756 �����1952961 ��ӳ�� ��ɨ���ڲ�����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define X_MAX 25
#define Y_MAX 9


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int test_mine(char mine[Y_MAX + 1][X_MAX + 1], int num)
{
	int x, y;
	int cnt = 0;
	int ret = 0;

	for (y = 0; y <= Y_MAX; y++) {
		for (x = 0; x <= X_MAX; x++) {
			if (mine[y][x] == '*') {
				cnt++;
			}

		}
	}

	if (cnt != num) {
		ret = 0;
	}
	else {
		ret = 1;
	}
	return ret;
}

int test_cout(char mine[Y_MAX + 1][X_MAX + 1])
{


	for (int y = 0; y <= Y_MAX; y++) {
		for (int x = 0; x <= X_MAX; x++) {

			int cnt = 0;

			if (mine[y][x] == '*') {
				//��������
				continue;
			}

			for (int r = y - 1; r <= y + 1; r++) {
				for (int c = x - 1; c <= x + 1; c++) {

					if (r >= 0 && r <= Y_MAX && c >= 0 && c <= X_MAX)
					{
						if (mine[r][c] == '*')
							cnt++;
					}
				}
			}

			if (mine[y][x] != cnt + '0') {
				return 0;
			}
		}

	}
	return 1;
}


int main()
{
	char mine[Y_MAX + 1][X_MAX + 1] = { '\0' };

	char tmp;
	int i, j;
	for (i = 0; i <= Y_MAX; ++i)
	{
		for (j = 0; j <= X_MAX;++j)
		{
			while(1) {

				scanf("%c", &tmp);
				if ((tmp == '*') || (tmp >= '0' && tmp <= '8'))
				{
					mine[i][j] = tmp;
					break;
				}
			}
		}
	}

	if (test_mine(mine, 50)) {
		if (test_cout(mine)) {
			printf("��ȷ\n");
		}
		else {
			printf("����2\n");
		}
	}
	else {

		printf("����1\n");

	}

	return 0;
}
