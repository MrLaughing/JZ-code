//============================================================================
// Name        : JZ-C-18.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 树的子结构
//============================================================================

#include <iostream>
#include <stdio.h>
#include "BinaryTree.h"
using namespace std;

bool DoesTree(BinaryTreeNode* pRoot, BinaryTreeNode* qRoot); //先函数原型声明

bool HasSubTree(BinaryTreeNode* pRoot, BinaryTreeNode* qRoot) {
	bool result = false;
	if (pRoot != NULL && qRoot != NULL) {
		if (pRoot->m_nValue == qRoot->m_nValue) {
			result = DoesTree(pRoot, qRoot);
		}
		if (!result) {
			result = HasSubTree(pRoot->m_pLeft, qRoot);
		}
		if (!result) {
			result = HasSubTree(pRoot->m_pRight, qRoot);
		}
	}
	return result;
}
bool DoesTree(BinaryTreeNode* pRoot, BinaryTreeNode* qRoot) {
	if (qRoot == NULL) {
		return true;
	}
	if (pRoot == NULL) {
		return false;
	}
	if (pRoot->m_nValue != qRoot->m_nValue) {
		return false;
	}
	return DoesTree(pRoot->m_pLeft, qRoot->m_pLeft)
			&& DoesTree(pRoot->m_pRight, qRoot->m_pRight);
}
// ====================测试代码====================
void Test(char* testName, BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2,
		bool expected) {
	if (HasSubTree(pRoot1, pRoot2) == expected)
		printf("%s passed.\n", testName);
	else
		printf("%s failed.\n", testName);
}

// 树中结点含有分叉，树B是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     2
//               / \
//              4   7
void Test1() {
	BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
	ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
	ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

	BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

	Test("Test1", pNodeA1, pNodeB1, true);

	DestroyTree(pNodeA1);
	DestroyTree(pNodeB1);
}

// 树中结点含有分叉，树B不是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     3
//               / \
//              4   7
void Test2() {
	BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
	ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
	ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

	BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

	Test("Test2", pNodeA1, pNodeB1, false);

	DestroyTree(pNodeA1);
	DestroyTree(pNodeB1);
}

// 树中结点只有左子结点，树B是树A的子结构
//                8                  8
//              /                   /
//             8                   9
//           /                    /
//          9                    2
//         /
//        2
//       /
//      5
void Test3() {
	BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNodeA1, pNodeA2, NULL);
	ConnectTreeNodes(pNodeA2, pNodeA3, NULL);
	ConnectTreeNodes(pNodeA3, pNodeA4, NULL);
	ConnectTreeNodes(pNodeA4, pNodeA5, NULL);

	BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNodeB1, pNodeB2, NULL);
	ConnectTreeNodes(pNodeB2, pNodeB3, NULL);

	Test("Test3", pNodeA1, pNodeB1, true);

	DestroyTree(pNodeA1);
	DestroyTree(pNodeB1);
}

// 树中结点只有左子结点，树B不是树A的子结构
//                8                  8
//              /                   /
//             8                   9
//           /                    /
//          9                    3
//         /
//        2
//       /
//      5
void Test4() {
	BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNodeA1, pNodeA2, NULL);
	ConnectTreeNodes(pNodeA2, pNodeA3, NULL);
	ConnectTreeNodes(pNodeA3, pNodeA4, NULL);
	ConnectTreeNodes(pNodeA4, pNodeA5, NULL);

	BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(3);

	ConnectTreeNodes(pNodeB1, pNodeB2, NULL);
	ConnectTreeNodes(pNodeB2, pNodeB3, NULL);

	Test("Test4", pNodeA1, pNodeB1, false);

	DestroyTree(pNodeA1);
	DestroyTree(pNodeB1);
}

// 树中结点只有右子结点，树B是树A的子结构
//       8                   8
//        \                   \
//         8                   9
//          \                   \
//           9                   2
//            \
//             2
//              \
//               5
void Test5() {
	BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNodeA1, NULL, pNodeA2);
	ConnectTreeNodes(pNodeA2, NULL, pNodeA3);
	ConnectTreeNodes(pNodeA3, NULL, pNodeA4);
	ConnectTreeNodes(pNodeA4, NULL, pNodeA5);

	BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNodeB1, NULL, pNodeB2);
	ConnectTreeNodes(pNodeB2, NULL, pNodeB3);

	Test("Test5", pNodeA1, pNodeB1, true);

	DestroyTree(pNodeA1);
	DestroyTree(pNodeB1);
}

// 树A中结点只有右子结点，树B不是树A的子结构
//       8                   8
//        \                   \
//         8                   9
//          \                 / \
//           9               3   2
//            \
//             2
//              \
//               5
void Test6() {
	BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNodeA1, NULL, pNodeA2);
	ConnectTreeNodes(pNodeA2, NULL, pNodeA3);
	ConnectTreeNodes(pNodeA3, NULL, pNodeA4);
	ConnectTreeNodes(pNodeA4, NULL, pNodeA5);

	BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNodeB4 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNodeB1, NULL, pNodeB2);
	ConnectTreeNodes(pNodeB2, pNodeB3, pNodeB4);

	Test("Test6", pNodeA1, pNodeB1, false);

	DestroyTree(pNodeA1);
	DestroyTree(pNodeB1);
}

// 树A为空树
void Test7() {
	BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNodeB4 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNodeB1, NULL, pNodeB2);
	ConnectTreeNodes(pNodeB2, pNodeB3, pNodeB4);

	Test("Test7", NULL, pNodeB1, false);

	DestroyTree(pNodeB1);
}

// 树B为空树
void Test8() {
	BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNodeA1, NULL, pNodeA2);
	ConnectTreeNodes(pNodeA2, pNodeA3, pNodeA4);

	Test("Test8", pNodeA1, NULL, false);

	DestroyTree(pNodeA1);
}

// 树A和树B都为空
void Test9() {
	Test("Test9", NULL, NULL, false);
}

int main(int argc, char** argv) {
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();
	return 0;
}
