#include<iostream>
#include<cstdio>
using namespace std;
int n;
struct node
{
    int re;
    int ma;
    int mi;
};
node dp[4010];
void init()
{
    for(int l=0;l<=n;l++)
    {dp[l].re=1;dp[l].mi=-1;}
}
int main()
{
    int i,j,m;
    int s[4010];
    while(cin>>n)
    {
        int y=0;
        init();
        for(i=1;i<=n;i++)
        scanf("%d",&s[i]);
        for(i=1;i<=n;i++)
        {
            int mo=1;
            for(j=1;j<=n;j++)
            {
                if(s[j]+dp[j].ma*dp[j].mi==s[i])
                mo=max(mo,dp[j].re+1);
            }
            dp[i].re=mo;
            y=max(y,mo);
        }
        cout<<y<<endl;
    }
    return 0;
}
