#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define INF 0xfffffff
using namespace std;
struct node
{
    int number;
    int c;
}s[60][60];
int ww[60][60];
struct node1
{
    int x1;
    int y1;
}mark[3800];
queue <node1> q;
int distence[60][60];
int l,num,x,y,dd;
struct node2
{
    int ma;
    int mar;
}path[3800];
int direction[][2]={1,0,-1,0,0,1,0,-1};
void bfs(int x2,int y2,int ci)
{
    int x3,y3;
   while(!q.empty())
   {
       node1 ee=q.top();
       q.pop();
       for(int k=0;k<4;k++)
       {
           xx=ee.x1+direction[k][0];
           yy=ee.y1+direction[k][1];
           if(xx<0||xx>y-1||yy<0||yy>x-1||s[xx][yy].c=='#')continue;
           else
           {
               node1 rr;
               rr.x1=xx;
               rr.y1=yy;
               q.push(rr);
           }
       }
   }
    return ;
}
void prim()
{
   path[1].ma=0;
   int aa=1;
   int mm=0;
   while(aa)
   {
       aa=0;
       num+=mm;
       cout<<mm<<endl;
       mm=INF;
     for(int k=1;k<l;k++)
     {
       if(path[k].ma<mm&&!path[k].mar)
       {
           mm=path[k].ma;
           aa=k;
       }
     }
     path[aa].mar=1;
     for(int k=1;k<l;k++)
     {
         if(path[k].ma>distence[aa][k]&&!path[k].mar)
         path[k].ma=distence[aa][k];
     }
   }
   return ;
}
void init()
{
    for(int k=1;k<l;k++)
    {
        path[k].ma=INF;
        path[k].mar=0;
    }
    for(int k=0;k<=y;k++)
    {
        for(int u=0;u<=x;u++)
        distence[k][u]=INF;
    }
    for(int k=0;k<=52;k++)
    distence[k][k]=0;
}
int main()
{
    int i,j,m,n;
    cin>>n;
    while(n--)
    {
        num=0;
        l=1;
        cin>>x>>y;
        for(i=0;i<y;i++)
        {
            getchar();
            for(j=0;j<x;j++)
            scanf("%c",&s[i][j].c);
        }
        for(i=0;i<y;i++)
        {
            for(j=0;j<x;j++)
            {
                  if(s[i][j].c=='A'||s[i][j].c=='S')
                    {
                      s[i][j].number=l++;
                      mark[s[i][j].number].x1=i;
                      mark[s[i][j].number].y1=j;
                    }
            }
        }
        init();
        for(i=1;i<l;i++)
        {
            memset(ww,0,sizeof(ww));
            dd=i;
            dfs(mark[i].x1,mark[i].y1,0);
        }
       /* for(i=1;i<l;i++)
        {
            for(j=1;j<l;j++)
            cout<<i<<' '<<j<<' '<<distence[i][j]<<endl;
        }*/
        prim();
        cout<<num<<endl;
    }
    return 0;
}
