//============================================================================
// Name        : JZ-C-41.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description :和为s的两个数字：输入一个递增排序的数组和一个数字，在数组中查找两个数，使得它们的和正好等于s。若有多对，输出任意一对即可
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

bool FindNumbersWithSum(int data[], int length, int sum, int* num1, int* num2) {
	bool found = false;
	if (length < 1 || num1 == NULL || num2 == NULL)
		return found;

	int ahead = length - 1;
	int behind = 0;

	while (ahead > behind) {
		long long curSum = data[ahead] + data[behind];

		if (curSum == sum) {
			*num1 = data[behind];
			*num2 = data[ahead];
			found = true;
			break;
		} else if (curSum > sum)
			ahead--;
		else
			behind++;
	}

	return found;
}

// ====================测试代码====================
void Test(char* testName, int data[], int length, int sum,
		bool expectedReturn) {
	if (testName != NULL)
		printf("%s begins: ", testName);

	int num1, num2;
	int result = FindNumbersWithSum(data, length, sum, &num1, &num2);
	if (result == expectedReturn) {
		if (result) {
			if (num1 + num2 == sum)
				printf("Passed. \n");
			else
				printf("Failed. \n");
		} else
			printf("Passed. \n");
	} else
		printf("Failed. \n");
}

// 存在和为s的两个数字，这两个数字位于数组的中间
void Test1() {
	int data[] = { 1, 2, 4, 7, 11, 15 };
	Test("Test1", data, sizeof(data) / sizeof(int), 15, true);
}

// 存在和为s的两个数字，这两个数字位于数组的两段
void Test2() {
	int data[] = { 1, 2, 4, 7, 11, 16 };
	Test("Test2", data, sizeof(data) / sizeof(int), 17, true);
}

// 不存在和为s的两个数字
void Test3() {
	int data[] = { 1, 2, 4, 7, 11, 16 };
	Test("Test3", data, sizeof(data) / sizeof(int), 10, false);
}

// 鲁棒性测试
void Test4() {
	Test("Test4", NULL, 0, 0, false);
}

int main(int argc, char** argv) {
	Test1();
	Test2();
	Test3();
	Test4();

	return 0;
}

