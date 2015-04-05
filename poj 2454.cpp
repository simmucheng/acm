#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<iostream>
using namespace std;
struct node
{
    int num;
    int sta;
}s[200];
int cmp(node a,node b)
{
    return a.num<b.num;
}
int mark[200];
int main()
{
    int i,j,m,n,k;
        scanf("%d",&k);
        memset(mark,0,sizeof(mark));
        memset(s,0,sizeof(s));
        int sum1=0;
        int sum2=0;
        for(i=0;i<3*k;i++)
        {
            scanf("%d",&s[i].num);
            s[i].num-=500;
            s[i].sta=i;
        }
        sort(s,s+k*3,cmp);
        for(i=k;i<2*k;i++)
        sum1+=s[i].num;
        for(i=2*k;i<3*k;i++)
        sum2+=s[i].num;
        srand((unsigned)time(NULL));
        while(sum1<=0||sum2<=0)
        {
            //if(sum1>0&&sum2>0)break;
            int tt1=(rand()%k)+k;
            int tt2=(rand()%k)+2*k;
            sum1-=s[tt1].num-s[tt2].num;
            sum2-=s[tt2].num-s[tt1].num;
            swap(s[tt1].num,s[tt2].num);
            swap(s[tt1].sta,s[tt2].sta);
        }
        //cout<<sum1<<' '<<sum2<<endl;
        for(i=0;i<3*k;i++)
            printf("%d\n",s[i].sta+1);
    return 0;
}
