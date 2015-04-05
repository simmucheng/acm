#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int s[1100000];
int I[1100000];
int Q[1100000];
int len,size;
void getmax()
{
    int l;
    int head=1;
    int tail=0;
    for(l=1;l<size;l++)
    {
        while(head<=tail&&Q[tail]<=s[l])tail--;
        tail++;
        Q[tail]=s[l];
        I[tail]=l;
    }
    for(l=size;l<=len;l++)
    {
      while(head<=tail&&Q[tail]<=s[l])tail--;
        tail++;
        Q[tail]=s[l];
        I[tail]=l;
        while(I[head]<=l-size)head++;
        printf("%d ",Q[head]);
    }
}
void getmin()
{
    int l;
    int head=1;
    int tail=0;
    for(l=1;l<size;l++)
    {
        while(head<=tail&&Q[tail]>=s[l])tail--;
        tail++;
        Q[tail]=s[l];
        I[tail]=l;
    }
    for(l=size;l<=len;l++)
    {
      while(head<=tail&&Q[tail]>=s[l])tail--;
        tail++;
        Q[tail]=s[l];
        I[tail]=l;
        while(I[head]<=l-size)head++;
        printf("%d ",Q[head]);
    }
}
int main()
{
    int i,j;
    scanf("%d%d",&len,&size);
        for(i=1;i<=len;i++)
        scanf("%d",&s[i]);
        getmin();
        cout<<endl;
        getmax();
    return 0;
}
