/*1951393 自动化 张儒戈*/

/* 允许按需加入系统的宏定义、需要的头文件等 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_STU_NUM			150	//约定最大人数为150人（两轮的总和，包括退选、补选）
#define MAX_NAME_LEN			20	//姓名的最大长度不超过9个汉字
#define MAX_FILENAME_LEN		256	//文件名的最大长度

/* 给出需要的定义 */

/* 给出stu_list的定义 */   
struct stu_list {
	int  stu_no;			//学号
	char stu_name[MAX_NAME_LEN];	//姓名
	char round_1[5] ;
	char round_2[5] ;

};  

/* 给出其它需要的函数的实现 */

/***************************************************************************
  函数名称：
  功    能：返回存了多少个数据 
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int get_cnt(const struct stu_list* const list) {
	int cnt = 0;
	for ( cnt = 1; cnt <= MAX_STU_NUM; cnt++) {
		if (list[cnt].round_1[0] == '\0') {
			cnt--;
			break;
		}
	}
	return cnt;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：append : 0 : 覆盖方式
					 1 : 追加方式
  返 回 值：
  说    明：
***************************************************************************/
int read_stulist(const char* filename, struct stu_list* C, const int append)
{
	struct stu_list temp = { 0 };//暂存
	int cnt;//计数 从1开始 对应序号1
	FILE* fp;

	if ((fp = fopen(filename, "r")) == NULL) {
		printf( "文件[%s]打开失败\n", filename);

		return -1;
	}   
	
	if (append == 0) {

		cnt = 0;

		//输入
		while (1) {
			cnt++;

			fscanf(fp, "%d %s", &(C[cnt].stu_no), C[cnt].stu_name);

			if (feof(fp)) {
				cnt--;
				break;
			}
			strcpy(C[cnt].round_1 , "Y");
			strcpy(C[cnt].round_2, "退课");

		}


		//排序
		int i ,j;
		for (i = 1; i <= cnt; i++) {
			for ( j = i + 1; j <= cnt; j++) {
				if (C[i].stu_no > C[j].stu_no) {
					temp.stu_no = C[i].stu_no;
					C[i].stu_no = C[j].stu_no;
					C[j].stu_no = temp.stu_no;

					strcpy(temp.stu_name, C[i].stu_name);
					strcpy(C[i].stu_name, C[j].stu_name);
					strcpy(C[j].stu_name, temp.stu_name);
				}
			}
		}

	}
	else {
		cnt = get_cnt(C);
		while (1) {
			//将append的内容暂存入temp
			fscanf(fp, "%d %s", &(temp.stu_no),temp.stu_name);

			if (feof(fp)) {
				cnt--;
				break;
			}
			//如果前一轮无数据
			if (cnt == 0) {
				strcpy(C[cnt + 1].stu_name, temp.stu_name);
				C[cnt + 1].stu_no = temp.stu_no;
				strcpy(C[cnt + 1].round_1, "/");
				strcpy(C[cnt + 1].round_2, "补选");
				cnt++;
				continue;
			}
			//判断两轮都选了的
			int i,j,k;
			for (i = 1; i <= cnt; i++) {
				if (C[i].stu_no == temp.stu_no) {
					strcpy(C[i].round_2, "Y");
					break;
				}
			}
			//用i作为哨兵判断
			if (cnt >= i)
				continue;

			//要添加的位置如果是第一个
			for (j = 1; j <= cnt; j++) {

				if (j == 1 && temp.stu_no < C[j].stu_no)
				{
					for ( k = cnt; k >= j; k--) {
						strcpy(C[k + 1].stu_name,C[k].stu_name);
						C[k + 1].stu_no = C[k].stu_no;
						strcpy(C[k + 1].round_1, C[k].round_1);
						strcpy(C[k + 1].round_2, C[k].round_2);
					}

					strcpy(C[1].stu_name, temp.stu_name);
					C[1].stu_no = temp.stu_no;
					strcpy(C[1].round_1, "/");
					strcpy(C[1].round_2, "补选");
					cnt++;
					break;
				}


				//两学号之间，或大于最后一个
				if (temp.stu_no > C[j].stu_no) {

					if (cnt != j && temp.stu_no < C[j + 1].stu_no) {
						for (int k = cnt; k >= j + 1; k--) {
							strcpy(C[k + 1].stu_name, C[k].stu_name);
							C[k + 1].stu_no = C[k].stu_no;
							strcpy(C[k + 1].round_1, C[k].round_1);
							strcpy(C[k + 1].round_2, C[k].round_2);
						}
					}

					if (temp.stu_no < C[j + 1].stu_no || cnt == j) {
						strcpy(C[j + 1].stu_name, temp.stu_name);
						C[j + 1].stu_no = temp.stu_no;
						strcpy(C[j + 1].round_1, "/");
						strcpy(C[j + 1].round_2, "补选");
						cnt++;
						break;
					}

				}

			}//end of for

		}//end of while
	}//end of else

	fclose(fp);
	return 1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int print_stulist(const struct stu_list* const list, const char* prompt)
{
	int cnt = get_cnt(list);
	printf("%s\n", prompt);
	printf("===========================================\n");
	printf("序号 学号    姓名             第一轮 第二轮\n");
	printf("===========================================\n");
	for (int i = 1; i <= cnt; i++) {
		printf("%-5d%-8d%-17s%-7s%-7s\n", i, list[i].stu_no, list[i].stu_name, list[i].round_1, list[i].round_2);


	}
	printf("===========================================\n");
	return 1;

	//return 0;
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

	struct stu_list list[MAX_STU_NUM + 1] = { 0 };

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
