#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
__int64 s[50000100];
__int64 m,mm,n,late;
__int64 binary(__int64 r,__int64 ci)
{   
  if(ci==1)return r%9901;
    if(ci%2==1)return (binary((r%9901)*(r%9901),ci/2)%9901)*(r%9901)%9901;
    else return binary((r%9901)*(r%9901),ci/2)%9901;
}
__int64 sum(__int64 x,__int64 y)
{
    if(y==0)return 1;
    if (y%2==0){return ((sum(x,(y/2)-1)%9901)*((1+binary(x,y/2+1))%9901)+(binary(x,y/2)%9901))%9901;}
    else {return (sum(x,(y/2))%9901)*((1+binary(x,y/2+1))%9901)%9901;}
} 
__int64 togother()
{
	__int64 num=1; 
   for(int l=2;l*l<=mm;l++)
   {
       num*=((sum(l,s[l]*n))%9901);
       num%=9901;
   }
   return num;
}
int main()
{
    __int64 i,j;
    late=0;
    while(cin>>m>>n)
    {
    mm=m;
    i=2;
    for(i=2;i*i<=mm;i++)
    {
      s[i]=0;
      while(m%i==0){s[i]++;m/=i;}
      if(m==1)break;
    }
    __int64 late=1;
    if(m!=1)late=sum(m,n)%9901;
    //if(mm==0&&n)cout<<"0"<<endl;
    //else 
    cout<<(late*togother())%9901<<endl;
    }
    return 0;
}