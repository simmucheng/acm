#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int dp[110][110];
int s[110][110];
int m,n;
void init()
{
    int i,j;
    for(i=0;i<110;i++)
    for(j=0;j<110;j++)
    {dp[i][j]=1;s[i][j]=0xfffffff;}
}
int main()
{
    int i,j,m,n,l;
    int w[4][2]={1,0,-1,0,0,1,0,-1};
    while(scanf("%d%d",&m,&n)!=EOF)
{
    init();
    int y;
    int t=0;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            cin>>s[i][j];
    int end1;
    int r=3000;
    int ma=-1;
    while(r--)
{

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            int t=0;
            for(l=0;l<4;l++)
            {
                if(s[i][j]>s[i+w[l][0]][j+w[l][1]]&&(i+w[l][0]>=0)&&(j+w[l][1]>=0))
                t=max(t,dp[i+w[l][0]][j+w[l][1]]);
            }
            dp[i][j]=t+1;
            ma=dp[i][j]>ma?dp[i][j]:ma;
        }
    }
}
    cout<<ma<<endl;
}
    return 0;
}
