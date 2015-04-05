#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#define INF 0xfffffff
using namespace std;
int m,n,w,f;
int s[520][520];
int mark[5200];
struct node
{
    int ma;
    int number;
}path[5200];
bool spfa()
{
    int l;
    queue <int> qq;
    qq.push(1);
    mark[1]=1;
    while(!qq.empty())
    {
        int pp;
        pp=qq.front();
        qq.pop();
        mark[pp]=0;
        path[1].number++;
        for(l=1;l<=n;l++)
        {
            if(path[l].ma>path[pp].ma+s[pp][l])
            {
                path[l].ma=path[pp].ma+s[pp][l];
                if(!mark[l])
                {
                qq.push(l);
                mark[l]=1;
                path[l].number++;
                if(path[l].number>n-1)return false;
                }
            }
        }
    }
    return true;
}
void init()
{
       int v;
        for(v=1;v<=510;v++)
        {
            mark[v]=0;
            path[v].ma=INF;
            path[v].number=0;
            for(int k=1;k<=510;k++)
                s[v][k]=INF;
        }
        return ;
}
int main()
{
    int f;
    int i,j;
    cin>>f;
    while(f--)
    {
        init();
        cin>>n>>m>>w;
        for(i=1;i<=m;i++)
        {
            int x,y;
            cin>>x>>y;
            int uu;
            cin>>uu;
            if(s[x][y]>uu)s[x][y]=uu;
            if(s[y][x]>uu)s[y][x]=uu;
        }
        for(i=1;i<=w;i++)
        {
            int x,y;
            cin>>x>>y;
            int uu;
            cin>>uu;
            if(s[x][y]>-uu)s[x][y]=-uu;
        }
        path[1].ma=0;
        if(!spfa())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
