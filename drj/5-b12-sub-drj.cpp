/* 1951650 信02 戴仁杰 */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */

/* 不允许定义任何形式的外部全局、静态全局、宏定义、只读变量 */

/***************************************************************************
  函数名称：tj_strlen()
  功    能：返回字符串长度
  输入参数：字符串
  返 回 值：字符串长度
  说    明：
***************************************************************************/
int tj_strlen(const char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i = 0;
    while (str[i] != '\0')
    {
        ++i;
    }
    
    return i; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strcat
  功    能：s2的内容追加到s1后，包含\0
  输入参数：s1[],s2[]
  返 回 值：0
  说    明：
***************************************************************************/
int tj_strcat(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int lenth_s2 = tj_strlen(s2);
    int lenth_s1 = tj_strlen(s1);
    int i = 0;   
    int j = 0;
    
    for (i = lenth_s1; i <= lenth_s1 + lenth_s2; ++i)
    {
        s1[i] = s2[j];
        ++j;
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strncat()
  功    能：把字符串s2的前len个字符追加到s1后面,并添加\0
  输入参数：被追加s1[],追加者s2[],追加长度len
  返 回 值：0
  说    明：如果len超过s2的长度，就把整个给接上，包含\0
***************************************************************************/
int tj_strncat(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int lenth_s1 = tj_strlen(s1);  //求s1的长度
    int lenth_s2 = tj_strlen(s2);
    int i = 0;
    int j = 0;
    if (len > lenth_s2)   //len长度大于了字符串长度，直接全接上去
    {
        tj_strcat(s1, s2);
    }
    else
    {
        for (i = lenth_s1; j < len; ++i)
        {
            s1[i] = s2[j];
            ++j;
        }
        s1[i] = '\0';  //补最后的尾零
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strcpy（）
  功    能：字符串s2复制到s1当中，覆盖s1当中的原内容，复制时包含\0
  输入参数：被修改的s1[],要复制的s2[]
  返 回 值：0
  说    明：
***************************************************************************/
int tj_strcpy(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组) */
    int lenth_s2 = tj_strlen(s2);
    int i = 0;
    for (i = 0; i <= lenth_s2; ++i)
    {
        s1[i] = s2[i];
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strncpy()
  功    能：字符串s2前len个字符复制到s1当中，覆盖s1当中的原内容，复制时不包含\0
  输入参数：s1[],s2[],要复制的长度len
  返 回 值：0
  说    明：若len比s2的长度长，那么复制s2个即可，不含\0
***************************************************************************/
int tj_strncpy(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int lenth_s2 = tj_strlen(s2);
    int i = 0;
    if (len > lenth_s2)
    {
        for (i = 0; i < lenth_s2; ++i)
        {
            s1[i] = s2[i];
        }
    }
    else
    {
        for (i = 0; i < len; ++i)
        {
            s1[i] = s2[i];
        }
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strcmp()
  功    能：比较字符串s1和s2的大小，英文字母要区分大小写
  输入参数：s1[],s2[]
  返 回 值：相等为0，不等则为第一个不相等字符的ASCII差值
  说    明：
***************************************************************************/
int tj_strcmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i = 0;
    while (s1[i] == s2[i])
    {
        if (s1[i] == '\0')   //相等跳出
        {
            return 0;
        }
        ++i;
    }

    return (s1[i]-s2[i]);   //return二者之差
}

/***************************************************************************
  函数名称：tj_strcasecmp()
  功    能：比较字符串s1和s2的大小，英文字母要不分大小写
  输入参数：s1[],s2[]
  返 回 值：相等为0，不等则为第一个不相等字符的ASCII差值(统一转为小写后比较)
  说    明：
***************************************************************************/
int tj_strcasecmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i = 0;
    int tmp_s1, tmp_s2;
    while (s1[i] != '\0' && s2[i] != '\0')
    {    
        tmp_s1 = s1[i];  //第一次初始化
        tmp_s2 = s2[i];
        if (s1[i] >= 'A' && s1[i] <= 'Z')
        {
            tmp_s1 = s1[i] + 'a' - 'A';     //s1大写变小写再初始化给tmp
        }
        if (s2[i] >= 'A' && s2[i] <= 'Z')
        {
            tmp_s2 = s2[i] + 'a' - 'A';     //s2大写变小写再初始化给tmp
        }
        ++i;       
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
    if (s1[i] >= 'A' && s1[i] <= 'Z')  //代表s1是大写字母，则s2必定是\0
    {
        return (s1[i] + 'a' - 'A' - '\0');
    }
    if (s2[i] >= 'A' && s2[i] <= 'Z')  //代表s2是大写字母，则s1必定是\0
    {
        return ('\0' - (s2[i] + 'a' - 'A'));
    }

    return s1[i] - s2[i];   //俩里边没有大写字母
}

/***************************************************************************
  函数名称：tj_strncmp
  功    能：比较字符串s1和s2的大小，英文字母要区分大小写
  输入参数：s1[],s2[],要比较的前len个字符的len值
  返 回 值：相等为0，不等则为第一个不相等字符的ASCII差值
  说    明：若len超长，则比到短串的末尾结束
***************************************************************************/
int tj_strncmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i = 0;
    int lenth_s1 = tj_strlen(s1);
    int lenth_s2 = tj_strlen(s2);
    int lenth_min;
    int judge = 0;  //用于判断是不是len大于了min
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
        while (s1[i]!='\0'&& s2[i] != '\0')  //从while中跳出说明到底了
        {
            if (s1[i] == s2[i])   //相等继续
            {
                i++;
                continue;
            }
            else       //不相等就返回
            {
                return (s1[i] - s2[i]);
            }
        }
    }
    else
    {
        while (i < len)
        {
            if (s1[i] == s2[i])   //相等继续
            {
                i++;
                continue;
            }
            else       //不相等就返回
            {
                return (s1[i] - s2[i]);
            }
        }
    }
    if (judge)
    {
        return (s1[i] - s2[i]);  //return二者之差
    }
    else  //情况2，就return0
    {
        return 0;
    }
}

/***************************************************************************
  函数名称：tj_strcasencmp()
  功    能：比较字符串s1和s2的大小，英文字母不要区分大小写,大写都转成小写
  输入参数：s1[],s2[],要比较的前len个字符的len值
  返 回 值：相等为0，不等则为第一个不相等字符的ASCII差值
  说    明：若len超长，则比到短串的末尾结束
***************************************************************************/
int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i = 0;
    int lenth_s1 = tj_strlen(s1);
    int lenth_s2 = tj_strlen(s2);
    int lenth_min;
    int judge = 0;  //用于判断是不是len大于了min
    int tmp_s1, tmp_s2;
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
        //judge = 1;
        while (s1[i] != '\0' && s2[i] != '\0')
        {
            tmp_s1 = s1[i];  //第一次初始化
            tmp_s2 = s2[i];
            if (s1[i] >= 'A' && s1[i] <= 'Z')
            {
                tmp_s1 = s1[i] + 'a' - 'A';     //s1大写变小写再初始化给tmp
            }
            if (s2[i] >= 'A' && s2[i] <= 'Z')
            {
                tmp_s2 = s2[i] + 'a' - 'A';     //s2大写变小写再初始化给tmp
            }
            ++i;
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
        if (s1[i] >= 'A' && s1[i] <= 'Z')  //代表s1是大写字母，则s2必定是\0
        {
            return (s1[i] + 'a' - 'A' - '\0');
        }
        if (s2[i] >= 'A' && s2[i] <= 'Z')  //代表s2是大写字母，则s1必定是\0
        {
            return ('\0' - (s2[i] + 'a' - 'A'));
        }

        return s1[i] - s2[i];   //俩里边没有大写字母
    }
    else
    {
        while (i < len)
        {
            tmp_s1 = s1[i];  //第一次初始化
            tmp_s2 = s2[i];
            if (s1[i] >= 'A' && s1[i] <= 'Z')
            {
                tmp_s1 = s1[i] + 'a' - 'A';     //s1大写变小写再初始化给tmp
            }
            if (s2[i] >= 'A' && s2[i] <= 'Z')
            {
                tmp_s2 = s2[i] + 'a' - 'A';     //s2大写变小写再初始化给tmp
            }
            //以上完成了初始化的功能
            ++i;
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
}

/***************************************************************************
  函数名称：tj_strupr()
  功    能：将字符串str中的所有小写字母转成大写字母存在原串中，其余不变
  输入参数：数组str[]
  返 回 值：0
  说    明：
***************************************************************************/
int tj_strupr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int lenth = tj_strlen(str); //得到长度
    int i = 0;
    for (i = 0; i < lenth; ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] + 'A' - 'a';
        }
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strlwr()
  功    能：将字符串str中的所有大写字母转成小写字母存在原串中，其余不变
  输入参数：数组str[]
  返 回 值：0
  说    明：
***************************************************************************/
int tj_strlwr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int lenth = tj_strlen(str); //得到长度
    int i = 0;
    for (i = 0; i < lenth; ++i)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 'a' - 'A';
        }
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strchr
  功    能：在str中寻找字符ch第一次出现的位置，顺序是从左到右
  输入参数：待搜索字符串str[]，要寻找的字符ch
  返 回 值：1-n(位置从1开始)，未找到则返回0
  说    明：
***************************************************************************/
int tj_strchr(const char str[], char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int lenth = tj_strlen(str); //得到长度
    int i = 0;
    for (i = 0; i < lenth; ++i)
    {
        if (str[i] == ch)
        {
            return (i + 1);
        }
    }

    return 0; //跑完了也没找到就return0
}

/***************************************************************************
  函数名称：tj_strstr()
  功    能：在str中寻找字符串substr第一次出现的位置，顺序是从左到右
  输入参数：待搜索字符串str[]，要寻找的字符串substr
  返 回 值：1-n(位置从1开始)，未找到则返回0
  说    明：
***************************************************************************/
int tj_strstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int lenth = tj_strlen(str); //得到长度
    int lenth_sub = tj_strlen(substr);
    int i, j;
    for (i = 0; i < lenth; ++i)
    {
        if (str[i] == substr[0])
        {
            for (j = 0; j < lenth_sub; ++j)
            {
                if (str[i + j] != substr[j])  //该串不满足条件
                {
                    break;
                }
            }
            if (j == lenth_sub)  //不是由于break跳出的，找到了满足条件的，return
            {
                return i+1;
            }
            //不然继续寻找
        }
    }

    return 0; //最后还是没找到，return 0
}

/***************************************************************************
  函数名称：tj_strrchr()
  功    能：在str中寻找字符ch第一次出现的位置，顺序是从右到左
  输入参数：待搜索字符串str[]，要寻找的字符ch
  返 回 值：1-n(位置从1开始)，未找到则返回0
  说    明：
***************************************************************************/
int tj_strrchr(const char str[], const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int lenth = tj_strlen(str); //得到长度
    int i = 0;
    for (i = lenth - 1; i >= 0; --i)
    {
        if (str[i] == ch)
        {
            return (i + 1);
        }
    }

    return 0; //没找到返回0
}

/***************************************************************************
  函数名称：tj_strrstr()
  功    能：在str中寻找字符串substr第一次出现的位置，顺序是从右到左
  输入参数：待搜索字符串str[]，要寻找的字符串substr
  返 回 值：1-n(位置从1开始)，未找到则返回0
  说    明：
***************************************************************************/
int tj_strrstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */

    int lenth = tj_strlen(str); //得到长度
    int lenth_sub = tj_strlen(substr);
    int i, j;
    for (i = lenth - 1; i >= 0; --i)
    {
        if (str[i] == substr[lenth_sub - 1])  //找到了一个字符等于目标串的末尾
        {
            for (j = 0; j < lenth_sub; ++j)
            {
                if (str[i - j] != substr[lenth_sub - 1 - j])  //该串不满足条件
                {
                    break;
                }
            }
            if (j == lenth_sub)  //不是由于break跳出的，找到了满足条件的，return
            {
                return (i - lenth_sub + 2);
            }
            //不然继续寻找
        }
    }

    return 0; //最后还是没找到，return 0
}

/***************************************************************************
  函数名称：tj_strrev()
  功    能：字符串反转，放入原串中
  输入参数：字符串str[]
  返 回 值：0
  说    明：
***************************************************************************/
int tj_strrev(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i, tmp;
    int lenth = tj_strlen(str);
    for (i = 0; i < lenth / 2; ++i)
    {
        tmp = str[i];
        str[i] = str[lenth - 1 - i];
        str[lenth - 1 - i] = tmp;
    }

    return 0; //return值可根据需要修改
}