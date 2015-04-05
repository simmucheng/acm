#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct node
{
	int par;
	int mark;
}s[100005];
int main()
{
	int i,j,m,n;
	int mm;
	scanf("%d",&n);
	while(n--)
	{
	   memset(s,0,sizeof(s));
       scanf("%d",&m);
       m--;
       while(m--)
       {
       	int x,y;
       	scanf("%d%d",&x,&y);
       	s[y].par=x;
       }
       int xx,yy;
       scanf("%d%d",&xx,&yy);
       while(xx)
       {
       	 s[xx].mark=1;
       	 xx=s[xx].par;
       }
       while(yy)
       {
       	  if(s[yy].mark)
       	  {
       	  	mm=yy;
       	  	break;
       	  }
       	  yy=s[yy].par;
       }
       printf("%d\n",mm);
	}
	return 0;
}