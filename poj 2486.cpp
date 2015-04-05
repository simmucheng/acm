#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int next[110][110];
int mark[110][110];
int step;
int f[110];
int dp[110][210][2];
int s[110];
void find_pa(int nn)
{
    for(int ii=1;ii<=mark[nn][0];ii++)
    {
        if(f[mark[nn][ii]])continue;
        f[mark[nn][ii]]=1;
        find_pa(mark[nn][ii]);
        next[nn][++next[nn][0]]=mark[nn][ii];
    }
    return ;
}
void dfs(int nn)
{
    for(int ii=1;ii<=next[nn][0];ii++)
    dfs(next[nn][ii]);
    for(int ii=0;ii<=step;ii++)
    {
    dp[nn][ii][0]=s[nn];
    dp[nn][ii][1]=s[nn];
    }
    for(int ii=1;ii<=next[nn][0];ii++)
    {
        for(int jj=step;jj>=1;jj--)
        {
            int temp1=dp[nn][jj][0];
            int temp2=dp[nn][jj][1];
            for(int kk=0;kk<=jj;kk++)
            {
                if(jj-kk-2>=0)
                temp1=max(dp[next[nn][ii]][jj-kk-2][0]+dp[nn][kk][0],temp1);
                if(jj-1-kk>=0)
                temp2=max(dp[next[nn][ii]][jj-1-kk][1]+dp[nn][kk][0],temp2);
                if(jj-1-kk>=0)
                temp2=max(dp[next[nn][ii]][jj-2-kk][0]+dp[nn][kk][1],temp2);
            }
            //cout<<"nn = "<<nn<<' '<<"jj = "<<jj<<' '<<temp1<<' '<<temp2<<endl;
            dp[nn][jj][0]=temp1;
            dp[nn][jj][1]=temp2;
        }
    }
     return ;
}
int main()
{
    int i,j,n,m;
    int a,b;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(next,0,sizeof(next));
        memset(dp,0,sizeof(dp));
        memset(f,0,sizeof(f));
        memset(mark,0,sizeof(mark));
        step=n;
        for(i=1;i<=m;i++)
        scanf("%d",&s[i]);
        for(i=1;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            mark[a][++mark[a][0]]=b;
            mark[b][++mark[b][0]]=a;
        }
        //cout<<mark[1][1]<<endl;
        f[1]=1;
        find_pa(1);
        dfs(1);
        int tt=max(dp[1][n][1],dp[1][n][0]);
        printf("%d\n",tt);
    }
    return 0;
}
