#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char s[100];
    char mark[20];
    int next[20];
    int lenmark;
    int lens;
    int i,j,m,n;
    int st;
    while(1)
    {
        cin>>s+1;
        cin>>mark+1;
        cin>>st;
        lenmark=strlen(mark);
        lens=strlen(s);
       // cout<<"lens = "<<lens<<endl;
        next[1]=0;
        i=1;
        j=0;
        while(i<lenmark)
        {
            if(mark[i]==mark[j]||j==0){i++;j++;next[i]=j;}
            else j=next[j];
        }
       // for(i=1;i<=lenmark;i++)
      //  cout<<next[i]<<' ';
      //  cout<<endl;
        i=st;
        j=1;
        int num=0;
        while(i<=lens&&j<=lenmark)
        {
            if(s[i]==mark[j]||j==0){i++;j++;}
            else j=next[j];
            if(j==lenmark)num=1;
        }
      //  cout<<i<<endl;
        if(num==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
