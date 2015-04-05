#include<iostream>
using namespace std;
int re(int a)
{
    if(a==0)return 1;
    return re(a-1)*a;
}
int main()
{
    int x;
    cin>>x;
    cout<<re(x);
    return 0;
}

