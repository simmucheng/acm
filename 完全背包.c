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
    b=0;
    memset(con,0,sizeof(con));
    for(i=1;i<=n;i++)
    {
        for(j=s[i];j<=price;j++)
        {
            con[j]=con[j-s[i]]+p[i]>con[j]?con[j-s[i]]+p[i]:con[j];
            b=b>con[j]?b:con[j];
            printf("%d ",con[j]);
        }
        putchar('\n');
    }
     printf("%d\n",b);
     return 0;
}
