#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
__int64 s[500010];
__int64 l[500010];
__int64 r[500010];
__int64 num;
void merge(int sta,int mid,int end)
{

    int ii=sta;
    int jj=mid+1;
    while(ii<=mid)
    l[ii]=s[ii++];
    while(jj<=end)
    r[jj]=s[jj++];
    int ee=sta;
    ii=sta;
    jj=mid+1;
    while(ii<=mid&&jj<=end)
    {
        if(l[ii]<=r[jj])s[ee++]=l[ii++];
        else {s[ee++]=r[jj++];num+=mid-ii+1;}
    }
    while(ii<=mid)
    s[ee++]=l[ii++];
    while(jj<=end)
    s[ee++]=r[jj++];
}
void mergesort(int sta,int end)
{
    int mid=(sta+end)/2;
    if(sta<end)
    {
        mergesort(sta,mid);
        mergesort(mid+1,end);
        merge(sta,mid,end);
    }
}
int main()
{
    int i,j,m,n;
    while(cin>>n,n)
    {
        num=0;
        for(i=0;i<n;i++)
        scanf("%I64d",&s[i]);
        mergesort(0,n-1);
       /* for(i=0;i<n;i++)
        cout<<s[i]<<' ';
        cout<<endl; */
        cout<<num<<endl;
    }
    return 0;
}
