#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 0xfffffff
using namespace std;
__int64 s[400010];
int main()
{
    int i,j,m,n;
    while(scanf("%d",&n)!=EOF)
    {
      int mark=0;
      for(i=0;i<n;i++)
      {
        scanf("%I64d",&s[i]);
      }
      sort(s,s+n);
      for(i=0;i<n;i++)
      {
        if(s[i]%s[0]!=0){mark=1;break;};
      }
     if(mark==1)printf("-1\n");
     else printf("%I64d\n",s[0]);
    }
    return 0;
}
