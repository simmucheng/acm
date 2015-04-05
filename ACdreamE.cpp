#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    long long i,j,m,n,k;
    long long w[100010];
    while(scanf("%lld%lld",&n,&k)!=EOF)
    {
        for(i=0;i<n;i++)
        scanf("%lld",&w[i]);
        sort(w,w+n);
        for(i=n-1;i>=0;i--)
        {
            if(k>0)k-=w[i];
            else break;
        }
        printf("%lld\n",n-i-1);
    }
    return 0;
}
