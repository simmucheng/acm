#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
using namespace std;
ofstream oo("111.txt");
__int64 N=10000000000;
char t[12];
__int64 poww(int nn)
{
    __int64 kk=1;
    for(int ii=1;ii<=nn;ii++)
    kk*=10;
    return kk;
}
int judge(__int64 nn)
{
    int top=0;
    for(int ii=1;;ii++)
    {
        t[top++]='0'+nn%10;
        nn/=10;
        if(nn==0)break;
    }
    for(int ii=2;ii<top;ii++)
    {
        if(t[ii-2]=='6'&&t[ii-1]=='0'&&t[ii]=='2')
        return 1;
    }
    return 0;
}
int main()
{
    int n,i,j;
    __int64 a,b;
    for(int x0=0;x0<1;x0++)
    {
        for(int x1=0;x1<10;x1++)
        {
            if(x1==x0)continue;
            for(int x2=0;x2<10;x2++)
            {
                if(x1==x2||x2==x0)continue;
                for(int x3=0;x3<10;x3++)
                {
                    if(x3==x0||x3==x1||x3==x2)continue;
                    for(int x4=0;x4<10;x4++)
                    {
                        if(x4==x0||x4==x1||x4==x2||x4==x3)continue;
                        for(int x5=0;x5<10;x5++)
                        {
                            if(x5==x0||x5==x1||x5==x2||x5==x3||x5==x4)continue;
                            for(int x6=0;x6<10;x6++)
                            {
                                if(x6==x0||x6==x1||x6==x2||x6==x3||x6==x4||x6==x5)continue;
                                for(int x7=0;x7<10;x7++)
                                {
                                    if(x7==x0||x7==x1||x7==x2||x7==x3||x7==x4||x7==x5||x7==x6)continue;
                                    for(int x8=0;x8<10;x8++)
                                    {
                                        if(x8==x0||x8==x1||x8==x2||x8==x3||x8==x4||x8==x5||x8==x6||x8==x7)continue;
                                        for(int x9=0;x9<10;x9++)
                                        {
                                            __int64 sum;
                                            if(x9==x0||x9==x1||x9==x2||x9==x3||x9==x4||x9==x5||x9==x6||x9==x7||x9==x8)
                                            sum=x9*poww(0)+x8*poww(1)+x7*poww(2)+x6*poww(3)+x5*poww(4)+x4*poww(5)+x3*poww(6)+x2*poww(7)+x1*poww(8)+x0*poww(9);
                                            if(judge(sum))
                                            {
                                                cout<<sum<<endl;
                                                oo<<sum<<',';
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
    return 0;
}
