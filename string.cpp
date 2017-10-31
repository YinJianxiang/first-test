/*************************************************************************
> File Name: string.cpp
> Author: YinJianxiang
> Mail: YinJianxiang123@gmail.com
> Created Time: 2017年10月24日 星期二 15时32分01秒
************************************************************************/

#include<iostream>
#include<cstring>
#include<string>

using namespace std;

string s;

int find_tar(string str) {
    int x_1 = s.find(str,0);
    if(x_1 == -1) { 
        return 0;
    }
    if (x_1 + 1 >= (int)s.size()) { 
        return 1;
    }
    int x_2 = s.find(str,x_1+1);
    if (x_2 != -1) { 
        return 2;
    } else { 
        return 1;
    }
}


int main() {
const string freinds[] = {"Danil","Olya","Slava","Ann","Nikita"};
    int num[5];

    memset(num,0,sizeof(num));

    cin >> s;

    int cnt = 0;
   
    for(int i = 0;i < 5;i++) {
        num[i] += find_tar(freinds[i]);
    }

    for(int i = 0;i < 5;i++) {
        cnt += num[i];
    }

    if(cnt == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

