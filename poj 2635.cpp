#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1000101
using namespace std;
char s[110];
__int64 w[50];
__int64 pri[1000000];
int b;
void primemake()
{
	int ii,jj;
	int num=0;
	pri[0]=2;
    for(ii=3;ii<N;ii+=2)
    {
    	int flag=0;
    	for(jj=0;pri[jj]*pri[jj]<=ii;jj++)
    	{
            if(ii%pri[jj]==0){flag=1;break;}
    	}
    	if(flag==0){pri[++num]=ii;}
    }
    return ;
}
int ppow(int tt)
{
	int l;
	int mm=1;
	for(l=1;l<tt;l++)
	{
       mm*=10;
	}
	return mm;
}
void change(int len)
{
	int k;
	k=len%5;
	int nu=0;
	b=0;
	for(int l=0;l<k;l++)
	{
        nu+=(s[l]-'0')*ppow(k-l);
	}
    w[b++]=nu;
	for(int l=k;l<len;l+=5)
	{
        nu=0;
        for(int h=l;h<l+5;h++)
        {
        	nu+=(s[h]-'0')*ppow(5-(h-l));
        }
        w[b++]=nu;
	}
	return ;
}
int judge(int p)
{
	__int64 r=0;
	for(int l=0;l<b;l++)
		r=(w[l]+r*100000)%p;
	if(r==0)return 1;
	else return 0;
}
int main()
{
	primemake();
    int i,j,m,n;
    while(scanf("%s %d",s,&n),n)
    {
    	 memset(w,0,sizeof(w));
    	 int t=strlen(s);
    	 int mark=0,pp;
    	 change(t); 
         for(i=0;pri[i]<n;i++)
         {
         	 if(pri[i]==0)break;
             if(judge(pri[i])){mark=1;pp=pri[i];break;}
         }
         if(mark==1)printf("BAD %d\n",pp);
         else printf("GOOD\n");
    }
    return 0;
}