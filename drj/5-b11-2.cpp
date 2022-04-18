/* 1951650 ��02 ���ʽ� */
#include <iostream>
#include <string>
#include <cmath>
//�ɰ���������Ҫ��ͷ�ļ�
using namespace std;

const char chistr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/

/* �ֽ����֣�����Ϊ�����ʹӸߵ��͵ĵ�nλ(ʮ��λn=0) */
int fenjie(double num, int n)
{
    int w[15] = { 0 };   //�洢ÿһλ������
    int zheng = 0;  //����������/10
    double xiao; //�洢С��λ
    int i;
    w[0] = (int)(num / 1000000000.0);  //ʮ��λ��������
    zheng = (int)(num - w[0] * 1000000000.0); //��֤λ��0��10���ڣ���Խ��
    xiao = num - (w[0] * 1000000000.0 + zheng) + 0.001;  //��С�����ּӸ�0.001�ٳ���100������
    for (i = 9; i > 0; --i)
    {
        w[i] = zheng % 10;
        zheng = zheng / 10;
    }
    w[10] = (int)(xiao / 0.1);
    w[11] = (int)((xiao - w[10] * 0.1) / 0.01);

    return w[n];
}

/* λȨ����result����,�������Ϊ��ǰλ��i�͵�ǰ�ַ�����countֵ */
void input_weiquan(int i)    //�������������Ҫ��������
{
    const char weiquan[] = "ʰ��Ǫ����Բ�Ƿ���";
    switch (i)
    {
        case 0:
        case 4:
        case 8:
            result = result + weiquan[0] + weiquan[1];
            break;     //���"ʰ"
        case 3:
        case 7:
            result = result + weiquan[2] + weiquan[3];
            break;     //���"��"
        case 2:
        case 6:
            result = result + weiquan[4] + weiquan[5];
            break;     //���"Ǫ"
        case 5:
            result = result + weiquan[6] + weiquan[7];
            break;     //���"��"
        case 1:
            result = result + weiquan[8] + weiquan[9];
            break;     //���"��"
        case 9:
            result = result + weiquan[10] + weiquan[11];
            break;     //���"Բ"
        case 10:
            result = result + weiquan[12] + weiquan[13];
            break;     //���"��"
        case 11:
            result = result + weiquan[14] + weiquan[15];
            break;     //���"��"
    }
    return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    /* --���������Ҫ������ --*/

    double num;
    int cut[15] = { 0 };   //��΢����һЩ����ֹԽ��Σ��
    int i;
    int count = 0;
    const char ling[] = "Բ��a\0a";  //���ڶ�0�����кʹ�ӡ������,��ֹdev��warning��a����\0
    cout << "������[0-100��)֮�������: " << endl;
    cin >> num;
    for (i = 0; i < 12; ++i)       //�ѷֽ���ÿһλ�浽cut�����ʮ��λΪcut[0]
    {
        cut[i] = fenjie(num, i);
    }

    for (i = 0; i < 12; ++i)
    {
        if (count == 0 && cut[i] == 0)   //���ִ��Ч�ʣ�����ǰ�ߵĿ�0
        {
            continue;
        }
        if (cut[i] != 0)    //��λ��Ϊ0,������ù������ȥ
        {
            result = result + chistr[cut[i] * 2] + chistr[cut[i] * 2 + 1];
            input_weiquan(i);   //��λ����0��ʱ��ض����λȨ,count���¸�ֵ
            count++;
        }
        if (cut[i] == 0 && cut[i + 1] != 0 && i % 4 != 1)   //��λΪ0������жϺ�ʱ������㡱;  �������õ�cut[12],ǰ������Ҫ��һЩ
        {
            result = result + chistr[cut[i] * 2] + chistr[cut[i] * 2 + 1];
        }
        if (cut[i] == 0)   //�Ը�λΪ0���ж�
        {
            if (i == 1)
            {
                input_weiquan(i);
            }
            if (i == 5 && (cut[4] + cut[3] + cut[2]) != 0)  //���򼶲�ȫΪ0��ʱ���������
            {
                input_weiquan(i);
            }
            if (i == 9 && (cut[8] + cut[7] + cut[6] + cut[5] + cut[4] + cut[3] + cut[2] + cut[1] + cut[0]) != 0)
            {
                input_weiquan(i);
            }
        }
        if (i == 9 && (cut[10] + cut[11]) == 0)  //������,ֱ������
        {
            result = result + ling[2] + ling[3];
            break;
        }
        if (i == 10 && cut[11] == 0)  //������,ֱ������
        {
            result = result + ling[2] + ling[3];
            break;
        }
    }

    if (fabs(num) < 1e-6)  //��0����
    {
        result = result + chistr[0] + chistr[1] + ling[0] + ling[1] + ling[2] + ling[3];
    }
    cout << "��д����ǣ�" << endl;

    cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ���������֮ǰ�������κ���ʽ�Ĳ������ */
    return 0;
}
