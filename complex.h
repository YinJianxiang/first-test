/*************************************************************************
    > File Name: complex.h
    > Author: YinJianxiang
    > Mail: YinJianxiang123@gmail.com
    > Created Time: 2017年10月23日 星期一 19时24分33秒
 ************************************************************************/

#ifndef _COMLPEX_H_
#define _COMPLEX_H_

class Complex {
public:
	Complex(int real,int imag);
	~Complex();
	Complex &add(const Complex &other);
	Complex operator+(const Complex &other);
	friend Complex operator+(const Complex &one,const Complex &other);
private:
	int real_;
	int imag_;
};



#endif   //_COMPLEX_H_
