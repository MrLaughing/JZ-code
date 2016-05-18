//============================================================================
// Name        : JZ-C-07.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description :利用两个栈实现队列
//============================================================================

#include <iostream>
#include <stack>
using namespace std;
template<typename T> //类模板，typename可替换为class
class CQueue {
public:
	CQueue(void); //缺省构造函数
	~CQueue(void);
	void appendTail(const T& node); // 在队列末尾添加一个结点
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};
//对使用类模板的类的函数，都要在前面加上类模板
template<typename T> CQueue<T>::CQueue(void) {
}
template<typename T> CQueue<T>::~CQueue(void) {
}
/**
 *队列的插入在队列尾部：此处实现是在stack1里push
 */
template<typename T> void CQueue<T>::appendTail(const T& element) { //这里为什么是&呢？
	stack1.push(element);
}
/**
 * 队列的取出在队列头部：此处实现是根据stack2中的栈顶元素是最先进入队列的元素（通过判断stack2是否为空）
 */
template<typename T> T CQueue<T>::deleteHead() {
	if (stack2.empty()) {
		//将stack1全部压入stack2中
		while (!stack1.empty()) {
			T& node = stack1.top();
			stack1.pop();
			stack2.push(node);
		}
	}
	if (stack2.empty()) { //再次判断，如果stack2栈空，说明队列已空★
		cout << "队列为空" << endl;
		throw new exception();
	}
	//从stack2中取出栈顶元素
	T node = stack2.top();
	stack2.pop();
	return node;
}
int main() {
	CQueue<char> queue;
	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');
	char result1 = queue.deleteHead();
	queue.appendTail('d');
	char result2 = queue.deleteHead();
	cout<<result1<<endl;
	cout<<result2<<endl;
	char result3 = queue.deleteHead();
	cout<<result3<<endl;
	char result4 = queue.deleteHead();
	cout<<result4<<endl;
//	char result5 = queue.deleteHead();//队列已为空
	return 0;
}
