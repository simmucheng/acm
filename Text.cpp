#include<ctime>
#include<algorithm>
#include<cstdio>
#include<iostream>
#define random(x) (rand()%x)
using namespace std;
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
