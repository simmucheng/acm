#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
//map<int,int> mm;
short mm[50000010];
int main()
{
    int i,j,m,n;
    int a1,a2,a3,a4,a5;
    int com=0;
   scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5);
    for(int x1=-50;x1<=50;x1++)
    {
        if(x1==0)continue;
        for(int x2=-50;x2<=50;x2++)
        {
            if(x2==0)continue;
            int num=a1*x1*x1*x1+a2*x2*x2*x2;
            if(-num<0)mm[50000010-num]++;
            else
            mm[-num]++;
        }
    }
    for(int x3=-50;x3<=50;x3++)
    {
        if(x3==0)continue;
        for(int x4=-50;x4<=50;x4++)
        {
            if(x4==0)continue;
            for(int x5=-50;x5<=50;x5++)
            {
                if(x5==0)continue;
                int nu=a3*x3*x3*x3+a4*x4*x4*x4+a5*x5*x5*x5;
                if(nu<0)nu+=50000010;
                com+=mm[nu];
            }
        }
    }
    printf("%d\n",com);
    return 0;
}
