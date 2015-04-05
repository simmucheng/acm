#include<iostream>
using namespace std;
int main()
{
    __int64 i,j,m,n;
    while(cin>>n)
    {
        if(n<=2){cout<<"-1"<<endl;continue;}
        if(n==3){cout<<"210"<<endl;continue;}
        cout<<'1';
        for(i=2;i<=n-3;i++)
        cout<<'0';
        if(n%6==1)cout<<"020"<<endl;
        else if(n%6==2)cout<<"200"<<endl;
        else if(n%6==3)cout<<"110"<<endl;
        else if(n%6==4)cout<<"050"<<endl;
        else if(n%6==5)cout<<"080"<<endl;
        else if(n%6==0)cout<<"170"<<endl;
    }
    return 0;
}
