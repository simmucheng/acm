#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
bool s[1000005];
int p[100000];
int con=0;
void init(){
    memset(s,true,sizeof(s));
    for(int i=4;i<1000010;i+=2)
        s[i] = false;
    for(int i=3;i<=1000;i+=2)
        for(int j=3;i*j<1000010;j+=2)
            s[i*j] = false;
      for(int i=2;i<=1000010;i++)
      if(s[i])p[con++]=i;
           }
bool judge(__int64 x,__int64 y)
{
    int o;
    for(o=0;o<con;o++)
    {
        if(x%p[o]==0)
        {
            if(y%p[o]!=0)return false;
            while(x%p[o]==0)
            x/=p[o];
        }
        if(p[o]>x)break;
    }
    if(x>1)return y%x==0;
    return true;
}
int main()
{
       int n,k;
       __int64 a,b;
       init();
       scanf("%d",&n);
       for(k=1;k<=n;k++)
        {
        scanf("%I64d%I64d",&a,&b);
        printf("Case #%d: ",k);
        if(judge(a,b))printf("YES\n");
        else printf("NO\n");
        }
        return 0;
}
