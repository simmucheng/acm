#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int a,b,m,n,i,j;
    int s[1000];
    int p[1000];
    int sum,number;
    while(scanf("%d%d",&sum,&number)!=EOF)
    {
        for(i=0;i<number;i++)
        scanf("%d",&s[i]);
        memset(p,0,sizeof(p));
        for(i=0;i<number;i++)
        {
            for(j=sum;j>=s[i];j--)
                p[j]=max(p[j],p[j-s[i]]+s[i]);
        }
        cout<<sum-p[sum]<<endl;
    }
    return 0;
}
