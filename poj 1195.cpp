#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int w[1100][1100];
int lowbit(int nn)
{
	return nn&(-nn);
}
void add(int xx,int yy,int v)
{
     while(xx<=1100)
     {
        int temp=yy;
     	while(temp<=1100)
     	{
     		w[xx][temp]+=v;
     		temp+=lowbit(temp);
     	}
     	xx+=lowbit(xx);
     }
}
int get_sum(int xx,int yy)
{
	int sum=0;
	while(xx>0)
	{
	    int temp=yy;
		while(temp>0)
		{
           sum+=w[xx][temp];
           temp-=lowbit(temp);
		}
		xx-=lowbit(xx);
	}
	return sum;
}
void init(int nn)
{
    for(int ii=0;ii<=nn;ii++)
    	for(int jj=0;jj<=nn;jj++)
            w[ii][jj]=0;
}
int main()
{
	int i,j,m,n;
	int a,b,c;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
	    init(b);
	    while(1)
	    {
		 int e;
         scanf("%d",&e);
         if(e==1)
         {
        	scanf("%d%d%d",&a,&b,&c);
        	add(a+1,b+1,c);
         }
         else if(e==2)
         {
        	int x1,y1,x2,y2;
        	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            int tt=get_sum(x2+1,y2+1)-get_sum(x2+1,y1)-get_sum(x1,y2+1)+get_sum(x1,y1);
            printf("%d\n",tt);
         }
         else if(e==3)break;
        }
	}
	return 0;
}
