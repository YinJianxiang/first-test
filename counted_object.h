/*************************************************************************
    > File Name: counted_object.h
    > Author: YinJianxiang
    > Mail: YinJianxiang123@gmail.com
    > Created Time: 2017年10月17日 星期二 13时44分11秒
 ************************************************************************/

#ifndef _COUNTED_OBJECT_H
#define _COUNTED_OBJECT_H

class CountedObject {
public:
	CountObject();
	~CountObject();
public:
	static int GetCount();
private:
	static int count_;
}


#endif
