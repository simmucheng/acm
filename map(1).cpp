#include<iostream>
#include<map>
using namespace std;
int erfen(int x,int y)
{
    if(y==0)return 1;
    else if(y%2==1)return erfen(x*x,y/2)*x;
    else return erfen(x*x,y/2);
}
int main()
{
    int a,b,i,j;
    cin>>a>>b;
   cout<<erfen(a,b)<<endl;
    return 0;
}
