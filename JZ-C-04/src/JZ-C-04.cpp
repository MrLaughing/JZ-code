//============================================================================
// Name        : JZ-C-04.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <string>
using namespace std;

char* ReplaceBlank(char string[]) {
	int length = strlen(string);
	if (length > 0) {
		int number = 0; //初始化
		for (int i = 0; i < length; i++) {
			if (string[i] == ' ') {
				number++; //先记录空格数
			}
		}
		int newLength = length + number * 2; //重新定义字符串长度
		char* result = new char[newLength]; //定义新的字符串
		char *p, *q; //定义两个指向两字符串的指针
		p = string;
		q = result;
		int pIndex = length - 1; //从字符串末尾向前依次输出，遇到空格，转换为%20
		int qIndex = newLength - 1;
		while (pIndex >= 0 && qIndex >= 0) {
			if (p[pIndex] == ' ') {
				q[qIndex--] = '0';
				q[qIndex--] = '2';
				q[qIndex--] = '%';
				pIndex--;
			} else {
				q[qIndex--] = p[pIndex--];
			}
		}
		q[newLength] = '\0';//最后补位'\0'
		return result;
	} else {
		cout << "字符串为空" << endl;
		return NULL;
	}
}
int main() {
	char string[] = "Hello World ";
	char* result = ReplaceBlank(string);
	cout << "转换后：" << result << endl;
	delete[] result;//释放内存，针对函数里的char* result =new char[...] ?
	return 0;
}
