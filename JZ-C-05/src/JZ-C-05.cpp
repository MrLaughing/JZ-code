//============================================================================
// Name        : JZ-C-05.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <stack>
#include  <list>
using namespace std;

typedef struct SNode {
	int data;
	struct SNode *next;
} NODE;

/*从尾到头打印链表:递归*/
void PrintListReverse1(NODE * head) {
	if (head != NULL) {
		if (head->next != NULL) {
			PrintListReverse1(head->next); //递归
		}
		cout << head->data << setw(3);
	}
}
/*从尾到头打印链表：利用栈的后进先出特点*/
void PrintListReverse2(NODE *head) {
	std::stack<NODE*> nodes; //创建一个栈，存入NODE*类型的元素
	NODE *p = head;
	while (p != NULL) {
		nodes.push(p); //压入栈中
		p = p->next;
	}
	while (!nodes.empty()) {
		cout <<nodes.top()->data << setw(3); //'后进先出'出栈
		nodes.pop();
	}
}
/*建立一个单链表*/
NODE* CreatList() {
	NODE *node1 = new NODE();
	NODE *node2 = new NODE();
	NODE *node3 = new NODE();
	NODE *node4 = new NODE();
	NODE *node5 = new NODE();
	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;
	node5->data = 5;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	return node1;
}
int main() {
	NODE *head = CreatList();
//	NODE *head = NULL;
	PrintListReverse2(head);
	return 0;
}
