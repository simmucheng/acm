#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int t[100];
int num(int w)
{
    int q=0;
    int h=w-1;
    for(int z=0;z<w;z++)
    {
        q=q+t[z]*pow(10,h--);
    }
    return q;
}
int main()
{
    int i,j,m,n;
    char s[100000];
    char mark[]="XXX";
    while(cin>>s)
    {
        if(!strcmp(s,mark))break;
        int l,u;
        int y=strlen(s);
        char a;
        l=0;
        for(i=0;i<y;i++)
        {
            if(s[i]>='a'&&s[i]<='z')cout<<s[i];
            if(s[i+1]>='0'&&s[i+1]<='9'&&(s[i]>='a'&&s[i]<='z')){a=s[i];continue;}
            if(s[i]>='0'&&s[i]<='9')
            {
                t[l++]=s[i]-'0';
                if((s[i+1]>='a'&&s[i+1]<='z')||i+1==y)
                {
                  u=num(l);
                  for(j=0;j<u-1;j++)
                  cout<<a;
                  l=0;
                }
            }
        }
        memset(t,0,sizeof(t));
        cout<<endl;
    }
    return 0;
}
