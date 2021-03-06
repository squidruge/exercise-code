/*1951393 自动化 张儒戈*/

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

	if (str == NULL) {
		return 0;
	}

	const char* p = str;

	while (*p != '\0')
		p++;

	return p - str;
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

	char* p1 = s1;
	const char* p2 = s2;

	if (s1 != NULL && s2 != NULL) {
		while (*p1 != '\0')
			p1++;

		while (*p2 != '\0')
			*p1++ = *p2++;

		*p1 = '\0';
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

	char* p1 = s1 + tj_strlen(s1);
	const char* p2 = s2;


	if (s1 != NULL && s2 != NULL && len > 0) {

		while (p2 - s2 < len && *p2 != '\0') {
			*p1++ = *p2++;
		}

		*p1 = '\0';
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

	char* p1 = s1;
	const char* p2 = s2;


	if (s1 != NULL && s2 != NULL) {

		while (*p2 != '\0') {
			*p1++ = *p2++;
		}

		*p1 = '\0';
	}
	else {
		if (s1 != NULL) {
			*p1 = '\0';
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
char* tj_strncpy(char* s1, const char* s2, const int len)
{

	char* p1 = s1;
	const char* p2 = s2;


	if (s1 != NULL && s2 != NULL) {

		while (p2 - s2 < len && *p2 != '\0') {
			*p1++ = *p2++;
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
		/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */

	const char* p1 = s1;
	const char* p2 = s2;

	if (p1 != NULL && p2 != NULL) {

		while (*p1 == *p2 && *p1 != '\0') {
			p1++;
			p2++;
		}
	}
	else if (p1 == NULL && p2 == NULL) {

		return 0;
	}
	else if (p1 == NULL && p2 != NULL) {
		return -1;
	}
	else {
		return 1;
	}


	return *p1 - *p2; //return值可根据需要修改

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
	int is_up_p1 = 0, is_up_p2 = 0;//分别记录当前比较的p1 p2的字符是否为大写，是为1
	const char* p1 = s1;
	const char* p2 = s2;

	if (p1 != NULL && p2 != NULL) {

		while (1) {

			if (*p1 >= 'A' && *p1 <= 'Z') {
				is_up_p1 = 1;
			}
			else {
				is_up_p1 = 0;
			}
			if (*p2 >= 'A' && *p2 <= 'Z') {
				is_up_p2 = 1;
			}
			else {
				is_up_p2 = 0;
			}

			if (*p1 + ('a' - 'A') * is_up_p1 != *p2 + ('a' - 'A') * is_up_p2 || (*p1 == '\0' && *p2 == '\0')) {
				break;
			}
			p1++;
			p2++;
		}
	}
	else if (p1 == NULL && p2 == NULL) {

		return 0;
	}
	else if (p1 == NULL && p2 != NULL) {
		return -1;
	}
	else {
		return 1;
	}

	return *p1 - *p2 + ('a' - 'A') * (is_up_p1 - is_up_p2);

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
	const char* p1 = s1;
	const char* p2 = s2;

	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (p1 != NULL && p2 != NULL) {

		while (*p1 == *p2) {
			if (p1 - s1 == len - 1 || *p1 == '\0') {
				break;
			}

			p1++;
			p2++;
		}
	}
	else if (p1 == NULL && p2 == NULL) {

		return 0;
	}
	else if (p1 == NULL && p2 != NULL) {
		return -1;
	}
	else {
		return 1;
	}


	return *p1 - *p2; //return值可根据需要修改

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
	int is_up_p1 = 0, is_up_p2 = 0;//分别记录当前比较的p1 p2的字符是否为大写，是为1
	const char* p1 = s1;
	const char* p2 = s2;

	if (p1 != NULL && p2 != NULL) {

		while (1) {

			if (*p1 >= 'A' && *p1 <= 'Z') {
				is_up_p1 = 1;
			}
			else {
				is_up_p1 = 0;
			}
			if (*p2 >= 'A' && *p2 <= 'Z') {
				is_up_p2 = 1;
			}
			else {
				is_up_p2 = 0;
			}

			if (*p1 + ('a' - 'A') * is_up_p1 != *p2 + ('a' - 'A') * is_up_p2
				|| (*p1 == '\0' && *p2 == '\0') || p1 - s1 == len - 1) {
				break;
			}
			p1++;
			p2++;
		}
	}
	else if (p1 == NULL && p2 == NULL) {

		return 0;
	}
	else if (p1 == NULL && p2 != NULL) {
		return -1;
	}
	else {
		return 1;
	}

	return *p1 - *p2 + ('a' - 'A') * (is_up_p1 - is_up_p2);
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

	char* p = str;
	if (p != NULL) {
		while (*p != '\0') {
			if (*p >= 'a' && *p <= 'z') {
				*p += 'A' - 'a';
			}
			p++;
		}
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
	char* p = str;
	if (p != NULL) {
		while (*p != '\0') {
			if (*p >= 'A' && *p <= 'Z') {
				*p += 'a' - 'A';
			}
			p++;
		}
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
	const char* p = str;
	if (p != NULL) {
		while (1) {

			if (*p == '\0') {
				return 0;
			}

			if (*p == ch) {
				break;
			}
			p++;
		}
	}
	else {
		return 0;
	}
	return p - str + 1;
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

	const char* p1 = str, * p2 = str;
	const char* psub = substr;

	if (psub == NULL)
		return 0;

	if (p1 != NULL) {
		while (1) {

			if (*p1 == '\0') {
				return 0;
			}

			if (*p1 == *psub) {
				p2 = p1;
				while (1) {

					if (*psub == '\0') {
						break;
					}

					if (*p2 != *psub)
						break;

					p2++;
					psub++;
				}

				if (*psub == '\0') {
					break;
				}
				else {
					psub = substr;
				}

			}
			p1++;
		}
	}
	else {
		return 0;
	}

	return p1 - str + 1;

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
	const char* p = str;
	int ret = 0;

	if (p != NULL) {
		while (1) {

			if (*p == '\0') {
				break;

			}

			if (*p == ch) {
				ret = p - str + 1;
			}

			p++;
		}
	}
	else {
		return 0;
	}
	return ret;
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

	const char* p1 = str, * p2 = str;
	const char* psub = substr;
	int ret = 0;

	if (psub == NULL)
		return 0;

	if (p1 != NULL) {
		while (1) {

			if (*p1 == '\0') {
				break;
			}

			if (*p1 == *psub) {
				p2 = p1;

				while (1) {

					if (*psub == '\0') {
						break;
					}

					if (*p2 != *psub)
						break;

					p2++;
					psub++;
				}

				if (*psub == '\0') {
					ret = p1 - str + 1;
				}
				psub = substr;

			}
			p1++;
		}
	}
	else {
		return 0;
	}

	return ret;


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

	char* begin, * end;
	char ch;

	if (str == NULL) {
		return str;
	}
	else {
		begin = str;
		end = str + tj_strlen(str) - 1;//指向最后一个非空字符
		if (*begin != '\0') {

			while (begin < end) {
				ch = *begin;
				*begin = *end;
				*end = ch;
				begin++;
				end--;
			}
		}
	}

	return str;
}
