#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int next[1100];
char s[1100];
void findnext(char p[],int size)
{
   // cout<<size<<endl;
    next[1]=0;
    int i=1;
    int j=0;
    //int k=0;
    while(i<size)
        {
            if(p[i]==p[j]||j==0){i++;j++;next[i]=j;}
            else j=next[j];
           // cout<<"mdskm"<<endl;
        }
//    for(i=1;i<=size;i++)
//    cout<<next[i]<<' ';
//    cout<<"\n";
}
int findnumber(char w[],int size1,int size2)
{
    int num=0;
    int i=0,j=1;
    while(i<size1)
    {
        if(j==0||s[i]==w[j]){i++;j++;}
        else j=next[j];
        if(j>size2){num++;j=1;}
    }
    return num;
}
int main()
{
    int i,j,m,n;
    char a[1100];
    char r[1100];
    while(cin>>s)
    {
        if(s[0]=='#')break;
        cin>>a;
        int t=strlen(a);
        for(int y=strlen(a)-1;y>=0;y--)
        a[y+1]=a[y];
        a[0]=' ';
        strcpy(r,a);
        //puts(r);
        findnext(a,t+1);
        int y=findnumber(r,strlen(s),t);
        cout<<y<<endl;
    }
    return 0;
}
