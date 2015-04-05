#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    int i,j,m,n;
    double pi=3.14159;
    while(cin>>n)
    {
        double num=0;
        cin>>m;
        while(n--)
        {
            double s;
            cin>>s;
            s=s/180*pi;
            num+=sin(s)*m*m/2;
        }
        printf("%.3f\n",num);
    }
    return 0;
}
