/*1951393 自动化 张儒戈*/
#include <iostream>
#include <cstdio>

using namespace std;

void tongji(int cnt[], char str[])
{
	int i;

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			cnt[0]++;
			continue;
		}

		if (str[i] >= 'a' && str[i] <= 'z') {
			cnt[1]++;
			continue;
		}

		if (str[i] >= '0' && str[i] <= '9') {
			cnt[2]++;
			continue;
		}

		if (str[i] == ' ') {
			cnt[3]++;
			continue;
		}
		if (str[i] != '\n') {
			cnt[4]++;//其他字符
		}


	}
}

int main()
{
	char str[3][128] = { '\0' };
	int cnt[5] = { 0 };
	for (int i = 0; i < 3; i++) {
		cout << "请输入第" << (i + 1) << "行" << endl;
		cin.getline(str[i], 128);
	}




	tongji(cnt, str[0]);
	tongji(cnt, str[1]);
	tongji(cnt, str[2]);

	cout << "大写 : " << cnt[0] << endl;
	cout << "小写 : " << cnt[1] << endl;
	cout << "数字 : " << cnt[2] << endl;
	cout << "空格 : " << cnt[3] << endl;
	cout << "其它 : " << cnt[4] << endl;


	return 0;
}
