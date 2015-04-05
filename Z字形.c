#include<stdio.h>
#define N 144
int main ()
{
    char s[N],a[12][12];
    int i=-1,j,m,n,k,x,y,p,q=0;
        scanf("%s",&s);
    n=(int)sqrt(strlen(s)*1.0);
    k=strlen(s);
    for(p=0;p<=2*(n-1);p++)
    {
       x=0;
       for(i=q;i<=k-1;i++)
          {
             if(p-x<0&&x>=n)break;
             a[x][p-x]=s[i];
             printf("%c",a[x][p-x]);
             printf("%d %d %d\n",x,p,p-x);
             x++;
             q=i+1;
          }
          //putchar('\n');
        //x=0;
        p++;
      for(j=q;j<=k-1;j++)
          {
              if(x!=n-1)
             if(y<0&&p-y>=n)break;
             a[y][p-y]=s[j];
             printf("%c ",a[y][p-y]);
             y--;
             q=j+1;
          }
          //printf("%c ",a[x][p-x]);
    }
    /*for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=n-1;j++)
        {
            printf("%c",a[i][j]);
        }
        putchar('\n');
    }*/
    return 0;
}
