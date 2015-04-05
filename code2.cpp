#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

#define eps 1e-10
using namespace std;
__int64 s[100];
int main()
{
    int i,j,m,n;
    __int64 p,q;
    while(scanf("%I64d%I64d",&p,&q)!=EOF)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        scanf("%I64d",&s[i]);
        int top=0;
        while(1)
        {
            __int64 tt;
            tt=q;
            if(q==0)
            {
                q=-1;
                break;
            }
            if(s[top+1]-1>=p/q)
            {
                q=-1;
                break;
            }
            q=p-s[++top]*q;
            if(q<0){q=-1;break;}
            p=tt;
            if(top==n)break;
        }
        if(q==0)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


