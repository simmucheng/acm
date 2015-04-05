#include<stdio.h>
int main()
{
    int s[1000]={0},a,i,j,k,n,m,y;
    scanf("%d",&m);
    for(y=0;y<m;y++)
    {
      scanf("%s",&s);
       scanf("%d",&a);
       for(k=0;k<a;k++)
         {
           for(i=1000;i>=0;i--)
              {
                 n=0;
                 for(j=1000;j>=0;j--)
                     {
                        s[j]=(s[i]*s[j]+n)%10;
                        n=s[i]*s[j]/10;
                     }}}
                     for(i=1000;i>=0;i--)
                     {
                         if(s[i]!=0)
                         {

                             for(j=0;j<=i;j++)
                             {
                                 printf("%d",s[j]);
                             }
                             break;
                         }
                     }
    }
    return 0;
}
