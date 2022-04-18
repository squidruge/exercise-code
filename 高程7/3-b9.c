/*1951393 自动化 张儒戈*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	for (int num = 2; num <= 1000; ++num) {

		for (int factor = 1, sum = 0, cnt = 0; factor < num; factor++) {
			if (num % factor == 0) {
				sum += factor;
				cnt++;
			}

			if ((factor == num - 1) && (sum == num)) {
				printf("%d,its factors are ",num);
				for (int factor = 1; factor < num; ++factor) {
					if (num % factor == 0) {
						printf("%d",factor);
						if (cnt != 1) {
							printf(",");
							cnt--;
						}
						else {
							printf("\n");
						}


					}
				}

			}


		}


	}
	return 0;
}