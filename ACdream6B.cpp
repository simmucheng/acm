#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    double a,b;
    double r;
    while(scanf("%lf%lf",&a,&b)!=EOF)
    {
        if(a>b)swap(a,b);
        double e=asin((b-a)/sqrt(a*a+b*b));
        double d=e+asin(b/sqrt(a*a+b*b));
        r=b/(2*(sin(d)+1));
        printf("%.3f\n",r);
    }
    return 0;
}
