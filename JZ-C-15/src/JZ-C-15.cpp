//============================================================================
// Name        : JZ-C-15.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 链表中倒数第K个结点
//============================================================================

#include <iostream>
#include "List.h"
#include <stdio.h>
using namespace std;

ListNode* FindKthToTail(ListNode* node, unsigned int k) {
	if (k == 0 || node == NULL) {
		return NULL;
	}
	ListNode* head = node;
	ListNode* follow = node;
	for (unsigned int i = 0; i < k - 1; i++) {
		if (head->m_pNext == NULL) {
			return NULL;
		} else {
			head = head->m_pNext;
		}
	}
	while (head->m_pNext != NULL) {
		head = head->m_pNext;
		follow = follow->m_pNext;
	}
	return follow;
}

// ====================测试代码====================
// 测试要找的结点在链表中间
void Test1() {
	printf("=====Test1 starts:=====\n");
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	printf("expected result: 4.\n");
	ListNode* pNode = FindKthToTail(pNode1, 2);
	PrintListNode(pNode);

	DestroyList(pNode1);
}

// 测试要找的结点是链表的尾结点
void Test2() {
	printf("=====Test2 starts:=====\n");
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	printf("expected result: 5.\n");
	ListNode* pNode = FindKthToTail(pNode1, 1);
	PrintListNode(pNode);

	DestroyList(pNode1);
}

// 测试要找的结点是链表的头结点
void Test3() {
	printf("=====Test3 starts:=====\n");
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	printf("expected result: 1.\n");
	ListNode* pNode = FindKthToTail(pNode1, 5);
	PrintListNode(pNode);

	DestroyList(pNode1);
}

// 测试空链表
void Test4() {
	printf("=====Test4 starts:=====\n");
	printf("expected result: NULL.\n");
	ListNode* pNode = FindKthToTail(NULL, 100);
	PrintListNode(pNode);
}

// 测试输入的第二个参数大于链表的结点总数
void Test5() {
	printf("=====Test5 starts:=====\n");
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	printf("expected result: NULL.\n");
	ListNode* pNode = FindKthToTail(pNode1, 6);
	PrintListNode(pNode);

	DestroyList(pNode1);
}

// 测试输入的第二个参数为0
void Test6() {
	printf("=====Test6 starts:=====\n");
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	printf("expected result: NULL.\n");
	ListNode* pNode = FindKthToTail(pNode1, 0);
	PrintListNode(pNode);

	DestroyList(pNode1);
}

int main(int argc, char** argv) {
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	return 0;
}

