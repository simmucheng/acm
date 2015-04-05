#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
int p1[1004];
int p2[1004];
float s[1004];
int main()
{
    int i,j,m,n,a,b;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        scanf("%f",&s[i]);
        s[0]=0.0;
        s[n+1]=0.0;
        memset(p1,0,sizeof(p1));
        int ma;
        p1[1]=1;
        for(i=2;i<=n;i++)
        {
            ma=0;
            for(j=0;j<i;j++)
        {
            if(s[i]>s[j])
            ma=max(ma,p1[j]);
        }
        p1[i]=ma+1;
        }
        memset(p2,0,sizeof(p2));
        p2[n]=1;
        for(i=n-1;i>=1;i--)
        {
            ma=0;
            for(j=n+1;j>i;j--)
        {
            if(s[i]>s[j])
            ma=max(ma,p2[j]);
        }
        p2[i]=ma+1;
        }
        int m=0;
        for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
        m=max(m,p1[i]+p2[j]);
        cout<<n-m<<endl;
    }
    return 0;
}

