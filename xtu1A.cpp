#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
int q[10],w[10]; 
struct node
{
	int aa;
	int sta;
	int num;
}s[110];
int poww(int nn)
{
	int kk=1;
	for(int ii=1;ii<=nn;ii++)
		kk*=10;
	return kk;
}
int judge(int nn,int number)
{
	memset(q,0,sizeof(q));
	int mm=nn;
	int tt;
	while(nn)
  {
      int t=nn%10;
      q[t]++;
      nn/=10;
  }
	for(int ii=1;ii<=number;ii++)
	{
		for(int jj=0;jj<10;jj++)
			w[jj]=q[jj];
		tt=mm;
		int xx=0;
		int yy=0;
		int ee=s[ii].aa;
        for(int jj=0;jj<4;jj++)
        {
            if(w[ee%10])
            	{
            		yy++;
                    w[ee%10]--;
                }
            if(ee%10==tt%10)xx++;
            ee/=10;
            tt/=10;
        }
        if(xx!=s[ii].sta||yy!=s[ii].num)return 0;
	}
	return 1;
}
int main()
{
	int i,j,m,n;
	while(scanf("%d",&n),n)
	{
		int sum=0;
		int mark=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&s[i].aa,&s[i].num,&s[i].sta);
		}

		for(i=1000;i<10000;i++)
		{
			if(judge(i,n))
				{
					if(sum==0)
					mark=i;
					sum++;
				}
		}
		if(sum>1||sum==0)printf("Not sure\n");
		else printf("%d\n",mark);
	}
	return 0;
}