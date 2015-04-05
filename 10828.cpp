#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
vector<int>s[110];
const double eps=1e-8;
double matrix[110][110];
int ou[110];
int mark[110];
void build(int nn)
{
    for(int ii=1;ii<=nn;ii++)
    {
        matrix[ii][ii]=-1;
        int len=s[ii].size();
        for(int jj=0;jj<len;jj++)
        {
            matrix[ii][s[ii][jj]]+=1.0/(ou[s[ii][jj]]*1.0);
        }
    }
    matrix[1][nn+1]=-1;
   /* for(int ii=1;ii<=nn;ii++)
    {
        for(int jj=1;jj<=nn+1;jj++)
            cout<<matrix[ii][jj]<<' ';
        cout<<endl;
    }*/
    return ;
}
void gauss_gardon(int nn)
{
    for(int ii=1;ii<=nn;ii++)
    {
        int rr=ii;
        for(int jj=ii+1;jj<=nn;jj++)
        {
            if(fabs(matrix[jj][ii])>fabs(matrix[rr][ii]))rr=jj;
        }
        if(fabs(matrix[rr][ii])<eps)continue;
        if(rr!=ii)
        {
            for(int kk=1;kk<=nn+1;kk++)
                swap(matrix[ii][kk],matrix[rr][kk]);
        }
        for(int jj=1;jj<=nn;jj++)
        {
            if(jj==ii)continue;
            for(int kk=nn+1;kk>=ii;kk--)
            {
                matrix[jj][kk]-=matrix[ii][kk]/matrix[ii][ii]*matrix[jj][ii];
            }
        }
      /* for(int ii=1;ii<=nn;ii++)
    {
        for(int jj=1;jj<=nn+1;jj++)
            cout<<matrix[ii][jj]<<' ';
        cout<<endl;
    }*/
    }
    for(int ii=1;ii<=nn;ii++)
    {
        if(fabs(matrix[ii][ii])<eps&&fabs(matrix[ii][nn+1])>eps)
        {
            mark[ii]=1;
            for(int jj=1;jj<=nn;jj++)
            {
                if(fabs(matrix[jj][ii])>eps)
                    mark[jj]=1;
            }
        }
    }
    return ;
}
void init(int nn)
{
    for(int ii=1;ii<=nn;ii++)
        s[ii].clear();
    return ;
}
int main()
{
    int n,m,i,j;
    int sta=1;
    while(scanf("%d",&n),n)
    {
        init(n);
        memset(ou,0,sizeof(ou));
        memset(mark,0,sizeof(mark));
        memset(matrix,0,sizeof(matrix));
        int a,b;
        while(scanf("%d%d",&a,&b),a||b)
        {
            ou[a]++;
            s[b].push_back(a);
        }
        build(n);
        gauss_gardon(n);
        scanf("%d",&m);
        printf("Case #%d:\n",sta++);
        for(i=1;i<=m;i++)
        {
            int d;
            scanf("%d",&d);
            if(mark[d])
                printf("infinity\n");
            else
            {
                double yy=0;
                if(fabs(matrix[d][d])<eps&&fabs(matrix[d][n+1])<eps)
                    printf("%.3f\n",yy);
                else
                    printf("%.3f\n",fabs(matrix[d][n+1]/matrix[d][d]));
            }
        }
    }
    return 0;
}
