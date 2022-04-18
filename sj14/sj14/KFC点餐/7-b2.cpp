/*1951393 自动化 张儒戈*/
#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

struct KFC
{
	char letter;
	char name[128];
	double price;
}; 

struct SPECIAL
{
	char letter[128];
	char name[1024];
	double price;
};

const struct KFC list[] = {
	{'A', "香辣鸡腿堡",         18},
	{'B', "劲脆鸡腿堡",         18},
	{'C', "新奥尔良烤鸡腿堡",   18.5},
	{'D', "鸡肉火腿帕尼尼",   14.0},
	{'E', "老北京鸡肉卷",       16.5},
	{'F', "川辣嫩牛卷",     19},
	{'G', "吮指原味鸡(1块)",   11.5},
	{'H', "热辣薯片脆皮鸡",   12.5},
	{'I', "新奥尔良烤翅(2块)", 12},
	{'J', "劲爆鸡米花",         10.5},
	{'K', "香辣鸡翅(2块)",     11.0},
	{'L', "热辣香骨鸡(3块)",     11.0},
	{'M', "鲜蔬色拉",           12.5},
	{'N', "薯条(小)",           8},
	{'O', "薯条(中)",           11},
	{'P', "薯条(大)",           13},
	{'Q', "芙蓉蔬荟汤",         8},
	{'R', "原味花筒冰激凌",     6},
	{'S', "醇香土豆泥",         6.5},
	{'T', "香甜粟米棒",         8.0},
	{'U', "葡式蛋挞",           7.5},
	{'V', "百事可乐(小)",       7.0},
	{'W', "百事可乐(中)",       9.5},
	{'X', "百事可乐(大)",       11.5},
	{'Y', "九珍果汁饮料",       12.0},
	{'Z', "纯纯玉米饮",         11.0},
	{'\0', NULL,                0}
};

const struct SPECIAL special[] = {
	//{"ANV", "香辣鸡腿堡工作日午餐",    22}, //如果有需要，放开此项，注释掉下一行的“BMV”优惠，观察优惠菜单是否发生了变化
	{"BMV", "劲脆鸡腿堡超值套餐",    24},
	{"ABCGGIIKKOUWWW", "超值全家桶", 100},
	{"KIIRRJUWW", "缤纷小吃桶",  65},
	{"JJ","劲爆鸡米花(2份小)",      9.5},
	{NULL, NULL, 0}
};

/***************************************************************************
  函数名称：
  功    能：判断字母是否是大写，若是小写则改成大写
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int judge_letter(char letter[])
{
	for (int j = 0; letter[j]; j++) {

		if (letter[j] >= 'a' && letter[j] <= 'z')
			letter[j] += ('A' - 'a');

		if (letter[j] < 'A' || letter[j] > 'Z') {
			return 0;
		}

	}

	return 1;
}

/***************************************************************************
  函数名称：
  功    能：打印通过字母转化的食物名称
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void print_food(const char letter[])
{

	int cnt[26] = { 0 };//最多26样菜品，用来存储点单数量
	int flag = 0;//是否是第一个输出的名字，用来判断输出名字前是否输出"+"

	//记录各食物的数量
	for (int j = 0; letter[j]; j++) {

		cnt[letter[j] - 'A']++;

	}

	//输出菜名
	for (int j = 0; j < 26; j++) {

		if (cnt[j] > 0) {
			//如果不是第一个则先输出"+"
			if (flag) {
				cout << "+";
			}
			flag++;

			cout << list[j].name;

			//数量大于1则输出点单数量
			if (cnt[j] > 1)
				cout << "*" << cnt[j];
		}

	}

}

/***************************************************************************
  函数名称：
  功    能：输出优惠信息
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void print_special(const struct SPECIAL special[])
{

	cout << endl << "【优惠信息】：" << endl;
	for (int i = 0; special[i].price; i++) {

		cout << special[i].name << "=";

		print_food(special[i].letter);

		cout << "=" << special[i].price << endl;
	}

}

/***************************************************************************
  函数名称：
  功    能：将点单字母转化为对应价格(未处理优惠)
  输入参数：
  返 回 值：点单的价格
  说    明：
***************************************************************************/
double letter2price(const char letter[])
{
	double price = 0;

	for (int j = 0; letter[j]; j++) {
		price += list[letter[j] - 'A'].price;

	}
	return price;
}

