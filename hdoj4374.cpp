#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int s[103][10005];
int dp[103][10005];
int I[10005];
int main()
{
    int m,n,i,j;
    int len,si,loca,move;
    while(scanf("%d%d%d%d",&len,&si,&loca,&move)!=EOF)
    {
        for(i=0;i<len;i++)
        for(j=0;j<si;j++)
        scanf("%d",&s[i][j]);
        for(j=0;j<si;j++)
        dp[len-1][j]=
        for(i=1;i<len;i++)
        for(j=0;j<si;j++)
        dp[i][j]=
    }

}
