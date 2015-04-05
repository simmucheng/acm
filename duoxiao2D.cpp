#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 0xfffffff
using namespace std;
int find_min(int a,int b,int c,int d)
{
    return min(min(min(a,b),c),d);
}
int dp[2010][2010];
char s[2010];
int va[30][2];
void init()
/*{
   for(int ii=0;ii<30;ii++)
   	{
   		va[ii][0]=N;
   		va[ii][1]=N;
   	}
   	return  ;
}*/
int main()
{

	int i,j,m,n;
	scanf("%d%d",&n,&m);
	getchar();
	for(i=1;i<=m;i++)
	scanf("%c",&s[i]);
	char e;
	init();
	for(i=0;i<n;i++)
	{
		getchar();
        scanf("%c",&e);
        scanf("%d%d",&va[e-'a'][0],&va[e-'a'][1]);
	}
	dp[0][m]=min(va[s[m]-'a'][1],va[s[m]-'a'][0]);
	dp[1][m+1]=min(va[s[1]-'a'][0],va[s[1]-'a'][1]);
	dp[0][m+1]=0;
    for(j=m-1;j>=1;j--)
        dp[0][j]=min(dp[0][j+1]+va[s[j]-'a'][1],dp[0][j+1]+va[s[j]-'a'][0]);
    for(j=2;j<=m;j++)
    	dp[j][m+1]=min(dp[j-1][m+1]+va[s[j]-'a'][1],dp[j-1][m+1]+va[s[j]-'a'][0]);
    int uu=0xfffffff;
	for(i=1;i<=m;i++)
	{
		for(j=m;j>=i;j--)
		{
		    dp[i][j]=find_min(dp[i-1][j]+va[s[i]-'a'][1],dp[i][j+1]+va[s[j]-'a'][1],dp[i-1][j]+va[s[i]-'a'][0],dp[i][j+1]+va[s[j]-'a'][0]);
			if(s[i]==s[j])
			{
				dp[i][j]=min(dp[i][j],dp[i-1][j+1]);
			}
			if(i==j||i+1==j)
			uu=min(uu,dp[i][j]);
		   //cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
		}
	}
	printf("%d\n",uu);
	return 0;
}
