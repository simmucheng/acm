#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;
int n;
int s[210];
int mark;
string qq;
 ofstream o_file;
void dfs(int e,string w,int c)
{
    if(mark==1)return ;
    if(c>100)return ;
    for(int k=0;k<2;k++)
    {
        if(mark==1)return ;
        char t;
        int u;
        t=(k+'0');
        u=(e*10+k)%n;
        if(u==0&&!mark){qq=w+t;o_file<<'"'<<w+t<<'"'<<',';mark=1;return ;}
        if(mark==1)return ;
        dfs(u,w+t,c+1);
    }
    return ;
}
int judge(string pp)
{
    int a=pp.length();
    int z=0;
    for(int l=0;l<a;l++)
    {
        int y=1;
        for(int d=0;d<a-l-1;d++)
        {
            y=(y*(10%n))%n;
        }
        y=y*(pp[l]-'0');
        //cout<<"y = "<<y<<endl;
        z=(z+y)%n;
        //cout<<"z = "<<z<<endl;
    }
    if(z==0)return 1;
    else return 0;
}
int main()
{
    int i,j,m;

    //o_file.open("aaa.txt");
    for(i=1;i<=200;i++)
    {
        n=i;
        mark=0;
        string d="1";
        memset(s,0,sizeof(s));
        cout<<i<<endl;
        dfs(1,d,1);
        if(!judge(qq)){cout<<"NO!"<<endl;break;}
    }
    return 0;
}
