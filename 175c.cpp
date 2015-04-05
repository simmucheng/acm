#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
__int64 s[300010];
int main()
{
    int i,j,m;
    while(scanf("%d",&m)!=EOF)
    {
        __int64 num;
        num=0;
        for(i=0;i<m;i++)
        {
            scanf("%I64d",&s[i]);
        }
        sort(s,s+m);
        for(i=0;i<m;i++)
        {
            num+=abs(s[i]-i-1);
        }
        printf("%I64d\n",num);
    }
    return 0;
}
