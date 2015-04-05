#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<map>
#include<stuck>
using namespace std;
int p[26];
stuck <string>ww;
map<string,short> q;
int main()
{
    int i,j,m,n;
    string s,w;
    while(cin>>s)
    {
        int sum=0;
        memset(p,0,sizeof(p));
        q.clear();
        cin>>w;
        cin>>n;
        for(i=0;i<26;i++)
            if(w[i]=='1')p[i]=1;
        for(i=0;i<s.length();i++)
        {
            string h;
            m=0;
            for(j=i;j<s.length();j++)
            {
                if(!p[s[j]-'a'])m++;
                  h+=s[j];
                 if(m<=n&&q[h]==0)
                 {
                  sum++;
                  q[h]=1;
                 }
                 if(m>n)break;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
