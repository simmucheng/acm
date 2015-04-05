#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,m,n;
    int x,y;
    while(cin>>n)
    {
        int num1,num2;
        int m1,m2;
        num1=num2=m1=m2=0;
        while(n--)
        {
            cin>>x>>y;
            num1+=x;
            num2+=y;
            m1+=abs(x-1);
            m2+=abs(y-1);
        }
        int e1=min(num1,m1);
        int e2=min(num2,m2);
        cout<<e1+e2<<endl;
        //if(num1+num2<m1+m2)cout<<x+y<<endl;
        //else cout<<num1+num2<<endl;
    }
    return 0;
}
