#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int s[100],p[100],con[100];
    int i,j,m,n,a,b,k,price,q;
    scanf("%d%d",&price,&n);
    for(i=1;i<=n;i++)
    scanf("%d%d",&p[i],&s[i]);
    q=n;
    for(i=1;i<=q;i++)
    {
        for(j=4;j>=0;j--)
        {
            if(s[i]-pow(2.0,j*1.0)+1>0){a=j;break;}
        }
        //printf("%d ",a);
        for(k=1;k<=a-1;k++)
        {
            n++;
            p[n]=p[i]*pow(2.0,k*1.0);
        }
        if(a==0)continue;
        n++;
        p[n]=p[i]*(s[i]-pow(2,a)+1);
     }
    for(i=1;i<=n;i++)
    printf("%d ",p[i]);
    putchar('\n');
    b=0;
    memset(con,0,sizeof(con));
    for(i=1;i<=n;i++)
    {
        for(j=price;j>=p[i];j--)
        {
            con[j]=con[j-p[i]]+p[i]>con[j]?con[j-p[i]]+p[i]:con[j];
            b=b>con[j]?b:con[j];
            printf("%d ",con[j]);
        }
        putchar('\n');
    }
     printf("%d\n",b);
     return 0;
}
