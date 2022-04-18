#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char s1[10], s2[10];//s1/s2是数组(后续内容)

    scanf("%s %s", s1, s2);
    printf("s1=%s\ns2=%s\n", s1, s2);

    return 0;
}

/* 特别说明：
   数组名，代表了数组的首地址，因此放在scanf中时，
s1/s2可以不加&，具体概念后续数组时再详细说明
*/

