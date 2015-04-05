#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
    int sta;
    int mark;
};
vector<node>q[10010];
int pre[10010];
int len[100010];
int bridge[100010];
int ee;
int ti;
void add_edge(int xx,int yy,int id)
{
    int judge=0;
    for(int ii=0;ii<q[xx].size();ii++)
    {
        if(q[xx][ii].sta==yy)
        {
            judge=q[xx][ii].mark;
            break;
        }
    }
    if(judge!=0)len[judge]=1;
    else
    {
        node uu;
        uu.mark=id;
        uu.sta=yy;
        q[xx].push_back(uu);
        uu.sta=xx;
        q[yy].push_back(uu);
    }
    return ;
}
int tarjan(int son,int fa)
{
    int lowu=pre[son]=++ti;
    for(int ii=0;ii<q[son].size();ii++)
    {
        int uu=q[son][ii].sta;
        if(!pre[uu])
        {
            int lowv=tarjan(uu,son);
            lowu=min(lowv,lowu);
            if(pre[son]<lowv&&!len[q[son][ii].mark])
            {
                bridge[ee++]=q[son][ii].mark;
            }
        }
        else if(uu!=fa)
              lowu=min(lowu,pre[uu]);
             // cout<<"son = "<<son<<' '<<"uu = "<<uu<<' '<<pre[son]<<' '<<lowu<<endl;
    }
    return lowu;
}
void init()
{
    for(int ii=1;ii<=10000;ii++)
        q[ii].clear();
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        init();
        ti=0;
        ee=0;
        memset(len,0,sizeof(len));
        memset(pre,0,sizeof(pre));
         int a,b;
         scanf("%d%d",&a,&b);
         for(int ii=1;ii<=b;ii++)
         {
             int x,y;
             scanf("%d%d",&x,&y);
             add_edge(x,y,ii);
         }
         tarjan(1,-1);
         printf("%d\n",ee);
         sort(bridge,bridge+ee);
         if(ee>0)
        {
             printf("%d",bridge[0]);
             for(int ii=1;ii<ee;ii++)
             printf(" %d",bridge[ii]);
             printf("\n");
        }
        if(n!=0)printf("\n");
    }
    return 0;
}
/*
son = 2  2 1
son = 3  3 2
son = 3  3 1
son = 6  4 3
son = 3  3 1
son = 2  2 1
son = 4  5 2
son = 5  6 5
son = 4  5 2
son = 2  2 1
son = 1  1 1
son = 1  1 1
*/
