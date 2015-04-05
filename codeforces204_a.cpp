#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
         int mark=0;
         int sum=0;
         int s;
         for(int ii=1;ii<=n;ii++)
         {
             scanf("%d",&s);
             if(s==0)mark++;
             sum+=s;
         }
         while(sum%9!=0)sum-=5;
         if(sum==0||mark==0){printf("-1");continue;}
         int tt=sum;
         while(sum)
         {
             printf("5");
             sum-=5;
         }
         while(mark)
         {
             printf("0");
             if(tt==0)break;
             mark--;
         }
         printf("\n");
    }
   return 0;
}
