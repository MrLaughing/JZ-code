//============================================================================
// Name        : JZ-C-24.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 二叉搜索树的后序遍历序列
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

// BST：Binary Search Tree，二叉搜索树
bool VerifySquenceOfBST(int sequence[], int length) {
	if (sequence == NULL || length <= 0) {
		return false;
	}
	int root = sequence[length - 1]; //后序遍历序列的最后一位为二叉搜索树的根结点
	// 在二叉搜索树中左子树的结点小于根结点
	int i = 0;
	for (; i < length - 1; i++) {
		if (sequence[i] > root) {
			break;
		}
	}
	// 在二叉搜索树中右子树的结点大于根结点
	int j = i;
	for (; j < length - 1; j++) {
		if (sequence[j] < root) {
			return false;
		}
	}
	// 递归判断左子树是不是二叉搜索树
	bool left = true;
	if (i > 0) {
		left = VerifySquenceOfBST(sequence, i);//结合长度i可只遍历数组中的左子树
	}
	// 递归判断右子树是不是二叉搜索树
	bool right = true;
	if (i < length- 1) {
		right = VerifySquenceOfBST(sequence+i,length-i-1);//sequence+i结合长度length-i-1可只遍历数组中的右子树★
	}
	return left&&right;

}

// ====================测试代码====================
void Test(char* testName, int sequence[], int length, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(VerifySquenceOfBST(sequence, length) == expected)
        printf("passed.\n");
    else
        printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    int data[] = {4, 8, 6, 12, 16, 14, 10};
    Test("Test1", data, sizeof(data)/sizeof(int), true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2()
{
    int data[] = {4, 6, 7, 5};
    Test("Test2", data, sizeof(data)/sizeof(int), true);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test3()
{
    int data[] = {1, 2, 3, 4, 5};
    Test("Test3", data, sizeof(data)/sizeof(int), true);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test4()
{
    int data[] = {5, 4, 3, 2, 1};
    Test("Test4", data, sizeof(data)/sizeof(int), true);
}

// 树中只有1个结点
void Test5()
{
    int data[] = {5};
    Test("Test5", data, sizeof(data)/sizeof(int), true);
}

void Test6()
{
    int data[] = {7, 4, 6, 5};
    Test("Test6", data, sizeof(data)/sizeof(int), false);
}

void Test7()
{
    int data[] = {4, 6, 12, 8, 16, 14, 10};
    Test("Test7", data, sizeof(data)/sizeof(int), false);
}

void Test8()
{
    Test("Test8", NULL, 0, false);
}

int main(int argc, char** argv)
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();

    return 0;
}
