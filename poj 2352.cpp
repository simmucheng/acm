#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int w[32010];
int s[15100];
int lowbit(int nn)
{
    return nn&(-nn);
}
void add(int nn)
{
    while(nn<=32010)
    {
        w[nn]+=1;
        nn+=lowbit(nn);
    }
    return ;
}
int get_sum(int nn)
{
    int ss=0;
    while(nn>0)
    {
        ss+=w[nn];
        nn-=lowbit(nn);
    }
    return ss;
}
int main()
{
    int i,j,m,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(s,0,sizeof(s));
        int a,e;
        for(i=1;i<=n;i++)
        {
        scanf("%d%d",&a,&e);
        add(a+1);
        s[get_sum(a+1)]++;
        }
        for(i=1;i<=n;i++)
        printf("%d\n",s[i]);
    }
    return 0;
}
