//============================================================================
// Name        : JZ-C-35.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 第一个只出现一次的字符
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

char FirstNotRepeatingChar(char* pString)
{
    if(pString == NULL)
        return '\0';

    const int tableSize = 256;
    unsigned int hashTable[tableSize];//此处定义的哈希表中，key为字符，字符的ASCII码值为数组下标，value为字符出现次数，
    for(unsigned int i = 0; i<tableSize; ++ i)
        hashTable[i] = 0;

    char* pHashKey = pString;
    while(*(pHashKey) != '\0')//第一次遍历字符串
        hashTable[*(pHashKey++)] ++;//使哈希表中对应字符(数组下标为字符ASCII码值)的出现次数加1

    pHashKey = pString;//再将指针重新指向pString
    while(*pHashKey != '\0')
    {
        if(hashTable[*pHashKey] == 1)//遇到第一个value为1的立即跳出循环，返回
            return *pHashKey;

        pHashKey++;
    }

    return '\0';
}

// ====================测试代码====================
void Test(char* pString, char expected)
{
    if(FirstNotRepeatingChar(pString) == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char** argv)
{
    // 常规输入测试，存在只出现一次的字符
    Test("google", 'l');

    // 常规输入测试，不存在只出现一次的字符
    Test("aabccdbd", '\0');

    // 常规输入测试，所有字符都只出现一次
    Test("abcdefg", 'a');

    // 鲁棒性测试，输入NULL
    Test(NULL, '\0');

    return 0;
}

