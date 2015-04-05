#include<stdio.h>
int main()
{
    int a,b,m,n,i,s[109];
    while(scanf("%d",&n)==1)
    {
        if(n==0)break;
        for(i=1;i<n+1;i++)
            scanf("%d",&s[i]);
        m=0;
        s[0]=0;
        for(i=0;i<n;i++)
        {
            if(s[i+1]>s[i])
            {
            b=s[i+1]-s[i];
            m=b*6+m;
            }
            if(i<=n-1)m=m+5;
            if(s[i+1]<s[i])
            {
            b=s[i]-s[i+1];
            m=b*4+m;
            }
        }
        printf("%d\n",m);
    }
    return 0;
}
