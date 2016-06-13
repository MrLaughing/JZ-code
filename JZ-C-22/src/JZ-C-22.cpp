//============================================================================
// Name        : JZ-C-22.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 栈的压入、弹出序列
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
/**
 *给定两个整数序列，第一个序列表示栈的压入顺序，判断第二个序列是否会是该栈的弹出顺序
 */
bool IsPopOrder(const int* pPush, const int* pPop, int nLength) {
	std::stack<int> StackData; //辅助栈
	if (pPush != NULL && pPop != NULL && nLength != 0) {
		int pLength = nLength-1;//pLength指的是压入栈剩余未进辅助栈的数目
		StackData.push(*pPush);
		while (!StackData.empty()) { //每次将辅助栈的栈顶元素和弹出栈序列第一个数比较,直至全部比较完毕
			if (StackData.top() != *pPop && pLength > 0) {
				pPush++;
				StackData.push(*pPush);
				pLength--;
			} else if (StackData.top() != *pPop && pLength <= 0) {
				return false; //弹出栈序列有错误，直接退出循环
			} else {
				StackData.pop();
				pPop++;
				if(StackData.empty() && pLength > 0){//出栈后若辅助栈为空，继续压入‘压入栈序列’后续元素
					StackData.push(*pPush);
				}
			}
		}
	} else {
		return false;
	}
	return true;
}

// ====================测试代码====================
void Test(char* testName, const int* pPush, const int* pPop, int nLength,
		bool expected) {
	if (testName != NULL)
		printf("%s begins: ", testName);

	if (IsPopOrder(pPush, pPop, nLength) == expected)
		printf("Passed.\n");
	else
		printf("failed.\n");
}

void Test1() {
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 4, 5, 3, 2, 1 };

	Test("Test1", push, pop, nLength, true);
}

void Test2() {
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 3, 5, 4, 2, 1 };

	Test("Test2", push, pop, nLength, true);
}

void Test3() {
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 4, 3, 5, 1, 2 };

	Test("Test3", push, pop, nLength, false);
}

void Test4() {
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 3, 5, 4, 1, 2 };

	Test("Test4", push, pop, nLength, false);
}

// push和pop序列只有一个数字
void Test5() {
	const int nLength = 1;
	int push[nLength] = { 1 };
	int pop[nLength] = { 2 };

	Test("Test5", push, pop, nLength, false);
}

void Test6() {
	const int nLength = 1;
	int push[nLength] = { 1 };
	int pop[nLength] = { 1 };

	Test("Test6", push, pop, nLength, true);
}

void Test7() {
	Test("Test7", NULL, NULL, 0, false); //这里若两栈均为空，判断为false
}

void Test8() {
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 1, 5, 4, 3, 2 };

	Test("Test8", push, pop, nLength, true);
}
int main(int argc, char** argv) {
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();

	return 0;
}

