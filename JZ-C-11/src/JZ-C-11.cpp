//============================================================================
// Name        : JZ-C-11.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 数值的整数次方
//============================================================================

#include <iostream>
using namespace std;

bool equal(double num1, double num2);
double Power(double base, int exponent) {
	double result = 1;
	if (exponent > 0) {
		if (equal(base, 0.0)) {
			result = 0;
		} else {
			while (exponent > 0) {
				result = result * base;
				exponent--;
			}
		}
	} else if (exponent == 0) {
		if (equal(base, 0.0)) { //这里不能直接判断exponent == 0,原因：计算机内表示小数时都有误差，判断判断两个小数是否相等，只能判断它们之差的绝对值是不是在一个很小的范围，如小于0.0000001★★
			cout << "无意义" << endl;
			result = 0; //0的0次方没意义★★
		} else {
			result = 1;
		}
	} else {
		if (equal(base, 0.0)) {
			result = 0;
		} else {
			exponent = -exponent; //取绝对值
			while (exponent > 0) {
				result = result * base;
				exponent--;
			}
			result = 1 / result;
		}

	}
	return result;
}
bool equal(double num1, double num2) { //判断两个小数是否相等★★
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001)) {
		return true;
	} else {
		return false;
	}
}
/*
 *这里没有使用此函数，此函数好处在于位运算的效率比乘除法及求余运算效率高
 */
/*double PowerWithUnsignedExponent(double base, unsigned int exponent) {
	if (exponent == 0) {
		return 1;
	}
	if (exponent == 1) {
		return base;
	}
	double result = PowerWithUnsignedExponent(base, exponent >> 1);//用右移代替除以2 ★
	result *= result;
	if ((exponent & 0x1) == 1) {//用与运算判断指数是奇数或偶数 ★
		result *= base;
	}
	return result;
}*/

int main() {
	double result = Power(9, 5);
	cout << result << endl;
	return 0;
}
