#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,m,n;
    while(cin>>n)
    {
        int num=0;
        for(i=1;i<=n;i++)
        num+=pow(i,2);
        cout<<num<<endl;
    }
    return 0;
}
