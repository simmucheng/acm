#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
int a,b,c;
struct node
{
    int a1;
    int b1;
    int num;
};
queue<node> q;
struct node1
{
    int mark;
    int prex;
    int prey;
    int kind;
}mm[110][110];
void dir(int u)
{
    if(u==0)cout<<"DROP(1)"<<endl;
    else if(u==1)cout<<"DROP(2)"<<endl;
    else if(u==2)cout<<"FILL(1)"<<endl;
    else if(u==3)cout<<"FILL(2)"<<endl;
    else if(u==4)cout<<"POUR(2,1)"<<endl;
    else if(u==5)cout<<"POUR(1,2)"<<endl;
}
int dx,dy;
int bfs(int aa,int bb)
{
     node e;
     e.a1=0;
     e.b1=0;
     e.num=0;
     q.push(e);
     int ll=0;
     while(!q.empty())
     {
         node dd=q.front();
         q.pop();
         if(dd.a1==c||dd.b1==c){dx=dd.a1;dy=dd.b1;return dd.num;}
         node rr;
         rr.a1=0;
         rr.b1=dd.b1;
         if(!mm[rr.a1][rr.b1].mark)
         {
         mm[rr.a1][rr.b1].mark=1;
         mm[rr.a1][rr.b1].prex=dd.a1;
         mm[rr.a1][rr.b1].prey=dd.b1;
         mm[rr.a1][rr.b1].kind=0;
         rr.num=dd.num+1;
         q.push(rr);
         }//drop a
         rr.a1=dd.a1;
         rr.b1=0;
         if(!mm[rr.a1][rr.b1].mark)
         {
         mm[rr.a1][rr.b1].mark=1;
         mm[rr.a1][rr.b1].prex=dd.a1;
         mm[rr.a1][rr.b1].prey=dd.b1;
         mm[rr.a1][rr.b1].kind=1;
         rr.num=dd.num+1;
         q.push(rr);
         }//drop b
         rr.a1=aa;
         rr.b1=dd.b1;
         if(!mm[rr.a1][rr.b1].mark)
         {
         mm[rr.a1][rr.b1].mark=1;
         mm[rr.a1][rr.b1].prex=dd.a1;
         mm[rr.a1][rr.b1].prey=dd.b1;
         mm[rr.a1][rr.b1].kind=2;
         rr.num=dd.num+1;
         q.push(rr);
         }//fill a
         rr.a1=dd.a1;
         rr.b1=bb;
         if(!mm[rr.a1][rr.b1].mark)
         {
         mm[rr.a1][rr.b1].mark=1;
         mm[rr.a1][rr.b1].prex=dd.a1;
         mm[rr.a1][rr.b1].prey=dd.b1;
         mm[rr.a1][rr.b1].kind=3;
         rr.num=dd.num+1;
         q.push(rr);
         }//fill b
         if(dd.a1+dd.b1>=aa)
         {
         rr.a1=aa;
         rr.b1=dd.a1+dd.b1-aa;
         }
         else
         {
             rr.a1=dd.a1+dd.b1;
             rr.b1=0;
         }
         if(!mm[rr.a1][rr.b1].mark)
         {
         mm[rr.a1][rr.b1].mark=1;
         mm[rr.a1][rr.b1].prex=dd.a1;
         mm[rr.a1][rr.b1].prey=dd.b1;
         mm[rr.a1][rr.b1].kind=4;
         rr.num=dd.num+1;
         q.push(rr);
         }//b - > a
         if(dd.a1+dd.b1>=bb)
         {
             rr.b1=bb;
             rr.a1=dd.a1+dd.b1-bb;
         }
         else
         {
             rr.b1=dd.a1+dd.b1;
             rr.a1=0;
         }
         if(!mm[rr.a1][rr.b1].mark)
         {
         mm[rr.a1][rr.b1].mark=1;
         mm[rr.a1][rr.b1].prex=dd.a1;
         mm[rr.a1][rr.b1].prey=dd.b1;
         mm[rr.a1][rr.b1].kind=5;
         rr.num=dd.num+1;
         q.push(rr);
         }//a - > b
     }
     return -1;
}
int ee[10000];
int main()
{
    int i,j,m,n;
    scanf("%d%d%d",&a,&b,&c);
    //if(a<b)swap(a,b);
    i=bfs(a,b);
    if(i==-1)cout<<"impossible"<<endl;
    else
    {
       n=i;
       cout<<i<<endl;
      while(1)
       {
          int ddx;
          int ddy;
          if(dx==0&&dy==0)break;
          ee[i--]=mm[dx][dy].kind;
          ddx=mm[dx][dy].prex;
          ddy=mm[dx][dy].prey;
          dx=ddx;
          dy=ddy;
      }
      for(j=1;j<=n;j++)
      dir(ee[j]);
    }
   return 0;
}
