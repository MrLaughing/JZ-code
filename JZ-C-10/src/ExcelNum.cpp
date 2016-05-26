//============================================================================
// Name        : ExcelNum.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 位运算
//============================================================================

#include <iostream>
#include <stack>
using namespace std;
/**
 *输入十进制整数，返回A-Z进制数
 */
char ExcelNum(int n) {
	char result = 0;
	if (n <= 0) {
		cout<<"错误"<<endl;
		return -1; //错误
	} else {
		std::stack<char> s;
		while (n > 0) {
			int remain = n % 26;
			remain == 0?remain = 26,n = n-1:NULL;
			result = remain + 64;
			n = n / 26;
			s.push(result);
		}
		cout<<"A-Z进制数为："<<endl;
		while(!s.empty()){
			cout<<s.top();
			s.pop();
		}
	}

	return result;
}

/*int main() {
	ExcelNum(27);
	return 0;
}*/
