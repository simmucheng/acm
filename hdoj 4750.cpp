#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=501000;
struct node
{
    int x;
    int y;
    int value;
}s[MAXN];
struct node1
{
    int value;
    int pp;
    int ff;
}dd[1001000];
int fa[100100],number[100100],next[100100];
vector<int>q;
inline bool cmp(node aa,node bb)
{
    return aa.value<bb.value;
}
int find(int nn)
{
    if(fa[nn]!=nn)fa[nn]=find(fa[nn]);
    return fa[nn];
}
int reseach(int nn,int len)
{
    int ll=0,rr=len-1;
    if(nn<=q[0])return 0;
    if(nn>q[len-1])return len;
    while(ll<rr)
    {
        int mid=(ll+rr)>>1;
        if(q[mid]<nn)ll=mid+1;
        else rr=mid;
    }
    return ll;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        q.clear();
        for(int ii=0;ii<n;ii++){fa[ii]=ii;number[ii]=1;}
        for(int ii=0;ii<m;ii++)
        {
            int x,y,value;
            scanf("%d%d%d",&s[ii].x,&s[ii].y,&s[ii].value);
        }
        int ll;
        scanf("%d",&ll);
        for(int ii=1;ii<=ll;ii++){scanf("%d",&dd[ii].ff);dd[ii].pp=ii;}
        sort(s,s+m,cmp);
        sort(dd+1,dd+1+ll);
        for(int ii=1;ii<=ll;ii++)next[dd[ii].pp]=ii;
        //int sta=0;
        for(int ii=0;ii<m;ii++)
        {
            if(find(s[ii].x)!=find(s[ii].y))
            {
                long long hh=number[fa[s[ii].y]]*number[fa[s[ii].x]];
                number[fa[s[ii].y]]+=number[fa[s[ii].x]];
                int step=reseach(s[ii].value);
                dd[step].value-=hh;
                number[fa[s[ii].x]]=0;
                fa[fa[s[ii].x]]=fa[s[ii].y];
            }
        }
        long long yy=n*(n-1);
        for(int ii=ll;ii>=1;ii--)
        {
            dd[ii].value=yy-dd[ii+1].value;
            yy=dd[ii].value;
        }
        for(int ii=1;ii<=ll;ii++)printf("%lld\n",dd[next[ii]].value);
    }
    return 0;
}


