#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
__int64 s[15];
int mark[15];
map<__int64,int>q;
int main()
{
    int l=0;
    int i,j;
    __int64 num=1;
    for(i=1;i<=12;i++)
    {
    num=num*i;
    s[l++]=num;
    }
    for(int x1=0;x1<2;x1++)
    {
        for(int x2=0;x2<2;x2++)
        {
            for(int x3=0;x3<2;x3++)
            {
                for(int x4=0;x4<2;x4++)
                {
                    for(int x5=0;x5<2;x5++)
                    {
                        for(int x6=0;x6<2;x6++)
                        {
                            for(int x7=0;x7<2;x7++)
                            {
                                for(int x8=0;x8<2;x8++)
                                {
                                    for(int x9=0;x9<2;x9++)
                                    {
                                        for(int x10=0;x10<2;x10++)
                                        {
                                            for(int x11=0;x11<2;x11++)
                                            {
                                                for(int x12=0;x12<2;x12++)
                                                {
                                                    for(int x13=0;x13<2;x13++)
                                                    {
                                                    __int64 y=s[0]*x1+s[1]*x2+s[2]*x3+s[3]*x4+s[4]*x5+s[5]*x6+s[6]*x7+s[7]*x8+s[8]*x9+s[9]*x10+s[10]*x11+s[11]*x12+x13*s[12];
                                                     q[y]=x1*1+2*x2+x3*3+x4*4+x5*5+x6*6+x7*7+x8*8+x9*9+x10*10+x11*11+x12*12;
                                                   }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    __int64 mm;
    while(cin>>mm,mm>0)
    cout<<q[mm]<<endl;
    return 0;
}
