#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double pi=3.14159;
int main()
{
    int m,i,n=0;
    for(i=0;i<9;i++)
    {
        n+=90;
        double t=cos(pi*n/180);
        printf("%.0f\n",t);
    }
    return 0;
}
