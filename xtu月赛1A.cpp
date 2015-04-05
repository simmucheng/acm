#include<iostream>
#include<cstdio>
using namesapce std;
map<char,short>q;
struct node
{
	int aa;
	int sta;
	int num
}s[110];
int poww(int nn)
{
	int kk=1;
	for(int ii=1;ii<=nn;ii++)
		kk*=10;
	return kk;
}
int judge(int nn)
{
	int tt=nn;
	while(nn)
  {
      int t=nn%10;
      q[t]=1;
      nn/=10;
  }
	for(int ii=1;ii<=n;ii++)
	{
		int xx=0;
		int yy=0;
		int ee=s[ii].aa;
        for(int jj=0;jj<4;jj++)
        {
            if(q[ee%poww(jj)])yy++;
            if(ee/poww(jj)==tt/poww(jj))xx++;
        }
        if(xx!=s[ii].sta||yy!=s[ii].num)return 0;
	}
	return 1;
}
int main()
{
	int i,j,m,n;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			sacnf("%d%d%d",&s[i].aa,&s[i].num,&s[i].sta);
		}
		for(i=1000;i<10000;i++)
		{
			if(judge(i))
				{
					if(sun==0)
					mark=i;
					sum++;
				}
		}
		if(sum>1||sum==0)printf("Not sure\n");
		else printf("%d\n",mark);
	}
	return 0;
}