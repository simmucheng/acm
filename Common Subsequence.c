#include<stdio.h>
#include<string.h>
int b[2000][2000];
char s[2000],a[2000];
int main()
{
    int i,j,m,n,x,y;
    while(scanf("%s%s",a,s)!=EOF)
    {
        x=strlen(a);
        y=strlen(s);
         memset(b,0,sizeof(b));
         for(i=0;i<x;i++)
         {if(s[0]==a[i])break;}
         for(j=i;j<x;j++)
         b[0][j]=1;
          for(i=0;i<y;i++)
           {if(a[0]==s[i])break;}
             for(j=i;j<y;j++)
               b[j][0]=1;
       for(i=1;i<y;i++)
          {
             for(j=1;j<x;j++)
                {
                   if(s[i]==a[j])
                       b[i][j]=b[i-1][j-1]+1;
                   else b[i][j]=b[i][j-1]>b[i-1][j]?b[i][j-1]:b[i-1][j];
                }
          }
          printf("%d\n",b[i-1][j-1]);
    }
    return 0;
}
