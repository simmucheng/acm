#include<stdio.h>
int main()
{
    int s[5],i,j,t;
    for(i=0;i<=4;i++)
    {
        scanf("%d",&s[i]);
    }
    for(j=0;j<=4;j++)
    {
        for(i=0;i<=3-j;i++)
        {
            if(s[i]<s[i+1])
          {
            t=s[i];
            s[i]=s[i+1];
            s[i+1]=t;
          }
    }
    }
    for(i=0;i<=4;i++)
    {
        printf("%d ",s[i]);
    }
    return 0;
}
