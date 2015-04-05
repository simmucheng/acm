#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int l[9],r[9],w[3][3];
int s[10][10];
int mark=0;
void dfs(int x,int y)
{
   if(x==9){mark=1;return ;}
   if(s[x][y]==0)
   {
   	 for(int k=0;k<9;k++)
   	 {
   	 	if((l[x]&(1<<k))||(r[y]&(1<<k))||(w[x/3][y/3]&(1<<k)))continue;
   	 	else 
   	 	{
   	 		if(y<8)
   	 		{
   	 			int last;
   	 			last=s[x][y];
   	 	        s[x][y]=k+1;
   	 	        //cout<<x<<' '<<y<<' '<<k+1<<endl;
   	 			l[x]^=(1<<k);
   	 			r[y]^=(1<<k);
   	 			w[x/3][y/3]^=(1<<k);
   	 			dfs(x,y+1);
   	 			if(mark)return ;
   	 			s[x][y]=last;
   	 			l[x]^=(1<<k);
   	 			r[y]^=(1<<k);
   	 			w[x/3][y/3]^=(1<<k);
   	 			
   	 		}
   	 		else if(y==8)
   	 	  {
   	 	  	int last;
   	 	  	last=s[x][y];
   	 		s[x][y]=k+1;
   	 		//cout<<x<<' '<<y<<' '<<k+1<<endl;
   	 		l[x]^=(1<<k);
   	 		r[y]^=(1<<k);
   	 		w[x/3][y/3]^=(1<<k);
   	 		dfs(x+1,0);
   	 		if(mark)return ;
   	 		s[x][y]=last;
   	 		l[x]^=(1<<k);
   	 		r[y]^=(1<<k);
   	 		w[x/3][y/3]^=(1<<k);
   	 		
   	 	  }
   	 	}
   	 	if(mark)return ;
   	 }
   }
   else
  { 
   if(y<8)dfs(x,y+1);
   if(mark)return ;
   if(y==8)dfs(x+1,0);
  }
   return ;
}
int main()
{
   int i,j,m,n;
   scanf("%d",&n);
   while(n--)
   {
      mark=0;
   	memset(w,0,sizeof(w));
   	memset(l,0,sizeof(l));
   	memset(r,0,sizeof(r));
   	char e;
      for(i=0;i<9;i++)
      {
      	getchar();
      	for(j=0;j<9;j++)
      	{
      		scanf("%c",&e);
      		s[i][j]=e-'0';
      		l[i]^=(1<<(s[i][j]-1));
      		r[j]^=(1<<(s[i][j]-1));
            w[i/3][j/3]^=(1<<(s[i][j]-1));
      	}
      }
      dfs(0,0);
      for(i=0;i<9;i++)
      {
      	for(j=0;j<9;j++)
      	printf("%d",s[i][j]);
        printf("\n");
      }
   }
   return 0;
}