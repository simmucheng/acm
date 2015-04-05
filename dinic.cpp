#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#include<vector>
#include<queue>
using namespace std;
struct node
{
    int aa;
    int bb;
    int cc;
}s[410];
int step[410];
int city[410][410];
int fa[410];
int bfs(int sta,int en,int number)
{
    queue<int>q;
    q.push(sta);
    memset(step,0,sizeof(step));
    memset(fa,-1,sizeof(fa));
    fa[sta]=0;
    while(!q.empty())
    {
        int tt=q.front();
        q.pop();
        for(int ii=0;ii<number;ii++)
        {
            if(city[tt][ii]>0&&fa[ii]==-1)
            {
                fa[ii]=tt;
                step[ii]=step[tt]+1;
                q.push(ii);
            }
        }
    }
    if(fa[en]!=-1)return 1;
    else return 0;
}
int find(int sta,int en,int number,int low)
{
    int a;
    if(sta==en)return low;
    for(int ii=0;ii<number;ii++)
    {
        if(city[sta][ii]>0&&(step[ii]==step[sta]+1)&&(a=find(ii,en,number,min(low,city[sta][ii]))))
        {
            city[sta][ii]-=a;
            city[ii][sta]+=a;
            return a;
        }
    }
    return 0;
}
int dinic(int sta,int en,int number)
{
     int sum=0;
     while(bfs(sta,en,number))
     {
         int ss;
         while(ss=find(sta,en,number,INT_MAX))sum+=ss;
     }
     return sum;
}
int main()
{
    int i,j,m,n;
    int start,end,num;
    while(scanf("%d%d",&start,&end)!=EOF)
    {
        vector<int>value;
        value.push_back(start);
        value.push_back(end);
        scanf("%d",&num);
        for(i=0;i<num;i++)
        {
            scanf("%d%d%d",&s[i].aa,&s[i].bb,&s[i].cc);
            value.push_back(s[i].aa);
            value.push_back(s[i].bb);
        }
        std::sort(value.begin(),value.end());
        value.erase(std::unique(value.begin(),value.end()),value.end());
        #define FIND(v)(lower_bound(value.begin(),value.end(),v)-value.begin())
        memset(city,0,sizeof(city));
        for(i=0;i<num;i++)
        {
            city[FIND(s[i].aa)][FIND(s[i].bb)]+=s[i].cc;
        }
        printf("%d\n",dinic(FIND(start),FIND(end),(int)value.size()));
        #undef FIND
    }
    return 0;
}
