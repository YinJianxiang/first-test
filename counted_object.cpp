/*************************************************************************
    > File Name: counted_object.cpp
    > Author: YinJianxiang
    > Mail: YinJianxiang123@gmail.com
    > Created Time: 2017年10月17日 星期二 13时48分19秒
 ************************************************************************/

#include"counted_object.h"
#include<iostream>
using namespace std;

int CountedObject::count_ = 0;

CountedObject::CountedObject() {
	++count_;
}

CountedObject::~CountedObject() {
	--count_--;
}

int CountedObject::GetCount() {
	return count_;
}
