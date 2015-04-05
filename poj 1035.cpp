#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<string>
using namespace std;
map <string,int> qq;
struct node
{
    int number;
    char w[20];
}s[10100];
node x[60];
void compare1(int xx,int yy)
{
    int mm=0;
        for(int k=0;k<x[xx].number;k++)
            if(x[xx].w[k]!=s[yy].w[k])mm++;
        if(mm>1)return ;
        else if(mm==1)cout<<' '<<s[yy].w;
        return ;
}
void compare2(int xx,int yy)
{
    int mm=0;
    int k,rr;
    for(k=rr=0;k<s[yy].number;k++,rr++)
        if(x[xx].w[rr]!=s[yy].w[k]){k--;mm++;}
    if(mm>1)return ;
    else cout<<' '<<s[yy].w;
    return ;
}
void compare3(int xx,int yy)
{
        int mm=0;
        int k,rr;
        for(k=rr=0;k<s[yy].number;k++,rr++)
           if(x[xx].w[rr]!=s[yy].w[k]){rr--;mm++;}
        if(mm>1)return ;
        else cout<<' '<<s[yy].w;
        return ;
}
void init()
{
   memset(s,0,sizeof(s));
   memset(x,0,sizeof(x));
}
int main()
{
        int i,j,m,n;
        qq.clear();
        init();
        int l=0;
        int num=0;
        while(1)
        {
        scanf("%s",s[l].w);
        qq[s[l].w]=1;
        s[l].number=strlen(s[l].w);
        l++;
        getchar();
        if(s[l-1].w[0]=='#')break;
        }
        while(1)
        {
            scanf("%s",x[num].w);
            x[num].number=strlen(x[num].w);
            num++;
            getchar();
            if(x[num-1].w[0]=='#')break;
        }
        for(i=0;i<num-1;i++)
        {
            cout<<x[i].w;
            if(qq[x[i].w]==1)cout<<" is correct";
            else
            {
                cout<<':';
              for(j=0;j<l-1;j++)
              {
                if(x[i].number-s[j].number==0)(compare1(i,j));
                else if(x[i].number-s[j].number==1)compare2(i,j);
                else if(x[i].number-s[j].number==-1)compare3(i,j);
              }
            }
            cout<<endl;
        }
    return 0;
}

