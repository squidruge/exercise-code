/*1951393 自动化 张儒戈*/
#include <iostream>
#define MAX 16
#define MIN 12

using namespace std;


/*读取第一行并忽略*/
void firstline()
{
	char ch;

	while ((ch = getchar()) != EOF && ch != '\n')
		;
}

/*判断第二行五个参数是否正确，不正确返回0，正确返回1 */
int secondline(int num[], int n)
{
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		cin >> num[i];
		if (cin.fail())  //非法字符，返回0，表示错误
		{
			return 0;
		}
		if (num[i] < 2)  //数字不对，返回0，表示错误
		{
			return 0;
		}
	}

	if (num[0] >= 12 && num[0] <= 16 && num[1] + num[2] + num[3] + num[4] <= num[0])
	{
		return 1;
	}


	return 0;
}

/* 将密码串读入字符数组 */
void input_password(char pass_word[][MAX + 1], int n)
{
	char ch;

	//处理第二行剩余的换行符 
	while ((ch = getchar()) != EOF && ch != '\n')
		;

	for (int i = 0; i < n; ++i)
	{
		//读入密码，最多MAX个字符，缺省遇回车停止，且丢弃 
		cin.getline(pass_word[i], MAX + 1);
		//fgets(pass_word[i], MAX + 1, stdin);

	}

}


//验证密码 错误返回0 
int yanzheng(char pass_word[MAX + 1], int len, int  up_num, int low_num, int  figure_num, int other_num)
{
	int cnt[4] = { 0 };


	int i;

	//统计 
	for (i = 0; pass_word[i] != '\0'; i++) {
		if (pass_word[i] >= 'A' && pass_word[i] <= 'Z') {
			cnt[0]++;
			continue;
		}

		if (pass_word[i] >= 'a' && pass_word[i] <= 'z') {
			cnt[1]++;
			continue;
		}

		if (pass_word[i] >= '0' && pass_word[i] <= '9') {
			cnt[2]++;
			continue;
		}

		cnt[3]++;

	}

	//判断数量的正确性 
	if (cnt[0] < up_num || cnt[1] < low_num ||
		cnt[2] < figure_num || cnt[3] < other_num ||
		i < len) {

		return 0;

	}
	else {
		return 1;
	}



}



int main()
{


	char pass_word[10][MAX + 1] = { '\0' };

	int num[5];

	firstline();

	if (!secondline(num, 5)) {
		cout << "错误" << endl;
		return 0;
	}

	
	input_password(pass_word, 10);


	for (int i = 0; i < 10; i++) {

		if (!yanzheng(pass_word[i], num[0], num[1], num[2], num[3], num[4])) {
			cout << "错误" << endl;

			return 0;

		}


	}

	cout << "正确" << endl;

	return 0;
}



