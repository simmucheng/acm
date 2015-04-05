#include<iostream>
using namespace std;
void f(int &i,int num)
{
    for(int j=1;j<=i;j++)
    {
        cout<<num<<" ";
        num*=2;
    }
    cout<<endl;
}
int main()
{
    int i=1;
    while(i<=6)
    {
        f(i,2);
        i++;
    }
    return 0;
}
