#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    int i,j,m,n;
    char s[3];
    while(scanf("%s",s)!=EOF)
    {
        sort(s,s+3);
        cout<<s[0];
        for(i=1;i<3;i++)
        printf(" %c",s[i]);
        cout<<endl;
    }
    return 0;
}
