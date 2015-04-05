#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
long long s[20];
long long pri[4]={2,3,5,7};
int mark[4];
vector<int>pp;
long long poww(int nn,int mm)
{
    long long rr=1;
    for(int ii=1;ii<=mm;ii++)
    rr*=nn;
    return rr;
}
int gcd(int nn,int mm)
{
    while(mm)
    {
        int tt=nn%mm;
        nn=mm;
        mm=tt;
    }
    return nn;
}
int lcm(long long nn,int mm)
{
    return nn*mm/gcd(nn,mm);
}
int main()
{
    long long n;
    int m;
    while(scanf("%d%lld",&m,&n)!=EOF)
    {
        long long num=0;
        memset(mark,0,sizeof(mark));
        for(int ii=0;ii<m;ii++)
        scanf("%lld",&s[ii]);
        for(int ii=1;ii<poww(2,m);ii++)
        {
            int nn=ii;
            int sta=0;
            int step=0;
            long long rr=1;
            while(nn)
            {
                if(nn&1)
                {
                    sta++;
                    rr=lcm(rr,s[step]);
                }
                step++;
                nn>>=1;
            }
            if(sta&1)
                num+=n/rr;
            else
                num-=n/rr;
        }
        printf("%lld\n",num);
    }
    return 0;
}