/***************************************************************************
  函数名称：
  功    能：计算优惠折扣，不考虑优惠商品重复
  输入参数：
  返 回 值：总的优惠
  说    明：
***************************************************************************/
double discount(char letter[])
{

	double total_discount = 0;//总的优惠

	int cnt[26] = { 0 };
	for (int j = 0; letter[j]; j++) {

		cnt[letter[j] - 'A']++;

	}

	//依次判断每一种优惠的数量，直到遇到special[i].price==0
	for (int i = 0; special[i].price; i++) {
		/*
		int cnt[26] = { 0 };
		for (int j = 0; letter[j]; j++) {

			cnt[letter[j] - 'A']++;

		}*/


		int j = 0;
		while (1) {

			char ch = special[i].letter[j];

			//如果能读完优惠商品的字符串,则折扣累加
			if (ch == '\0') {
				total_discount += letter2price(special[i].letter) - special[i].price;//折扣为 原价-折扣价

				j = 0;//重新读优惠商品字符串
				continue;
			}


			if (cnt[ch - 'A'] <= 0) {
				//如果数组中对应点单数量已经为0，就不再进行该优惠的计算，直接进入下个优惠组合的计算
				
				for (; j >= 0; j--) {
					ch = special[i].letter[j];
					cnt[ch - 'A'] ++;//加回去 不在要求内 仅为了和demo一致 
				}
				 
				break;
			}
			else {
				//否则点单对应数量-1，并且j++，读取该组合的下一个商品
				cnt[ch - 'A']--;
				j++;
			}

		}

	}
	//cout << total_discount;
	return total_discount;
}

/***************************************************************************
  函数名称：
  功    能：打印点单信息
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void print_order(char letter[])
{
	double price = 0;


	if (judge_letter(letter)) {

		cout << "您的点餐=";
		print_food(letter);
		cout << endl;

		price = letter2price(letter) - discount(letter);
		cout << "共计：" << price << "元" << endl;
		cout << "点单完成，按任意键继续." << endl;
	}
	else {
		cout << "输入错误，按任意键继续." << endl;
	}

}

/***************************************************************************
  函数名称：
  功    能：打印菜单
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void menu()
{
	cout << "=============================================================" << endl;
	cout << "                      KFC 2021春季菜单						  " << endl;
	cout << "=============================================================" << endl;

	for (int i = 0; list[i].letter; i += 2) {
		cout << " " << list[i].letter << " " << setw(20) << setiosflags(ios::left)
			<< list[i].name << setw(7) << list[i].price
			<< "|   " << list[i + 1].letter << " " << setw(20)
			<< list[i + 1].name << setw(7) << list[i + 1].price << endl;
	}
	print_special(special);

	cout << endl;
	cout << "【输入规则说明】：" << endl;
	cout << "ANV=香辣鸡腿堡+薯条(小)+百事可乐(小) / akaak=香辣鸡腿堡*3+香辣鸡翅*2" << endl;
	cout << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl << endl;


}


/***************************************************************************
  函数名称：
  功    能：进行点单
  输入参数：
  返 回 值：0表示退出 1表示正常 2表示无输入
  说    明：
***************************************************************************/
int order()
{

	char letter[128];

	cout << "请点单: ";

	cin.getline(letter, 128);

	if (letter[0] == '0' && letter[1] == '\0') {
		return 0;
	}

	if (letter[0] == '\0') {
		return 2;
	}

	print_order(letter);

	return 1;
}


int main()
{
	system("mode con cols=120 lines=35");
	char ch;
	int ret;

	while (1) {

		system("cls");
		menu();

		ret = order();//接收返回值
		if (ret == 0)
			break; //按零退出

		if (ret == 2)
			continue; //无输入

		ch = _getch();//按任意键继续

	}
	   
	return 0;

}






