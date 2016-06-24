//============================================================================
// Name        : JZ-C-45.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 圆圈中最后剩下的数字：0,1,..,n-1这n个数排成一个圆圈，从数字0开始每次从圆圈中删除第m个数字。求出圆圈中剩下的最后一个数字（约瑟夫环★）
//============================================================================

#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;

// ====================方法1====================
/**
 * 使用环形链表模拟圆圈，这里用模板库的std::list模拟环形链表，当迭代器扫描到链表末尾时候，将迭代器移到链表的头部
 * 每删除一个数字都需要m步运算，共n个数字，所以时间复杂度为O(m*n)，并且还需要一个辅助链表模拟圆圈，所以空间复杂度为O(n)
 */
int LastRemaining_Solution1(unsigned int n, unsigned int m) {
	if (n < 1 || m < 1)
		return -1;
	unsigned int i = 0;

	list<int> numbers;
	for (i = 0; i < n; ++i)
		numbers.push_back(i);

	list<int>::iterator current = numbers.begin();
	while (numbers.size() > 1) {
		for (int i = 1; i < m; ++i) { //m也可以为1
			current++;
			if (current == numbers.end()) //当迭代器扫描到链表末尾时候，将迭代器移到链表的头部
				current = numbers.begin();
		}

		list<int>::iterator next = ++current;
		if (next == numbers.end()) //当迭代器扫描到链表末尾时候，将迭代器移到链表的头部
			next = numbers.begin();

		--current;
		numbers.erase(current);
		current = next;
	}

	return *(current);
}

// ====================方法2====================
/**
 * n>1时：f(n,m) = [f(n-1,m)+m]%n;
 * n=1时：f(n,m) = 0;
 * 这种算法的时间复杂度为O(n)，空间复杂度为O(1)
 * 求解释！！！★★★
 */
int LastRemaining_Solution2(unsigned int n, unsigned int m) {
	if (n < 1 || m < 1)
		return -1;

	int last = 0;
	for (int i = 2; i <= n; i++)
		last = (last + m) % i;

	return last;
}

// ====================测试代码====================
void Test(char* testName, unsigned int n, unsigned int m, int expected) {
	if (testName != NULL)
		printf("%s begins: \n", testName);

	if (LastRemaining_Solution1(n, m) == expected)
		printf("Solution1 passed.\n");
	else
		printf("Solution1 failed.\n");

	if (LastRemaining_Solution2(n, m) == expected)
		printf("Solution2 passed.\n");
	else
		printf("Solution2 failed.\n");

	printf("\n");
}

void Test1() {
	Test("Test1", 5, 3, 3);
}

void Test2() {
	Test("Test2", 5, 2, 2);
}

void Test3() {
	Test("Test3", 6, 7, 4);
}

void Test4() {
	Test("Test4", 6, 6, 3);
}

void Test5() {
	Test("Test5", 0, 0, -1);
}

void Test6() {
	Test("Test6", 4000, 997, 1027);
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

