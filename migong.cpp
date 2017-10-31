/*************************************************************************
	> File Name: migong.cpp
	> Author: YinJianxiang
	> Mail: YinJianxiang123@gmail.com
	> Created Time: 2017年10月24日 星期二 14时36分23秒
 ************************************************************************/

#include<iostream>
using namespace std;

const int maxn = 10001;

typedef struct node {
    int x_;
    int y_;
    int dir_;

    struct node(int x,int y,int dir) : x(x_),y(y_),dir(dir_);
} node;

int m;
int n;

vector<node> vec;
char map[maxn][maxn];

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

bool check(int x,int y) { 
    if(x <= 0 || x > m || y <= 0 || y > n || map[x][y] == '1') {
        return false;
    }
    return true;
}

bool dfs(int x,int y) {
    if(x == m && y == n) {
        return;
    }
    
    for(int i = 0;i < 4;i++) {
        int tX = x + dx[i];
        int tY = y = dy[i];
        if(check(tx,ty) = false) {
            continue;
        }
        bool res = dfs(tX,tY);
        if(res) {
            vec.push_back(node(tX,tY,dir));
            return true;
        }
    }
    
}


int main() {
    cin >> m >> n;

    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> map[i][j];
        }
    }
    
    dfs(1,1);

    for(vec.type_size i = vec.size() - 1;i != -1;i--) {
        cout << vec[i].x_ << " " << vec[i].y_ << " " << vec[i].dir_ << endl; 
    }

    return 0;
}

