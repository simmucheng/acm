#include<iostream>
#include<cstdio>
using namespace std;
int ss(int u)
{
    int s[10]={0};
    for(int l=0;l<4;l++)
    {
        if(s[u%10]==0)
        {
            s[u%10]=1;
            u/=10;
        }
        else return 0;
    }
    return 1;
}
int main()
{
    int i,j,m,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=n+1;;i++)
            if(ss(i)){printf("%d\n",i);break;}
    }
    return 0;
}
