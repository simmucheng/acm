#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
using namespace std;
//ofstream oo("1234.txt");
int mark[110];
int s[110];
int number[110];
int top;
int dp[110][100][100];
int judge(int nn)
{
    if(nn&(nn<<1)||nn&(nn<<2))return 0;
    return 1;
}
int get(int nn)
{
    int num=0;
    while(nn)
    {
        if(nn%2)num++;
        nn=(nn>>1);
    }
    return num;
}
void init(int nn)
{
    for(int ii=0;ii<nn;ii++)
    {
        if(judge(ii))
        {
            s[++top]=ii;
            number[top]=get(ii);
        }
    }
    return ;
}
int main()
{
    int a,b,m,n,i,j;
    int r,k;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        top=0;
        init(1<<b);
        for(i=1;i<=a;i++)
        {
            getchar();
            mark[i]=0;
            for(j=1;j<=b;j++)
            {
                char e;
                scanf("%c",&e);
                if(e=='P')
                mark[i]+=(1<<(b-j));
            }
        }
        mark[0]=0;
        int sum=0;
        for(i=1;i<=a+2;i++)
        {
            for(j=1;j<=top;j++)
            {
                if((mark[i]^((1<<b)-1))&s[j])continue;
                for(k=1;k<=top;k++)
                {
                    if(s[k]&s[j])continue;
                    for(r=1;r<=top;r++)
                    {
                        if(s[j]&s[r])continue;
                        dp[i][j][k]=max(dp[i-1][k][r]+number[j],dp[i][j][k]);
                    }
                }
            }
        }
        printf("%d\n",dp[a+2][1][1]);
    }
    return 0;
}
