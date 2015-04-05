#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int s[10010];
int main()
{
    int i,j,m,n;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        scanf("%d",&s[i]);
        sort(s,s+n);
        printf("%d\n",s[n/2]);
    }
    return 0;
}
