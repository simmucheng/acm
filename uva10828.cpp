#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

#define eps 1e-8
using namespace std;
int s[110][110];
int ou[110];
double matrix[110][110];
int mark[110];
void build(int nn)
{
    for(int ii=1;ii<=nn;ii++)
    {
        matrix[ii][ii]=1.0;
        for(int jj=1;jj<=nn;jj++)
        {
            if(s[jj][ii]>0)
              {
                matrix[ii][jj]-=1.0*s[jj][ii]/ou[jj];
              }
        }
    }
    matrix[1][nn+1]=1;
    return ;
}

void find_ans(int nn)
{
    for(int ii=1;ii<=nn;ii++)
    {
        int rr=ii;
        for(int jj=ii+1;jj<=nn;jj++)
            if(fabs(matrix[jj][ii])>fabs(matrix[rr][ii]))rr=jj;
        if(fabs(matrix[rr][ii])<eps)continue;
        if(rr!=ii)
        {
            for(int jj=1;jj<=nn+1;jj++)
                swap(matrix[ii][jj],matrix[rr][jj]);
        }

        for(int jj=1;jj<=nn;jj++)
        {
            if(jj==ii)continue;
            for(int kk=nn+1;kk>=ii;kk--)
            {
                matrix[jj][kk]-=matrix[jj][ii]/matrix[ii][ii]*matrix[ii][kk];
            }
        }
    }
    for(int ii=1;ii<=nn;ii++)
    {
        if(fabs(matrix[ii][ii])<eps&&fabs(matrix[ii][nn+1])>eps)
        {
            mark[ii]=1;
            for(int jj=1;jj<=nn;jj++)
            if(fabs(matrix[jj][ii])>eps)
            mark[jj]=1;
        }
    }
    return ;
}
int main()
{

    int i,j,m,n;
    int yy=0;
    while(scanf("%d",&n),n)
    {
        memset(matrix,0,sizeof(matrix));
        memset(mark,0,sizeof(mark));
        memset(ou,0,sizeof(ou));
        memset(s,0,sizeof(s));
        int x,y;
         while(scanf("%d%d",&x,&y),x||y)
        {
            s[x][y]++;
            ou[x]++;
        }
        build(n);
        find_ans(n);
        int num;
        scanf("%d",&num);
        printf("Case #%d:\n",++yy);
        for(i=1;i<=num;i++)
        {
            int tt;
            scanf("%d",&tt);
            if(mark[tt])
                printf("infinity\n");
            else
                printf("%.3f\n",fabs(matrix[tt][tt])<eps?0.0:(matrix[tt][n+1]/matrix[tt][tt]));
        }
    }
    return 0;
}
