#include<iostream>
using namespace std;
int main()
{
    int i,j,m,n;
    while(cin>>n)
    {
        for(i=3;i<=100;i++)
        s[i-1]=i;
        s[0]=2;
        s[1]=1;
        if(n>2)cout<<'-1'<<endl;
        else
        {
            for(i=0;i<n;i++)
            cout<<s[i]<<' ';
        }
    }
    return 0;
}
