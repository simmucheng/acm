#include<cstdio>
#include<cmath>
#include<iostream>
#include<fstream>
#define N 500000
using namespace std;
ofstream ww;
int prime[N];
int main()
{
    int i, j, num = 0;
    ww.open("rrrr.txt");
    for(i=2; i<=N; i++)
    {
         int mark=0;
         for(j=2; j<=sqrt(i); j++)
         {
             if( i%j==0&&j%4==1){mark=1;break;}
         }
         if(mark==0&&(i%4)==1){++num;ww<<i<<',';}
    }
    //for(i=2; i<1000; i++) //由于输出将占用太多io时间，所以只输出2-100内的素数。可以把100改为N
    //if( prime[i] )printf("%d ",i);
cout<<num<<endl;
 return 0;
}
