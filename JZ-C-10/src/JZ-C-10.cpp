//============================================================================
// Name        : JZ-C-10.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 位运算
//============================================================================

#include <iostream>
#include <stack>
using namespace std;
/**
 *位运算:
 */
int Number(int n) {
	int count = 0;
	while (n > 0) {
		if (n & 1) { //和1（...01）相与运算，保证除最低位均为0，若最低位为1，则与运算结果为1，否则为0 ★★
			count++;
		}
		n = n >> 1; //将要判断的数右移一位（有可能出现死循环，如0X80000000 为负数，后移一位为0XC0000000（负数右移左端补1），最后变成0XFFFFFFFF，死循环···★★）
	}
	return count;
}
int Number1(int n) {
	int count = 0;
	int flag = 1;
	int time = 0;
	while (flag) {
		cout << "第" << ++time << "次" << endl;
		if (flag & n) {
			count++;
		}
		flag = flag << 1; //将flag左移，避免死循环。32位整数需要移位32次★★
	}
	return count;
}
int Number2(int n) {
	int count = 0;
	while (n) {
		++count;
		n = n & (n - 1);// n-1：将从低至高位第一个1变为0，同时从低至高位第一个1后的所有0变为了1，n&(n-1):将从低至高的第一个1及其后面的数全部变为0 循环即可★★
	}
	return count;
}
int main() {
//	cout << Number(0x80000000) << endl; //前面带0 表示八进制，前面带0x 表示十六进制
//	cout << Number1(10) << endl; //前面带0 表示八进制，前面带0x 表示十六进制
	cout<<Number2(12)<<endl;//最优
	return 0;
}
