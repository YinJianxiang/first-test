/*************************************************************************
	> File Name: sortAndfind.cpp
	> Author: YinJianxiang
	> Mail: YinJianxiang123@gmail.com
	> Created Time: 2017年10月25日 星期三 20时25分32秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int maxn = 10001;

int main() {
    int n;
    int p;
    int a[maxn];

    while(cin >> n >> p && n) {
        memset(a,0,sizeof(a));
        for(int i = 0;i < n;i++) {
            cin >> a[i];
        }
        sort(a,a+n);
        while(p--) {
            int x;
            cin >> x;
            int p = lower_bound(a,a-n,x) - a;
            if(a[p] == x) {
                cout << p << endl;
            } else {
                cout << "-1" << endl;
            }
        }

    }
    return 0;
}

