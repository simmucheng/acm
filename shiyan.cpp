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
int main()
{
    int i,j,m,n;
    int a1,b1;
    scanf("%d",&n);
    while(n--)
    {
      a.clear();
      scanf("%d",&a1);
      int h,w;
      for(i=0;i<a1;i++)
          {
              scanf("%d%d",&w,&h);
              a.push_back(make_pair(w,h));
          }
      /*scanf("%d",&b1);
      for(i=0;i<b1;i++)
          {
              scanf("%d%d",&w,&h);
               b.push_back(make_pair(w,h));
          }*/
      sort(a.begin(),a.end());
      //sort(b.begin(),b.end());
      for(i=0;i<a1;i++)
      cout<<a[i].first<<' '<<a[i].second<<endl;
    }
    return 0;
}
