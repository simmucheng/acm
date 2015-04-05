#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define INF 0xfffffff
using namespace std;
struct node
{
    int mark;
    int distence;
    int dis;
    int money;
};
int u,limit,num;
node path[110];
int s[120][120];
void dijicster()
{
    int l;
    int ma=INF;
    int mar=1;
    while(mar)
    {
        mar=0;
      for(l=1;l<=num;l++)
       {
         if(ma>path[l].distence&&!path[l].mark)
         {mar=l;ma=path[l].distence;}
       }
      path[mar].mark=1;
      for(l=1;l<=num;l++)
        {
            if(path[l].distence>ma+s[mar][l]&&!path[l].mark&&(abs(path[mar].dis-path[l].dis)<=limit))
            path[l].distence=ma+s[mar][l];
        }
    }
     u=INF;
    for(l=1;l<=num;l++)
        u=min(path[l].distence+path[l].money,u);
    return ;
}
void init()
{
    int k,h;
    for(k=0;k<=num;k++)
    {
        for(h=0;h<=num;h++)
        s[k][h]=INF;
    }
    return ;
}
int main()
{
    int i,j,m,n;
    while(cin>>limit>>num)
    {
        //memset(s,0,sizeof(s));
        init();
        int x,y;
        for(i=0;i<=num;i++){path[i].distence=INF;path[i].mark=0;}
        for(i=1;i<=num;i++)
        {
            cin>>path[i].money>>path[i].dis>>y;
            while(y--)
            {
                int sample;
                cin>>x>>sample;
                s[i][x]=sample;
            }
        }
        path[1].distence=0;
        dijicster();
        cout<<u<<endl;
    }
    return 0;
}
