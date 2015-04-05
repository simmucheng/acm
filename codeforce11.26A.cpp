#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int  i,j,m,n;
    int s[110];
    int mark[110];
    while(cin>>n)
    {
        int t,e,r,l;
        r=0;
        t=0;
        e=1;
        l=0;
        for(i=0;i<n;i++)
        cin>>s[i];
        for(i=0;i<n;i++)
        {
            l++;
            if(s[i]<0)t++;
            if(t>=3){mark[r++]=l-1;t=1;l=1;e++;}
            if(i==n-1&&t<=2){mark[r++]=l;}
        }
        cout<<e<<endl;
        //cout<<mark[0]<<endl;
        for(i=0;i<r;i++)
        cout<<mark[i]<<' ';
        cout<<endl;
        memset(s,0,sizeof(s));
        memset(mark,0,sizeof(mark));
    }
    return 0;
}
