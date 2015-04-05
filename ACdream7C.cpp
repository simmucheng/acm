#include<iostream>
#include<cstdio>
#define ma 10000007
using namespace std;
int s[10000];
int sum(int a,int b)
{
    int t=0;
    for(int l=a;l<=b;l++)
    t+=(s[l]%ma)*(s[a+b-l]%ma)%ma;
    return t%ma;
}
void cm(int x)
{
    s[x]=-2*x*s[x-1]+sum(1,x-1);
    cout<<s[x]<<endl;
}
int main()
{
    int i,j,m,n;
    while(cin>>n)
    {
        s[1]=1;
        for(i=2;i<=4;i++)
        {
            cm(i);
        }
    }
    return 0;
}

