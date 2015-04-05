#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
long long s[20];
long long gcd(long long aa,long long bb)
{
    while(bb)
    {
        int tt=bb;
        bb=aa%bb;
        aa=tt;
    }
    return aa;
}
long long clm(long long aa,long long bb)
{
    return aa*bb/gcd(aa,bb);
}
int main()
{
    int i,j,m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(i=0;i<n;i++)
        scanf("%lld",&s[i]);
        int ans=0;
        for(i=1;i<=(1<<n)-1;i++)
        {
            long long sum;
            int mark=0;
            int total=0;
            for(j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    total++;
                    if(!mark)
                    {
                        sum=s[j];
                        mark=1;
                    }
                    else sum=clm(sum,s[j]);
                }
            }
            ans+=((total%2==1)?(1):(-1))*m/sum;
        }
        printf("%d\n",m-ans);
    }
    return 0;
}
