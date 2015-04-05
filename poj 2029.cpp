#include<iostream>
#include<cstdio>
#include<cstring>
#define N -1;
using namespace std;
int w[120][120];
int lowbit(int nn)
{
    return nn&(-nn);
}
void insert(int x,int y)
{
    int temp=y;
    while(x<=100)
    {
        y=temp;
        while(y<=100)
        {
            w[x][y]+=1;
            y+=lowbit(y);
        }
        x+=lowbit(x);
    }
}
int get(int x,int y)
{
    int sum=0;
    int temp=y;
    while(x)
    {
        y=temp;
        while(y)
        {
            sum+=w[x][y];
            y-=lowbit(y);
        }
        x-=lowbit(x);
    }
    return sum;
}
int getnum(int xx1,int yy1,int xx2,int yy2)
{
    return get(xx1,yy1)-get(xx1,yy2-1)-get(xx2-1,yy1)+get(xx2-1,yy2-1);
}
int main()
{
    int i,j,m,n;
    while(scanf("%d",&n),n)
    {
        memset(w,0,sizeof(w));
        int a,b;
        scanf("%d%d",&a,&b);
        for(i=1;i<=n;i++)
        {
            int xx,yy;
            scanf("%d%d",&xx,&yy);
            insert(xx,yy);
        }
        int x1,y1;
        scanf("%d%d",&x1,&y1);
        int getmax=N;
        for(i=1;i<=a-x1+1;i++)
        {
            for(j=1;j<=b-y1+1;j++)
            {
                int tt=getnum(i+x1-1,j+y1-1,i,j);
                getmax=max(getmax,tt);
            }
        }
        printf("%d\n",getmax);
    }
    return 0;
}
