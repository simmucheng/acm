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
    //for(i=2; i<1000; i++) //���������ռ��̫��ioʱ�䣬����ֻ���2-100�ڵ����������԰�100��ΪN
    //if( prime[i] )printf("%d ",i);
cout<<num<<endl;
 return 0;
}
