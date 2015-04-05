#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
struct node
{
 int begin;
 int end;
 int hj;
}s[100009];
bool cmp1(node x1,node x2)
{
    if(x1.begin!=x2.begin)
    return x1.begin>x2.begin;
    return x1.end<x2.end;
}
bool cmp2(node y1,node y2)
{
    if(y1.end!=y2.end)
    return y1.end<y2.end;
    return y2.begin>y2.begin;
}
int main()
{
    int n,m,i,j,a;
    int dis,ques;
    node p[100009];
    int b,e,t,r;
    node w;
    while(scanf("%d%d",&dis,&ques)!=EOF)
    {
        memset(s,0,sizeof(0));
        for(i=0;i<dis;i++)
        {
            scanf("%d%d",&s[i].begin,&s[i].end);
            s[i].hj=1;
        }
        sort(s,s+dis,cmp1);
        for(i=0;i<dis;)
        {
            if(s[j].begin<=s[i].begin&&j<dis&&s[j].end>=s[i].end)
            s[j++].hj=0;
            i=j;
        }
        j=0;
        for(i=0;i<dis;i++)
        {
            if(s[i].hj)
            p[j++]=s[i];
        }
        int N=j;
        sort(p,p+N,cmp2);
        for(i=0;i<N;i++)
        while(ques--)
        {
            t=0;
           scanf("%d%d",&b,&e);
            for(i=0;i<N;i++)
            {
                if(p[i].begin>=b&&p[i].end<=e)
                {
                   t=1;
                   r=i;
                   w=p[i];
                   break;
                }
            }
            for(i=r+1;i<N;i++)
            {
                if(p[i].begin>=w.begin&&p[i].end<=e)
                {
                    t++;
                    w=p[i];
                }
            }
            printf("%d\n",t);
        }
    }
    return 0;
}

