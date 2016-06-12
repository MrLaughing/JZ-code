//============================================================================
// Name        : JZ-C-21.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stack>
#include <assert.h>
using namespace std;
template<typename T> class StackWithMin {
public:
	StackWithMin<T>(void) {
	}
	;
	~StackWithMin<T>(void) {
	}
	; //析构函数
	void push(const T& value);
	T& top(void);
	const T& top(void) const;
	void pop(void);
	const T& min(void) const;
	bool empty(void) const;
	size_t size() const;
private:
	std::stack<T> dataStack; //存放数据
	std::stack<T> minStack; //存放最小值
};
template<typename T> void StackWithMin<T>::push(const T& value) {
	dataStack.push(value); //数据压入数据栈
	if (minStack.size() == 0 || value < minStack.top()) {
		minStack.push(value); //比较后压入最小值栈
	} else {
		minStack.push(minStack.top()); //若比最小值大，则重复压入最小值
	}
}
template<typename T> void StackWithMin<T>::pop() {
	assert(!minStack.empty() && !dataStack.empty()); //这里为什么要用assert？用法？
	dataStack.pop();
	minStack.pop();
}
template<typename T> const T& StackWithMin<T>::min() const {
	assert(dataStack.size() > 0 && dataStack.size() > 0);

	return minStack.top();
}

template<typename T> T& StackWithMin<T>::top() {
	return dataStack.top();
}

template<typename T> const T& StackWithMin<T>::top() const {
	return dataStack.top();
}
template<typename T> bool StackWithMin<T>::empty() const {
	return dataStack.empty();
}

template<typename T> size_t StackWithMin<T>::size() const {
	return dataStack.size();
}

void Test(char* testName, const StackWithMin<int>& stack, int expected) {
	if (testName != NULL)
		printf("%s begins: ", testName);

	if (stack.min() == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}
int main(int argc, char** argv) {
	StackWithMin<int> stack;

	stack.push(3);
	Test("Test1", stack, 3);

	stack.push(4);
	Test("Test2", stack, 3);

	stack.push(2);
	Test("Test3", stack, 2);

	stack.push(3);
	Test("Test4", stack, 2);

	stack.pop();
	Test("Test5", stack, 2);

	stack.pop();
	Test("Test6", stack, 3);

	stack.pop();
	Test("Test7", stack, 3);

	stack.push(0);
	Test("Test8", stack, 0);

	return 0;
}
