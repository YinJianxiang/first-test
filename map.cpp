/*************************************************************************
	> File Name: map.cpp
	> Author: YinJianxiang
	> Mail: YinJianxiang123@gmail.com
	> Created Time: 2017年10月24日 星期二 19时29分18秒
 ************************************************************************/

#include<iostream>
#include<map>

using namespace std;

map<string,int> mapSet;

int main() {
    mapSet["aaa"] = 100;
    mapSet["bbb"] = 200;
    mapSet["ccc"] = 300;
    //重复则为最后一次修改的值

    //重复则为无效的操作
    mapSet.insert(map<string,int>::value_type("ccc",444));
    mapSet.insert(pair<string,int>("ddd",444));
    mapSet.insert(make_pair("eee",555));

    map<string,int>::iterator it;
    for(it = mapSet.begin();it != mapSet.end();++it) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}

