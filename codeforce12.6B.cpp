#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
map<int,int>p;
int main()
{
    int i,j,m,n;
    int s[100100];
    while(cin>>n)
    {
        int mark=0;
        int k=0;
        for(i=1;i<=n;i++)
            scanf("%d",&s[i]);
        for(j=1;j<n;j++)
        {
            if(s[j]!=s[j+1])
            {
                int r=0;
                swap(s[j],s[j+1]);
                for(i=1;i<n;i++)
                {
                    if(s[i]<s[i+1]){r++;break;}
                }
                for(i=1;i<n;i++)
                {
                    if(s[i]>s[i+1]){r++;break;}
                }
               // cout<<r<<endl;
                swap(s[j],s[j+1]);
                if(r<2)continue;
                else
                {
                    cout<<j<<' '<<j+1<<endl;
                    mark=1;
                    break;
                }
            }
        }
        if(mark==0)cout<<"-1"<<endl;
    }
    return 0;
}
