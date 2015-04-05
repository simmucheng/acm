#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

#define eps 1e-8
using namespace std;
int s[120];
int dd(int nn)
{
    if(nn==0)return 1;
    while(nn)
    {
        int tt=nn%10;
        if(tt==0)return 1;
        nn/=10;
    }
    return 0;
}
int main()
{
    int i,j,m,n;
    while(scanf("%d",&n)!=EOF)
    {
        int num=0;
        int yy=-1;
        for(i=1;i<=n;i++)
            {
                scanf("%d",&s[i]);
                if(dd(s[i]))
                    num++;
                else
                {
                    if(yy==-1)
                        yy=s[i];
                }
            }
        if(n==1){printf("0\n");continue;}
        if(num<n&&num>0)
            num++;
        printf("%d\n",num);
        int kk=0;
        for(i=1;i<=n;i++)
        {
            if(dd(s[i]))
                {
                    if(kk==0)
                    {
                        printf("%d",s[i]);
                        kk=1;
                    }
                    else printf(" %d",s[i]);
                }
        }
        if(num>0&&yy!=-1)printf(" %d\n",yy);
        else
        {
            if(num>0)
                printf("\n");
        }
    }
    return 0;
}

