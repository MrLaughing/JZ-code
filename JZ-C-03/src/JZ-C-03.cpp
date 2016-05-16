//============================================================================
// Name        : JZ-C-03.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
/**
 *二维数组matrix中，每一行都从左到右递增排序， 每一列都从上到下递增排序
 *这里将要查找的data和矩阵一直和右上角的元素进行比较。
 */
bool FindData(int *matrix, int rows, int columns, int data) {
	if (matrix != NULL && rows > 0 && columns > 0) {
		int row = 0;
		int column = columns - 1;
		while (row <= rows - 1 && column >= 0) { //循环结束条件
			if (matrix[row * columns + column] == data) {//二维数组在内存中占据连续的空间
				return true;
			}
			if (matrix[row * columns + column] < data) {
				row += 1;
			} else if (matrix[row * columns + column] > data) {
				column -= 1;
			}
		}
	}
	return false;

}
int main() {
	int matrix[5][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6,
			8, 11, 15 }, { 7, 10, 13, 18 } };
	bool result = FindData((int *) matrix, 5, 4, 13); //二维数组，将指针array再转为整型指针?
	cout << boolalpha << result << endl; //boolalpha:功能是把bool值显示为true或false。
	return 0;
}
