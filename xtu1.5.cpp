#include<iostream>
#include<cstdio>
using  namespace std;
int s[32007];
int re[32007];
int lowbit(int d)
{
    return d&(-d);
}
int sum(int d)
{
    int su=0;
    while(d)
    {
        su+=s[d];
        d-=lowbit(d);
    }
    return su;
}
void add(int d,int v)
{
    while(d<=32001)
    {
        s[d]+=v;
        d+=lowbit(d);
    }
    return ;
}
int main()
{
    int i,j,m,n;
    scanf("%d",&n);
    int x,y;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        re[sum(x+1)]++;
        add(x+1,1);
    }
    for(i=0;i<n;i++)
    printf("%d\n",re[i]);
    return 0;
}
