#include<iostream>
#include<stdlib.h>
using namespace std;

int d[8][2]={{0,1},{1,0},{-1,0},{0,-1},{1,-1},{-1,1},{-1,-1},{1,1}};
int sign[101][101];
char maps[101][101];
int n,m,t;
int number;

void bfs( int x , int y , int number )
{
    int queue[100001][2];
    for ( int i = 0 ; i < t ; ++ i )
        queue[i][0] = -1;
    int move = 0;
    int save = 0;
    queue[save][0] = x;
    queue[save++][1] = y;
    sign[x][y]= number ;
    while (queue[move][0]!=-1)
    {
          for ( int k = 0 ; k < 8 ; ++ k )
          {
              int px = queue[move][0] + d[k][0];
              int py = queue[move][1] + d[k][1];
              if ( px >= 0 && px < n && py >= 0 && py < m && sign[px][py] == 0 && maps[px][py] != '*' )
              {
                   queue[ save ][0] = px;
                   queue[save++][1] = py;
                   sign[px][py] = number;
              }
          }
          move ++;
    }
}

int main()
{
    while ( cin >> n >> m && n )
    {
          t = m*n;number = 1;
          for ( int i = 0 ; i < n ; ++ i )
          for ( int j = 0 ; j < m ; ++ j )
          {
              cin >> maps[i][j];
              sign[i][j] = 0;
          }
          for ( int i = 0 ; i < n ; ++ i )
          for ( int j = 0 ; j < m ; ++ j )
          if ( sign[i][j] == 0 && maps[i][j] != '*' )
          {
              bfs( i , j , number );
              number ++;
          }
          cout << number-1 << "\n";
    }
    system("pause");
}
