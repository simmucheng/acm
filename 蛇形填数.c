#include<stdio.h>
#include<string.h>
int main ()
{
    int i,j,s[8][8],a,n,m=1,b=0;
    scanf("%d",&n);
     memset(s,0,sizeof(s));
    a=n;
    if(n%2==1)s[(a-1)/2][(a-1)/2]=n*n;

   while(1){
       if(n<1)break;
        for(i=b;i<=n-2;i++)
        {
            s[i][n-1]=m;
            m++;
        }
        for(i=n-1;i>=b+1;i--)
        {
            s[n-1][i]=m;
            m++;
        }
        for(i=n-1;i>=b+1;i--)
        {
            s[i][b]=m;
            m++;
        }
        for(i=b;i<=n-2;i++)
        {
            s[b][i]=m;
            m++;
        }
        n--;
        b++;

    }
    for(i=0;i<=a-1;i++)
    {
        for(j=0;j<=a-1;j++)
        {
            printf("%d  ",s[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
