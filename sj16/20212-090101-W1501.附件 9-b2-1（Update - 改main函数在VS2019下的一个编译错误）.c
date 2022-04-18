/* 学号 班级 姓名 */

/* 允许按需加入系统的宏定义、需要的头文件等 */
#include <stdio.h>

#define MAX_STU_NUM			150	//约定最大人数为150人（两轮的总和，包括退选、补选）
#define MAX_NAME_LEN			20	//姓名的最大长度不超过9个汉字
#define MAX_FILENAME_LEN		256	//文件名的最大长度

/* 给出需要的定义 */

/* 给出stu_list的定义 */
struct stu_list {

};

/* 给出其它需要的函数的实现 */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：append : 0 : 覆盖方式
                     1 : 追加方式
  返 回 值：
  说    明：
***************************************************************************/
int read_stulist(const char* filename, struct stu_list* list, const int append)
{
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int print_stulist(const struct stu_list* const list, const char *prompt)
{
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	printf("请输入前一轮选课的数据文件 : ");
	scanf("%s", file1);
	printf("请输入后一轮选课的数据文件 : ");
	scanf("%s", file2);

	struct stu_list list[MAX_STU_NUM + 1]={ 0 };

	if (read_stulist(file1, list, 0) < 0)
		return -1;
#if 0
	/* 打开这个宏定义，可以打印首轮读入的选课名单，用于调试 */
	print_stulist(list, "前一轮选课名单");
	printf("\n\n");
#endif

	if (read_stulist(file2, list, 1) < 0)
		return -1;

	print_stulist(list, "最终选课名单");

	return 0;
}

