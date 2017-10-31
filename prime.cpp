/*************************************************************************
	> File Name: prime.cpp
	> Author: YinJianxiang
	> Mail: YinJianxiang123@gmail.com
	> Created Time: 2017年10月23日 星期一 21时52分58秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn = 1e5+7;
const int inf = 1e7+7;

int main() {
    int m;//边的条数
    int n;//顶点个数
    int e[maxn][maxn];
    int book[maxn];
    int dis[maxn];

    int count = 0;//添加的顶点的个数
    int sum = 0;//最小生成树的和值

    memset(book,0,sizeof(book));

    cin >> n >> m;

    //初始化
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(i == j) {
                e[i][j] = 0; 
            } else {
                e[i][j] = inf;
            }
        }
    }

    //读取边
    for(int i = 1;i <= m;i++) {
        int t_1;
        int t_2;
        int t_3;
        cin >> t_1 >> t_2 >> t_3;
        e[t_1][t_2] = t_3;
        e[t_2][t_1] = t_3;
    }
    
    //初始化dis
    for(int i = 1;i <= n;i++) {
        dis[i] = e[1][i];
    }
    
    
    book[1] = 1;
    count++;
    
    while(count < n) {
        int t = inf;
        for(int i = 1;i <= n;i++) {
            int j;
            if(book[i] == 0 && dis[i] < t) {
                t = dis[i];
                j = i;
            }
            book[j] = 1;
            count++;
            sum += dis[i];

            for(int k = 1;k <= n;k++) {
                if(book[k] == 0 && dis[k] > dis[j][k]) {
                    dis[k] = e[j][k];
                }
            }
        }
    }

    cout << sum << endl;

    return 0;
}



