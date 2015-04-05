#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
char s[12];
int p[30][30];
int change(char r)
{
    return r-'a'+1;
}
void init()
{
    p[1][0]=1;
    p[1][1]=1;
    for(int i=2;i<=26;i++)
    {
        for(int j=0;j<=i;j++)
        {
         if(i==j||j==0)p[i][j]=1;
         else
         p[i][j]=p[i-1][j-1]+p[i-1][j];
        }
    }
}
int judge()
{
    for(int k=0;k<strlen(s)-1;k++)
    if(s[k]>=s[k+1])return 0;
    return 1;
}
int main()
{
    int i,j;
    init();

    cin>>s;
    __int64 sum=0;
    if(!judge())printf("0\n");
    else
    {
    int y=change(s[0]);
    int t=strlen(s);
    for(i=1;i<t;i++)
    sum+=p[26][i];
    char e='a';
      for(i=0;i<t;i++)
     {
         int u=change(s[i]);
         sum+=p['z'-e+1][t-i]-p['z'-s[i]+1][t-i];
         e=s[i]+1;
     }
    printf("%I64d\n",sum+1);
    }
    //}
    return 0;
}
