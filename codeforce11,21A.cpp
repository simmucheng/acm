#include<iostream>
using namespace std;
int main()
{
    int i,j,m,n;
    int s[120];
    for(i=3;i<=50;i++)s[i-1]=i;
        s[0]=90;
        s[1]=99;
        //for(i=0;i<100;i++)
       // cout<<s[i]<<' ';
    while(cin>>n)
    {
        if(n<=2)cout<<"-1"<<endl;
        else
        {
            for(i=0;i<n;i++)
            cout<<s[i]<<' ';
            cout<<endl;
        }
    }
    return 0;
}
