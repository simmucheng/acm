#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int i,j,m,n,num,h;
    int s[10000];
    cin>>h;
    for(i=1;i<=h;i++)
    {
        cin>>m>>n>>num;
        int a,b,c;
        a=m;
        b=n;
        int l=0;
        int k=3;
        s[1]=m;
        s[2]=n;
        while(1)
        {
            c=a+b;
            if(c<10){a=b;b=c;s[k++]=c;}
            else {a=c/10;b=c%10;s[k++]=a;s[k++]=b;}
            if(a==m&&b==n)break;
        }
        num%=(k-3);
        if(num==0)num=k-3;
        printf("Case #%d: %d\n",i,s[num]);
    }
}
