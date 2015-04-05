#include<iostream>
#include<cstdio>
#define N 1000000007 
using namespace std;
int main()
{
	int i,j,m,n;
	long long a,b;
	while(scanf("%lld",&a)!=EOF)
	{
		b=((a*(a-1))/2)%N;
		printf("%lld\n",b);
	}
	return 0;
}