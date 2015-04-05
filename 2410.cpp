#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
__int64 po(__int64 w1,__int64 w2)
{
    __int64 r=1;
    if(w2==0)
    return 1;
    while(w2)
    {
        w2--;
        r*=w1;
    }
    return r;
}
int main()
{
    __int64 i,j,m,n;
    __int64 num;
    char s[15],w[15];
    while(scanf("%s",s)!=EOF)
    {
        if(s[0]=='#')break;
        scanf("%s",w);
        n=strlen(s);
        num=0;
        for(i=0;i<n;i++)
        {
            if(s[i]=='?')num++;
        }
        __int64 nu=0;
        for(i=0;i<n;i++)
        {
            if(s[i]!='?')
            {
               if(s[i]<w[i]&&nu==0){nu=0;break;}
               else if(s[i]<w[i]&&nu>0)break;
               else if(s[i]==w[i])continue;
               else if(s[i]>w[i])
               {
                nu+=po(10,num);
                break;
               }
            }
            else
            {
                __int64 r;
               // cout<<"vbewuih"<<endl;

                r=9-(w[i]-'0');
                num--;
                //cout<<r*po(10,num)<<endl;
                nu+=r*po(10,num);

            }
          //  cout<<nu<<endl;
        }
        printf("%I64d\n",nu);
        memset(s,0,sizeof(s));
        memset(w,0,sizeof(w));
    }
    return 0;
}
