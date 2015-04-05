#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 0xfffffff
using namespace std;
struct node
{
    int x1;
    int y1;
    int x2;
    int y2;
    int col;
}s[20];
int mark[20];
int up[20][20];
int m;
int getmin;
void dfs(int color,int step,int number)
{
    if(step>=getmin)return ;
    if(number==m)
    {
        getmin=step;
        return ;
    }
    for(int ii=1;ii<=m;ii++)
    {
        if(mark[ii])continue;
        int flag=0;
        for(int jj=1;jj<=up[ii][0];jj++)
        {
            if(!mark[up[ii][jj]])
            {
                flag=1;break;
            }
        }
        mark[ii]=1;
        if(!flag)
            if(s[ii].col==color)dfs(color,step,number+1);
            else dfs(s[ii].col,step+1,number+1);
        mark[ii]=0;
    }
    return ;
}
int main()
{
    int i,j,n;
    scanf("%d",&n);
    while(n--)
    {
        getmin=N;
        memset(mark,0,sizeof(mark));
        memset(up,0,sizeof(up));
        scanf("%d",&m);
        for(i=1;i<=m;i++)
            scanf("%d%d%d%d%d",&s[i].y1,&s[i].x1,&s[i].y2,&s[i].x2,&s[i].col);
        for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
        {
            if(i==j)continue;
            if(s[i].y2==s[j].y1&&((s[i].x1<=s[j].x1&&s[i].x2>=s[j].x1)||(s[i].x1<=s[j].x2&&s[i].x2>=s[j].x2)))
            {
               up[j][++up[j][0]]=i;
            }
        }
        dfs(0,0,0);
        printf("%d\n",getmin);
    }
    return 0;
}
