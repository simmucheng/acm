#include<stdio.h>
#include<math.h>
int main ()
{
    int i,j,s[100]={0},m;
    for(i=2;i<=100;i++)
    {
        m=0;
        for(j=2;j<i;j++)
        {
            if(i%j==0)m=1;
        }
        if(m==0)s[i]=i;
    }
    int a,k[100]={0},p,n=1;
    scanf("%d",&a);
    for(i=2;i<=a;i++)
    {
        n=i*n;
        for(p=1;p<=50;p++)
        {
        for(j=2;j<=a;j++)
        {
            if(s[j]!=0)
            {
                if(n%s[j]==0)
                {
                    //printf("%d\n",s[j]);
                    n=n/s[j];
                    k[j]++;
                }
            }
        }
        }
    }
   // printf("%d\n",n);
    for(i=2;i<=a;i++)
    {
        if(s[i]!=0)printf("%d ",k[i]);
    }
    return 0;
}
