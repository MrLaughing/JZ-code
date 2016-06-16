//============================================================================
// Name        : JZ-C-26.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 复杂链表的复制
//============================================================================

#include <iostream>
#include "ComplexList.h"
#include <stdio.h>
using namespace std;

void CloneNodes(ComplexListNode* pHead);
void ConnectSiblingNodes(ComplexListNode* pHead);
ComplexListNode* ReconnectNodes(ComplexListNode* pHead);

ComplexListNode* Clone(ComplexListNode* pHead) {
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}
/**
 *第一步：克隆Next结点
 */
void CloneNodes(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;
	while (pNode != NULL) {
		ComplexListNode* pCloneNode = new ComplexListNode();
		pCloneNode->m_nValue = pNode->m_nValue;
		pCloneNode->m_pNext = pNode->m_pNext;
		pNode->m_pNext = pCloneNode;
		pNode = pCloneNode->m_pNext; //进行下一次Clone
	}
}
/**
 *第二步：连接Sibling结点
 */
void ConnectSiblingNodes(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;
	while (pNode != NULL) {
		ComplexListNode* pCloneNode = pNode->m_pNext;
		if (pNode->m_pSibling != NULL) {
			pCloneNode->m_pSibling = pNode->m_pSibling->m_pNext;
		}
		pNode = pCloneNode->m_pNext;
	}
}
/**
 *第三步：拆分出复制的复杂链表
 */
ComplexListNode* ReconnectNodes(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;
	ComplexListNode* pCloneHead = NULL;
	ComplexListNode* pCloneNode = NULL;
	if (pNode != NULL) {
		pCloneHead = pCloneNode = pNode->m_pNext; //先确定复制链表的头
		pNode = pCloneNode->m_pNext;
	}
	while (pNode != NULL) {
		pCloneNode->m_pNext = pNode->m_pNext;
		pCloneNode = pCloneNode->m_pNext;
		pNode = pCloneNode->m_pNext;
	}
	return pCloneHead;
}

// ====================测试代码====================
void Test(char* testName, ComplexListNode* pHead) {
	if (testName != NULL)
		printf("%s begins:\n", testName);

	printf("The original list is:\n");
	PrintList(pHead);

	ComplexListNode* pClonedHead = Clone(pHead);

	printf("The cloned list is:\n");
	PrintList(pClonedHead);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1() {
	ComplexListNode* pNode1 = CreateNode(1);
	ComplexListNode* pNode2 = CreateNode(2);
	ComplexListNode* pNode3 = CreateNode(3);
	ComplexListNode* pNode4 = CreateNode(4);
	ComplexListNode* pNode5 = CreateNode(5);

	BuildNodes(pNode1, pNode2, pNode3);
	BuildNodes(pNode2, pNode3, pNode5);
	BuildNodes(pNode3, pNode4, NULL);
	BuildNodes(pNode4, pNode5, pNode2);

	Test("Test1", pNode1);
}

// m_pSibling指向结点自身
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test2() {
	ComplexListNode* pNode1 = CreateNode(1);
	ComplexListNode* pNode2 = CreateNode(2);
	ComplexListNode* pNode3 = CreateNode(3);
	ComplexListNode* pNode4 = CreateNode(4);
	ComplexListNode* pNode5 = CreateNode(5);

	BuildNodes(pNode1, pNode2, NULL);
	BuildNodes(pNode2, pNode3, pNode5);
	BuildNodes(pNode3, pNode4, pNode3);
	BuildNodes(pNode4, pNode5, pNode2);

	Test("Test2", pNode1);
}

// m_pSibling形成环
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void Test3() {
	ComplexListNode* pNode1 = CreateNode(1);
	ComplexListNode* pNode2 = CreateNode(2);
	ComplexListNode* pNode3 = CreateNode(3);
	ComplexListNode* pNode4 = CreateNode(4);
	ComplexListNode* pNode5 = CreateNode(5);

	BuildNodes(pNode1, pNode2, NULL);
	BuildNodes(pNode2, pNode3, pNode4);
	BuildNodes(pNode3, pNode4, NULL);
	BuildNodes(pNode4, pNode5, pNode2);

	Test("Test3", pNode1);
}

// 只有一个结点
void Test4() {
	ComplexListNode* pNode1 = CreateNode(1);
	BuildNodes(pNode1, NULL, pNode1);

	Test("Test4", pNode1);
}

// 鲁棒性测试
void Test5() {
	Test("Test5", NULL);
}

int main(int argc, char** argv) {
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();

	return 0;
}

