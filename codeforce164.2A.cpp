#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<int,int> righ;
map<int,int> lef;
int main()
{
    int i,j,m,n;
    while(cin>>n)
    {
        righ.clear();
        lef.clear();
        int num=0;
        while(n--)
        {
            int x,y;
            cin>>x>>y;
            righ[x]++;
            lef[y]++;
        }
        for(i=1;i<=100;i++)
            num+=lef[i]*righ[i];
        cout<<num<<endl;
    }
    return 0;
}
