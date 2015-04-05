#include<iostream>
#include<cstdio>
using namespace std;
__int64 s[100100];
int main()
{

    int i,j,m,n;
    while(cin>>m>>n)
    {
        n--;
        __int64 ma=0xffffffffffff;
        int sta;
        for(i=0;i<m;i++)
        {
            scanf("%I64d",&s[i]);
            if(s[i]<ma){ma=s[i];}
        }
        int len=0xffffff;
        for(i=0;i<m;i++)
        {
            if(s[i]==ma)
            {
                if(i<n)
                {
                    if(len>(n-i)){sta=i;len=(n-i);}
                }
                else if(i==n){sta=i;break;}
                else
                {
                    if(len>(m-i+n)){len=m-i+n;sta=i;}
                }
            }
        }
        if(sta==n)
          {
              s[sta]=ma*m;

              for(i=0;i<m;i++)
              {
                  if(i>=1)printf(" ");
                  if(i==sta)printf("%I64d",s[sta]);
                  else printf("%I64d",s[i]-ma);
              }
          }
        else if(sta<n)
           {
               s[sta]=ma*m+n-sta;
               for(i=0;i<m;i++)
               {
                   if(i>=1)printf(" ");
                   if(i<=n&&i>sta)printf("%I64d",s[i]-ma-1);
                   else if(i==sta)printf("%I64d",s[sta]);
                   else printf("%I64d",s[i]-ma);
               }
           }
        else if(sta>n)
        {
            s[sta]=ma*m+m-sta+n;
            for(i=0;i<m;i++)
            {
                if(i>=1)printf(" ");
                if(i>sta||i<=n)printf("%I64d",s[i]-ma-1);
                else if(i==sta)printf("%I64d",s[sta]);
                else printf("%I64d",s[i]-ma);
            }
        }
        printf("\n");
    }
    return 0;
}
