/* 1951650 信02 戴仁杰 */

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p = str;
    if (p == NULL)
    {
        return 0;
    }
    while (*p != '\0')
    {
        p++;
    }
    return p - str;  //返回值是指针的变化量
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int lenth_s2 = tj_strlen(s2);
    int lenth_s1 = tj_strlen(s1);
    char* dst = s1 + lenth_s1;  //用dst完成拼接操作
    if (s1 != NULL && s2 != NULL)   //如果不是上述情况再进行连接,否则直接返回s1
    {   
        while (*s2 != '\0')
        {
            *dst = *s2;
            dst++;
            s2++;
        }
        *dst = '\0';  //最后补上尾零
    }
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncat(char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int lenth_s1 = tj_strlen(s1);  //求s1的长度
    int lenth_s2 = tj_strlen(s2);
    char* dst = s1 + lenth_s1;
    if (s1 != NULL && s2 != NULL)  //都不是null再操作
    {
        if (len > lenth_s2)   //len长度大于了字符串长度，直接全接上去
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
            *dst = '\0';  //补最后的尾零
        }
    }
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strcpy(char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
    while (*s2 != '\0')  //都不是NULL的时候
    {
        *dst = *s2;
        dst++;
        s2++;
    }
    *dst = '\0';   //手动补尾零
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncpy(char* s1, const char* s2, const int len)
{
    int lenth_s2 = tj_strlen(s2);
    char* dst = s1;
    if (s1 == NULL || s2 == NULL)   //特判NULL的问题
    {
        return s1;
    }
    if (lenth_s2 < len)  //长度超过被复制串
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
    }    //以上为特判
    while (*s1 == *s2)
    {
        if (*s1 == '\0')
        {
            return 0;
        }
        s1++;
        s2++;
    }
    return (*s1 - *s2);   //不相等，跳出
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
    }    //以上为特判
    while (*s1 != '\0' && *s2 != '\0')
    {
        tmp_s1 = *s1;  //第一次初始化
        tmp_s2 = *s2;
        if (*s1 >= 'A' && *s1 <= 'Z')
        {
            tmp_s1 = *s1 + 'a' - 'A';     //s1大写变小写再初始化给tmp
        }
        if (*s2 >= 'A' && *s2 <= 'Z')
        {
            tmp_s2 = *s2 + 'a' - 'A';     //s2大写变小写再初始化给tmp
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
    //上述循环跳出，代表有一个已经走到了末尾即\0处 
    if (*s1 >= 'A' && *s1 <= 'Z')  //代表s1是大写字母，则s2必定是\0
    {
        return (*s1 + 'a' - 'A' - '\0');
    }
    if (*s2 >= 'A' && *s2 <= 'Z')  //代表s2是大写字母，则s1必定是\0
    {
        return ('\0' - (*s2 + 'a' - 'A'));
    }

    return (*s1 - *s2);   //俩里边没有大写字母
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
    }    //以上为特判
    int lenth_s1 = tj_strlen(s1);
    int lenth_s2 = tj_strlen(s2);
    int lenth_min;
    int judge = 0;  //用于判断是不是len大于了min
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
    //确定二者当中较短的串长
    if (len > lenth_min)
    {
        judge = 1;
        while (*ps1 != '\0' && *ps2 != '\0')  //从while中跳出说明到底了
        {
            if (*ps1 == *ps2)   //相等继续
            {
                ps1++;
                ps2++;
                continue;
            }
            else       //不相等就返回
            {
                return (*ps1 - *ps2);
            }
        }
    }
    else
    {
        while (ps1 - s1 < len)
        {
            if (*ps1 == *ps2)   //相等继续
            {
                ps1++;
                ps2++;
                continue;
            }
            else       //不相等就返回
            {
                return (*ps1 - *ps2);
            }
        }
    }
    if (judge)
    {
        return (*ps1 - *ps2);  //return二者之差
    }
    else  //情况2，就return0
    {
        return 0;
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
    }    //以上为特判
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
    //确定二者当中较短的串长
    if (len > lenth_min)   //此时就比到短的结束
    {
        while (*ps1 != '\0' && *ps2 != '\0')
        {
            tmp_s1 = *ps1;  //第一次初始化
            tmp_s2 = *ps2;
            if (*ps1 >= 'A' && *ps1 <= 'Z')
            {
                tmp_s1 = *ps1 + 'a' - 'A';     //s1大写变小写再初始化给tmp
            }
            if (*ps2 >= 'A' && *ps2 <= 'Z')
            {
                tmp_s2 = *ps2 + 'a' - 'A';     //s2大写变小写再初始化给tmp
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
        //上述循环跳出，代表有一个已经走到了末尾即\0处 
        if (*ps1 >= 'A' && *ps1 <= 'Z')  //代表s1是大写字母，则s2必定是\0
        {
            return (*ps1 + 'a' - 'A' - '\0');
        }
        if (*ps2 >= 'A' && *ps2 <= 'Z')  //代表s2是大写字母，则s1必定是\0
        {
            return ('\0' - (*ps2 + 'a' - 'A'));
        }

        return *ps1 - *ps2;   //俩里边没有大写字母
    }
    else
    {
        while (ps1 - s1 < len)
        {
            tmp_s1 = *ps1;  //第一次初始化
            tmp_s2 = *ps2;
            if (*ps1 >= 'A' && *ps1 <= 'Z')
            {
                tmp_s1 = *ps1 + 'a' - 'A';     //s1大写变小写再初始化给tmp
            }
            if (*ps2 >= 'A' && *ps2 <= 'Z')
            {
                tmp_s2 = *ps2 + 'a' - 'A';     //s2大写变小写再初始化给tmp
            }
            //以上完成了初始化的功能
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
        }   //跳出while说明已经比较完了，都未发现异常
        return 0;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strupr(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)  //特判str是null的时候
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strlwr(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)  //特判str是null的时候
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char* str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL) //特判，如果是NULL就直接返回0
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
    return 0; //跑完了也没找到就return0
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char* str, const char* substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL || substr == NULL)  //特判返回0
    {
        return 0;
    }
    int lenth = tj_strlen(str); //得到长度
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
                if (*pstr != *psubstr)  //找到不等的了就跳出
                {
                    break;
                }
                psubstr++;
                pstr++;
            }
            if (psubstr - substr == lenth_sub) //此时说明不是由break跳出的，满足条件
            {
                return tmpstr - str + 1;
            }
        }
        tmpstr++;   //暂存当前外层指向的地址,外层地址往后移动一个
        pstr = tmpstr;
        psubstr = substr;   //重新初始化二者       
    }
    return 0;  //跑完了整个都没找到,返回0
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char* str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL) //特判，如果是NULL就直接返回0
    {
        return 0;
    }
    int lenth = tj_strlen(str); //得到长度
    const char* p_str = str + lenth - 1;  //指向最后一个
    while (p_str - str >= 0)
    {
        if (*p_str == ch)
        {
            return p_str - str + 1;
        }
        p_str--;
    }
    return 0;  //没找到返回0
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char* str, const char* substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL || substr == NULL)  //特判返回0
    {
        return 0;
    }
    int lenth = tj_strlen(str); //得到长度
    int lenth_sub = tj_strlen(substr);
    const char* pstr = str + lenth - 1;   //指向串的末尾
    const char* psubstr = substr + lenth_sub - 1;
    const char* tmpstr = str + lenth - 1;
    while (pstr - str >= 0)
    {
        if (*pstr == *psubstr)
        {
            while (psubstr - substr >= 0)
            {
                if (*pstr != *psubstr)  //找到不等的了就跳出
                {
                    break;
                }
                psubstr--;
                pstr--;
            }
            if (psubstr - substr == -1) //此时说明不是由break跳出的，满足条件
            {
                return tmpstr - str - lenth_sub + 2;
            }
        }
        tmpstr--;   //暂存当前外层指向的地址,外层地址往后移动一个
        pstr = tmpstr;
        psubstr = substr + lenth_sub - 1;   //重新初始化二者       
    }
    return 0;  //跑完了整个都没找到,返回0
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strrev(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
    {
        return str;
    }
    int lenth = tj_strlen(str);
    char* p_str = str + lenth - 1;  //尾巴
    char* p_strs = str;  //头
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