/*************************************************************************
	> File Name: string.h
	> Author: YinJianxiang
	> Mail: YinJianxiang123@gmail.com
	> Created Time: 2017年10月23日 星期一 22时19分23秒
 ************************************************************************/

#ifndef _STRING_H
#define _STRING_H

class String {
public:
    explicit String(const char *str = "");
    String(const String &other);
    String &operator=(const String &other);
    String &operator=(const char *str);

    bool operator!() const;
    ~String();

    void Display() const;
private:
    char *AllocAndCopy(const char *str);
    char *str_;
};

#endif //_STRING_H
