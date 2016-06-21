//============================================================================
// Name        : JZ-C-31.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 连续子数组的最大和
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

bool g_InvalidInput = false;

int FindGreatestSumOfSubArray(int *pData, int nLength) {
	if ((pData == NULL) || (nLength <= 0)) {
		g_InvalidInput = true;
		return 0;
	}

	g_InvalidInput = false;

	int nCurSum = 0;
	int nGreatestSum = 0x80000000;//最小的整数。int 4个字节，最小数：-2^31:0x80000000，最大数：2^32-1:0x7fffffff。（均为补码）
	for (int i = 0; i < nLength; ++i) {
		if (nCurSum <= 0)
			nCurSum = pData[i];
		else
			nCurSum += pData[i];

		if (nCurSum > nGreatestSum)
			nGreatestSum = nCurSum;
	}

	return nGreatestSum;
}

// ====================测试代码====================
void Test(char* testName, int* pData, int nLength, int expected,
		bool expectedFlag) {
	if (testName != NULL)
		printf("%s begins: \n", testName);

	int result = FindGreatestSumOfSubArray(pData, nLength);
	if (result == expected && expectedFlag == g_InvalidInput)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1() {
	int data[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
}

// 所有数字都是负数
// -2, -8, -1, -5, -9
void Test2() {
	int data[] = { -2, -8, -1, -5, -9 };
	Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// 所有数字都是正数
// 2, 8, 1, 5, 9
void Test3() {
	int data[] = { 2, 8, 1, 5, 9 };
	Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

// 无效输入
void Test4() {
	Test("Test4", NULL, 0, 0, true);
}

int main(int argc, char** argv) {
	Test1();
	Test2();
	Test3();
	Test4();

	return 0;
}

