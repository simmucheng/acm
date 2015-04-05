#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#include<cstring>
#include<string>
using namespace std;
struct node
{
    int a;
    int mark;
}s[100010];
int w[100010];
int u[100010];
int k[100010];
int f[100010];
int main()
{
    int i,j,m,n;
    int p;
    while(cin>>n)
    {
        __int64 num=0;
        memset(f,0,sizeof(f));
        memset(s,0,sizeof(s));
        memset(w,0,sizeof(w));
        memset(f,0,sizeof(f));
        memset(k,0,sizeof(k));
        int mi,ma;
        mi=0xffffff;
        ma=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&p);
            num+=p;
            mi=min(mi,p);
            ma=max(ma,p);
            s[p].a=i;
            s[p].mark=1;
            k[i]=p;
        }
        int r=1;
        for(i=mi;i<=ma;i++)
        {
            u[1]=s[mi].a;
            w[i]=1;
            if(s[i].mark==1&&i!=mi)
               {
                   w[i]+=r;
                   r=w[i];
                   u[w[i]]=s[i].a;
               }
        }
        int mia;
        for(i=1;i<=n;i++)
        {
            if(u[i]==i)num-=k[i];
                int t;
                t=u[i];
                int len=1;
                if(f[i]==0)
                {
                    f[i]=1;
                    mia=min(k[i],k[t]);
                    int q=1;
                  while(i!=t)
                  {
                      q++;
                    f[t]=1;
                    mia=min(mia,k[t]);
                    t=u[t];
                    ++len;
                   // if(q==6)break;
                  }
                   if(len>1)
                       num+=min((len-2)*mia,mia+(len+1)*mi);
                }
        }
        printf("%I64d\n",num);
    }
    return 0;
}


