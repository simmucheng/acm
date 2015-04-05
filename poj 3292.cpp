#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<cmath>
#define N 50000
using namespace std;
ofstream ww;
int w[1000100];
int ee[1000100];
int rr[1000100];
void prim()
{
	int nu=0;
	for(int ii=1; ii<=N; ii++)
    {
         int mark=0;
         __int64 e;
         for(int jj=1; jj<=ii; jj++)
         {
             int a=ii*4+1;
             int b=jj*4+1; 
             e=a*b;
             if(e>1000001)break;
             if(rr[a]==0&&rr[b]==0){rr[e]=1;}
             else rr[e]=-1;//this problem is delate e can be formed by three H-number
         }
    }
    return ;
}
int main()
{
	prim();
	int i,j,m,n;
    int num=0;
    for (i = 1; i <=1000001; i++)
    {
    	if(rr[i]==1){ee[i]=++num;}
    	else ee[i]=num;
    }
    while(scanf("%d",&n),n)
    printf("%d %d\n",n,ee[n]);
    return 0;
}