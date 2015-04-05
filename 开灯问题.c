#include<stdio.h>
int main ()
{
    int i,j,n,k,s[1001]={0};
    scanf("%d%d",&n,&k);
    for(j=1;j<=k;j++)
    {
        for(i=1;i<=n;i++)
        {
            if(i%j==0)
            s[i]++;
        }
    }
        for(i=1;i<=n;i++)
        {
            if(s[i]%2==1)printf("%d ",i);
        }
    return 0;
}
