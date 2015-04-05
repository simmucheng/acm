#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 2000000000
int height[14];
int low[14];
bool cmp(int x,int y)
{
    return x>y;
}
void init()
{
    fill(height,height+14,0);
    fill(low,low+14,N);
}
int main()
{
    int a,b,i,j,great,less,n,s;
    while(scanf("%d%d%d",&great,&less,&n)&&great&&less&&n)
    {
        double sum=0.0;
        init();
        for(i=0;i<n;i++)
        {
            scanf("%d",&s);
            sum+=s;
            if(s>height[great])
            {
                height[great]=s;
                make_heap(height,height+great+1,cmp);
                pop_heap(height,height+great+1,cmp);
            }
            if(s<low[less])
            {
                low[less]=s;
                make_heap(low,low+less+1);
                pop_heap(low,low+less+1);
            }
        }
        for(i=0;i<great;i++)
        sum-=height[i];
        for(i=0;i<less;i++)
        sum-=low[i];
        double su=sum*1.0/(n-great-less);
        printf("%.6f\n",su);
    }
    return 0;
}
