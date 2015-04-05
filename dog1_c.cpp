#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const double eps=1e-6;
struct node
{
    int xx;
    int yy;
}s[200];
bool judge1(int xx1,int yy1,int xx2,int yy2)
{
    if(xx1*yy2-yy1*xx2>0)
        return false;
    else return true;
}
bool judge2(double r,int xx1,int yy1)
{
    double xx2=xx1*1.0;
    double yy2=yy1*1.0;
    if(xx2*xx2+yy2*yy2<=r*r)return true;
    else return false;
}
int main()
{
    int i,j,m,n;
    int x,y;
    double r;
    while(scanf("%d%d%lf",&x,&y,&r),r>eps)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            {
                int aa,bb;
                scanf("%d%d",&aa,&bb);
                s[i].xx=aa-x;
                s[i].yy=bb-y;
            }
        int getmax=-1;
        for(i=0;i<n;i++)
        {
            int sum=0;
            for(j=0;j<n;j++)
            {
                if(judge1(s[i].xx,s[i].yy,s[j].xx,s[j].yy)&&judge2(r,s[j].xx,s[j].yy))
                sum++;
            }
            getmax=max(getmax,sum);
        }
        printf("%d\n",getmax);
    }
    return 0;
}
