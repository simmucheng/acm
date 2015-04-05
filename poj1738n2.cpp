#include<iostream>
#include<cstdio>
using namespace std;
int s[50050];
int r,temp;
int n;
void combine(int x)
{
    int i;
    temp=s[x]+s[x+1];
    r+=temp;
    n--;
    if(n<=1)return ;
    for(i=x+1;i<=n;i++)
    s[i]=s[i+1];
    for(i=x-1;i>=1&&s[i]<temp;i--)
    s[i+1]=s[i];
    s[i+1]=temp;
    s[n+1]=0xfffffff;
    while(i>=2&&s[i]>=s[i-2])
    {
        int d=n-i;
        combine(i);
        i=n-d;
        //i++;
    }
}
int main(){
    int i,j,m;
    while(scanf("%d",&n),n)
    {
        r=0;
        s[0]=0xfffffff;
        for(i=1;i<=n;i++)
        scanf("%d",&s[i]);
        for(i=1;i<=n-2;i++)
        {
            while(s[i]<=s[i+2]&&i+2<=n)
            combine(i);
        }
        while(n>2)combine(n-2);
        cout<<r<<endl;
    }
     return 0;
}

