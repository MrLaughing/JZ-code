//============================================================================
// Name        : JZ-C-08.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 旋转数组的最小数字：（二分查找）
//============================================================================

#include <iostream>
using namespace std;

int MinInArray(int array[], int start, int end) {
	int middle = (start + end) / 2;
	while (start < end) {
		if (array[end] >= array[middle] && array[middle] >= array[start]) {
			if (array[start] == array[end] && array[end] == array[middle]) { //若这三个值都相同，二分查找失效★
				int min = array[start];
				for (int i = 0; i <= (end - start); i++) { //只能顺序查找(只可能存在于第一次查找)
					if (array[i] < min) {
						min = array[i];
					}
				}
				return min; //找到最小值
				break; //退出循环
			} else {//否则序列为有序序列，二分查找同样失效★
				int min = array[start];
				return min;
				break;
			}
		} else {
			if (array[middle] >= array[start]) {
				start = middle;
			}
			if (array[middle] <= array[end]) {
				end = middle;
			}
		}
		middle = (start + end) / 2;
		if (middle == start) {
			break;
		}
	}
	if (array[start] < array[end]) {
		return array[start];
	} else {
		return array[end];
	}
}
int main() {
	int array[] = { 5, 6, 1, 2, 3, 4 };
//	int array[] = { 5, 6, 1, 1, 1, 1 };
//	int array[] = { 1, 0, 1, 1, 1, 1 };
//	int array[] = { 1, 1, 1, 1, 0, 1 };
//	int array[] = { 3, 3, 3, 1, 2, 3 };
//	int array[] = { 1, 2, 6, 6, 6, 6 };
//	int array[] = { 1, 2, 3, 4, 5, 6 };
	int min = MinInArray(array, 0, 5);
	cout << "旋转数组中最小值为：" << min << endl;
	return 0;
}
