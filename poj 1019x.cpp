#include<iostream>
#include<cmath>
using namespace std;
int ch(int f)
{
    if(f>0&&f<10)return 1;
    else if(f<100&&f>=10)return 2;
    else if(f<1000&&f>=100)return 3;
    else if(f<10000&&f>=1000)return 4;
    else if(f<100000&&f>=10000)return 5;
}
int qq(int e,int st)
{
    int k=0;
    while(e)
    {
        k++;
        e/=10;
    }
    return k+1-st;
}
int sta1(__int64 ww)
{
    int k;
    __int64 y=0;
    for(k=1;;k++)
     {
         y+=ch(k);
         if(y-ch(k)<ww&&ww<=y)break;
     }
     int z=ww-(y-ch(k));
     int yy=k;
     int jj=qq(yy,z);
     int pp;
     for(k=0;k<jj;k++)
     {
     pp=yy%10;
     yy/=10;
     }
     return pp;
}
int main()
{
    int i,j;
    __int64 n,m;
    __int64 num=0;
    __int64 end=0;
    __int64 e=0;
    cin>>m;
    while(m--)
    {
        cin>>n;
        e=0;
        num=0;
    for(i=1;i<=30000;i++)
    {
        e=e+ch(i);
        end=num;
        num+=e;
        if(n>end&&n<=num)break;
    }
    n-=end;
    cout<<"n = "<<n<<endl;
    cout<<sta1(n)<<endl;
    }
    return 0;
}
