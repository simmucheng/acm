#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{
    int x;
    char y;
    char t;
}w[2][100];
int cmp1(node a,node b)
{
    if(a.t=='K'&&b.t!='K')return 1;
    else if(a.t!='K'&&b.t=='K')return 0;
    else if(a.t=='K'&&a.t=='K')
    {
        if(a.y!=b.y)return a.y<b.y;
        else return a.x<b.x;
    }
    if(a.t=='Q'&&b.t!='Q')return 1;
    else if(a.t!='Q'&&b.t=='Q')return 0;
    else if(a.t=='Q'&&a.t=='Q')
    {
        if(a.y!=b.y)return a.y<b.y;
        else return a.x<b.x;
    }
    if(a.t=='R'&&b.t!='R')return 1;
    else if(a.t!='R'&&b.t=='R')return 0;
    else if(a.t=='R'&&a.t=='R')
    {
        if(a.y!=b.y)return a.y<b.y;
        else return a.x<b.x;
    }
    if(a.t=='B'&&b.t!='B')return 1;
    else if(a.t!='B'&&b.t=='B')return 0;
    else if(a.t=='B'&&a.t=='B')
    {
        if(a.y!=b.y)return a.y<b.y;
        else return a.x<b.x;
    }
    if(a.t=='N'&&b.t!='N')return 1;
    else if(a.t!='N'&&b.t=='N')return 0;
    else if(a.t=='N'&&a.t=='N')
    {
        if(a.y!=b.y)return a.y<b.y;
        else return a.x<b.x;
    }
}
int cmp2(node a,node b)
{
    if(a.t=='K'&&b.t!='K')return 1;
    else if(a.t!='K'&&b.t=='K')return 0;
    else if(a.t=='K'&&a.t=='K')
    {
        if(a.y!=b.y)return a.y<b.y;
        else return a.x>b.x;
    }
    if(a.t=='Q'&&b.t!='Q')return 1;
    else if(a.t!='Q'&&b.t=='Q')return 0;
    else if(a.t=='Q'&&a.t=='Q')
    {
        if(a.y!=b.y)return a.y<b.y;
        else return a.x>b.x;
    }
    if(a.t=='R'&&b.t!='R')return 1;
    else if(a.t!='R'&&b.t=='R')return 0;
    else if(a.t=='R'&&a.t=='R')
    {
        if(a.y!=b.y)return a.y<b.y;
        else return a.x>b.x;
    }
    if(a.t=='B'&&b.t!='B')return 1;
    else if(a.t!='B'&&b.t=='B')return 0;
    else if(a.t=='B'&&a.t=='B')
    {
        if(a.y!=b.y)return a.y<b.y;
        else return a.x>b.x;
    }
    if(a.t=='N'&&b.t!='N')return 1;
    else if(a.t!='N'&&b.t=='N')return 0;
    else if(a.t=='N'&&a.t=='N')
    {
        if(a.y!=b.y)return a.y<b.y;
        else return a.x>b.x;
    }

}
int judge(char f)
{
    if(f=='Q'||f=='q'||f=='K'||f=='k'||f=='R'||f=='r'||f=='B'||f=='b'||f=='N'||f=='n')return 1;
    else return 0;
}
int main()
{
    int i,j,m,n;
    char d;
    char s[32][32];
    int l1=0;
    int l2=0;
    for(i=1;i<=17;i++)
    {
        for(j=1;j<=33;j++)
        scanf("%c",&s[i][j]);
        getchar();
    }
    for(i=2;i<=17;i+=2)
    {
        for(j=3;j<=33;j+=4)
        {
                if(s[i][j-1]==':'&&(s[i][j]=='p'||s[i][j]=='P')){w[0][l1].t='p';w[0][l1].x=(16-i)/2+1;w[0][l1++].y='a'+(j-1)/4;}
                else if(s[i][j-1]==':'&&judge(s[i][j]))
                {
                    w[0][l1].t=s[i][j];
                    w[0][l1].x=(16-i)/2+1;
                    w[0][l1++].y='a'+(j-1)/4;
                }
                else if(s[i][j-1]=='.'&&(s[i][j]=='P'||s[i][j]=='p')){w[1][l2].t='P';w[1][l2].x=(16-i)/2+1;w[1][l2++].y='a'+(j-1)/4;}
                else if(s[i][j-1]=='.'&&judge(s[i][j]))
                {
                    w[1][l2].t=s[i][j];
                    w[1][l2].x=(16-i)/2+1;
                    w[1][l2++].y='a'+(j-1)/4;
                }
        }
    }
     //sort(w[0],w[0]+l1,cmp1);
    // sort(w[1],w[1]+l2,cmp2);
     cout<<w[0][0].t<<w[0][0].y<<w[0][0].x;
     for(i=1;i<l1;i++)
     cout<<','<<w[0][i].t<<w[0][i].y<<w[0][i].x;
     cout<<endl;
     for(i=0;i<l2;i++)
     cout<<w[1][i].t<<w[1][i].y<<w[1][i].x<<',';
     cout<<endl;
    return 0;
}
