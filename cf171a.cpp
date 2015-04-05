#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{
    int xx;
    int yy;
}s[10010];
void init()
{
    int x1=1;
    int y1=0;
    int x2=1;
    int y2=1;
    int x3=-1;
    int y3=1;
    int x4=-1;
    int y4=-1;
    for(int l=0;;l++)
    {
       if(l%4==1){x1+=1;y1-=1;s[l].xx=x1;s[l].yy=y1;}
       else if(l%4==2){x2+=1;y2+=1;s[l].xx=x2;s[l].yy=y2;}
        else if(l%4==3){x3-=1;y3+=1;s[l].xx=x3;s[l].yy=y3;}
            else if(l%4==0){x4-=1;y4-=1;s[l].xx=x4;s[l].yy=y4;}
    }
    return ;
}
int main()
{
    int i,j,m,n;
    int a,b,c;
    int num;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int num;
        for()
        printf("%d\n",num);
    }
    return 0;
}