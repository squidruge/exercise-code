/* 1951650 ��02 ���ʽ� */

#include <cstdio>   //NULL
//������������κ�ϵͳͷ�ļ�

/* ----- ���������κ���ʽ��ȫ�ֱ���/ȫ������/ֻ��ȫ�ֱ���/�궨��!!!!! ----- */

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��returnֻ��һ��ʾ�����ɸı� */
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strlen(const char* str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    const char* p = str;
    if (p == NULL)
    {
        return 0;
    }
    while (*p != '\0')
    {
        p++;
    }
    return p - str;  //����ֵ��ָ��ı仯��
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int lenth_s2 = tj_strlen(s2);
    int lenth_s1 = tj_strlen(s1);
    char* dst = s1 + lenth_s1;  //��dst���ƴ�Ӳ���
    if (s1 != NULL && s2 != NULL)   //���������������ٽ�������,����ֱ�ӷ���s1
    {   
        while (*s2 != '\0')
        {
            *dst = *s2;
            dst++;
            s2++;
        }
        *dst = '\0';  //�����β��
    }
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char* tj_strncat(char* s1, const char* s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int lenth_s1 = tj_strlen(s1);  //��s1�ĳ���
    int lenth_s2 = tj_strlen(s2);
    char* dst = s1 + lenth_s1;
    if (s1 != NULL && s2 != NULL)  //������null�ٲ���
    {
        if (len > lenth_s2)   //len���ȴ������ַ������ȣ�ֱ��ȫ����ȥ
        {
            tj_strcat(s1, s2);
        }
        else
        {
            while (dst - s1 < lenth_s1 + len)
            {
                *dst = *s2;
                dst++;
                s2++;
            }            
            *dst = '\0';  //������β��
        }
    }
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char* tj_strcpy(char* s1, const char* s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char* dst = s1;
    if (s1 == NULL)
    {
        return s1;
    }
    if (s2 == NULL)
    {
        *dst = '\0';
        return s1;
    } 
    while (*s2 != '\0')  //������NULL��ʱ��
    {
        *dst = *s2;
        dst++;
        s2++;
    }
    *dst = '\0';   //�ֶ���β��
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char* tj_strncpy(char* s1, const char* s2, const int len)
{
    int lenth_s2 = tj_strlen(s2);
    char* dst = s1;
    if (s1 == NULL || s2 == NULL)   //����NULL������
    {
        return s1;
    }
    if (lenth_s2 < len)  //���ȳ��������ƴ�
    {
        while (dst - s1 < lenth_s2)
        {
            *dst = *s2;
            dst++;
            s2++;
        }
    }
    else
    {
        while (dst - s1 < len)
        {
            *dst = *s2;
            dst++;
            s2++;
        }
    }
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcmp(const char* s1, const char* s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 != NULL)
    {
        return -1;
    }
    if (s2 == NULL && s1 != NULL)
    {
        return 1;
    }
    if (s1 == NULL && s2 == NULL)
    {
        return 0;
    }    //����Ϊ����
    while (*s1 == *s2)
    {
        if (*s1 == '\0')
        {
            return 0;
        }
        s1++;
        s2++;
    }
    return (*s1 - *s2);   //����ȣ�����
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasecmp(const char* s1, const char* s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char tmp_s1, tmp_s2;
    if (s1 == NULL && s2 != NULL)
    {
        return -1;
    }
    if (s2 == NULL && s1 != NULL)
    {
        return 1;
    }
    if (s1 == NULL && s2 == NULL)
    {
        return 0;
    }    //����Ϊ����
    while (*s1 != '\0' && *s2 != '\0')
    {
        tmp_s1 = *s1;  //��һ�γ�ʼ��
        tmp_s2 = *s2;
        if (*s1 >= 'A' && *s1 <= 'Z')
        {
            tmp_s1 = *s1 + 'a' - 'A';     //s1��д��Сд�ٳ�ʼ����tmp
        }
        if (*s2 >= 'A' && *s2 <= 'Z')
        {
            tmp_s2 = *s2 + 'a' - 'A';     //s2��д��Сд�ٳ�ʼ����tmp
        }
        ++s1;
        ++s2;
        if (tmp_s1 == tmp_s2)
        {
            continue;
        }
        else
        {
            return (tmp_s1 - tmp_s2);
        }
    }
    //����ѭ��������������һ���Ѿ��ߵ���ĩβ��\0�� 
    if (*s1 >= 'A' && *s1 <= 'Z')  //����s1�Ǵ�д��ĸ����s2�ض���\0
    {
        return (*s1 + 'a' - 'A' - '\0');
    }
    if (*s2 >= 'A' && *s2 <= 'Z')  //����s2�Ǵ�д��ĸ����s1�ض���\0
    {
        return ('\0' - (*s2 + 'a' - 'A'));
    }

    return (*s1 - *s2);   //�����û�д�д��ĸ
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strncmp(const char* s1, const char* s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 != NULL)
    {
        return -1;
    }
    if (s2 == NULL && s1 != NULL)
    {
        return 1;
    }
    if (s1 == NULL && s2 == NULL)
    {
        return 0;
    }    //����Ϊ����
    int lenth_s1 = tj_strlen(s1);
    int lenth_s2 = tj_strlen(s2);
    int lenth_min;
    int judge = 0;  //�����ж��ǲ���len������min
    const char* ps1 = s1;
    const char* ps2 = s2;
    if (lenth_s1 >= lenth_s2)
    {
        lenth_min = lenth_s2;
    }
    else
    {
        lenth_min = lenth_s1;
    }
    //ȷ�����ߵ��н϶̵Ĵ���
    if (len > lenth_min)
    {
        judge = 1;
        while (*ps1 != '\0' && *ps2 != '\0')  //��while������˵��������
        {
            if (*ps1 == *ps2)   //��ȼ���
            {
                ps1++;
                ps2++;
                continue;
            }
            else       //����Ⱦͷ���
            {
                return (*ps1 - *ps2);
            }
        }
    }
    else
    {
        while (ps1 - s1 < len)
        {
            if (*ps1 == *ps2)   //��ȼ���
            {
                ps1++;
                ps2++;
                continue;
            }
            else       //����Ⱦͷ���
            {
                return (*ps1 - *ps2);
            }
        }
    }
    if (judge)
    {
        return (*ps1 - *ps2);  //return����֮��
    }
    else  //���2����return0
    {
        return 0;
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 != NULL)
    {
        return -1;
    }
    if (s2 == NULL && s1 != NULL)
    {
        return 1;
    }
    if (s1 == NULL && s2 == NULL)
    {
        return 0;
    }    //����Ϊ����
    int lenth_s1 = tj_strlen(s1);
    int lenth_s2 = tj_strlen(s2);
    int lenth_min;
    int tmp_s1, tmp_s2;
    const char* ps1 = s1;
    const char* ps2 = s2;
    if (lenth_s1 >= lenth_s2)
    {
        lenth_min = lenth_s2;
    }
    else
    {
        lenth_min = lenth_s1;
    }
    //ȷ�����ߵ��н϶̵Ĵ���
    if (len > lenth_min)   //��ʱ�ͱȵ��̵Ľ���
    {
        while (*ps1 != '\0' && *ps2 != '\0')
        {
            tmp_s1 = *ps1;  //��һ�γ�ʼ��
            tmp_s2 = *ps2;
            if (*ps1 >= 'A' && *ps1 <= 'Z')
            {
                tmp_s1 = *ps1 + 'a' - 'A';     //s1��д��Сд�ٳ�ʼ����tmp
            }
            if (*ps2 >= 'A' && *ps2 <= 'Z')
            {
                tmp_s2 = *ps2 + 'a' - 'A';     //s2��д��Сд�ٳ�ʼ����tmp
            }
            ++ps1;
            ++ps2;
            if (tmp_s1 == tmp_s2)
            {
                continue;
            }
            else
            {
                return (tmp_s1 - tmp_s2);
            }
        }
        //����ѭ��������������һ���Ѿ��ߵ���ĩβ��\0�� 
        if (*ps1 >= 'A' && *ps1 <= 'Z')  //����s1�Ǵ�д��ĸ����s2�ض���\0
        {
            return (*ps1 + 'a' - 'A' - '\0');
        }
        if (*ps2 >= 'A' && *ps2 <= 'Z')  //����s2�Ǵ�д��ĸ����s1�ض���\0
        {
            return ('\0' - (*ps2 + 'a' - 'A'));
        }

        return *ps1 - *ps2;   //�����û�д�д��ĸ
    }
    else
    {
        while (ps1 - s1 < len)
        {
            tmp_s1 = *ps1;  //��һ�γ�ʼ��
            tmp_s2 = *ps2;
            if (*ps1 >= 'A' && *ps1 <= 'Z')
            {
                tmp_s1 = *ps1 + 'a' - 'A';     //s1��д��Сд�ٳ�ʼ����tmp
            }
            if (*ps2 >= 'A' && *ps2 <= 'Z')
            {
                tmp_s2 = *ps2 + 'a' - 'A';     //s2��д��Сд�ٳ�ʼ����tmp
            }
            //��������˳�ʼ���Ĺ���
            ++ps1;
            ++ps2;
            if (tmp_s1 == tmp_s2)
            {
                continue;
            }
            else
            {
                return (tmp_s1 - tmp_s2);
            }
        }   //����while˵���Ѿ��Ƚ����ˣ���δ�����쳣
        return 0;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char* tj_strupr(char* str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL)  //����str��null��ʱ��
    {
        return str;
    }
    char* p_str = str;
    while (*p_str != '\0')
    {
        if (*p_str >= 'a' && *p_str <= 'z')
        {
            *p_str = *p_str + 'A' - 'a';
        }
        p_str++;
    }
    return str;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char* tj_strlwr(char* str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL)  //����str��null��ʱ��
    {
        return str;
    }
    char* p_str = str;
    while (*p_str != '\0')
    {
        if (*p_str >= 'A' && *p_str <= 'Z')
        {
            *p_str = *p_str + 'a' - 'A';
        }
        p_str++;
    }
    return str;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strchr(const char* str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL) //���У������NULL��ֱ�ӷ���0
    {
        return 0;
    }
    const char* p_str = str;
    while (*p_str != '\0')
    {
        if (*p_str == ch)
        {
            return (p_str - str + 1);
        }
        ++p_str;
    }
    return 0; //������Ҳû�ҵ���return0
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strstr(const char* str, const char* substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL || substr == NULL)  //���з���0
    {
        return 0;
    }
    int lenth = tj_strlen(str); //�õ�����
    int lenth_sub = tj_strlen(substr);
    const char* pstr = str;
    const char* psubstr = substr;
    const char* tmpstr = str;
    while (pstr - str < lenth)
    {       
        if (*pstr == *substr)
        {
            while (psubstr - substr < lenth_sub)
            {
                if (*pstr != *psubstr)  //�ҵ����ȵ��˾�����
                {
                    break;
                }
                psubstr++;
                pstr++;
            }
            if (psubstr - substr == lenth_sub) //��ʱ˵��������break�����ģ���������
            {
                return tmpstr - str + 1;
            }
        }
        tmpstr++;   //�ݴ浱ǰ���ָ��ĵ�ַ,����ַ�����ƶ�һ��
        pstr = tmpstr;
        psubstr = substr;   //���³�ʼ������       
    }
    return 0;  //������������û�ҵ�,����0
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrchr(const char* str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL) //���У������NULL��ֱ�ӷ���0
    {
        return 0;
    }
    int lenth = tj_strlen(str); //�õ�����
    const char* p_str = str + lenth - 1;  //ָ�����һ��
    while (p_str - str >= 0)
    {
        if (*p_str == ch)
        {
            return p_str - str + 1;
        }
        p_str--;
    }
    return 0;  //û�ҵ�����0
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrstr(const char* str, const char* substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL || substr == NULL)  //���з���0
    {
        return 0;
    }
    int lenth = tj_strlen(str); //�õ�����
    int lenth_sub = tj_strlen(substr);
    const char* pstr = str + lenth - 1;   //ָ�򴮵�ĩβ
    const char* psubstr = substr + lenth_sub - 1;
    const char* tmpstr = str + lenth - 1;
    while (pstr - str >= 0)
    {
        if (*pstr == *psubstr)
        {
            while (psubstr - substr >= 0)
            {
                if (*pstr != *psubstr)  //�ҵ����ȵ��˾�����
                {
                    break;
                }
                psubstr--;
                pstr--;
            }
            if (psubstr - substr == -1) //��ʱ˵��������break�����ģ���������
            {
                return tmpstr - str - lenth_sub + 2;
            }
        }
        tmpstr--;   //�ݴ浱ǰ���ָ��ĵ�ַ,����ַ�����ƶ�һ��
        pstr = tmpstr;
        psubstr = substr + lenth_sub - 1;   //���³�ʼ������       
    }
    return 0;  //������������û�ҵ�,����0
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char* tj_strrev(char* str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL)
    {
        return str;
    }
    int lenth = tj_strlen(str);
    char* p_str = str + lenth - 1;  //β��
    char* p_strs = str;  //ͷ
    char tmp;
    while (p_str > p_strs)
    {
        tmp = *p_strs;
        *p_strs = *p_str;
        *p_str = tmp;
        p_str--;
        p_strs++;
    }
    return str;
}