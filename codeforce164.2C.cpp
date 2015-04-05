#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int i,j,m,n;
    int x,y;
    while(cin>>x>>y)
    {
        n=min(x,y);
        cout<<n+1<<endl;
        for(i=0;i<=n;i++)
            cout<<n-i<<' '<<0+i<<endl;
    }
    return 0;
}
