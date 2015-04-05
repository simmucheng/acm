#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node
{
    int c;
    int d;
    int way;
}w[20010];
struct node1
{
    int x1;
    int num;
    int y1;
}yy[1010];
int s[1010][1010];
int cmp(node1 a,node1 b)
{
    return a.x1>b.x1;
}
int main()
{
    int i,j,m,n;
    int x,y;
    node1 xx[1010];
    //int yy[1010];
    while(cin>>n)
    {
        m=n;
        int l=0;
        n--;
      while(n--)
      {
          scanf("%d%d",&x,&y);
          yy[y].num++;
          yy[y].x1=x;
          yy[y].y1=y;
      }
      sort(xx+1,xx+m+1,cmp);
      for(i=1;i<=m;i++)
      {
        cout<<'2'<<' '<<yy[i].y1<<' '<<i<<endl;
      }

      cout<<l<<endl;
      for(i=0;i<l;i++)
      cout<<w[i].way<<' '<<w[i].c<<' '<<w[i].d<<endl;
    }
    return 0;
}
