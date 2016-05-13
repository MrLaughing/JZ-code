//============================================================================
// Name        : C++inEclipse.cpp
// Author      : Laughing
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "stdafx.h"
#include <string.h>
using namespace std;
/**
 *剑指offer面试题1
 */
class CMyString {
public:
	CMyString(char* pData = NULL); //构造函数
	CMyString(const CMyString &str); //类似复制构造函数？
	~CMyString(void);
	void print(); //打印
	CMyString& operator =(const CMyString &str); //赋值运算符重载：返回类型是该类型的引用，这样才可以允许连续赋值:"str=str1=str2"。const:因为在赋值运算符函数内不会改变传入的实例的状态
private:
	char* m_pData;
};
CMyString::CMyString(char *pData) {
	if (pData == NULL) { //若为空
		m_pData = new char[1];
		m_pData = '\0'; //字符串默认最后一位补'\0'
	} else {
		int length = strlen(pData); //字符串长度
		m_pData = new char[length + 1]; //为何+1?
		strcpy(m_pData, pData); //复制
	}
}
CMyString::CMyString(const CMyString &str) {
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
}
CMyString::~CMyString() {
	delete[] m_pData; //释放内存
}
void CMyString::print() {
	cout << m_pData << endl;
}
CMyString& CMyString::operator =(const CMyString& str) { //自动生成，前面有inline,为什么？
	if (this == &str) { //先判断传入的参数和当前实例是不是同一个实例★
		return *this;
	}
	/*若没上面的if判断，若为同一个实例，一旦释放自身的内存，传入的参数的内存同样被释放*/
	delete[] m_pData; //先释放内存
	m_pData = NULL;
	m_pData = new char[strlen(str.m_pData) + 1]; //重新分配空间
	strcpy(m_pData, str.m_pData);
	return *this; //返回实例自身的引用
}
int main() {
	cout << "Hello World!!!" << endl; // prints Hello World!!!
	char* str = "Hello World"; //有什么问题，和不加 const区别
	CMyString test(str);
	test.print();
	CMyString test2, test3;
	//test = test; //赋值给自己,此处以判断传入参数和当前实例相同时会不会出现问题
	test3 = test2 = test; //利用赋值运算符为对象test2,test3赋值
	test3.print();
	return 0;
}

