#include<ctime>
#include<algorithm>
#include<cstdio>
#include<iostream>
#define random(x) (rand()%x)
using namespace std;
int gcd(int w1,int w2)
{
    int e;
    e=w1%w2;
    while(e)
    {
        w1=w2;
        w2=e;
        e=w1%w2;
    }
    return w2;
}
int quick(__int64 x1,__int64 x2,int x3)
{
    if(x2==1)return x1;
    int t=quick(x1,x2/2,x3);
    t=(t%x3)*t%x3;
    if(x2&1)t*=x1%x3;
    cout<<t%x3<<endl;
    return t%x3;
}
int judge(__int64 k)
{
    srand(time(0));
    for(int i=1;i<=100;i++)
      {
          //cout<<random(100)<<endl;
          if(quick(random(k)+1,k-1,k)!=1)
          return 5;
      }
      return -5;
}
int muliaddmod(int x1,int x2,int x3)
{
    while(x2)
    {
       if(x2&1)
          temp=(temp+x1)%x3;
        x1=(x1<<1)%x3;
        x2>>=1;
    }
    return temp;
}
int hro(int u)
{
    int x,y;
    int k,l;
    srand(time(0));
    x=y=rand(u)+1;
    while(1)
    {
        y=
    }
    x=
}
int main()
{
    int i,j,m,n;
    __int64 num;
   while(scanf("%I64d",&num)!=EOF)
   {

       if(judge(num)>0)
       printf("Prime\n");
       else if(judge(num)>0)
       printf("NO\n");
   }
   return 0;
}
//要带负数的 -rand()%a+a/2  这样写
