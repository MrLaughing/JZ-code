//============================================================================
// Name        : JZ-C-50.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 树中两个结点的最低公共祖先：这里的树是普通树，且没有指向父结点的指针。
//============================================================================

#include <iostream>
#include <stdio.h>
#include "Tree.h"
#include <list>
using namespace std;

using namespace std;
/**
 * 获得从树的根结点到某结点的路径
 */
bool GetNodePath(TreeNode* pRoot, TreeNode* pNode, list<TreeNode*>& path) {
	if (pRoot == pNode)
		return true;

	path.push_back(pRoot);

	bool found = false;

	vector<TreeNode*>::iterator i = pRoot->m_vChildren.begin(); //这里的树为普通树，甚至不是二叉树。所以这里按照前序遍历子树即可。
	while (!found && i < pRoot->m_vChildren.end()) {
		found = GetNodePath(*i, pNode, path);
		++i;
	}

	if (!found)
		path.pop_back();

	return found;
}
/**
 * 获得两条路径的最后一个公共结点。
 */
TreeNode* GetLastCommonNode(const list<TreeNode*>& path1,
		const list<TreeNode*>& path2) {
	list<TreeNode*>::const_iterator iterator1 = path1.begin();
	list<TreeNode*>::const_iterator iterator2 = path2.begin();

	TreeNode* pLast = NULL;

	while (iterator1 != path1.end() && iterator2 != path2.end()) {
		if (*iterator1 == *iterator2)
			pLast = *iterator1; //遍历完两条路径，得到最后一个公共结点。

		iterator1++;
		iterator2++;
	}

	return pLast;
}

TreeNode* GetLastCommonParent(TreeNode* pRoot, TreeNode* pNode1,
		TreeNode* pNode2) {
	if (pRoot == NULL || pNode1 == NULL || pNode2 == NULL)
		return NULL;

	list<TreeNode*> path1;
	GetNodePath(pRoot, pNode1, path1);

	list<TreeNode*> path2;
	GetNodePath(pRoot, pNode2, path2);

	return GetLastCommonNode(path1, path2);
}

// ====================测试代码====================

void Test(char* testName, TreeNode* pRoot, TreeNode* pNode1, TreeNode* pNode2,
		TreeNode* pExpected) {
	if (testName != NULL)
		printf("%s begins: \n", testName);

	TreeNode* pResult = GetLastCommonParent(pRoot, pNode1, pNode2);

	if ((pExpected == NULL && pResult == NULL)
			|| (pExpected != NULL && pResult != NULL
					&& pResult->m_nValue == pExpected->m_nValue))
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 形状普通的树
//              1
//            /   \
//           2     3
//       /       \
//      4         5
//     / \      / |  \
//    6   7    8  9  10
void Test1() {
	TreeNode* pNode1 = CreateTreeNode(1);
	TreeNode* pNode2 = CreateTreeNode(2);
	TreeNode* pNode3 = CreateTreeNode(3);
	TreeNode* pNode4 = CreateTreeNode(4);
	TreeNode* pNode5 = CreateTreeNode(5);
	TreeNode* pNode6 = CreateTreeNode(6);
	TreeNode* pNode7 = CreateTreeNode(7);
	TreeNode* pNode8 = CreateTreeNode(8);
	TreeNode* pNode9 = CreateTreeNode(9);
	TreeNode* pNode10 = CreateTreeNode(10);

	ConnectTreeNodes(pNode1, pNode2);
	ConnectTreeNodes(pNode1, pNode3);

	ConnectTreeNodes(pNode2, pNode4);
	ConnectTreeNodes(pNode2, pNode5);

	ConnectTreeNodes(pNode4, pNode6);
	ConnectTreeNodes(pNode4, pNode7);

	ConnectTreeNodes(pNode5, pNode8);
	ConnectTreeNodes(pNode5, pNode9);
	ConnectTreeNodes(pNode5, pNode10);

	Test("Test1", pNode1, pNode6, pNode8, pNode2);
}

// 树退化成一个链表
//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test2() {
	TreeNode* pNode1 = CreateTreeNode(1);
	TreeNode* pNode2 = CreateTreeNode(2);
	TreeNode* pNode3 = CreateTreeNode(3);
	TreeNode* pNode4 = CreateTreeNode(4);
	TreeNode* pNode5 = CreateTreeNode(5);

	ConnectTreeNodes(pNode1, pNode2);
	ConnectTreeNodes(pNode2, pNode3);
	ConnectTreeNodes(pNode3, pNode4);
	ConnectTreeNodes(pNode4, pNode5);

	Test("Test2", pNode1, pNode5, pNode4, pNode3);
}

// 树退化成一个链表，一个结点不在树中
//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test3() {
	TreeNode* pNode1 = CreateTreeNode(1);
	TreeNode* pNode2 = CreateTreeNode(2);
	TreeNode* pNode3 = CreateTreeNode(3);
	TreeNode* pNode4 = CreateTreeNode(4);
	TreeNode* pNode5 = CreateTreeNode(5);

	ConnectTreeNodes(pNode1, pNode2);
	ConnectTreeNodes(pNode2, pNode3);
	ConnectTreeNodes(pNode3, pNode4);
	ConnectTreeNodes(pNode4, pNode5);

	TreeNode* pNode6 = CreateTreeNode(6);

	Test("Test3", pNode1, pNode5, pNode6, NULL);
}

// 输入NULL
void Test4() {
	Test("Test4", NULL, NULL, NULL, NULL);
}

int main(int argc, char** argv) {
	Test1();
	Test2();
	Test3();
	Test4();

	return 0;
}

