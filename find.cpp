#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int s[6]={1,2,3,4,5,6};
int nn=5;
int find(int start,int low)
{
    if(start==nn)return low;
    int yy=find(start+1,min(low,s[start+1]));
    cout<<yy<<endl;
    return yy;
}
int main()
{
    int i,j,m,n;

    find(0,0xfffffff);
    return 0;
}
