#include<iostream>
#include<algorithm>
#include<cstdio>
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
    if(x1.end!=x2.end)
    return y1.end<y2.end;
    return y2.begin>y2.begin;
}
int main()
{
    int n,m,i,j,a,b;
    int dis,ques;
    node p[100009];
    while(scanf("%d%d",&dis,&ques)!=EOF)
    {
        memset(s,0,sizeof(0));
        for(i=0;i<dis;i++)
        {
            sacnf("%d%d",&s[i].begin,&s[i].end);
            s[i].hj=1;
        }
        sort(s,s+dis,cmp1);
        for(i=0;i<dis;)
        {
            j=i+1;
            if(s[j].begin<=s[i].begin&&j<dis)
            s[j].hj=0;
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
        int b,e,t=0,r;
        node w;
        while(ques--)
        {
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
                if(p[i].begin>=w.begin&&p[i].end<=w.end)
                {
                    t++;
                    w=p[i];
                }
            }
        }
        printf("%d\n",t);
    }
    return 0;
}
