#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int mark[70][70][70];
int dir[6][3]={0,0,1,0,0,-1,1,0,0,-1,0,0,0,1,0,0,-1,0};
void change(int aa,int bb,int cc,int nn)
{
    int a1,b1,c1;
    a1=nn/(aa*bb);
    b1=(nn%(aa*bb))/aa;
    c1=(nn%(aa*bb))%aa;
    mark[c1+1][b1+1][a1+1]=1;
    return ;
}
int judge(int aa,int bb,int cc,int xx,int yy,int zz)
{
    int sum=0;
    for(int ii=1;ii<xx;ii++)
    {
        if(mark[ii][yy][zz])
        {
            sum++;
            break;
        }
    }
    for(int ii=xx+1;ii<=aa;ii++)
    {
        if(mark[ii][yy][zz])
        {
            sum++;
            break;
        }
    }
    for(int ii=1;ii<yy;ii++)
    {
        if(mark[xx][ii][zz])
        {
            sum++;
            break;
        }
    }
    for(int ii=yy+1;ii<=bb;ii++)
    {
        if(mark[xx][ii][zz])
        {
            sum++;
            break;
        }
    }
    for(int ii=1;ii<zz;ii++)
    {
        if(mark[xx][yy][ii])
        {
            sum++;
            break;
        }
    }
    for(int ii=zz+1;ii<=cc;ii++)
    {
        if(mark[xx][yy][ii])
        {
            sum++;
            break;
        }
    }
    if(sum==6)return 1;
    else return 0;
}
int main()
{
    int i,j,m,n;
    int a,b,c;
    while(scanf("%d%d%d%d",&a,&b,&c,&n),a||b||c||n)
    {
        int num=0;
        memset(mark,0,sizeof(mark));
        for(i=0;i<n;i++)
        {
            scanf("%d",&m);
            change(a,b,c,m);
        }
        for(int ii=0;ii<=a+1;ii++)
        {
            for(int jj=0;jj<=b+1;jj++)
            {
                for(int kk=0;kk<=c+1;kk++)
                {
                    if(!mark[ii][jj][kk])
                    {
                        //cout<<ii<<' '<<jj<<' '<<kk<<endl;
                        if(!judge(a,b,c,ii,jj,kk))
                        {
                            for(int ll=0;ll<6;ll++)
                            {
                                int a1=ii+dir[ll][0];
                                int b1=jj+dir[ll][1];
                                int c1=kk+dir[ll][2];
                                if(a1<1||a1>a||b1<1||b1>b||c1<1||c1>c)continue;
                                if(mark[a1][b1][c1])
                                num++;
                            }
                        }
                    }
                }
            }
        }
        printf("The number of faces needing shielding is %d.\n",num);
    }
    return 0;
}
