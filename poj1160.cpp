#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int dp[40][320];
int sum[40][320];
int mark[40][320];
int pos[320];
int con(int x,int y)
{
    int i=x;
    int j=y;
    int su=0;
    while(i<j)
    {
        su+=pos[j]-pos[i];
        i++;
        j--;
    }
    return su;
}
int main()
{
    int village,po;
    int i,j,k;
    while(scanf("%d%d",&village,&po)!=EOF)
    {
        for(i=1;i<=village;i++)
        scanf("%d",&pos[i]);
        for(i=1;i<=village;i++)
        {dp[1][i]=con(1,i);
        mark[1][i]=0;
        }
        for(i=2;i<=po;i++)
        mark[i][village+1]=village-1;
        for(i=2;i<=po;i++)
        {
            for(j=village;j>=i;j--)
            {
                int mi=0xfffffff;
                for(k=mark[i-1][j];k<=mark[i][j+1];k++)
                if(mi>dp[i-1][k]+con(k+1,j)){mi=dp[i-1][k]+con(k+1,j);
                mark[i][j]=k;
                }
                dp[i][j]=mi;
            }
        }
    cout<<dp[po][village]<<endl;
    }
    return 0;
}
