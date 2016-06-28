//============================================================================
// Name        : JZ-C-46.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 求1+2+3+...+n：要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;
// ====================方法一:利用构造函数求解====================
class Temp {
public:
	Temp() {
		++N;
		Sum += N;
	}

	static void Reset() { //注意这里是静态方法
		N = 0;
		Sum = 0;
	}
	static unsigned int GetSum() { //注意这里是静态方法
		return Sum;
	}

private:
	static unsigned int N; //注意这里是静态变量
	static unsigned int Sum; //注意这里是静态变量
};

unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

unsigned int Sum_Solution1(unsigned int n) {
	Temp::Reset();

	Temp *a = new Temp[n]; //这里创建的是对象数组
	delete[] a;
	a = NULL;

	return Temp::GetSum();
}

// ====================方法二:利用虚函数求解====================
/**
 * 一个函数充当递归函数的角色，另一个函数处理终止递归的情况，因此使用布尔变量，若n不为0，!!n为1;若n为0，!!n为0；
 */
class A;
A* Array[2];

class A {
public:
	virtual unsigned int Sum(unsigned int n) {
		return 0;
	}
};

class B: public A {
public:
	virtual unsigned int Sum(unsigned int n) {
		return Array[!!n]->Sum(n - 1) + n;
	}
};

int Sum_Solution2(int n) {
	A a;
	B b;
	Array[0] = &a; //递归结束，调用的为父类Sum方法
	Array[1] = &b;

	int value = Array[1]->Sum(n);

	return value;
}

// ====================方法三：利用函数指针求解====================
typedef unsigned int (*fun)(unsigned int); //函数指针定义

unsigned int Solution3_Teminator(unsigned int n) {
	return 0;
}

unsigned int Sum_Solution3(unsigned int n) {
	static fun f[2] = { Solution3_Teminator, Sum_Solution3 };
	return n + f[!!n](n - 1);
}

// ====================方法四：利用模板类型求解====================
template<unsigned int n> struct Sum_Solution4 {
	enum Value {//enum：枚举类型
		N = Sum_Solution4<n - 1>::N + n
	};
};

template<> struct Sum_Solution4<1> {
	enum Value {
		N = 1
	};
};

template<> struct Sum_Solution4<0> {
	enum Value {
		N = 0
	};
};

// ====================测试代码====================
void Test(int n, int expected) {
	printf("Test for %d begins:\n", n);

	if (Sum_Solution1(n) == expected)
		printf("Solution1 passed.\n");
	else
		printf("Solution1 failed.\n");

	if (Sum_Solution2(n) == expected)
		printf("Solution2 passed.\n");
	else
		printf("Solution2 failed.\n");

	if (Sum_Solution3(n) == expected)
		printf("Solution3 passed.\n");
	else
		printf("Solution3 failed.\n");
}

void Test1() {
	const unsigned int number = 1;
	int expected = 1;
	Test(number, expected);
	if (Sum_Solution4<number>::N == expected)
		printf("Solution4 passed.\n");
	else
		printf("Solution4 failed.\n");
}

void Test2() {
	const unsigned int number = 5;
	int expected = 15;
	Test(number, expected);
	if (Sum_Solution4<number>::N == expected)
		printf("Solution4 passed.\n");
	else
		printf("Solution4 failed.\n");
}

void Test3() {
	const unsigned int number = 10;
	int expected = 55;
	Test(number, expected);
	if (Sum_Solution4<number>::N == expected)
		printf("Solution4 passed.\n");
	else
		printf("Solution4 failed.\n");
}

void Test4() {
	const unsigned int number = 0;
	int expected = 0;
	Test(number, expected);
	if (Sum_Solution4<number>::N == expected)
		printf("Solution4 passed.\n");
	else
		printf("Solution4 failed.\n");
}

int main(int argc, char** argvb) {
	Test1();
	Test2();
	Test3();
	Test4();

	return 0;
}

