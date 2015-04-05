#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int s[101000];
int dp[101000][33];
int n;
int get(int x1,int y1);
void rmq()
{
	int dd=get(1,n);
	for(int ii=1;ii<=n;ii++)
		dp[ii][0]=1;
	for(int jj=1;jj<=dd;jj++)
	{
		for(int ii=1;ii+(1<<jj)-1<=n;ii++)
		{
			dp[ii][jj]=max(dp[ii][jj-1],dp[ii+(1<<(jj-1))][jj-1]);
			//cout<<"dp = "<<dp[ii][jj]<<endl;
			int xx=0;
			int yy=0;
			int mark=ii+(1<<(jj-1))-1;
			int k=ii+(1<<(jj-1))-1;
			while(k>=ii)
			{
              if(s[mark]==s[k])
              	xx++;
              else break;
              k--;
			}
			//cout<<"xx = "<<xx;
			k=ii+(1<<(jj-1));
			while(k<=ii+(1<<jj)-1)
			{

				if(s[mark]==s[k])
              	yy++;
                else break;
                k++;
			}
			//cout<<"yy = "<<yy<<endl;
			//cout<<"xx+yy = "<<xx+yy<<endl;
			dp[ii][jj]=max(dp[ii][jj],xx+yy);
			//cout<<"ii = "<<ii<<' '<<"jj = "<<jj<<' '<<dp[ii][jj]<<endl;
		}

	}
	return ;
}
int get(int x1,int y1)
{
	return (int)(log(y1-x1+1)/log(2));
} 
int get_answer(int x1,int y1)
{
    int e=get(x1,y1);
    int ee=max(dp[x1][e],dp[y1-(1<<e)+1][e]);
    int xx=0;
    int yy=0;
    int k=x1+(1<<e)-1;
    while(k>=x1)
    {
         if(s[k]==s[x1+(1<<e)-1])
         	xx++;
         else break;
         k--;
    }
    k=x1+(1<<e);
    while(k<=y1)
    {
         if(s[k]==s[x1+(1<<e)-1])
         	yy++;
         else break;
         k++;
    }
    return max(ee,xx+yy);
}
int main()
{
	int i,j,m;
	while(scanf("%d",&n),n)
	{
        scanf("%d",&m);
		for(i=1;i<=n;i++)
			scanf("%d",&s[i]);
		rmq();
		while(m--)
		{
			int aa,bb;
			scanf("%d%d",&aa,&bb);
			int u=get_answer(aa,bb);
			printf("%d\n",u);
		}
	}
	return 0;
}
