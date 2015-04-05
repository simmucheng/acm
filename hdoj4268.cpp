#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef pair<int,int>PII;
vector <PII> a,b;
multiset<int> c;
multiset<int>::iterator it;
int a1;
int main()
{
    int i,j,m,n;
    scanf("%d",&n);
    while(n--)
    {
      scanf("%d",&a1);
      int h,w;
      a.clear();
      b.clear();
      for(i=0;i<a1;i++)
          {
              scanf("%d%d",&w,&h);
              a.push_back(make_pair(w,h));
          }
      for(i=0;i<a1;i++)
          {
              scanf("%d%d",&w,&h);
              b.push_back(make_pair(w,h));
          }
      sort(a.begin(),a.end());
      sort(b.begin(),b.end());
      int con=0;
      for(i=0;i<a.size();i++)
      {
          int t=0;
          while(a[i].first>=b[t].first&&t<b.size())
          {
              c.insert(b[t].second);
              t++;
          }
          it=c.upper_bound(a[i].second);
          if(it!=c.begin()&&!c.empty())
          {
              it--;
              c.erase(it);
              con++;
          }
      }
      printf("%d\n",con);
        c.clear();

    }
    return 0;
}
