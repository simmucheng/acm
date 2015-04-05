#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int rela[30][30];
int mark[30];
int ee[30];
int ss[30];
int step;
int res;
int ssum;
void topsort(int limit)
{
    int sum=0;
    int sta;
    for(int ii=0;ii<limit;ii++)
    {
        if(ee[ii]==0)
        {
            sum++;
            sta=ii;
        }
    }
    if(sum==1)
    {
        for(int jj=0;jj<limit;jj++)
            if(rela[sta][jj])
            ee[jj]--;
        ss[step++]=sta;
        ee[sta]=-1;
        topsort(limit);
    }
    else if(sum>1)return ;
    else if(sum==0&&step!=limit)
    res=2;
    if(step==limit)res=1;
    return ;
}
void topsort1(int nn)
{
    for(int ii=0;ii<nn;ii++)
    {
        if(ee[ii]==0)
        {
            ee[ii]=-1;
            for(int jj=0;jj<nn;jj++)
                if(rela[ii][jj])
                    ee[jj]--;
            topsort1(nn);
        }
    }
    return ;
}
void init()
{
    for(int ii=0;ii<30;ii++)
    {
        for(int jj=0;jj<30;jj++)
            rela[ii][jj]=0;
        mark[ii]=0;
    }
    return ;
}
int main()
{
    int i,j,m,n;
    while(scanf("%d%d",&m,&n),n||m)
    {
        init();
        int xy=0;
        ssum=0;
        res=0;
        int rr;
        char s[4];
        for(i=1;i<=n;i++)
        {
            scanf("%s",s);
            if(res==1||xy>0)continue;
            if(!rela[s[0]-'A'][s[2]-'A'])
            {
                rela[s[0]-'A'][s[2]-'A']=1;
                mark[s[2]-'A']++;
            }
            if(rela[s[2]-'A'][s[0]-'A'])xy=i;
            if(!mark[s[0]-'A'])
            ssum++;
            if(!mark[s[2]-'A'])
            ssum++;
            step=0;
           for(int ii=0;ii<30;ii++)
           ee[ii]=mark[ii];
           topsort1(m);
           for(int ii=0;ii<30;ii++)
           if(ee[ii]>0)
           {
               xy=i;
               continue;
           }
           for(int ii=0;ii<30;ii++)
            ee[ii]=mark[ii];
           topsort(m);
            if(res==1)rr=i;
            else if(res==2)xy=i;
        }
        if(xy>0)
            printf("Inconsistency found after %d relations.\n",xy);
        else if(res==1)
            {
                printf("Sorted sequence determined after %d relations: ",rr);
                for(i=0;i<m;i++)
                    printf("%c",ss[i]+'A');
                printf(".\n");
            }
        else
            printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
/*
先要考虑是不是可以直接找出唯一的序列来
然后考虑是不是能找出矛盾的序列来（包括在不能找出唯一的序列的条件下）
最后再是考虑是不是不存在这种可以找出的情况
矛盾的情况包括两种，
1.与直接给出的相反
2.推理后矛盾
我wa首先是忘了考虑推理后矛盾的情况
然后是在没有唯一的情况下矛盾的情况没有处理好。其中主要是间接的矛盾。
*/
