#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int s[54];
    int i,j,m,n,k;
    while(cin>>n>>k)
    {
        for(i=0;i<n;i++)
        scanf("%d",&s[i]);
        if(k>n)cout<<"-1"<<endl;
        else
        {
         sort(s,s+n);
         //for(i=n-1;i>=0;i++)
         cout<<s[n-k]<<" 1"<<endl;
        }
    }
    return 0;
}
