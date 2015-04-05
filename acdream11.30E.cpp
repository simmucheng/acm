#include<iostream>
#include<cmath>
using namespace std;
int search(int d)
{
    int l=1;
    int mark=0;
    while(1)
    {
         l++;
         if(pow(2,l)==d){mark=1;break;}
         if(pow(2,l)<d&&d<pow(2,l+1))break;
    }
    if(mark==0)
    {
        return 1+(d-pow(2,l))*2;
    }
    else return 1;
}
int main()
{
    int m,n;
    while(cin>>n)
    {
        if(n>4)
        cout<<search(n)<<endl;
        else if(n==1)cout<<"1"<<endl;
        else if(n==2||n==4)cout<<"1"<<endl;
        else if(n==3)cout<<"3"<<endl;

    }
    return 0;
}
