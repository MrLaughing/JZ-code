//============================================================================
// Name        : JZ-C-09.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 斐波那契数列
//============================================================================

#include <iostream>
using namespace std;
/**
 *输入n，返回第n个斐波那契数
 */
double Fibonacci(int n) {
	double fi;
	if (n <= 0) {
		return -1; //错误
	} else if (n == 1 || n == 2) {
		fi = 1;
	} else {
		fi = Fibonacci(n - 1) + Fibonacci(n - 2);//递归的时间复杂度是n的指数递增，还可能导致栈溢出
	}
	return fi;
}
long long Fibonacci1(int n) {
	long long previous[] = { 1, 1 };//避免重复计算，利用数组存储第n-1和n-2个数。时间复杂度为0(n)
	if (n <= 0) {
		return -1; //错误
	} else {
		if (n == 1 || n == 2) {
			return previous[n-1];
		}
		for (int m = 2; m < n; m++) {
			long long pre = previous[1];
			previous[1] = previous[0] + previous[1];
			previous[0] = pre;
		}
		return previous[1];
	}
}
int main() {
	long long result = Fibonacci1(50);
	cout << result << endl;
	return 0;
	return 0;
}
