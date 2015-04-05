#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define MA 0xfffffff
using namespace std;
int a,b;
struct node
{
    int aa;
    int bb;
    int P;
    int R;
    int co;
}s[100];
int sum;
int yy;
int sat[110];
void dfs(int nn,int su)
{
    if(nn==a)
    {
        sum=min(sum,su);
        return ;
    }
    for(int ii=1;ii<=b;ii++)
    {
        if(nn==s[ii].aa&&sat[nn]<7)
        {
            sat[nn]++;
            if(sat[s[ii].co]>0)
            dfs(s[ii].bb,su+s[ii].P);
            else
            dfs(s[ii].bb,su+s[ii].R);
            sat[nn]--;
        }
    }
    return ;
}
void init(int nn)
{
    for(int ii=1;ii<=nn;ii++)
    {
        sat[ii]=0;
        s[ii].co=0;
    }
    return ;
}
int main()
{
    int i,j,m,n;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        yy=0;
        init(b);
        sum=MA;
        for(i=1;i<=b;i++)
        scanf("%d%d%d%d%d",&s[i].aa,&s[i].bb,&s[i].co,&s[i].P,&s[i].R);
        sat[1]++;
        dfs(1,0);
        if(sum==MA)printf("impossible\n");
        else
        printf("%d\n",sum);
    }
    return 0;
}
