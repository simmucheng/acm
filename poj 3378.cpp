#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const __int64 mark=1e8;
int s[51010];
struct node
{
    __int64 bi;
    __int64 sm;
}ma[5][50010];
node pp[50010];
node ll[51000];
node ask[51000];
int lowbit(int nn)
{
    return nn&(-nn);
}
node add(node aa,node bb)
{
    aa.bi+=bb.bi;
    aa.sm+=bb.sm;
    __int64 rr=aa.sm/mark;
    aa.sm%=mark;
    aa.bi+=rr;
    return aa;
}
void inser(int nn,int ci)
{
    int mm=nn;
    nn=s[nn];
    while(nn<=50010)
    {
        ma[ci][nn]=add(ma[ci][nn],ask[mm]);
        nn+=lowbit(nn);
    }
    return ;
}
node get_ans(int nn,int ci)
{
    node ss;
    ss.bi=0;
    ss.sm=0;
    while(nn>0)
    {
        ss=add(ss,ma[ci][nn]);
        nn-=lowbit(nn);
    }
    return ss;
}
node xx(node aa,node bb)
{
    aa.bi-=bb.bi;
    aa.sm-=bb.sm;
    if(aa.sm<0)
       {
           aa.sm+=mark;
           aa.bi--;
       }
    return aa;
}
void init(int nn)
{
    for(int ii=1;ii<=nn;ii++)
    {
        for(int jj=1;jj<=4;jj++)
            {
                ma[jj][ii].bi=0;
                ma[jj][ii].sm=0;
            }
            ask[ii].sm=0;
            ask[ii].bi=0;
    }
    return ;
}
int main()
{
    int i,j,m,n;
    while(scanf("%d",&n)!=EOF)
    {
        vector<int>q;
        init(n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&s[i]);
            q.push_back(s[i]);
        }
        sort(q.begin(),q.end());
        q.erase(unique(q.begin(),q.end()),q.end());

        #define FIND(v) (lower_bound(q.begin(),q.end(),v)-q.begin())
        for(i=1;i<=n;i++)
                    s[i]=FIND(s[i])+1;
        #undef FIND

        for(i=1;i<=n;i++)
              ask[i].sm=1;
        for(i=1;i<=4;i++)
           {
               for(j=1;j<=n;j++)
                  {
                      inser(j,i);
                      //ll[s[j]]=add(ll[s[j]],ask[j]);
                      pp[j]=get_ans(s[j]-1,i);
                  }
                for(int k=1;k<=n;k++)
                    {
                           ask[k].bi=pp[k].bi;
                           ask[k].sm=pp[k].sm;
                           //cout<<pp[k].sm<<' ';
                           //ll[s[k]].bi=0;
                           //ll[s[k]].sm=0;
                    }
           }
        node ee;
        ee.bi=0;
        ee.sm=0;
        for(i=1;i<=n;i++)
               ee=add(ee,ask[i]);
        if(ee.bi>0)
            printf("%I64d%08I64d\n",ee.bi,ee.sm);
        else
            printf("%I64d\n",ee.sm);
    }
    return 0;
}
