//tzc_3431
//http://acm.tzc.edu.cn/acmhome/problemdetail.do?&method=showdetail&id=3431

#include<iostream>
#include<queue>
using namespace std;

int r,c;
int grass[1050][1050];
int dir[8][2]={1,0,0,1,-1,0,0,-1,1,1,-1,-1,1,-1,-1,1};

void dfs(int x,int y)
{	if( x>=0 && x<r && y>=0 && y<c && grass[x][y]>0 )
	{   grass[x][y]=-1;
		for(int i=0;i<8;i++)
		{	int x1=x+dir[i][0];
			int y1=y+dir[i][1];
			if (x1>=0 && x1<r && y1>=0 &&y1<c){   dfs(x1,y1);  }
		}
	}     
}

void bfs(int x,int y)
{    queue <int> qx,qy;
     qx.push(x);
     qy.push(y);
     
     while(!qx.empty())
     {	int x=qx.front();	qx.pop();
        int y=qy.front();	qy.pop();
        
        for(int i=0;i<8;i++)
        {  int x1=x+dir[i][0];
           int y1=y+dir[i][1];
          
           if(x1>=0&&x1<r&&y1>=0&&y1<c)
           {  if(grass[x1][y1]>0)
              {  grass[x1][y1]=-1;
                 qx.push(x1);
                 qy.push(y1);
              }
           }
        }
     }
}

void print()
{    for(int i=0;i<r;i++)
     {   for(int j=0;j<c;j++) cout<<grass[i][j]<<' ';
         cout<<endl;
     }
}

int main()
{   while(cin>>r>>c)
    {  for(int i=0;i<r;i++)
         for(int j=0;j<c;j++)  cin>>grass[i][j];
      
      int ans=0;   
      for(int i=0;i<r;i++)
        for(int j=0;j<c;j++) if(grass[i][j]>0) {bfs(i,j);ans++;}
      cout<<ans<<endl;
      
      print();
    }
}