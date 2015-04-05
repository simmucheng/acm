#include<queue>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct node
{
    string  num;
    int time;
    int mark;
    string sta;
};
queue<node>q;
int main()
{
    int i,j,m,n;
    node r;
    while(cin>>n)
    {
        while(n--)
        {
            cin>>r.num>>r.time;
            r.mark=r.time;
            r.sta="ready";
            q.push(r);
        }
        cout<<"进程名"<<"   时间"<<"   状态"<<endl;
        while(!q.empty())
	    {
              node t;
              t=q.front();
              q.pop();
              t.sta="running";
              if(t.time==0)continue;
	          t.time-=(t.mark-1);
              cout<<t.num<<' '<<"unknow"<<"   "<<t.sta<<endl;
	          if(t.time>0)
	          {
	              t.sta="ready";
	              q.push(t);cout<<t.num<<' '<<t.mark-1<<"   "<<t.sta<<endl;
              }
	          else
	          {
	              t.sta="finish";
	              cout<<t.num<<"     "<<t.mark+t.time-1<<"   "<<t.sta<<endl;
              }
        }
    }
    return 0;
}














