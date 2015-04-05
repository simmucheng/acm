#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<fstream>
using namespace std;
long long n;
ofstream o;
void bfs(long long m)
{
    queue<long long> q;
    q.push(m);
    while(!q.empty())
    {
        long long x=q.front();
        q.pop();
        if(x%n==0){cout<<x<<endl;return ;}
        q.push(x*10+1);
        q.push(x*10);
    }
    return ;
}
int main()
{
    while(cin>>n,n)bfs(1);
    return 0;
}
