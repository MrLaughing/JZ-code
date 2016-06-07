//============================================================================
// Name        : JZ-C-16.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 反转链表
//============================================================================

#include <iostream>
#include "List.h"
#include <stdio.h>
using namespace std;

ListNode* ReverseList(ListNode* pHead) {
	ListNode* RevNode = pHead;
	ListNode* Node = pHead;
	ListNode* preNode = NULL;
	while (Node != NULL) {//考虑链表为空的情况
		ListNode* nexNode = Node->m_pNext;
		if (nexNode == NULL) {
			RevNode = Node; //在原链表最后一个结点处，将尾结点赋值为新链表的头结点
		}
		Node->m_pNext = preNode; //修改Next结点
		preNode = Node;
		Node = nexNode;
	}
	return RevNode;
}

// ====================测试代码====================
ListNode* Test(ListNode* pHead) {
	printf("The original list is: \n");
	PrintList(pHead);

	ListNode* pReversedHead = ReverseList(pHead);

	printf("The reversed list is: \n");
	PrintList(pReversedHead);

	return pReversedHead;
}

// 输入的链表有多个结点
void Test1() {
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	ListNode* pReversedHead = Test(pNode1);

	DestroyList(pReversedHead);
}

// 输入的链表只有一个结点
void Test2() {
	ListNode* pNode1 = CreateListNode(1);

	ListNode* pReversedHead = Test(pNode1);

	DestroyList(pReversedHead);
}

// 输入空链表
void Test3() {
	Test(NULL);
}

int main(int argc, char** argv) {
	Test1();
	Test2();
	Test3();

	return 0;
}

