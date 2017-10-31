/*************************************************************************
    > File Name: single_2.cpp
    > Author: YinJianxiang
    > Mail: YinJianxiang123@gmail.com
    > Created Time: 2017年10月17日 星期二 15时58分10秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Singleton {
public:
	static Singleton *GetInstance() {
		if(instance_ == NULL) {
			instance_ = new Singleton;
		}
		return instance_;
	}
	~Singleton() {
		cout << "destory ..." << endl;
	}

	class Garbo {
		public:
			~Garbo() {
				if(Singleton::instance_ != NULL) {
					delete instance_;
				}
			}
	};
private:
	Singleton(const Singleton &other);
	Singleton &operator=(const Singleton &other);
	Singleton() {
		cout << "create Singleton..." << endl;
	}
	static Singleton *instance_;

	static Garbo *garbo_;
};

Singleton::Garbo garbo_;
Singleton *Singleton::instance_;

int main() {
	Singleton *s_1 = Singleton::GetInstance();
	Singleton *s_2 = Singleton::GetInstance();

	return 0;
}

