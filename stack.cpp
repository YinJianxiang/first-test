/*************************************************************************
    > File Name: stack.cpp
    > Author: YinJianxiang
    > Mail: YinJianxiang123@gmail.com
    > Created Time: 2017年10月19日 星期四 00时07分05秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Stack {
private:
	struct Link {
		int data_;
		Link *next_;
		Link(int data,Link *next) : data_(data),next_(next) {

		}
	};
public:
	Stack() : head_(0),size_(0) {

	}
	~Stack() {
		Link *tmp;
		while(head_) {
			Link *tmp = head_;
			head_ = head_->next_;
			delete tmp;
		}
	}
	void Push(const int data) {
		Link *node = new Link(data,head_);
		head_ = node;
		++size_;
	}
	bool Empty() {
		return size_ == 0;
	}
	bool Pop(int &data) {
		if(Empty()) {
			return false;
		}
		Link *tmp = head_;
		data = head_->data_;
		head_ = head_->next_;
		delete tmp;
		--size_;
	
		return true;
	}
private:
	Link *head_;
	int size_;
};

int main() {
	Stack stack;
	
	for(int i = 0;i < 5;i++) {
		stack.Push(i);
	}

	while(!stack.Empty()) {
		int t;
		stack.Pop(t);
		cout << t << " ";
    }

	return 0;
}
