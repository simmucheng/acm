#include<iostream>
#include<cstring>
using namespace std;
struct node
{
    int re;
    int lo;
};
int main()
{
    int i,j,m,n;
    int a,b;
    node s[3];
    while(cin>>m)
    {
        memset(s,0,sizeof(s));
        for(i=0;i<m;i++)
        {
            cin>>n;
            cin>>a>>b;
            s[n].re+=a;
            s[n].lo+=b;
        }
        for(i=1;i<=2;i++)
        {
            if(s[i].re>=s[i].lo)cout<<"LIVE"<<endl;
            else cout<<"DEAD"<<endl;
        }
    }
    return 0;
}
