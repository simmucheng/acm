#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int i,j,m,n;
    int len,e,r;
    char s[50];
    cin>>n;
    while(n--)
    {
        cin>>s;
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if((s[i]==':'&&s[i+1]!=':')||(i==0&&s[i]!=':'))
            {
                if(s[i-1]!=':'&&i!=0)cout<<':';
                for(j=i+1;j<=i+4;j++)
                {
                    if(s[j]==':'||j==len-1)
                    {
                        int l=0;
                        int q=0;
                        int u=0;
                        if(j==len-1||i==0){q=1;}
                        for(l=0;l<5-(j-i);l++)
                        {
                            if(q==1&&u==0)
                            {
                                l++;u=1;
                            if(l>=5-(j-i))break;
                            }
                            cout<<"0";
                        }
                       // if(s[i-1]==':'&&j==len-1&&i!=1){cout<<':';}
                        break;
                    }
                }
            }
            else if(s[i]!=':')cout<<s[i];
            if(i==0&&s[i]!=':')cout<<s[0];
            if(s[i]==':'&&s[i+1]==':')
            {
                if(i!=0)
                cout<<s[i];
                int num=0;
                for(int l=0;l<len;l++)
                {
                    if(s[l]==':')num++;
                }
                if(i+1==len-1)
                {
                    int b;
                    if(i==0)b=10;
                    else b=9;
                    for(int k=1;k<=b-num;k++)
                  {
                      if(k!=b-num)
                      cout<<"0000:";
                      else cout<<"0000";
                  }
                }
                else if(i==0)
                {
                    for(int k=1;k<=9-num;k++)
                   {
                    cout<<"0000:";
                   }
                }
                else
                {
                      for(int k=1;k<=8-num;k++)
                   {
                    cout<<"0000:";
                   }
                }
            }
        }
        cout<<endl;
        memset(s,0,sizeof(s));
    }
    return 0;
}
