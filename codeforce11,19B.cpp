#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int i,j,m,n,len;
    char s[60];
    while(cin>>s)
    {
        len=strlen(s);
        int mark=0;
        int mark1=0;
        int k;
        int y;
        for(i=0;i<len;i++)
        {
            if(s[i]=='r'&&s[i+1]=='u'&&mark1==0&&y+1!=i)
            {
                mark1=1;
                cout<<'.';
                k=i+1;
            }
            cout<<s[i];
           if(s[i]=='p'&&mark==0)
            {
                mark=1;
                cout<<"://";
                y=i;
            }
            if(i==k&&i!=len-1)cout<<'/';
        }
        k=-1;
        cout<<endl;
    }
    return 0;
}
