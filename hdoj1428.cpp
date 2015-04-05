#include<iostream>
#include<cstdio>
using namespace std;
int w[][]={1,0,-1,0,0,-1,0,1};
int ma[55][55];
int ci[55][55];
int num;
int dfs(int a,int b)
{
    int l;
    if(a==n-1&&b==n-1)return s[n-1][n-1];
    int mark1,mark2;
    for(l=0;l<4;l++)
    {
        if(a+w[l][0]<0||b+w[l][1]<0)continue;
        else {
            if(ma[a+w[l][0]][b+w[l][1]]==0)
            {
            ma[a+w[l][0][b+w[l][1]]=1;
            if(dp[a+w[l][0]][b+w[l][1]]==dfs(a+w[l][0],b+w[l][1]))ci[a+w[l][0]][b+w[l][1]++;
            else
            dp[a+w[l][0]][b+w[l][1]]=min(dfs(a+w[l][0],b+w[l][1])+s[a+w[l][0]][b+w[l][1]],dp[a+w[l][0]][b+w[l][1]]);
            }
             }
    }
}
int main()
{
    int i,j,m,n;
    int s[55][55];
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            cin>>s[i][j];
        }

    }
}
