/*************************************************************************
    > File Name: union_find.cpp
    > Author: YinJianxiang
    > Mail: YinJianxiang123@gmail.com
    > Created Time: 2017年10月16日 星期一 23时53分16秒
 ************************************************************************/

#include<iostream>
#include<cstdio>

using namespace std;

int f[1000] = {
	0
};

int n;
int k;
int m;
int sum = 0;

void init() {
	for(int i = 1;i <= n;i++) {
		f[i] = i;
	}
}


//相当于找父
int getf(int v) {
	if(f[v] == v) {
		return v;
	} else {
		f[v] = getf(f[v]);
		
		return f[v];
	}
}

//合并集合
void merge(int v,int u) {
	int t_1;
	int t_2;
	
	t_1 = getf(v);
	t_2 = getf(u);

	if(t_1 != t_2) {
		f[t_2] = t_1;
		//靠左原则
		//路径压缩
	}
}

int main() {
	int x;
	int y;

	cin >> n >> m;
	
	init();
	for(int i = 1;i <= m;i++) {
		cin >> x >> y;
		merge(x,y);
	}

	for(int i = 1;i <= m;i++) {
		if(f[i] == i) {
			sum++;
		}
	}

	cout << sum << endl;

	return 0;
}



