//============================================================================
// Name        : JZ-C-13.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 在O(1)时间内删除链表结点
//============================================================================

#include <iostream>
#include "List.h"
using namespace std;

/*typedef struct ListNode {
 int value;
 ListNode* next;
 } NODE;*/

void DeleteNode(ListNode** HeadNode, ListNode* ToBeDeleted) {
	if (!HeadNode || !ToBeDeleted) {
		return;
	}
	if (ToBeDeleted->m_pNext != NULL) { // 要删除的结点不是尾结点
		ListNode* p = ToBeDeleted->m_pNext;
		ToBeDeleted->m_nValue = p->m_nValue;
		ToBeDeleted->m_pNext = p->m_pNext;
		delete p;
		p = NULL;
	} else if (*HeadNode == ToBeDeleted) { // 链表只有一个结点，删除头结点（也是尾结点）
		delete ToBeDeleted;
		ToBeDeleted = NULL;
		*HeadNode = NULL;
	} else { // 链表中有多个结点，删除尾结点
		ListNode* p = *HeadNode;
		while (p->m_pNext != ToBeDeleted) {
			p = p->m_pNext;
		}
		p->m_pNext = NULL;
		delete ToBeDeleted;
		ToBeDeleted = NULL;
	}

}
// ====================测试代码====================
void Test(ListNode* pListHead, ListNode* pNode) {
//	printf("The original list is: \n");
	cout << "The original list is:" << endl;
	PrintList(pListHead);

//	printf("The node to be deleted is: \n");
	cout << "The node to be deleted is:" << endl;
	PrintListNode(pNode);

	DeleteNode(&pListHead, pNode);
//	printf("The result list is: \n");
	cout << "The result list is:" << endl;
	PrintList(pListHead);
}

// 链表中有多个结点，删除中间的结点
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

	Test(pNode1, pNode3);

	DestroyList(pNode1);
}

// 链表中有多个结点，删除尾结点
void Test2() {
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1, pNode5);

	DestroyList(pNode1);
}

// 链表中有多个结点，删除头结点
void Test3() {
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1, pNode1);

	DestroyList(pNode1);
}

// 链表中只有一个结点，删除头结点
void Test4() {
	ListNode* pNode1 = CreateListNode(1);

	Test(pNode1, pNode1);
}

// 链表为空
void Test5() {
	Test(NULL, NULL);
}

int main(int argc, char** argv) {
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();

	return 0;
}

