/*1951393 自动化 张儒戈*/
#include<iostream>
#define size 1000
using namespace std;

int main()
{
	int num[101] = { 0 };
	int score[1000];

	for (int i = 0; i < 1000; i++) {
		score[i] = -1;
	}

	cout << "请输入成绩（最多1000个），以-1结束" << endl;

	int cnt = 0;
	while (cnt < size - 1) {

		cin >> score[cnt];

		if (score[cnt] < 0) {
			break;
		}
		cnt++;
	}

	if (score[0] <0) {
		cout << "无有效输入" << endl;
		return 0;
	}

	cout << "输入的数组为:" ;

	for (int i = 0; i < size - 1; i++) {
		if (i % 10 == 0) {
			cout << endl;
		}

		if (score[i] >= 0) {
			cout << score[i] << " ";
		}
		else {
			cout << endl;
			break;
		}
	}

	for (int i = 0; i < size; i++) {
		if (score[i]>= 0) {
			num[score[i]]++;
		}
	}

	cout << "分数与人数的对应关系为:" << endl;

	for (int i = 100; i >=0; i--) {
		if (num[i] > 0) {
			cout << i << " " << num[i] << endl;
		}
	}

	return 0;
}


