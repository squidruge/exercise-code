/* 班级 学号 姓名 */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */

/* 不允许定义任何形式的外部全局、静态全局、宏定义、只读变量 */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len = 0;
    while (str[len])
    {
        len++;
    }
    return len; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcat(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int n1 = tj_strlen(s1);
    int n2 = 0;

    while (s1[n1++] = s2[n2++])
        ;
    
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncat(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int n1 = tj_strlen(s1);
    int n2 = 0;
    
    if(len>0){
        while (n2 < len&& s2[n2]){
            s1[n1++] = s2[n2++];
        } 
        s1[n1] = '\0';
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcpy(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int n1 = 0;
    int n2 = 0;

   
        while (s1[n1++] = s2[n2++]) 
            ;
 
  
  
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncpy(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int n1 = 0;
    int n2 = 0;

    if (len > 0) {
        while (n2 < len && s2[n2]) {
            s1[n1++] = s2[n2++];
        }
     
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int n = 0;

   while (s1[n] == s2[n]) {
       if (n == tj_strlen(s1)) {
           break;
       }
       n++;
    }

    return s1[n]-s2[n]; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char ch1, ch2;

    for (int n = 0; ; n++) {
        ch1 = s1[n];
        ch2 = s2[n];
        if (ch1 >= 'A' && ch1 <= 'Z') {
            ch1 += 32;
        }

        if (ch2 >= 'A' && ch2 <= 'Z') {
            ch2 += 32;
        }

        if (ch1 != ch2||n== tj_strlen(s1)) {
            break;
        }
    }

    return ch1-ch2; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */

    char ch1='\0', ch2='\0';

    for (int n = 0; n<len; n++) {
        ch1 = s1[n];
        ch2 = s2[n];


        if (ch1 != ch2 || n == tj_strlen(s1)) {
            break;
        }

    }

    return ch1 - ch2; //return值可根据需要修改

}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char ch1='\0', ch2='\0';

    for (int n = 0; n<len; n++) {
        ch1 = s1[n];
        ch2 = s2[n];
        if (ch1 >= 'A' && ch1 <= 'Z') {
            ch1 += 32;
        }

        if (ch2 >= 'A' && ch2 <= 'Z') {
            ch2 += 32;
        }

        if (ch1 != ch2 || n == tj_strlen(s1)) {
            break;
        }
    }

    return ch1 - ch2; //return值可根据需要修改
   
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strupr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */



    for (int n = 0; n < tj_strlen(str); n++) {
        
        if (str[n] >= 'a' && str[n] <= 'z') {
            str[n] -= 32;
        }
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlwr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    for (int n = 0; n < tj_strlen(str); n++) {

        if (str[n] >= 'A' && str[n] <= 'Z') {
            str[n] += 32;
        }
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char str[], char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int ret = 0;

    for (int i = 0; i < tj_strlen(str); i++) {
        if (str[i] == ch) {
            ret = i+1;
            break;
        }
    }

    return ret; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int ret = 0;
    bool same = 0;

    for (int i = 0; i < tj_strlen(str); i++) {
        for(int j=0;j<tj_strlen(substr);j++){
            if (str[i+j] == substr[j]) {
                same = 1;
            }
            else {
                same = 0;
                break;
            }
        } 
        if (same) {
            ret = i + 1;
            break;
        }

    }

    return ret; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char str[], const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int ret = 0;
    int len = tj_strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[len-i-1] == ch) {
            ret = len - i ;
            break;
        }
    }

    return ret; //return值可根据需要修改
   
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int ret = 0;
    bool same = 0;

    for (int i = 0; i < tj_strlen(str); i++) {
        for (int j = 0; j < tj_strlen(substr); j++) {
            if (str[i + j] == substr[j]) {
                same = 1;
            }
            else {
                same = 0;
                break;
            }
        }
        if (same) {
            ret = i + 1;
    
        }

    }

    return ret; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrev(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
   
    char temp;
    int len = tj_strlen(str);

    for (int i = 0; i < len/2; i++) {
    
        temp = str[i];
        str[i] = str[len-i - 1];
        str[len - i - 1] = temp;

    }
    return 0; //return值可根据需要修改
}
