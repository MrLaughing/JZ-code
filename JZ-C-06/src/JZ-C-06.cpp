//============================================================================
// Name        : JZ-C-06.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <exception>
using namespace std;

typedef struct BinaryTreeNode { //二叉树结点
	int data; //数据域
	struct BinaryTreeNode *left; //左孩子
	struct BinaryTreeNode *right; //右孩子
} BTN;
BTN* ConstructBTCore(int *startPreOrder, int *endPreOrder, int *startInOrder,
		int *endInOrder); //函数调用在前，定义在后，需要先进行函数原型说明

BTN* ConstructBT(int *preOrder, int *inOrder, int length) {
	if (preOrder == NULL || inOrder == NULL || length <= 0) {
		cout << "序列为空？请检查两个序列" << endl;
		return NULL;
	}
	BTN *root = ConstructBTCore(preOrder, preOrder + length - 1, inOrder,
			inOrder + length - 1);
	cout << root->data << endl;//返回根
	return root;
}

BTN* ConstructBTCore(int *startPreOrder, int *endPreOrder, int *startInOrder,
		int *endInOrder) {
	BTN *root = new BTN(); //生成结点
	root->data = startPreOrder[0];
	root->left = root->right = NULL;
	if (endPreOrder == startPreOrder) {
		if (startInOrder == endInOrder && *startPreOrder == *startInOrder) {
			return root;
		} else {
			cout << "前序序列和中序序列不匹配，错误！" << endl;
			throw std::exception();
		}
	}
	int inOrderLength = endInOrder - startInOrder; //中序遍历序列长度
	int i = 0;
	for (; i < inOrderLength + 1; i++) { //在中序遍历序列里查找头结点的值
//		int rootInOrder =*startInOrder;
//		while(*startInOrder+rootInOrder){}
		if (*startPreOrder == *(startInOrder + i)) { //和前序遍历序列的头结点比较
			root->data = *startPreOrder; //头结点
			if (i > 0) { //如果有左子树
				root->left = ConstructBTCore(startPreOrder + 1,
						startPreOrder + i, startInOrder, startInOrder + i - 1); //递归遍历左子树序列
			}
			if (i < inOrderLength) { //如果有右子树
				root->right = ConstructBTCore(startPreOrder + i + 1,
						endPreOrder, startInOrder + i + 1, endInOrder); //递归遍历右子树序列
			}
			break; //退出循环
		}
	}
	if (i == inOrderLength + 1) { //说明中序遍历序列中没有和前序遍历序列头结点值相同的结点，错误
		cout << "中序序列中没有前序序列的头结点，错误！" << endl;
		throw std::exception();
	}
	return root;
}
int main() {
	const int length = 7; //完全二叉树
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 5, 1, 6, 3, 7 };
//	const int length = 8;//普通二叉树
//	int preorder[length] = { 1, 2, 4, 7, 3, 5, 6, 8 };
//	int inorder[length] = { 4, 7, 2, 1, 5, 3, 8, 6 };
//  const int length = 7;//不匹配的序列
//  int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
//  int inorder[length] = {4, 2, 8, 1, 6, 3, 7};
//	const int length = 5;//所有结点都没有右子结点
//	int preorder[length] = { 1, 2, 3, 4, 5 };
//	int inorder[length] = { 5, 4, 3, 2, 1 };
//    const int length = 5;//	所有结点都没有左子结点
//    int preorder[length] = {1, 2, 3, 4, 5};
//    int inorder[length] = {1, 2, 3, 4, 5};
//    const int length = 1;//树中只有一个结点
//    int preorder[length] = {1};
//    int inorder[length] = {1};
	ConstructBT(preorder, inorder, length);
//	ConstructBT(NULL, NULL, 0);//输入空指针

	return 0;
}
