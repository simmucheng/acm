#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[1101000];
char mark[2202000];
int dp[2202000];
int manacher(int nn)
{
    int maxlen=1;
    int maxid=1;
    for(int ii=1;ii<=nn;ii++)
    {
        int kk=ii-maxid;
        int yy=min(dp[maxid-kk],dp[maxid]-kk);
        yy=max(0,yy);
        while(mark[ii+yy]==mark[ii-yy])
        yy++;
        dp[ii]=yy;
        cout<<ii<<' '<<yy<<endl;
        if(yy>maxlen)
        {
            maxlen=yy;
            maxid=ii;
        }
    }
    return maxlen;
}
void init(int nn)
{
    for(int ii=1;ii<=(nn<<1)+2;ii++)
    dp[ii]=1;
    return ;
}
int main()
{
    int i,j,m,n;
    while(scanf("%s",s)!=EOF)
    {
        int len=strlen(s);
        init(len);
        for(i=1;i<=len;i++)
        {
            mark[i<<1]=s[i];
            mark[(i<<1)+1]='#';
        }
        mark[0]='*';
        mark[(len+1)>>1]='\0';
        int tt=manacher(len<<1);
        printf("%d\n",tt);
    }
    return 0;
}
