#include<stdio.h>
#include<string.h>
long s[12][100003];
int main()
{
     long a,b,m,n,i,j,c,d;
     while(scanf("%ld",&n)==1)
    {
        if(n==0)break;
         c=0;
         memset(s,0,sizeof(s));
      while(n--)
      {
          scanf("%ld%ld",&a,&b);
          s[a][b]++;
          c=b>c?b:c;
      }
      for(j=c-1;j>=0;j--)
      {
          if(j>=5){s[0][j]=max(s[0][j+1],s[1][j+1],0)+s[0][j];}
          for(i=1;i<=10;i++)
              s[i][j]=max(s[i][j+1],s[i-1][j+1],s[i+1][j+1])+s[i][j];
      }
      printf("%ld\n",s[5][0]);
    }
    return 0;
}
int max(int x,int y,int z)
{
    int t;
    t=x>y?x:y;
    t=t>z?t:z;
    return(t);
}
