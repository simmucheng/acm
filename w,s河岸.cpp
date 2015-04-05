#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
    int w;
    int s;
}s[1000];
bool cmp(node a,node b)
{
    if(a.w!=b.w)
    return a.w<b.w;
}
int main()
{
    int a,n,m,b,i,j,x1,x2;
    int len,dis,man;
    int p[1000];
    while(scanf("%d%d",&len,&dis))
    {
        memset(p,0,sizeof(p));
        memset(s,0,sizeof(s));
        scanf("%d",&man);
        for(i=0;i<man;i++)
        scanf("%d%d",&s[i].w,&s[i].s);
        scanf("%d%d",&x1,&x2);
        sort(s,s+man,cmp);
        for(i=0;i<man;i++)
       // cout<<s[i].s<<' ';
        p[0]=1;
        int m=0;
        for(i=1;i<man;i++)
        {
            int ma=0;
            for(j=0;j<i;j++)
            {
                if(s[i].s>s[j].s)
                ma=max(ma,p[j]);
            }
            p[i]=ma+1;
            m=max(m,p[i]);
        }
        cout<<m<<endl;
    }
    return 0;
}

