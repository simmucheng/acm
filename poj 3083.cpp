#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
char s[50][50];
int x,y;
int dir[][2]={0,1,-1,0,0,-1,1,0};
struct node
{
    int x1;
    int y1;
    int di;
};
queue<node> q;
struct node1
{
    int mm;
    int step;
}mark[50][50];
int num1,num2;
int end1,end2;
void dfs1(int xx,int yy,int d)
{
    num1++;
    if(s[xx][yy]=='E'){end1=num1;return ;}
     for(int l=1;l<5;l++)
     {
         int x3=xx+dir[(d+l)%4][0];
         int y3=yy+dir[(d+l)%4][1];
         if(x3<0||x3>=x||y3<0||y3>=y||s[x3][y3]=='#')continue;
         else
             {
                 cout<<x3<<' '<<y3<<endl;
                 dfs1(x3,y3,(d+l)%4);
             }
     }
}//left
void dfs2(int xx,int yy,int d)
{
    num2++;
    if(s[xx][yy]=='E'){end2=num2;return ;}
    for(int l=1;l<5;l++)
    {
        int x3=xx+dir[(((d-l)%4)+4)%4][0];;
        int y3=yy+dir[(((d-l)%4)+4)%4][1];
        if(x3<0||x3>=x||y3<0||y3>=y||s[x3][y3]=='#')continue;
        else
        dfs2(x3,y3,(((d-l)%4)+4)%4);
    }
}//right
int bfs(int xx,int yy)
{
      node r;
      r.x1=xx;
      r.y1=yy;
      mark[xx][yy].step=1;
      mark[xx][yy].mm=1;
      q.push(r);
      while(!q.empty())
      {
          node e=q.front();
          q.pop();
          for(int l=0;l<4;l++)
          {
              node t;
              t.x1=e.x1+dir[l][0];
              t.y1=e.y1+dir[l][1];
              if(t.x1<0||t.x1>=x||t.y1<0||t.y1>=y||s[t.x1][t.y1]=='#'||mark[t.x1][t.y1].mm==1)continue;
              else
              {
                  mark[t.x1][t.y1].step=mark[e.x1][e.y1].step+1;
                  if(s[t.x1][t.y1]=='E')return mark[t.x1][t.y1].step;
                  mark[t.x1][t.y1].mm=1;
                  q.push(t);
              }
          }
      }
}
int main()
{
    int i,j,m,n;
    scanf("%d",&n);
    int ii,jj;
    while(n--)
    {
        num1=0;
        num2=0;
        while(!q.empty())q.pop();
        memset(mark,0,sizeof(mark));
        scanf("%d%d",&y,&x);
        for(i=0;i<x;i++)
        {
            getchar();
            for(j=0;j<y;j++)
            {
            scanf("%c",&s[i][j]);
            if(s[i][j]=='S'){ii=i;jj=j;}
            }
        }
        int pp;
        if(ii==0)pp=2;
        else if(ii==x-1)pp=0;
        else if(jj==0)pp=3;
        else if(jj==y-1)pp=1;
        cout<<"pp = "<<pp<<endl;
        dfs1(ii,jj,pp);
        cout<<end1<<endl;
       // cout<<"rrrrr"<<endl;
        //dfs2(ii,jj,pp);
        //cout<<end1<<' '<<end2<<' '<<bfs(ii,jj)<<endl;
        /*for(i=0;i<x;i++)
        {
            for(j=0;j<y;j++)
            cout<<mark[i][j].step;
            cout<<endl;
        }*/
    }
    return 0;
}
