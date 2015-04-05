#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct node
{
    int number;
    int value;
}s[20];
int rr=0;
int dp[101000];
int w[1000];
int poow(int r)
{
    int e=1;
    for(int l=1;l<=r;l++)
    e*=2;
    return e;
}
void binary(int man,int y)
{
    int l;
    int sta;
    for(l=0;;l++)
    {
        if(poow(l)-1<=man&&man<poow(l+1)-1)
        {
            sta=l;
            break;
        }
    }
    for(l=0;l<sta;l++)
       w[rr++]=poow(l)*y;
    if(man-poow(l)+1>0)w[rr++]=(man-poow(l)+1)*y;
    return ;
}
int main()
{
    int i,j,m,n;
    int num;
    while(cin>>m)
    {
        memset(dp,0,sizeof(dp));
        memset(w,0,sizeof(w));
        cin>>n;
        for(i=0;i<n;i++)
            scanf("%d%d",&s[i].number,&s[i].value);
        for(i=0;i<n;i++)
            binary(s[i].number,s[i].value);
       for(i=0;i<=m;i++)
               if(i>=w[0])dp[i]=w[0];
        int temp=w[0];
        for(i=1;i<rr;i++)
        {
            temp+=w[i];
            temp=min(temp,m);
            for(j=temp;j>=0;j--)
                   if(w[i]<=j)dp[j]=max(dp[j-w[i]]+w[i],dp[j]);
        }
        for(i=m;i>=1;i--)
            if(dp[i]==i)break;
        cout<<i<<endl;
    }
    return 0;
}
