#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
int a;
int b;
double c;
};
bool cmp(Node x,Node y)
{
    if(x.a!=y.a)return x.a>y.a;
    if(x.b!=y.b)return x.b<y.b;
    if(x.c!=y.c) return x.c>y.c;
}
int main()
{
    Node s[5];
    int i;
    for(i=0;i<5;i++)
    cin>>s[i].a>>s[i].b>>s[i].c;
    sort(s,s+5,cmp);
    for(i=0;i<5;i++)
    cout<<s[i].a<<' '<<s[i].b<<' '<<s[i].c<<endl;
    return 0;
}
