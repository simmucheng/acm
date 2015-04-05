#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
string str[4];
string r[4];
string ans[4];
string ee[4];
string w[60];
string s[60];
string w1,w2;
map<string,int>pp;
int gg[4];
int MOD(int nn,int mm)
{
    return (nn%mm+mm)%mm;
}
void trans(int nn)
{
    for(int ii=0;ii<nn;ii++)
        for(int jj=0;jj<nn;jj++)
            ans[jj][nn-1-ii]=w[ii][jj];
    for(int ii=0;ii<nn;ii++)
        for(int jj=0;jj<nn;jj++)
            w[ii][jj]=ans[ii][jj];
}
void get_string(int len,int nn)
{
    for(int ii=0;ii<len;ii++)
    {
        for(int jj=0;jj<len;jj++)
        {
            if(w[ii][jj]=='*')
                    str[nn]+=s[ii][jj];
        }
    }
    return ;
}
void init()
{
    for(int ii=0;ii<4;ii++)
    {
        r[ii].clear();
        str[ii].clear();
        ans[ii].clear();
        ee[ii].clear();
    }
    for(int ii=0;ii<60;ii++)
    {
        w[ii].clear();
        s[ii].clear();
    }
    pp.clear();
    return ;
}
void output(int nn)
{
    int sta=0;
    for(int ii=ans[nn].size();ii>=0;ii--)
    {
        if(ans[nn][ii]!=' ')
        {sta=ii;break;}
    }
    for(int ii=0;ii<=sta;ii++)
        printf("%c",ans[nn][ii]);
    printf("\n");
    return ;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int dd=1;dd<=n;dd++)
    {
        init();
        int m;
        scanf("%d",&m);
        for(int ii=0;ii<m;ii++)cin>>s[ii];
        for(int ii=0;ii<m;ii++)cin>>w[ii];
        int uu;
        scanf("%d",&uu);
        for(int ii=0;ii<uu;ii++)
        {
            string hh;
            cin>>hh;
            pp[hh]=1;
        }
        printf("Case #%d: ",dd);
        for(int ii=0;ii<4;ii++)
        {
            get_string(m,ii);
            trans(m);
        }
        for(int ii=0;ii<4;ii++)
        {
            for(int jj=0;jj<4;jj++)
            {
                for(int kk=0;kk<str[0].size();kk++)
                {
                    if(jj==0)while(str[(ii+jj)%4][kk]=='.'&&kk<str[0].size())kk++;
                    if(kk>=str[0].size())continue;
                    if(str[(ii+jj)%4][kk]=='.')
                    {
                        int yy=ans[ii].size();
                        if(ans[ii][yy-1]!=' ')ans[ii]+=' ';
                    }
                    else ans[ii]+=str[(ii+jj)%4][kk];
                }
            }
        }
        int oo=0;
        for(int ii=0;ii<4;ii++)
        {
            string h;
            int mark=0;
            for(int jj=0;jj<ans[ii].size();jj++)
            {
                if(ans[ii][jj]!=' ')h+=ans[ii][jj];
                if((ans[ii][jj]==' '||jj==ans[ii].size()-1)&&!pp[h])
                {
                    mark=1;
                    h.clear();
                    break;
                }
                else if((ans[ii][jj]==' '||jj==ans[ii].size()-1)&&pp[h])h.clear();
            }
            if(mark==0){gg[oo]=ii;oo++;}
        }
        if(oo==1)output(gg[oo]);
        else if(oo==0)printf("FAIL TO DECRYPT\n");
        else
        {
          for(int ii=0;ii<oo;ii++)
          {
              for(int jj=0;jj<ans[gg[ii]].size();jj++)
                if(ans[gg[ii]][jj]!=' ')
                ee[gg[ii]]+=ans[gg[ii]][jj];
          }
          for(int ii=1;ii<oo;ii++)
         {
            if(ee[gg[ii]].compare(ee[gg[ii-1]])>0)
            swap(gg[ii],gg[ii-1]);
         }
         output(gg[oo-1]);
        }
    }
    return 0;
}
