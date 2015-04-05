#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#define INF 0xfffffff
using namespace std;
queue <int> qq;
int t;
int i,j,m,n;
struct node
{
    double ma;
    int number;
}path[110];
struct node1
{
    double rate;
    double mon;
}s[110][110];
bool spfa()
{
    int k,l;
    qq.push(t);
    while(!qq.empty())
    {
        int d;
        d=qq.front();
        qq.pop();
        for(l=1;l<=n;l++)
        {
            if(path[l].ma<(path[d].ma-s[d][l].mon)*s[d][l].rate)
            {
                path[l].ma=(path[d].ma-s[d][l].mon)*s[d][l].rate;
                qq.push(l);
                path[l].number++;
                if(path[l].number>n-1)return false;
            }
        }
    }
    return true;
}//这是第一次用spfa算法,居然一次ac,不过这个算法我写的有一点问题,就是,没有判断能再次压栈的数是不是还在栈中.
void init()
{
    int l;
    for(l=0;l<=n;l++)
    {
        path[l].ma=INF;
        path[l].number=0;
    }
}
int main()
{
    double num;
    init();
    cin>>n>>m>>t>>num;
    for(i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        cin>>s[x][y].rate>>s[x][y].mon;
        cin>>s[y][x].rate>>s[y][x].mon;
    }
    path[t].ma=num;
    if(!spfa())cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
