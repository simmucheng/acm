#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int i,j,m,n;
    char s[100];
    while(cin>>m>>n)
    {
        cin>>s;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<strlen(s)-1;j++)
            {
                if(s[j]=='B'&&s[j+1]=='G'){swap(s[j],s[j+1]);j++;}
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
