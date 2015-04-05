#include<iostream>
#include<cstdio>
using namespace std;
int next[1000010];
char s[1000010];
int main()
{
	int i,j,m,n;
	int num=0;
	while(scanf("%d",&n),n)
	{
		scanf("%s",s);
		int ii,jj;
		ii=0;
		jj=-1;
		next[0]=-1;
		while(ii<n)
		{
            if(s[ii]==s[jj]||jj==-1){ii++;jj++;next[ii]=jj;}
            else jj=next[jj];
		}
		printf("Test case #%d\n",++num);
		for(i=2;i<=n;i++)
		{
            if(i%(i-next[i])==0&&(next[i]!=0))
            	printf("%d %d\n",i,i/(i-next[i]));
		}
		printf("\n");
	}
	return 0;
}