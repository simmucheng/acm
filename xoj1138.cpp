#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
	int x;
	int y; 
}s[40];
int xx,yy,n;
int cmp(node a,node b)
{
     if((a.x-xx)*(b.y-yy)==(b.x-xx)*(a.y-yy))return a.x<b.x;
     return (a.x-xx)*(b.y-yy)>(b.x-xx)*(a.y-yy);
}
int judge(node a,node b)
{
	if((a.x-xx)*(b.y-yy)!=(b.x-xx)*(a.y-yy))return 1;
	return 0;
}
int xxji(node a,node b,node c)
{
	return ((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y));
}
bool tubao()
{
	int l;
	for(l=0;l<n-1;l++)
	{
		if(xxji(s[l],s[l+1],s[l+2])<0)return false;
	}
	return true;
}
int main()
{
	int i,j,m;
	while(scanf("%d",&n),n)
	{
		xx=0xfffffff;
		yy=0xfffffff;
		memset(s,0,sizeof(s));
		int mark;
        for(i=0;i<n;i++)
        {
        	scanf("%d%d",&s[i].x,&s[i].y);
        	if(yy>s[i].y||(yy==s[i].y&&xx>s[i].x))
        	{
        		yy=s[i].y;
        		xx=s[i].x;
        		mark=i;
        	}
        }
        int mm=0;
        swap(s[0],s[mark]);
        s[n]=s[0];
        sort(s+1,s+n,cmp);
        if(tubao())printf("Yes\n");
        else printf("No\n");
       	}
	return 0;
}
