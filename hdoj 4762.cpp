#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<fstream>
#define MOD 1000
using namespace std;
int ans,sum[110];
ofstream oo("1.txt");
void xx(int nn)
{
    sum[100]=1;
    while(nn--)
    {
        int sta=0;
        for(int ii=100;ii>=0;ii--)
        {
            int tt=sum[ii];
            sum[ii]=(sum[ii]*ans+sta)%MOD;
            sta=(tt*ans+sta)/MOD;
        }
    }
    return ;
}
bool judge(int nn)
{
    int kk=0;
    for(int ii=0;ii<=100;ii++)kk=(sum[ii]+kk*MOD)%nn;
    if(kk==0)return true;
    return false;
}
void dd(int nn)
{
    int uu=0;
    for(int ii=0;ii<=100;ii++)
    {
        int tt=uu;
        uu=(sum[ii]+uu*MOD)%nn;
        sum[ii]=(sum[ii]+tt*MOD)/nn;
    }
    return ;
}
int main()
{
    int n;

        memset(sum,0,sizeof(sum));
        int x,y;
        for(int i1=2;i1<=100;i1++)
        {
            for(int j1=2;j1<=100;j1++)
            {
        x=i1;
        y=j1;
        ans=x;
        xx(y-1);
        int pp=y;
        for(int ii=2;ii<=pp;ii++)
        {
            while(y%ii==0)
            {
                if(judge(ii)){y/=ii;dd(ii);}
                else break;
            }
        }
        printf("%d/",y);
        for(int ii=0;ii<=100;ii++)
        {
            if(sum[ii]!=0)
            {
                printf("%d",sum[ii]);
                for(int jj=ii+1;jj<=100;jj++)printf("%03d",sum[jj]);
                break;
            }
        }
        printf("\n");
            }
        }

    return 0;
}
