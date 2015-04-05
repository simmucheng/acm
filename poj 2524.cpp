#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int father[50100];
int s[50100];
int n;
__int64 m;
int find_father(int k)
{
    if(father[k]!=k)father[k]=find_father(father[k]);
    return father[k];
}
void unit(int xx,int yy)
{
    father[father[yy]]=father[xx];
}
void init()
{
    for(int l=1;l<=n;l++)
    {
        s[l]=0;
        father[l]=l;
    }
    return ;
}
int main()
{
    __int64 i,j;
    int a,b;
    int nn=1;
    while(scanf("%d%I64d",&n,&m),m||n)
    {
        int num=n;
        init();
        for(i=0;i<m;i++)
        {
         scanf("%d%d",&a,&b);
          if(find_father(a)!=find_father(b))
          {
            num--;
            unit(a,b);
          }
        }
        printf("Case %d: %d\n",nn++,num);
    }
    return 0;
}
