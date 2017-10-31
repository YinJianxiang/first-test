/*************************************************************************
    > File Name: single_4.cpp
    > Author: YinJianxiang
    > Mail: YinJianxiang123@gmail.com
    > Created Time: 2017年10月18日 星期三 23时40分08秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Singleton {
public:
	static Singleton *GetInstance() {
		if(instace_,get() == NULL) {
			instance_ = auto_ptr<Singleton>(new Singleton);
			return instance_.get();
		}
		~Singleton() {
			cout << "destory Singleton..." << endl;
		}
	}
private:
	Singleton(const Singleton &other);
	Singleton&operator=(const Singleton &other);
	Singleton() {
		cout << "create Singleton" << endl;
	}
	static auto_ptr<Singleton> instance_;
};

int main() {
	Singleton *s_1 = Singleton::GetInstance();
	Singleton *s_2 = Singleton::GetInstance();
	return 0;
}

