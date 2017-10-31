/*************************************************************************
    > File Name: expand_gcd.cpp
    > Author: YinJianxiang
    > Mail: YinJianxiang123@gmail.com
    > Created Time: 2017年10月17日 星期二 14时40分40秒
 ************************************************************************/

#include<iostream>
using namespace std;

int ex_gcd(int a,int b,int &x,int &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int ans = ex_gcd(b,a%b,x,y);
	int temp = x;
	x = y;
	y = temp - a/b * y;

	return abs;
}

int main() {
	int a;
	int b;
	int c;
	int d;

	cin >> a >> b;
	cin >> c >> d;
	int &x = a;
	int &y = c;

	cout << ex_gcd(b,d,x,y) << endl;

	return 0;
}
