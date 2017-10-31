/*************************************************************************
    > File Name: television.h
    > Author: YinJianxiang
    > Mail: YinJianxiang123@gmail.com
    > Created Time: 2017年10月21日 星期六 21时56分30秒
 ************************************************************************/

#ifndef _TELEVISION_H_
#define _TELEVISION_H_

class Telecontroller;

class Television {
	friend class Telecontroller;
public:
	Television(int volume,imt chanel);
private:
	int volume_;
	int chanel_;
};

#endif   //_TELEVISION_H_

