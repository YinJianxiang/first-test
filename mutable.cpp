/*************************************************************************
    > File Name: mutable.cpp
    > Author: YinJianxiang
    > Mail: YinJianxiang123@gmail.com
    > Created Time: 2017年10月20日 星期五 22时03分26秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Test {
public:
	Test(int x) : x_(x),outputTimes_(0) {

	}
	int GetX() const {
		cout << "const Get_X" << endl;
		return x_;
	}
	int GetX() {
		cout << "Get_X " << endl;
		return x_;
	}

	void Output() const {
		cout << "x = " << x_ << endl;
		outputTimes_++;
	}

	int GetOutTimes() const {
		return outputTimes_;
	}
private:
	int x_;
	mutable int outputTimes_;
};


int main() {
	const Test t(10);

	t.GetX();

	Test t_2(20);
	t_2.GetX();

	t.Output();
	t.Output();
	cout << t.GetOutTimes() << endl;


	return 0;
}
