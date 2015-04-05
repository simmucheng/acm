#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int mark[100][100];
int direction[8][2]={-2,-1,-2,1,-1,-2,-1,2,1,-2,1,2,2,-1,2,1};
struct node
{
    int x1;
    int y1;
};
queue<node> q;
queue<node> w;
int num=0;
int ll;
int x,y;
int mar=0;
node path[1000];
void dfs(int x2,int y2,int ci,int num)
{
        if(num==x*y-1)
        {
        num=0;
        path[ci].x1=x2;
        path[ci].y1=y2;
        mar=1;
        }//this place wa twice
        if(mar==1)return ;
        path[ci].x1=x2;
        path[ci].y1=y2;
        mark[x2][y2]=1;
        for(int l=0;l<8;l++)
        {
            int xx=x2+direction[l][0];
            int yy=y2+direction[l][1];
            if(xx<1||xx>x||yy<1||yy>y||mark[xx][yy]==1)continue;
            else {
                  dfs(xx,yy,ci+1,num+1);
                  mark[xx][yy]=0;//thie place wa some times
                 }
        }
    return ;
}
//A1B3C1A2B4C2A3B1C3A4B2C4
int main()
{
    int i,j,m,n;
    cin>>n;
    for(i=1;i<=n;i++)
    {
            mar=0;
            scanf("%d%d",&y,&x);
            memset(mark,0,sizeof(mark));
            memset(path,0,sizeof(path));
            dfs(1,1,0,0);
        printf("Scenario #%d:\n",i);
        if(mar!=1)cout<<"impossible";
        else
        {
            for(int k=0;k<x*y;k++)
            printf("%c%d",path[k].x1-1+'A',path[k].y1);
        }
        cout<<endl<<endl;
    }
    //cout<<endl;
    return 0;
}
