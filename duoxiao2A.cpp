#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
map<long long,short>q;
int s[100010];
int main()
{
   int i,j,m,n;
   while(scanf("%d%d",&m,&n)!=EOF)
   {
   	 q.clear();
   	  for(i=0;i<m;i++)
   	  	scanf("%d",&s[i]);
   	  sort(s,s+m);
   	  int sum=0;
   	  for(i=0;i<m;i++)
   	  {
         if(!q[s[i]])
         	{
         		sum++;
         		q[s[i]*n]=1;
         	}
   	  }
   	  printf("%d\n",sum);
   }
   return 0;
}