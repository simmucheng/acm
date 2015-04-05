#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int w[4];
int a,b;
int s[1010][1010];
int path[1010];
int mark[1010];
int ee[3][3];
int ww[3][3];
int dir[4][2]={1,0,-1,0,0,-1,0,1};
void dij(int t)
{
    path[t]=0;
    int se=t;
    while(1)
    {
    	se=-1;
    	int ma=0xfffffff;
    	for(int l=0;l<=a;l++)
    	{
            if(ma>path[l]&&!mark[l])
            {
            	ma=path[l];
                se=l;
            }
    	}
    	if(se==-1)break;
        //cout<<"se = "<<se<<' '<<ma<<endl;
    	mark[se]=1;
    	for(int l=0;l<=a;l++)
    	{
    	  if(path[l]>path[se]+s[l][se]&&!mark[l])path[l]=path[se]+s[l][se];
    	}
    }
    return ;
}
void init()
{
    for (int l=0; l<=a; l++)
    {
    	path[l]=0xfffffff;
    	mark[l]=0;
    }
    return ;
}
int ma=0xfffffff;
void init1()
{
	for(int l=0;l<=a;l++)
    {
    	for(int k=0;k<=a;k++)
    		s[l][k]=0xfffffff;
    }
   /* for(int l=0;l<4;l++)
    {
    	for(int k=0;k<4;k++)
    		ee[l][k]=0xfffffff;
    }*/
    return ;
}
void dfs(int x1,int y1,int nu,int sum)
{
	 if(nu==4){ma=min(ma,sum);return ;}
     for(int l=0;l<4;l++)
     {
     	int xx,yy;
        xx=x1+dir[l][0];
        yy=y1+dir[l][1];
        if(xx<0||xx>3||yy<0||yy>3)continue;
        else 
        {
        	if(!ww[xx][yy])
        	{
        	  ww[xx][yy]=1;
        	  ww[yy][xx]=1;
        	dfs(xx,yy,nu+1,sum+ee[xx][yy]);
            }
        }
     }
     return ;
}
int main()
{
	int i,j,m,n;
	scanf("%d",&n);
	while(n--)
	{
		
		scanf("%d%d",&a,&b);
		scanf("%d%d%d",&w[1],&w[2],&w[3]);
        
		w[0]=0;
		init1();
	    for(i=0;i<b;i++)
	    {
	     int x,y,z; 	
		 scanf("%d%d%d",&x,&y,&z);
		 s[x][y]=z;
		 s[y][x]=z;
        }
        for(i=0;i<4;i++)
        {
        	init();
            dij(w[i]);
            for(j=0;j<4;j++)
            {
              // cout<<i<<' '<<j<<' '<<path[w[j]]<<endl;
               ee[i][j]=path[w[j]];
               //ee[j][i]=ee[i][j];
            }
        }
        for(i=0;i<4;i++)
        {
        	for(j=0;j<4;j++)
        		cout<<ee[i][j]<<' ';
        	cout<<endl;
        }
        for(i=0;i<3;i++)
        {
           memset(ww,0,sizeof(ww));
           dfs(3,i,0,0);
           cout<<ma<<endl;
        }
        printf("%d\n",ma);
    }
    return 0;
}