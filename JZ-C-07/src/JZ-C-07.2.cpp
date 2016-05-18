//============================================================================
// Name        : JZ-C-07.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description :扩展：利用两个队列实现栈
//============================================================================

#include <iostream>
#include <queue>
using namespace std;
template<typename T> //类模板，typename可替换为class
class CStack {
public:
	CStack(void); //缺省构造函数
	~CStack(void);
	void appendHead(const T& node); // 入栈
	T deleteHead(); //出栈
private:
	queue<T> queue1;
	queue<T> queue2;
};
//对使用类模板的类的函数，都要在前面加上类模板
template<typename T> CStack<T>::CStack(void) {
}
template<typename T> CStack<T>::~CStack(void) {
}
/**
 *入栈：此处实现是判断两个队列哪个为不为空（为空的队列用来出栈，交替使用）
 */
template<typename T> void CStack<T>::appendHead(const T& element) { //这里为什么是&呢？
	if (!queue1.empty()) {
		queue1.push(element);
	} else {
		queue2.push(element); //默认第一次入栈插入第二个队列
	}
}
/**
 * 出栈：此处实现是将某个不为空的队列除最后一个元素全部出队列并插入另一个队列中
 */
template<typename T> T CStack<T>::deleteHead() {
	if (queue1.empty() && queue2.empty()) {
		cout << "栈已为空，错误！" << endl;
		throw new exception();
	} else if (!queue1.empty()) {
		while (queue1.size() > 1) {
			T& node = queue1.front();
			queue1.pop();
			queue2.push(node);
		}
		T& node = queue1.front(); //将最后压入的元素出栈，出栈后queue1为空
		queue1.pop();
		return node;
	} else if (!queue2.empty()) {
		while (queue2.size() > 1) {
			T& node = queue2.front();
			queue2.pop();
			queue1.push(node);
		}
		T& node = queue2.front(); //将最后压入的元素出栈，出栈后queue2为空
		queue2.pop();
		return node;
	}
	return 0;//并没意义
}
/*int main() {
	CStack<char> stack;
	stack.appendHead('a');
	stack.appendHead('b');
	stack.appendHead('c');
	stack.appendHead('d');
	char result1 = stack.deleteHead();
	cout << result1 << endl;
	stack.appendHead('e');
	char result2 = stack.deleteHead();
	cout << result2 << endl;
	char result3 = stack.deleteHead();
	cout << result3 << endl;
	char result4 = stack.deleteHead();
	cout << result4 << endl;
	char result5 = stack.deleteHead();
	cout << result5 << endl;
//	char result6 = stack.deleteHead();//栈已为空
//	cout << result6 << endl;
	return 0;
}*/
