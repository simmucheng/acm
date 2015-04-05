#include<iostream>
#include<cstring>
using namespace std;
int find(const char * const s,char t)
{
    //int t=strlen(s);
    for(int i=0;i<t;i++)
    if(s[i]==t)return 5;
    return 8;
}
int main()
{
    char p;
    char r[]="bsbvdabaphbfopihioap";
    cin>>p;
    cout<<find(r,p);
    return 0;
}
