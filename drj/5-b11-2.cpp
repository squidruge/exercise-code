/* 1951650 信02 戴仁杰 */
#include <iostream>
#include <string>
#include <cmath>
//可按需增加需要的头文件
using namespace std;

const char chistr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/

/* 分解数字，输入为该数和从高到低的第n位(十亿位n=0) */
int fenjie(double num, int n)
{
    int w[15] = { 0 };   //存储每一位的数组
    int zheng = 0;  //存整数部分/10
    double xiao; //存储小数位
    int i;
    w[0] = (int)(num / 1000000000.0);  //十亿位单独处理
    zheng = (int)(num - w[0] * 1000000000.0); //保证位于0到10亿内，不越界
    xiao = num - (w[0] * 1000000000.0 + zheng) + 0.001;  //把小数部分加个0.001再乘以100存起来
    for (i = 9; i > 0; --i)
    {
        w[i] = zheng % 10;
        zheng = zheng / 10;
    }
    w[10] = (int)(xiao / 0.1);
    w[11] = (int)((xiao - w[10] * 0.1) / 0.01);

    return w[n];
}

/* 位权存入result数组,输入参数为当前位数i和当前字符串的count值 */
void input_weiquan(int i)    //“整”的输出需要单独考虑
{
    const char weiquan[] = "拾佰仟万亿圆角分整";
    switch (i)
    {
        case 0:
        case 4:
        case 8:
            result = result + weiquan[0] + weiquan[1];
            break;     //输出"拾"
        case 3:
        case 7:
            result = result + weiquan[2] + weiquan[3];
            break;     //输出"佰"
        case 2:
        case 6:
            result = result + weiquan[4] + weiquan[5];
            break;     //输出"仟"
        case 5:
            result = result + weiquan[6] + weiquan[7];
            break;     //输出"万"
        case 1:
            result = result + weiquan[8] + weiquan[9];
            break;     //输出"亿"
        case 9:
            result = result + weiquan[10] + weiquan[11];
            break;     //输出"圆"
        case 10:
            result = result + weiquan[12] + weiquan[13];
            break;     //输出"角"
        case 11:
            result = result + weiquan[14] + weiquan[15];
            break;     //输出"分"
    }
    return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    /* --允许添加需要的内容 --*/

    double num;
    int cut[15] = { 0 };   //略微开大一些，防止越界危险
    int i;
    int count = 0;
    const char ling[] = "圆整a\0a";  //用于对0的特判和打印“整”,防止dev报warning用a隔开\0
    cout << "请输入[0-100亿)之间的数字: " << endl;
    cin >> num;
    for (i = 0; i < 12; ++i)       //把分解后的每一位存到cut数组里，十亿位为cut[0]
    {
        cut[i] = fenjie(num, i);
    }

    for (i = 0; i < 12; ++i)
    {
        if (count == 0 && cut[i] == 0)   //提高执行效率，跳过前边的空0
        {
            continue;
        }
        if (cut[i] != 0)    //该位不为0,从里边拿过来存进去
        {
            result = result + chistr[cut[i] * 2] + chistr[cut[i] * 2 + 1];
            input_weiquan(i);   //该位不是0的时候必定输出位权,count重新赋值
            count++;
        }
        if (cut[i] == 0 && cut[i + 1] != 0 && i % 4 != 1)   //该位为0情况下判断何时输出“零”;  这里会调用到cut[12],前面数组要大一些
        {
            result = result + chistr[cut[i] * 2] + chistr[cut[i] * 2 + 1];
        }
        if (cut[i] == 0)   //对该位为0的判断
        {
            if (i == 1)
            {
                input_weiquan(i);
            }
            if (i == 5 && (cut[4] + cut[3] + cut[2]) != 0)  //当万级不全为0的时候，输出“万”
            {
                input_weiquan(i);
            }
            if (i == 9 && (cut[8] + cut[7] + cut[6] + cut[5] + cut[4] + cut[3] + cut[2] + cut[1] + cut[0]) != 0)
            {
                input_weiquan(i);
            }
        }
        if (i == 9 && (cut[10] + cut[11]) == 0)  //打“整”,直接跳出
        {
            result = result + ling[2] + ling[3];
            break;
        }
        if (i == 10 && cut[11] == 0)  //打“整”,直接跳出
        {
            result = result + ling[2] + ling[3];
            break;
        }
    }

    if (fabs(num) < 1e-6)  //对0特判
    {
        result = result + chistr[0] + chistr[1] + ling[0] + ling[1] + ling[2] + ling[3];
    }
    cout << "大写结果是：" << endl;

    cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，之前不允许任何形式的部分输出 */
    return 0;
}
