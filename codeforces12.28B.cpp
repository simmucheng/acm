#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char s[100010];
int com(int e,int len)
{
    int u=0;
    int q=len;
    for(int l=e;l<e+q;l++)
    {
        if(s[l]=='-')return 10000;
        u+=(s[l]-'0')*pow(10,--len);
    }
    return u;
}
int main()
{
    int i,m,n;
    int mark[10];
    int ma[13]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
    int c[3][13][32];
    while(scanf("%s",s)!=EOF)
    {
        memset(c,0,sizeof(c));
        int da,mada;
        int yu,mayu;
        int ye,maye;
        int r=0;
        for(i=0;i<strlen(s);i++)
        {
            if(s[i+2]=='-'&&s[i+5]=='-')
            {
                da=com(i,2);
                yu=com(i+3,2);
                ye=com(i+6,4);
               // cout<<da<<' '<<yu<<' '<<ye<<endl;
                if(ye>=2013&&ye<=2015)
                {
                   // cout<<ma[yu]<<' '<<yu<<' '<<da<<endl;
                    if(yu<=12&&yu>0&&ma[yu]>=da&&da>0)
                    {
                       // cout<<"vb reybve"<<endl;
                        c[ye-2013][yu][da]++;
                        if(c[ye-2013][yu][da]>r){r=c[ye-2013][yu][da];mada=da;mayu=yu;maye=ye;}
                    }
                }
            }
        }
        printf("%02d-%02d-%04d\n",mada,mayu,maye);
        memset(s,0,sizeof(s));
    }
    return 0;
}
