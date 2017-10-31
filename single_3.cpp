/*************************************************************************
    > File Name: single_3.cpp
    > Author: YinJianxiang
    > Mail: YinJianxiang123@gmail.com
    > Created Time: 2017年10月18日 星期三 23时11分23秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Singleton {
public:
	static Singleton &GetInstance() {	
		static Singleton instance_;
		return instance_;
	}
	~Singleton() {
		cout << "destory Singleton..." << endl;
	}
private:
	Singleton(const Singleton &other);
	Singleton &operator=(const Singleton &other);
	Singleton() {
		cout << "create Singleton" << endl;
	}
};

int main() {
	Singleton &s_1 = Singleton::GetInstance();
	Singleton &s_2 = Singleton::GetInstance();
	return 0;
}
