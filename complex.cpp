/*************************************************************************
	> File Name: complex.cpp
	> Author: YinJianxiang
	> Mail: YinJianxiang123@gmail.com
	> Created Time: 2017年10月23日 星期一 19时42分34秒
 ************************************************************************/

#include "./complex.h"
#include <iostream>

using namespace std;

Complex::Complex(int real,int imag):real_(real) ,imag_(imag) {
    
}

Complex::~Complex() {
    cout << "destory" << endl;
}

Complex::Complex &add(const Complex &other) {
    real_ += other.real;
    imag_ += other.imag;

    return *this;
}

Complex::Complex operator+(const Complex &other) {
    int r = real_ + other.real_;
    int i = imag + other.imag_;

    return Complex(r,l);
}

Complex operator+(const Complex &one,const Complex &another) {
    int r = one.real_ + other.real_;
    int i = another.imag_ + another.imag_;
    
    return Comlex(r,i);
}


