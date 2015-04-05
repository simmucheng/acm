#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,m;
    __int64 n;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%I64d",&n);
        int step=0;
        while(n)
        {
            if(n%2)
            {
                n-=1;
                step++;
            }
            else
            {
                n/=2;
                step++;
            }
        }
        printf("%d\n",step);
    }
    return 0;
}
