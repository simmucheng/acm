#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int ss[1100];
int ww[1100];
int main()
{
    char s[1100],w[1100];
    while(scanf("%s%s",s,w)!=EOF)
    {
        int len=strlen(s);
        for(int ii=0;ii<len;ii++)ss[ii]=s[ii]-'0';
        for(int ii=0;ii<len;ii++)ww[ii]=w[ii]-'0';
        for(int ii=0;ii<len;ii++)
        {
            for(int jj=0;;jj<=9;jj++)
            {
                for(int kk=0;kk<=9;kk++)
                {
                    int ans1=((kk-jj)%10+10)%10;
                    int ans2=((jj-kk)%10+10)%10;
                    int i3=s[ii+2];
                    dp[ii][kk][i3]=min(dp[ii-1][jj][kk]+ans,dp[ii][kk][i3]);
                    dp[ii][(kk+ans)%10][i3]=min(dp[ii-1][jj][kk]+ans,dp[ii][kk][(kk+ans)%10]);
                    dp[ii][kk][(i3+ans)%10]=min(dp[ii-1][jj][kk]+ans,dp[ii][(kk+ans)%10][(i3+ans)%10]);
                }
            }
        }
    }
    return 0;
}
