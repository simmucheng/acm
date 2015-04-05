#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int s[5];
    int i;
    for(i=0;i<5;i++)
    cin>>s[i];
    sort(s+1,s+5,cmp);
    for(i=0;i<5;i++)
    cout<<s[i];
    return 0;
}
