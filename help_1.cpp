#include<iostream>
#include<cstdio>
using namespace std;
int s[1000100];
const int MIN=0;
struct node
{
    int x;
    int y;
    long long num;
}w[1000100];
int main()
{
    int i,j,m,n;
    while(scanf("%d",&n)!=EOF)
    {
        long long total=0;
        for(i=1;i<=n;i++)
            scanf("%d",&s[i]);
        int bb=1;
        long long get_max=MIN;
        long long sum=0;
        int sta=0;
        int ee=1;
        i=1;
        while(i<=n)
        {
           sum+=s[i];
           if(sum>get_max)
           {
               get_max=sum;
               ee=i;
           }
           if(sum<0||i==n)
            {
                    sum=0;
                    w[sta].num=get_max;
                    get_max=MIN;
                    w[sta].y=ee;
                    w[sta++].x=bb;
                    bb=++ee;
                    i=bb;
            }
            else i++;
            //cout<<"i = "<<i<<' '<<sum<<endl;
        }
        int mark=-1;
        for(i=0;i<sta;i++)
        {
            if(w[i].num>get_max)
            {
                get_max=w[i].num;
                mark=i;
            }
        }
        total=get_max;
        get_max=MIN;
        for(i=0;i<sta;i++)
        {
            if(mark==i)continue;
            get_max=max(get_max,w[i].num);
        }
        total+=get_max;
        cout<<total<<endl;
    }
    return 0;
}
