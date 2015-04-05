#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const long long mod=1e9+7;
long long MOD(long long nn)
{
    return nn%mod;
}
long long binary(long long nn,long long num)
{
    if(num==0)return 1;
    if(num&1)return binary(MOD(nn*nn),num/2)*nn;
    return binary(MOD(nn*nn),num/2);
}
long long cc(int nn,int mm)
{
    for(int )
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        long long sum=1;
        for(long long ii=1;ii<=a;ii++)
        {

        }
        printf("%lld\n",sum);
    }
    return 0;
}
