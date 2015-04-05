#include<iostream>
using namespace std;
int main()
{
    int i,j,m,n;
    cin>>n;
    while(n--)
    {
        cin>>m;
        if(m>10&&m<190&&(m%2==1))cout<<(m-9)/2+9<<endl;
        else if(m<10)cout<<m<<endl;
        else if(m>=192&&((m-189)%3==0))cout<<99+(m-189)/3<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}
