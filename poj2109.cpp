#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    double m,n;
    while(scanf("%lf%lf",&m,&n)!=EOF)
        {
            printf("%.0f\n",pow(n,1.0/m));
        }

    return 0;
}
