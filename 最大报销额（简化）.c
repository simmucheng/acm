#include<stdio.h>
#include<string.h>
int main()
{
    int m,n,i,j,price,p[100];
    int con[100],t;
    scanf("%d%d",&price,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
           t=0;
           memset(con,0,sizeof(con));
         for(i=1;i<=n;i++)
         {
             for(j=price;j>=p[i];j--)
             {
                 con[j]=con[j-p[i]]+p[i]>con[j]?con[j-p[i]]+p[i]:con[j];
                 t=t>con[j]?t:con[j];
             }
             //putchar('\n');
             for(j=price;j>0;j--)
             //printf("%d ",con[j]);
             //putchar('\n');
         }
         printf("%d\n",t);
      return 0;
    }

