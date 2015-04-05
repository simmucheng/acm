#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int s[500010];
int binary_search(int h,int k)
{
    int be=1;
    int len=k;
    int mia;
    while(be<=len)
    {
        mia=(be+len)/2;
        if(s[mia]<=h)be=mia+1;
        else len=mia-1;
    }
    return be;
}
int main()
{
    int i,j,m,n,mu;
    mu=0;
    cin>>n;
    int k=10;
    for(i=1;i<=n;i++)s[i]=i;
    int a=binary_search(2,3);
    cout<<a<<endl;
    return 0;
}

