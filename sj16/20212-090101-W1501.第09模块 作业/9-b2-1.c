/*1951393 �Զ��� �����*/

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_STU_NUM			150	//Լ���������Ϊ150�ˣ����ֵ��ܺͣ�������ѡ����ѡ��
#define MAX_NAME_LEN			20	//��������󳤶Ȳ�����9������
#define MAX_FILENAME_LEN		256	//�ļ�������󳤶�

/* ������Ҫ�Ķ��� */

/* ����stu_list�Ķ��� */   
struct stu_list {
	int  stu_no;			//ѧ��
	char stu_name[MAX_NAME_LEN];	//����
	char round_1[5] ;
	char round_2[5] ;

};

/* ����������Ҫ�ĺ�����ʵ�� */

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ش��˶��ٸ����� 
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�
  ��    �ܣ�
  ���������append : 0 : ���Ƿ�ʽ
					 1 : ׷�ӷ�ʽ
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int read_stulist(const char* filename, struct stu_list* C, const int append)
{
	struct stu_list temp = { 0 };//�ݴ�
	int cnt;//���� ��1��ʼ ��Ӧ���1
	FILE* fp;

	if ((fp = fopen(filename, "r")) == NULL) {
		printf( "�ļ�[%s]��ʧ��\n", filename);

		return -1;
	}   
	
	if (append == 0) {

		cnt = 0;

		//����
		while (1) {
			cnt++;

			fscanf(fp, "%d %s", &(C[cnt].stu_no), C[cnt].stu_name);

			if (feof(fp)) {
				cnt--;
				break;
			}
			strcpy(C[cnt].round_1 , "Y");
			strcpy(C[cnt].round_2, "�˿�");

		}


		//����
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
			//��append�������ݴ���temp
			fscanf(fp, "%d %s", &(temp.stu_no),temp.stu_name);

			if (feof(fp)) {
				cnt--;
				break;
			}
			//���ǰһ��������
			if (cnt == 0) {
				strcpy(C[cnt + 1].stu_name, temp.stu_name);
				C[cnt + 1].stu_no = temp.stu_no;
				strcpy(C[cnt + 1].round_1, "/");
				strcpy(C[cnt + 1].round_2, "��ѡ");
				cnt++;
				continue;
			}
			//�ж����ֶ�ѡ�˵�
			int i,j,k;
			for (i = 1; i <= cnt; i++) {
				if (C[i].stu_no == temp.stu_no) {
					strcpy(C[i].round_2, "Y");
					break;
				}
			}
			//��i��Ϊ�ڱ��ж�
			if (cnt >= i)
				continue;

			//Ҫ��ӵ�λ������ǵ�һ��
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
					strcpy(C[1].round_2, "��ѡ");
					cnt++;
					break;
				}


				//��ѧ��֮�䣬��������һ��
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
						strcpy(C[j + 1].round_2, "��ѡ");
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int print_stulist(const struct stu_list* const list, const char* prompt)
{
	int cnt = get_cnt(list);
	printf("%s\n", prompt);
	printf("===========================================\n");
	printf("��� ѧ��    ����             ��һ�� �ڶ���\n");
	printf("===========================================\n");
	for (int i = 1; i <= cnt; i++) {
		printf("%-5d%-8d%-17s%-7s%-7s\n", i, list[i].stu_no, list[i].stu_name, list[i].round_1, list[i].round_2);


	}
	printf("===========================================\n");
	return 1;

	//return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	printf("������ǰһ��ѡ�ε������ļ� : ");
	scanf("%s", file1);
	printf("�������һ��ѡ�ε������ļ� : ");
	scanf("%s", file2);

	struct stu_list list[MAX_STU_NUM + 1] = { 0 };

	if (read_stulist(file1, list, 0) < 0)
		return -1;
#if 0
	/* ������궨�壬���Դ�ӡ���ֶ����ѡ�����������ڵ��� */
	print_stulist(list, "ǰһ��ѡ������");
	printf("\n\n");
#endif

	if (read_stulist(file2, list, 1) < 0)
		return -1;

	print_stulist(list, "����ѡ������");

	return 0;
}
