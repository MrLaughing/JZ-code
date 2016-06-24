//============================================================================
// Name        : JZ-C-42-Plus.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 左旋转字符串：左旋转操作是把字符串前面的若干个字符转移到字符串的尾部，如输入"abcdefg"和数字2，左旋转2位后为："cdefgab"
//============================================================================

#include <iostream>
#include <stdio.h>
#include "StringUtil.h"
#include <string.h>
using namespace std;

char* LeftRotateString(char* pStr, int n) {
	if (pStr != NULL) {
		int nLength = static_cast<int>(strlen(pStr));
		if (nLength > 0 && n > 0 && n < nLength) {
			char* pFirstStart = pStr;
			char* pFirstEnd = pStr + n - 1;
			char* pSecondStart = pStr + n;
			char* pSecondEnd = pStr + nLength - 1;
			// 翻转字符串的前面n个字符
			Reverse(pFirstStart, pFirstEnd);
			// 翻转字符串的后面部分
			Reverse(pSecondStart, pSecondEnd);
			// 翻转整个字符串
			Reverse(pFirstStart, pSecondEnd);
		}
	}

	return pStr;
}

// ====================测试代码====================
void Test(char* testName, char* input, int num, char* expectedResult) {
	if (testName != NULL)
		printf("%s begins: ", testName);

	char* result = LeftRotateString(input, num);

	if ((input == NULL && expectedResult == NULL)
			|| (input != NULL && strcmp(result, expectedResult) == 0))
		printf("Passed.\n\n");
	else
		printf("Failed.\n\n");
}

// 功能测试
void Test1() {
	char input[] = "abcdefg";
	char expected[] = "cdefgab";

	Test("Test1", input, 2, expected);
}

// 边界值测试
void Test2() {
	char input[] = "abcdefg";
	char expected[] = "bcdefga";

	Test("Test2", input, 1, expected);
}

// 边界值测试
void Test3() {
	char input[] = "abcdefg";
	char expected[] = "gabcdef";

	Test("Test3", input, 6, expected);
}

// 鲁棒性测试
void Test4() {
	Test("Test4", NULL, 6, NULL);
}

// 鲁棒性测试
void Test5() {
	char input[] = "abcdefg";
	char expected[] = "abcdefg";

	Test("Test5", input, 0, expected);
}

// 鲁棒性测试
void Test6() {
	char input[] = "abcdefg";
	char expected[] = "abcdefg";

	Test("Test6", input, 7, expected);
}

int main(int argc, char** argv) {
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	return 0;
}

