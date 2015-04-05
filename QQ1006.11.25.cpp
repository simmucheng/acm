#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
struct node
{
    int ji;
    int cla;
    string num;
    int ma;
}mark[1010];
int cmp(node a1,node a2)
{
    if(a1.ji!=a2.ji)
    return a1.ji<a2.ji;
    if(a1.ma!=a2.ma)
    return a1.ma>a2.ma;
    if(a1.cla!=a2.cla)
    return a1.cla<a2.cla;
    if(a1.num!=a2.num)
    return a1.num>a2.num;
}
int main()
{
    int i,j,m,n,l;
    int s[11][55];
    memset(s,0,sizeof(s));
    cin>>n;
    for(i=1;i<=n;i++)
    {
        int t,r,e1;
        cin>>e1;
        l=0;
        while(1)
        {
            cin>>r;
            if(r==0)break;
            s[i][r]=1;
        }
    }
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>mark[i].ji>>mark[i].cla>>mark[i].num;
        mark[i].ma=s[mark[i].ji][mark[i].cla];
    }
    sort(mark,mark+m,cmp);
    for(i=0;i<m;i++)
    cout<<mark[i].ji<<' '<<mark[i].cla<<' '<<mark[i].num<<endl;
    return 0;
}
