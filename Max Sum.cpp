#include<iostream>
using namespace std;
struct node
{
    int end;
    int he;
}
int main()
{
    int i,j,m,n;
    int s[100000];
    int dp;
    node mark[10000];
    scanf("%d",&n);
    while(n--)
    {
        j=0;
        int sum=0;
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        scanf("%d",&s[i]);
        for(i=1;i<=m;i++)
        {
        sum+=s[i];
        dp=sum;
        if(dp<0){
                 mark[j].he=dp;
                 mark[j++].end=i;
                }
        }
        for()
    }
}
