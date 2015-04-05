#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
char s[30][40];
int mark[30];
int n;
int m[30][30];
int mm=0xfffffff;
int ma;
int pp=0xfffffff;
int judge(int sta,int color)
{
    for(int ii=0;ii<30;ii++)
    {
        if(m[sta][ii])
        {
            if(color==mark[ii])return 0;
        }
    }
    return 1;
}
int find_max(int nn)
{
    int ee=-0xfffffff;
    for (int ii = 0; ii < nn; ++ii)
    {
        ee=max(ee,mark[ii]);
    }
    return ee;
}
void dfs(int x)
{
   if (x==n)
    {
        ma=find_max(n);
        pp=min(pp,ma);
        return ;
    } 
        for(int ii=1;ii<=4;ii++)
        {
            if(judge(x,ii)){mark[x]=ii;dfs(x+1);}
        }
    return ;
}
void init()
{
    for(int jj=0;jj<=n;jj++)
        {
            mark[jj]=0;
            for(int kk=0;kk<=n;kk++)
                m[jj][kk]=0;
        }
        return ;
}
int main()
{
	int i,j;
	while(scanf("%d",&n),n)
	{
        init();
        pp=0xfffffff;
		for(i=0;i<n;i++)
		{
			scanf("%s",s[i]);
			for(j=2;j<strlen(s[i]);j++)
			{
               m[i][s[i][j]-'A']=1;
               m[s[i][j]-'A'][i]=1;
			}
        }
       dfs(0);
       if(pp==1)printf("%d channel needed.\n",pp);
       else printf("%d channels needed.\n",pp);
	}
	return 0;
}
