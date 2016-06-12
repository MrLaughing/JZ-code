//============================================================================
// Name        : JZ-C-19.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 二叉树的镜像
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stack>
#include "BinaryTree.h"
using namespace std;
/**
 *前序遍历：递归
 */
void MirrorRecursively(BinaryTreeNode* root) {
	if (root == NULL) {
		return;
	}
	if (root->m_pLeft == NULL && root->m_pRight == NULL) { //这里是&&
		return;
	}
	BinaryTreeNode* temp = root->m_pLeft;
	; //临时结点，用于交换左右子孩子
	root->m_pLeft = root->m_pRight;
	root->m_pRight = temp;
	if (root->m_pLeft != NULL) {
		MirrorRecursively(root->m_pLeft);
	}
	if (root->m_pRight != NULL) {
		MirrorRecursively(root->m_pRight);
	}
}
/**
 *前序遍历：循环
 */
void MirrorIteratively(BinaryTreeNode *root) {
	if (root == NULL) {
		return;
	}
	std::stack<BinaryTreeNode*> stackTreeNode; //利用栈的出入来存储每次需要遍历的结点
	stackTreeNode.push(root);

	while (stackTreeNode.size() > 0) {
		BinaryTreeNode *Node = stackTreeNode.top(); //拿到要操作的结点
		stackTreeNode.pop(); //出栈

		BinaryTreeNode *temp = Node->m_pLeft;
		Node->m_pLeft = Node->m_pRight;
		Node->m_pRight = temp;

		if (Node->m_pLeft != NULL) {
			stackTreeNode.push(Node->m_pLeft);
		}
		if (Node->m_pRight != NULL) {
			stackTreeNode.push(Node->m_pRight);
		}
	}
}
// ====================测试代码====================
// 测试完全二叉树：除了叶子节点，其他节点都有两个子节点
//            8
//        6      10
//       5 7    9  11
void Test1() {
	printf("=====Test1 starts:=====\n");
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);

	PrintTree(pNode8);

	printf("=====Test1: MirrorRecursively=====\n");
	MirrorRecursively(pNode8);
	PrintTree(pNode8);

	printf("=====Test1: MirrorIteratively=====\n");
	MirrorIteratively(pNode8);
	PrintTree(pNode8);

	DestroyTree(pNode8);
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个左子结点
//            8
//          7
//        6
//      5
//    4
void Test2() {
	printf("=====Test2 starts:=====\n");
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

	ConnectTreeNodes(pNode8, pNode7, NULL);
	ConnectTreeNodes(pNode7, pNode6, NULL);
	ConnectTreeNodes(pNode6, pNode5, NULL);
	ConnectTreeNodes(pNode5, pNode4, NULL);

	PrintTree(pNode8);

	printf("=====Test2: MirrorRecursively=====\n");
	MirrorRecursively(pNode8);
	PrintTree(pNode8);

	printf("=====Test2: MirrorIteratively=====\n");
	MirrorIteratively(pNode8);
	PrintTree(pNode8);

	DestroyTree(pNode8);
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个右子结点
//            8
//             7
//              6
//               5
//                4
void Test3() {
	printf("=====Test3 starts:=====\n");
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

	ConnectTreeNodes(pNode8, NULL, pNode7);
	ConnectTreeNodes(pNode7, NULL, pNode6);
	ConnectTreeNodes(pNode6, NULL, pNode5);
	ConnectTreeNodes(pNode5, NULL, pNode4);

	PrintTree(pNode8);

	printf("=====Test3: MirrorRecursively=====\n");
	MirrorRecursively(pNode8);
	PrintTree(pNode8);

	printf("=====Test3: MirrorIteratively=====\n");
	MirrorIteratively(pNode8);
	PrintTree(pNode8);

	DestroyTree(pNode8);
}

// 测试空二叉树：根结点为空指针
void Test4() {
	printf("=====Test4 starts:=====\n");
	BinaryTreeNode* pNode = NULL;

	PrintTree(pNode);

	printf("=====Test4: MirrorRecursively=====\n");
	MirrorRecursively(pNode);
	PrintTree(pNode);

	printf("=====Test4: MirrorIteratively=====\n");
	MirrorIteratively(pNode);
	PrintTree(pNode);
}

// 测试只有一个结点的二叉树
void Test5() {
	printf("=====Test5 starts:=====\n");
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);

	PrintTree(pNode8);

	printf("=====Test4: MirrorRecursively=====\n");
	MirrorRecursively(pNode8);
	PrintTree(pNode8);

	printf("=====Test4: MirrorIteratively=====\n");
	MirrorIteratively(pNode8);
	PrintTree(pNode8);
}

int main(int argc, char** argv) {
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();

	return 0;
}

