#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int i,j,m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(i=1;i<m-n;i++)
        printf("%d ",i);
        for(i=m;i>m-n;i--)
        printf("%d ",i);
        printf("%d\n",m-n);
    }
    return 0;
}
