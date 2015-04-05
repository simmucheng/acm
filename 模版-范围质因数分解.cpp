#include<iostream>
#include<cstdio>
#define N 1000000
using namespace std;
int deg[N];
int cit[N];
int good[N];
int main()
{
    int i,j,m,n;
    int sum=0;
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        if(good[i]==0)
        for(j=1;j*i<=n;j++)
        {
            if(deg[i]==0)deg[i]=1;
            if(j>1&&deg[i]==1)
            {
                if(j%i==0)
                good[i*j]=1;
                else
                ++deg[i*j];
            }
            cit[i*j]+=(deg[i]%2==1?1:-1)*(n/i);
        }
        sum+=(n-1-cit[i])*(cit[i]-1);
    }
    sum/=2;
    cout<<sum<<endl;
    int yy=(n-1)*(n-2)*(n-3)/6-sum;
    cout<<yy<<endl;
    return 0;
}
