#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define INF 0xfffffff
using namespace std;
int n;
struct node
{
    int x;
    int y;
    int mark;
}s[210];
double path[210];
double distence(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2.0)+pow(y1-y2,2.0));
}
void dijkstra()
{
    int l,k;
    int uu;
    int ee=1;
    while(ee)
    {
        uu=INF;
        ee=0;
    for(l=1;l<=n;l++)
    {
        if((!s[l].mark)&&uu>path[l])
        {
            uu=path[l];
            ee=l;
        }
    }
    s[ee].mark=1;
    if(ee==2)return ;
    for(l=1;l<=n;l++)
    {
        double rr=distence(s[ee].x,s[ee].y,s[l].x,s[l].y);
        if(path[l]>rr&&(!s[l].mark))path[l]=rr;
    }
    }
    return ;
}
double findmax()
{
    double xx=-INF;
    int yy;
    for(int l=2;l<=n;l++)
    {
        if(s[l].mark&&path[l]>xx)
            xx=path[l];
    }
   return xx;
}
void init()
{
    for(int l=1;l<=201;l++)
       {
         s[l].mark=0;
         path[l]=INF;
       }
       return ;
}
int main()
{
    int i,j,m;
    int dd=1;
    while(cin>>n,n)
    {
        init();
        for(i=1;i<=n;i++)
        cin>>s[i].x>>s[i].y;
        path[1]=0;
        dijkstra();
        double ff=findmax();
        cout<<"Scenario #"<<dd++<<endl;
        printf("Frog Distance = %.3f\n\n",ff);
    }
    return 0;
}
