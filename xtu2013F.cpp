#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
__int64 ma=2000000001;
__int64 mi=1000000001;
__int64 s[100004];
__int64 w[100004];
__int64 lowbit(__int64 k)
{
	return k&(-k);
}
void add(__int64 x,__int64 v)
{
	while(x<=100000)
	{
        s[x]+=v;
        x+=lowbit(x);
	}
	return ;
}
__int64 getsum(__int64 x)
{
    __int64 num=0;
    while(x)
    {
      num+=s[x];
      x-=lowbit(x); 
    }
    return num;
}
int main()
{
	__int64 i,j,m,n;
	__int64 a,b,c;
	char e;
    while(scanf("%I64d%I64d",&m,&n)!=EOF)
    {
    	memset(s,0,sizeof(s));
    	for(i=1;i<=m;i++)
    		{
    			scanf("%I64d",&w[i]);
    			w[i]+=mi;
    			add(i,w[i]);
            }
         for(i=1;i<=n;i++)
         {
         	getchar();
         	scanf("%c",&e);
         	if(e=='C')
         	{
                scanf("%I64d%I64d%I64d",&a,&b,&c);
                for(j=a;j<=b;j++)
                {
                	add(j,c);
                }
         	}
         	else 
         	{
               scanf("%I64d%I64d",&a,&b);
               __int64 tt=getsum(b)-getsum(a-1)-(b-a+1)*mi;
               printf("%I64d\n",tt);
         	}
         }
    }
    return 0;
}