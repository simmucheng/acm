#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int i,j,m,n,t;
    int num;
    int s[110000];
    while(cin>>m)
    {
        num=0;
        int mark;
        int t=0;
        for(i=0;i<m;i++)
        {
            cin>>s[i];
            t+=s[i];
        }
        if(t%m==0)cout<<m<<endl;
        else cout<<m-1<<endl;
       memset(s,0,sizeof(s));
    }
    return 0;
}
