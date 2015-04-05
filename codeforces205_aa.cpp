#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<climits>
#include<deque>
#include<cmath>
#define MAX(a,b)(a)>(b)?(a):(b)
#define MIN(a,b)(a)<(b)?(a):(b)
#define inf 1<<30
using namespace std;
inline bool cmp(int aa,int bb){return aa<bb;}
const int MAXN=50;

void init()
{

}
int main()
{
    int m,n;
    while(scanf("%d",&n)!=EOF)
    {
        int sum1=0,sum2=0,sum=0,sum3=0;
        for(int ii=1;ii<=n;ii++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(x%2==1)sum1++;
            if(y%2==1)sum2++;
            if(x%2==1&&y%2==1)sum3++;
            sum+=x+y;
        }
        if(sum%2==1){printf("-1\n");continue;}
        else
        {
            sum1-=sum3;
            sum2-=sum3;
            if(sum1+sum2==0)printf("0\n");
            else if((sum1+sum2)%2==0)printf("1\n");
            else printf("-1\n");
        }
    }
    return 0;
}

