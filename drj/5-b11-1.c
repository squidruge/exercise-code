/* 1951650 ��02 ���ʽ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
//�ɰ���������Ҫ��ͷ�ļ�

const char chistr[] = "��Ҽ��������½��ƾ�ʰ"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/

/* �ֽ����֣�����Ϊ�����ʹӸߵ��͵ĵ�nλ(ʮ��λn=0) */
int fenjie(double num, int n)
{
    int w[15] = { 0 };   //�洢ÿһλ������
    int zheng = 0;  //����������/10
    double xiao; //�洢С��λ
    int i;
    w[0] = (int)(num / 1000000000.0);  //ʮ��λ��������
    zheng = (int)(num - w[0]* 1000000000.0); //��֤λ��0��10���ڣ���Խ��
    xiao = num - (w[0] * 1000000000.0 + zheng) + 0.001;  //��С�����ּӸ�0.001�ٳ���100������
    for (i = 9; i > 0; --i)
    {
        w[i] = zheng % 10;
        zheng = zheng / 10;
    }
    w[10] = (int)(xiao / 0.1);
    w[11] = (int)((xiao-w[10]*0.1)/0.01);

    return w[n];
}

/* λȨ����result����,�������Ϊ��ǰλ��i */
void input_weiquan(int i)    //�������������Ҫ��������
{
    const char weiquan[] = "ʰ��Ǫ����Բ�Ƿ���";   
    switch (i)
    {
        case 0:
        case 4:
        case 8:
            strncat(result, &weiquan[0], 2);
            break;     //���"ʰ"
        case 3:
        case 7:
            strncat(result, &weiquan[2], 2);
            break;     //���"��"
        case 2:
        case 6:
            strncat(result, &weiquan[4], 2);
            break;     //���"Ǫ"
        case 5:
            strncat(result, &weiquan[6], 2);
            break;     //���"��"
        case 1:
            strncat(result, &weiquan[8], 2);
            break;     //���"��"
        case 9:
            strncat(result, &weiquan[10], 2);
            break;     //���"Բ"
        case 10:
            strncat(result, &weiquan[12], 2);
            break;     //���"��"
        case 11:
            strncat(result, &weiquan[14], 2);
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
    int judge = 0;
    const char ling[] = "Բ��a\0a";  //���ڶ�0�����кʹ�ӡ������,��ֹdev��warning��a����\0
    printf("������[0-100��)֮�������: \n");
    scanf("%lf", &num);
    for (i = 0; i < 12; ++i)       //�ѷֽ���ÿһλ�浽cut�����ʮ��λΪcut[0]
    {
        cut[i] = fenjie(num, i);       
    }

    for (i = 0; i < 12; ++i)
    {
        if (judge==0 && cut[i] == 0)   //���ִ��Ч�ʣ�����ǰ�ߵĿ�0
        {
            continue;
        }
        if (cut[i] != 0)    //��λ��Ϊ0,������ù������ȥ
        {
            strncat(result, &chistr[cut[i] * 2], 2);
            input_weiquan(i);   //��λ����0��ʱ��ض����λȨ,count���¸�ֵ
            judge++;
        }
        if (cut[i] == 0 && cut[i + 1] != 0 && i % 4 != 1)   //��λΪ0������жϺ�ʱ������㡱;  �������õ�cut[12],ǰ������Ҫ��һЩ
        {
            strncat(result, &chistr[cut[i] * 2], 2);
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
            if (i == 9 && (cut[8] + cut[7] + cut[6]+ cut[5] + cut[4] + cut[3]+ cut[2] + cut[1] + cut[0]) != 0)
            {
                input_weiquan(i);
            }
        }
        if (i == 9 && (cut[10] + cut[11]) == 0)  //������,ֱ������
        {
            strncat(result, &ling[2], 2);
            break;
        }
        if (i == 10 && cut[11] == 0)  //������,ֱ������
        {
            strncat(result, &ling[2], 2);
            break;
        }
    }
    
    if (fabs(num) > 1e-6)
    {
        strncat(result, &ling[5], 1);    //����һ��\0
    }

    if (fabs(num) < 1e-6)  //��0����
    {
        strncat(result, chistr, 2);
        strcat(result, ling);        
        result[6] = '\0';
    }
    printf("��д����ǣ�\n");
    printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ���������֮ǰ�������κ���ʽ�Ĳ������ */
    return 0;
}
