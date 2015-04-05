#include<iostream>
#include<cstdio>
#define N 10000
using namespace std;
int fa[N<<1];
void init(int nn)
{
	for(int ii=1;ii<=nn+N;ii++)
		fa[ii]=ii;
	return ;
}
int find_fa(int nn)
{
	if(fa[nn]!=nn)
		fa[nn]=find_fa(fa[nn]);
	return fa[nn];
}
void unin(int aa,int bb)
{
    int xx=find_fa(aa);
    int yy=find_fa(bb);
    if(xx==yy)return ;
    fa[xx]=yy;
    return ;
}
int main()
{
	int i,j,m,n;
	int e;
	scanf("%d",&e);
	int a,b;
	for(i=1;i<=e;i++)
	{
		int mark=0;
		scanf("%d%d",&m,&n);
		init(m);
		while(n--)
		{
            scanf("%d%d",&a,&b);
            if(find_fa(a)==find_fa(b))mark=1;
            else 
            {
            	unin(a,b+N);
            	unin(b,a+N);
            }
		}
		printf("Scenario #%d:\n",i);
		if(mark==1)
			printf("Suspicious bugs found!\n");
		else printf("No suspicious bugs found!\n");
		printf("\n");
	}
	return 0;
}