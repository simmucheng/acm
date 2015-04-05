#include<stdio.h>
int main()
{
    char a,i,b,j;
    int m,n,k;
    scanf("%d",n);
    for(k=0;k<=n;k++)
    {
    a=getchar();
    getchar();
        for(b=a;b>='A';b--)
           {
               for(m=0;m<=(int)a-b;m++)
                    {
                         putchar('\0');
                    }
               for(i='A';i<=b;i++)
                    {
                         putchar(i);
                    }
               for(j=b-1;j>='A';j--)
                   {
                         putchar(j);
                   }
                putchar('\n');
           }
    if(k==n)break;
    }
    return 0;
}
