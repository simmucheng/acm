#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int mark[30];
int uu[21][30];
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        for(int ii=0;ii<='Z'-'A';ii++)
        mark[ii]=100;
        memset(uu,0,sizeof(uu));
        int m;
        scanf("%d",&m);
        for(int kk=1;kk<=m;kk++)
        {
            char s[20];
            scanf("%s",s);
            int len=strlen(s);
            for(int ii=0;ii<len;ii++)
            {
                uu[kk][s[ii]-'A']++;
            }
        }
        for(int ii=0;ii<='Z'-'A';ii++)
        {
            for(int jj=1;jj<=m;jj++)
            {
                mark[ii]=min(mark[ii],uu[jj][ii]);
            }
        }
       // for(int ii=0;ii<=26;ii++)
        //    cout<<mark[ii]<<endl;
        for(int ii=0;ii<='Z'-'A';ii++)
        {
            while(mark[ii])
            {
                printf("%c",ii+'A');
                mark[ii]--;
            }
        }
        printf("\n");
    }
    return 0;
}
