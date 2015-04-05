#include<stdio.h>
#include<string.h>
long s[100003][100003];
int main()
{
    long a,b,m,n,i,j,c;
     while(scanf("%ld",&n)==1)
    {
        c=0;
         memset(s,0,sizeof(s));
      while(n--)
      {
          scanf("%ld%ld",&a,&b);
          s[a][b]++;
          c=b>c?b:c;
      }
      i=5;
      for(j=1
          j<=c;i++)
      {
          s[i][j]=max(s[i][j-1],s[i-1][j-1],s[i+1][j-1])+s[i][j];
      }
    }
    return 0;
}
int max(long x,long y,long z)
{
    long t;
    t=x>y?x:y;
    t=t>z?t:z;
    return(t);
}
