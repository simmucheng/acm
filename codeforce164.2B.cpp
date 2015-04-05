#include<iostream>
using namespace std;
int main()
{
    int i,j,m,n;
    __int64 num;
    while(cin>>n)
    {
        num=0;
        for(i=1;i<=n;i++)
            num+=(n-i)*i+1;
        cout<<num<<endl;
    }
    return 0;
}
