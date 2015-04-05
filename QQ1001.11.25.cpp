#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,m,n;
    char s[11000];
    cin>>n;
    while(n--)
    {
        int num=0;
        int num1=0;
        int num2=0;
        int t;
        cin>>s;
        t=strlen(s);
        for(i=0;i<t;i++)
        {
            num+=s[i]-'0';
           // cout<<num<<endl;
            if((i+1)&1)num1+=s[i]-'0';
            else num2+=s[i]-'0';
        }
        if(num%9==0&&(abs(num2-num1)%11==0))
        cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        //judge(m);
    }
}
