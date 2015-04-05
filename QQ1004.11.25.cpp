#include<iostream>
using namespace std;
int main()
{
    int i,j,m,n;
    while(cin>>n)
    {
        int b=0;
        int r;
        while(n--)
        {
            cin>>r;
            b^=r;
        }
        cout<<b<<endl;
    }
    return 0;
}
