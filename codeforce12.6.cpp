#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int s[120];
__int64 sum(int x,int y)
{
    __int64 t=s[x];
    for(int l=x+1;l<=y;l++)
    t^=s[l];
    return t;
}
int main()
{
    int i,j,m,n;
    while(cin>>n)
    {
        memset(s,0,sizeof(s));
        for(i=0;i<n;i++)
        cin>>s[i];
        __int64 mi=s[0];
        for(i=0;i<=n;i++)
        {
            for(j=0;j<n-i;j++)
            {
                __int64 e=sum(j,j+i);
                if(mi<e)mi=e;
            }
        }
        printf("%I64d\n",mi);
    }
    return 0;
}
