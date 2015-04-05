#include<iostream>
using namespace std;
long erfen(int a,int b)
{
    if(b==0)return 1;
    else if(b==1)return a;
    if(b&1)return erfen(a*a,b>>1)*a;
    else return erfen(a*a,b>>1);
}
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        cout<<erfen(m,n)<<endl;
    }
    return 0;
}
