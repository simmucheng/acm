#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
//queue<int>Q;
int main()
{
    int i,j,m,n;
    int s[100010];
    while(scanf("%d",&n)!=EOF)
    {
        __int64 e=0;
        cin>>m;
        for(i=0;i<n;i++)
        scanf("%d",&s[i]);
        for(i=0;i<n-2;i++)
        {
            __int64 l1=i+2;
            __int64 l2=n-1;
            __int64 l=l1;
            __int64 sta=0;
           if(abs(s[i]-s[i+2])<=m)
           {
             while(1)
             {
                if(abs(s[l]-s[i])<=m&&abs(s[l+1]-s[i])<=m&&l<n-1)
                     l1=l+1;
                else if(abs(s[l]-s[i])>m)l2=l-1;
                else if(abs(s[l]-s[i])<=m&&(abs(s[l+1]-s[i])>m)){sta=(l-i-1)*(l-i)/2;break;}
                else if((l==n-1)&&abs(s[l]-s[i])<=m){sta=(l-i-1)*(l-i)/2;break;}
                l=(l1+l2)/2;
             }
             e+=sta;
           }
        }
        printf("%I64d\n",e);
    }
    return 0;
}
/*5
100
1 99 100 1000 10001
*/
