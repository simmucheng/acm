#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
char s[2][110];
char w[220];
char mark[220];
int mm[220];
map <string,bool> q;
int compare(int r)
{
    for(int l=0;l<=2*r-1;l++)
    {
        if(w[l]!=mark[l])return 0;
    }
    return 1;
}
int main()
{
    int i,j,m,n;
    scanf("%d",&n);
    j=0;
    while(n--)
    {
        j++;
        q.clear();
        scanf("%d",&m);
        getchar();
        for(i=m-1;i>=0;i--)
        scanf("%c",&s[0][i]);
        getchar();
        for(i=m-1;i>=0;i--)
        scanf("%c",&s[1][i]);
        getchar();
        for(i=2*m-1;i>=0;i--)
        scanf("%c",&w[i]);
        int pp=0;
        int a=0,b=0;
        int step=0;
        while(1)
        {
          a=0;
          b=0;
          step++;
          for(i=0;i<=2*m-1;i++)
          {
            if(i%2==0)
            mark[i]=s[0][a++];
            else mark[i]=s[1][b++];
          }
          if(compare(m)){pp=1;break;}
          string dd=mark;
          if(q[dd]==true){pp=0;break;}
          else q[dd]=true;
          for(i=0;i<m;i++)
          s[1][i]=mark[i];
          for(i=m;i<=2*m-1;i++)
          s[0][i-m]=mark[i];
        }
        if(pp==1)printf("%d %d\n",j,step);
        else printf("%d -1\n",j);
    }
    return 0;
}
