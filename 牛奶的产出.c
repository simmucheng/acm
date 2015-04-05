#include<stdio.h>
#define N 100000
int main ()
{
    long int s[N];
    int a,b,i,j,k,m,p=0;
    scanf("%d",&a);
    while(1)
    {
        if(p>=a)break;
        p++;
        scanf("%d",&b);
       for(j=0;j<=b-1;j++)
       {
           scanf("%ld",&s[j]);
       }
       for(k=0;k<=b;k++)
           {
               for(j=0;j<=b-k;j++)
                  {
                      if(s[j]>s[j+1])
                           {
                               m=s[j];
                               s[j]=s[j+1];
                               s[j+1]=m;
                           }
                  }
            }
    printf("%ld\n",s[(b-1)/2]);
    }
    return 0;
}
