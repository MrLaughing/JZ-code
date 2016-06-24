//============================================================================
// Name        : JZ-C-41-Plus.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 和为s的连续正数序列：输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

void PrintContinuousSequence(int small, int big);

void FindContinuousSequence(int sum) {
	if (sum < 3)
		return;

	int small = 1;
	int big = 2;
	int middle = (1 + sum) / 2;
	int curSum = small + big; //这里curSum其实是从small到big之间所有数字的累加和

	while (small < middle) {
		if (curSum == sum)
			PrintContinuousSequence(small, big);

		while (curSum > sum && small < middle) {
			curSum -= small; //每次更新curSum值
			small++;

			if (curSum == sum)
				PrintContinuousSequence(small, big);
		}
//		while (curSum <= sum && small < middle) { //自己写的还是不如源码啊。。清晰却不简洁
//			big++;
//			curSum += big;
//			if (curSum >= sum)
//				break;
//		}
		big++;
		curSum += big; //每次更新curSum值
	}
}

void PrintContinuousSequence(int small, int big) {
	for (int i = small; i <= big; ++i)
		printf("%d ", i);

	printf("\n");
}

// ====================测试代码====================
void Test(char* testName, int sum) {
	if (testName != NULL)
		printf("%s for %d begins: \n", testName, sum);

	FindContinuousSequence(sum);
}

int main(int argc, char** argv) {
	Test("test1", 1);
	Test("test2", 3);
	Test("test3", 4);
	Test("test4", 9);
	Test("test5", 15);
	Test("test6", 100);

	return 0;
}

