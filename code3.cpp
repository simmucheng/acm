#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define eps 1e-8
using namespace std;
struct cmp
{
    bool operator()(__int64 &aa,__int64 &bb)
    {
        return aa>bb;
    }
};
int main()
{
    int i,j,m,n;
    while(scanf("%d",&n)!=EOF)
    {
        priority_queue<__int64,vector<__int64>,cmp> q;
        __int64 s;
        for(i=0;i<n;i++)
            {
                scanf("%I64d",&s);
                q.push(s);
            }
        __int64 top[2];
        __int64 num=0;
        __int64 getmax=0;
        while(1)
        {
            top[0]=q.top();
            q.pop();
            if(q.empty())
            {
                num++;
                getmax=top[0];
                break;
            }
            top[1]=q.top();
            q.pop();
            if(top[0]==top[1])
                q.push(top[1]+1);
            else
            {
                    q.push(top[1]);
                    num++;
            }
        }
        printf("%I64d\n",getmax+1-num);
    }
    return 0;
}



