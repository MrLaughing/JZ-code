//============================================================================
// Name        : JZ-C-43.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : n个骰子的点数：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s，求所有可能的s的概率
//============================================================================

#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int g_maxValue = 6; //骰子面数

// ====================方法一====================
void Probability(int number, int* pProbabilities);
void Probability(int original, int current, int sum, int* pProbabilities);
/**
 * 递归：许多计算时重复的，当number变大时，性能很低
 */
void PrintProbability_Solution1(int number) {
	if (number < 1)
		return;

	int maxSum = number * g_maxValue;
	int* pProbabilities = new int[maxSum - number + 1];
	for (int i = number; i <= maxSum; ++i)
		pProbabilities[i - number] = 0;

	Probability(number, pProbabilities);

	int total = pow((double) g_maxValue, number);//pow(x,y)函数：表示x^y
	for (int i = number; i <= maxSum; ++i) {
		double ratio = (double) pProbabilities[i - number] / total;
		printf("%d: %e\n", i, ratio);
	}

	delete[] pProbabilities;
}

void Probability(int number, int* pProbabilities) {
	for (int i = 1; i <= g_maxValue; ++i)
		Probability(number, number, i, pProbabilities);
}

void Probability(int original, int current, int sum, int* pProbabilities) {
	if (current == 1) {
		pProbabilities[sum - original]++;
	} else {
		for (int i = 1; i <= g_maxValue; ++i) {
			Probability(original, current - 1, i + sum, pProbabilities);
		}
	}
}

// ====================方法二====================
/**
 * 循环：利用两个数组交替存储两次循环后各值可能出现的次数。时间性能好
 */
void PrintProbability_Solution2(int number) {
	if (number < 1)
		return;

	int* pProbabilities[2];
	pProbabilities[0] = new int[g_maxValue * number + 1];
	pProbabilities[1] = new int[g_maxValue * number + 1];
	for (int i = 0; i < g_maxValue * number + 1; ++i) {
		pProbabilities[0][i] = 0;
		pProbabilities[1][i] = 0;
	}

	int flag = 0;
	for (int i = 1; i <= g_maxValue; ++i)
		pProbabilities[flag][i] = 1;//第一次,先将各值可能出现的次数赋为1

	for (int k = 2; k <= number; ++k) {//number 骰子数
		for (int i = 0; i < k; ++i)
			pProbabilities[1 - flag][i] = 0;

		for (int i = k; i <= g_maxValue * k; ++i) {
			pProbabilities[1 - flag][i] = 0;//先重新赋值为0 ★★(结合flag交替使用得知：这里每一轮都会重复计算上一轮得过的次数，因为每次都是从值为0开始。所以仍有重复计算的问题)
			for (int j = 1; j <= i && j <= g_maxValue; ++j)
				pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];//★★★这里表示f(n)=f(n-1)+f(n-2)+f(n-3)+f(n-4)+f(n-5)+f(n-6)
		}

		flag = 1 - flag;//交替使用两个数组
	}

	double total = pow((double) g_maxValue, number);
	for (int i = number; i <= g_maxValue * number; ++i) {
		double ratio = (double) pProbabilities[flag][i] / total;
		printf("%d: %e\n", i, ratio);
	}

	delete[] pProbabilities[0];
	delete[] pProbabilities[1];
}

// ====================测试代码====================
void Test(int n) {
	printf("Test for %d begins:\n", n);

	printf("Test for solution1\n");
	PrintProbability_Solution1(n);

	printf("Test for solution2\n");
	PrintProbability_Solution2(n);

	printf("\n");
}

int main(int argc, char** argv) {
	Test(1);
	Test(2);
	Test(3);
	Test(4);
	Test(11);
	Test(0);

	return 0;
}

