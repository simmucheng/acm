#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int m;
    vector<int>a;
    make_heap(a.begin(),a.end(),less<int>() );
    a.push_back(1);
    m=a.front();
    cout<<m<<endl;
    return 0;
}
