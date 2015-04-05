#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int i,j,m,n;
    char s[1011];
    while(cin>>n)
    {
        cin>>s;
        int e=0;
        int t=strlen(s);
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]=='L')e++;
        }
        cout<<e+n-t<<' '<<e<<endl;
    }
    return 0;
}
