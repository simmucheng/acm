#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int m,n;
int s[30010];
int father[30010];
void init()
{
    for(int l=0;l<=m;l++)
    {
        father[l]=l;
        s[l]=0;
    }
}
int find_father(int k)
{
    if(father[k]!=k)father[k]=find_father(father[k]);
    return father[k];
}
void unit(int x,int y)
{
    father[father[y]]=father[x];
}
int main()
{
    int i,j;
    int c,a,b;
    while(scanf("%d%d",&m,&n),m||n)
    {
        init();
        int mark;
        int num=0;
        for(i=0;i<n;i++)
        {
            mark=-1;
            scanf("%d",&c);
            for(j=1;j<=c;j++)
            {
                scanf("%d",&s[j]);
                if(find_father(s[j])!=s[j])mark=father[find_father(s[j])];
            }
            if(mark>-1)
            {
                for(j=1;j<=c;j++)
                father[find_father(s[j])]=mark;
            }
            else
            {
                for(j=1;j<=c;j++)
                father[s[j]]=s[1];
            }
        }
        for(i=0;i<m;i++)
        if(find_father(0)==find_father(i))num++;
        //之前用if(father[0]==father[i])num++;错了,是因为我更新节点只是将根节点的father更新,其他的子节点的father还是没有更新的
        printf("%d\n",num);
    }
    return 0;
}
