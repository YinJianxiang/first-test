/*************************************************************************
	> File Name: string.cpp
	> Author: YinJianxiang
	> Mail: YinJianxiang123@gmail.com
	> Created Time: 2017年10月23日 星期一 23时25分21秒
 ************************************************************************/

#include"./string.h"
#include<iostream>
#include<cstring>
using namespace std;

String::String(const char *str) {
    str_ = AllocAndCopy(str);
}

String::String(const String &other) {
    str_ = AllocAndCopy(other.str_);
}




char String::AllocAndCopy(const char *str) {
    int len = strlen(str);
    char *newstr = new char[len+1];
    memset(newstr,0,len);
    strcpy(newstr,str);

    return newstr;
}

void String::Display() {
    cout << str_ << endl;
}

