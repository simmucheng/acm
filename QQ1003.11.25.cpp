#include<iostream>
#include<string>
#include<map>
#include<cstring>
using namespace std;
map<string,int>q;
int main()
{
    int i,j,m,n;
    cin>>n;
    while(n--)
    {
        char s[40];
        cin>>m;
        while(m--)
        {
            int r;
            cin>>s;
            cin>>r;
            q[s]=r;
        }
        int num1,num2;
        num1=num2=0;
        char w[40];
        for(i=0;i<5;i++)
        {
         memset(w,0,sizeof(w));
         cin>>w;
         num1+=q[w];
        }
        for(i=0;i<5;i++)
        {
            memset(w,0,sizeof(w));
            cin>>w;
            num2+=q[w];
        }
       // cout<<"num1 = "<<num1<<' '<<"num2 = "<<num2<<endl;
        if(num1>=num2)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
