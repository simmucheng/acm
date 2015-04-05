#include<stdio.h>
int main ()
{
    int a,i,b,k,j;
    scanf("%d",&a);
    b=2*a-1;
    for(j=b;j>=1;j-=2)
    {
          a-=1;
          for(k=(b+1)/2;k>a+1;k--)
            {
                putchar('\0');
            }
          for(i=j;i>=1;i--)
            {
                putchar('#');
            }
    putchar('\n');
    }
    return 0;
}
