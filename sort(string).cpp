#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    char a;
    int b;};
bool cmp(node x,node y)
{
    return x.a<y.a;
}
int main()
{
    node d[5];
    int i;
    for(i=0;i<5;i++)
    cin>>d[i].a>>d[i].b;
    sort(d,d+5,cmp);
    for(i=0;i<5;i++)
    cout<<d[i].a<<d[i].b;
    return 0;
}
