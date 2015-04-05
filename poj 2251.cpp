#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;
struct node1
{
    int c1;
    int x1;
    int y1;
};
queue<node1> q;
char s[45][45][45];
struct node
{
    int num;
    int mark;
}w[45][45][45];
int m,n,k;
int dir[][3]={{0,1,0},{0,-1,0},{0,0,1},{0,0,-1},{1,0,0},{-1,0,0}};
int bfs(int ci,int x,int y)
{
    w[ci][x][y].mark=1;
    node1 e;
    e.c1=ci;
    e.x1=x;
    e.y1=y;
    q.push(e);
    while(!q.empty())
    {
        node1 r=q.front();
        q.pop();
        int step=w[r.c1][r.x1][r.y1].num;
        for(int ll=0;ll<6;ll++)
        {
            int cc,yy,xx;
            cc=r.c1+dir[ll][0];
            xx=r.x1+dir[ll][1];
            yy=r.y1+dir[ll][2];
            if((cc<0||cc>=k||xx<0||xx>=m||yy<0||yy>=n)||w[cc][xx][yy].mark||s[cc][xx][yy]=='#')continue;
            else
            {

                w[cc][xx][yy].mark=1;
                w[cc][xx][yy].num=step+1;
                if(s[cc][xx][yy]=='E')return step+1;
                node1 t;
                t.c1=cc;
                t.x1=xx;
                t.y1=yy;
                q.push(t);
            }
        }
    }
    return 0;
}
int main()
{
    int i,j,l;
    while(cin>>k>>m>>n,k||m||n)
    {

        for(i=0;i<k;i++)
            for(j=0;j<m;j++)
                scanf("%s",s[i][j]);
        int ee=0;
        for(i=0;i<k;i++)
        {
           for(j=0;j<m;j++)
               {
                   for(l=0;l<n;l++)
                   if(s[i][j][l]=='S'){ee=1;break;}
                   if(ee==1)break;
               }
               if(ee==1)break;
        }
        while(!q.empty())q.pop();
        memset(w,0,sizeof(w));
        int tt;
        tt=bfs(i,j,l);
       if(tt>0)printf("Escaped in %d minute(s).\n",tt);
       else printf("Trapped!\n");
    }
    return 0;
}
