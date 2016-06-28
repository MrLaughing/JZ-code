//============================================================================
// Name        : JZ-C-47.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 不能用加减乘除做加法
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

int Add(int num1, int num2) {
	int sum, carry;
	do {
		sum = num1 ^ num2; //第一步：异或（各(★)位相加，先不考虑进位）
		carry = (num1 & num2) << 1; //第二步：先与运算再左移得到进位

		num1 = sum;
		num2 = carry;
	} while (num2 != 0); //第三步：前两个步骤的结果相加（重复前面两步，直到不产生进位为止）

	return num1;
}

// ====================测试代码====================
void Test(int num1, int num2, int expected) {
	int result = Add(num1, num2);
	if (result == expected)
		printf("%d + %d is %d. Passed\n", num1, num2, result);
	else
		printf("%d + %d is %d. Failed\n", num1, num2, result);
}

int main(int argc, char** argv) {
	Test(1, 2, 3);
	Test(111, 899, 1010);
	Test(-1, 2, 1);
	Test(1, -2, -1);
	Test(3, 0, 3);
	Test(0, -4, -4);
	Test(-2, -8, -10);
}

