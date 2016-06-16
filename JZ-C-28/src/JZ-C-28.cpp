//============================================================================
// Name        : JZ-C-28.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 字符串的排列
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

void Permutation(char* pStr, char* pBegin);
void Permutation(char* pStr) {
	if (pStr == NULL) {
		return;
	}
	Permutation(pStr, pStr);
}
void Permutation(char* pStr, char* pBegin) {
	if (*pBegin == '\0') {
		printf("%s\n", pStr);
	} else {
		for (char* pCh = pBegin; *pCh != '\0'; pCh++) {
			char temp = *pBegin;
			*pBegin = *pCh;
			*pCh = temp;

			Permutation(pStr, pBegin + 1);

			temp = *pBegin;
			*pBegin = *pCh;
			*pCh = temp;
		}
	}

}
// ====================测试代码====================
void Test(char* pStr) {
	if (pStr == NULL)
		printf("Test for NULL begins:\n");
	else
		printf("Test for %s begins:\n", pStr);

	Permutation(pStr);

	printf("\n");
}

int main(int argc, char** argv) {
	Test(NULL);

	char string1[] = "";
	Test(string1);

	char string2[] = "a";
	Test(string2);

	char string3[] = "ab";
	Test(string3);

	char string4[] = "abc";
	Test(string4);

	return 0;
}

