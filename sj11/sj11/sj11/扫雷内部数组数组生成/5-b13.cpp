/*1951393 �Զ��� �����*/
#include <iostream>
#include <time.h>
using namespace std;

#define X_MAX 25
#define Y_MAX 9


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void input_mine(char mine[Y_MAX+1][X_MAX+1], int num)
{
	int x, y;
	//int cnt = 0;
	srand((unsigned int)(time(0)));

	for (int cnt = 0; cnt < num; cnt++) {

		do
		{
			x = rand() % (X_MAX + 1);
			y = rand() % (Y_MAX + 1);
		} while (mine[y][x] == '*');

		mine[y][x] = '*';
	}
}

void cout_mine(char mine[Y_MAX + 1][X_MAX + 1])
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
			
			mine[y][x] = cnt+'0';
		}
	}
}

void output_mine(char mine[Y_MAX + 1][X_MAX + 1])
{
	for (int y = 0; y <= Y_MAX; y++) {
		for (int x = 0; x <= X_MAX; x++) {

			cout << mine[y][x] << " ";
		}
		cout << endl;
	}
}


int main()
{
	char mine[Y_MAX + 1][X_MAX + 1] = { '\0' };
	input_mine(mine, 50);
	cout_mine(mine);
	output_mine(mine);
	
	return 0;
}