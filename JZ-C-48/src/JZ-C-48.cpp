//============================================================================
// Name        : JZ-C-48.cpp
// Author      : Laughing_Lz
// Version     :
// Copyright   : All Right Reserved
// Description : 不能被继承的类：用C++设计一个不能被继承的类（如C#里关键字Sealed，Java里关键字final）
//============================================================================

#include <iostream>
using namespace std;

// ====================方法一:把构造函数设为私有函数====================
class SealedClass1 {
public:
	static SealedClass1* GetInstance() {
		return new SealedClass1();
	}

	static void DeleteInstance(SealedClass1* pInstance) {
		delete pInstance;
	}

private:
	SealedClass1() {//private
	}
	~SealedClass1() {//private
	}
};

// 如果试图从SealedClass1继承出新的类型，
// 将会导致编译错误。
/*
 class Try1 : public SealedClass1
 {
 public:
 Try1() {}
 ~Try1() {}
 };
 */

// ====================方法二：利用虚拟继承virtual====================
template<typename T> class MakeSealed {
	friend T;//友元类

private:
	MakeSealed() {
	}
	~MakeSealed() {
	}
};

class SealedClass2: virtual public MakeSealed<SealedClass2> {//
public:
	SealedClass2() {
	}
	~SealedClass2() {
	}
};

// 如果试图从SealedClass1继承出新的类型，
// 将会导致编译错误。
/*
 class Try2 : public SealedClass2
 {
 public:
 Try2() {}
 ~Try2() {}
 };
 */

int main(int argc, char** argv) {
	return 0;
}

