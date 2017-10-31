/*************************************************************************
    > File Name: dijkstra.cpp
    > Author: YinJianxiang
    > Mail: YinJianxiang123@gmail.com
    > Created Time: 2017年10月13日 星期五 20时38分05秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int inf = 1e7 + 1;
int e[1001][1001];
int dis[1001];
int book[1001];

int main() {
	int n;
	int m;
	//n表示顶点的个数,m表示边的条数
	
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(i == j) {
				e[i][j] = 0;
			} else {
				e[i][j] = inf;
			}
		}
	}
	
	memset(book,0,sizeof(book));
	book[1] = 1;

	for(int i = 1;i <= n;i++) {
		dis[i] = e[i][j];
	}
	
	int u;
	for(int i = 1;i < n;i++) {
		int min;
		min = inf;
		
		for(int j = 1;j <= n;j++) {
			if(book[j] == 0 && dis[j] < min) {
				min = dis[j];
				u = j;		
			}
		}
		book[u] = 1;
		for(int v = 1;v <= n;v++) {
			if(e[u][v] < inf) {
				if(dis[v] > dis[u] + e[u][v]) {
					dis[v] = dis[u] + e[u][v];
				}
			}
		}
	}

	for(int i = 1;i <= n;i++) {
		printf("%d ",dis[i]);
	}

	return 0;
}

