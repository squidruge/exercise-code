/*1951393 �Զ��� �����*/

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;

#define MAX_STU_NUM			150	//Լ���������Ϊ150�ˣ����ֵ��ܺͣ�������ѡ����ѡ��
#define MAX_NAME_LEN			20	//��������󳤶Ȳ�����9������
#define MAX_FILENAME_LEN		256	//�ļ�������󳤶�

class stu_list;
/* stu_info ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_info {
private:
	int  stu_no;			//ѧ��
	char stu_name[MAX_NAME_LEN];	//����

	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	char round_1[5] = { '\0' };
	char round_2[5] = { '\0' };
	friend class stu_list;

public:
	/* ���಻�������κεĹ������ݳ�Ա����Ա���� */
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];

	/* ���������private���ݳ�Ա�ͳ�Ա���� */
	int cnt=0;

public:
	int read(const char* filename, const int append = 0);	//���ļ��ж���ѡ����Ϣ�����д�����2������ֵΪ0��ʾ���Ƿ�ʽ��1��ʾ׷�ӷ�ʽ
	int print(const char* prompt = NULL);			//��ӡ��ǰ�����ѡ������

	/* �������������public��Ա���� */

};

/* --- �˴���������������ĳ�Ա����������ʵ�� --- */
int stu_list::read(const char* filename, const int append)
{
	//stu_info temp[MAX_STU_NUM + 1];//�ݴ��ȡ������
	stu_info temp;//�ݴ�


	ifstream in(filename, ios::in);

	if (in.is_open() == 0) {
		cerr << "�ļ�[" << filename << "]��ʧ��" << endl;
		return -1;
	}
	if (append == 0) {

		cnt = 0;

		//����
		while (1) {
			cnt++;

			in >> stu[cnt].stu_no;
			if (in.eof()) {
				cnt--;
				in.clear();
				break;
			}


			in >> stu[cnt].stu_name;
			if (in.eof()) {
				cnt--;
				in.clear();

				break;
			}

			strcpy(stu[cnt].round_1, "Y");
			strcpy(stu[cnt].round_2, "�˿�");

		}


		//����
		for (int i = 1; i <= cnt; i++) {
			for (int j = i + 1; j <= cnt; j++) {
				if (stu[i].stu_no > stu[j].stu_no) {
					temp.stu_no = stu[i].stu_no;
					stu[i].stu_no = stu[j].stu_no;
					stu[j].stu_no = temp.stu_no;

					strcpy(temp.stu_name, stu[i].stu_name);
					strcpy(stu[i].stu_name, stu[j].stu_name);
					strcpy(stu[j].stu_name, temp.stu_name);
				}
			}
		}

	}
	else {
		while (1) {
			//��append�������ݴ���temp
			in >> temp.stu_no;
			if (in.eof()) {
				in.clear();
				break;
			}

			in >> temp.stu_name;
			if (in.eof()) {
				in.clear();
				break;
			}
			//���ǰһ��������
			if (cnt == 0) {
				strcpy(stu[cnt + 1].stu_name, temp.stu_name);
				stu[cnt + 1].stu_no = temp.stu_no;
				strcpy(stu[cnt + 1].round_1, "/");
				strcpy(stu[cnt + 1].round_2, "��ѡ");
				cnt++;
				continue;
			}
			//�ж����ֶ�ѡ�˵�
			int i;
			for (i = 1; i <= cnt; i++) {
				if (stu[i].stu_no == temp.stu_no) {
					strcpy(stu[i].round_2, "Y");
					break;
				}
			}
			//��i��Ϊ�ڱ��ж�
			if (cnt >= i)
				continue;

			//Ҫ��ӵ�λ������ǵ�һ��
			for (int j = 1; j <= cnt; j++) {

				if (j == 1 && temp.stu_no < stu[j].stu_no)
				{
					for (int k = cnt; k >= j; k--) {
						strcpy(stu[k + 1].stu_name, stu[k].stu_name);
						stu[k + 1].stu_no = stu[k].stu_no;
						strcpy(stu[k + 1].round_1, stu[k].round_1);
						strcpy(stu[k + 1].round_2, stu[k].round_2);
					}

					strcpy(stu[1].stu_name, temp.stu_name);
					stu[1].stu_no = temp.stu_no;
					strcpy(stu[1].round_1, "/");
					strcpy(stu[1].round_2, "��ѡ");
					cnt++;
					break;
				}


				//��ѧ��֮�䣬��������һ��
				if (temp.stu_no > stu[j].stu_no) {

					if (cnt != j && temp.stu_no < stu[j + 1].stu_no) {
						for (int k = cnt; k >= j + 1; k--) {
							strcpy(stu[k + 1].stu_name, stu[k].stu_name);
							stu[k + 1].stu_no = stu[k].stu_no;
							strcpy(stu[k + 1].round_1, stu[k].round_1);
							strcpy(stu[k + 1].round_2, stu[k].round_2);
						}
					}

					if (temp.stu_no < stu[j + 1].stu_no || cnt == j) {
						strcpy(stu[j + 1].stu_name, temp.stu_name);
						stu[j + 1].stu_no = temp.stu_no;
						strcpy(stu[j + 1].round_1, "/");
						strcpy(stu[j + 1].round_2, "��ѡ");
						cnt++;
						break;
					}

				}

			}//end of for

		}//end of while
	}//end of else

	in.close();
	return 1;
}
 
int stu_list::print(const char* prompt)
{

	cout << prompt << endl;
	cout << "===========================================" << endl;
	cout << "��� ѧ��    ����             ��һ�� �ڶ���" << endl;
	cout << "===========================================" << endl;
	for (int i = 1; i <= cnt; i++) {
		cout << setiosflags(ios::left) << setw(5) << i
			<< setw(8) << stu[i].stu_no << setw(17) << stu[i].stu_name
			<< setw(7) << stu[i].round_1 << setw(7) << stu[i].round_2 << endl;

	}
	printf("===========================================\n");
	return 1;
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

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	cin >> file1;
	cout << "�������һ��ѡ�ε������ļ� : ";
	cin >> file2;

	stu_list list;

	/* �����һ�������ļ� */
	if (list.read(file1) < 0)
		return -1;

#if 0
	/* ������궨�壬���Դ�ӡ���ֶ����ѡ�����������ڵ��� */
	list.print("ǰһ��ѡ������");
	cout << endl << endl;
#endif

	/* ����ڶ��������ļ�������2��ֵΪ1��ʾ׷�ӷ�ʽ */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("����ѡ������");

	return 0;
}