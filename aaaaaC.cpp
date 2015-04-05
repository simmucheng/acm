#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,m,n;
    while(cin>>n)
    {
        for(i=0;i<n*2+1;i++)
        cout<<'*';
        cout<<endl;
        for(i=0;i<2*n-1;i++)
        {
            int e=0;
            for(j=0;j<=2*n-1;j++)
            {
                if(j+i==2*n-1){cout<<'*';break;}
                else cout<<' ';
            }
            cout<<endl;
        }
        for(i=0;i<n*2+1;i++)
        cout<<'*';
        cout<<endl;
        cout<<endl;
    }
    return 0;
}
