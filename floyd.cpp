/*************************************************************************
    > File Name: floyd.cpp
    > Author: YinJianxiang
    > Mail: YinJianxiang123@gmail.com
    > Created Time: 2017年10月13日 星期五 20时24分47秒
 ************************************************************************/

#include<iostream>
#include<cstdio>

using namespace std;

int e[101][101];
const int inf = 1e7+1;

int main() {
	int m;
	int n;
	//m表示变数,n表示顶点数

	cin >> n >> m;
	
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(i == j) {
				e[i][j] = 0;
			} else {
				e[i][j] = inf;
			}
		}
	}
	
	for(int i = 0;i < m;i++) {
		int t_1,t_2,t_3;
		cin >> t_1 >> t_2 >> t_3;
		e[t_1][t_2] = t_3;	
	}

	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			for(int k = 1;k <= n;k++) {
				if(e[i][k] < inf && e[k][j] < inf && e[i][j] > e[i][k] + e[k][j]) {
					e[i][j] = e[i][k] + e[k][j];
				}
			}
		}
	}
	
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			printf("%2d ",e[i][j]);
		}
		cout << endl;
	}

	return 0;
}





