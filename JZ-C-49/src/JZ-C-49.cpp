//============================================================================
// Name        : JZ-C-49.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 把字符串转换为整数
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

long long StrToIntCore(const char* str, bool minus);

enum Status {
	kValid = 0, kInvalid //此时kInvalid为1，如果没有定义enum变量的需求，枚举变量的值可以省略。在以上形式下，第一个值默认值为0，以下各个分别为上一个值加1。
};
int g_nStatus = kValid;//定义全局变量，反映输入是否合法

int StrToInt(const char* str) {
	g_nStatus = kInvalid;//初始为1:不合法
	long long num = 0;//用long long型存储转换的str，实际返回的则是int型★

	if (str != NULL && *str != '\0') {//考虑空指针NULL或字符串为空""，函数直接返回0，且全局变量g_nStatus为1，不合法
		bool minus = false;//考虑正负
		if (*str == '+')
			str++;
		else if (*str == '-') {
			str++;
			minus = true;
		}

		if (*str != '\0') {
			num = StrToIntCore(str, minus);
		}
	}

	return (int) num;//将long long型num转为int
}

long long StrToIntCore(const char* digit, bool minus) {
	long long num = 0;

	while (*digit != '\0') {
		if (*digit >= '0' && *digit <= '9') {
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (*digit - '0');
			//考虑溢出
			if ((!minus && num > 0x7FFFFFFF) //int所能表示的最大正整数
			|| (minus && num < (signed int) 0x80000000)) { //int所能表示的最小负整数
				num = 0;
				break;
			}

			digit++;
		} else {
			num = 0;
			break;
		}
	}

	if (*digit == '\0') {
		g_nStatus = kValid;
	}

	return num;
}

// ====================测试代码====================
void Test(char* string) {
	int result = StrToInt(string);
	if (result == 0 && g_nStatus == kInvalid)
		printf("the input %s is invalid.\n", string);
	else
		printf("number for %s is: %d.\n", string, result);
}

int main(int argc, char** argv) {
	Test(NULL);

	Test("");

	Test("123");

	Test("+123");

	Test("-123");

	Test("1a33");

	Test("+0");

	Test("-0");

	//有效的最大正整数, 0x7FFFFFFF
	Test("+2147483647");

	Test("-2147483647");

	Test("+2147483648");

	//有效的最小负整数, 0x80000000
	Test("-2147483648");

	Test("+2147483649");

	Test("-2147483649");

	Test("+");

	Test("-");

	return 0;
}
