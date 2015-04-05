#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
struct node
{
	int num;
	int mark;
}s[30];
int main()
{
	int i,j,m,n;
	int x,y;
	int p=0;
	while(scanf("%d",&n),n)
	{
        scanf("%d%d",&x,&y);
        for(i=0;i<n;i++)
             scanf("%d",&s[i].num);
         int mm=1;
        while(mm)
        {
          mm=0;
          for(i=0;i<n;i++)
          {
          	    if(!s[i].mark)
          	{
                if(s[i].num%x==0){y-=s[i].num/x;mm=1;s[i].mark=1;}
                else if(s[i].num%y==0){x-=s[i].num/y;mm=1;s[i].mark=1;}
            }
          }
       }
       if(x*y==0)printf("Case %d: YES\n",++p);
       else printf("Case %d: NO\n",++p);
	}
	return 0;
}