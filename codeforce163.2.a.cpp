#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int i,j,m,n;
    char s[100];
    while(cin>>n)
    {
        cin>>s;
        int c=0;
        for(i=0;i<strlen(s)-1;i++)
            if(s[i]==s[i+1])c++;
        cout<<c<<endl;
    }
    return 0;
}
