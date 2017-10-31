/*************************************************************************
    > File Name: saolei.cpp
    > Author: YinJianxiang
    > Mail: YinJianxiang123@gmail.com
    > Created Time: 2017年10月22日 星期日 23时48分46秒
 ************************************************************************/

#include <bits/stdc++.h>
#include <cstring>
#define UNREVAL -1
#define FLAGED 10
using namespace std;
const int N = 10;
int g[N+1][N+1];
int o[N+1][N+1];
int surf[N+1][N+1];
int score;
int gcd(int a,int b)
{
    int i=max(a,b);
    while(i>0)
    {
         if(a%i==0&&b%i==0)
         {
             break;
         }
         i--;
    }
    return i;
}
struct Node
{
    int x,y;
};
bool check(int x,int y)
{
    if(x>N||y>N||x<=0||y<=0)
    {
        return 0;
    }
    return 1;
}
int dx[8] = {0,1,0,-1,1,1,-1,-1};
int dy[8] = {1,0,-1,0,-1,1,1,-1};
void generate_new_map(int num)
{
    int x=0,y=0;
    memset(g,0,sizeof(g));
    memset(o,0,sizeof(o));
    memset(surf,0,sizeof(surf));
    for(int i=0; i<num; i++)
    {
        x = 1+rand()%N;
        y = 1+rand()%N;
        //cout<<x<<" "<<y<<endl;
        if(g[x][y] == -1)
        {
            i--;
            continue;
        }
        g[x][y] = -1;
    }
    x=0;
    y=0;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(g[i][j] == -1) continue;
            for(int k=0; k<8; k++)
            {
                x = i+dx[k];
                y = j+dy[k];
                if(check(x,y)&&g[x][y] == -1)
                {
                    g[i][j] += 1;
                }
            }

        }
    }
}
void show_map()
{
    cout<<"x  ";
    for(int i=1; i<=N; i++)
    {
        cout<<i;
    }
    cout<<endl;
    for(int i=1; i<=N; i++)
    {
        printf("%-3d",i);
        for(int j=1; j<=N; j++)
        {
            if(o[i][j] == 0)
            {
                cout<<'*';
                surf[i][j] = UNREVAL;
            }
            else if (o[i][j] == 1)
            {
                //cout<<'.';
                if(g[i][j] == 0)
                {
                    cout<<".";
                    surf[i][j] = 0;
                }
                else
                {
                    cout<<g[i][j];
                    surf[i][j] = g[i][j];
                }
            }
            else
            {
                surf[i][j] = FLAGED;
                cout<<'T';
            }

        }
        cout<<endl;
    }
}
void expand(int x,int y)
{
    Node a,next;
    a.x = x;
    a.y = y;
    int vis[N+1][N+1];
    memset(vis,0,sizeof(vis));
    vis[x][y] =1;
    queue<Node> q;
    q.push(a);
    while(!q.empty())
    {
        a = q.front();
        q.pop();
        for(int i=0; i<8; i++)
        {
            int nx = a.x+dx[i];
            int ny = a.y + dy[i];
            if(check(nx,ny)&&g[nx][ny]!= -1&&vis[nx][ny] == 0)
            {
                //cout<<nx<<" "<<ny<<endl;
                o[nx][ny] = 1;
                if(g[nx][ny] >= 1)
                {
                    continue;
                }
                else
                {
                    vis[nx][ny] = 1;
                    next.x = nx;
                    next.y = ny;
                    q.push(next);
                }

            }
        }
    }
}
int reveal(int x,int y)
{
    if(g[x][y] == -1)
    {
        return 0;
    }
    else
    {
        o[x][y] = 1;
        if(g[x][y] == 0)
        {
            expand(x,y);
        }
        return 1;
    }

}
void show_mines()
{
    for(int i=1; i<=N; i++)
    {
        for(int j =1; j<=N; j++)
        {
            cout<<g[i][j]<<"  ";
        }
        cout<<endl;
    }
}
void flag(int x,int y)
{
    o[x][y] = 2;
    if(g[x][y] == -1)
    {
        score++;
    }
}
void AI(int x,int y)
{
    int cnt = 0;
    for(int i=0; i<8; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(check(xx,yy)&&surf[xx][yy] == UNREVAL)
        {
            cnt++;
        }
    }
    int num = surf[x][y];
    if(num<cnt)
    {
        for(int i=0; i<8; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(check(xx,yy)&&surf[xx][yy] == UNREVAL)
            {
                reveal(xx,yy);
            }
        }
    }
    else
    {
         for(int i=0; i<8; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(check(xx,yy)&&surf[xx][yy] == UNREVAL)
            {
                flag(xx,yy);
            }
        }

    }
}
int main()
{
    cout<<gcd(1,6);
    srand(time(0));
    generate_new_map(10);
    show_map();
    //show_mines();
    int x,y,op;
    score = 0;
    int left = 10;
    while(cin>>op)
    {
        if(left == 0)
        {
            cout<<"win!"<<endl;
        }
        if(op == 0) break;
        cin>>x>>y;
        if(op ==1)
        {
            if(!reveal(x,y))
            {
                cout<<"gameover"<<endl;
                cout<<"score: "<<score<<endl;
                break;
            }
            else
            {
                cout<<"no mines"<<endl;
                show_map();
            }

        }
        if(op == 2)
        {
            flag(x,y);
            cout<<"flag!"<<endl;
            show_map();
        }
        if(op == 3)
        {
            AI(x,y);
            show_map();
        }
    }
    return 0;
}
