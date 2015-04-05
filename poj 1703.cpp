#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200000
using namespace std;
int fa[200100<<1];
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
	else 
		fa[xx]=yy;
	return ;
}
void init()
{
	for(int ii=1;ii<=N*2;ii++)
		fa[ii]=ii;
	return ;
}
int main()
{
	int i,j,m,n;
	int e;
	scanf("%d",&e);
	while(e--)
	{
		scanf("%d%d",&m,&n);
		init();
		while(n--)
		{
			int a,b;
			char s[2];
			scanf("%s",s);
			if(s[0]=='D')
			{
                scanf("%d%d",&a,&b);
                unin(a,b+N);
                unin(b,a+N);	
			}
			else 
			{
				scanf("%d%d",&a,&b);
                 if(find_fa(a)==find_fa(b))
                 	printf("In the same gang.\n");
                 else 
                 {
                 	if(find_fa(a)==find_fa(b+N)||(find_fa(b)==find_fa(a+N)))
                 		printf("In different gangs.\n");
                 	else 
                 		printf("Not sure yet.\n");
                 }
			}
		}
	}
	return 0;
}