#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<fstream>
using namespace std;
ofstream oo("1.txt");
char s[4][4];
int l[4];
int r[4];
int su1;
int su2;
int main()
{
    int n,m,i,j;
    scanf("%d",&n);
    int kk=0;
    while(n--)
    {
        int mark=0;
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        su1=0;
        su2=0;
        int mm=0;
        for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        cin>>s[i][j];
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(s[i][j]=='X'||s[i][j]=='T')
                {
                    l[j]++;
                    r[i]++;
                    if(i==j)su1++;
                    if(i+j==3)su2++;
                }
                else if(s[i][j]=='.')
                    mm=1;
            }
        }
        for(i=0;i<4;i++)
            if(l[i]==4||r[i]==4||su1==4||su2==4){mark=1;break;}
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        su1=0;
        su2=0;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(s[i][j]=='O'||s[i][j]=='T')
                {
                    l[j]++;
                    r[i]++;
                    if(i==j)su1++;
                    if(i+j==3)su2++;
                }
            }
        }
         for(i=0;i<4;i++)
            if(l[i]==4||r[i]==4||su1==4||su2==4){mark=2;break;}
        oo<<"Case #"<<++kk<<": ";
        if(mark==1)
        oo<<"X won"<<endl;
        else if(mark==2)
        oo<<"O won"<<endl;
        else if(mm==1)oo<<"Game has not completed"<<endl;
        else oo<<"Draw"<<endl;
    }
    return 0;
}
